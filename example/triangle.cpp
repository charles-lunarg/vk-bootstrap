#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <condition_variable>

#include <cmath>

#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>

#include <VkBootstrap.h>
#include <VkSwapchainManager.h>

#include "example_config.h"

const size_t MAX_FRAMES_IN_FLIGHT = 2; // number of command buffers and fences
std::atomic_bool is_running;
std::atomic_bool should_resize;

std::mutex main_mutex;

std::mutex render_wait_mutex;
std::condition_variable render_wait_condition_variable;

const bool run_multithreaded = true;
const bool use_refresh_callback = true; // should be true for WindowsOS
const bool use_validation_layer = true; // enabling layers can cause some stuttering

enum class DrawFrameRet { success, fail, out_of_date };

struct Init {
    GLFWwindow* window;
    vkb::Instance instance;
    vkb::InstanceDispatchTable inst_disp;
    VkSurfaceKHR surface;
    vkb::Device device;
    vkb::DispatchTable disp;
};

struct FrameData {
    VkFence fence_inflight{};
    VkCommandBuffer command_buffer{};
};

struct RenderData {
    Init* init; // Needed for the glfw callback

    VkQueue graphics_queue;
    VkQueue present_queue;

    VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_RELAXED_KHR;

    VkRenderPass render_pass;
    VkPipelineLayout pipeline_layout;
    VkPipeline graphics_pipeline;

    VkCommandPool command_pool;
    std::vector<FrameData> frame_data;


    vkb::SwapchainManager swapchain_manager;
    vkb::SwapchainInfo swapchain_info;
    vkb::SwapchainResources swapchain_resources;
    std::vector<VkFramebuffer> framebuffers;

    size_t current_frame = 0;
    double current_time = 0;
};

// Forward declarations that we can give to GLFW
void glfw_resize_callback(GLFWwindow* window, int width, int height);
void glfw_refresh_callback(GLFWwindow* window);

GLFWwindow* create_window_glfw(const char* window_name = "", bool resize = true) {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    if (!resize) glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    return glfwCreateWindow(1024, 1024, window_name, NULL, NULL);
}

void destroy_window_glfw(GLFWwindow* window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

VkSurfaceKHR create_surface_glfw(VkInstance instance, GLFWwindow* window, VkAllocationCallbacks* allocator = nullptr) {
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkResult err = glfwCreateWindowSurface(instance, window, allocator, &surface);
    if (err) {
        const char* error_msg;
        int ret = glfwGetError(&error_msg);
        if (ret != 0) {
            std::cout << ret << " ";
            if (error_msg != nullptr) std::cout << error_msg;
            std::cout << "\n";
        }
        surface = VK_NULL_HANDLE;
    }
    return surface;
}

inline VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void*) {
    auto ms = vkb::to_string_message_severity(messageSeverity);
    auto mt = vkb::to_string_message_type(messageType);
    std::cerr << "[" << ms << ": " << mt << "]\n" << pCallbackData->pMessage << "\n";

    return VK_FALSE; // Applications must return false here
}


