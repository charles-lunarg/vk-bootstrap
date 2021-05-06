
#pragma once

#include <vulkan/vulkan.h>

namespace vkb {

struct DispatchTable {
	DispatchTable() = default;
	DispatchTable(VkDevice const& device, PFN_vkGetDeviceProcAddr const& procAddr) {
#ifdef VK_VERSION_1_0
		getDeviceQueue = (PFN_vkGetDeviceQueue)procAddr(device, "vkGetDeviceQueue");
		queueSubmit = (PFN_vkQueueSubmit)procAddr(device, "vkQueueSubmit");
		queueWaitIdle = (PFN_vkQueueWaitIdle)procAddr(device, "vkQueueWaitIdle");
		deviceWaitIdle = (PFN_vkDeviceWaitIdle)procAddr(device, "vkDeviceWaitIdle");
		allocateMemory = (PFN_vkAllocateMemory)procAddr(device, "vkAllocateMemory");
		freeMemory = (PFN_vkFreeMemory)procAddr(device, "vkFreeMemory");
		mapMemory = (PFN_vkMapMemory)procAddr(device, "vkMapMemory");
		unmapMemory = (PFN_vkUnmapMemory)procAddr(device, "vkUnmapMemory");
		flushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)procAddr(device, "vkFlushMappedMemoryRanges");
		invalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)procAddr(device, "vkInvalidateMappedMemoryRanges");
		getDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)procAddr(device, "vkGetDeviceMemoryCommitment");
		bindBufferMemory = (PFN_vkBindBufferMemory)procAddr(device, "vkBindBufferMemory");
		bindImageMemory = (PFN_vkBindImageMemory)procAddr(device, "vkBindImageMemory");
		getBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)procAddr(device, "vkGetBufferMemoryRequirements");
		getImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)procAddr(device, "vkGetImageMemoryRequirements");
		getImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)procAddr(device, "vkGetImageSparseMemoryRequirements");
		queueBindSparse = (PFN_vkQueueBindSparse)procAddr(device, "vkQueueBindSparse");
		createFence = (PFN_vkCreateFence)procAddr(device, "vkCreateFence");
		destroyFence = (PFN_vkDestroyFence)procAddr(device, "vkDestroyFence");
		resetFences = (PFN_vkResetFences)procAddr(device, "vkResetFences");
		getFenceStatus = (PFN_vkGetFenceStatus)procAddr(device, "vkGetFenceStatus");
		waitForFences = (PFN_vkWaitForFences)procAddr(device, "vkWaitForFences");
		createSemaphore = (PFN_vkCreateSemaphore)procAddr(device, "vkCreateSemaphore");
		destroySemaphore = (PFN_vkDestroySemaphore)procAddr(device, "vkDestroySemaphore");
		createEvent = (PFN_vkCreateEvent)procAddr(device, "vkCreateEvent");
		destroyEvent = (PFN_vkDestroyEvent)procAddr(device, "vkDestroyEvent");
		getEventStatus = (PFN_vkGetEventStatus)procAddr(device, "vkGetEventStatus");
		setEvent = (PFN_vkSetEvent)procAddr(device, "vkSetEvent");
		resetEvent = (PFN_vkResetEvent)procAddr(device, "vkResetEvent");
		createQueryPool = (PFN_vkCreateQueryPool)procAddr(device, "vkCreateQueryPool");
		destroyQueryPool = (PFN_vkDestroyQueryPool)procAddr(device, "vkDestroyQueryPool");
		getQueryPoolResults = (PFN_vkGetQueryPoolResults)procAddr(device, "vkGetQueryPoolResults");
		createBuffer = (PFN_vkCreateBuffer)procAddr(device, "vkCreateBuffer");
		destroyBuffer = (PFN_vkDestroyBuffer)procAddr(device, "vkDestroyBuffer");
		createBufferView = (PFN_vkCreateBufferView)procAddr(device, "vkCreateBufferView");
		destroyBufferView = (PFN_vkDestroyBufferView)procAddr(device, "vkDestroyBufferView");
		createImage = (PFN_vkCreateImage)procAddr(device, "vkCreateImage");
		destroyImage = (PFN_vkDestroyImage)procAddr(device, "vkDestroyImage");
		getImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)procAddr(device, "vkGetImageSubresourceLayout");
		createImageView = (PFN_vkCreateImageView)procAddr(device, "vkCreateImageView");
		destroyImageView = (PFN_vkDestroyImageView)procAddr(device, "vkDestroyImageView");
		createShaderModule = (PFN_vkCreateShaderModule)procAddr(device, "vkCreateShaderModule");
		destroyShaderModule = (PFN_vkDestroyShaderModule)procAddr(device, "vkDestroyShaderModule");
		createPipelineCache = (PFN_vkCreatePipelineCache)procAddr(device, "vkCreatePipelineCache");
		destroyPipelineCache = (PFN_vkDestroyPipelineCache)procAddr(device, "vkDestroyPipelineCache");
		getPipelineCacheData = (PFN_vkGetPipelineCacheData)procAddr(device, "vkGetPipelineCacheData");
		mergePipelineCaches = (PFN_vkMergePipelineCaches)procAddr(device, "vkMergePipelineCaches");
		createGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)procAddr(device, "vkCreateGraphicsPipelines");
		createComputePipelines = (PFN_vkCreateComputePipelines)procAddr(device, "vkCreateComputePipelines");
		destroyPipeline = (PFN_vkDestroyPipeline)procAddr(device, "vkDestroyPipeline");
		createPipelineLayout = (PFN_vkCreatePipelineLayout)procAddr(device, "vkCreatePipelineLayout");
		destroyPipelineLayout = (PFN_vkDestroyPipelineLayout)procAddr(device, "vkDestroyPipelineLayout");
		createSampler = (PFN_vkCreateSampler)procAddr(device, "vkCreateSampler");
		destroySampler = (PFN_vkDestroySampler)procAddr(device, "vkDestroySampler");
		createDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)procAddr(device, "vkCreateDescriptorSetLayout");
		destroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)procAddr(device, "vkDestroyDescriptorSetLayout");
		createDescriptorPool = (PFN_vkCreateDescriptorPool)procAddr(device, "vkCreateDescriptorPool");
		destroyDescriptorPool = (PFN_vkDestroyDescriptorPool)procAddr(device, "vkDestroyDescriptorPool");
		resetDescriptorPool = (PFN_vkResetDescriptorPool)procAddr(device, "vkResetDescriptorPool");
		allocateDescriptorSets = (PFN_vkAllocateDescriptorSets)procAddr(device, "vkAllocateDescriptorSets");
		freeDescriptorSets = (PFN_vkFreeDescriptorSets)procAddr(device, "vkFreeDescriptorSets");
		updateDescriptorSets = (PFN_vkUpdateDescriptorSets)procAddr(device, "vkUpdateDescriptorSets");
		createFramebuffer = (PFN_vkCreateFramebuffer)procAddr(device, "vkCreateFramebuffer");
		destroyFramebuffer = (PFN_vkDestroyFramebuffer)procAddr(device, "vkDestroyFramebuffer");
		createRenderPass = (PFN_vkCreateRenderPass)procAddr(device, "vkCreateRenderPass");
		destroyRenderPass = (PFN_vkDestroyRenderPass)procAddr(device, "vkDestroyRenderPass");
		getRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)procAddr(device, "vkGetRenderAreaGranularity");
		createCommandPool = (PFN_vkCreateCommandPool)procAddr(device, "vkCreateCommandPool");
		destroyCommandPool = (PFN_vkDestroyCommandPool)procAddr(device, "vkDestroyCommandPool");
		resetCommandPool = (PFN_vkResetCommandPool)procAddr(device, "vkResetCommandPool");
		allocateCommandBuffers = (PFN_vkAllocateCommandBuffers)procAddr(device, "vkAllocateCommandBuffers");
		freeCommandBuffers = (PFN_vkFreeCommandBuffers)procAddr(device, "vkFreeCommandBuffers");
		beginCommandBuffer = (PFN_vkBeginCommandBuffer)procAddr(device, "vkBeginCommandBuffer");
		endCommandBuffer = (PFN_vkEndCommandBuffer)procAddr(device, "vkEndCommandBuffer");
		resetCommandBuffer = (PFN_vkResetCommandBuffer)procAddr(device, "vkResetCommandBuffer");
		cmdBindPipeline = (PFN_vkCmdBindPipeline)procAddr(device, "vkCmdBindPipeline");
		cmdSetViewport = (PFN_vkCmdSetViewport)procAddr(device, "vkCmdSetViewport");
		cmdSetScissor = (PFN_vkCmdSetScissor)procAddr(device, "vkCmdSetScissor");
		cmdSetLineWidth = (PFN_vkCmdSetLineWidth)procAddr(device, "vkCmdSetLineWidth");
		cmdSetDepthBias = (PFN_vkCmdSetDepthBias)procAddr(device, "vkCmdSetDepthBias");
		cmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)procAddr(device, "vkCmdSetBlendConstants");
		cmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)procAddr(device, "vkCmdSetDepthBounds");
		cmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)procAddr(device, "vkCmdSetStencilCompareMask");
		cmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)procAddr(device, "vkCmdSetStencilWriteMask");
		cmdSetStencilReference = (PFN_vkCmdSetStencilReference)procAddr(device, "vkCmdSetStencilReference");
		cmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)procAddr(device, "vkCmdBindDescriptorSets");
		cmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)procAddr(device, "vkCmdBindIndexBuffer");
		cmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)procAddr(device, "vkCmdBindVertexBuffers");
		cmdDraw = (PFN_vkCmdDraw)procAddr(device, "vkCmdDraw");
		cmdDrawIndexed = (PFN_vkCmdDrawIndexed)procAddr(device, "vkCmdDrawIndexed");
		cmdDrawIndirect = (PFN_vkCmdDrawIndirect)procAddr(device, "vkCmdDrawIndirect");
		cmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)procAddr(device, "vkCmdDrawIndexedIndirect");
		cmdDispatch = (PFN_vkCmdDispatch)procAddr(device, "vkCmdDispatch");
		cmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)procAddr(device, "vkCmdDispatchIndirect");
		cmdCopyBuffer = (PFN_vkCmdCopyBuffer)procAddr(device, "vkCmdCopyBuffer");
		cmdCopyImage = (PFN_vkCmdCopyImage)procAddr(device, "vkCmdCopyImage");
		cmdBlitImage = (PFN_vkCmdBlitImage)procAddr(device, "vkCmdBlitImage");
		cmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)procAddr(device, "vkCmdCopyBufferToImage");
		cmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)procAddr(device, "vkCmdCopyImageToBuffer");
		cmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)procAddr(device, "vkCmdUpdateBuffer");
		cmdFillBuffer = (PFN_vkCmdFillBuffer)procAddr(device, "vkCmdFillBuffer");
		cmdClearColorImage = (PFN_vkCmdClearColorImage)procAddr(device, "vkCmdClearColorImage");
		cmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)procAddr(device, "vkCmdClearDepthStencilImage");
		cmdClearAttachments = (PFN_vkCmdClearAttachments)procAddr(device, "vkCmdClearAttachments");
		cmdResolveImage = (PFN_vkCmdResolveImage)procAddr(device, "vkCmdResolveImage");
		cmdSetEvent = (PFN_vkCmdSetEvent)procAddr(device, "vkCmdSetEvent");
		cmdResetEvent = (PFN_vkCmdResetEvent)procAddr(device, "vkCmdResetEvent");
		cmdWaitEvents = (PFN_vkCmdWaitEvents)procAddr(device, "vkCmdWaitEvents");
		cmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)procAddr(device, "vkCmdPipelineBarrier");
		cmdBeginQuery = (PFN_vkCmdBeginQuery)procAddr(device, "vkCmdBeginQuery");
		cmdEndQuery = (PFN_vkCmdEndQuery)procAddr(device, "vkCmdEndQuery");
		cmdResetQueryPool = (PFN_vkCmdResetQueryPool)procAddr(device, "vkCmdResetQueryPool");
		cmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)procAddr(device, "vkCmdWriteTimestamp");
		cmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)procAddr(device, "vkCmdCopyQueryPoolResults");
		cmdPushConstants = (PFN_vkCmdPushConstants)procAddr(device, "vkCmdPushConstants");
		cmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)procAddr(device, "vkCmdBeginRenderPass");
		cmdNextSubpass = (PFN_vkCmdNextSubpass)procAddr(device, "vkCmdNextSubpass");
		cmdEndRenderPass = (PFN_vkCmdEndRenderPass)procAddr(device, "vkCmdEndRenderPass");
		cmdExecuteCommands = (PFN_vkCmdExecuteCommands)procAddr(device, "vkCmdExecuteCommands");
#endif
#ifdef VK_VERSION_1_1
		bindBufferMemory2 = (PFN_vkBindBufferMemory2)procAddr(device, "vkBindBufferMemory2");
		bindImageMemory2 = (PFN_vkBindImageMemory2)procAddr(device, "vkBindImageMemory2");
		getDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)procAddr(device, "vkGetDeviceGroupPeerMemoryFeatures");
		cmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)procAddr(device, "vkCmdSetDeviceMask");
		cmdDispatchBase = (PFN_vkCmdDispatchBase)procAddr(device, "vkCmdDispatchBase");
		getImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)procAddr(device, "vkGetImageMemoryRequirements2");
		getBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)procAddr(device, "vkGetBufferMemoryRequirements2");
		getImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)procAddr(device, "vkGetImageSparseMemoryRequirements2");
		trimCommandPool = (PFN_vkTrimCommandPool)procAddr(device, "vkTrimCommandPool");
		getDeviceQueue2 = (PFN_vkGetDeviceQueue2)procAddr(device, "vkGetDeviceQueue2");
		createSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)procAddr(device, "vkCreateSamplerYcbcrConversion");
		destroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)procAddr(device, "vkDestroySamplerYcbcrConversion");
		createDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)procAddr(device, "vkCreateDescriptorUpdateTemplate");
		destroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)procAddr(device, "vkDestroyDescriptorUpdateTemplate");
		updateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)procAddr(device, "vkUpdateDescriptorSetWithTemplate");
		getDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)procAddr(device, "vkGetDescriptorSetLayoutSupport");
#endif
#ifdef VK_VERSION_1_2
		cmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)procAddr(device, "vkCmdDrawIndirectCount");
		cmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)procAddr(device, "vkCmdDrawIndexedIndirectCount");
		createRenderPass2 = (PFN_vkCreateRenderPass2)procAddr(device, "vkCreateRenderPass2");
		cmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)procAddr(device, "vkCmdBeginRenderPass2");
		cmdNextSubpass2 = (PFN_vkCmdNextSubpass2)procAddr(device, "vkCmdNextSubpass2");
		cmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)procAddr(device, "vkCmdEndRenderPass2");
		resetQueryPool = (PFN_vkResetQueryPool)procAddr(device, "vkResetQueryPool");
		getSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)procAddr(device, "vkGetSemaphoreCounterValue");
		waitSemaphores = (PFN_vkWaitSemaphores)procAddr(device, "vkWaitSemaphores");
		signalSemaphore = (PFN_vkSignalSemaphore)procAddr(device, "vkSignalSemaphore");
		getBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)procAddr(device, "vkGetBufferDeviceAddress");
		getBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)procAddr(device, "vkGetBufferOpaqueCaptureAddress");
		getDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSwapchainKHR_LOAD
#define PFN_vkCreateSwapchainKHR_LOAD
		createSwapchainKHR = (PFN_vkCreateSwapchainKHR)procAddr(device, "vkCreateSwapchainKHR");
#endif
#ifndef PFN_vkDestroySwapchainKHR_LOAD
#define PFN_vkDestroySwapchainKHR_LOAD
		destroySwapchainKHR = (PFN_vkDestroySwapchainKHR)procAddr(device, "vkDestroySwapchainKHR");
#endif
#ifndef PFN_vkGetSwapchainImagesKHR_LOAD
#define PFN_vkGetSwapchainImagesKHR_LOAD
		getSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)procAddr(device, "vkGetSwapchainImagesKHR");
#endif
#ifndef PFN_vkAcquireNextImageKHR_LOAD
#define PFN_vkAcquireNextImageKHR_LOAD
		acquireNextImageKHR = (PFN_vkAcquireNextImageKHR)procAddr(device, "vkAcquireNextImageKHR");
#endif
#ifndef PFN_vkQueuePresentKHR_LOAD
#define PFN_vkQueuePresentKHR_LOAD
		queuePresentKHR = (PFN_vkQueuePresentKHR)procAddr(device, "vkQueuePresentKHR");
#endif
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
		getDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)procAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
		getDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)procAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif
#ifndef PFN_vkAcquireNextImage2KHR_LOAD
#define PFN_vkAcquireNextImage2KHR_LOAD
		acquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)procAddr(device, "vkAcquireNextImage2KHR");
