#include <stdio.h>

#include <memory>
#include <iostream>
#include <fstream>

#include "../tests/common.h"

const int MAX_FRAMES_IN_FLIGHT = 2;

struct Init {
	GLFWwindow* window;
	vkb::Instance instance;
	VkSurfaceKHR surface;
	vkb::Device device;
	vkb::Swapchain swapchain;
};

struct RenderData {
	VkQueue graphics_queue;
	VkQueue present_queue;

	std::vector<VkImage> swapchain_images;
	std::vector<VkImageView> swapchain_image_views;
	std::vector<VkFramebuffer> framebuffers;

	VkRenderPass render_pass;
	VkPipelineLayout pipeline_layout;
	VkPipeline graphics_pipeline;

	VkCommandPool command_pool;
	std::vector<VkCommandBuffer> command_buffers;

	std::vector<VkSemaphore> available_semaphores;
	std::vector<VkSemaphore> finished_semaphore;
	std::vector<VkFence> in_flight_fences;
	std::vector<VkFence> image_in_flight;
	size_t current_frame = 0;
};

int device_initialization (Init& init) {
	init.window = create_window_glfw (false);

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.use_default_debug_messenger ().request_validation_layers ().build ();
	if (!instance_ret) {
		std::cout << vkb::to_string (instance_ret.error ().type) << "\n";
		return -1;
	}
	init.instance = instance_ret.value ();

	init.surface = create_surface_glfw (init.instance.instance, init.window);

	vkb::PhysicalDeviceSelector phys_device_selector (init.instance);
	auto phys_device_ret = phys_device_selector.set_surface (init.surface).select ();
	if (!phys_device_ret) {
		std::cout << vkb::to_string (phys_device_ret.error ().type) << "\n";
		return -1;
	}
	vkb::PhysicalDevice physical_device = phys_device_ret.value ();

	vkb::DeviceBuilder device_builder{ physical_device };
	auto device_ret = device_builder.build ();
	if (!device_ret) {
		std::cout << vkb::to_string (device_ret.error ().type) << "\n";
		return -1;
	}
	init.device = device_ret.value ();

	vkb::SwapchainBuilder swapchain_builder{ init.device };
	auto swap_ret =
	    swapchain_builder.use_default_format_selection ().use_default_present_mode_selection ().build ();
	if (!swap_ret) {
		std::cout << vkb::to_string (swap_ret.error ().type) << "\n";
		return -1;
	}
	init.swapchain = swap_ret.value ();
	return 0;
}

int get_queues (Init& init, RenderData& data) {
	auto gq = init.device.get_queue (vkb::QueueType::graphics);
	if (!gq.has_value ()) {
		std::cout << "failed to get graphics queue: " << vkb::to_string (gq.error ().type) << "\n";
		return -1;
	}
	data.graphics_queue = gq.value ();

	auto pq = init.device.get_queue (vkb::QueueType::present);
	if (!pq.has_value ()) {
		std::cout << "failed to get present queue: " << vkb::to_string (gq.error ().type) << "\n";
		return -1;
	}
	data.present_queue = pq.value ();
	return 0;
}

int create_render_pass (Init& init, RenderData& data) {
	VkAttachmentDescription color_attachment = {};
	color_attachment.format = init.swapchain.image_format;
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

	if (vkCreateRenderPass (init.device.device, &render_pass_info, nullptr, &data.render_pass) != VK_SUCCESS) {
		std::cout << "failed to create render pass\n";
		return -1; // failed to create render pass!
	}
	return 0;
}

std::vector<char> readFile (const std::string& filename) {
	std::ifstream file (filename, std::ios::ate | std::ios::binary);

	if (!file.is_open ()) {
		throw std::runtime_error ("failed to open file!");
	}

	size_t file_size = (size_t)file.tellg ();
	std::vector<char> buffer (file_size);

	file.seekg (0);
	file.read (buffer.data (), static_cast<std::streamsize> (file_size));

	file.close ();

	return buffer;
}

VkShaderModule createShaderModule (Init& init, const std::vector<char>& code) {
	VkShaderModuleCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	create_info.codeSize = code.size ();
	create_info.pCode = reinterpret_cast<const uint32_t*> (code.data ());

	VkShaderModule shaderModule;
	if (vkCreateShaderModule (init.device.device, &create_info, nullptr, &shaderModule) != VK_SUCCESS) {
		return VK_NULL_HANDLE; // failed to create shader module
	}

	return shaderModule;
}

