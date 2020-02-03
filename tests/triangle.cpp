#include <stdio.h>

#include <memory>
#include <iostream>
#include <fstream>

#include "common.h"

struct Init
{
	GLFWwindow* window;
	vkb::Instance instance;
	VkSurfaceKHR surface;
	vkb::Device device;
	vkb::Swapchain swapchain;
};

struct RenderData
{
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkRenderPass renderPass;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;
	std::vector<VkCommandBuffer> commandBuffers;

	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	std::vector<VkFence> imagesInFlight;
	size_t currentFrame = 0;
};

void device_initialization (Init& init)
{
	init.window = create_window_glfw ();

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().setup_validation_layers ().build ();
	if (!instance_ret)
	{
		std::cout << instance_ret.error ().msg << "\n";
	}
	init.instance = instance_ret.value ();

	init.surface = create_surface_glfw (init.instance.instance, init.window);

	vkb::PhysicalDeviceSelector phys_device_selector (init.instance);
	auto phys_device_ret = phys_device_selector.set_surface (init.surface).select ();
	if (!phys_device_ret)
	{
		std::cout << phys_device_ret.error ().msg << "\n";
	}
	vkb::PhysicalDevice physical_device = phys_device_ret.value ();

	vkb::DeviceBuilder device_builder (physical_device);
	auto device_ret = device_builder.build ();
	if (!device_ret)
	{
		std::cout << device_ret.error ().msg << "\n";
	}
	init.device = device_ret.value ();

	vkb::SwapchainBuilder swapchain_builder (init.device);
	auto swap_ret =
	    swapchain_builder.use_default_format_selection ().use_default_present_mode_selection ().build ();
	if (!swap_ret)
	{
		std::cout << swap_ret.error ().msg << "\n";
	}
	init.swapchain = swap_ret.value ();
}

void get_queues (Init& init, RenderData& data)
{
	data.graphicsQueue = vkb::get_queue_graphics (init.device).value ();
	data.presentQueue = vkb::get_queue_graphics (init.device).value ();
}

void createImageViews (Init& init, RenderData& data)
{
	data.swapChainImageViews.resize (init.swapchain.images.size ());

	for (size_t i = 0; i < init.swapchain.images.size (); i++)
	{
		VkImageViewCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		createInfo.image = init.swapchain.images[i];
		createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		createInfo.format = init.swapchain.image_format;
		createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		createInfo.subresourceRange.baseMipLevel = 0;
		createInfo.subresourceRange.levelCount = 1;
		createInfo.subresourceRange.baseArrayLayer = 0;
		createInfo.subresourceRange.layerCount = 1;

		if (vkCreateImageView (init.device.device, &createInfo, nullptr, &data.swapChainImageViews[i]) != VK_SUCCESS)
		{
			throw std::runtime_error ("failed to create image views!");
		}
	}
}

void createRenderPass (Init& init, RenderData& data)
{
	VkAttachmentDescription colorAttachment = {};
	colorAttachment.format = init.swapchain.image_format;
	colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
	colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
	colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

	VkAttachmentReference colorAttachmentRef = {};
	colorAttachmentRef.attachment = 0;
	colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	VkSubpassDescription subpass = {};
	subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	subpass.colorAttachmentCount = 1;
	subpass.pColorAttachments = &colorAttachmentRef;

	VkSubpassDependency dependency = {};
	dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
	dependency.dstSubpass = 0;
	dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependency.srcAccessMask = 0;
	dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

	VkRenderPassCreateInfo renderPassInfo = {};
	renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	renderPassInfo.attachmentCount = 1;
	renderPassInfo.pAttachments = &colorAttachment;
	renderPassInfo.subpassCount = 1;
	renderPassInfo.pSubpasses = &subpass;
	renderPassInfo.dependencyCount = 1;
	renderPassInfo.pDependencies = &dependency;

	if (vkCreateRenderPass (init.device.device, &renderPassInfo, nullptr, &data.renderPass) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to create render pass!");
	}
}