int device_initialization(Init& init, RenderData& data) {
    init.window = create_window_glfw("Vulkan Triangle", true);

    if (!init.window) {

        std::cout << "Failed to create glfw window" << "\n";
        return -1;
    }

    glfwSetWindowUserPointer(init.window, &data);
    glfwSetWindowSizeCallback(init.window, glfw_resize_callback);
    if (use_refresh_callback) glfwSetWindowRefreshCallback(init.window, glfw_refresh_callback);

    vkb::InstanceBuilder instance_builder;
    auto instance_ret =
        instance_builder.set_debug_callback(debug_callback).request_validation_layers(use_validation_layer).build();
    if (!instance_ret) {
        std::cout << instance_ret.error().message() << "\n";
        return -1;
    }
    init.instance = instance_ret.value();

    init.inst_disp = init.instance.make_table();

    init.surface = create_surface_glfw(init.instance, init.window);

    vkb::PhysicalDeviceSelector phys_device_selector(init.instance);

    auto phys_device_ret = phys_device_selector.set_surface(init.surface).select();
    if (!phys_device_ret) {
        std::cout << phys_device_ret.error().message() << "\n";
        if (phys_device_ret.error() == vkb::PhysicalDeviceError::no_suitable_device) {
            const auto& detailed_reasons = phys_device_ret.detailed_failure_reasons();
            if (!detailed_reasons.empty()) {
                std::cerr << "GPU Selection failure reasons:\n";
                for (const std::string& reason : detailed_reasons) {
                    std::cerr << reason << "\n";
                }
            }
        }
        return -1;
    }
    vkb::PhysicalDevice physical_device = phys_device_ret.value();

    vkb::DeviceBuilder device_builder{ physical_device };

    auto device_ret = device_builder.build();
    if (!device_ret) {
        std::cout << device_ret.error().message() << "\n";
        return -1;
    }
    init.device = device_ret.value();

    init.disp = init.device.make_table();

    auto swapchain_manager_ret = vkb::SwapchainManager::create(
        vkb::SwapchainBuilder{ init.device }.set_desired_present_mode(data.present_mode).set_desired_extent(512, 512));
    if (!swapchain_manager_ret) {
        std::cout << swapchain_manager_ret.error().message() << "\n";
        return -1;
    }
    data.swapchain_manager = std::move(swapchain_manager_ret.value());
    data.swapchain_resources = data.swapchain_manager.get_swapchain_resources().value();
    data.swapchain_info = data.swapchain_manager.get_info().value();

    return 0;
}

int get_queues(Init& init, RenderData& data) {
    auto gq = init.device.get_queue(vkb::QueueType::graphics);
    if (!gq.has_value()) {
        std::cout << "failed to get graphics queue: " << gq.error().message() << "\n";
        return -1;
    }
    data.graphics_queue = gq.value();

    auto pq = init.device.get_queue(vkb::QueueType::present);
    if (!pq.has_value()) {
        std::cout << "failed to get present queue: " << pq.error().message() << "\n";
        return -1;
    }
    data.present_queue = pq.value();
    return 0;
}

int create_render_pass(Init& init, RenderData& data) {
    VkAttachmentDescription color_attachment = {};
    color_attachment.format = data.swapchain_info.image_format;
    color_attachment.samples = VK_SAMPLE_COUNT_1_BIT;
    color_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    color_attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    color_attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    color_attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    color_attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference color_attachment_ref = {};
    color_attachment_ref.attachment = 0;
    color_attachment_ref.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &color_attachment_ref;

    VkSubpassDependency dependency = {};
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass = 0;
    dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.srcAccessMask = 0;
    dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount = 1;
    render_pass_info.pAttachments = &color_attachment;
    render_pass_info.subpassCount = 1;
    render_pass_info.pSubpasses = &subpass;
    render_pass_info.dependencyCount = 1;
    render_pass_info.pDependencies = &dependency;

    if (init.disp.createRenderPass(&render_pass_info, nullptr, &data.render_pass) != VK_SUCCESS) {
        std::cout << "failed to create render pass\n";
        return -1; // failed to create render pass!
    }
    return 0;
}

std::vector<char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("failed to open file!");
    }

    size_t file_size = (size_t)file.tellg();
    std::vector<char> buffer(file_size);

    file.seekg(0);
    file.read(buffer.data(), static_cast<std::streamsize>(file_size));

    file.close();

    return buffer;
}

VkShaderModule createShaderModule(Init& init, const std::vector<char>& code) {
    VkShaderModuleCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    create_info.codeSize = code.size();
    create_info.pCode = reinterpret_cast<const uint32_t*>(code.data());

    VkShaderModule shaderModule;
    if (init.disp.createShaderModule(&create_info, nullptr, &shaderModule) != VK_SUCCESS) {
        return VK_NULL_HANDLE; // failed to create shader module
    }

    return shaderModule;
}

