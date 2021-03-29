#include <stdio.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <condition_variable>

#include <cmath>

#include "../tests/common.h"

#include "example_config.h"

const size_t MAX_FRAMES_IN_FLIGHT = 2;
std::atomic_bool is_running;
std::atomic_bool should_resize;
uint32_t current_width = default_window_width;
uint32_t current_height = default_window_height;

std::mutex main_mutex;

std::mutex render_wait_mutex;
std::condition_variable render_wait_condition_variable;

const bool run_multithreaded = true;
const bool use_refresh_callback = true;
const VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
// options are:
// VK_PRESENT_MODE_IMMEDIATE_KHR, VK_PRESENT_MODE_MAILBOX_KHR, VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_FIFO_RELAXED_KHR

struct Renderer {
	GLFWwindow* window;
	vkb::Instance instance;
	VkSurfaceKHR surface;
	vkb::PhysicalDevice physical_device;
	vkb::Device device;
	vkb::DispatchTable dispatch;

	VkQueue graphics_queue;
	VkQueue present_queue;

	vkb::SwapchainManager swapchain_manager;
	vkb::SwapchainInfo swap_info;

	vkb::DeletionQueue delete_queue;

	VkRenderPass render_pass;
	VkFramebuffer framebuffer;
	VkPipelineLayout pipeline_layout;
	VkPipeline graphics_pipeline;

	VkCommandPool command_pool;
	std::array<VkCommandBuffer, MAX_FRAMES_IN_FLIGHT> command_buffers;
	std::array<VkFence, MAX_FRAMES_IN_FLIGHT> fences;
	uint32_t current_index = 0;

	double current_time = 0;
};

bool try_lock(std::mutex& mutex) {
	if (run_multithreaded)
		return mutex.try_lock();
	else
		return true;
}
void unlock(std::mutex& mutex) {
	if (run_multithreaded) mutex.unlock();
}

int recreate_swapchain(Renderer& renderer);
int draw_frame(Renderer& renderer);