std::vector<char> readFile (const std::string& filename)
{
	std::ifstream file (filename, std::ios::ate | std::ios::binary);

	if (!file.is_open ())
	{
		throw std::runtime_error ("failed to open file!");
	}

	size_t fileSize = (size_t)file.tellg ();
	std::vector<char> buffer (fileSize);

	file.seekg (0);
	file.read (buffer.data (), fileSize);

	file.close ();

	return buffer;
}

VkShaderModule createShaderModule (Init& init, const std::vector<char>& code)
{
	VkShaderModuleCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = code.size ();
	createInfo.pCode = reinterpret_cast<const uint32_t*> (code.data ());

	VkShaderModule shaderModule;
	if (vkCreateShaderModule (init.device.device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to create shader module!");
	}

	return shaderModule;
}

void createGraphicsPipeline (Init& init, RenderData& data)
{
	auto vertShaderCode = readFile ("vert.spv");
	auto fragShaderCode = readFile ("frag.spv");

	VkShaderModule vertShaderModule = createShaderModule (init, vertShaderCode);
	VkShaderModule fragShaderModule = createShaderModule (init, fragShaderCode);

	VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
	vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
	vertShaderStageInfo.module = vertShaderModule;
	vertShaderStageInfo.pName = "main";

	VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
	fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	fragShaderStageInfo.module = fragShaderModule;
	fragShaderStageInfo.pName = "main";

	VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

	VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
	vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	vertexInputInfo.vertexBindingDescriptionCount = 0;
	vertexInputInfo.vertexAttributeDescriptionCount = 0;

	VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
	inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	inputAssembly.primitiveRestartEnable = VK_FALSE;

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

	VkPipelineViewportStateCreateInfo viewportState = {};
	viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	viewportState.viewportCount = 1;
	viewportState.pViewports = &viewport;
	viewportState.scissorCount = 1;
	viewportState.pScissors = &scissor;

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

	VkPipelineColorBlendStateCreateInfo colorBlending = {};
	colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlending.logicOpEnable = VK_FALSE;
	colorBlending.logicOp = VK_LOGIC_OP_COPY;
	colorBlending.attachmentCount = 1;
	colorBlending.pAttachments = &colorBlendAttachment;
	colorBlending.blendConstants[0] = 0.0f;
	colorBlending.blendConstants[1] = 0.0f;
	colorBlending.blendConstants[2] = 0.0f;
	colorBlending.blendConstants[3] = 0.0f;

	VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutInfo.setLayoutCount = 0;
	pipelineLayoutInfo.pushConstantRangeCount = 0;

	if (vkCreatePipelineLayout (init.device.device, &pipelineLayoutInfo, nullptr, &data.pipelineLayout) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to create pipeline layout!");
	}

	VkGraphicsPipelineCreateInfo pipelineInfo = {};
	pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	pipelineInfo.stageCount = 2;
	pipelineInfo.pStages = shaderStages;
	pipelineInfo.pVertexInputState = &vertexInputInfo;
	pipelineInfo.pInputAssemblyState = &inputAssembly;
	pipelineInfo.pViewportState = &viewportState;
	pipelineInfo.pRasterizationState = &rasterizer;
	pipelineInfo.pMultisampleState = &multisampling;
	pipelineInfo.pColorBlendState = &colorBlending;
	pipelineInfo.layout = data.pipelineLayout;
	pipelineInfo.renderPass = data.renderPass;
	pipelineInfo.subpass = 0;
	pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;

	if (vkCreateGraphicsPipelines (
	        init.device.device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &data.graphicsPipeline) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to create graphics pipeline!");
	}

	vkDestroyShaderModule (init.device.device, fragShaderModule, nullptr);
	vkDestroyShaderModule (init.device.device, vertShaderModule, nullptr);
}

void createFramebuffers (Init& init, RenderData& data)
{
	data.swapChainFramebuffers.resize (data.swapChainImageViews.size ());

	for (size_t i = 0; i < data.swapChainImageViews.size (); i++)
	{
		VkImageView attachments[] = { data.swapChainImageViews[i] };

		VkFramebufferCreateInfo framebufferInfo = {};
		framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		framebufferInfo.renderPass = data.renderPass;
		framebufferInfo.attachmentCount = 1;
		framebufferInfo.pAttachments = attachments;
		framebufferInfo.width = init.swapchain.extent.width;
		framebufferInfo.height = init.swapchain.extent.height;
		framebufferInfo.layers = 1;

		if (vkCreateFramebuffer (
		        init.device.device, &framebufferInfo, nullptr, &data.swapChainFramebuffers[i]) != VK_SUCCESS)
		{
			throw std::runtime_error ("failed to create framebuffer!");
		}
	}
}

void createCommandPool (Init& init, RenderData& data)
{

	VkCommandPoolCreateInfo poolInfo = {};
	poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	poolInfo.queueFamilyIndex = vkb::get_queue_index_graphics (init.device);

	if (vkCreateCommandPool (init.device.device, &poolInfo, nullptr, &data.commandPool) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to create command pool!");
	}
}

void createCommandBuffers (Init& init, RenderData& data)
{
	data.commandBuffers.resize (data.swapChainFramebuffers.size ());

	VkCommandBufferAllocateInfo allocInfo = {};
	allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	allocInfo.commandPool = data.commandPool;
	allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	allocInfo.commandBufferCount = (uint32_t)data.commandBuffers.size ();

	if (vkAllocateCommandBuffers (init.device.device, &allocInfo, data.commandBuffers.data ()) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to allocate command buffers!");
	}

	for (size_t i = 0; i < data.commandBuffers.size (); i++)
	{
		VkCommandBufferBeginInfo beginInfo = {};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

		if (vkBeginCommandBuffer (data.commandBuffers[i], &beginInfo) != VK_SUCCESS)
		{
			throw std::runtime_error ("failed to begin recording command buffer!");
		}

		VkRenderPassBeginInfo renderPassInfo = {};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = data.renderPass;
		renderPassInfo.framebuffer = data.swapChainFramebuffers[i];
		renderPassInfo.renderArea.offset = { 0, 0 };
		renderPassInfo.renderArea.extent = init.swapchain.extent;

		VkClearValue clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };
		renderPassInfo.clearValueCount = 1;
		renderPassInfo.pClearValues = &clearColor;

		vkCmdBeginRenderPass (data.commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

		vkCmdBindPipeline (data.commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, data.graphicsPipeline);

		vkCmdDraw (data.commandBuffers[i], 3, 1, 0, 0);

		vkCmdEndRenderPass (data.commandBuffers[i]);

		if (vkEndCommandBuffer (data.commandBuffers[i]) != VK_SUCCESS)
		{
			throw std::runtime_error ("failed to record command buffer!");
		}
	}
}

void createSyncObjects (Init& init, RenderData& data)
{
	data.imageAvailableSemaphores.resize (init.swapchain.images.size ());
	data.renderFinishedSemaphores.resize (init.swapchain.images.size ());
	data.inFlightFences.resize (init.swapchain.images.size ());
	data.imagesInFlight.resize (init.swapchain.images.size (), VK_NULL_HANDLE);

	VkSemaphoreCreateInfo semaphoreInfo = {};
	semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

	VkFenceCreateInfo fenceInfo = {};
	fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	for (size_t i = 0; i < init.swapchain.images.size (); i++)
	{
		if (vkCreateSemaphore (
		        init.device.device, &semaphoreInfo, nullptr, &data.imageAvailableSemaphores[i]) != VK_SUCCESS ||
		    vkCreateSemaphore (
		        init.device.device, &semaphoreInfo, nullptr, &data.renderFinishedSemaphores[i]) != VK_SUCCESS ||
		    vkCreateFence (init.device.device, &fenceInfo, nullptr, &data.inFlightFences[i]) != VK_SUCCESS)
		{
			throw std::runtime_error ("failed to create synchronization objects for a frame!");
		}
	}
}

void drawFrame (Init& init, RenderData& data)
{
	vkWaitForFences (init.device.device, 1, &data.inFlightFences[data.currentFrame], VK_TRUE, UINT64_MAX);

	uint32_t imageIndex;
	vkAcquireNextImageKHR (init.device.device,
	    init.swapchain.swapchain,
	    UINT64_MAX,
	    data.imageAvailableSemaphores[data.currentFrame],
	    VK_NULL_HANDLE,
	    &imageIndex);

	if (data.imagesInFlight[imageIndex] != VK_NULL_HANDLE)
	{
		vkWaitForFences (init.device.device, 1, &data.imagesInFlight[imageIndex], VK_TRUE, UINT64_MAX);
	}
	data.imagesInFlight[imageIndex] = data.inFlightFences[data.currentFrame];

	VkSubmitInfo submitInfo = {};
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

	VkSemaphore waitSemaphores[] = { data.imageAvailableSemaphores[data.currentFrame] };
	VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
	submitInfo.waitSemaphoreCount = 1;
	submitInfo.pWaitSemaphores = waitSemaphores;
	submitInfo.pWaitDstStageMask = waitStages;

	submitInfo.commandBufferCount = 1;
	submitInfo.pCommandBuffers = &data.commandBuffers[imageIndex];

	VkSemaphore signalSemaphores[] = { data.renderFinishedSemaphores[data.currentFrame] };
	submitInfo.signalSemaphoreCount = 1;
	submitInfo.pSignalSemaphores = signalSemaphores;

	vkResetFences (init.device.device, 1, &data.inFlightFences[data.currentFrame]);

	if (vkQueueSubmit (data.graphicsQueue, 1, &submitInfo, data.inFlightFences[data.currentFrame]) != VK_SUCCESS)
	{
		throw std::runtime_error ("failed to submit draw command buffer!");
	}

	VkPresentInfoKHR presentInfo = {};
	presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

	presentInfo.waitSemaphoreCount = 1;
	presentInfo.pWaitSemaphores = signalSemaphores;

	VkSwapchainKHR swapChains[] = { init.swapchain.swapchain };
	presentInfo.swapchainCount = 1;
	presentInfo.pSwapchains = swapChains;

	presentInfo.pImageIndices = &imageIndex;

	vkQueuePresentKHR (data.presentQueue, &presentInfo);

	data.currentFrame = (data.currentFrame + 1) % init.swapchain.images.size ();
}

void cleanup (Init& init, RenderData& data)
{
	for (size_t i = 0; i < init.swapchain.images.size (); i++)
	{
		vkDestroySemaphore (init.device.device, data.renderFinishedSemaphores[i], nullptr);
		vkDestroySemaphore (init.device.device, data.imageAvailableSemaphores[i], nullptr);
		vkDestroyFence (init.device.device, data.inFlightFences[i], nullptr);
	}

	vkDestroyCommandPool (init.device.device, data.commandPool, nullptr);

	for (auto framebuffer : data.swapChainFramebuffers)
	{
		vkDestroyFramebuffer (init.device.device, framebuffer, nullptr);
	}

	vkDestroyPipeline (init.device.device, data.graphicsPipeline, nullptr);
	vkDestroyPipelineLayout (init.device.device, data.pipelineLayout, nullptr);
	vkDestroyRenderPass (init.device.device, data.renderPass, nullptr);

	for (auto imageView : data.swapChainImageViews)
	{
		vkDestroyImageView (init.device.device, imageView, nullptr);
	}

	vkb::destroy_swapchain (init.swapchain);
	vkb::destroy_device (init.device);
	vkDestroySurfaceKHR (init.instance.instance, init.surface, nullptr);
	vkb::destroy_instance (init.instance);
	destroy_window_glfw (init.window);
}

int main ()
{
	Init init;
	RenderData render_data;


	device_initialization (init);
	get_queues (init, render_data);
	createImageViews (init, render_data);
	createRenderPass (init, render_data);
	createGraphicsPipeline (init, render_data);
	createFramebuffers (init, render_data);
	createCommandPool (init, render_data);
	createCommandBuffers (init, render_data);
	createSyncObjects (init, render_data);

	while (!glfwWindowShouldClose (init.window))
	{
		glfwPollEvents ();
		drawFrame (init, render_data);
	}
	vkDeviceWaitIdle (init.device.device);

	cleanup (init, render_data);
	return 0;
}