#endif
#endif
#if defined(VK_KHR_display_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSharedSwapchainsKHR_LOAD
#define PFN_vkCreateSharedSwapchainsKHR_LOAD
		createSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)procAddr(device, "vkCreateSharedSwapchainsKHR");
#endif
#endif
#if defined(VK_ANDROID_native_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainGrallocUsageANDROID_LOAD
#define PFN_vkGetSwapchainGrallocUsageANDROID_LOAD
		getSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)procAddr(device, "vkGetSwapchainGrallocUsageANDROID");
#endif
#ifndef PFN_vkAcquireImageANDROID_LOAD
#define PFN_vkAcquireImageANDROID_LOAD
		acquireImageANDROID = (PFN_vkAcquireImageANDROID)procAddr(device, "vkAcquireImageANDROID");
#endif
#ifndef PFN_vkQueueSignalReleaseImageANDROID_LOAD
#define PFN_vkQueueSignalReleaseImageANDROID_LOAD
		queueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)procAddr(device, "vkQueueSignalReleaseImageANDROID");
#endif
#ifndef PFN_vkGetSwapchainGrallocUsage2ANDROID_LOAD
#define PFN_vkGetSwapchainGrallocUsage2ANDROID_LOAD
		getSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)procAddr(device, "vkGetSwapchainGrallocUsage2ANDROID");
#endif
#endif
#if defined(VK_EXT_debug_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDebugMarkerSetObjectTagEXT_LOAD
#define PFN_vkDebugMarkerSetObjectTagEXT_LOAD
		debugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)procAddr(device, "vkDebugMarkerSetObjectTagEXT");
#endif
#ifndef PFN_vkDebugMarkerSetObjectNameEXT_LOAD
#define PFN_vkDebugMarkerSetObjectNameEXT_LOAD
		debugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)procAddr(device, "vkDebugMarkerSetObjectNameEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerBeginEXT_LOAD
#define PFN_vkCmdDebugMarkerBeginEXT_LOAD
		cmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)procAddr(device, "vkCmdDebugMarkerBeginEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerEndEXT_LOAD
#define PFN_vkCmdDebugMarkerEndEXT_LOAD
		cmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)procAddr(device, "vkCmdDebugMarkerEndEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerInsertEXT_LOAD
#define PFN_vkCmdDebugMarkerInsertEXT_LOAD
		cmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)procAddr(device, "vkCmdDebugMarkerInsertEXT");
#endif
#endif
#if defined(VK_KHR_video_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateVideoSessionKHR_LOAD
#define PFN_vkCreateVideoSessionKHR_LOAD
		createVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)procAddr(device, "vkCreateVideoSessionKHR");
#endif
#ifndef PFN_vkDestroyVideoSessionKHR_LOAD
#define PFN_vkDestroyVideoSessionKHR_LOAD
		destroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)procAddr(device, "vkDestroyVideoSessionKHR");
#endif
#ifndef PFN_vkGetVideoSessionMemoryRequirementsKHR_LOAD
#define PFN_vkGetVideoSessionMemoryRequirementsKHR_LOAD
		getVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)procAddr(device, "vkGetVideoSessionMemoryRequirementsKHR");
#endif
#ifndef PFN_vkBindVideoSessionMemoryKHR_LOAD
#define PFN_vkBindVideoSessionMemoryKHR_LOAD
		bindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)procAddr(device, "vkBindVideoSessionMemoryKHR");
#endif
#ifndef PFN_vkCreateVideoSessionParametersKHR_LOAD
#define PFN_vkCreateVideoSessionParametersKHR_LOAD
		createVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)procAddr(device, "vkCreateVideoSessionParametersKHR");
#endif
#ifndef PFN_vkUpdateVideoSessionParametersKHR_LOAD
#define PFN_vkUpdateVideoSessionParametersKHR_LOAD
		updateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)procAddr(device, "vkUpdateVideoSessionParametersKHR");
#endif
#ifndef PFN_vkDestroyVideoSessionParametersKHR_LOAD
#define PFN_vkDestroyVideoSessionParametersKHR_LOAD
		destroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)procAddr(device, "vkDestroyVideoSessionParametersKHR");
#endif
#ifndef PFN_vkCmdBeginVideoCodingKHR_LOAD
#define PFN_vkCmdBeginVideoCodingKHR_LOAD
		cmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)procAddr(device, "vkCmdBeginVideoCodingKHR");
#endif
#ifndef PFN_vkCmdEndVideoCodingKHR_LOAD
#define PFN_vkCmdEndVideoCodingKHR_LOAD
		cmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)procAddr(device, "vkCmdEndVideoCodingKHR");
#endif
#ifndef PFN_vkCmdControlVideoCodingKHR_LOAD
#define PFN_vkCmdControlVideoCodingKHR_LOAD
		cmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)procAddr(device, "vkCmdControlVideoCodingKHR");
#endif
#endif
#if defined(VK_KHR_video_decode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDecodeVideoKHR_LOAD
#define PFN_vkCmdDecodeVideoKHR_LOAD
		cmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)procAddr(device, "vkCmdDecodeVideoKHR");
#endif
#endif
#if defined(VK_KHR_video_encode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdEncodeVideoKHR_LOAD
#define PFN_vkCmdEncodeVideoKHR_LOAD
		cmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)procAddr(device, "vkCmdEncodeVideoKHR");
#endif
#endif
#if defined(VK_EXT_transform_feedback) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindTransformFeedbackBuffersEXT_LOAD
#define PFN_vkCmdBindTransformFeedbackBuffersEXT_LOAD
		cmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)procAddr(device, "vkCmdBindTransformFeedbackBuffersEXT");
#endif
#ifndef PFN_vkCmdBeginTransformFeedbackEXT_LOAD
#define PFN_vkCmdBeginTransformFeedbackEXT_LOAD
		cmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)procAddr(device, "vkCmdBeginTransformFeedbackEXT");
#endif
#ifndef PFN_vkCmdEndTransformFeedbackEXT_LOAD
#define PFN_vkCmdEndTransformFeedbackEXT_LOAD
		cmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)procAddr(device, "vkCmdEndTransformFeedbackEXT");
#endif
#ifndef PFN_vkCmdBeginQueryIndexedEXT_LOAD
#define PFN_vkCmdBeginQueryIndexedEXT_LOAD
		cmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)procAddr(device, "vkCmdBeginQueryIndexedEXT");
#endif
#ifndef PFN_vkCmdEndQueryIndexedEXT_LOAD
#define PFN_vkCmdEndQueryIndexedEXT_LOAD
		cmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)procAddr(device, "vkCmdEndQueryIndexedEXT");
#endif
#ifndef PFN_vkCmdDrawIndirectByteCountEXT_LOAD
#define PFN_vkCmdDrawIndirectByteCountEXT_LOAD
		cmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)procAddr(device, "vkCmdDrawIndirectByteCountEXT");
#endif
#endif
#if defined(VK_NVX_image_view_handle) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageViewHandleNVX_LOAD
#define PFN_vkGetImageViewHandleNVX_LOAD
		getImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)procAddr(device, "vkGetImageViewHandleNVX");
#endif
#ifndef PFN_vkGetImageViewAddressNVX_LOAD
#define PFN_vkGetImageViewAddressNVX_LOAD
		getImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)procAddr(device, "vkGetImageViewAddressNVX");
#endif
#endif
#if defined(VK_AMD_draw_indirect_count) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawIndirectCountAMD_LOAD
#define PFN_vkCmdDrawIndirectCountAMD_LOAD
		cmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)procAddr(device, "vkCmdDrawIndirectCountAMD");
#endif
#ifndef PFN_vkCmdDrawIndexedIndirectCountAMD_LOAD
#define PFN_vkCmdDrawIndexedIndirectCountAMD_LOAD
		cmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)procAddr(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif
#endif
#if defined(VK_AMD_shader_info) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetShaderInfoAMD_LOAD
#define PFN_vkGetShaderInfoAMD_LOAD
		getShaderInfoAMD = (PFN_vkGetShaderInfoAMD)procAddr(device, "vkGetShaderInfoAMD");
#endif
#endif
#if defined(VK_NV_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleNV_LOAD
#define PFN_vkGetMemoryWin32HandleNV_LOAD
		getMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)procAddr(device, "vkGetMemoryWin32HandleNV");
#endif
#endif
#if defined(VK_KHR_device_group) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_LOAD
#define PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_LOAD
		getDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)procAddr(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif
#ifndef PFN_vkCmdSetDeviceMaskKHR_LOAD
#define PFN_vkCmdSetDeviceMaskKHR_LOAD
		cmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)procAddr(device, "vkCmdSetDeviceMaskKHR");
#endif
#ifndef PFN_vkCmdDispatchBaseKHR_LOAD
#define PFN_vkCmdDispatchBaseKHR_LOAD
		cmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)procAddr(device, "vkCmdDispatchBaseKHR");
#endif
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
		getDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)procAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
		getDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)procAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif
#ifndef PFN_vkAcquireNextImage2KHR_LOAD
#define PFN_vkAcquireNextImage2KHR_LOAD
		acquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)procAddr(device, "vkAcquireNextImage2KHR");
#endif
#endif
#if defined(VK_KHR_maintenance1) && defined(VK_VERSION_1_0)
#ifndef PFN_vkTrimCommandPoolKHR_LOAD
#define PFN_vkTrimCommandPoolKHR_LOAD
		trimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)procAddr(device, "vkTrimCommandPoolKHR");
#endif
#endif
#if defined(VK_KHR_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleKHR_LOAD
#define PFN_vkGetMemoryWin32HandleKHR_LOAD
		getMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)procAddr(device, "vkGetMemoryWin32HandleKHR");
#endif
#ifndef PFN_vkGetMemoryWin32HandlePropertiesKHR_LOAD
#define PFN_vkGetMemoryWin32HandlePropertiesKHR_LOAD
		getMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)procAddr(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif
#endif
#if defined(VK_KHR_external_memory_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryFdKHR_LOAD
#define PFN_vkGetMemoryFdKHR_LOAD
		getMemoryFdKHR = (PFN_vkGetMemoryFdKHR)procAddr(device, "vkGetMemoryFdKHR");
#endif
#ifndef PFN_vkGetMemoryFdPropertiesKHR_LOAD
#define PFN_vkGetMemoryFdPropertiesKHR_LOAD
		getMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)procAddr(device, "vkGetMemoryFdPropertiesKHR");
#endif
#endif
#if defined(VK_KHR_external_semaphore_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreWin32HandleKHR_LOAD
#define PFN_vkImportSemaphoreWin32HandleKHR_LOAD
		importSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)procAddr(device, "vkImportSemaphoreWin32HandleKHR");
#endif
#ifndef PFN_vkGetSemaphoreWin32HandleKHR_LOAD
#define PFN_vkGetSemaphoreWin32HandleKHR_LOAD
		getSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)procAddr(device, "vkGetSemaphoreWin32HandleKHR");
#endif
#endif
#if defined(VK_KHR_external_semaphore_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreFdKHR_LOAD
#define PFN_vkImportSemaphoreFdKHR_LOAD
		importSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)procAddr(device, "vkImportSemaphoreFdKHR");
#endif
#ifndef PFN_vkGetSemaphoreFdKHR_LOAD
#define PFN_vkGetSemaphoreFdKHR_LOAD
		getSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)procAddr(device, "vkGetSemaphoreFdKHR");
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdPushDescriptorSetKHR_LOAD
#define PFN_vkCmdPushDescriptorSetKHR_LOAD
		cmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)procAddr(device, "vkCmdPushDescriptorSetKHR");
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		cmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		cmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_EXT_conditional_rendering) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBeginConditionalRenderingEXT_LOAD
#define PFN_vkCmdBeginConditionalRenderingEXT_LOAD
		cmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)procAddr(device, "vkCmdBeginConditionalRenderingEXT");
#endif
#ifndef PFN_vkCmdEndConditionalRenderingEXT_LOAD
#define PFN_vkCmdEndConditionalRenderingEXT_LOAD
		cmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)procAddr(device, "vkCmdEndConditionalRenderingEXT");
#endif
#endif
#if defined(VK_KHR_descriptor_update_template) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDescriptorUpdateTemplateKHR_LOAD
#define PFN_vkCreateDescriptorUpdateTemplateKHR_LOAD
		createDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)procAddr(device, "vkCreateDescriptorUpdateTemplateKHR");
#endif
#ifndef PFN_vkDestroyDescriptorUpdateTemplateKHR_LOAD
#define PFN_vkDestroyDescriptorUpdateTemplateKHR_LOAD
		destroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)procAddr(device, "vkDestroyDescriptorUpdateTemplateKHR");
#endif
#ifndef PFN_vkUpdateDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkUpdateDescriptorSetWithTemplateKHR_LOAD
		updateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)procAddr(device, "vkUpdateDescriptorSetWithTemplateKHR");
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		cmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_NV_clip_space_w_scaling) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetViewportWScalingNV_LOAD
#define PFN_vkCmdSetViewportWScalingNV_LOAD
		cmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)procAddr(device, "vkCmdSetViewportWScalingNV");
#endif
#endif
#if defined(VK_EXT_display_control) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDisplayPowerControlEXT_LOAD
#define PFN_vkDisplayPowerControlEXT_LOAD
		displayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)procAddr(device, "vkDisplayPowerControlEXT");
#endif
#ifndef PFN_vkRegisterDeviceEventEXT_LOAD
#define PFN_vkRegisterDeviceEventEXT_LOAD
		registerDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)procAddr(device, "vkRegisterDeviceEventEXT");
#endif
#ifndef PFN_vkRegisterDisplayEventEXT_LOAD
#define PFN_vkRegisterDisplayEventEXT_LOAD
		registerDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)procAddr(device, "vkRegisterDisplayEventEXT");
#endif
#ifndef PFN_vkGetSwapchainCounterEXT_LOAD
#define PFN_vkGetSwapchainCounterEXT_LOAD
		getSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)procAddr(device, "vkGetSwapchainCounterEXT");
#endif
#endif
#if defined(VK_GOOGLE_display_timing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetRefreshCycleDurationGOOGLE_LOAD
#define PFN_vkGetRefreshCycleDurationGOOGLE_LOAD
		getRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)procAddr(device, "vkGetRefreshCycleDurationGOOGLE");
#endif
#ifndef PFN_vkGetPastPresentationTimingGOOGLE_LOAD
#define PFN_vkGetPastPresentationTimingGOOGLE_LOAD
		getPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)procAddr(device, "vkGetPastPresentationTimingGOOGLE");
#endif
#endif
#if defined(VK_EXT_discard_rectangles) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetDiscardRectangleEXT_LOAD
#define PFN_vkCmdSetDiscardRectangleEXT_LOAD
		cmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)procAddr(device, "vkCmdSetDiscardRectangleEXT");
#endif
#endif
#if defined(VK_EXT_hdr_metadata) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetHdrMetadataEXT_LOAD
#define PFN_vkSetHdrMetadataEXT_LOAD
		setHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)procAddr(device, "vkSetHdrMetadataEXT");
#endif
#endif
#if defined(VK_KHR_create_renderpass2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateRenderPass2KHR_LOAD
#define PFN_vkCreateRenderPass2KHR_LOAD
		createRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)procAddr(device, "vkCreateRenderPass2KHR");
#endif
#ifndef PFN_vkCmdBeginRenderPass2KHR_LOAD
#define PFN_vkCmdBeginRenderPass2KHR_LOAD
		cmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)procAddr(device, "vkCmdBeginRenderPass2KHR");
#endif
#ifndef PFN_vkCmdNextSubpass2KHR_LOAD
#define PFN_vkCmdNextSubpass2KHR_LOAD
		cmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)procAddr(device, "vkCmdNextSubpass2KHR");
#endif
#ifndef PFN_vkCmdEndRenderPass2KHR_LOAD
#define PFN_vkCmdEndRenderPass2KHR_LOAD
		cmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)procAddr(device, "vkCmdEndRenderPass2KHR");
#endif
#endif
#if defined(VK_KHR_shared_presentable_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainStatusKHR_LOAD
#define PFN_vkGetSwapchainStatusKHR_LOAD
		getSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)procAddr(device, "vkGetSwapchainStatusKHR");
#endif
#endif
#if defined(VK_KHR_external_fence_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceWin32HandleKHR_LOAD
#define PFN_vkImportFenceWin32HandleKHR_LOAD
		importFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)procAddr(device, "vkImportFenceWin32HandleKHR");
#endif
#ifndef PFN_vkGetFenceWin32HandleKHR_LOAD
#define PFN_vkGetFenceWin32HandleKHR_LOAD
		getFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)procAddr(device, "vkGetFenceWin32HandleKHR");