int create_graphics_pipeline(Init& init, RenderData& data) {
    auto vert_code = readFile(std::string(EXAMPLE_SOURCE_DIRECTORY) + "/example/shaders/triangle.vert.spv");
    auto frag_code = readFile(std::string(EXAMPLE_SOURCE_DIRECTORY) + "/example/shaders/triangle.frag.spv");

    VkShaderModule vert_module = createShaderModule(init, vert_code);
    VkShaderModule frag_module = createShaderModule(init, frag_code);
    if (vert_module == VK_NULL_HANDLE || frag_module == VK_NULL_HANDLE) {
        std::cout << "failed to create shader module\n";
        return -1; // failed to create shader modules
    }

    VkPipelineShaderStageCreateInfo vert_stage_info = {};
    vert_stage_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vert_stage_info.stage = VK_SHADER_STAGE_VERTEX_BIT;
    vert_stage_info.module = vert_module;
    vert_stage_info.pName = "main";

    VkPipelineShaderStageCreateInfo frag_stage_info = {};
    frag_stage_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    frag_stage_info.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    frag_stage_info.module = frag_module;
    frag_stage_info.pName = "main";

    VkPipelineShaderStageCreateInfo shader_stages[] = { vert_stage_info, frag_stage_info };

    VkPipelineVertexInputStateCreateInfo vertex_input_info = {};
    vertex_input_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_info.vertexBindingDescriptionCount = 0;
    vertex_input_info.vertexAttributeDescriptionCount = 0;

    VkPipelineInputAssemblyStateCreateInfo input_assembly = {};
    input_assembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    input_assembly.primitiveRestartEnable = VK_FALSE;

    VkViewport viewport = {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)data.swapchain_info.extent.width;
    viewport.height = (float)data.swapchain_info.extent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor = {};
    scissor.offset = { 0, 0 };
    scissor.extent = data.swapchain_info.extent;

    VkPipelineViewportStateCreateInfo viewport_state = {};
    viewport_state.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state.viewportCount = 1;
    viewport_state.pViewports = &viewport;
    viewport_state.scissorCount = 1;
    viewport_state.pScissors = &scissor;

    VkPipelineRasterizationStateCreateInfo rasterizer = {};
    rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterizer.depthClampEnable = VK_FALSE;
    rasterizer.rasterizerDiscardEnable = VK_FALSE;
    rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
    rasterizer.lineWidth = 1.0f;
    rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
    rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
    rasterizer.depthBiasEnable = VK_FALSE;

    VkPipelineMultisampleStateCreateInfo multisampling = {};
    multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable = VK_FALSE;
    multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
    colorBlendAttachment.colorWriteMask =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    colorBlendAttachment.blendEnable = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo color_blending = {};
    color_blending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    color_blending.logicOpEnable = VK_FALSE;
    color_blending.logicOp = VK_LOGIC_OP_COPY;
    color_blending.attachmentCount = 1;
    color_blending.pAttachments = &colorBlendAttachment;
    color_blending.blendConstants[0] = 0.0f;
    color_blending.blendConstants[1] = 0.0f;
    color_blending.blendConstants[2] = 0.0f;
    color_blending.blendConstants[3] = 0.0f;

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount = 0;
    pipeline_layout_info.pushConstantRangeCount = 0;

    if (init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &data.pipeline_layout) != VK_SUCCESS) {
        std::cout << "failed to create pipeline layout\n";
        return -1; // failed to create pipeline layout
    }

    std::vector<VkDynamicState> dynamic_states = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

    VkPipelineDynamicStateCreateInfo dynamic_info = {};
    dynamic_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_info.dynamicStateCount = static_cast<uint32_t>(dynamic_states.size());
    dynamic_info.pDynamicStates = dynamic_states.data();

    VkGraphicsPipelineCreateInfo pipeline_info = {};
    pipeline_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline_info.stageCount = 2;
    pipeline_info.pStages = shader_stages;
    pipeline_info.pVertexInputState = &vertex_input_info;
    pipeline_info.pInputAssemblyState = &input_assembly;
    pipeline_info.pViewportState = &viewport_state;
    pipeline_info.pRasterizationState = &rasterizer;
    pipeline_info.pMultisampleState = &multisampling;
    pipeline_info.pColorBlendState = &color_blending;
    pipeline_info.pDynamicState = &dynamic_info;
    pipeline_info.layout = data.pipeline_layout;
    pipeline_info.renderPass = data.render_pass;
    pipeline_info.subpass = 0;
    pipeline_info.basePipelineHandle = VK_NULL_HANDLE;

    if (init.disp.createGraphicsPipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &data.graphics_pipeline) != VK_SUCCESS) {
        std::cout << "failed to create pipline\n";
        return -1; // failed to create graphics pipeline
    }

    init.disp.destroyShaderModule(frag_module, nullptr);
    init.disp.destroyShaderModule(vert_module, nullptr);
    return 0;
}