int create_graphics_pipeline (Init& init, RenderData& data) {
	auto vert_code = readFile ("vert.spv");
	auto frag_code = readFile ("frag.spv");

	VkShaderModule vert_module = createShaderModule (init, vert_code);
	VkShaderModule frag_module = createShaderModule (init, frag_code);
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
	viewport.width = (float)init.swapchain.extent.width;
	viewport.height = (float)init.swapchain.extent.height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor = {};
	scissor.offset = { 0, 0 };
	scissor.extent = init.swapchain.extent;

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

	if (vkCreatePipelineLayout (
	        init.device.device, &pipeline_layout_info, nullptr, &data.pipeline_layout) != VK_SUCCESS) {
		std::cout << "failed to create pipeline layout\n";
		return -1; // failed to create pipeline layout
	}

	VkGraphicsPipelineCreateInfo pipelineInfo = {};
	pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	pipelineInfo.stageCount = 2;
	pipelineInfo.pStages = shader_stages;
	pipelineInfo.pVertexInputState = &vertex_input_info;
	pipelineInfo.pInputAssemblyState = &input_assembly;
	pipelineInfo.pViewportState = &viewport_state;
	pipelineInfo.pRasterizationState = &rasterizer;
	pipelineInfo.pMultisampleState = &multisampling;
	pipelineInfo.pColorBlendState = &color_blending;
	pipelineInfo.layout = data.pipeline_layout;
	pipelineInfo.renderPass = data.render_pass;
	pipelineInfo.subpass = 0;
	pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;

	if (vkCreateGraphicsPipelines (
	        init.device.device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &data.graphics_pipeline) != VK_SUCCESS) {
		std::cout << "failed to create pipline\n";
		return -1; // failed to create graphics pipeline
	}

	vkDestroyShaderModule (init.device.device, frag_module, nullptr);
	vkDestroyShaderModule (init.device.device, vert_module, nullptr);
	return 0;
}

int create_framebuffers (Init& init, RenderData& data) {
	data.swapchain_images = init.swapchain.get_images ().value ();
	data.swapchain_image_views = init.swapchain.get_image_views ().value ();

	data.framebuffers.resize (data.swapchain_image_views.size ());

	for (size_t i = 0; i < data.swapchain_image_views.size (); i++) {
		VkImageView attachments[] = { data.swapchain_image_views[i] };

		VkFramebufferCreateInfo framebuffer_info = {};
		framebuffer_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		framebuffer_info.renderPass = data.render_pass;
		framebuffer_info.attachmentCount = 1;
		framebuffer_info.pAttachments = attachments;
		framebuffer_info.width = init.swapchain.extent.width;
		framebuffer_info.height = init.swapchain.extent.height;
		framebuffer_info.layers = 1;

		if (vkCreateFramebuffer (init.device.device, &framebuffer_info, nullptr, &data.framebuffers[i]) != VK_SUCCESS) {
			return -1; // failed to create framebuffer
		}
	}
	return 0;
}

int create_command_pool (Init& init, RenderData& data) {
	VkCommandPoolCreateInfo pool_info = {};
	pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	pool_info.queueFamilyIndex = init.device.get_queue_index (vkb::QueueType::graphics).value ();

	if (vkCreateCommandPool (init.device.device, &pool_info, nullptr, &data.command_pool) != VK_SUCCESS) {
		std::cout << "failed to create command pool\n";
		return -1; // failed to create command pool
	}
	return 0;
}

int create_command_buffers (Init& init, RenderData& data) {
	data.command_buffers.resize (data.framebuffers.size ());

	VkCommandBufferAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	allocInfo.commandPool = data.command_pool;
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	allocInfo.commandBufferCount = (uint32_t)data.command_buffers.size ();

	if (vkAllocateCommandBuffers (init.device.device, &allocInfo, data.command_buffers.data ()) != VK_SUCCESS) {
		return -1; // failed to allocate command buffers;
	}

	for (size_t i = 0; i < data.command_buffers.size (); i++) {
		VkCommandBufferBeginInfo begin_info = {};
		begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

		if (vkBeginCommandBuffer (data.command_buffers[i], &begin_info) != VK_SUCCESS) {
			return -1; // failed to begin recording command buffer
		}

		VkRenderPassBeginInfo render_pass_info = {};
		render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		render_pass_info.renderPass = data.render_pass;
		render_pass_info.framebuffer = data.framebuffers[i];
		render_pass_info.renderArea.offset = { 0, 0 };
		render_pass_info.renderArea.extent = init.swapchain.extent;

		VkClearValue clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };
		render_pass_info.clearValueCount = 1;
		render_pass_info.pClearValues = &clearColor;

		vkCmdBeginRenderPass (data.command_buffers[i], &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);

		vkCmdBindPipeline (data.command_buffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, data.graphics_pipeline);

		vkCmdDraw (data.command_buffers[i], 3, 1, 0, 0);

		vkCmdEndRenderPass (data.command_buffers[i]);

		if (vkEndCommandBuffer (data.command_buffers[i]) != VK_SUCCESS) {
			std::cout << "failed to record command buffer\n";
			return -1; // failed to record command buffer!
		}
	}
	return 0;
}