#endif
#endif
#if defined(VK_KHR_external_fence_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceFdKHR_LOAD
#define PFN_vkImportFenceFdKHR_LOAD
		importFenceFdKHR = (PFN_vkImportFenceFdKHR)procAddr(device, "vkImportFenceFdKHR");
#endif
#ifndef PFN_vkGetFenceFdKHR_LOAD
#define PFN_vkGetFenceFdKHR_LOAD
		getFenceFdKHR = (PFN_vkGetFenceFdKHR)procAddr(device, "vkGetFenceFdKHR");
#endif
#endif
#if defined(VK_KHR_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireProfilingLockKHR_LOAD
#define PFN_vkAcquireProfilingLockKHR_LOAD
		acquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)procAddr(device, "vkAcquireProfilingLockKHR");
#endif
#ifndef PFN_vkReleaseProfilingLockKHR_LOAD
#define PFN_vkReleaseProfilingLockKHR_LOAD
		releaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)procAddr(device, "vkReleaseProfilingLockKHR");
#endif
#endif
#if defined(VK_EXT_debug_utils) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetDebugUtilsObjectNameEXT_LOAD
#define PFN_vkSetDebugUtilsObjectNameEXT_LOAD
		setDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)procAddr(device, "vkSetDebugUtilsObjectNameEXT");
#endif
#ifndef PFN_vkSetDebugUtilsObjectTagEXT_LOAD
#define PFN_vkSetDebugUtilsObjectTagEXT_LOAD
		setDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)procAddr(device, "vkSetDebugUtilsObjectTagEXT");
#endif
#ifndef PFN_vkQueueBeginDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueBeginDebugUtilsLabelEXT_LOAD
		queueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)procAddr(device, "vkQueueBeginDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkQueueEndDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueEndDebugUtilsLabelEXT_LOAD
		queueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)procAddr(device, "vkQueueEndDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkQueueInsertDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueInsertDebugUtilsLabelEXT_LOAD
		queueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)procAddr(device, "vkQueueInsertDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdBeginDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdBeginDebugUtilsLabelEXT_LOAD
		cmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)procAddr(device, "vkCmdBeginDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdEndDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdEndDebugUtilsLabelEXT_LOAD
		cmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)procAddr(device, "vkCmdEndDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdInsertDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdInsertDebugUtilsLabelEXT_LOAD
		cmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)procAddr(device, "vkCmdInsertDebugUtilsLabelEXT");
#endif
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetAndroidHardwareBufferPropertiesANDROID_LOAD
#define PFN_vkGetAndroidHardwareBufferPropertiesANDROID_LOAD
		getAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)procAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
#endif
#ifndef PFN_vkGetMemoryAndroidHardwareBufferANDROID_LOAD
#define PFN_vkGetMemoryAndroidHardwareBufferANDROID_LOAD
		getMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)procAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif
#endif
#if defined(VK_EXT_sample_locations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetSampleLocationsEXT_LOAD
#define PFN_vkCmdSetSampleLocationsEXT_LOAD
		cmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)procAddr(device, "vkCmdSetSampleLocationsEXT");
#endif
#endif
#if defined(VK_KHR_get_memory_requirements2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageMemoryRequirements2KHR_LOAD
#define PFN_vkGetImageMemoryRequirements2KHR_LOAD
		getImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)procAddr(device, "vkGetImageMemoryRequirements2KHR");
#endif
#ifndef PFN_vkGetBufferMemoryRequirements2KHR_LOAD
#define PFN_vkGetBufferMemoryRequirements2KHR_LOAD
		getBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)procAddr(device, "vkGetBufferMemoryRequirements2KHR");
#endif
#ifndef PFN_vkGetImageSparseMemoryRequirements2KHR_LOAD
#define PFN_vkGetImageSparseMemoryRequirements2KHR_LOAD
		getImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)procAddr(device, "vkGetImageSparseMemoryRequirements2KHR");
#endif
#endif
#if defined(VK_KHR_acceleration_structure) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureKHR_LOAD
#define PFN_vkCreateAccelerationStructureKHR_LOAD
		createAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)procAddr(device, "vkCreateAccelerationStructureKHR");
#endif
#ifndef PFN_vkDestroyAccelerationStructureKHR_LOAD
#define PFN_vkDestroyAccelerationStructureKHR_LOAD
		destroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)procAddr(device, "vkDestroyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresKHR_LOAD
#define PFN_vkCmdBuildAccelerationStructuresKHR_LOAD
		cmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)procAddr(device, "vkCmdBuildAccelerationStructuresKHR");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresIndirectKHR_LOAD
#define PFN_vkCmdBuildAccelerationStructuresIndirectKHR_LOAD
		cmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)procAddr(device, "vkCmdBuildAccelerationStructuresIndirectKHR");
#endif
#ifndef PFN_vkBuildAccelerationStructuresKHR_LOAD
#define PFN_vkBuildAccelerationStructuresKHR_LOAD
		buildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)procAddr(device, "vkBuildAccelerationStructuresKHR");
#endif
#ifndef PFN_vkCopyAccelerationStructureKHR_LOAD
#define PFN_vkCopyAccelerationStructureKHR_LOAD
		copyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)procAddr(device, "vkCopyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCopyAccelerationStructureToMemoryKHR_LOAD
#define PFN_vkCopyAccelerationStructureToMemoryKHR_LOAD
		copyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCopyAccelerationStructureToMemoryKHR");
#endif
#ifndef PFN_vkCopyMemoryToAccelerationStructureKHR_LOAD
#define PFN_vkCopyMemoryToAccelerationStructureKHR_LOAD
		copyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCopyMemoryToAccelerationStructureKHR");
#endif
#ifndef PFN_vkWriteAccelerationStructuresPropertiesKHR_LOAD
#define PFN_vkWriteAccelerationStructuresPropertiesKHR_LOAD
		writeAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkWriteAccelerationStructuresPropertiesKHR");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureKHR_LOAD
#define PFN_vkCmdCopyAccelerationStructureKHR_LOAD
		cmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)procAddr(device, "vkCmdCopyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureToMemoryKHR_LOAD
#define PFN_vkCmdCopyAccelerationStructureToMemoryKHR_LOAD
		cmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCmdCopyAccelerationStructureToMemoryKHR");
#endif
#ifndef PFN_vkCmdCopyMemoryToAccelerationStructureKHR_LOAD
#define PFN_vkCmdCopyMemoryToAccelerationStructureKHR_LOAD
		cmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCmdCopyMemoryToAccelerationStructureKHR");
#endif
#ifndef PFN_vkGetAccelerationStructureDeviceAddressKHR_LOAD
#define PFN_vkGetAccelerationStructureDeviceAddressKHR_LOAD
		getAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)procAddr(device, "vkGetAccelerationStructureDeviceAddressKHR");
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_LOAD
#define PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_LOAD
		cmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
#endif
#ifndef PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_LOAD
#define PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_LOAD
		getDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)procAddr(device, "vkGetDeviceAccelerationStructureCompatibilityKHR");
#endif
#ifndef PFN_vkGetAccelerationStructureBuildSizesKHR_LOAD
#define PFN_vkGetAccelerationStructureBuildSizesKHR_LOAD
		getAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)procAddr(device, "vkGetAccelerationStructureBuildSizesKHR");
#endif
#endif
#if defined(VK_KHR_ray_tracing_pipeline) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdTraceRaysKHR_LOAD
#define PFN_vkCmdTraceRaysKHR_LOAD
		cmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)procAddr(device, "vkCmdTraceRaysKHR");
#endif
#ifndef PFN_vkCreateRayTracingPipelinesKHR_LOAD
#define PFN_vkCreateRayTracingPipelinesKHR_LOAD
		createRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)procAddr(device, "vkCreateRayTracingPipelinesKHR");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesKHR_LOAD
#define PFN_vkGetRayTracingShaderGroupHandlesKHR_LOAD
		getRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingShaderGroupHandlesKHR");
#endif
#ifndef PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_LOAD
#define PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_LOAD
		getRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
#endif
#ifndef PFN_vkCmdTraceRaysIndirectKHR_LOAD
#define PFN_vkCmdTraceRaysIndirectKHR_LOAD
		cmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)procAddr(device, "vkCmdTraceRaysIndirectKHR");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupStackSizeKHR_LOAD
#define PFN_vkGetRayTracingShaderGroupStackSizeKHR_LOAD
		getRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)procAddr(device, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif
#ifndef PFN_vkCmdSetRayTracingPipelineStackSizeKHR_LOAD
#define PFN_vkCmdSetRayTracingPipelineStackSizeKHR_LOAD
		cmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)procAddr(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
#endif
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSamplerYcbcrConversionKHR_LOAD
#define PFN_vkCreateSamplerYcbcrConversionKHR_LOAD
		createSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)procAddr(device, "vkCreateSamplerYcbcrConversionKHR");
#endif
#ifndef PFN_vkDestroySamplerYcbcrConversionKHR_LOAD
#define PFN_vkDestroySamplerYcbcrConversionKHR_LOAD
		destroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)procAddr(device, "vkDestroySamplerYcbcrConversionKHR");
#endif
#endif
#if defined(VK_KHR_bind_memory2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkBindBufferMemory2KHR_LOAD
#define PFN_vkBindBufferMemory2KHR_LOAD
		bindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)procAddr(device, "vkBindBufferMemory2KHR");
#endif
#ifndef PFN_vkBindImageMemory2KHR_LOAD
#define PFN_vkBindImageMemory2KHR_LOAD
		bindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)procAddr(device, "vkBindImageMemory2KHR");
#endif
#endif
#if defined(VK_EXT_image_drm_format_modifier) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageDrmFormatModifierPropertiesEXT_LOAD
#define PFN_vkGetImageDrmFormatModifierPropertiesEXT_LOAD
		getImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)procAddr(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif
#endif
#if defined(VK_EXT_validation_cache) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateValidationCacheEXT_LOAD
#define PFN_vkCreateValidationCacheEXT_LOAD
		createValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)procAddr(device, "vkCreateValidationCacheEXT");
#endif
#ifndef PFN_vkDestroyValidationCacheEXT_LOAD
#define PFN_vkDestroyValidationCacheEXT_LOAD
		destroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)procAddr(device, "vkDestroyValidationCacheEXT");
#endif
#ifndef PFN_vkMergeValidationCachesEXT_LOAD
#define PFN_vkMergeValidationCachesEXT_LOAD
		mergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)procAddr(device, "vkMergeValidationCachesEXT");
#endif
#ifndef PFN_vkGetValidationCacheDataEXT_LOAD
#define PFN_vkGetValidationCacheDataEXT_LOAD
		getValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)procAddr(device, "vkGetValidationCacheDataEXT");
#endif
#endif
#if defined(VK_NV_shading_rate_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindShadingRateImageNV_LOAD
#define PFN_vkCmdBindShadingRateImageNV_LOAD
		cmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)procAddr(device, "vkCmdBindShadingRateImageNV");
#endif
#ifndef PFN_vkCmdSetViewportShadingRatePaletteNV_LOAD
#define PFN_vkCmdSetViewportShadingRatePaletteNV_LOAD
		cmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)procAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
#endif
#ifndef PFN_vkCmdSetCoarseSampleOrderNV_LOAD
#define PFN_vkCmdSetCoarseSampleOrderNV_LOAD
		cmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)procAddr(device, "vkCmdSetCoarseSampleOrderNV");
#endif
#endif
#if defined(VK_NV_ray_tracing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureNV_LOAD
#define PFN_vkCreateAccelerationStructureNV_LOAD
		createAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)procAddr(device, "vkCreateAccelerationStructureNV");
#endif
#ifndef PFN_vkDestroyAccelerationStructureNV_LOAD
#define PFN_vkDestroyAccelerationStructureNV_LOAD
		destroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)procAddr(device, "vkDestroyAccelerationStructureNV");
#endif
#ifndef PFN_vkGetAccelerationStructureMemoryRequirementsNV_LOAD
#define PFN_vkGetAccelerationStructureMemoryRequirementsNV_LOAD
		getAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)procAddr(device, "vkGetAccelerationStructureMemoryRequirementsNV");
#endif
#ifndef PFN_vkBindAccelerationStructureMemoryNV_LOAD
#define PFN_vkBindAccelerationStructureMemoryNV_LOAD
		bindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)procAddr(device, "vkBindAccelerationStructureMemoryNV");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructureNV_LOAD
#define PFN_vkCmdBuildAccelerationStructureNV_LOAD
		cmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)procAddr(device, "vkCmdBuildAccelerationStructureNV");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureNV_LOAD
#define PFN_vkCmdCopyAccelerationStructureNV_LOAD
		cmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)procAddr(device, "vkCmdCopyAccelerationStructureNV");
#endif
#ifndef PFN_vkCmdTraceRaysNV_LOAD
#define PFN_vkCmdTraceRaysNV_LOAD
		cmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)procAddr(device, "vkCmdTraceRaysNV");
#endif
#ifndef PFN_vkCreateRayTracingPipelinesNV_LOAD
#define PFN_vkCreateRayTracingPipelinesNV_LOAD
		createRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)procAddr(device, "vkCreateRayTracingPipelinesNV");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesNV_LOAD
#define PFN_vkGetRayTracingShaderGroupHandlesNV_LOAD
		getRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)procAddr(device, "vkGetRayTracingShaderGroupHandlesNV");
#endif
#ifndef PFN_vkGetAccelerationStructureHandleNV_LOAD
#define PFN_vkGetAccelerationStructureHandleNV_LOAD
		getAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)procAddr(device, "vkGetAccelerationStructureHandleNV");
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesNV_LOAD
#define PFN_vkCmdWriteAccelerationStructuresPropertiesNV_LOAD
		cmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
#endif
#ifndef PFN_vkCompileDeferredNV_LOAD
#define PFN_vkCompileDeferredNV_LOAD
		compileDeferredNV = (PFN_vkCompileDeferredNV)procAddr(device, "vkCompileDeferredNV");
#endif
#endif
#if defined(VK_KHR_maintenance3) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDescriptorSetLayoutSupportKHR_LOAD
#define PFN_vkGetDescriptorSetLayoutSupportKHR_LOAD
		getDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)procAddr(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif
#endif
#if defined(VK_EXT_external_memory_host) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryHostPointerPropertiesEXT_LOAD
#define PFN_vkGetMemoryHostPointerPropertiesEXT_LOAD
		getMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)procAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif
#endif
#if defined(VK_AMD_buffer_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdWriteBufferMarkerAMD_LOAD
#define PFN_vkCmdWriteBufferMarkerAMD_LOAD
		cmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)procAddr(device, "vkCmdWriteBufferMarkerAMD");
#endif
#endif
#if defined(VK_EXT_calibrated_timestamps) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetCalibratedTimestampsEXT_LOAD
#define PFN_vkGetCalibratedTimestampsEXT_LOAD
		getCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)procAddr(device, "vkGetCalibratedTimestampsEXT");
#endif
#endif
#if defined(VK_NV_mesh_shader) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawMeshTasksNV_LOAD
#define PFN_vkCmdDrawMeshTasksNV_LOAD
		cmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)procAddr(device, "vkCmdDrawMeshTasksNV");
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectNV_LOAD
#define PFN_vkCmdDrawMeshTasksIndirectNV_LOAD
		cmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)procAddr(device, "vkCmdDrawMeshTasksIndirectNV");
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectCountNV_LOAD
#define PFN_vkCmdDrawMeshTasksIndirectCountNV_LOAD
		cmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)procAddr(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif
#endif
#if defined(VK_NV_scissor_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetExclusiveScissorNV_LOAD
#define PFN_vkCmdSetExclusiveScissorNV_LOAD
		cmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)procAddr(device, "vkCmdSetExclusiveScissorNV");
#endif
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCheckpointNV_LOAD
#define PFN_vkCmdSetCheckpointNV_LOAD
		cmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)procAddr(device, "vkCmdSetCheckpointNV");
#endif
#ifndef PFN_vkGetQueueCheckpointDataNV_LOAD
#define PFN_vkGetQueueCheckpointDataNV_LOAD
		getQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)procAddr(device, "vkGetQueueCheckpointDataNV");
#endif
#endif
#if defined(VK_KHR_timeline_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSemaphoreCounterValueKHR_LOAD
#define PFN_vkGetSemaphoreCounterValueKHR_LOAD
		getSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)procAddr(device, "vkGetSemaphoreCounterValueKHR");
#endif
#ifndef PFN_vkWaitSemaphoresKHR_LOAD
#define PFN_vkWaitSemaphoresKHR_LOAD
		waitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)procAddr(device, "vkWaitSemaphoresKHR");
#endif
#ifndef PFN_vkSignalSemaphoreKHR_LOAD
#define PFN_vkSignalSemaphoreKHR_LOAD
		signalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)procAddr(device, "vkSignalSemaphoreKHR");