int create_command_pool(Init& init, RenderData& data) {
    VkCommandPoolCreateInfo pool_info = {};
    pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_info.queueFamilyIndex = init.device.get_queue_index(vkb::QueueType::graphics).value();

    if (init.disp.createCommandPool(&pool_info, nullptr, &data.command_pool) != VK_SUCCESS) {
        std::cout << "failed to create command pool\n";
        return -1; // failed to create command pool
    }
    return 0;
}

int create_frame_data(Init& init, RenderData& data) {

    data.frame_data.resize(MAX_FRAMES_IN_FLIGHT);

    for (auto& frame : data.frame_data) {
        VkCommandBufferAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.commandPool = data.command_pool;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = 1;


        if (init.disp.allocateCommandBuffers(&allocInfo, &frame.command_buffer) != VK_SUCCESS) {
            return -1; // failed to allocate command buffers;
        }

        VkFenceCreateInfo fence_info = {};
        fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;

        if (init.disp.createFence(&fence_info, nullptr, &frame.fence_inflight) != VK_SUCCESS) {
            std::cout << "failed to create sync objects\n";
            return -1; // failed to create synchronization objects for a frame
        }
    }

    return 0;
}

int create_framebuffers(Init& init, RenderData& data) {

    data.framebuffers.resize(data.swapchain_info.image_count);

    for (uint32_t i = 0; i < data.framebuffers.size(); i++) {
        VkImageView attachments[] = { data.swapchain_resources.image_views[i] };

        VkFramebufferCreateInfo framebuffer_info = {};
        framebuffer_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebuffer_info.renderPass = data.render_pass;
        framebuffer_info.attachmentCount = 1;
        framebuffer_info.pAttachments = attachments;
        framebuffer_info.width = data.swapchain_info.extent.width;
        framebuffer_info.height = data.swapchain_info.extent.height;
        framebuffer_info.layers = 1;

        if (init.disp.createFramebuffer(&framebuffer_info, nullptr, &data.framebuffers[i]) != VK_SUCCESS) {
            return -1; // failed to create framebuffer
        }
    }
    return 0;
}

int record_command_buffer(Init& init, RenderData& data, uint32_t image_index) {
    auto& current_frame_data = data.frame_data.at(data.current_frame);

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if (init.disp.beginCommandBuffer(current_frame_data.command_buffer, &begin_info) != VK_SUCCESS) {
        return -1; // failed to begin recording command buffer
    }

    VkRenderPassBeginInfo render_pass_info = {};
    render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    render_pass_info.renderPass = data.render_pass;
    render_pass_info.framebuffer = data.framebuffers[image_index];
    render_pass_info.renderArea.offset = { 0, 0 };
    render_pass_info.renderArea.extent = data.swapchain_info.extent;

    float x = static_cast<float>(std::sin(data.current_time * 1.5) * 0.5 + 0.5);
    float z = static_cast<float>(std::cos(data.current_time * 1.5) * 0.5 + 0.5);

    VkClearValue clearColor{ { { x, 0.0f, z, 1.0f } } };
    render_pass_info.clearValueCount = 1;
    render_pass_info.pClearValues = &clearColor;

    VkViewport viewport = {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)data.swapchain_info.extent.width;
    viewport.height = (float)data.swapchain_info.extent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor = {};
    scissor.offset = { 0, 0 };
    scissor.extent = data.swapchain_info.extent;

    init.disp.cmdSetViewport(current_frame_data.command_buffer, 0, 1, &viewport);
    init.disp.cmdSetScissor(current_frame_data.command_buffer, 0, 1, &scissor);

    init.disp.cmdBeginRenderPass(current_frame_data.command_buffer, &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);

    init.disp.cmdBindPipeline(current_frame_data.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, data.graphics_pipeline);

    init.disp.cmdDraw(current_frame_data.command_buffer, 3, 1, 0, 0);

    init.disp.cmdEndRenderPass(current_frame_data.command_buffer);

    if (init.disp.endCommandBuffer(current_frame_data.command_buffer) != VK_SUCCESS) {
        std::cout << "failed to record command buffer\n";
        return -1; // failed to record command buffer!
    }

    return 0;
}