void glfw_resize_callback(GLFWwindow* window, int width, int height) {
	if (!is_running || width == 0 || height == 0) {
		return;
	}
	should_resize = true;
	current_width = width;
	current_height = height;

	std::lock_guard<std::mutex> lg(main_mutex);
	Renderer* renderer = reinterpret_cast<Renderer*>(glfwGetWindowUserPointer(window));
	int res = recreate_swapchain(*renderer);
	if (res < 0) {
		is_running = false;
		return;
	}
	if (!use_refresh_callback) {
		res = draw_frame(*renderer);
		if (res < 0) {
			is_running = false;
		}
	}
	should_resize = false;
	render_wait_condition_variable.notify_one();
}
void glfw_refresh_callback(GLFWwindow* window) {
	if (try_lock(main_mutex)) {
		Renderer* renderer = reinterpret_cast<Renderer*>(glfwGetWindowUserPointer(window));
		int res = draw_frame(*renderer);
		if (res < 0) {
			is_running = false;
		}
		unlock(main_mutex);
	}
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

int instance_initialization(Renderer& renderer) {
	renderer.window = create_window_glfw("Vulkan Triangle", true);

	glfwSetWindowUserPointer(renderer.window, &renderer);

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.request_validation_layers()
	                        .require_api_version(1, 2)
	                        .set_debug_callback(debug_callback)
	                        .build();
	if (!instance_ret) {
		std::cout << instance_ret.error().message() << "\n";
		return -1;
	}
	renderer.instance = instance_ret.value();

	glfwSetWindowSizeCallback(renderer.window, glfw_resize_callback);
	if (use_refresh_callback) glfwSetWindowRefreshCallback(renderer.window, glfw_refresh_callback);

	renderer.surface = create_surface_glfw(renderer.instance.instance, renderer.window);
	VkPhysicalDeviceVulkan12Features features_1_2{};
	features_1_2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
	features_1_2.imagelessFramebuffer = true;

	vkb::PhysicalDeviceSelector phys_device_selector(renderer.instance);
	auto phys_device_ret =
	    phys_device_selector.set_surface(renderer.surface).set_required_features_12(features_1_2).select();
	if (!phys_device_ret) {
		std::cout << phys_device_ret.error().message() << "\n";
		return -1;
	}
	renderer.physical_device = phys_device_ret.value();
	return 0;
}

int device_initialization(Renderer& renderer) {
	vkb::DeviceBuilder device_builder{ renderer.physical_device };
	auto device_ret = device_builder.build();
	if (!device_ret) {
		std::cout << device_ret.error().message() << "\n";
		return -1;
	}
	renderer.device = device_ret.value();

	renderer.dispatch = renderer.device.make_table();

	renderer.delete_queue = vkb::DeletionQueue(renderer.device.device, MAX_FRAMES_IN_FLIGHT);

	auto swapchain_manager_ret = vkb::SwapchainManager::create(
	    vkb::SwapchainBuilder{ renderer.device }.set_desired_present_mode(present_mode).set_desired_extent(default_window_width, default_window_height));
	if (!swapchain_manager_ret) {
		std::cout << swapchain_manager_ret.error().message() << "\n";
		return -1;
	}
	renderer.swapchain_manager = std::move(swapchain_manager_ret.value());
	renderer.swap_info = renderer.swapchain_manager.get_info().value();
	return 0;
}

int get_queues(Renderer& renderer) {
	auto gq = renderer.device.get_queue(vkb::QueueType::graphics);
	if (!gq.has_value()) {
		std::cout << "failed to get graphics queue: " << gq.error().message() << "\n";
		return -1;
	}
	renderer.graphics_queue = gq.value();

	auto pq = renderer.device.get_queue(vkb::QueueType::present);
	if (!pq.has_value()) {
		std::cout << "failed to get present queue: " << pq.error().message() << "\n";
		return -1;
	}
	renderer.present_queue = pq.value();
	return 0;
}

int create_render_pass(Renderer& renderer) {
	VkAttachmentDescription color_attachment = {};
	color_attachment.format = renderer.swap_info.image_format;
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

	if (renderer.dispatch.createRenderPass(&render_pass_info, nullptr, &renderer.render_pass) != VK_SUCCESS) {
		std::cout << "failed to create render pass\n";
		return -1; // failed to create render pass!
	}
	return 0;
}

int create_framebuffer(Renderer& renderer) {

	vkb::ImagelessFramebufferBuilder if_builder(renderer.device);
	renderer.framebuffer =
	    if_builder.set_renderpass(renderer.render_pass)
	        .set_extent(renderer.swap_info.extent)
	        .set_layers(1)
	        .add_attachment(renderer.swap_info.image_usage_flags, renderer.swap_info.image_format)
	        .build();

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

VkShaderModule createShaderModule(Renderer& renderer, const std::vector<char>& code) {
	VkShaderModuleCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	create_info.codeSize = code.size();
	create_info.pCode = reinterpret_cast<const uint32_t*>(code.data());

	VkShaderModule shaderModule;
	if (renderer.dispatch.createShaderModule(&create_info, nullptr, &shaderModule) != VK_SUCCESS) {
		return VK_NULL_HANDLE; // failed to create shader module
	}

	return shaderModule;
}

int create_graphics_pipeline(Renderer& renderer) {
	auto vert_code = readFile(std::string(EXAMPLE_BUILD_DIRECTORY) + "/vert.spv");
	auto frag_code = readFile(std::string(EXAMPLE_BUILD_DIRECTORY) + "/frag.spv");

	VkShaderModule vert_module = createShaderModule(renderer, vert_code);
	VkShaderModule frag_module = createShaderModule(renderer, frag_code);
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
	viewport.width = (float)renderer.swap_info.extent.width;
	viewport.height = (float)renderer.swap_info.extent.height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor = {};
	scissor.offset = { 0, 0 };
	scissor.extent = renderer.swap_info.extent;

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
	colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT |
	                                      VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
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

	if (renderer.dispatch.createPipelineLayout(
	        &pipeline_layout_info, nullptr, &renderer.pipeline_layout) != VK_SUCCESS) {
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
	pipeline_info.layout = renderer.pipeline_layout;
	pipeline_info.renderPass = renderer.render_pass;
	pipeline_info.subpass = 0;
	pipeline_info.basePipelineHandle = VK_NULL_HANDLE;

	if (renderer.dispatch.createGraphicsPipelines(
	        VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &renderer.graphics_pipeline) != VK_SUCCESS) {
		std::cout << "failed to create pipline\n";
		return -1; // failed to create graphics pipeline
	}

	renderer.dispatch.destroyShaderModule(frag_module, nullptr);
	renderer.dispatch.destroyShaderModule(vert_module, nullptr);
	return 0;
}

int create_command_buffers(Renderer& renderer) {
	VkCommandPoolCreateInfo pool_info{};
	pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	pool_info.queueFamilyIndex = renderer.device.get_queue_index(vkb::QueueType::graphics).value();
	if (renderer.dispatch.createCommandPool(&pool_info, nullptr, &renderer.command_pool) != VK_SUCCESS) {
		std::cout << "failed to create command pool\n";
		return -1;
	}

	VkCommandBufferAllocateInfo info{};
	info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	info.commandPool = renderer.command_pool;
	info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	info.commandBufferCount = static_cast<uint32_t>(4);
	if (renderer.dispatch.allocateCommandBuffers(&info, renderer.command_buffers.data()) != VK_SUCCESS) {
		std::cout << "failed to allocate command buffers\n";
		return -1;
	}

	VkFenceCreateInfo fence_info{};
	fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
	for (auto& fence : renderer.fences) {
		if (renderer.dispatch.createFence(&fence_info, nullptr, &fence) != VK_SUCCESS) {
			std::cout << "failed to create fence\n";
			return -1;
		}
	}
	return 0;
}

int record_command_buffer(Renderer& renderer, VkCommandBuffer command_buffer, VkImageView image_view) {
	VkCommandBufferBeginInfo begin_info = {};
	begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

	if (renderer.dispatch.beginCommandBuffer(command_buffer, &begin_info) != VK_SUCCESS) {
		std::cout << "failed to begin recording command buffer\n";
		return -1; // failed to begin recording command buffer
	}

	VkRenderPassAttachmentBeginInfo attach_begin_info{};
	attach_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO;
	attach_begin_info.attachmentCount = 1;
	attach_begin_info.pAttachments = &image_view;

	VkRenderPassBeginInfo render_pass_info = {};
	render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	render_pass_info.pNext = &attach_begin_info;
	render_pass_info.renderPass = renderer.render_pass;
	render_pass_info.framebuffer = renderer.framebuffer;
	render_pass_info.renderArea.offset = { 0, 0 };
	render_pass_info.renderArea.extent = renderer.swap_info.extent;

	float x = static_cast<float>(std::sin(renderer.current_time * 1.5) * 0.5 + 0.5);
	float z = static_cast<float>(std::cos(renderer.current_time * 1.5) * 0.5 + 0.5);

	VkClearValue clearColor{ { { x, 0.0f, z, 1.0f } } };
	render_pass_info.clearValueCount = 1;
	render_pass_info.pClearValues = &clearColor;

	VkViewport viewport = {};
	viewport.x = 0.0f;
	viewport.y = 0.0f;
	viewport.width = (float)renderer.swap_info.extent.width;
	viewport.height = (float)renderer.swap_info.extent.height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor = {};
	scissor.offset = { 0, 0 };
	scissor.extent = renderer.swap_info.extent;

	renderer.dispatch.cmdSetViewport(command_buffer, 0, 1, &viewport);
	renderer.dispatch.cmdSetScissor(command_buffer, 0, 1, &scissor);

	renderer.dispatch.cmdBeginRenderPass(command_buffer, &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);

	renderer.dispatch.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, renderer.graphics_pipeline);

	renderer.dispatch.cmdDraw(command_buffer, 3, 1, 0, 0);

	renderer.dispatch.cmdEndRenderPass(command_buffer);

	if (renderer.dispatch.endCommandBuffer(command_buffer) != VK_SUCCESS) {
		std::cout << "failed to record command buffer\n";
		return -1; // failed to record command buffer!
	}
	return 0;
}

int recreate_swapchain(Renderer& renderer) {
	renderer.delete_queue.add_framebuffer(renderer.framebuffer);
	renderer.framebuffer = VK_NULL_HANDLE;
	auto ret = renderer.swapchain_manager.recreate();
	if (!ret) {
		std::cout << "failed to recreate swapchain\n";
		return -1;
	}
	renderer.swap_info = ret.value();
	if (0 != create_framebuffer(renderer)) return -1;
	return 0;
}

int draw_frame(Renderer& renderer) {

	vkb::SwapchainAcquireInfo acquire_info;
	auto acquire_ret = renderer.swapchain_manager.acquire_image();
	if (acquire_ret.matches_error(vkb::SwapchainManagerError::swapchain_out_of_date)) {
		return 1;
	} else if (!acquire_ret.has_value()) {
		std::cout << "failed to acquire swapchain image\n";
		return -1;
	}

	acquire_info = acquire_ret.value();
	if (should_resize) return 1;

	renderer.dispatch.waitForFences(1, &renderer.fences[renderer.current_index], VK_TRUE, UINT64_MAX);
	renderer.dispatch.resetFences(1, &renderer.fences[renderer.current_index]);

	record_command_buffer(renderer, renderer.command_buffers[renderer.current_index], acquire_info.image_view);

	auto semaphores = renderer.swapchain_manager.get_submit_semaphores().value();

	VkSemaphore wait_semaphores[1] = { semaphores.wait };
	VkSemaphore signal_semaphores[1] = { semaphores.signal };
	VkPipelineStageFlags wait_stages[1] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };

	VkSubmitInfo submit_info = {};
	submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit_info.waitSemaphoreCount = 1;
	submit_info.pWaitSemaphores = wait_semaphores;
	submit_info.pWaitDstStageMask = wait_stages;
	submit_info.commandBufferCount = 1;
	submit_info.pCommandBuffers = &renderer.command_buffers[renderer.current_index];
	submit_info.signalSemaphoreCount = 1;
	submit_info.pSignalSemaphores = signal_semaphores;

	if (renderer.dispatch.queueSubmit(
	        renderer.graphics_queue, 1, &submit_info, renderer.fences[renderer.current_index]) != VK_SUCCESS) {
		std::cout << "failed to submit command buffer\n";
		return -1;
	}
	renderer.current_index = (renderer.current_index + 1) % MAX_FRAMES_IN_FLIGHT;
	if (should_resize) return 1;

	auto present_ret = renderer.swapchain_manager.present();

	if (present_ret.matches_error(vkb::SwapchainManagerError::swapchain_out_of_date)) {
		return 1;
	} else if (!present_ret) {
		std::cout << "failed to present swapchain image\n";
		return -1;
	}
	renderer.delete_queue.tick();
	renderer.current_time = glfwGetTime();
	return 0;
}

void cleanup(Renderer& renderer) {
	renderer.dispatch.deviceWaitIdle();

	for (auto& fence : renderer.fences) {
		renderer.dispatch.destroyFence(fence, nullptr);
	}
	renderer.dispatch.destroyCommandPool(renderer.command_pool, nullptr);

	renderer.dispatch.destroyPipeline(renderer.graphics_pipeline, nullptr);
	renderer.dispatch.destroyPipelineLayout(renderer.pipeline_layout, nullptr);
	renderer.dispatch.destroyFramebuffer(renderer.framebuffer, nullptr);
	renderer.dispatch.destroyRenderPass(renderer.render_pass, nullptr);

	renderer.delete_queue.destroy();
	renderer.swapchain_manager.destroy();

	vkb::destroy_device(renderer.device);
	vkb::destroy_surface(renderer.instance, renderer.surface);
	vkb::destroy_instance(renderer.instance);
	destroy_window_glfw(renderer.window);
}


void render_loop(Renderer* renderer) {
	while (is_running) {
		std::unique_lock<std::mutex> lg(main_mutex, std::try_to_lock);
		if (!lg.owns_lock()) {
			std::unique_lock<std::mutex> ulg(render_wait_mutex);
			render_wait_condition_variable.wait(ulg);
			continue;
		} else {
			int res = draw_frame(*renderer);
			if (res < 0) {
				is_running = false;
			}
			if (res == 1) {
				lg.unlock();
				std::unique_lock<std::mutex> ulg(render_wait_mutex);
				render_wait_condition_variable.wait(ulg);
			}
		}
	}
}

int main() {
	is_running = false;
	should_resize = false;
	Renderer renderer;

	if (0 != instance_initialization(renderer)) return -1;
	if (0 != device_initialization(renderer)) return -1;
	if (0 != get_queues(renderer)) return -1;
	if (0 != create_render_pass(renderer)) return -1;
	if (0 != create_framebuffer(renderer)) return -1;
	if (0 != create_graphics_pipeline(renderer)) return -1;
	if (0 != create_command_buffers(renderer)) return -1;
	is_running = true;
	renderer.current_time = glfwGetTime();
	if (run_multithreaded) {
		std::thread render_thread{ render_loop, &renderer };

		while (!glfwWindowShouldClose(renderer.window) && is_running) {
			glfwPollEvents();
			glfwWaitEvents();
		}
		is_running = false;
		render_wait_condition_variable.notify_one();
		render_thread.join();
	} else {
		while (!glfwWindowShouldClose(renderer.window) && is_running) {
			glfwPollEvents();
			int res = draw_frame(renderer);
			if (res < 0) {
				is_running = false;
			}
		}
	}
	cleanup(renderer);
	return 0;
}