#endif
#endif
#if defined(VK_INTEL_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkInitializePerformanceApiINTEL_LOAD
#define PFN_vkInitializePerformanceApiINTEL_LOAD
		initializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)procAddr(device, "vkInitializePerformanceApiINTEL");
#endif
#ifndef PFN_vkUninitializePerformanceApiINTEL_LOAD
#define PFN_vkUninitializePerformanceApiINTEL_LOAD
		uninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)procAddr(device, "vkUninitializePerformanceApiINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceMarkerINTEL_LOAD
#define PFN_vkCmdSetPerformanceMarkerINTEL_LOAD
		cmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)procAddr(device, "vkCmdSetPerformanceMarkerINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceStreamMarkerINTEL_LOAD
#define PFN_vkCmdSetPerformanceStreamMarkerINTEL_LOAD
		cmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)procAddr(device, "vkCmdSetPerformanceStreamMarkerINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceOverrideINTEL_LOAD
#define PFN_vkCmdSetPerformanceOverrideINTEL_LOAD
		cmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)procAddr(device, "vkCmdSetPerformanceOverrideINTEL");
#endif
#ifndef PFN_vkAcquirePerformanceConfigurationINTEL_LOAD
#define PFN_vkAcquirePerformanceConfigurationINTEL_LOAD
		acquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)procAddr(device, "vkAcquirePerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkReleasePerformanceConfigurationINTEL_LOAD
#define PFN_vkReleasePerformanceConfigurationINTEL_LOAD
		releasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)procAddr(device, "vkReleasePerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkQueueSetPerformanceConfigurationINTEL_LOAD
#define PFN_vkQueueSetPerformanceConfigurationINTEL_LOAD
		queueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)procAddr(device, "vkQueueSetPerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkGetPerformanceParameterINTEL_LOAD
#define PFN_vkGetPerformanceParameterINTEL_LOAD
		getPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)procAddr(device, "vkGetPerformanceParameterINTEL");
#endif
#endif
#if defined(VK_AMD_display_native_hdr) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetLocalDimmingAMD_LOAD
#define PFN_vkSetLocalDimmingAMD_LOAD
		setLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)procAddr(device, "vkSetLocalDimmingAMD");
#endif
#endif
#if defined(VK_KHR_fragment_shading_rate) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateKHR_LOAD
#define PFN_vkCmdSetFragmentShadingRateKHR_LOAD
		cmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)procAddr(device, "vkCmdSetFragmentShadingRateKHR");
#endif
#endif
#if defined(VK_EXT_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferDeviceAddressEXT_LOAD
#define PFN_vkGetBufferDeviceAddressEXT_LOAD
		getBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)procAddr(device, "vkGetBufferDeviceAddressEXT");
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireFullScreenExclusiveModeEXT_LOAD
#define PFN_vkAcquireFullScreenExclusiveModeEXT_LOAD
		acquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)procAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif
#ifndef PFN_vkReleaseFullScreenExclusiveModeEXT_LOAD
#define PFN_vkReleaseFullScreenExclusiveModeEXT_LOAD
		releaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)procAddr(device, "vkReleaseFullScreenExclusiveModeEXT");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
		getDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)procAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
		getDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)procAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#endif
#if defined(VK_KHR_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferOpaqueCaptureAddressKHR_LOAD
#define PFN_vkGetBufferOpaqueCaptureAddressKHR_LOAD
		getBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)procAddr(device, "vkGetBufferOpaqueCaptureAddressKHR");
#endif
#ifndef PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_LOAD
#define PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_LOAD
		getDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif
#endif
#if defined(VK_EXT_line_rasterization) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetLineStippleEXT_LOAD
#define PFN_vkCmdSetLineStippleEXT_LOAD
		cmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)procAddr(device, "vkCmdSetLineStippleEXT");
#endif
#endif
#if defined(VK_EXT_host_query_reset) && defined(VK_VERSION_1_0)
#ifndef PFN_vkResetQueryPoolEXT_LOAD
#define PFN_vkResetQueryPoolEXT_LOAD
		resetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)procAddr(device, "vkResetQueryPoolEXT");
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCullModeEXT_LOAD
#define PFN_vkCmdSetCullModeEXT_LOAD
		cmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)procAddr(device, "vkCmdSetCullModeEXT");
#endif
#ifndef PFN_vkCmdSetFrontFaceEXT_LOAD
#define PFN_vkCmdSetFrontFaceEXT_LOAD
		cmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)procAddr(device, "vkCmdSetFrontFaceEXT");
#endif
#ifndef PFN_vkCmdSetPrimitiveTopologyEXT_LOAD
#define PFN_vkCmdSetPrimitiveTopologyEXT_LOAD
		cmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)procAddr(device, "vkCmdSetPrimitiveTopologyEXT");
#endif
#ifndef PFN_vkCmdSetViewportWithCountEXT_LOAD
#define PFN_vkCmdSetViewportWithCountEXT_LOAD
		cmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)procAddr(device, "vkCmdSetViewportWithCountEXT");
#endif
#ifndef PFN_vkCmdSetScissorWithCountEXT_LOAD
#define PFN_vkCmdSetScissorWithCountEXT_LOAD
		cmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)procAddr(device, "vkCmdSetScissorWithCountEXT");
#endif
#ifndef PFN_vkCmdBindVertexBuffers2EXT_LOAD
#define PFN_vkCmdBindVertexBuffers2EXT_LOAD
		cmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)procAddr(device, "vkCmdBindVertexBuffers2EXT");
#endif
#ifndef PFN_vkCmdSetDepthTestEnableEXT_LOAD
#define PFN_vkCmdSetDepthTestEnableEXT_LOAD
		cmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)procAddr(device, "vkCmdSetDepthTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthWriteEnableEXT_LOAD
#define PFN_vkCmdSetDepthWriteEnableEXT_LOAD
		cmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)procAddr(device, "vkCmdSetDepthWriteEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthCompareOpEXT_LOAD
#define PFN_vkCmdSetDepthCompareOpEXT_LOAD
		cmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)procAddr(device, "vkCmdSetDepthCompareOpEXT");
#endif
#ifndef PFN_vkCmdSetDepthBoundsTestEnableEXT_LOAD
#define PFN_vkCmdSetDepthBoundsTestEnableEXT_LOAD
		cmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)procAddr(device, "vkCmdSetDepthBoundsTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetStencilTestEnableEXT_LOAD
#define PFN_vkCmdSetStencilTestEnableEXT_LOAD
		cmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)procAddr(device, "vkCmdSetStencilTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetStencilOpEXT_LOAD
#define PFN_vkCmdSetStencilOpEXT_LOAD
		cmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)procAddr(device, "vkCmdSetStencilOpEXT");
#endif
#endif
#if defined(VK_KHR_deferred_host_operations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDeferredOperationKHR_LOAD
#define PFN_vkCreateDeferredOperationKHR_LOAD
		createDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)procAddr(device, "vkCreateDeferredOperationKHR");
#endif
#ifndef PFN_vkDestroyDeferredOperationKHR_LOAD
#define PFN_vkDestroyDeferredOperationKHR_LOAD
		destroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)procAddr(device, "vkDestroyDeferredOperationKHR");
#endif
#ifndef PFN_vkGetDeferredOperationMaxConcurrencyKHR_LOAD
#define PFN_vkGetDeferredOperationMaxConcurrencyKHR_LOAD
		getDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)procAddr(device, "vkGetDeferredOperationMaxConcurrencyKHR");
#endif
#ifndef PFN_vkGetDeferredOperationResultKHR_LOAD
#define PFN_vkGetDeferredOperationResultKHR_LOAD
		getDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)procAddr(device, "vkGetDeferredOperationResultKHR");
#endif
#ifndef PFN_vkDeferredOperationJoinKHR_LOAD
#define PFN_vkDeferredOperationJoinKHR_LOAD
		deferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)procAddr(device, "vkDeferredOperationJoinKHR");
#endif
#endif
#if defined(VK_KHR_pipeline_executable_properties) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetPipelineExecutablePropertiesKHR_LOAD
#define PFN_vkGetPipelineExecutablePropertiesKHR_LOAD
		getPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)procAddr(device, "vkGetPipelineExecutablePropertiesKHR");
#endif
#ifndef PFN_vkGetPipelineExecutableStatisticsKHR_LOAD
#define PFN_vkGetPipelineExecutableStatisticsKHR_LOAD
		getPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)procAddr(device, "vkGetPipelineExecutableStatisticsKHR");
#endif
#ifndef PFN_vkGetPipelineExecutableInternalRepresentationsKHR_LOAD
#define PFN_vkGetPipelineExecutableInternalRepresentationsKHR_LOAD
		getPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)procAddr(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif
#endif
#if defined(VK_NV_device_generated_commands) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetGeneratedCommandsMemoryRequirementsNV_LOAD
#define PFN_vkGetGeneratedCommandsMemoryRequirementsNV_LOAD
		getGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)procAddr(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif
#ifndef PFN_vkCmdPreprocessGeneratedCommandsNV_LOAD
#define PFN_vkCmdPreprocessGeneratedCommandsNV_LOAD
		cmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)procAddr(device, "vkCmdPreprocessGeneratedCommandsNV");
#endif
#ifndef PFN_vkCmdExecuteGeneratedCommandsNV_LOAD
#define PFN_vkCmdExecuteGeneratedCommandsNV_LOAD
		cmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)procAddr(device, "vkCmdExecuteGeneratedCommandsNV");
#endif
#ifndef PFN_vkCmdBindPipelineShaderGroupNV_LOAD
#define PFN_vkCmdBindPipelineShaderGroupNV_LOAD
		cmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)procAddr(device, "vkCmdBindPipelineShaderGroupNV");
#endif
#ifndef PFN_vkCreateIndirectCommandsLayoutNV_LOAD
#define PFN_vkCreateIndirectCommandsLayoutNV_LOAD
		createIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)procAddr(device, "vkCreateIndirectCommandsLayoutNV");
#endif
#ifndef PFN_vkDestroyIndirectCommandsLayoutNV_LOAD
#define PFN_vkDestroyIndirectCommandsLayoutNV_LOAD
		destroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)procAddr(device, "vkDestroyIndirectCommandsLayoutNV");
#endif
#endif
#if defined(VK_EXT_private_data) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreatePrivateDataSlotEXT_LOAD
#define PFN_vkCreatePrivateDataSlotEXT_LOAD
		createPrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)procAddr(device, "vkCreatePrivateDataSlotEXT");
#endif
#ifndef PFN_vkDestroyPrivateDataSlotEXT_LOAD
#define PFN_vkDestroyPrivateDataSlotEXT_LOAD
		destroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)procAddr(device, "vkDestroyPrivateDataSlotEXT");
#endif
#ifndef PFN_vkSetPrivateDataEXT_LOAD
#define PFN_vkSetPrivateDataEXT_LOAD
		setPrivateDataEXT = (PFN_vkSetPrivateDataEXT)procAddr(device, "vkSetPrivateDataEXT");
#endif
#ifndef PFN_vkGetPrivateDataEXT_LOAD
#define PFN_vkGetPrivateDataEXT_LOAD
		getPrivateDataEXT = (PFN_vkGetPrivateDataEXT)procAddr(device, "vkGetPrivateDataEXT");
#endif
#endif
#if defined(VK_KHR_synchronization2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetEvent2KHR_LOAD
#define PFN_vkCmdSetEvent2KHR_LOAD
		cmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)procAddr(device, "vkCmdSetEvent2KHR");
#endif
#ifndef PFN_vkCmdResetEvent2KHR_LOAD
#define PFN_vkCmdResetEvent2KHR_LOAD
		cmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)procAddr(device, "vkCmdResetEvent2KHR");
#endif
#ifndef PFN_vkCmdWaitEvents2KHR_LOAD
#define PFN_vkCmdWaitEvents2KHR_LOAD
		cmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)procAddr(device, "vkCmdWaitEvents2KHR");
#endif
#ifndef PFN_vkCmdPipelineBarrier2KHR_LOAD
#define PFN_vkCmdPipelineBarrier2KHR_LOAD
		cmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)procAddr(device, "vkCmdPipelineBarrier2KHR");
#endif
#ifndef PFN_vkCmdWriteTimestamp2KHR_LOAD
#define PFN_vkCmdWriteTimestamp2KHR_LOAD
		cmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)procAddr(device, "vkCmdWriteTimestamp2KHR");
#endif
#ifndef PFN_vkQueueSubmit2KHR_LOAD
#define PFN_vkQueueSubmit2KHR_LOAD
		queueSubmit2KHR = (PFN_vkQueueSubmit2KHR)procAddr(device, "vkQueueSubmit2KHR");
#endif
#ifndef PFN_vkCmdWriteBufferMarker2AMD_LOAD
#define PFN_vkCmdWriteBufferMarker2AMD_LOAD
		cmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)procAddr(device, "vkCmdWriteBufferMarker2AMD");
#endif
#ifndef PFN_vkGetQueueCheckpointData2NV_LOAD
#define PFN_vkGetQueueCheckpointData2NV_LOAD
		getQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)procAddr(device, "vkGetQueueCheckpointData2NV");
#endif
#endif
#if defined(VK_NV_fragment_shading_rate_enums) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateEnumNV_LOAD
#define PFN_vkCmdSetFragmentShadingRateEnumNV_LOAD
		cmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)procAddr(device, "vkCmdSetFragmentShadingRateEnumNV");
#endif
#endif
#if defined(VK_KHR_copy_commands2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdCopyBuffer2KHR_LOAD
#define PFN_vkCmdCopyBuffer2KHR_LOAD
		cmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)procAddr(device, "vkCmdCopyBuffer2KHR");
#endif
#ifndef PFN_vkCmdCopyImage2KHR_LOAD
#define PFN_vkCmdCopyImage2KHR_LOAD
		cmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)procAddr(device, "vkCmdCopyImage2KHR");
#endif
#ifndef PFN_vkCmdCopyBufferToImage2KHR_LOAD
#define PFN_vkCmdCopyBufferToImage2KHR_LOAD
		cmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)procAddr(device, "vkCmdCopyBufferToImage2KHR");
#endif
#ifndef PFN_vkCmdCopyImageToBuffer2KHR_LOAD
#define PFN_vkCmdCopyImageToBuffer2KHR_LOAD
		cmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)procAddr(device, "vkCmdCopyImageToBuffer2KHR");
#endif
#ifndef PFN_vkCmdBlitImage2KHR_LOAD
#define PFN_vkCmdBlitImage2KHR_LOAD
		cmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)procAddr(device, "vkCmdBlitImage2KHR");
#endif
#ifndef PFN_vkCmdResolveImage2KHR_LOAD
#define PFN_vkCmdResolveImage2KHR_LOAD
		cmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)procAddr(device, "vkCmdResolveImage2KHR");
#endif
#endif
#if defined(VK_EXT_vertex_input_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetVertexInputEXT_LOAD
#define PFN_vkCmdSetVertexInputEXT_LOAD
		cmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)procAddr(device, "vkCmdSetVertexInputEXT");
#endif
#endif
#if defined(VK_FUCHSIA_external_memory) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryZirconHandleFUCHSIA_LOAD
#define PFN_vkGetMemoryZirconHandleFUCHSIA_LOAD
		getMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)procAddr(device, "vkGetMemoryZirconHandleFUCHSIA");
#endif
#ifndef PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_LOAD
#define PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_LOAD
		getMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)procAddr(device, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif
#endif
#if defined(VK_FUCHSIA_external_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreZirconHandleFUCHSIA_LOAD
#define PFN_vkImportSemaphoreZirconHandleFUCHSIA_LOAD
		importSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif
#ifndef PFN_vkGetSemaphoreZirconHandleFUCHSIA_LOAD
#define PFN_vkGetSemaphoreZirconHandleFUCHSIA_LOAD
		getSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkGetSemaphoreZirconHandleFUCHSIA");
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetPatchControlPointsEXT_LOAD
#define PFN_vkCmdSetPatchControlPointsEXT_LOAD
		cmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)procAddr(device, "vkCmdSetPatchControlPointsEXT");
#endif
#ifndef PFN_vkCmdSetRasterizerDiscardEnableEXT_LOAD
#define PFN_vkCmdSetRasterizerDiscardEnableEXT_LOAD
		cmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)procAddr(device, "vkCmdSetRasterizerDiscardEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthBiasEnableEXT_LOAD
#define PFN_vkCmdSetDepthBiasEnableEXT_LOAD
		cmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)procAddr(device, "vkCmdSetDepthBiasEnableEXT");
#endif
#ifndef PFN_vkCmdSetLogicOpEXT_LOAD
#define PFN_vkCmdSetLogicOpEXT_LOAD
		cmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)procAddr(device, "vkCmdSetLogicOpEXT");