int recreate_swapchain(Init& init, RenderData& data) {
    data.swapchain_manager.destroy_framebuffers(data.framebuffers.size(), data.framebuffers.data());
    auto ret = data.swapchain_manager.recreate();
    if (!ret) {
        std::cout << "failed to recreate swapchain\n";
        return -1;
    }
    data.swapchain_info = ret.value();
    data.swapchain_resources = data.swapchain_manager.get_swapchain_resources().value();
    if (0 != create_framebuffers(init, data)) return -1;
    return 0;
}

DrawFrameRet draw_frame(Init& init, RenderData& data) {
    data.current_time = glfwGetTime();

    auto& current_frame = data.frame_data.at(data.current_frame);

    init.disp.waitForFences(1, &current_frame.fence_inflight, VK_TRUE, UINT64_MAX);

    auto acquire_ret = data.swapchain_manager.acquire_image();

    if (acquire_ret.matches_error(vkb::SwapchainManagerError::swapchain_out_of_date)) {
        return DrawFrameRet::out_of_date;
    } else if (!acquire_ret.has_value()) {
        std::cout << "failed to acquire swapchain image\n";
        return DrawFrameRet::fail;
    }

    vkb::SwapchainAcquireInfo acquire_info = acquire_ret.value();
    if (should_resize) {
        // data.swapchain_manager.cancel_acquire_frame();
        return DrawFrameRet::out_of_date;
    }

    if (0 != record_command_buffer(init, data, acquire_info.image_index)) return DrawFrameRet::fail;

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore wait_semaphores[] = { acquire_info.wait_semaphore };
    VkPipelineStageFlags wait_stages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = wait_semaphores;
    submitInfo.pWaitDstStageMask = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &current_frame.command_buffer;

    VkSemaphore signal_semaphores[] = { acquire_info.signal_semaphore };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signal_semaphores;

    init.disp.resetFences(1, &current_frame.fence_inflight);

    if (init.disp.queueSubmit(data.graphics_queue, 1, &submitInfo, current_frame.fence_inflight) != VK_SUCCESS) {
        std::cout << "failed to submit draw command buffer\n";
        return DrawFrameRet::fail; //"failed to submit draw command buffer
    }

    data.current_frame = (data.current_frame + 1) % MAX_FRAMES_IN_FLIGHT;

    // No need to cancel, if a resize has started, then present will bail
    auto present_ret = data.swapchain_manager.present();

    if (present_ret.matches_error(vkb::SwapchainManagerError::swapchain_out_of_date)) {
        return DrawFrameRet::out_of_date;
    } else if (!present_ret) {
        std::cout << "failed to present swapchain image\n";
        return DrawFrameRet::fail;
    }

    return DrawFrameRet::success;
}