int create_sync_objects (Init& init, RenderData& data) {
	data.available_semaphores.resize (MAX_FRAMES_IN_FLIGHT);
	data.finished_semaphore.resize (MAX_FRAMES_IN_FLIGHT);
	data.in_flight_fences.resize (MAX_FRAMES_IN_FLIGHT);
	data.image_in_flight.resize (init.swapchain.image_count, VK_NULL_HANDLE);

	VkSemaphoreCreateInfo semaphore_info = {};
	semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

	VkFenceCreateInfo fence_info = {};
	fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
		if (vkCreateSemaphore (init.device.device, &semaphore_info, nullptr, &data.available_semaphores[i]) != VK_SUCCESS ||
		    vkCreateSemaphore (init.device.device, &semaphore_info, nullptr, &data.finished_semaphore[i]) != VK_SUCCESS ||
		    vkCreateFence (init.device.device, &fence_info, nullptr, &data.in_flight_fences[i]) != VK_SUCCESS) {
			std::cout << "failed to create sync objects\n";
			return -1; // failed to create synchronization objects for a frame
		}
	}
	return 0;
}

int draw_frame (Init& init, RenderData& data) {
	vkWaitForFences (init.device.device, 1, &data.in_flight_fences[data.current_frame], VK_TRUE, UINT64_MAX);

	uint32_t image_index = 0;
	vkAcquireNextImageKHR (init.device.device,
	    init.swapchain.swapchain,
	    UINT64_MAX,
	    data.available_semaphores[data.current_frame],
	    VK_NULL_HANDLE,
	    &image_index);

	if (data.image_in_flight[image_index] != VK_NULL_HANDLE) {
		vkWaitForFences (init.device.device, 1, &data.image_in_flight[image_index], VK_TRUE, UINT64_MAX);
	}
	data.image_in_flight[image_index] = data.in_flight_fences[data.current_frame];

	VkSubmitInfo submitInfo = {};
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

	VkSemaphore wait_semaphores[] = { data.available_semaphores[data.current_frame] };
	VkPipelineStageFlags wait_stages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
	submitInfo.waitSemaphoreCount = 1;
	submitInfo.pWaitSemaphores = wait_semaphores;
	submitInfo.pWaitDstStageMask = wait_stages;

	submitInfo.commandBufferCount = 1;
	submitInfo.pCommandBuffers = &data.command_buffers[image_index];

	VkSemaphore signal_semaphores[] = { data.finished_semaphore[data.current_frame] };
	submitInfo.signalSemaphoreCount = 1;
	submitInfo.pSignalSemaphores = signal_semaphores;

	vkResetFences (init.device.device, 1, &data.in_flight_fences[data.current_frame]);

	if (vkQueueSubmit (data.graphics_queue, 1, &submitInfo, data.in_flight_fences[data.current_frame]) != VK_SUCCESS) {
		std::cout << "failed to submit draw command buffer\n";
		return -1; //"failed to submit draw command buffer
	}

	VkPresentInfoKHR present_info = {};
	present_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

	present_info.waitSemaphoreCount = 1;
	present_info.pWaitSemaphores = signal_semaphores;

	VkSwapchainKHR swapChains[] = { init.swapchain.swapchain };
	present_info.swapchainCount = 1;
	present_info.pSwapchains = swapChains;

	present_info.pImageIndices = &image_index;

	vkQueuePresentKHR (data.present_queue, &present_info);

	data.current_frame = (data.current_frame + 1) % MAX_FRAMES_IN_FLIGHT;
	return 0;
}

void cleanup (Init& init, RenderData& data) {
	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
		vkDestroySemaphore (init.device.device, data.finished_semaphore[i], nullptr);
		vkDestroySemaphore (init.device.device, data.available_semaphores[i], nullptr);
		vkDestroyFence (init.device.device, data.in_flight_fences[i], nullptr);
	}

	vkDestroyCommandPool (init.device.device, data.command_pool, nullptr);

	for (auto framebuffer : data.framebuffers) {
		vkDestroyFramebuffer (init.device.device, framebuffer, nullptr);
	}

	vkDestroyPipeline (init.device.device, data.graphics_pipeline, nullptr);
	vkDestroyPipelineLayout (init.device.device, data.pipeline_layout, nullptr);
	vkDestroyRenderPass (init.device.device, data.render_pass, nullptr);

	for (auto imageView : data.swapchain_image_views) {
		vkDestroyImageView (init.device.device, imageView, nullptr);
	}

	vkb::destroy_swapchain (init.swapchain);
	vkb::destroy_device (init.device);
	vkDestroySurfaceKHR (init.instance.instance, init.surface, nullptr);
	vkb::destroy_instance (init.instance);
	destroy_window_glfw (init.window);
}

int main () {
	Init init;
	RenderData render_data;

	if (0 != device_initialization (init)) return -1;
	if (0 != get_queues (init, render_data)) return -1;
	if (0 != create_render_pass (init, render_data)) return -1;
	if (0 != create_graphics_pipeline (init, render_data)) return -1;
	if (0 != create_framebuffers (init, render_data)) return -1;
	if (0 != create_command_pool (init, render_data)) return -1;
	if (0 != create_command_buffers (init, render_data)) return -1;
	if (0 != create_sync_objects (init, render_data)) return -1;

	while (!glfwWindowShouldClose (init.window)) {
		glfwPollEvents ();
		int res = draw_frame (init, render_data);
		if (res != 0) {
			std::cout << "failed to draw frame \n";
			return -1;
		}
	}
	vkDeviceWaitIdle (init.device.device);

	cleanup (init, render_data);
	return 0;
}