#endif
#ifndef PFN_vkCmdSetPrimitiveRestartEnableEXT_LOAD
#define PFN_vkCmdSetPrimitiveRestartEnableEXT_LOAD
		cmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)procAddr(device, "vkCmdSetPrimitiveRestartEnableEXT");
#endif
#endif
#if defined(VK_EXT_color_write_enable) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetColorWriteEnableEXT_LOAD
#define PFN_vkCmdSetColorWriteEnableEXT_LOAD
		cmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)procAddr(device, "vkCmdSetColorWriteEnableEXT");
#endif
#endif
	}
#ifdef VK_VERSION_1_0
	PFN_vkGetDeviceQueue getDeviceQueue = nullptr;
	PFN_vkQueueSubmit queueSubmit = nullptr;
	PFN_vkQueueWaitIdle queueWaitIdle = nullptr;
	PFN_vkDeviceWaitIdle deviceWaitIdle = nullptr;
	PFN_vkAllocateMemory allocateMemory = nullptr;
	PFN_vkFreeMemory freeMemory = nullptr;
	PFN_vkMapMemory mapMemory = nullptr;
	PFN_vkUnmapMemory unmapMemory = nullptr;
	PFN_vkFlushMappedMemoryRanges flushMappedMemoryRanges = nullptr;
	PFN_vkInvalidateMappedMemoryRanges invalidateMappedMemoryRanges = nullptr;
	PFN_vkGetDeviceMemoryCommitment getDeviceMemoryCommitment = nullptr;
	PFN_vkBindBufferMemory bindBufferMemory = nullptr;
	PFN_vkBindImageMemory bindImageMemory = nullptr;
	PFN_vkGetBufferMemoryRequirements getBufferMemoryRequirements = nullptr;
	PFN_vkGetImageMemoryRequirements getImageMemoryRequirements = nullptr;
	PFN_vkGetImageSparseMemoryRequirements getImageSparseMemoryRequirements = nullptr;
	PFN_vkQueueBindSparse queueBindSparse = nullptr;
	PFN_vkCreateFence createFence = nullptr;
	PFN_vkDestroyFence destroyFence = nullptr;
	PFN_vkResetFences resetFences = nullptr;
	PFN_vkGetFenceStatus getFenceStatus = nullptr;
	PFN_vkWaitForFences waitForFences = nullptr;
	PFN_vkCreateSemaphore createSemaphore = nullptr;
	PFN_vkDestroySemaphore destroySemaphore = nullptr;
	PFN_vkCreateEvent createEvent = nullptr;
	PFN_vkDestroyEvent destroyEvent = nullptr;
	PFN_vkGetEventStatus getEventStatus = nullptr;
	PFN_vkSetEvent setEvent = nullptr;
	PFN_vkResetEvent resetEvent = nullptr;
	PFN_vkCreateQueryPool createQueryPool = nullptr;
	PFN_vkDestroyQueryPool destroyQueryPool = nullptr;
	PFN_vkGetQueryPoolResults getQueryPoolResults = nullptr;
	PFN_vkCreateBuffer createBuffer = nullptr;
	PFN_vkDestroyBuffer destroyBuffer = nullptr;
	PFN_vkCreateBufferView createBufferView = nullptr;
	PFN_vkDestroyBufferView destroyBufferView = nullptr;
	PFN_vkCreateImage createImage = nullptr;
	PFN_vkDestroyImage destroyImage = nullptr;
	PFN_vkGetImageSubresourceLayout getImageSubresourceLayout = nullptr;
	PFN_vkCreateImageView createImageView = nullptr;
	PFN_vkDestroyImageView destroyImageView = nullptr;
	PFN_vkCreateShaderModule createShaderModule = nullptr;
	PFN_vkDestroyShaderModule destroyShaderModule = nullptr;
	PFN_vkCreatePipelineCache createPipelineCache = nullptr;
	PFN_vkDestroyPipelineCache destroyPipelineCache = nullptr;
	PFN_vkGetPipelineCacheData getPipelineCacheData = nullptr;
	PFN_vkMergePipelineCaches mergePipelineCaches = nullptr;
	PFN_vkCreateGraphicsPipelines createGraphicsPipelines = nullptr;
	PFN_vkCreateComputePipelines createComputePipelines = nullptr;
	PFN_vkDestroyPipeline destroyPipeline = nullptr;
	PFN_vkCreatePipelineLayout createPipelineLayout = nullptr;
	PFN_vkDestroyPipelineLayout destroyPipelineLayout = nullptr;
	PFN_vkCreateSampler createSampler = nullptr;
	PFN_vkDestroySampler destroySampler = nullptr;
	PFN_vkCreateDescriptorSetLayout createDescriptorSetLayout = nullptr;
	PFN_vkDestroyDescriptorSetLayout destroyDescriptorSetLayout = nullptr;
	PFN_vkCreateDescriptorPool createDescriptorPool = nullptr;
	PFN_vkDestroyDescriptorPool destroyDescriptorPool = nullptr;
	PFN_vkResetDescriptorPool resetDescriptorPool = nullptr;
	PFN_vkAllocateDescriptorSets allocateDescriptorSets = nullptr;
	PFN_vkFreeDescriptorSets freeDescriptorSets = nullptr;
	PFN_vkUpdateDescriptorSets updateDescriptorSets = nullptr;
	PFN_vkCreateFramebuffer createFramebuffer = nullptr;
	PFN_vkDestroyFramebuffer destroyFramebuffer = nullptr;
	PFN_vkCreateRenderPass createRenderPass = nullptr;
	PFN_vkDestroyRenderPass destroyRenderPass = nullptr;
	PFN_vkGetRenderAreaGranularity getRenderAreaGranularity = nullptr;
	PFN_vkCreateCommandPool createCommandPool = nullptr;
	PFN_vkDestroyCommandPool destroyCommandPool = nullptr;
	PFN_vkResetCommandPool resetCommandPool = nullptr;
	PFN_vkAllocateCommandBuffers allocateCommandBuffers = nullptr;
	PFN_vkFreeCommandBuffers freeCommandBuffers = nullptr;
	PFN_vkBeginCommandBuffer beginCommandBuffer = nullptr;
	PFN_vkEndCommandBuffer endCommandBuffer = nullptr;
	PFN_vkResetCommandBuffer resetCommandBuffer = nullptr;
	PFN_vkCmdBindPipeline cmdBindPipeline = nullptr;
	PFN_vkCmdSetViewport cmdSetViewport = nullptr;
	PFN_vkCmdSetScissor cmdSetScissor = nullptr;
	PFN_vkCmdSetLineWidth cmdSetLineWidth = nullptr;
	PFN_vkCmdSetDepthBias cmdSetDepthBias = nullptr;
	PFN_vkCmdSetBlendConstants cmdSetBlendConstants = nullptr;
	PFN_vkCmdSetDepthBounds cmdSetDepthBounds = nullptr;
	PFN_vkCmdSetStencilCompareMask cmdSetStencilCompareMask = nullptr;
	PFN_vkCmdSetStencilWriteMask cmdSetStencilWriteMask = nullptr;
	PFN_vkCmdSetStencilReference cmdSetStencilReference = nullptr;
	PFN_vkCmdBindDescriptorSets cmdBindDescriptorSets = nullptr;
	PFN_vkCmdBindIndexBuffer cmdBindIndexBuffer = nullptr;
	PFN_vkCmdBindVertexBuffers cmdBindVertexBuffers = nullptr;
	PFN_vkCmdDraw cmdDraw = nullptr;
	PFN_vkCmdDrawIndexed cmdDrawIndexed = nullptr;
	PFN_vkCmdDrawIndirect cmdDrawIndirect = nullptr;
	PFN_vkCmdDrawIndexedIndirect cmdDrawIndexedIndirect = nullptr;
	PFN_vkCmdDispatch cmdDispatch = nullptr;
	PFN_vkCmdDispatchIndirect cmdDispatchIndirect = nullptr;
	PFN_vkCmdCopyBuffer cmdCopyBuffer = nullptr;
	PFN_vkCmdCopyImage cmdCopyImage = nullptr;
	PFN_vkCmdBlitImage cmdBlitImage = nullptr;
	PFN_vkCmdCopyBufferToImage cmdCopyBufferToImage = nullptr;
	PFN_vkCmdCopyImageToBuffer cmdCopyImageToBuffer = nullptr;
	PFN_vkCmdUpdateBuffer cmdUpdateBuffer = nullptr;
	PFN_vkCmdFillBuffer cmdFillBuffer = nullptr;
	PFN_vkCmdClearColorImage cmdClearColorImage = nullptr;
	PFN_vkCmdClearDepthStencilImage cmdClearDepthStencilImage = nullptr;
	PFN_vkCmdClearAttachments cmdClearAttachments = nullptr;
	PFN_vkCmdResolveImage cmdResolveImage = nullptr;
	PFN_vkCmdSetEvent cmdSetEvent = nullptr;
	PFN_vkCmdResetEvent cmdResetEvent = nullptr;
	PFN_vkCmdWaitEvents cmdWaitEvents = nullptr;
	PFN_vkCmdPipelineBarrier cmdPipelineBarrier = nullptr;
	PFN_vkCmdBeginQuery cmdBeginQuery = nullptr;
	PFN_vkCmdEndQuery cmdEndQuery = nullptr;
	PFN_vkCmdResetQueryPool cmdResetQueryPool = nullptr;
	PFN_vkCmdWriteTimestamp cmdWriteTimestamp = nullptr;
	PFN_vkCmdCopyQueryPoolResults cmdCopyQueryPoolResults = nullptr;
	PFN_vkCmdPushConstants cmdPushConstants = nullptr;
	PFN_vkCmdBeginRenderPass cmdBeginRenderPass = nullptr;
	PFN_vkCmdNextSubpass cmdNextSubpass = nullptr;
	PFN_vkCmdEndRenderPass cmdEndRenderPass = nullptr;
	PFN_vkCmdExecuteCommands cmdExecuteCommands = nullptr;
#endif
#ifdef VK_VERSION_1_1
	PFN_vkBindBufferMemory2 bindBufferMemory2 = nullptr;
	PFN_vkBindImageMemory2 bindImageMemory2 = nullptr;
	PFN_vkGetDeviceGroupPeerMemoryFeatures getDeviceGroupPeerMemoryFeatures = nullptr;
	PFN_vkCmdSetDeviceMask cmdSetDeviceMask = nullptr;
	PFN_vkCmdDispatchBase cmdDispatchBase = nullptr;
	PFN_vkGetImageMemoryRequirements2 getImageMemoryRequirements2 = nullptr;
	PFN_vkGetBufferMemoryRequirements2 getBufferMemoryRequirements2 = nullptr;
	PFN_vkGetImageSparseMemoryRequirements2 getImageSparseMemoryRequirements2 = nullptr;
	PFN_vkTrimCommandPool trimCommandPool = nullptr;
	PFN_vkGetDeviceQueue2 getDeviceQueue2 = nullptr;
	PFN_vkCreateSamplerYcbcrConversion createSamplerYcbcrConversion = nullptr;
	PFN_vkDestroySamplerYcbcrConversion destroySamplerYcbcrConversion = nullptr;
	PFN_vkCreateDescriptorUpdateTemplate createDescriptorUpdateTemplate = nullptr;
	PFN_vkDestroyDescriptorUpdateTemplate destroyDescriptorUpdateTemplate = nullptr;
	PFN_vkUpdateDescriptorSetWithTemplate updateDescriptorSetWithTemplate = nullptr;
	PFN_vkGetDescriptorSetLayoutSupport getDescriptorSetLayoutSupport = nullptr;
#endif
#ifdef VK_VERSION_1_2
	PFN_vkCmdDrawIndirectCount cmdDrawIndirectCount = nullptr;
	PFN_vkCmdDrawIndexedIndirectCount cmdDrawIndexedIndirectCount = nullptr;
	PFN_vkCreateRenderPass2 createRenderPass2 = nullptr;
	PFN_vkCmdBeginRenderPass2 cmdBeginRenderPass2 = nullptr;
	PFN_vkCmdNextSubpass2 cmdNextSubpass2 = nullptr;
	PFN_vkCmdEndRenderPass2 cmdEndRenderPass2 = nullptr;
	PFN_vkResetQueryPool resetQueryPool = nullptr;
	PFN_vkGetSemaphoreCounterValue getSemaphoreCounterValue = nullptr;
	PFN_vkWaitSemaphores waitSemaphores = nullptr;
	PFN_vkSignalSemaphore signalSemaphore = nullptr;
	PFN_vkGetBufferDeviceAddress getBufferDeviceAddress = nullptr;
	PFN_vkGetBufferOpaqueCaptureAddress getBufferOpaqueCaptureAddress = nullptr;
	PFN_vkGetDeviceMemoryOpaqueCaptureAddress getDeviceMemoryOpaqueCaptureAddress = nullptr;
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSwapchainKHR_DECLARE
#define PFN_vkCreateSwapchainKHR_DECLARE
	PFN_vkCreateSwapchainKHR createSwapchainKHR = nullptr;
#endif
#ifndef PFN_vkDestroySwapchainKHR_DECLARE
#define PFN_vkDestroySwapchainKHR_DECLARE
	PFN_vkDestroySwapchainKHR destroySwapchainKHR = nullptr;
#endif
#ifndef PFN_vkGetSwapchainImagesKHR_DECLARE
#define PFN_vkGetSwapchainImagesKHR_DECLARE
	PFN_vkGetSwapchainImagesKHR getSwapchainImagesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImageKHR_DECLARE
#define PFN_vkAcquireNextImageKHR_DECLARE
	PFN_vkAcquireNextImageKHR acquireNextImageKHR = nullptr;
#endif
#ifndef PFN_vkQueuePresentKHR_DECLARE
#define PFN_vkQueuePresentKHR_DECLARE
	PFN_vkQueuePresentKHR queuePresentKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
	PFN_vkGetDeviceGroupPresentCapabilitiesKHR getDeviceGroupPresentCapabilitiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModesKHR getDeviceGroupSurfacePresentModesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImage2KHR_DECLARE
#define PFN_vkAcquireNextImage2KHR_DECLARE
	PFN_vkAcquireNextImage2KHR acquireNextImage2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_display_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSharedSwapchainsKHR_DECLARE
#define PFN_vkCreateSharedSwapchainsKHR_DECLARE
	PFN_vkCreateSharedSwapchainsKHR createSharedSwapchainsKHR = nullptr;
#endif
#endif
#if defined(VK_ANDROID_native_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainGrallocUsageANDROID_DECLARE
#define PFN_vkGetSwapchainGrallocUsageANDROID_DECLARE
	PFN_vkGetSwapchainGrallocUsageANDROID getSwapchainGrallocUsageANDROID = nullptr;
#endif
#ifndef PFN_vkAcquireImageANDROID_DECLARE
#define PFN_vkAcquireImageANDROID_DECLARE
	PFN_vkAcquireImageANDROID acquireImageANDROID = nullptr;
#endif
#ifndef PFN_vkQueueSignalReleaseImageANDROID_DECLARE
#define PFN_vkQueueSignalReleaseImageANDROID_DECLARE
	PFN_vkQueueSignalReleaseImageANDROID queueSignalReleaseImageANDROID = nullptr;
#endif
#ifndef PFN_vkGetSwapchainGrallocUsage2ANDROID_DECLARE
#define PFN_vkGetSwapchainGrallocUsage2ANDROID_DECLARE
	PFN_vkGetSwapchainGrallocUsage2ANDROID getSwapchainGrallocUsage2ANDROID = nullptr;
#endif
#endif
#if defined(VK_EXT_debug_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDebugMarkerSetObjectTagEXT_DECLARE
#define PFN_vkDebugMarkerSetObjectTagEXT_DECLARE
	PFN_vkDebugMarkerSetObjectTagEXT debugMarkerSetObjectTagEXT = nullptr;
#endif
#ifndef PFN_vkDebugMarkerSetObjectNameEXT_DECLARE
#define PFN_vkDebugMarkerSetObjectNameEXT_DECLARE
	PFN_vkDebugMarkerSetObjectNameEXT debugMarkerSetObjectNameEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerBeginEXT_DECLARE
#define PFN_vkCmdDebugMarkerBeginEXT_DECLARE
	PFN_vkCmdDebugMarkerBeginEXT cmdDebugMarkerBeginEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerEndEXT_DECLARE
#define PFN_vkCmdDebugMarkerEndEXT_DECLARE
	PFN_vkCmdDebugMarkerEndEXT cmdDebugMarkerEndEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerInsertEXT_DECLARE
#define PFN_vkCmdDebugMarkerInsertEXT_DECLARE
	PFN_vkCmdDebugMarkerInsertEXT cmdDebugMarkerInsertEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_video_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateVideoSessionKHR_DECLARE
#define PFN_vkCreateVideoSessionKHR_DECLARE
	PFN_vkCreateVideoSessionKHR createVideoSessionKHR = nullptr;