void cleanup(Init& init, RenderData& data) {

    for (auto& framebuffer : data.framebuffers) {
        init.disp.destroyFramebuffer(framebuffer, nullptr);
    }
    for (auto& frame_data : data.frame_data) {
        init.disp.destroyFence(frame_data.fence_inflight, nullptr);
    }

    init.disp.destroyCommandPool(data.command_pool, nullptr);

    init.disp.destroyPipeline(data.graphics_pipeline, nullptr);
    init.disp.destroyPipelineLayout(data.pipeline_layout, nullptr);
    init.disp.destroyRenderPass(data.render_pass, nullptr);

    data.swapchain_manager.destroy();

    vkb::destroy_device(init.device);
    vkb::destroy_surface(init.instance, init.surface);
    vkb::destroy_instance(init.instance);
    destroy_window_glfw(init.window);
}
void render_loop(Init* init, RenderData* data) {
    while (is_running) {
        std::unique_lock<std::mutex> lg(main_mutex, std::try_to_lock);
        if (lg.owns_lock()) {
            switch (draw_frame(*init, *data)) {
                case (DrawFrameRet::success):
                    break;
                case (DrawFrameRet::out_of_date): {
                    lg.unlock();
                    std::unique_lock<std::mutex> ulg(render_wait_mutex);
                    render_wait_condition_variable.wait(ulg);
                    break;
                }
                default:
                case (DrawFrameRet::fail):
                    is_running = false;
                    break;
            }
        } else {
            std::unique_lock<std::mutex> ulg(render_wait_mutex);
            render_wait_condition_variable.wait(ulg);
        }
    }
    init->disp.deviceWaitIdle();
}


void glfw_resize_callback(GLFWwindow* window, int width, int height) {
    if (!is_running || width == 0 || height == 0) {
        return;
    }
    should_resize = true;
    bool should_notify = true;
    std::unique_lock<std::mutex> lg(main_mutex);
    RenderData* data = reinterpret_cast<RenderData*>(glfwGetWindowUserPointer(window));
    auto res = recreate_swapchain(*(data->init), *data);
    if (res == -1) {
        is_running = false;
        return;
    }
    should_resize = false; // makes draw_frame exit early instead of submitting.
    if (!use_refresh_callback) {
        switch (draw_frame(*(data->init), *data)) {
            case (DrawFrameRet::success):
                break;
            case (DrawFrameRet::out_of_date): {
                should_resize = true;
                should_notify = false;
                break;
            }
            default:
            case (DrawFrameRet::fail):
                is_running = false;
                break;
        }
    }
    lg.unlock();
    if (!use_refresh_callback) {
        if (should_notify) {
            render_wait_condition_variable.notify_one();
        }
    }
}
void glfw_refresh_callback(GLFWwindow* window) {
    bool should_notify = false;

    std::unique_lock<std::mutex> lg(main_mutex, std::try_to_lock);
    if (lg.owns_lock()) {
        if (!should_resize) {
            should_notify = true;
            RenderData* data = reinterpret_cast<RenderData*>(glfwGetWindowUserPointer(window));
            switch (draw_frame(*(data->init), *data)) {
                case (DrawFrameRet::success):
                    break;
                case (DrawFrameRet::out_of_date): {
                    should_resize = true;
                    should_notify = false;
                    break;
                }
                default:
                case (DrawFrameRet::fail):
                    is_running = false;
                    should_notify = false;
                    break;
            }
        }
        lg.unlock();
    }
    if (should_notify) {
        render_wait_condition_variable.notify_one();
    }
}

int main() {
    is_running = false;
    should_resize = false;
    Init init{};
    RenderData render_data;
    render_data.init = &init;

    if (0 != device_initialization(init, render_data)) return -1;
    if (0 != get_queues(init, render_data)) return -1;
    if (0 != create_render_pass(init, render_data)) return -1;
    if (0 != create_graphics_pipeline(init, render_data)) return -1;
    if (0 != create_command_pool(init, render_data)) return -1;
    if (0 != create_frame_data(init, render_data)) return -1;
    if (0 != create_framebuffers(init, render_data)) return -1;

    is_running = true;

    render_data.current_time = glfwGetTime();
    if (run_multithreaded) {
        std::thread render_thread{ render_loop, &init, &render_data };

        while (!glfwWindowShouldClose(init.window) && is_running) {
            glfwPollEvents();
            glfwWaitEvents();
        }
        is_running = false;
        render_wait_condition_variable.notify_one();
        render_thread.join();
    } else {
        while (!glfwWindowShouldClose(init.window) && is_running) {
            glfwPollEvents();
            DrawFrameRet res = draw_frame(init, render_data);
            if (res == DrawFrameRet::fail) {
                is_running = false;
            } else if (res == DrawFrameRet::out_of_date) {
                is_running = false;
            }
        }
        init.disp.deviceWaitIdle();
    }


    cleanup(init, render_data);
    return 0;
}