#endif
#ifndef PFN_vkDestroyVideoSessionKHR_DECLARE
#define PFN_vkDestroyVideoSessionKHR_DECLARE
	PFN_vkDestroyVideoSessionKHR destroyVideoSessionKHR = nullptr;
#endif
#ifndef PFN_vkGetVideoSessionMemoryRequirementsKHR_DECLARE
#define PFN_vkGetVideoSessionMemoryRequirementsKHR_DECLARE
	PFN_vkGetVideoSessionMemoryRequirementsKHR getVideoSessionMemoryRequirementsKHR = nullptr;
#endif
#ifndef PFN_vkBindVideoSessionMemoryKHR_DECLARE
#define PFN_vkBindVideoSessionMemoryKHR_DECLARE
	PFN_vkBindVideoSessionMemoryKHR bindVideoSessionMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCreateVideoSessionParametersKHR_DECLARE
#define PFN_vkCreateVideoSessionParametersKHR_DECLARE
	PFN_vkCreateVideoSessionParametersKHR createVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkUpdateVideoSessionParametersKHR_DECLARE
#define PFN_vkUpdateVideoSessionParametersKHR_DECLARE
	PFN_vkUpdateVideoSessionParametersKHR updateVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkDestroyVideoSessionParametersKHR_DECLARE
#define PFN_vkDestroyVideoSessionParametersKHR_DECLARE
	PFN_vkDestroyVideoSessionParametersKHR destroyVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkCmdBeginVideoCodingKHR_DECLARE
#define PFN_vkCmdBeginVideoCodingKHR_DECLARE
	PFN_vkCmdBeginVideoCodingKHR cmdBeginVideoCodingKHR = nullptr;
#endif
#ifndef PFN_vkCmdEndVideoCodingKHR_DECLARE
#define PFN_vkCmdEndVideoCodingKHR_DECLARE
	PFN_vkCmdEndVideoCodingKHR cmdEndVideoCodingKHR = nullptr;
#endif
#ifndef PFN_vkCmdControlVideoCodingKHR_DECLARE
#define PFN_vkCmdControlVideoCodingKHR_DECLARE
	PFN_vkCmdControlVideoCodingKHR cmdControlVideoCodingKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_video_decode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDecodeVideoKHR_DECLARE
#define PFN_vkCmdDecodeVideoKHR_DECLARE
	PFN_vkCmdDecodeVideoKHR cmdDecodeVideoKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_video_encode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdEncodeVideoKHR_DECLARE
#define PFN_vkCmdEncodeVideoKHR_DECLARE
	PFN_vkCmdEncodeVideoKHR cmdEncodeVideoKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_transform_feedback) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindTransformFeedbackBuffersEXT_DECLARE
#define PFN_vkCmdBindTransformFeedbackBuffersEXT_DECLARE
	PFN_vkCmdBindTransformFeedbackBuffersEXT cmdBindTransformFeedbackBuffersEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginTransformFeedbackEXT_DECLARE
#define PFN_vkCmdBeginTransformFeedbackEXT_DECLARE
	PFN_vkCmdBeginTransformFeedbackEXT cmdBeginTransformFeedbackEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndTransformFeedbackEXT_DECLARE
#define PFN_vkCmdEndTransformFeedbackEXT_DECLARE
	PFN_vkCmdEndTransformFeedbackEXT cmdEndTransformFeedbackEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginQueryIndexedEXT_DECLARE
#define PFN_vkCmdBeginQueryIndexedEXT_DECLARE
	PFN_vkCmdBeginQueryIndexedEXT cmdBeginQueryIndexedEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndQueryIndexedEXT_DECLARE
#define PFN_vkCmdEndQueryIndexedEXT_DECLARE
	PFN_vkCmdEndQueryIndexedEXT cmdEndQueryIndexedEXT = nullptr;
#endif
#ifndef PFN_vkCmdDrawIndirectByteCountEXT_DECLARE
#define PFN_vkCmdDrawIndirectByteCountEXT_DECLARE
	PFN_vkCmdDrawIndirectByteCountEXT cmdDrawIndirectByteCountEXT = nullptr;
#endif
#endif
#if defined(VK_NVX_image_view_handle) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageViewHandleNVX_DECLARE
#define PFN_vkGetImageViewHandleNVX_DECLARE
	PFN_vkGetImageViewHandleNVX getImageViewHandleNVX = nullptr;
#endif
#ifndef PFN_vkGetImageViewAddressNVX_DECLARE
#define PFN_vkGetImageViewAddressNVX_DECLARE
	PFN_vkGetImageViewAddressNVX getImageViewAddressNVX = nullptr;
#endif
#endif
#if defined(VK_AMD_draw_indirect_count) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawIndirectCountAMD_DECLARE
#define PFN_vkCmdDrawIndirectCountAMD_DECLARE
	PFN_vkCmdDrawIndirectCountAMD cmdDrawIndirectCountAMD = nullptr;
#endif
#ifndef PFN_vkCmdDrawIndexedIndirectCountAMD_DECLARE
#define PFN_vkCmdDrawIndexedIndirectCountAMD_DECLARE
	PFN_vkCmdDrawIndexedIndirectCountAMD cmdDrawIndexedIndirectCountAMD = nullptr;
#endif
#endif
#if defined(VK_AMD_shader_info) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetShaderInfoAMD_DECLARE
#define PFN_vkGetShaderInfoAMD_DECLARE
	PFN_vkGetShaderInfoAMD getShaderInfoAMD = nullptr;
#endif
#endif
#if defined(VK_NV_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleNV_DECLARE
#define PFN_vkGetMemoryWin32HandleNV_DECLARE
	PFN_vkGetMemoryWin32HandleNV getMemoryWin32HandleNV = nullptr;
#endif
#endif
#if defined(VK_KHR_device_group) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_DECLARE
#define PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_DECLARE
	PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR getDeviceGroupPeerMemoryFeaturesKHR = nullptr;
#endif
#ifndef PFN_vkCmdSetDeviceMaskKHR_DECLARE
#define PFN_vkCmdSetDeviceMaskKHR_DECLARE
	PFN_vkCmdSetDeviceMaskKHR cmdSetDeviceMaskKHR = nullptr;
#endif
#ifndef PFN_vkCmdDispatchBaseKHR_DECLARE
#define PFN_vkCmdDispatchBaseKHR_DECLARE
	PFN_vkCmdDispatchBaseKHR cmdDispatchBaseKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
	PFN_vkGetDeviceGroupPresentCapabilitiesKHR getDeviceGroupPresentCapabilitiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModesKHR getDeviceGroupSurfacePresentModesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImage2KHR_DECLARE
#define PFN_vkAcquireNextImage2KHR_DECLARE
	PFN_vkAcquireNextImage2KHR acquireNextImage2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_maintenance1) && defined(VK_VERSION_1_0)
#ifndef PFN_vkTrimCommandPoolKHR_DECLARE
#define PFN_vkTrimCommandPoolKHR_DECLARE
	PFN_vkTrimCommandPoolKHR trimCommandPoolKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleKHR_DECLARE
#define PFN_vkGetMemoryWin32HandleKHR_DECLARE
	PFN_vkGetMemoryWin32HandleKHR getMemoryWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetMemoryWin32HandlePropertiesKHR_DECLARE
#define PFN_vkGetMemoryWin32HandlePropertiesKHR_DECLARE
	PFN_vkGetMemoryWin32HandlePropertiesKHR getMemoryWin32HandlePropertiesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_memory_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryFdKHR_DECLARE
#define PFN_vkGetMemoryFdKHR_DECLARE
	PFN_vkGetMemoryFdKHR getMemoryFdKHR = nullptr;
#endif
#ifndef PFN_vkGetMemoryFdPropertiesKHR_DECLARE
#define PFN_vkGetMemoryFdPropertiesKHR_DECLARE
	PFN_vkGetMemoryFdPropertiesKHR getMemoryFdPropertiesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_semaphore_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreWin32HandleKHR_DECLARE
#define PFN_vkImportSemaphoreWin32HandleKHR_DECLARE
	PFN_vkImportSemaphoreWin32HandleKHR importSemaphoreWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreWin32HandleKHR_DECLARE
#define PFN_vkGetSemaphoreWin32HandleKHR_DECLARE
	PFN_vkGetSemaphoreWin32HandleKHR getSemaphoreWin32HandleKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_semaphore_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreFdKHR_DECLARE
#define PFN_vkImportSemaphoreFdKHR_DECLARE
	PFN_vkImportSemaphoreFdKHR importSemaphoreFdKHR = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreFdKHR_DECLARE
#define PFN_vkGetSemaphoreFdKHR_DECLARE
	PFN_vkGetSemaphoreFdKHR getSemaphoreFdKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdPushDescriptorSetKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetKHR_DECLARE
	PFN_vkCmdPushDescriptorSetKHR cmdPushDescriptorSetKHR = nullptr;
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR cmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR cmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_conditional_rendering) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBeginConditionalRenderingEXT_DECLARE
#define PFN_vkCmdBeginConditionalRenderingEXT_DECLARE
	PFN_vkCmdBeginConditionalRenderingEXT cmdBeginConditionalRenderingEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndConditionalRenderingEXT_DECLARE
#define PFN_vkCmdEndConditionalRenderingEXT_DECLARE
	PFN_vkCmdEndConditionalRenderingEXT cmdEndConditionalRenderingEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_descriptor_update_template) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDescriptorUpdateTemplateKHR_DECLARE
#define PFN_vkCreateDescriptorUpdateTemplateKHR_DECLARE
	PFN_vkCreateDescriptorUpdateTemplateKHR createDescriptorUpdateTemplateKHR = nullptr;
#endif
#ifndef PFN_vkDestroyDescriptorUpdateTemplateKHR_DECLARE
#define PFN_vkDestroyDescriptorUpdateTemplateKHR_DECLARE
	PFN_vkDestroyDescriptorUpdateTemplateKHR destroyDescriptorUpdateTemplateKHR = nullptr;
#endif
#ifndef PFN_vkUpdateDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkUpdateDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkUpdateDescriptorSetWithTemplateKHR updateDescriptorSetWithTemplateKHR = nullptr;
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR cmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_NV_clip_space_w_scaling) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetViewportWScalingNV_DECLARE
#define PFN_vkCmdSetViewportWScalingNV_DECLARE
	PFN_vkCmdSetViewportWScalingNV cmdSetViewportWScalingNV = nullptr;
#endif
#endif
#if defined(VK_EXT_display_control) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDisplayPowerControlEXT_DECLARE
#define PFN_vkDisplayPowerControlEXT_DECLARE
	PFN_vkDisplayPowerControlEXT displayPowerControlEXT = nullptr;
#endif
#ifndef PFN_vkRegisterDeviceEventEXT_DECLARE
#define PFN_vkRegisterDeviceEventEXT_DECLARE
	PFN_vkRegisterDeviceEventEXT registerDeviceEventEXT = nullptr;
#endif
#ifndef PFN_vkRegisterDisplayEventEXT_DECLARE
#define PFN_vkRegisterDisplayEventEXT_DECLARE
	PFN_vkRegisterDisplayEventEXT registerDisplayEventEXT = nullptr;
#endif
#ifndef PFN_vkGetSwapchainCounterEXT_DECLARE
#define PFN_vkGetSwapchainCounterEXT_DECLARE
	PFN_vkGetSwapchainCounterEXT getSwapchainCounterEXT = nullptr;
#endif
#endif
#if defined(VK_GOOGLE_display_timing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetRefreshCycleDurationGOOGLE_DECLARE
#define PFN_vkGetRefreshCycleDurationGOOGLE_DECLARE
	PFN_vkGetRefreshCycleDurationGOOGLE getRefreshCycleDurationGOOGLE = nullptr;
#endif
#ifndef PFN_vkGetPastPresentationTimingGOOGLE_DECLARE
#define PFN_vkGetPastPresentationTimingGOOGLE_DECLARE
	PFN_vkGetPastPresentationTimingGOOGLE getPastPresentationTimingGOOGLE = nullptr;
#endif
#endif
#if defined(VK_EXT_discard_rectangles) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetDiscardRectangleEXT_DECLARE
#define PFN_vkCmdSetDiscardRectangleEXT_DECLARE
	PFN_vkCmdSetDiscardRectangleEXT cmdSetDiscardRectangleEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_hdr_metadata) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetHdrMetadataEXT_DECLARE
#define PFN_vkSetHdrMetadataEXT_DECLARE
	PFN_vkSetHdrMetadataEXT setHdrMetadataEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_create_renderpass2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateRenderPass2KHR_DECLARE
#define PFN_vkCreateRenderPass2KHR_DECLARE
	PFN_vkCreateRenderPass2KHR createRenderPass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdBeginRenderPass2KHR_DECLARE
#define PFN_vkCmdBeginRenderPass2KHR_DECLARE
	PFN_vkCmdBeginRenderPass2KHR cmdBeginRenderPass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdNextSubpass2KHR_DECLARE
#define PFN_vkCmdNextSubpass2KHR_DECLARE
	PFN_vkCmdNextSubpass2KHR cmdNextSubpass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdEndRenderPass2KHR_DECLARE
#define PFN_vkCmdEndRenderPass2KHR_DECLARE
	PFN_vkCmdEndRenderPass2KHR cmdEndRenderPass2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_shared_presentable_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainStatusKHR_DECLARE
#define PFN_vkGetSwapchainStatusKHR_DECLARE
	PFN_vkGetSwapchainStatusKHR getSwapchainStatusKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_fence_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceWin32HandleKHR_DECLARE
#define PFN_vkImportFenceWin32HandleKHR_DECLARE
	PFN_vkImportFenceWin32HandleKHR importFenceWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetFenceWin32HandleKHR_DECLARE
#define PFN_vkGetFenceWin32HandleKHR_DECLARE
	PFN_vkGetFenceWin32HandleKHR getFenceWin32HandleKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_fence_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceFdKHR_DECLARE
#define PFN_vkImportFenceFdKHR_DECLARE
	PFN_vkImportFenceFdKHR importFenceFdKHR = nullptr;
#endif
#ifndef PFN_vkGetFenceFdKHR_DECLARE
#define PFN_vkGetFenceFdKHR_DECLARE
	PFN_vkGetFenceFdKHR getFenceFdKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireProfilingLockKHR_DECLARE
#define PFN_vkAcquireProfilingLockKHR_DECLARE
	PFN_vkAcquireProfilingLockKHR acquireProfilingLockKHR = nullptr;
#endif
#ifndef PFN_vkReleaseProfilingLockKHR_DECLARE
#define PFN_vkReleaseProfilingLockKHR_DECLARE
	PFN_vkReleaseProfilingLockKHR releaseProfilingLockKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_debug_utils) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetDebugUtilsObjectNameEXT_DECLARE
#define PFN_vkSetDebugUtilsObjectNameEXT_DECLARE
	PFN_vkSetDebugUtilsObjectNameEXT setDebugUtilsObjectNameEXT = nullptr;
#endif
#ifndef PFN_vkSetDebugUtilsObjectTagEXT_DECLARE
#define PFN_vkSetDebugUtilsObjectTagEXT_DECLARE
	PFN_vkSetDebugUtilsObjectTagEXT setDebugUtilsObjectTagEXT = nullptr;
#endif
#ifndef PFN_vkQueueBeginDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueBeginDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueBeginDebugUtilsLabelEXT queueBeginDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkQueueEndDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueEndDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueEndDebugUtilsLabelEXT queueEndDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkQueueInsertDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueInsertDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueInsertDebugUtilsLabelEXT queueInsertDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdBeginDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdBeginDebugUtilsLabelEXT cmdBeginDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdEndDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdEndDebugUtilsLabelEXT cmdEndDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdInsertDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdInsertDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdInsertDebugUtilsLabelEXT cmdInsertDebugUtilsLabelEXT = nullptr;
#endif
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetAndroidHardwareBufferPropertiesANDROID_DECLARE
#define PFN_vkGetAndroidHardwareBufferPropertiesANDROID_DECLARE
	PFN_vkGetAndroidHardwareBufferPropertiesANDROID getAndroidHardwareBufferPropertiesANDROID = nullptr;
#endif
#ifndef PFN_vkGetMemoryAndroidHardwareBufferANDROID_DECLARE
#define PFN_vkGetMemoryAndroidHardwareBufferANDROID_DECLARE
	PFN_vkGetMemoryAndroidHardwareBufferANDROID getMemoryAndroidHardwareBufferANDROID = nullptr;
#endif
#endif
#if defined(VK_EXT_sample_locations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetSampleLocationsEXT_DECLARE
#define PFN_vkCmdSetSampleLocationsEXT_DECLARE
	PFN_vkCmdSetSampleLocationsEXT cmdSetSampleLocationsEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_get_memory_requirements2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageMemoryRequirements2KHR_DECLARE
#define PFN_vkGetImageMemoryRequirements2KHR_DECLARE
	PFN_vkGetImageMemoryRequirements2KHR getImageMemoryRequirements2KHR = nullptr;
#endif
#ifndef PFN_vkGetBufferMemoryRequirements2KHR_DECLARE
#define PFN_vkGetBufferMemoryRequirements2KHR_DECLARE
	PFN_vkGetBufferMemoryRequirements2KHR getBufferMemoryRequirements2KHR = nullptr;
#endif
#ifndef PFN_vkGetImageSparseMemoryRequirements2KHR_DECLARE
#define PFN_vkGetImageSparseMemoryRequirements2KHR_DECLARE
	PFN_vkGetImageSparseMemoryRequirements2KHR getImageSparseMemoryRequirements2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_acceleration_structure) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureKHR_DECLARE
#define PFN_vkCreateAccelerationStructureKHR_DECLARE
	PFN_vkCreateAccelerationStructureKHR createAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkDestroyAccelerationStructureKHR_DECLARE
#define PFN_vkDestroyAccelerationStructureKHR_DECLARE
	PFN_vkDestroyAccelerationStructureKHR destroyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresKHR_DECLARE
#define PFN_vkCmdBuildAccelerationStructuresKHR_DECLARE
	PFN_vkCmdBuildAccelerationStructuresKHR cmdBuildAccelerationStructuresKHR = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresIndirectKHR_DECLARE
#define PFN_vkCmdBuildAccelerationStructuresIndirectKHR_DECLARE
	PFN_vkCmdBuildAccelerationStructuresIndirectKHR cmdBuildAccelerationStructuresIndirectKHR = nullptr;
#endif
#ifndef PFN_vkBuildAccelerationStructuresKHR_DECLARE
#define PFN_vkBuildAccelerationStructuresKHR_DECLARE
	PFN_vkBuildAccelerationStructuresKHR buildAccelerationStructuresKHR = nullptr;
#endif
#ifndef PFN_vkCopyAccelerationStructureKHR_DECLARE
#define PFN_vkCopyAccelerationStructureKHR_DECLARE
	PFN_vkCopyAccelerationStructureKHR copyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCopyAccelerationStructureToMemoryKHR_DECLARE
#define PFN_vkCopyAccelerationStructureToMemoryKHR_DECLARE
	PFN_vkCopyAccelerationStructureToMemoryKHR copyAccelerationStructureToMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCopyMemoryToAccelerationStructureKHR_DECLARE
#define PFN_vkCopyMemoryToAccelerationStructureKHR_DECLARE
	PFN_vkCopyMemoryToAccelerationStructureKHR copyMemoryToAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkWriteAccelerationStructuresPropertiesKHR_DECLARE
#define PFN_vkWriteAccelerationStructuresPropertiesKHR_DECLARE
	PFN_vkWriteAccelerationStructuresPropertiesKHR writeAccelerationStructuresPropertiesKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureKHR_DECLARE
#define PFN_vkCmdCopyAccelerationStructureKHR_DECLARE
	PFN_vkCmdCopyAccelerationStructureKHR cmdCopyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureToMemoryKHR_DECLARE
#define PFN_vkCmdCopyAccelerationStructureToMemoryKHR_DECLARE
	PFN_vkCmdCopyAccelerationStructureToMemoryKHR cmdCopyAccelerationStructureToMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyMemoryToAccelerationStructureKHR_DECLARE
#define PFN_vkCmdCopyMemoryToAccelerationStructureKHR_DECLARE
	PFN_vkCmdCopyMemoryToAccelerationStructureKHR cmdCopyMemoryToAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureDeviceAddressKHR_DECLARE
#define PFN_vkGetAccelerationStructureDeviceAddressKHR_DECLARE
	PFN_vkGetAccelerationStructureDeviceAddressKHR getAccelerationStructureDeviceAddressKHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_DECLARE
#define PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_DECLARE
	PFN_vkCmdWriteAccelerationStructuresPropertiesKHR cmdWriteAccelerationStructuresPropertiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_DECLARE
#define PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_DECLARE
	PFN_vkGetDeviceAccelerationStructureCompatibilityKHR getDeviceAccelerationStructureCompatibilityKHR = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureBuildSizesKHR_DECLARE
#define PFN_vkGetAccelerationStructureBuildSizesKHR_DECLARE
	PFN_vkGetAccelerationStructureBuildSizesKHR getAccelerationStructureBuildSizesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_ray_tracing_pipeline) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdTraceRaysKHR_DECLARE
#define PFN_vkCmdTraceRaysKHR_DECLARE
	PFN_vkCmdTraceRaysKHR cmdTraceRaysKHR = nullptr;
#endif
#ifndef PFN_vkCreateRayTracingPipelinesKHR_DECLARE
#define PFN_vkCreateRayTracingPipelinesKHR_DECLARE
	PFN_vkCreateRayTracingPipelinesKHR createRayTracingPipelinesKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesKHR_DECLARE
#define PFN_vkGetRayTracingShaderGroupHandlesKHR_DECLARE
	PFN_vkGetRayTracingShaderGroupHandlesKHR getRayTracingShaderGroupHandlesKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_DECLARE
#define PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_DECLARE
	PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR getRayTracingCaptureReplayShaderGroupHandlesKHR = nullptr;
#endif
#ifndef PFN_vkCmdTraceRaysIndirectKHR_DECLARE
#define PFN_vkCmdTraceRaysIndirectKHR_DECLARE
	PFN_vkCmdTraceRaysIndirectKHR cmdTraceRaysIndirectKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupStackSizeKHR_DECLARE
#define PFN_vkGetRayTracingShaderGroupStackSizeKHR_DECLARE
	PFN_vkGetRayTracingShaderGroupStackSizeKHR getRayTracingShaderGroupStackSizeKHR = nullptr;
#endif
#ifndef PFN_vkCmdSetRayTracingPipelineStackSizeKHR_DECLARE
#define PFN_vkCmdSetRayTracingPipelineStackSizeKHR_DECLARE
	PFN_vkCmdSetRayTracingPipelineStackSizeKHR cmdSetRayTracingPipelineStackSizeKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSamplerYcbcrConversionKHR_DECLARE
#define PFN_vkCreateSamplerYcbcrConversionKHR_DECLARE
	PFN_vkCreateSamplerYcbcrConversionKHR createSamplerYcbcrConversionKHR = nullptr;
#endif
#ifndef PFN_vkDestroySamplerYcbcrConversionKHR_DECLARE
#define PFN_vkDestroySamplerYcbcrConversionKHR_DECLARE
	PFN_vkDestroySamplerYcbcrConversionKHR destroySamplerYcbcrConversionKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_bind_memory2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkBindBufferMemory2KHR_DECLARE
#define PFN_vkBindBufferMemory2KHR_DECLARE
	PFN_vkBindBufferMemory2KHR bindBufferMemory2KHR = nullptr;
#endif
#ifndef PFN_vkBindImageMemory2KHR_DECLARE
#define PFN_vkBindImageMemory2KHR_DECLARE
	PFN_vkBindImageMemory2KHR bindImageMemory2KHR = nullptr;
#endif
#endif
#if defined(VK_EXT_image_drm_format_modifier) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageDrmFormatModifierPropertiesEXT_DECLARE
#define PFN_vkGetImageDrmFormatModifierPropertiesEXT_DECLARE
	PFN_vkGetImageDrmFormatModifierPropertiesEXT getImageDrmFormatModifierPropertiesEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_validation_cache) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateValidationCacheEXT_DECLARE
#define PFN_vkCreateValidationCacheEXT_DECLARE
	PFN_vkCreateValidationCacheEXT createValidationCacheEXT = nullptr;
#endif
#ifndef PFN_vkDestroyValidationCacheEXT_DECLARE
#define PFN_vkDestroyValidationCacheEXT_DECLARE
	PFN_vkDestroyValidationCacheEXT destroyValidationCacheEXT = nullptr;
#endif
#ifndef PFN_vkMergeValidationCachesEXT_DECLARE
#define PFN_vkMergeValidationCachesEXT_DECLARE
	PFN_vkMergeValidationCachesEXT mergeValidationCachesEXT = nullptr;
#endif
#ifndef PFN_vkGetValidationCacheDataEXT_DECLARE
#define PFN_vkGetValidationCacheDataEXT_DECLARE
	PFN_vkGetValidationCacheDataEXT getValidationCacheDataEXT = nullptr;
#endif
#endif
#if defined(VK_NV_shading_rate_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindShadingRateImageNV_DECLARE
#define PFN_vkCmdBindShadingRateImageNV_DECLARE
	PFN_vkCmdBindShadingRateImageNV cmdBindShadingRateImageNV = nullptr;
#endif
#ifndef PFN_vkCmdSetViewportShadingRatePaletteNV_DECLARE
#define PFN_vkCmdSetViewportShadingRatePaletteNV_DECLARE
	PFN_vkCmdSetViewportShadingRatePaletteNV cmdSetViewportShadingRatePaletteNV = nullptr;
#endif
#ifndef PFN_vkCmdSetCoarseSampleOrderNV_DECLARE
#define PFN_vkCmdSetCoarseSampleOrderNV_DECLARE
	PFN_vkCmdSetCoarseSampleOrderNV cmdSetCoarseSampleOrderNV = nullptr;
#endif
#endif
#if defined(VK_NV_ray_tracing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureNV_DECLARE
#define PFN_vkCreateAccelerationStructureNV_DECLARE
	PFN_vkCreateAccelerationStructureNV createAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkDestroyAccelerationStructureNV_DECLARE
#define PFN_vkDestroyAccelerationStructureNV_DECLARE
	PFN_vkDestroyAccelerationStructureNV destroyAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureMemoryRequirementsNV_DECLARE
#define PFN_vkGetAccelerationStructureMemoryRequirementsNV_DECLARE
	PFN_vkGetAccelerationStructureMemoryRequirementsNV getAccelerationStructureMemoryRequirementsNV = nullptr;
#endif
#ifndef PFN_vkBindAccelerationStructureMemoryNV_DECLARE
#define PFN_vkBindAccelerationStructureMemoryNV_DECLARE
	PFN_vkBindAccelerationStructureMemoryNV bindAccelerationStructureMemoryNV = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructureNV_DECLARE
#define PFN_vkCmdBuildAccelerationStructureNV_DECLARE
	PFN_vkCmdBuildAccelerationStructureNV cmdBuildAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureNV_DECLARE
#define PFN_vkCmdCopyAccelerationStructureNV_DECLARE
	PFN_vkCmdCopyAccelerationStructureNV cmdCopyAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkCmdTraceRaysNV_DECLARE
#define PFN_vkCmdTraceRaysNV_DECLARE
	PFN_vkCmdTraceRaysNV cmdTraceRaysNV = nullptr;
#endif
#ifndef PFN_vkCreateRayTracingPipelinesNV_DECLARE
#define PFN_vkCreateRayTracingPipelinesNV_DECLARE
	PFN_vkCreateRayTracingPipelinesNV createRayTracingPipelinesNV = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesNV_DECLARE
#define PFN_vkGetRayTracingShaderGroupHandlesNV_DECLARE
	PFN_vkGetRayTracingShaderGroupHandlesNV getRayTracingShaderGroupHandlesNV = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureHandleNV_DECLARE
#define PFN_vkGetAccelerationStructureHandleNV_DECLARE
	PFN_vkGetAccelerationStructureHandleNV getAccelerationStructureHandleNV = nullptr;
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesNV_DECLARE
#define PFN_vkCmdWriteAccelerationStructuresPropertiesNV_DECLARE
	PFN_vkCmdWriteAccelerationStructuresPropertiesNV cmdWriteAccelerationStructuresPropertiesNV = nullptr;
#endif
#ifndef PFN_vkCompileDeferredNV_DECLARE
#define PFN_vkCompileDeferredNV_DECLARE
	PFN_vkCompileDeferredNV compileDeferredNV = nullptr;
#endif
#endif
#if defined(VK_KHR_maintenance3) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDescriptorSetLayoutSupportKHR_DECLARE
#define PFN_vkGetDescriptorSetLayoutSupportKHR_DECLARE
	PFN_vkGetDescriptorSetLayoutSupportKHR getDescriptorSetLayoutSupportKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_external_memory_host) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryHostPointerPropertiesEXT_DECLARE
#define PFN_vkGetMemoryHostPointerPropertiesEXT_DECLARE
	PFN_vkGetMemoryHostPointerPropertiesEXT getMemoryHostPointerPropertiesEXT = nullptr;
#endif
#endif
#if defined(VK_AMD_buffer_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdWriteBufferMarkerAMD_DECLARE
#define PFN_vkCmdWriteBufferMarkerAMD_DECLARE
	PFN_vkCmdWriteBufferMarkerAMD cmdWriteBufferMarkerAMD = nullptr;
#endif
#endif
#if defined(VK_EXT_calibrated_timestamps) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetCalibratedTimestampsEXT_DECLARE
#define PFN_vkGetCalibratedTimestampsEXT_DECLARE
	PFN_vkGetCalibratedTimestampsEXT getCalibratedTimestampsEXT = nullptr;
#endif
#endif
#if defined(VK_NV_mesh_shader) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawMeshTasksNV_DECLARE
#define PFN_vkCmdDrawMeshTasksNV_DECLARE
	PFN_vkCmdDrawMeshTasksNV cmdDrawMeshTasksNV = nullptr;
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectNV_DECLARE
#define PFN_vkCmdDrawMeshTasksIndirectNV_DECLARE
	PFN_vkCmdDrawMeshTasksIndirectNV cmdDrawMeshTasksIndirectNV = nullptr;
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectCountNV_DECLARE
#define PFN_vkCmdDrawMeshTasksIndirectCountNV_DECLARE
	PFN_vkCmdDrawMeshTasksIndirectCountNV cmdDrawMeshTasksIndirectCountNV = nullptr;
#endif
#endif
#if defined(VK_NV_scissor_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetExclusiveScissorNV_DECLARE
#define PFN_vkCmdSetExclusiveScissorNV_DECLARE
	PFN_vkCmdSetExclusiveScissorNV cmdSetExclusiveScissorNV = nullptr;
#endif
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCheckpointNV_DECLARE
#define PFN_vkCmdSetCheckpointNV_DECLARE
	PFN_vkCmdSetCheckpointNV cmdSetCheckpointNV = nullptr;
#endif
#ifndef PFN_vkGetQueueCheckpointDataNV_DECLARE
#define PFN_vkGetQueueCheckpointDataNV_DECLARE
	PFN_vkGetQueueCheckpointDataNV getQueueCheckpointDataNV = nullptr;
#endif
#endif
#if defined(VK_KHR_timeline_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSemaphoreCounterValueKHR_DECLARE
#define PFN_vkGetSemaphoreCounterValueKHR_DECLARE
	PFN_vkGetSemaphoreCounterValueKHR getSemaphoreCounterValueKHR = nullptr;
#endif
#ifndef PFN_vkWaitSemaphoresKHR_DECLARE
#define PFN_vkWaitSemaphoresKHR_DECLARE
	PFN_vkWaitSemaphoresKHR waitSemaphoresKHR = nullptr;
#endif
#ifndef PFN_vkSignalSemaphoreKHR_DECLARE
#define PFN_vkSignalSemaphoreKHR_DECLARE
	PFN_vkSignalSemaphoreKHR signalSemaphoreKHR = nullptr;
#endif
#endif
#if defined(VK_INTEL_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkInitializePerformanceApiINTEL_DECLARE
#define PFN_vkInitializePerformanceApiINTEL_DECLARE
	PFN_vkInitializePerformanceApiINTEL initializePerformanceApiINTEL = nullptr;
#endif
#ifndef PFN_vkUninitializePerformanceApiINTEL_DECLARE
#define PFN_vkUninitializePerformanceApiINTEL_DECLARE
	PFN_vkUninitializePerformanceApiINTEL uninitializePerformanceApiINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceMarkerINTEL_DECLARE
#define PFN_vkCmdSetPerformanceMarkerINTEL_DECLARE
	PFN_vkCmdSetPerformanceMarkerINTEL cmdSetPerformanceMarkerINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceStreamMarkerINTEL_DECLARE
#define PFN_vkCmdSetPerformanceStreamMarkerINTEL_DECLARE
	PFN_vkCmdSetPerformanceStreamMarkerINTEL cmdSetPerformanceStreamMarkerINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceOverrideINTEL_DECLARE
#define PFN_vkCmdSetPerformanceOverrideINTEL_DECLARE
	PFN_vkCmdSetPerformanceOverrideINTEL cmdSetPerformanceOverrideINTEL = nullptr;
#endif
#ifndef PFN_vkAcquirePerformanceConfigurationINTEL_DECLARE
#define PFN_vkAcquirePerformanceConfigurationINTEL_DECLARE
	PFN_vkAcquirePerformanceConfigurationINTEL acquirePerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkReleasePerformanceConfigurationINTEL_DECLARE
#define PFN_vkReleasePerformanceConfigurationINTEL_DECLARE
	PFN_vkReleasePerformanceConfigurationINTEL releasePerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkQueueSetPerformanceConfigurationINTEL_DECLARE
#define PFN_vkQueueSetPerformanceConfigurationINTEL_DECLARE
	PFN_vkQueueSetPerformanceConfigurationINTEL queueSetPerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkGetPerformanceParameterINTEL_DECLARE
#define PFN_vkGetPerformanceParameterINTEL_DECLARE
	PFN_vkGetPerformanceParameterINTEL getPerformanceParameterINTEL = nullptr;
#endif
#endif
#if defined(VK_AMD_display_native_hdr) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetLocalDimmingAMD_DECLARE
#define PFN_vkSetLocalDimmingAMD_DECLARE
	PFN_vkSetLocalDimmingAMD setLocalDimmingAMD = nullptr;
#endif
#endif
#if defined(VK_KHR_fragment_shading_rate) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateKHR_DECLARE
#define PFN_vkCmdSetFragmentShadingRateKHR_DECLARE
	PFN_vkCmdSetFragmentShadingRateKHR cmdSetFragmentShadingRateKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferDeviceAddressEXT_DECLARE
#define PFN_vkGetBufferDeviceAddressEXT_DECLARE
	PFN_vkGetBufferDeviceAddressEXT getBufferDeviceAddressEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireFullScreenExclusiveModeEXT_DECLARE
#define PFN_vkAcquireFullScreenExclusiveModeEXT_DECLARE
	PFN_vkAcquireFullScreenExclusiveModeEXT acquireFullScreenExclusiveModeEXT = nullptr;
#endif
#ifndef PFN_vkReleaseFullScreenExclusiveModeEXT_DECLARE
#define PFN_vkReleaseFullScreenExclusiveModeEXT_DECLARE
	PFN_vkReleaseFullScreenExclusiveModeEXT releaseFullScreenExclusiveModeEXT = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModes2EXT getDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModes2EXT getDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif
#endif
#if defined(VK_KHR_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferOpaqueCaptureAddressKHR_DECLARE
#define PFN_vkGetBufferOpaqueCaptureAddressKHR_DECLARE
	PFN_vkGetBufferOpaqueCaptureAddressKHR getBufferOpaqueCaptureAddressKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_DECLARE
#define PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_DECLARE
	PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR getDeviceMemoryOpaqueCaptureAddressKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_line_rasterization) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetLineStippleEXT_DECLARE
#define PFN_vkCmdSetLineStippleEXT_DECLARE
	PFN_vkCmdSetLineStippleEXT cmdSetLineStippleEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_host_query_reset) && defined(VK_VERSION_1_0)
#ifndef PFN_vkResetQueryPoolEXT_DECLARE
#define PFN_vkResetQueryPoolEXT_DECLARE
	PFN_vkResetQueryPoolEXT resetQueryPoolEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCullModeEXT_DECLARE
#define PFN_vkCmdSetCullModeEXT_DECLARE
	PFN_vkCmdSetCullModeEXT cmdSetCullModeEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetFrontFaceEXT_DECLARE
#define PFN_vkCmdSetFrontFaceEXT_DECLARE
	PFN_vkCmdSetFrontFaceEXT cmdSetFrontFaceEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetPrimitiveTopologyEXT_DECLARE
#define PFN_vkCmdSetPrimitiveTopologyEXT_DECLARE
	PFN_vkCmdSetPrimitiveTopologyEXT cmdSetPrimitiveTopologyEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetViewportWithCountEXT_DECLARE
#define PFN_vkCmdSetViewportWithCountEXT_DECLARE
	PFN_vkCmdSetViewportWithCountEXT cmdSetViewportWithCountEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetScissorWithCountEXT_DECLARE
#define PFN_vkCmdSetScissorWithCountEXT_DECLARE
	PFN_vkCmdSetScissorWithCountEXT cmdSetScissorWithCountEXT = nullptr;
#endif
#ifndef PFN_vkCmdBindVertexBuffers2EXT_DECLARE
#define PFN_vkCmdBindVertexBuffers2EXT_DECLARE
	PFN_vkCmdBindVertexBuffers2EXT cmdBindVertexBuffers2EXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthTestEnableEXT_DECLARE
#define PFN_vkCmdSetDepthTestEnableEXT_DECLARE
	PFN_vkCmdSetDepthTestEnableEXT cmdSetDepthTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthWriteEnableEXT_DECLARE
#define PFN_vkCmdSetDepthWriteEnableEXT_DECLARE
	PFN_vkCmdSetDepthWriteEnableEXT cmdSetDepthWriteEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthCompareOpEXT_DECLARE
#define PFN_vkCmdSetDepthCompareOpEXT_DECLARE
	PFN_vkCmdSetDepthCompareOpEXT cmdSetDepthCompareOpEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthBoundsTestEnableEXT_DECLARE
#define PFN_vkCmdSetDepthBoundsTestEnableEXT_DECLARE
	PFN_vkCmdSetDepthBoundsTestEnableEXT cmdSetDepthBoundsTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetStencilTestEnableEXT_DECLARE
#define PFN_vkCmdSetStencilTestEnableEXT_DECLARE
	PFN_vkCmdSetStencilTestEnableEXT cmdSetStencilTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetStencilOpEXT_DECLARE
#define PFN_vkCmdSetStencilOpEXT_DECLARE
	PFN_vkCmdSetStencilOpEXT cmdSetStencilOpEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_deferred_host_operations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDeferredOperationKHR_DECLARE
#define PFN_vkCreateDeferredOperationKHR_DECLARE
	PFN_vkCreateDeferredOperationKHR createDeferredOperationKHR = nullptr;
#endif
#ifndef PFN_vkDestroyDeferredOperationKHR_DECLARE
#define PFN_vkDestroyDeferredOperationKHR_DECLARE
	PFN_vkDestroyDeferredOperationKHR destroyDeferredOperationKHR = nullptr;
#endif
#ifndef PFN_vkGetDeferredOperationMaxConcurrencyKHR_DECLARE
#define PFN_vkGetDeferredOperationMaxConcurrencyKHR_DECLARE
	PFN_vkGetDeferredOperationMaxConcurrencyKHR getDeferredOperationMaxConcurrencyKHR = nullptr;
#endif
#ifndef PFN_vkGetDeferredOperationResultKHR_DECLARE
#define PFN_vkGetDeferredOperationResultKHR_DECLARE
	PFN_vkGetDeferredOperationResultKHR getDeferredOperationResultKHR = nullptr;
#endif
#ifndef PFN_vkDeferredOperationJoinKHR_DECLARE
#define PFN_vkDeferredOperationJoinKHR_DECLARE
	PFN_vkDeferredOperationJoinKHR deferredOperationJoinKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_pipeline_executable_properties) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetPipelineExecutablePropertiesKHR_DECLARE
#define PFN_vkGetPipelineExecutablePropertiesKHR_DECLARE
	PFN_vkGetPipelineExecutablePropertiesKHR getPipelineExecutablePropertiesKHR = nullptr;
#endif
#ifndef PFN_vkGetPipelineExecutableStatisticsKHR_DECLARE
#define PFN_vkGetPipelineExecutableStatisticsKHR_DECLARE
	PFN_vkGetPipelineExecutableStatisticsKHR getPipelineExecutableStatisticsKHR = nullptr;
#endif
#ifndef PFN_vkGetPipelineExecutableInternalRepresentationsKHR_DECLARE
#define PFN_vkGetPipelineExecutableInternalRepresentationsKHR_DECLARE
	PFN_vkGetPipelineExecutableInternalRepresentationsKHR getPipelineExecutableInternalRepresentationsKHR = nullptr;
#endif
#endif
#if defined(VK_NV_device_generated_commands) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetGeneratedCommandsMemoryRequirementsNV_DECLARE
#define PFN_vkGetGeneratedCommandsMemoryRequirementsNV_DECLARE
	PFN_vkGetGeneratedCommandsMemoryRequirementsNV getGeneratedCommandsMemoryRequirementsNV = nullptr;
#endif
#ifndef PFN_vkCmdPreprocessGeneratedCommandsNV_DECLARE
#define PFN_vkCmdPreprocessGeneratedCommandsNV_DECLARE
	PFN_vkCmdPreprocessGeneratedCommandsNV cmdPreprocessGeneratedCommandsNV = nullptr;
#endif
#ifndef PFN_vkCmdExecuteGeneratedCommandsNV_DECLARE
#define PFN_vkCmdExecuteGeneratedCommandsNV_DECLARE
	PFN_vkCmdExecuteGeneratedCommandsNV cmdExecuteGeneratedCommandsNV = nullptr;
#endif
#ifndef PFN_vkCmdBindPipelineShaderGroupNV_DECLARE
#define PFN_vkCmdBindPipelineShaderGroupNV_DECLARE
	PFN_vkCmdBindPipelineShaderGroupNV cmdBindPipelineShaderGroupNV = nullptr;
#endif
#ifndef PFN_vkCreateIndirectCommandsLayoutNV_DECLARE
#define PFN_vkCreateIndirectCommandsLayoutNV_DECLARE
	PFN_vkCreateIndirectCommandsLayoutNV createIndirectCommandsLayoutNV = nullptr;
#endif
#ifndef PFN_vkDestroyIndirectCommandsLayoutNV_DECLARE
#define PFN_vkDestroyIndirectCommandsLayoutNV_DECLARE
	PFN_vkDestroyIndirectCommandsLayoutNV destroyIndirectCommandsLayoutNV = nullptr;
#endif
#endif
#if defined(VK_EXT_private_data) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreatePrivateDataSlotEXT_DECLARE
#define PFN_vkCreatePrivateDataSlotEXT_DECLARE
	PFN_vkCreatePrivateDataSlotEXT createPrivateDataSlotEXT = nullptr;
#endif
#ifndef PFN_vkDestroyPrivateDataSlotEXT_DECLARE
#define PFN_vkDestroyPrivateDataSlotEXT_DECLARE
	PFN_vkDestroyPrivateDataSlotEXT destroyPrivateDataSlotEXT = nullptr;
#endif
#ifndef PFN_vkSetPrivateDataEXT_DECLARE
#define PFN_vkSetPrivateDataEXT_DECLARE
	PFN_vkSetPrivateDataEXT setPrivateDataEXT = nullptr;
#endif
#ifndef PFN_vkGetPrivateDataEXT_DECLARE
#define PFN_vkGetPrivateDataEXT_DECLARE
	PFN_vkGetPrivateDataEXT getPrivateDataEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_synchronization2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetEvent2KHR_DECLARE
#define PFN_vkCmdSetEvent2KHR_DECLARE
	PFN_vkCmdSetEvent2KHR cmdSetEvent2KHR = nullptr;
#endif
#ifndef PFN_vkCmdResetEvent2KHR_DECLARE
#define PFN_vkCmdResetEvent2KHR_DECLARE
	PFN_vkCmdResetEvent2KHR cmdResetEvent2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWaitEvents2KHR_DECLARE
#define PFN_vkCmdWaitEvents2KHR_DECLARE
	PFN_vkCmdWaitEvents2KHR cmdWaitEvents2KHR = nullptr;
#endif
#ifndef PFN_vkCmdPipelineBarrier2KHR_DECLARE
#define PFN_vkCmdPipelineBarrier2KHR_DECLARE
	PFN_vkCmdPipelineBarrier2KHR cmdPipelineBarrier2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteTimestamp2KHR_DECLARE
#define PFN_vkCmdWriteTimestamp2KHR_DECLARE
	PFN_vkCmdWriteTimestamp2KHR cmdWriteTimestamp2KHR = nullptr;
#endif
#ifndef PFN_vkQueueSubmit2KHR_DECLARE
#define PFN_vkQueueSubmit2KHR_DECLARE
	PFN_vkQueueSubmit2KHR queueSubmit2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteBufferMarker2AMD_DECLARE
#define PFN_vkCmdWriteBufferMarker2AMD_DECLARE
	PFN_vkCmdWriteBufferMarker2AMD cmdWriteBufferMarker2AMD = nullptr;
#endif
#ifndef PFN_vkGetQueueCheckpointData2NV_DECLARE
#define PFN_vkGetQueueCheckpointData2NV_DECLARE
	PFN_vkGetQueueCheckpointData2NV getQueueCheckpointData2NV = nullptr;
#endif
#endif
#if defined(VK_NV_fragment_shading_rate_enums) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateEnumNV_DECLARE
#define PFN_vkCmdSetFragmentShadingRateEnumNV_DECLARE
	PFN_vkCmdSetFragmentShadingRateEnumNV cmdSetFragmentShadingRateEnumNV = nullptr;
#endif
#endif
#if defined(VK_KHR_copy_commands2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdCopyBuffer2KHR_DECLARE
#define PFN_vkCmdCopyBuffer2KHR_DECLARE
	PFN_vkCmdCopyBuffer2KHR cmdCopyBuffer2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyImage2KHR_DECLARE
#define PFN_vkCmdCopyImage2KHR_DECLARE
	PFN_vkCmdCopyImage2KHR cmdCopyImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyBufferToImage2KHR_DECLARE
#define PFN_vkCmdCopyBufferToImage2KHR_DECLARE
	PFN_vkCmdCopyBufferToImage2KHR cmdCopyBufferToImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyImageToBuffer2KHR_DECLARE
#define PFN_vkCmdCopyImageToBuffer2KHR_DECLARE
	PFN_vkCmdCopyImageToBuffer2KHR cmdCopyImageToBuffer2KHR = nullptr;
#endif
#ifndef PFN_vkCmdBlitImage2KHR_DECLARE
#define PFN_vkCmdBlitImage2KHR_DECLARE
	PFN_vkCmdBlitImage2KHR cmdBlitImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdResolveImage2KHR_DECLARE
#define PFN_vkCmdResolveImage2KHR_DECLARE
	PFN_vkCmdResolveImage2KHR cmdResolveImage2KHR = nullptr;
#endif
#endif
#if defined(VK_EXT_vertex_input_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetVertexInputEXT_DECLARE
#define PFN_vkCmdSetVertexInputEXT_DECLARE
	PFN_vkCmdSetVertexInputEXT cmdSetVertexInputEXT = nullptr;
#endif
#endif
#if defined(VK_FUCHSIA_external_memory) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryZirconHandleFUCHSIA_DECLARE
#define PFN_vkGetMemoryZirconHandleFUCHSIA_DECLARE
	PFN_vkGetMemoryZirconHandleFUCHSIA getMemoryZirconHandleFUCHSIA = nullptr;
#endif
#ifndef PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_DECLARE
#define PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_DECLARE
	PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA getMemoryZirconHandlePropertiesFUCHSIA = nullptr;
#endif
#endif
#if defined(VK_FUCHSIA_external_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreZirconHandleFUCHSIA_DECLARE
#define PFN_vkImportSemaphoreZirconHandleFUCHSIA_DECLARE
	PFN_vkImportSemaphoreZirconHandleFUCHSIA importSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreZirconHandleFUCHSIA_DECLARE
#define PFN_vkGetSemaphoreZirconHandleFUCHSIA_DECLARE
	PFN_vkGetSemaphoreZirconHandleFUCHSIA getSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetPatchControlPointsEXT_DECLARE
#define PFN_vkCmdSetPatchControlPointsEXT_DECLARE
	PFN_vkCmdSetPatchControlPointsEXT cmdSetPatchControlPointsEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetRasterizerDiscardEnableEXT_DECLARE
#define PFN_vkCmdSetRasterizerDiscardEnableEXT_DECLARE
	PFN_vkCmdSetRasterizerDiscardEnableEXT cmdSetRasterizerDiscardEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthBiasEnableEXT_DECLARE
#define PFN_vkCmdSetDepthBiasEnableEXT_DECLARE
	PFN_vkCmdSetDepthBiasEnableEXT cmdSetDepthBiasEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetLogicOpEXT_DECLARE
#define PFN_vkCmdSetLogicOpEXT_DECLARE
	PFN_vkCmdSetLogicOpEXT cmdSetLogicOpEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetPrimitiveRestartEnableEXT_DECLARE
#define PFN_vkCmdSetPrimitiveRestartEnableEXT_DECLARE
	PFN_vkCmdSetPrimitiveRestartEnableEXT cmdSetPrimitiveRestartEnableEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_color_write_enable) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetColorWriteEnableEXT_DECLARE
#define PFN_vkCmdSetColorWriteEnableEXT_DECLARE
	PFN_vkCmdSetColorWriteEnableEXT cmdSetColorWriteEnableEXT = nullptr;
#endif
#endif
};

} // namespace vkb