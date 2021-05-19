/* 
 * Copyright © 2021 Cody Goodson (contact@vibimanx.com)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the “Software”), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

// This file is a part of VkBootstrap
// https://github.com/charles-lunarg/vk-bootstrap


#pragma once

#include <vulkan/vulkan.h>

namespace vkb {

struct DispatchTable {
	DispatchTable() = default;
	DispatchTable(VkDevice const& device, PFN_vkGetDeviceProcAddr const& procAddr) : device(device) {
#ifdef VK_VERSION_1_0
		fp_vkGetDeviceQueue = (PFN_vkGetDeviceQueue)procAddr(device, "vkGetDeviceQueue");
		fp_vkQueueSubmit = (PFN_vkQueueSubmit)procAddr(device, "vkQueueSubmit");
		fp_vkQueueWaitIdle = (PFN_vkQueueWaitIdle)procAddr(device, "vkQueueWaitIdle");
		fp_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)procAddr(device, "vkDeviceWaitIdle");
		fp_vkAllocateMemory = (PFN_vkAllocateMemory)procAddr(device, "vkAllocateMemory");
		fp_vkFreeMemory = (PFN_vkFreeMemory)procAddr(device, "vkFreeMemory");
		fp_vkMapMemory = (PFN_vkMapMemory)procAddr(device, "vkMapMemory");
		fp_vkUnmapMemory = (PFN_vkUnmapMemory)procAddr(device, "vkUnmapMemory");
		fp_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)procAddr(device, "vkFlushMappedMemoryRanges");
		fp_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)procAddr(device, "vkInvalidateMappedMemoryRanges");
		fp_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)procAddr(device, "vkGetDeviceMemoryCommitment");
		fp_vkBindBufferMemory = (PFN_vkBindBufferMemory)procAddr(device, "vkBindBufferMemory");
		fp_vkBindImageMemory = (PFN_vkBindImageMemory)procAddr(device, "vkBindImageMemory");
		fp_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)procAddr(device, "vkGetBufferMemoryRequirements");
		fp_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)procAddr(device, "vkGetImageMemoryRequirements");
		fp_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)procAddr(device, "vkGetImageSparseMemoryRequirements");
		fp_vkQueueBindSparse = (PFN_vkQueueBindSparse)procAddr(device, "vkQueueBindSparse");
		fp_vkCreateFence = (PFN_vkCreateFence)procAddr(device, "vkCreateFence");
		fp_vkDestroyFence = (PFN_vkDestroyFence)procAddr(device, "vkDestroyFence");
		fp_vkResetFences = (PFN_vkResetFences)procAddr(device, "vkResetFences");
		fp_vkGetFenceStatus = (PFN_vkGetFenceStatus)procAddr(device, "vkGetFenceStatus");
		fp_vkWaitForFences = (PFN_vkWaitForFences)procAddr(device, "vkWaitForFences");
		fp_vkCreateSemaphore = (PFN_vkCreateSemaphore)procAddr(device, "vkCreateSemaphore");
		fp_vkDestroySemaphore = (PFN_vkDestroySemaphore)procAddr(device, "vkDestroySemaphore");
		fp_vkCreateEvent = (PFN_vkCreateEvent)procAddr(device, "vkCreateEvent");
		fp_vkDestroyEvent = (PFN_vkDestroyEvent)procAddr(device, "vkDestroyEvent");
		fp_vkGetEventStatus = (PFN_vkGetEventStatus)procAddr(device, "vkGetEventStatus");
		fp_vkSetEvent = (PFN_vkSetEvent)procAddr(device, "vkSetEvent");
		fp_vkResetEvent = (PFN_vkResetEvent)procAddr(device, "vkResetEvent");
		fp_vkCreateQueryPool = (PFN_vkCreateQueryPool)procAddr(device, "vkCreateQueryPool");
		fp_vkDestroyQueryPool = (PFN_vkDestroyQueryPool)procAddr(device, "vkDestroyQueryPool");
		fp_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)procAddr(device, "vkGetQueryPoolResults");
		fp_vkCreateBuffer = (PFN_vkCreateBuffer)procAddr(device, "vkCreateBuffer");
		fp_vkDestroyBuffer = (PFN_vkDestroyBuffer)procAddr(device, "vkDestroyBuffer");
		fp_vkCreateBufferView = (PFN_vkCreateBufferView)procAddr(device, "vkCreateBufferView");
		fp_vkDestroyBufferView = (PFN_vkDestroyBufferView)procAddr(device, "vkDestroyBufferView");
		fp_vkCreateImage = (PFN_vkCreateImage)procAddr(device, "vkCreateImage");
		fp_vkDestroyImage = (PFN_vkDestroyImage)procAddr(device, "vkDestroyImage");
		fp_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)procAddr(device, "vkGetImageSubresourceLayout");
		fp_vkCreateImageView = (PFN_vkCreateImageView)procAddr(device, "vkCreateImageView");
		fp_vkDestroyImageView = (PFN_vkDestroyImageView)procAddr(device, "vkDestroyImageView");
		fp_vkCreateShaderModule = (PFN_vkCreateShaderModule)procAddr(device, "vkCreateShaderModule");
		fp_vkDestroyShaderModule = (PFN_vkDestroyShaderModule)procAddr(device, "vkDestroyShaderModule");
		fp_vkCreatePipelineCache = (PFN_vkCreatePipelineCache)procAddr(device, "vkCreatePipelineCache");
		fp_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)procAddr(device, "vkDestroyPipelineCache");
		fp_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)procAddr(device, "vkGetPipelineCacheData");
		fp_vkMergePipelineCaches = (PFN_vkMergePipelineCaches)procAddr(device, "vkMergePipelineCaches");
		fp_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)procAddr(device, "vkCreateGraphicsPipelines");
		fp_vkCreateComputePipelines = (PFN_vkCreateComputePipelines)procAddr(device, "vkCreateComputePipelines");
		fp_vkDestroyPipeline = (PFN_vkDestroyPipeline)procAddr(device, "vkDestroyPipeline");
		fp_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)procAddr(device, "vkCreatePipelineLayout");
		fp_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)procAddr(device, "vkDestroyPipelineLayout");
		fp_vkCreateSampler = (PFN_vkCreateSampler)procAddr(device, "vkCreateSampler");
		fp_vkDestroySampler = (PFN_vkDestroySampler)procAddr(device, "vkDestroySampler");
		fp_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)procAddr(device, "vkCreateDescriptorSetLayout");
		fp_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)procAddr(device, "vkDestroyDescriptorSetLayout");
		fp_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)procAddr(device, "vkCreateDescriptorPool");
		fp_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)procAddr(device, "vkDestroyDescriptorPool");
		fp_vkResetDescriptorPool = (PFN_vkResetDescriptorPool)procAddr(device, "vkResetDescriptorPool");
		fp_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)procAddr(device, "vkAllocateDescriptorSets");
		fp_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)procAddr(device, "vkFreeDescriptorSets");
		fp_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)procAddr(device, "vkUpdateDescriptorSets");
		fp_vkCreateFramebuffer = (PFN_vkCreateFramebuffer)procAddr(device, "vkCreateFramebuffer");
		fp_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)procAddr(device, "vkDestroyFramebuffer");
		fp_vkCreateRenderPass = (PFN_vkCreateRenderPass)procAddr(device, "vkCreateRenderPass");
		fp_vkDestroyRenderPass = (PFN_vkDestroyRenderPass)procAddr(device, "vkDestroyRenderPass");
		fp_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)procAddr(device, "vkGetRenderAreaGranularity");
		fp_vkCreateCommandPool = (PFN_vkCreateCommandPool)procAddr(device, "vkCreateCommandPool");
		fp_vkDestroyCommandPool = (PFN_vkDestroyCommandPool)procAddr(device, "vkDestroyCommandPool");
		fp_vkResetCommandPool = (PFN_vkResetCommandPool)procAddr(device, "vkResetCommandPool");
		fp_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)procAddr(device, "vkAllocateCommandBuffers");
		fp_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)procAddr(device, "vkFreeCommandBuffers");
		fp_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)procAddr(device, "vkBeginCommandBuffer");
		fp_vkEndCommandBuffer = (PFN_vkEndCommandBuffer)procAddr(device, "vkEndCommandBuffer");
		fp_vkResetCommandBuffer = (PFN_vkResetCommandBuffer)procAddr(device, "vkResetCommandBuffer");
		fp_vkCmdBindPipeline = (PFN_vkCmdBindPipeline)procAddr(device, "vkCmdBindPipeline");
		fp_vkCmdSetViewport = (PFN_vkCmdSetViewport)procAddr(device, "vkCmdSetViewport");
		fp_vkCmdSetScissor = (PFN_vkCmdSetScissor)procAddr(device, "vkCmdSetScissor");
		fp_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)procAddr(device, "vkCmdSetLineWidth");
		fp_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)procAddr(device, "vkCmdSetDepthBias");
		fp_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)procAddr(device, "vkCmdSetBlendConstants");
		fp_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)procAddr(device, "vkCmdSetDepthBounds");
		fp_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)procAddr(device, "vkCmdSetStencilCompareMask");
		fp_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)procAddr(device, "vkCmdSetStencilWriteMask");
		fp_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)procAddr(device, "vkCmdSetStencilReference");
		fp_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)procAddr(device, "vkCmdBindDescriptorSets");
		fp_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)procAddr(device, "vkCmdBindIndexBuffer");
		fp_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)procAddr(device, "vkCmdBindVertexBuffers");
		fp_vkCmdDraw = (PFN_vkCmdDraw)procAddr(device, "vkCmdDraw");
		fp_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)procAddr(device, "vkCmdDrawIndexed");
		fp_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)procAddr(device, "vkCmdDrawIndirect");
		fp_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)procAddr(device, "vkCmdDrawIndexedIndirect");
		fp_vkCmdDispatch = (PFN_vkCmdDispatch)procAddr(device, "vkCmdDispatch");
		fp_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)procAddr(device, "vkCmdDispatchIndirect");
		fp_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)procAddr(device, "vkCmdCopyBuffer");
		fp_vkCmdCopyImage = (PFN_vkCmdCopyImage)procAddr(device, "vkCmdCopyImage");
		fp_vkCmdBlitImage = (PFN_vkCmdBlitImage)procAddr(device, "vkCmdBlitImage");
		fp_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)procAddr(device, "vkCmdCopyBufferToImage");
		fp_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)procAddr(device, "vkCmdCopyImageToBuffer");
		fp_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)procAddr(device, "vkCmdUpdateBuffer");
		fp_vkCmdFillBuffer = (PFN_vkCmdFillBuffer)procAddr(device, "vkCmdFillBuffer");
		fp_vkCmdClearColorImage = (PFN_vkCmdClearColorImage)procAddr(device, "vkCmdClearColorImage");
		fp_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)procAddr(device, "vkCmdClearDepthStencilImage");
		fp_vkCmdClearAttachments = (PFN_vkCmdClearAttachments)procAddr(device, "vkCmdClearAttachments");
		fp_vkCmdResolveImage = (PFN_vkCmdResolveImage)procAddr(device, "vkCmdResolveImage");
		fp_vkCmdSetEvent = (PFN_vkCmdSetEvent)procAddr(device, "vkCmdSetEvent");
		fp_vkCmdResetEvent = (PFN_vkCmdResetEvent)procAddr(device, "vkCmdResetEvent");
		fp_vkCmdWaitEvents = (PFN_vkCmdWaitEvents)procAddr(device, "vkCmdWaitEvents");
		fp_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)procAddr(device, "vkCmdPipelineBarrier");
		fp_vkCmdBeginQuery = (PFN_vkCmdBeginQuery)procAddr(device, "vkCmdBeginQuery");
		fp_vkCmdEndQuery = (PFN_vkCmdEndQuery)procAddr(device, "vkCmdEndQuery");
		fp_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)procAddr(device, "vkCmdResetQueryPool");
		fp_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)procAddr(device, "vkCmdWriteTimestamp");
		fp_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)procAddr(device, "vkCmdCopyQueryPoolResults");
		fp_vkCmdPushConstants = (PFN_vkCmdPushConstants)procAddr(device, "vkCmdPushConstants");
		fp_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)procAddr(device, "vkCmdBeginRenderPass");
		fp_vkCmdNextSubpass = (PFN_vkCmdNextSubpass)procAddr(device, "vkCmdNextSubpass");
		fp_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)procAddr(device, "vkCmdEndRenderPass");
		fp_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)procAddr(device, "vkCmdExecuteCommands");
#endif
#ifdef VK_VERSION_1_1
		fp_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)procAddr(device, "vkBindBufferMemory2");
		fp_vkBindImageMemory2 = (PFN_vkBindImageMemory2)procAddr(device, "vkBindImageMemory2");
		fp_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)procAddr(device, "vkGetDeviceGroupPeerMemoryFeatures");
		fp_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)procAddr(device, "vkCmdSetDeviceMask");
		fp_vkCmdDispatchBase = (PFN_vkCmdDispatchBase)procAddr(device, "vkCmdDispatchBase");
		fp_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)procAddr(device, "vkGetImageMemoryRequirements2");
		fp_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)procAddr(device, "vkGetBufferMemoryRequirements2");
		fp_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)procAddr(device, "vkGetImageSparseMemoryRequirements2");
		fp_vkTrimCommandPool = (PFN_vkTrimCommandPool)procAddr(device, "vkTrimCommandPool");
		fp_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)procAddr(device, "vkGetDeviceQueue2");
		fp_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)procAddr(device, "vkCreateSamplerYcbcrConversion");
		fp_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)procAddr(device, "vkDestroySamplerYcbcrConversion");
		fp_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)procAddr(device, "vkCreateDescriptorUpdateTemplate");
		fp_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)procAddr(device, "vkDestroyDescriptorUpdateTemplate");
		fp_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)procAddr(device, "vkUpdateDescriptorSetWithTemplate");
		fp_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)procAddr(device, "vkGetDescriptorSetLayoutSupport");
#endif
#ifdef VK_VERSION_1_2
		fp_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)procAddr(device, "vkCmdDrawIndirectCount");
		fp_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)procAddr(device, "vkCmdDrawIndexedIndirectCount");
		fp_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)procAddr(device, "vkCreateRenderPass2");
		fp_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)procAddr(device, "vkCmdBeginRenderPass2");
		fp_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)procAddr(device, "vkCmdNextSubpass2");
		fp_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)procAddr(device, "vkCmdEndRenderPass2");
		fp_vkResetQueryPool = (PFN_vkResetQueryPool)procAddr(device, "vkResetQueryPool");
		fp_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)procAddr(device, "vkGetSemaphoreCounterValue");
		fp_vkWaitSemaphores = (PFN_vkWaitSemaphores)procAddr(device, "vkWaitSemaphores");
		fp_vkSignalSemaphore = (PFN_vkSignalSemaphore)procAddr(device, "vkSignalSemaphore");
		fp_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)procAddr(device, "vkGetBufferDeviceAddress");
		fp_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)procAddr(device, "vkGetBufferOpaqueCaptureAddress");
		fp_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSwapchainKHR_LOAD
#define PFN_vkCreateSwapchainKHR_LOAD
		fp_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)procAddr(device, "vkCreateSwapchainKHR");
#endif
#ifndef PFN_vkDestroySwapchainKHR_LOAD
#define PFN_vkDestroySwapchainKHR_LOAD
		fp_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)procAddr(device, "vkDestroySwapchainKHR");
#endif
#ifndef PFN_vkGetSwapchainImagesKHR_LOAD
#define PFN_vkGetSwapchainImagesKHR_LOAD
		fp_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)procAddr(device, "vkGetSwapchainImagesKHR");
#endif
#ifndef PFN_vkAcquireNextImageKHR_LOAD
#define PFN_vkAcquireNextImageKHR_LOAD
		fp_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)procAddr(device, "vkAcquireNextImageKHR");
#endif
#ifndef PFN_vkQueuePresentKHR_LOAD
#define PFN_vkQueuePresentKHR_LOAD
		fp_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)procAddr(device, "vkQueuePresentKHR");
#endif
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
		fp_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)procAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
		fp_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)procAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif
#ifndef PFN_vkAcquireNextImage2KHR_LOAD
#define PFN_vkAcquireNextImage2KHR_LOAD
		fp_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)procAddr(device, "vkAcquireNextImage2KHR");
#endif
#endif
#if defined(VK_KHR_display_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSharedSwapchainsKHR_LOAD
#define PFN_vkCreateSharedSwapchainsKHR_LOAD
		fp_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)procAddr(device, "vkCreateSharedSwapchainsKHR");
#endif
#endif
#if defined(VK_ANDROID_native_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainGrallocUsageANDROID_LOAD
#define PFN_vkGetSwapchainGrallocUsageANDROID_LOAD
		fp_vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)procAddr(device, "vkGetSwapchainGrallocUsageANDROID");
#endif
#ifndef PFN_vkAcquireImageANDROID_LOAD
#define PFN_vkAcquireImageANDROID_LOAD
		fp_vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID)procAddr(device, "vkAcquireImageANDROID");
#endif
#ifndef PFN_vkQueueSignalReleaseImageANDROID_LOAD
#define PFN_vkQueueSignalReleaseImageANDROID_LOAD
		fp_vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)procAddr(device, "vkQueueSignalReleaseImageANDROID");
#endif
#ifndef PFN_vkGetSwapchainGrallocUsage2ANDROID_LOAD
#define PFN_vkGetSwapchainGrallocUsage2ANDROID_LOAD
		fp_vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)procAddr(device, "vkGetSwapchainGrallocUsage2ANDROID");
#endif
#endif
#if defined(VK_EXT_debug_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDebugMarkerSetObjectTagEXT_LOAD
#define PFN_vkDebugMarkerSetObjectTagEXT_LOAD
		fp_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)procAddr(device, "vkDebugMarkerSetObjectTagEXT");
#endif
#ifndef PFN_vkDebugMarkerSetObjectNameEXT_LOAD
#define PFN_vkDebugMarkerSetObjectNameEXT_LOAD
		fp_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)procAddr(device, "vkDebugMarkerSetObjectNameEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerBeginEXT_LOAD
#define PFN_vkCmdDebugMarkerBeginEXT_LOAD
		fp_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)procAddr(device, "vkCmdDebugMarkerBeginEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerEndEXT_LOAD
#define PFN_vkCmdDebugMarkerEndEXT_LOAD
		fp_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)procAddr(device, "vkCmdDebugMarkerEndEXT");
#endif
#ifndef PFN_vkCmdDebugMarkerInsertEXT_LOAD
#define PFN_vkCmdDebugMarkerInsertEXT_LOAD
		fp_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)procAddr(device, "vkCmdDebugMarkerInsertEXT");
#endif
#endif
#if defined(VK_KHR_video_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateVideoSessionKHR_LOAD
#define PFN_vkCreateVideoSessionKHR_LOAD
		fp_vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)procAddr(device, "vkCreateVideoSessionKHR");
#endif
#ifndef PFN_vkDestroyVideoSessionKHR_LOAD
#define PFN_vkDestroyVideoSessionKHR_LOAD
		fp_vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)procAddr(device, "vkDestroyVideoSessionKHR");
#endif
#ifndef PFN_vkGetVideoSessionMemoryRequirementsKHR_LOAD
#define PFN_vkGetVideoSessionMemoryRequirementsKHR_LOAD
		fp_vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)procAddr(device, "vkGetVideoSessionMemoryRequirementsKHR");
#endif
#ifndef PFN_vkBindVideoSessionMemoryKHR_LOAD
#define PFN_vkBindVideoSessionMemoryKHR_LOAD
		fp_vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)procAddr(device, "vkBindVideoSessionMemoryKHR");
#endif
#ifndef PFN_vkCreateVideoSessionParametersKHR_LOAD
#define PFN_vkCreateVideoSessionParametersKHR_LOAD
		fp_vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)procAddr(device, "vkCreateVideoSessionParametersKHR");
#endif
#ifndef PFN_vkUpdateVideoSessionParametersKHR_LOAD
#define PFN_vkUpdateVideoSessionParametersKHR_LOAD
		fp_vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)procAddr(device, "vkUpdateVideoSessionParametersKHR");
#endif
#ifndef PFN_vkDestroyVideoSessionParametersKHR_LOAD
#define PFN_vkDestroyVideoSessionParametersKHR_LOAD
		fp_vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)procAddr(device, "vkDestroyVideoSessionParametersKHR");
#endif
#ifndef PFN_vkCmdBeginVideoCodingKHR_LOAD
#define PFN_vkCmdBeginVideoCodingKHR_LOAD
		fp_vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)procAddr(device, "vkCmdBeginVideoCodingKHR");
#endif
#ifndef PFN_vkCmdEndVideoCodingKHR_LOAD
#define PFN_vkCmdEndVideoCodingKHR_LOAD
		fp_vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)procAddr(device, "vkCmdEndVideoCodingKHR");
#endif
#ifndef PFN_vkCmdControlVideoCodingKHR_LOAD
#define PFN_vkCmdControlVideoCodingKHR_LOAD
		fp_vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)procAddr(device, "vkCmdControlVideoCodingKHR");
#endif
#endif
#if defined(VK_KHR_video_decode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDecodeVideoKHR_LOAD
#define PFN_vkCmdDecodeVideoKHR_LOAD
		fp_vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)procAddr(device, "vkCmdDecodeVideoKHR");
#endif
#endif
#if defined(VK_EXT_transform_feedback) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindTransformFeedbackBuffersEXT_LOAD
#define PFN_vkCmdBindTransformFeedbackBuffersEXT_LOAD
		fp_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)procAddr(device, "vkCmdBindTransformFeedbackBuffersEXT");
#endif
#ifndef PFN_vkCmdBeginTransformFeedbackEXT_LOAD
#define PFN_vkCmdBeginTransformFeedbackEXT_LOAD
		fp_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)procAddr(device, "vkCmdBeginTransformFeedbackEXT");
#endif
#ifndef PFN_vkCmdEndTransformFeedbackEXT_LOAD
#define PFN_vkCmdEndTransformFeedbackEXT_LOAD
		fp_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)procAddr(device, "vkCmdEndTransformFeedbackEXT");
#endif
#ifndef PFN_vkCmdBeginQueryIndexedEXT_LOAD
#define PFN_vkCmdBeginQueryIndexedEXT_LOAD
		fp_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)procAddr(device, "vkCmdBeginQueryIndexedEXT");
#endif
#ifndef PFN_vkCmdEndQueryIndexedEXT_LOAD
#define PFN_vkCmdEndQueryIndexedEXT_LOAD
		fp_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)procAddr(device, "vkCmdEndQueryIndexedEXT");
#endif
#ifndef PFN_vkCmdDrawIndirectByteCountEXT_LOAD
#define PFN_vkCmdDrawIndirectByteCountEXT_LOAD
		fp_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)procAddr(device, "vkCmdDrawIndirectByteCountEXT");
#endif
#endif
#if defined(VK_NVX_binary_import) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateCuModuleNVX_LOAD
#define PFN_vkCreateCuModuleNVX_LOAD
		fp_vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)procAddr(device, "vkCreateCuModuleNVX");
#endif
#ifndef PFN_vkCreateCuFunctionNVX_LOAD
#define PFN_vkCreateCuFunctionNVX_LOAD
		fp_vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)procAddr(device, "vkCreateCuFunctionNVX");
#endif
#ifndef PFN_vkDestroyCuModuleNVX_LOAD
#define PFN_vkDestroyCuModuleNVX_LOAD
		fp_vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)procAddr(device, "vkDestroyCuModuleNVX");
#endif
#ifndef PFN_vkDestroyCuFunctionNVX_LOAD
#define PFN_vkDestroyCuFunctionNVX_LOAD
		fp_vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)procAddr(device, "vkDestroyCuFunctionNVX");
#endif
#ifndef PFN_vkCmdCuLaunchKernelNVX_LOAD
#define PFN_vkCmdCuLaunchKernelNVX_LOAD
		fp_vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)procAddr(device, "vkCmdCuLaunchKernelNVX");
#endif
#endif
#if defined(VK_NVX_image_view_handle) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageViewHandleNVX_LOAD
#define PFN_vkGetImageViewHandleNVX_LOAD
		fp_vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)procAddr(device, "vkGetImageViewHandleNVX");
#endif
#ifndef PFN_vkGetImageViewAddressNVX_LOAD
#define PFN_vkGetImageViewAddressNVX_LOAD
		fp_vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)procAddr(device, "vkGetImageViewAddressNVX");
#endif
#endif
#if defined(VK_AMD_draw_indirect_count) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawIndirectCountAMD_LOAD
#define PFN_vkCmdDrawIndirectCountAMD_LOAD
		fp_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)procAddr(device, "vkCmdDrawIndirectCountAMD");
#endif
#ifndef PFN_vkCmdDrawIndexedIndirectCountAMD_LOAD
#define PFN_vkCmdDrawIndexedIndirectCountAMD_LOAD
		fp_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)procAddr(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif
#endif
#if defined(VK_AMD_shader_info) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetShaderInfoAMD_LOAD
#define PFN_vkGetShaderInfoAMD_LOAD
		fp_vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)procAddr(device, "vkGetShaderInfoAMD");
#endif
#endif
#if defined(VK_NV_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleNV_LOAD
#define PFN_vkGetMemoryWin32HandleNV_LOAD
		fp_vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)procAddr(device, "vkGetMemoryWin32HandleNV");
#endif
#endif
#if defined(VK_KHR_device_group) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_LOAD
#define PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_LOAD
		fp_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)procAddr(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif
#ifndef PFN_vkCmdSetDeviceMaskKHR_LOAD
#define PFN_vkCmdSetDeviceMaskKHR_LOAD
		fp_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)procAddr(device, "vkCmdSetDeviceMaskKHR");
#endif
#ifndef PFN_vkCmdDispatchBaseKHR_LOAD
#define PFN_vkCmdDispatchBaseKHR_LOAD
		fp_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)procAddr(device, "vkCmdDispatchBaseKHR");
#endif
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_LOAD
		fp_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)procAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_LOAD
		fp_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)procAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif
#ifndef PFN_vkAcquireNextImage2KHR_LOAD
#define PFN_vkAcquireNextImage2KHR_LOAD
		fp_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)procAddr(device, "vkAcquireNextImage2KHR");
#endif
#endif
#if defined(VK_KHR_maintenance1) && defined(VK_VERSION_1_0)
#ifndef PFN_vkTrimCommandPoolKHR_LOAD
#define PFN_vkTrimCommandPoolKHR_LOAD
		fp_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)procAddr(device, "vkTrimCommandPoolKHR");
#endif
#endif
#if defined(VK_KHR_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleKHR_LOAD
#define PFN_vkGetMemoryWin32HandleKHR_LOAD
		fp_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)procAddr(device, "vkGetMemoryWin32HandleKHR");
#endif
#ifndef PFN_vkGetMemoryWin32HandlePropertiesKHR_LOAD
#define PFN_vkGetMemoryWin32HandlePropertiesKHR_LOAD
		fp_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)procAddr(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif
#endif
#if defined(VK_KHR_external_memory_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryFdKHR_LOAD
#define PFN_vkGetMemoryFdKHR_LOAD
		fp_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)procAddr(device, "vkGetMemoryFdKHR");
#endif
#ifndef PFN_vkGetMemoryFdPropertiesKHR_LOAD
#define PFN_vkGetMemoryFdPropertiesKHR_LOAD
		fp_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)procAddr(device, "vkGetMemoryFdPropertiesKHR");
#endif
#endif
#if defined(VK_KHR_external_semaphore_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreWin32HandleKHR_LOAD
#define PFN_vkImportSemaphoreWin32HandleKHR_LOAD
		fp_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)procAddr(device, "vkImportSemaphoreWin32HandleKHR");
#endif
#ifndef PFN_vkGetSemaphoreWin32HandleKHR_LOAD
#define PFN_vkGetSemaphoreWin32HandleKHR_LOAD
		fp_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)procAddr(device, "vkGetSemaphoreWin32HandleKHR");
#endif
#endif
#if defined(VK_KHR_external_semaphore_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreFdKHR_LOAD
#define PFN_vkImportSemaphoreFdKHR_LOAD
		fp_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)procAddr(device, "vkImportSemaphoreFdKHR");
#endif
#ifndef PFN_vkGetSemaphoreFdKHR_LOAD
#define PFN_vkGetSemaphoreFdKHR_LOAD
		fp_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)procAddr(device, "vkGetSemaphoreFdKHR");
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdPushDescriptorSetKHR_LOAD
#define PFN_vkCmdPushDescriptorSetKHR_LOAD
		fp_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)procAddr(device, "vkCmdPushDescriptorSetKHR");
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		fp_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		fp_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_EXT_conditional_rendering) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBeginConditionalRenderingEXT_LOAD
#define PFN_vkCmdBeginConditionalRenderingEXT_LOAD
		fp_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)procAddr(device, "vkCmdBeginConditionalRenderingEXT");
#endif
#ifndef PFN_vkCmdEndConditionalRenderingEXT_LOAD
#define PFN_vkCmdEndConditionalRenderingEXT_LOAD
		fp_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)procAddr(device, "vkCmdEndConditionalRenderingEXT");
#endif
#endif
#if defined(VK_KHR_descriptor_update_template) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDescriptorUpdateTemplateKHR_LOAD
#define PFN_vkCreateDescriptorUpdateTemplateKHR_LOAD
		fp_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)procAddr(device, "vkCreateDescriptorUpdateTemplateKHR");
#endif
#ifndef PFN_vkDestroyDescriptorUpdateTemplateKHR_LOAD
#define PFN_vkDestroyDescriptorUpdateTemplateKHR_LOAD
		fp_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)procAddr(device, "vkDestroyDescriptorUpdateTemplateKHR");
#endif
#ifndef PFN_vkUpdateDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkUpdateDescriptorSetWithTemplateKHR_LOAD
		fp_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)procAddr(device, "vkUpdateDescriptorSetWithTemplateKHR");
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_LOAD
		fp_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#endif
#if defined(VK_NV_clip_space_w_scaling) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetViewportWScalingNV_LOAD
#define PFN_vkCmdSetViewportWScalingNV_LOAD
		fp_vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)procAddr(device, "vkCmdSetViewportWScalingNV");
#endif
#endif
#if defined(VK_EXT_display_control) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDisplayPowerControlEXT_LOAD
#define PFN_vkDisplayPowerControlEXT_LOAD
		fp_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)procAddr(device, "vkDisplayPowerControlEXT");
#endif
#ifndef PFN_vkRegisterDeviceEventEXT_LOAD
#define PFN_vkRegisterDeviceEventEXT_LOAD
		fp_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)procAddr(device, "vkRegisterDeviceEventEXT");
#endif
#ifndef PFN_vkRegisterDisplayEventEXT_LOAD
#define PFN_vkRegisterDisplayEventEXT_LOAD
		fp_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)procAddr(device, "vkRegisterDisplayEventEXT");
#endif
#ifndef PFN_vkGetSwapchainCounterEXT_LOAD
#define PFN_vkGetSwapchainCounterEXT_LOAD
		fp_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)procAddr(device, "vkGetSwapchainCounterEXT");
#endif
#endif
#if defined(VK_GOOGLE_display_timing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetRefreshCycleDurationGOOGLE_LOAD
#define PFN_vkGetRefreshCycleDurationGOOGLE_LOAD
		fp_vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)procAddr(device, "vkGetRefreshCycleDurationGOOGLE");
#endif
#ifndef PFN_vkGetPastPresentationTimingGOOGLE_LOAD
#define PFN_vkGetPastPresentationTimingGOOGLE_LOAD
		fp_vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)procAddr(device, "vkGetPastPresentationTimingGOOGLE");
#endif
#endif
#if defined(VK_EXT_discard_rectangles) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetDiscardRectangleEXT_LOAD
#define PFN_vkCmdSetDiscardRectangleEXT_LOAD
		fp_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)procAddr(device, "vkCmdSetDiscardRectangleEXT");
#endif
#endif
#if defined(VK_EXT_hdr_metadata) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetHdrMetadataEXT_LOAD
#define PFN_vkSetHdrMetadataEXT_LOAD
		fp_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)procAddr(device, "vkSetHdrMetadataEXT");
#endif
#endif
#if defined(VK_KHR_create_renderpass2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateRenderPass2KHR_LOAD
#define PFN_vkCreateRenderPass2KHR_LOAD
		fp_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)procAddr(device, "vkCreateRenderPass2KHR");
#endif
#ifndef PFN_vkCmdBeginRenderPass2KHR_LOAD
#define PFN_vkCmdBeginRenderPass2KHR_LOAD
		fp_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)procAddr(device, "vkCmdBeginRenderPass2KHR");
#endif
#ifndef PFN_vkCmdNextSubpass2KHR_LOAD
#define PFN_vkCmdNextSubpass2KHR_LOAD
		fp_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)procAddr(device, "vkCmdNextSubpass2KHR");
#endif
#ifndef PFN_vkCmdEndRenderPass2KHR_LOAD
#define PFN_vkCmdEndRenderPass2KHR_LOAD
		fp_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)procAddr(device, "vkCmdEndRenderPass2KHR");
#endif
#endif
#if defined(VK_KHR_shared_presentable_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainStatusKHR_LOAD
#define PFN_vkGetSwapchainStatusKHR_LOAD
		fp_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)procAddr(device, "vkGetSwapchainStatusKHR");
#endif
#endif
#if defined(VK_KHR_external_fence_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceWin32HandleKHR_LOAD
#define PFN_vkImportFenceWin32HandleKHR_LOAD
		fp_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)procAddr(device, "vkImportFenceWin32HandleKHR");
#endif
#ifndef PFN_vkGetFenceWin32HandleKHR_LOAD
#define PFN_vkGetFenceWin32HandleKHR_LOAD
		fp_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)procAddr(device, "vkGetFenceWin32HandleKHR");
#endif
#endif
#if defined(VK_KHR_external_fence_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceFdKHR_LOAD
#define PFN_vkImportFenceFdKHR_LOAD
		fp_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)procAddr(device, "vkImportFenceFdKHR");
#endif
#ifndef PFN_vkGetFenceFdKHR_LOAD
#define PFN_vkGetFenceFdKHR_LOAD
		fp_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)procAddr(device, "vkGetFenceFdKHR");
#endif
#endif
#if defined(VK_KHR_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireProfilingLockKHR_LOAD
#define PFN_vkAcquireProfilingLockKHR_LOAD
		fp_vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)procAddr(device, "vkAcquireProfilingLockKHR");
#endif
#ifndef PFN_vkReleaseProfilingLockKHR_LOAD
#define PFN_vkReleaseProfilingLockKHR_LOAD
		fp_vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)procAddr(device, "vkReleaseProfilingLockKHR");
#endif
#endif
#if defined(VK_EXT_debug_utils) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetDebugUtilsObjectNameEXT_LOAD
#define PFN_vkSetDebugUtilsObjectNameEXT_LOAD
		fp_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)procAddr(device, "vkSetDebugUtilsObjectNameEXT");
#endif
#ifndef PFN_vkSetDebugUtilsObjectTagEXT_LOAD
#define PFN_vkSetDebugUtilsObjectTagEXT_LOAD
		fp_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)procAddr(device, "vkSetDebugUtilsObjectTagEXT");
#endif
#ifndef PFN_vkQueueBeginDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueBeginDebugUtilsLabelEXT_LOAD
		fp_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)procAddr(device, "vkQueueBeginDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkQueueEndDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueEndDebugUtilsLabelEXT_LOAD
		fp_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)procAddr(device, "vkQueueEndDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkQueueInsertDebugUtilsLabelEXT_LOAD
#define PFN_vkQueueInsertDebugUtilsLabelEXT_LOAD
		fp_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)procAddr(device, "vkQueueInsertDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdBeginDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdBeginDebugUtilsLabelEXT_LOAD
		fp_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)procAddr(device, "vkCmdBeginDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdEndDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdEndDebugUtilsLabelEXT_LOAD
		fp_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)procAddr(device, "vkCmdEndDebugUtilsLabelEXT");
#endif
#ifndef PFN_vkCmdInsertDebugUtilsLabelEXT_LOAD
#define PFN_vkCmdInsertDebugUtilsLabelEXT_LOAD
		fp_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)procAddr(device, "vkCmdInsertDebugUtilsLabelEXT");
#endif
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetAndroidHardwareBufferPropertiesANDROID_LOAD
#define PFN_vkGetAndroidHardwareBufferPropertiesANDROID_LOAD
		fp_vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)procAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
#endif
#ifndef PFN_vkGetMemoryAndroidHardwareBufferANDROID_LOAD
#define PFN_vkGetMemoryAndroidHardwareBufferANDROID_LOAD
		fp_vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)procAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif
#endif
#if defined(VK_EXT_sample_locations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetSampleLocationsEXT_LOAD
#define PFN_vkCmdSetSampleLocationsEXT_LOAD
		fp_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)procAddr(device, "vkCmdSetSampleLocationsEXT");
#endif
#endif
#if defined(VK_KHR_get_memory_requirements2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageMemoryRequirements2KHR_LOAD
#define PFN_vkGetImageMemoryRequirements2KHR_LOAD
		fp_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)procAddr(device, "vkGetImageMemoryRequirements2KHR");
#endif
#ifndef PFN_vkGetBufferMemoryRequirements2KHR_LOAD
#define PFN_vkGetBufferMemoryRequirements2KHR_LOAD
		fp_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)procAddr(device, "vkGetBufferMemoryRequirements2KHR");
#endif
#ifndef PFN_vkGetImageSparseMemoryRequirements2KHR_LOAD
#define PFN_vkGetImageSparseMemoryRequirements2KHR_LOAD
		fp_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)procAddr(device, "vkGetImageSparseMemoryRequirements2KHR");
#endif
#endif
#if defined(VK_KHR_acceleration_structure) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureKHR_LOAD
#define PFN_vkCreateAccelerationStructureKHR_LOAD
		fp_vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)procAddr(device, "vkCreateAccelerationStructureKHR");
#endif
#ifndef PFN_vkDestroyAccelerationStructureKHR_LOAD
#define PFN_vkDestroyAccelerationStructureKHR_LOAD
		fp_vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)procAddr(device, "vkDestroyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresKHR_LOAD
#define PFN_vkCmdBuildAccelerationStructuresKHR_LOAD
		fp_vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)procAddr(device, "vkCmdBuildAccelerationStructuresKHR");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresIndirectKHR_LOAD
#define PFN_vkCmdBuildAccelerationStructuresIndirectKHR_LOAD
		fp_vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)procAddr(device, "vkCmdBuildAccelerationStructuresIndirectKHR");
#endif
#ifndef PFN_vkBuildAccelerationStructuresKHR_LOAD
#define PFN_vkBuildAccelerationStructuresKHR_LOAD
		fp_vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)procAddr(device, "vkBuildAccelerationStructuresKHR");
#endif
#ifndef PFN_vkCopyAccelerationStructureKHR_LOAD
#define PFN_vkCopyAccelerationStructureKHR_LOAD
		fp_vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)procAddr(device, "vkCopyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCopyAccelerationStructureToMemoryKHR_LOAD
#define PFN_vkCopyAccelerationStructureToMemoryKHR_LOAD
		fp_vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCopyAccelerationStructureToMemoryKHR");
#endif
#ifndef PFN_vkCopyMemoryToAccelerationStructureKHR_LOAD
#define PFN_vkCopyMemoryToAccelerationStructureKHR_LOAD
		fp_vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCopyMemoryToAccelerationStructureKHR");
#endif
#ifndef PFN_vkWriteAccelerationStructuresPropertiesKHR_LOAD
#define PFN_vkWriteAccelerationStructuresPropertiesKHR_LOAD
		fp_vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkWriteAccelerationStructuresPropertiesKHR");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureKHR_LOAD
#define PFN_vkCmdCopyAccelerationStructureKHR_LOAD
		fp_vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)procAddr(device, "vkCmdCopyAccelerationStructureKHR");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureToMemoryKHR_LOAD
#define PFN_vkCmdCopyAccelerationStructureToMemoryKHR_LOAD
		fp_vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCmdCopyAccelerationStructureToMemoryKHR");
#endif
#ifndef PFN_vkCmdCopyMemoryToAccelerationStructureKHR_LOAD
#define PFN_vkCmdCopyMemoryToAccelerationStructureKHR_LOAD
		fp_vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCmdCopyMemoryToAccelerationStructureKHR");
#endif
#ifndef PFN_vkGetAccelerationStructureDeviceAddressKHR_LOAD
#define PFN_vkGetAccelerationStructureDeviceAddressKHR_LOAD
		fp_vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)procAddr(device, "vkGetAccelerationStructureDeviceAddressKHR");
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_LOAD
#define PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_LOAD
		fp_vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
#endif
#ifndef PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_LOAD
#define PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_LOAD
		fp_vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)procAddr(device, "vkGetDeviceAccelerationStructureCompatibilityKHR");
#endif
#ifndef PFN_vkGetAccelerationStructureBuildSizesKHR_LOAD
#define PFN_vkGetAccelerationStructureBuildSizesKHR_LOAD
		fp_vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)procAddr(device, "vkGetAccelerationStructureBuildSizesKHR");
#endif
#endif
#if defined(VK_KHR_ray_tracing_pipeline) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdTraceRaysKHR_LOAD
#define PFN_vkCmdTraceRaysKHR_LOAD
		fp_vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)procAddr(device, "vkCmdTraceRaysKHR");
#endif
#ifndef PFN_vkCreateRayTracingPipelinesKHR_LOAD
#define PFN_vkCreateRayTracingPipelinesKHR_LOAD
		fp_vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)procAddr(device, "vkCreateRayTracingPipelinesKHR");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesKHR_LOAD
#define PFN_vkGetRayTracingShaderGroupHandlesKHR_LOAD
		fp_vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingShaderGroupHandlesKHR");
#endif
#ifndef PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_LOAD
#define PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_LOAD
		fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
#endif
#ifndef PFN_vkCmdTraceRaysIndirectKHR_LOAD
#define PFN_vkCmdTraceRaysIndirectKHR_LOAD
		fp_vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)procAddr(device, "vkCmdTraceRaysIndirectKHR");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupStackSizeKHR_LOAD
#define PFN_vkGetRayTracingShaderGroupStackSizeKHR_LOAD
		fp_vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)procAddr(device, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif
#ifndef PFN_vkCmdSetRayTracingPipelineStackSizeKHR_LOAD
#define PFN_vkCmdSetRayTracingPipelineStackSizeKHR_LOAD
		fp_vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)procAddr(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
#endif
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSamplerYcbcrConversionKHR_LOAD
#define PFN_vkCreateSamplerYcbcrConversionKHR_LOAD
		fp_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)procAddr(device, "vkCreateSamplerYcbcrConversionKHR");
#endif
#ifndef PFN_vkDestroySamplerYcbcrConversionKHR_LOAD
#define PFN_vkDestroySamplerYcbcrConversionKHR_LOAD
		fp_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)procAddr(device, "vkDestroySamplerYcbcrConversionKHR");
#endif
#endif
#if defined(VK_KHR_bind_memory2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkBindBufferMemory2KHR_LOAD
#define PFN_vkBindBufferMemory2KHR_LOAD
		fp_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)procAddr(device, "vkBindBufferMemory2KHR");
#endif
#ifndef PFN_vkBindImageMemory2KHR_LOAD
#define PFN_vkBindImageMemory2KHR_LOAD
		fp_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)procAddr(device, "vkBindImageMemory2KHR");
#endif
#endif
#if defined(VK_EXT_image_drm_format_modifier) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageDrmFormatModifierPropertiesEXT_LOAD
#define PFN_vkGetImageDrmFormatModifierPropertiesEXT_LOAD
		fp_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)procAddr(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif
#endif
#if defined(VK_EXT_validation_cache) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateValidationCacheEXT_LOAD
#define PFN_vkCreateValidationCacheEXT_LOAD
		fp_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)procAddr(device, "vkCreateValidationCacheEXT");
#endif
#ifndef PFN_vkDestroyValidationCacheEXT_LOAD
#define PFN_vkDestroyValidationCacheEXT_LOAD
		fp_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)procAddr(device, "vkDestroyValidationCacheEXT");
#endif
#ifndef PFN_vkMergeValidationCachesEXT_LOAD
#define PFN_vkMergeValidationCachesEXT_LOAD
		fp_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)procAddr(device, "vkMergeValidationCachesEXT");
#endif
#ifndef PFN_vkGetValidationCacheDataEXT_LOAD
#define PFN_vkGetValidationCacheDataEXT_LOAD
		fp_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)procAddr(device, "vkGetValidationCacheDataEXT");
#endif
#endif
#if defined(VK_NV_shading_rate_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindShadingRateImageNV_LOAD
#define PFN_vkCmdBindShadingRateImageNV_LOAD
		fp_vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)procAddr(device, "vkCmdBindShadingRateImageNV");
#endif
#ifndef PFN_vkCmdSetViewportShadingRatePaletteNV_LOAD
#define PFN_vkCmdSetViewportShadingRatePaletteNV_LOAD
		fp_vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)procAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
#endif
#ifndef PFN_vkCmdSetCoarseSampleOrderNV_LOAD
#define PFN_vkCmdSetCoarseSampleOrderNV_LOAD
		fp_vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)procAddr(device, "vkCmdSetCoarseSampleOrderNV");
#endif
#endif
#if defined(VK_NV_ray_tracing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureNV_LOAD
#define PFN_vkCreateAccelerationStructureNV_LOAD
		fp_vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)procAddr(device, "vkCreateAccelerationStructureNV");
#endif
#ifndef PFN_vkDestroyAccelerationStructureNV_LOAD
#define PFN_vkDestroyAccelerationStructureNV_LOAD
		fp_vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)procAddr(device, "vkDestroyAccelerationStructureNV");
#endif
#ifndef PFN_vkGetAccelerationStructureMemoryRequirementsNV_LOAD
#define PFN_vkGetAccelerationStructureMemoryRequirementsNV_LOAD
		fp_vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)procAddr(device, "vkGetAccelerationStructureMemoryRequirementsNV");
#endif
#ifndef PFN_vkBindAccelerationStructureMemoryNV_LOAD
#define PFN_vkBindAccelerationStructureMemoryNV_LOAD
		fp_vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)procAddr(device, "vkBindAccelerationStructureMemoryNV");
#endif
#ifndef PFN_vkCmdBuildAccelerationStructureNV_LOAD
#define PFN_vkCmdBuildAccelerationStructureNV_LOAD
		fp_vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)procAddr(device, "vkCmdBuildAccelerationStructureNV");
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureNV_LOAD
#define PFN_vkCmdCopyAccelerationStructureNV_LOAD
		fp_vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)procAddr(device, "vkCmdCopyAccelerationStructureNV");
#endif
#ifndef PFN_vkCmdTraceRaysNV_LOAD
#define PFN_vkCmdTraceRaysNV_LOAD
		fp_vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)procAddr(device, "vkCmdTraceRaysNV");
#endif
#ifndef PFN_vkCreateRayTracingPipelinesNV_LOAD
#define PFN_vkCreateRayTracingPipelinesNV_LOAD
		fp_vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)procAddr(device, "vkCreateRayTracingPipelinesNV");
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesNV_LOAD
#define PFN_vkGetRayTracingShaderGroupHandlesNV_LOAD
		fp_vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)procAddr(device, "vkGetRayTracingShaderGroupHandlesNV");
#endif
#ifndef PFN_vkGetAccelerationStructureHandleNV_LOAD
#define PFN_vkGetAccelerationStructureHandleNV_LOAD
		fp_vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)procAddr(device, "vkGetAccelerationStructureHandleNV");
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesNV_LOAD
#define PFN_vkCmdWriteAccelerationStructuresPropertiesNV_LOAD
		fp_vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
#endif
#ifndef PFN_vkCompileDeferredNV_LOAD
#define PFN_vkCompileDeferredNV_LOAD
		fp_vkCompileDeferredNV = (PFN_vkCompileDeferredNV)procAddr(device, "vkCompileDeferredNV");
#endif
#endif
#if defined(VK_KHR_maintenance3) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDescriptorSetLayoutSupportKHR_LOAD
#define PFN_vkGetDescriptorSetLayoutSupportKHR_LOAD
		fp_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)procAddr(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif
#endif
#if defined(VK_EXT_external_memory_host) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryHostPointerPropertiesEXT_LOAD
#define PFN_vkGetMemoryHostPointerPropertiesEXT_LOAD
		fp_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)procAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif
#endif
#if defined(VK_AMD_buffer_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdWriteBufferMarkerAMD_LOAD
#define PFN_vkCmdWriteBufferMarkerAMD_LOAD
		fp_vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)procAddr(device, "vkCmdWriteBufferMarkerAMD");
#endif
#endif
#if defined(VK_EXT_calibrated_timestamps) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetCalibratedTimestampsEXT_LOAD
#define PFN_vkGetCalibratedTimestampsEXT_LOAD
		fp_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)procAddr(device, "vkGetCalibratedTimestampsEXT");
#endif
#endif
#if defined(VK_NV_mesh_shader) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawMeshTasksNV_LOAD
#define PFN_vkCmdDrawMeshTasksNV_LOAD
		fp_vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)procAddr(device, "vkCmdDrawMeshTasksNV");
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectNV_LOAD
#define PFN_vkCmdDrawMeshTasksIndirectNV_LOAD
		fp_vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)procAddr(device, "vkCmdDrawMeshTasksIndirectNV");
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectCountNV_LOAD
#define PFN_vkCmdDrawMeshTasksIndirectCountNV_LOAD
		fp_vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)procAddr(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif
#endif
#if defined(VK_NV_scissor_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetExclusiveScissorNV_LOAD
#define PFN_vkCmdSetExclusiveScissorNV_LOAD
		fp_vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)procAddr(device, "vkCmdSetExclusiveScissorNV");
#endif
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCheckpointNV_LOAD
#define PFN_vkCmdSetCheckpointNV_LOAD
		fp_vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)procAddr(device, "vkCmdSetCheckpointNV");
#endif
#ifndef PFN_vkGetQueueCheckpointDataNV_LOAD
#define PFN_vkGetQueueCheckpointDataNV_LOAD
		fp_vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)procAddr(device, "vkGetQueueCheckpointDataNV");
#endif
#endif
#if defined(VK_KHR_timeline_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSemaphoreCounterValueKHR_LOAD
#define PFN_vkGetSemaphoreCounterValueKHR_LOAD
		fp_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)procAddr(device, "vkGetSemaphoreCounterValueKHR");
#endif
#ifndef PFN_vkWaitSemaphoresKHR_LOAD
#define PFN_vkWaitSemaphoresKHR_LOAD
		fp_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)procAddr(device, "vkWaitSemaphoresKHR");
#endif
#ifndef PFN_vkSignalSemaphoreKHR_LOAD
#define PFN_vkSignalSemaphoreKHR_LOAD
		fp_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)procAddr(device, "vkSignalSemaphoreKHR");
#endif
#endif
#if defined(VK_INTEL_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkInitializePerformanceApiINTEL_LOAD
#define PFN_vkInitializePerformanceApiINTEL_LOAD
		fp_vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)procAddr(device, "vkInitializePerformanceApiINTEL");
#endif
#ifndef PFN_vkUninitializePerformanceApiINTEL_LOAD
#define PFN_vkUninitializePerformanceApiINTEL_LOAD
		fp_vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)procAddr(device, "vkUninitializePerformanceApiINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceMarkerINTEL_LOAD
#define PFN_vkCmdSetPerformanceMarkerINTEL_LOAD
		fp_vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)procAddr(device, "vkCmdSetPerformanceMarkerINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceStreamMarkerINTEL_LOAD
#define PFN_vkCmdSetPerformanceStreamMarkerINTEL_LOAD
		fp_vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)procAddr(device, "vkCmdSetPerformanceStreamMarkerINTEL");
#endif
#ifndef PFN_vkCmdSetPerformanceOverrideINTEL_LOAD
#define PFN_vkCmdSetPerformanceOverrideINTEL_LOAD
		fp_vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)procAddr(device, "vkCmdSetPerformanceOverrideINTEL");
#endif
#ifndef PFN_vkAcquirePerformanceConfigurationINTEL_LOAD
#define PFN_vkAcquirePerformanceConfigurationINTEL_LOAD
		fp_vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)procAddr(device, "vkAcquirePerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkReleasePerformanceConfigurationINTEL_LOAD
#define PFN_vkReleasePerformanceConfigurationINTEL_LOAD
		fp_vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)procAddr(device, "vkReleasePerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkQueueSetPerformanceConfigurationINTEL_LOAD
#define PFN_vkQueueSetPerformanceConfigurationINTEL_LOAD
		fp_vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)procAddr(device, "vkQueueSetPerformanceConfigurationINTEL");
#endif
#ifndef PFN_vkGetPerformanceParameterINTEL_LOAD
#define PFN_vkGetPerformanceParameterINTEL_LOAD
		fp_vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)procAddr(device, "vkGetPerformanceParameterINTEL");
#endif
#endif
#if defined(VK_AMD_display_native_hdr) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetLocalDimmingAMD_LOAD
#define PFN_vkSetLocalDimmingAMD_LOAD
		fp_vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)procAddr(device, "vkSetLocalDimmingAMD");
#endif
#endif
#if defined(VK_KHR_fragment_shading_rate) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateKHR_LOAD
#define PFN_vkCmdSetFragmentShadingRateKHR_LOAD
		fp_vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)procAddr(device, "vkCmdSetFragmentShadingRateKHR");
#endif
#endif
#if defined(VK_EXT_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferDeviceAddressEXT_LOAD
#define PFN_vkGetBufferDeviceAddressEXT_LOAD
		fp_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)procAddr(device, "vkGetBufferDeviceAddressEXT");
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireFullScreenExclusiveModeEXT_LOAD
#define PFN_vkAcquireFullScreenExclusiveModeEXT_LOAD
		fp_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)procAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif
#ifndef PFN_vkReleaseFullScreenExclusiveModeEXT_LOAD
#define PFN_vkReleaseFullScreenExclusiveModeEXT_LOAD
		fp_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)procAddr(device, "vkReleaseFullScreenExclusiveModeEXT");
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
		fp_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)procAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_LOAD
		fp_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)procAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#endif
#if defined(VK_KHR_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferOpaqueCaptureAddressKHR_LOAD
#define PFN_vkGetBufferOpaqueCaptureAddressKHR_LOAD
		fp_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)procAddr(device, "vkGetBufferOpaqueCaptureAddressKHR");
#endif
#ifndef PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_LOAD
#define PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_LOAD
		fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif
#endif
#if defined(VK_EXT_line_rasterization) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetLineStippleEXT_LOAD
#define PFN_vkCmdSetLineStippleEXT_LOAD
		fp_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)procAddr(device, "vkCmdSetLineStippleEXT");
#endif
#endif
#if defined(VK_EXT_host_query_reset) && defined(VK_VERSION_1_0)
#ifndef PFN_vkResetQueryPoolEXT_LOAD
#define PFN_vkResetQueryPoolEXT_LOAD
		fp_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)procAddr(device, "vkResetQueryPoolEXT");
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCullModeEXT_LOAD
#define PFN_vkCmdSetCullModeEXT_LOAD
		fp_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)procAddr(device, "vkCmdSetCullModeEXT");
#endif
#ifndef PFN_vkCmdSetFrontFaceEXT_LOAD
#define PFN_vkCmdSetFrontFaceEXT_LOAD
		fp_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)procAddr(device, "vkCmdSetFrontFaceEXT");
#endif
#ifndef PFN_vkCmdSetPrimitiveTopologyEXT_LOAD
#define PFN_vkCmdSetPrimitiveTopologyEXT_LOAD
		fp_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)procAddr(device, "vkCmdSetPrimitiveTopologyEXT");
#endif
#ifndef PFN_vkCmdSetViewportWithCountEXT_LOAD
#define PFN_vkCmdSetViewportWithCountEXT_LOAD
		fp_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)procAddr(device, "vkCmdSetViewportWithCountEXT");
#endif
#ifndef PFN_vkCmdSetScissorWithCountEXT_LOAD
#define PFN_vkCmdSetScissorWithCountEXT_LOAD
		fp_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)procAddr(device, "vkCmdSetScissorWithCountEXT");
#endif
#ifndef PFN_vkCmdBindVertexBuffers2EXT_LOAD
#define PFN_vkCmdBindVertexBuffers2EXT_LOAD
		fp_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)procAddr(device, "vkCmdBindVertexBuffers2EXT");
#endif
#ifndef PFN_vkCmdSetDepthTestEnableEXT_LOAD
#define PFN_vkCmdSetDepthTestEnableEXT_LOAD
		fp_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)procAddr(device, "vkCmdSetDepthTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthWriteEnableEXT_LOAD
#define PFN_vkCmdSetDepthWriteEnableEXT_LOAD
		fp_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)procAddr(device, "vkCmdSetDepthWriteEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthCompareOpEXT_LOAD
#define PFN_vkCmdSetDepthCompareOpEXT_LOAD
		fp_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)procAddr(device, "vkCmdSetDepthCompareOpEXT");
#endif
#ifndef PFN_vkCmdSetDepthBoundsTestEnableEXT_LOAD
#define PFN_vkCmdSetDepthBoundsTestEnableEXT_LOAD
		fp_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)procAddr(device, "vkCmdSetDepthBoundsTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetStencilTestEnableEXT_LOAD
#define PFN_vkCmdSetStencilTestEnableEXT_LOAD
		fp_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)procAddr(device, "vkCmdSetStencilTestEnableEXT");
#endif
#ifndef PFN_vkCmdSetStencilOpEXT_LOAD
#define PFN_vkCmdSetStencilOpEXT_LOAD
		fp_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)procAddr(device, "vkCmdSetStencilOpEXT");
#endif
#endif
#if defined(VK_KHR_deferred_host_operations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDeferredOperationKHR_LOAD
#define PFN_vkCreateDeferredOperationKHR_LOAD
		fp_vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)procAddr(device, "vkCreateDeferredOperationKHR");
#endif
#ifndef PFN_vkDestroyDeferredOperationKHR_LOAD
#define PFN_vkDestroyDeferredOperationKHR_LOAD
		fp_vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)procAddr(device, "vkDestroyDeferredOperationKHR");
#endif
#ifndef PFN_vkGetDeferredOperationMaxConcurrencyKHR_LOAD
#define PFN_vkGetDeferredOperationMaxConcurrencyKHR_LOAD
		fp_vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)procAddr(device, "vkGetDeferredOperationMaxConcurrencyKHR");
#endif
#ifndef PFN_vkGetDeferredOperationResultKHR_LOAD
#define PFN_vkGetDeferredOperationResultKHR_LOAD
		fp_vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)procAddr(device, "vkGetDeferredOperationResultKHR");
#endif
#ifndef PFN_vkDeferredOperationJoinKHR_LOAD
#define PFN_vkDeferredOperationJoinKHR_LOAD
		fp_vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)procAddr(device, "vkDeferredOperationJoinKHR");
#endif
#endif
#if defined(VK_KHR_pipeline_executable_properties) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetPipelineExecutablePropertiesKHR_LOAD
#define PFN_vkGetPipelineExecutablePropertiesKHR_LOAD
		fp_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)procAddr(device, "vkGetPipelineExecutablePropertiesKHR");
#endif
#ifndef PFN_vkGetPipelineExecutableStatisticsKHR_LOAD
#define PFN_vkGetPipelineExecutableStatisticsKHR_LOAD
		fp_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)procAddr(device, "vkGetPipelineExecutableStatisticsKHR");
#endif
#ifndef PFN_vkGetPipelineExecutableInternalRepresentationsKHR_LOAD
#define PFN_vkGetPipelineExecutableInternalRepresentationsKHR_LOAD
		fp_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)procAddr(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif
#endif
#if defined(VK_NV_device_generated_commands) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetGeneratedCommandsMemoryRequirementsNV_LOAD
#define PFN_vkGetGeneratedCommandsMemoryRequirementsNV_LOAD
		fp_vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)procAddr(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif
#ifndef PFN_vkCmdPreprocessGeneratedCommandsNV_LOAD
#define PFN_vkCmdPreprocessGeneratedCommandsNV_LOAD
		fp_vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)procAddr(device, "vkCmdPreprocessGeneratedCommandsNV");
#endif
#ifndef PFN_vkCmdExecuteGeneratedCommandsNV_LOAD
#define PFN_vkCmdExecuteGeneratedCommandsNV_LOAD
		fp_vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)procAddr(device, "vkCmdExecuteGeneratedCommandsNV");
#endif
#ifndef PFN_vkCmdBindPipelineShaderGroupNV_LOAD
#define PFN_vkCmdBindPipelineShaderGroupNV_LOAD
		fp_vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)procAddr(device, "vkCmdBindPipelineShaderGroupNV");
#endif
#ifndef PFN_vkCreateIndirectCommandsLayoutNV_LOAD
#define PFN_vkCreateIndirectCommandsLayoutNV_LOAD
		fp_vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)procAddr(device, "vkCreateIndirectCommandsLayoutNV");
#endif
#ifndef PFN_vkDestroyIndirectCommandsLayoutNV_LOAD
#define PFN_vkDestroyIndirectCommandsLayoutNV_LOAD
		fp_vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)procAddr(device, "vkDestroyIndirectCommandsLayoutNV");
#endif
#endif
#if defined(VK_EXT_private_data) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreatePrivateDataSlotEXT_LOAD
#define PFN_vkCreatePrivateDataSlotEXT_LOAD
		fp_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)procAddr(device, "vkCreatePrivateDataSlotEXT");
#endif
#ifndef PFN_vkDestroyPrivateDataSlotEXT_LOAD
#define PFN_vkDestroyPrivateDataSlotEXT_LOAD
		fp_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)procAddr(device, "vkDestroyPrivateDataSlotEXT");
#endif
#ifndef PFN_vkSetPrivateDataEXT_LOAD
#define PFN_vkSetPrivateDataEXT_LOAD
		fp_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)procAddr(device, "vkSetPrivateDataEXT");
#endif
#ifndef PFN_vkGetPrivateDataEXT_LOAD
#define PFN_vkGetPrivateDataEXT_LOAD
		fp_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)procAddr(device, "vkGetPrivateDataEXT");
#endif
#endif
#if defined(VK_KHR_video_encode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdEncodeVideoKHR_LOAD
#define PFN_vkCmdEncodeVideoKHR_LOAD
		fp_vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)procAddr(device, "vkCmdEncodeVideoKHR");
#endif
#endif
#if defined(VK_KHR_synchronization2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetEvent2KHR_LOAD
#define PFN_vkCmdSetEvent2KHR_LOAD
		fp_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)procAddr(device, "vkCmdSetEvent2KHR");
#endif
#ifndef PFN_vkCmdResetEvent2KHR_LOAD
#define PFN_vkCmdResetEvent2KHR_LOAD
		fp_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)procAddr(device, "vkCmdResetEvent2KHR");
#endif
#ifndef PFN_vkCmdWaitEvents2KHR_LOAD
#define PFN_vkCmdWaitEvents2KHR_LOAD
		fp_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)procAddr(device, "vkCmdWaitEvents2KHR");
#endif
#ifndef PFN_vkCmdPipelineBarrier2KHR_LOAD
#define PFN_vkCmdPipelineBarrier2KHR_LOAD
		fp_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)procAddr(device, "vkCmdPipelineBarrier2KHR");
#endif
#ifndef PFN_vkCmdWriteTimestamp2KHR_LOAD
#define PFN_vkCmdWriteTimestamp2KHR_LOAD
		fp_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)procAddr(device, "vkCmdWriteTimestamp2KHR");
#endif
#ifndef PFN_vkQueueSubmit2KHR_LOAD
#define PFN_vkQueueSubmit2KHR_LOAD
		fp_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)procAddr(device, "vkQueueSubmit2KHR");
#endif
#ifndef PFN_vkCmdWriteBufferMarker2AMD_LOAD
#define PFN_vkCmdWriteBufferMarker2AMD_LOAD
		fp_vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)procAddr(device, "vkCmdWriteBufferMarker2AMD");
#endif
#ifndef PFN_vkGetQueueCheckpointData2NV_LOAD
#define PFN_vkGetQueueCheckpointData2NV_LOAD
		fp_vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)procAddr(device, "vkGetQueueCheckpointData2NV");
#endif
#endif
#if defined(VK_NV_fragment_shading_rate_enums) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateEnumNV_LOAD
#define PFN_vkCmdSetFragmentShadingRateEnumNV_LOAD
		fp_vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)procAddr(device, "vkCmdSetFragmentShadingRateEnumNV");
#endif
#endif
#if defined(VK_KHR_copy_commands2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdCopyBuffer2KHR_LOAD
#define PFN_vkCmdCopyBuffer2KHR_LOAD
		fp_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)procAddr(device, "vkCmdCopyBuffer2KHR");
#endif
#ifndef PFN_vkCmdCopyImage2KHR_LOAD
#define PFN_vkCmdCopyImage2KHR_LOAD
		fp_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)procAddr(device, "vkCmdCopyImage2KHR");
#endif
#ifndef PFN_vkCmdCopyBufferToImage2KHR_LOAD
#define PFN_vkCmdCopyBufferToImage2KHR_LOAD
		fp_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)procAddr(device, "vkCmdCopyBufferToImage2KHR");
#endif
#ifndef PFN_vkCmdCopyImageToBuffer2KHR_LOAD
#define PFN_vkCmdCopyImageToBuffer2KHR_LOAD
		fp_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)procAddr(device, "vkCmdCopyImageToBuffer2KHR");
#endif
#ifndef PFN_vkCmdBlitImage2KHR_LOAD
#define PFN_vkCmdBlitImage2KHR_LOAD
		fp_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)procAddr(device, "vkCmdBlitImage2KHR");
#endif
#ifndef PFN_vkCmdResolveImage2KHR_LOAD
#define PFN_vkCmdResolveImage2KHR_LOAD
		fp_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)procAddr(device, "vkCmdResolveImage2KHR");
#endif
#endif
#if defined(VK_EXT_vertex_input_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetVertexInputEXT_LOAD
#define PFN_vkCmdSetVertexInputEXT_LOAD
		fp_vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)procAddr(device, "vkCmdSetVertexInputEXT");
#endif
#endif
#if defined(VK_FUCHSIA_external_memory) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryZirconHandleFUCHSIA_LOAD
#define PFN_vkGetMemoryZirconHandleFUCHSIA_LOAD
		fp_vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)procAddr(device, "vkGetMemoryZirconHandleFUCHSIA");
#endif
#ifndef PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_LOAD
#define PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_LOAD
		fp_vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)procAddr(device, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif
#endif
#if defined(VK_FUCHSIA_external_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreZirconHandleFUCHSIA_LOAD
#define PFN_vkImportSemaphoreZirconHandleFUCHSIA_LOAD
		fp_vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif
#ifndef PFN_vkGetSemaphoreZirconHandleFUCHSIA_LOAD
#define PFN_vkGetSemaphoreZirconHandleFUCHSIA_LOAD
		fp_vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkGetSemaphoreZirconHandleFUCHSIA");
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetPatchControlPointsEXT_LOAD
#define PFN_vkCmdSetPatchControlPointsEXT_LOAD
		fp_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)procAddr(device, "vkCmdSetPatchControlPointsEXT");
#endif
#ifndef PFN_vkCmdSetRasterizerDiscardEnableEXT_LOAD
#define PFN_vkCmdSetRasterizerDiscardEnableEXT_LOAD
		fp_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)procAddr(device, "vkCmdSetRasterizerDiscardEnableEXT");
#endif
#ifndef PFN_vkCmdSetDepthBiasEnableEXT_LOAD
#define PFN_vkCmdSetDepthBiasEnableEXT_LOAD
		fp_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)procAddr(device, "vkCmdSetDepthBiasEnableEXT");
#endif
#ifndef PFN_vkCmdSetLogicOpEXT_LOAD
#define PFN_vkCmdSetLogicOpEXT_LOAD
		fp_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)procAddr(device, "vkCmdSetLogicOpEXT");
#endif
#ifndef PFN_vkCmdSetPrimitiveRestartEnableEXT_LOAD
#define PFN_vkCmdSetPrimitiveRestartEnableEXT_LOAD
		fp_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)procAddr(device, "vkCmdSetPrimitiveRestartEnableEXT");
#endif
#endif
#if defined(VK_EXT_color_write_enable) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetColorWriteEnableEXT_LOAD
#define PFN_vkCmdSetColorWriteEnableEXT_LOAD
		fp_vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)procAddr(device, "vkCmdSetColorWriteEnableEXT");
#endif
#endif
	}
	void getDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
		fp_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
	}
	VkResult queueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
		return fp_vkQueueSubmit(queue, submitCount, pSubmits, fence);
	}
	VkResult queueWaitIdle(VkQueue queue) {
		return fp_vkQueueWaitIdle(queue);
	}
	VkResult deviceWaitIdle() {
		return fp_vkDeviceWaitIdle(device);
	}
	VkResult allocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
		return fp_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
	}
	void freeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
		fp_vkFreeMemory(device, memory, pAllocator);
	}
	VkResult mapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) {
		return fp_vkMapMemory(device, memory, offset, size, flags, ppData);
	}
	void unmapMemory(VkDeviceMemory memory) {
		fp_vkUnmapMemory(device, memory);
	}
	VkResult flushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
		return fp_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	}
	VkResult invalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
		return fp_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	}
	void getDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) {
		fp_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
	}
	VkResult bindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
		return fp_vkBindBufferMemory(device, buffer, memory, memoryOffset);
	}
	VkResult bindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
		return fp_vkBindImageMemory(device, image, memory, memoryOffset);
	}
	void getBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) {
		fp_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
	}
	void getImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements) {
		fp_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
	}
	void getImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) {
		fp_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
	VkResult queueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) {
		return fp_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
	}
	VkResult createFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
		return fp_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
	}
	void destroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyFence(device, fence, pAllocator);
	}
	VkResult resetFences(uint32_t fenceCount, const VkFence* pFences) {
		return fp_vkResetFences(device, fenceCount, pFences);
	}
	VkResult getFenceStatus(VkFence fence) {
		return fp_vkGetFenceStatus(device, fence);
	}
	VkResult waitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) {
		return fp_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
	}
	VkResult createSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
		return fp_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
	}
	void destroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroySemaphore(device, semaphore, pAllocator);
	}
	VkResult createEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
		return fp_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
	}
	void destroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyEvent(device, event, pAllocator);
	}
	VkResult getEventStatus(VkEvent event) {
		return fp_vkGetEventStatus(device, event);
	}
	VkResult setEvent(VkEvent event) {
		return fp_vkSetEvent(device, event);
	}
	VkResult resetEvent(VkEvent event) {
		return fp_vkResetEvent(device, event);
	}
	VkResult createQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
		return fp_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
	}
	void destroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyQueryPool(device, queryPool, pAllocator);
	}
	VkResult getQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
		return fp_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
	}
	VkResult createBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
		return fp_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
	}
	void destroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyBuffer(device, buffer, pAllocator);
	}
	VkResult createBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
		return fp_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
	}
	void destroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyBufferView(device, bufferView, pAllocator);
	}
	VkResult createImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
		return fp_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
	}
	void destroyImage(VkImage image, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyImage(device, image, pAllocator);
	}
	void getImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) {
		fp_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
	}
	VkResult createImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
		return fp_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
	}
	void destroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyImageView(device, imageView, pAllocator);
	}
	VkResult createShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
		return fp_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
	}
	void destroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyShaderModule(device, shaderModule, pAllocator);
	}
	VkResult createPipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
		return fp_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
	}
	void destroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
	}
	VkResult getPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) {
		return fp_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
	}
	VkResult mergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) {
		return fp_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
	}
	VkResult createGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
		return fp_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
	VkResult createComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
		return fp_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
	void destroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyPipeline(device, pipeline, pAllocator);
	}
	VkResult createPipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
		return fp_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
	}
	void destroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
	}
	VkResult createSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
		return fp_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
	}
	void destroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroySampler(device, sampler, pAllocator);
	}
	VkResult createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) {
		return fp_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
	}
	void destroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
	}
	VkResult createDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
		return fp_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
	}
	void destroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
	}
	VkResult resetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
		return fp_vkResetDescriptorPool(device, descriptorPool, flags);
	}
	VkResult allocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) {
		return fp_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
	}
	VkResult freeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
		return fp_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
	}
	void updateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) {
		fp_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
	}
	VkResult createFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
		return fp_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
	}
	void destroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyFramebuffer(device, framebuffer, pAllocator);
	}
	VkResult createRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
		return fp_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
	}
	void destroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyRenderPass(device, renderPass, pAllocator);
	}
	void getRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity) {
		fp_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
	}
	VkResult createCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
		return fp_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
	}
	void destroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyCommandPool(device, commandPool, pAllocator);
	}
	VkResult resetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
		return fp_vkResetCommandPool(device, commandPool, flags);
	}
	VkResult allocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) {
		return fp_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
	}
	void freeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
		fp_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
	}
	VkResult beginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
		return fp_vkBeginCommandBuffer(commandBuffer, pBeginInfo);
	}
	VkResult endCommandBuffer(VkCommandBuffer commandBuffer) {
		return fp_vkEndCommandBuffer(commandBuffer);
	}
	VkResult resetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
		return fp_vkResetCommandBuffer(commandBuffer, flags);
	}
	void cmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
		fp_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
	}
	void cmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
		fp_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
	}
	void cmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) {
		fp_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
	}
	void cmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
		fp_vkCmdSetLineWidth(commandBuffer, lineWidth);
	}
	void cmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
		fp_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
	}
	void cmdSetBlendConstants(VkCommandBuffer commandBuffer, float blendConstants[4]) {
		fp_vkCmdSetBlendConstants(commandBuffer, blendConstants);
	}
	void cmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
		fp_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
	}
	void cmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) {
		fp_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
	}
	void cmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
		fp_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
	}
	void cmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
		fp_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
	}
	void cmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) {
		fp_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
	}
	void cmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
		fp_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
	}
	void cmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
		fp_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
	}
	void cmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
		fp_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
	}
	void cmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
		fp_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
	}
	void cmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
		fp_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
	}
	void cmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
		fp_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
	}
	void cmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
		fp_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
	}
	void cmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
		fp_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
	}
	void cmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) {
		fp_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
	}
	void cmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) {
		fp_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) {
		fp_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
	}
	void cmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
		fp_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
		fp_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
	}
	void cmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) {
		fp_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
	}
	void cmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
		fp_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
	}
	void cmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
		fp_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
	}
	void cmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
		fp_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
	}
	void cmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) {
		fp_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
	}
	void cmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) {
		fp_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
		fp_vkCmdSetEvent(commandBuffer, event, stageMask);
	}
	void cmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
		fp_vkCmdResetEvent(commandBuffer, event, stageMask);
	}
	void cmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
		fp_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	}
	void cmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
		fp_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	}
	void cmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
		fp_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
	}
	void cmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
		fp_vkCmdEndQuery(commandBuffer, queryPool, query);
	}
	void cmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
		fp_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
	}
	void cmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
		fp_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
	}
	void cmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
		fp_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
	}
	void cmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
		fp_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
	}
	void cmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) {
		fp_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
	}
	void cmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
		fp_vkCmdNextSubpass(commandBuffer, contents);
	}
	void cmdEndRenderPass(VkCommandBuffer commandBuffer) {
		fp_vkCmdEndRenderPass(commandBuffer);
	}
	void cmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
		fp_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
	}
	VkResult bindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
		return fp_vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
	}
	VkResult bindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
		return fp_vkBindImageMemory2(device, bindInfoCount, pBindInfos);
	}
	void getDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
		fp_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
	}
	void cmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
		fp_vkCmdSetDeviceMask(commandBuffer, deviceMask);
	}
	void cmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
		fp_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
	}
	void getImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
		fp_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
	}
	void getBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
		fp_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
	}
	void getImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
		fp_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
	void trimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
		fp_vkTrimCommandPool(device, commandPool, flags);
	}
	void getDeviceQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
		fp_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
	}
	VkResult createSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
		return fp_vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
	}
	void destroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
	}
	VkResult createDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
		return fp_vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
	}
	void destroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
	}
	void updateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
		fp_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
	}
	void getDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
		fp_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
	}
	void cmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
		fp_vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
	void cmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
		fp_vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
	VkResult createRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
		return fp_vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
	}
	void cmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
		fp_vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
	}
	void cmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
		fp_vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
	}
	void cmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
		fp_vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
	}
	void resetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
		fp_vkResetQueryPool(device, queryPool, firstQuery, queryCount);
	}
	VkResult getSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue) {
		return fp_vkGetSemaphoreCounterValue(device, semaphore, pValue);
	}
	VkResult waitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
		return fp_vkWaitSemaphores(device, pWaitInfo, timeout);
	}
	VkResult signalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo) {
		return fp_vkSignalSemaphore(device, pSignalInfo);
	}
	VkDeviceAddress getBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo) {
		return fp_vkGetBufferDeviceAddress(device, pInfo);
	}
	uint64_t getBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo) {
		return fp_vkGetBufferOpaqueCaptureAddress(device, pInfo);
	}
	uint64_t getDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
		return fp_vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
	}
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSwapchainKHR_PROXY
#define PFN_vkCreateSwapchainKHR_PROXY
	VkResult createSwapchainKHR(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
		return fp_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
	}
#endif
#ifndef PFN_vkDestroySwapchainKHR_PROXY
#define PFN_vkDestroySwapchainKHR_PROXY
	void destroySwapchainKHR(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroySwapchainKHR(device, swapchain, pAllocator);
	}
#endif
#ifndef PFN_vkGetSwapchainImagesKHR_PROXY
#define PFN_vkGetSwapchainImagesKHR_PROXY
	VkResult getSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {
		return fp_vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
	}
#endif
#ifndef PFN_vkAcquireNextImageKHR_PROXY
#define PFN_vkAcquireNextImageKHR_PROXY
	VkResult acquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
		return fp_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
	}
#endif
#ifndef PFN_vkQueuePresentKHR_PROXY
#define PFN_vkQueuePresentKHR_PROXY
	VkResult queuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
		return fp_vkQueuePresentKHR(queue, pPresentInfo);
	}
#endif
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_PROXY
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_PROXY
	VkResult getDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
		return fp_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
	}
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_PROXY
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_PROXY
	VkResult getDeviceGroupSurfacePresentModesKHR(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) {
		return fp_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
	}
#endif
#ifndef PFN_vkAcquireNextImage2KHR_PROXY
#define PFN_vkAcquireNextImage2KHR_PROXY
	VkResult acquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) {
		return fp_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
	}
#endif
#endif
#if defined(VK_KHR_display_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSharedSwapchainsKHR_PROXY
#define PFN_vkCreateSharedSwapchainsKHR_PROXY
	VkResult createSharedSwapchainsKHR(uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
		return fp_vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
	}
#endif
#endif
#if defined(VK_ANDROID_native_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainGrallocUsageANDROID_PROXY
#define PFN_vkGetSwapchainGrallocUsageANDROID_PROXY
	VkResult getSwapchainGrallocUsageANDROID(VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) {
		return fp_vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
	}
#endif
#ifndef PFN_vkAcquireImageANDROID_PROXY
#define PFN_vkAcquireImageANDROID_PROXY
	VkResult acquireImageANDROID(VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) {
		return fp_vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
	}
#endif
#ifndef PFN_vkQueueSignalReleaseImageANDROID_PROXY
#define PFN_vkQueueSignalReleaseImageANDROID_PROXY
	VkResult queueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) {
		return fp_vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
	}
#endif
#ifndef PFN_vkGetSwapchainGrallocUsage2ANDROID_PROXY
#define PFN_vkGetSwapchainGrallocUsage2ANDROID_PROXY
	VkResult getSwapchainGrallocUsage2ANDROID(VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) {
		return fp_vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
	}
#endif
#endif
#if defined(VK_EXT_debug_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDebugMarkerSetObjectTagEXT_PROXY
#define PFN_vkDebugMarkerSetObjectTagEXT_PROXY
	VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* pTagInfo) {
		return fp_vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
	}
#endif
#ifndef PFN_vkDebugMarkerSetObjectNameEXT_PROXY
#define PFN_vkDebugMarkerSetObjectNameEXT_PROXY
	VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
		return fp_vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
	}
#endif
#ifndef PFN_vkCmdDebugMarkerBeginEXT_PROXY
#define PFN_vkCmdDebugMarkerBeginEXT_PROXY
	void cmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
		fp_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
	}
#endif
#ifndef PFN_vkCmdDebugMarkerEndEXT_PROXY
#define PFN_vkCmdDebugMarkerEndEXT_PROXY
	void cmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
		fp_vkCmdDebugMarkerEndEXT(commandBuffer);
	}
#endif
#ifndef PFN_vkCmdDebugMarkerInsertEXT_PROXY
#define PFN_vkCmdDebugMarkerInsertEXT_PROXY
	void cmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
		fp_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
	}
#endif
#endif
#if defined(VK_KHR_video_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateVideoSessionKHR_PROXY
#define PFN_vkCreateVideoSessionKHR_PROXY
	VkResult createVideoSessionKHR(const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) {
		return fp_vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
	}
#endif
#ifndef PFN_vkDestroyVideoSessionKHR_PROXY
#define PFN_vkDestroyVideoSessionKHR_PROXY
	void destroyVideoSessionKHR(VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
	}
#endif
#ifndef PFN_vkGetVideoSessionMemoryRequirementsKHR_PROXY
#define PFN_vkGetVideoSessionMemoryRequirementsKHR_PROXY
	VkResult getVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR videoSession, uint32_t* pVideoSessionMemoryRequirementsCount, VkVideoGetMemoryPropertiesKHR* pVideoSessionMemoryRequirements) {
		return fp_vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pVideoSessionMemoryRequirementsCount, pVideoSessionMemoryRequirements);
	}
#endif
#ifndef PFN_vkBindVideoSessionMemoryKHR_PROXY
#define PFN_vkBindVideoSessionMemoryKHR_PROXY
	VkResult bindVideoSessionMemoryKHR(VkVideoSessionKHR videoSession, uint32_t videoSessionBindMemoryCount, const VkVideoBindMemoryKHR* pVideoSessionBindMemories) {
		return fp_vkBindVideoSessionMemoryKHR(device, videoSession, videoSessionBindMemoryCount, pVideoSessionBindMemories);
	}
#endif
#ifndef PFN_vkCreateVideoSessionParametersKHR_PROXY
#define PFN_vkCreateVideoSessionParametersKHR_PROXY
	VkResult createVideoSessionParametersKHR(const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) {
		return fp_vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
	}
#endif
#ifndef PFN_vkUpdateVideoSessionParametersKHR_PROXY
#define PFN_vkUpdateVideoSessionParametersKHR_PROXY
	VkResult updateVideoSessionParametersKHR(VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) {
		return fp_vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
	}
#endif
#ifndef PFN_vkDestroyVideoSessionParametersKHR_PROXY
#define PFN_vkDestroyVideoSessionParametersKHR_PROXY
	void destroyVideoSessionParametersKHR(VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
	}
#endif
#ifndef PFN_vkCmdBeginVideoCodingKHR_PROXY
#define PFN_vkCmdBeginVideoCodingKHR_PROXY
	void cmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
		fp_vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
	}
#endif
#ifndef PFN_vkCmdEndVideoCodingKHR_PROXY
#define PFN_vkCmdEndVideoCodingKHR_PROXY
	void cmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
		fp_vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
	}
#endif
#ifndef PFN_vkCmdControlVideoCodingKHR_PROXY
#define PFN_vkCmdControlVideoCodingKHR_PROXY
	void cmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
		fp_vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
	}
#endif
#endif
#if defined(VK_KHR_video_decode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDecodeVideoKHR_PROXY
#define PFN_vkCmdDecodeVideoKHR_PROXY
	void cmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pFrameInfo) {
		fp_vkCmdDecodeVideoKHR(commandBuffer, pFrameInfo);
	}
#endif
#endif
#if defined(VK_EXT_transform_feedback) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindTransformFeedbackBuffersEXT_PROXY
#define PFN_vkCmdBindTransformFeedbackBuffersEXT_PROXY
	void cmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
		fp_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
	}
#endif
#ifndef PFN_vkCmdBeginTransformFeedbackEXT_PROXY
#define PFN_vkCmdBeginTransformFeedbackEXT_PROXY
	void cmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
		fp_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
	}
#endif
#ifndef PFN_vkCmdEndTransformFeedbackEXT_PROXY
#define PFN_vkCmdEndTransformFeedbackEXT_PROXY
	void cmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
		fp_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
	}
#endif
#ifndef PFN_vkCmdBeginQueryIndexedEXT_PROXY
#define PFN_vkCmdBeginQueryIndexedEXT_PROXY
	void cmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
		fp_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
	}
#endif
#ifndef PFN_vkCmdEndQueryIndexedEXT_PROXY
#define PFN_vkCmdEndQueryIndexedEXT_PROXY
	void cmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {
		fp_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
	}
#endif
#ifndef PFN_vkCmdDrawIndirectByteCountEXT_PROXY
#define PFN_vkCmdDrawIndirectByteCountEXT_PROXY
	void cmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
		fp_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
	}
#endif
#endif
#if defined(VK_NVX_binary_import) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateCuModuleNVX_PROXY
#define PFN_vkCreateCuModuleNVX_PROXY
	VkResult createCuModuleNVX(const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) {
		return fp_vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
	}
#endif
#ifndef PFN_vkCreateCuFunctionNVX_PROXY
#define PFN_vkCreateCuFunctionNVX_PROXY
	VkResult createCuFunctionNVX(const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) {
		return fp_vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
	}
#endif
#ifndef PFN_vkDestroyCuModuleNVX_PROXY
#define PFN_vkDestroyCuModuleNVX_PROXY
	void destroyCuModuleNVX(VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyCuModuleNVX(device, module, pAllocator);
	}
#endif
#ifndef PFN_vkDestroyCuFunctionNVX_PROXY
#define PFN_vkDestroyCuFunctionNVX_PROXY
	void destroyCuFunctionNVX(VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyCuFunctionNVX(device, function, pAllocator);
	}
#endif
#ifndef PFN_vkCmdCuLaunchKernelNVX_PROXY
#define PFN_vkCmdCuLaunchKernelNVX_PROXY
	void cmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
		fp_vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
	}
#endif
#endif
#if defined(VK_NVX_image_view_handle) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageViewHandleNVX_PROXY
#define PFN_vkGetImageViewHandleNVX_PROXY
	uint32_t getImageViewHandleNVX(const VkImageViewHandleInfoNVX* pInfo) {
		return fp_vkGetImageViewHandleNVX(device, pInfo);
	}
#endif
#ifndef PFN_vkGetImageViewAddressNVX_PROXY
#define PFN_vkGetImageViewAddressNVX_PROXY
	VkResult getImageViewAddressNVX(VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) {
		return fp_vkGetImageViewAddressNVX(device, imageView, pProperties);
	}
#endif
#endif
#if defined(VK_AMD_draw_indirect_count) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawIndirectCountAMD_PROXY
#define PFN_vkCmdDrawIndirectCountAMD_PROXY
	void cmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
		fp_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#ifndef PFN_vkCmdDrawIndexedIndirectCountAMD_PROXY
#define PFN_vkCmdDrawIndexedIndirectCountAMD_PROXY
	void cmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
		fp_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#endif
#if defined(VK_AMD_shader_info) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetShaderInfoAMD_PROXY
#define PFN_vkGetShaderInfoAMD_PROXY
	VkResult getShaderInfoAMD(VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) {
		return fp_vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
	}
#endif
#endif
#if defined(VK_NV_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleNV_PROXY
#define PFN_vkGetMemoryWin32HandleNV_PROXY
	VkResult getMemoryWin32HandleNV(VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) {
		return fp_vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
	}
#endif
#endif
#if defined(VK_KHR_device_group) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_PROXY
#define PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_PROXY
	void getDeviceGroupPeerMemoryFeaturesKHR(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
		fp_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
	}
#endif
#ifndef PFN_vkCmdSetDeviceMaskKHR_PROXY
#define PFN_vkCmdSetDeviceMaskKHR_PROXY
	void cmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
		fp_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
	}
#endif
#ifndef PFN_vkCmdDispatchBaseKHR_PROXY
#define PFN_vkCmdDispatchBaseKHR_PROXY
	void cmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
		fp_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
	}
#endif
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_PROXY
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_PROXY
	VkResult getDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
		return fp_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
	}
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_PROXY
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_PROXY
	VkResult getDeviceGroupSurfacePresentModesKHR(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) {
		return fp_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
	}
#endif
#ifndef PFN_vkAcquireNextImage2KHR_PROXY
#define PFN_vkAcquireNextImage2KHR_PROXY
	VkResult acquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) {
		return fp_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
	}
#endif
#endif
#if defined(VK_KHR_maintenance1) && defined(VK_VERSION_1_0)
#ifndef PFN_vkTrimCommandPoolKHR_PROXY
#define PFN_vkTrimCommandPoolKHR_PROXY
	void trimCommandPoolKHR(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
		fp_vkTrimCommandPoolKHR(device, commandPool, flags);
	}
#endif
#endif
#if defined(VK_KHR_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleKHR_PROXY
#define PFN_vkGetMemoryWin32HandleKHR_PROXY
	VkResult getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
		return fp_vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#ifndef PFN_vkGetMemoryWin32HandlePropertiesKHR_PROXY
#define PFN_vkGetMemoryWin32HandlePropertiesKHR_PROXY
	VkResult getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) {
		return fp_vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
	}
#endif
#endif
#if defined(VK_KHR_external_memory_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryFdKHR_PROXY
#define PFN_vkGetMemoryFdKHR_PROXY
	VkResult getMemoryFdKHR(const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
		return fp_vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#ifndef PFN_vkGetMemoryFdPropertiesKHR_PROXY
#define PFN_vkGetMemoryFdPropertiesKHR_PROXY
	VkResult getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
		return fp_vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
	}
#endif
#endif
#if defined(VK_KHR_external_semaphore_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreWin32HandleKHR_PROXY
#define PFN_vkImportSemaphoreWin32HandleKHR_PROXY
	VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) {
		return fp_vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
	}
#endif
#ifndef PFN_vkGetSemaphoreWin32HandleKHR_PROXY
#define PFN_vkGetSemaphoreWin32HandleKHR_PROXY
	VkResult getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
		return fp_vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#endif
#if defined(VK_KHR_external_semaphore_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreFdKHR_PROXY
#define PFN_vkImportSemaphoreFdKHR_PROXY
	VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
		return fp_vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
	}
#endif
#ifndef PFN_vkGetSemaphoreFdKHR_PROXY
#define PFN_vkGetSemaphoreFdKHR_PROXY
	VkResult getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
		return fp_vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdPushDescriptorSetKHR_PROXY
#define PFN_vkCmdPushDescriptorSetKHR_PROXY
	void cmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
		fp_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
	}
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
	void cmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
		fp_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
	}
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
	void cmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
		fp_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
	}
#endif
#endif
#if defined(VK_EXT_conditional_rendering) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBeginConditionalRenderingEXT_PROXY
#define PFN_vkCmdBeginConditionalRenderingEXT_PROXY
	void cmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
		fp_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
	}
#endif
#ifndef PFN_vkCmdEndConditionalRenderingEXT_PROXY
#define PFN_vkCmdEndConditionalRenderingEXT_PROXY
	void cmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
		fp_vkCmdEndConditionalRenderingEXT(commandBuffer);
	}
#endif
#endif
#if defined(VK_KHR_descriptor_update_template) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDescriptorUpdateTemplateKHR_PROXY
#define PFN_vkCreateDescriptorUpdateTemplateKHR_PROXY
	VkResult createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
		return fp_vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
	}
#endif
#ifndef PFN_vkDestroyDescriptorUpdateTemplateKHR_PROXY
#define PFN_vkDestroyDescriptorUpdateTemplateKHR_PROXY
	void destroyDescriptorUpdateTemplateKHR(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
	}
#endif
#ifndef PFN_vkUpdateDescriptorSetWithTemplateKHR_PROXY
#define PFN_vkUpdateDescriptorSetWithTemplateKHR_PROXY
	void updateDescriptorSetWithTemplateKHR(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
		fp_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
	}
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_PROXY
	void cmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
		fp_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
	}
#endif
#endif
#if defined(VK_NV_clip_space_w_scaling) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetViewportWScalingNV_PROXY
#define PFN_vkCmdSetViewportWScalingNV_PROXY
	void cmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
		fp_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
	}
#endif
#endif
#if defined(VK_EXT_display_control) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDisplayPowerControlEXT_PROXY
#define PFN_vkDisplayPowerControlEXT_PROXY
	VkResult displayPowerControlEXT(VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
		return fp_vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
	}
#endif
#ifndef PFN_vkRegisterDeviceEventEXT_PROXY
#define PFN_vkRegisterDeviceEventEXT_PROXY
	VkResult registerDeviceEventEXT(const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
		return fp_vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
	}
#endif
#ifndef PFN_vkRegisterDisplayEventEXT_PROXY
#define PFN_vkRegisterDisplayEventEXT_PROXY
	VkResult registerDisplayEventEXT(VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
		return fp_vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
	}
#endif
#ifndef PFN_vkGetSwapchainCounterEXT_PROXY
#define PFN_vkGetSwapchainCounterEXT_PROXY
	VkResult getSwapchainCounterEXT(VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
		return fp_vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
	}
#endif
#endif
#if defined(VK_GOOGLE_display_timing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetRefreshCycleDurationGOOGLE_PROXY
#define PFN_vkGetRefreshCycleDurationGOOGLE_PROXY
	VkResult getRefreshCycleDurationGOOGLE(VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) {
		return fp_vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
	}
#endif
#ifndef PFN_vkGetPastPresentationTimingGOOGLE_PROXY
#define PFN_vkGetPastPresentationTimingGOOGLE_PROXY
	VkResult getPastPresentationTimingGOOGLE(VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) {
		return fp_vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
	}
#endif
#endif
#if defined(VK_EXT_discard_rectangles) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetDiscardRectangleEXT_PROXY
#define PFN_vkCmdSetDiscardRectangleEXT_PROXY
	void cmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
		fp_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
	}
#endif
#endif
#if defined(VK_EXT_hdr_metadata) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetHdrMetadataEXT_PROXY
#define PFN_vkSetHdrMetadataEXT_PROXY
	void setHdrMetadataEXT(uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) {
		fp_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
	}
#endif
#endif
#if defined(VK_KHR_create_renderpass2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateRenderPass2KHR_PROXY
#define PFN_vkCreateRenderPass2KHR_PROXY
	VkResult createRenderPass2KHR(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
		return fp_vkCreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
	}
#endif
#ifndef PFN_vkCmdBeginRenderPass2KHR_PROXY
#define PFN_vkCmdBeginRenderPass2KHR_PROXY
	void cmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
		fp_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
	}
#endif
#ifndef PFN_vkCmdNextSubpass2KHR_PROXY
#define PFN_vkCmdNextSubpass2KHR_PROXY
	void cmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
		fp_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
	}
#endif
#ifndef PFN_vkCmdEndRenderPass2KHR_PROXY
#define PFN_vkCmdEndRenderPass2KHR_PROXY
	void cmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
		fp_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
	}
#endif
#endif
#if defined(VK_KHR_shared_presentable_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainStatusKHR_PROXY
#define PFN_vkGetSwapchainStatusKHR_PROXY
	VkResult getSwapchainStatusKHR(VkSwapchainKHR swapchain) {
		return fp_vkGetSwapchainStatusKHR(device, swapchain);
	}
#endif
#endif
#if defined(VK_KHR_external_fence_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceWin32HandleKHR_PROXY
#define PFN_vkImportFenceWin32HandleKHR_PROXY
	VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) {
		return fp_vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
	}
#endif
#ifndef PFN_vkGetFenceWin32HandleKHR_PROXY
#define PFN_vkGetFenceWin32HandleKHR_PROXY
	VkResult getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
		return fp_vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#endif
#if defined(VK_KHR_external_fence_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceFdKHR_PROXY
#define PFN_vkImportFenceFdKHR_PROXY
	VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
		return fp_vkImportFenceFdKHR(device, pImportFenceFdInfo);
	}
#endif
#ifndef PFN_vkGetFenceFdKHR_PROXY
#define PFN_vkGetFenceFdKHR_PROXY
	VkResult getFenceFdKHR(const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
		return fp_vkGetFenceFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#endif
#if defined(VK_KHR_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireProfilingLockKHR_PROXY
#define PFN_vkAcquireProfilingLockKHR_PROXY
	VkResult acquireProfilingLockKHR(const VkAcquireProfilingLockInfoKHR* pInfo) {
		return fp_vkAcquireProfilingLockKHR(device, pInfo);
	}
#endif
#ifndef PFN_vkReleaseProfilingLockKHR_PROXY
#define PFN_vkReleaseProfilingLockKHR_PROXY
	void releaseProfilingLockKHR() {
		fp_vkReleaseProfilingLockKHR(device);
	}
#endif
#endif
#if defined(VK_EXT_debug_utils) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetDebugUtilsObjectNameEXT_PROXY
#define PFN_vkSetDebugUtilsObjectNameEXT_PROXY
	VkResult setDebugUtilsObjectNameEXT(const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
		return fp_vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
	}
#endif
#ifndef PFN_vkSetDebugUtilsObjectTagEXT_PROXY
#define PFN_vkSetDebugUtilsObjectTagEXT_PROXY
	VkResult setDebugUtilsObjectTagEXT(const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
		return fp_vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
	}
#endif
#ifndef PFN_vkQueueBeginDebugUtilsLabelEXT_PROXY
#define PFN_vkQueueBeginDebugUtilsLabelEXT_PROXY
	void queueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
		fp_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
	}
#endif
#ifndef PFN_vkQueueEndDebugUtilsLabelEXT_PROXY
#define PFN_vkQueueEndDebugUtilsLabelEXT_PROXY
	void queueEndDebugUtilsLabelEXT(VkQueue queue) {
		fp_vkQueueEndDebugUtilsLabelEXT(queue);
	}
#endif
#ifndef PFN_vkQueueInsertDebugUtilsLabelEXT_PROXY
#define PFN_vkQueueInsertDebugUtilsLabelEXT_PROXY
	void queueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
		fp_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
	}
#endif
#ifndef PFN_vkCmdBeginDebugUtilsLabelEXT_PROXY
#define PFN_vkCmdBeginDebugUtilsLabelEXT_PROXY
	void cmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
		fp_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	}
#endif
#ifndef PFN_vkCmdEndDebugUtilsLabelEXT_PROXY
#define PFN_vkCmdEndDebugUtilsLabelEXT_PROXY
	void cmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
		fp_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
	}
#endif
#ifndef PFN_vkCmdInsertDebugUtilsLabelEXT_PROXY
#define PFN_vkCmdInsertDebugUtilsLabelEXT_PROXY
	void cmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
		fp_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	}
#endif
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetAndroidHardwareBufferPropertiesANDROID_PROXY
#define PFN_vkGetAndroidHardwareBufferPropertiesANDROID_PROXY
	VkResult getAndroidHardwareBufferPropertiesANDROID(AHardwareBuffer buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
		return fp_vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
	}
#endif
#ifndef PFN_vkGetMemoryAndroidHardwareBufferANDROID_PROXY
#define PFN_vkGetMemoryAndroidHardwareBufferANDROID_PROXY
	VkResult getMemoryAndroidHardwareBufferANDROID(const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, AHardwareBuffer pBuffer) {
		return fp_vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
	}
#endif
#endif
#if defined(VK_EXT_sample_locations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetSampleLocationsEXT_PROXY
#define PFN_vkCmdSetSampleLocationsEXT_PROXY
	void cmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
		fp_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
	}
#endif
#endif
#if defined(VK_KHR_get_memory_requirements2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageMemoryRequirements2KHR_PROXY
#define PFN_vkGetImageMemoryRequirements2KHR_PROXY
	void getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
		fp_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
	}
#endif
#ifndef PFN_vkGetBufferMemoryRequirements2KHR_PROXY
#define PFN_vkGetBufferMemoryRequirements2KHR_PROXY
	void getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
		fp_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
	}
#endif
#ifndef PFN_vkGetImageSparseMemoryRequirements2KHR_PROXY
#define PFN_vkGetImageSparseMemoryRequirements2KHR_PROXY
	void getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
		fp_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
#endif
#endif
#if defined(VK_KHR_acceleration_structure) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureKHR_PROXY
#define PFN_vkCreateAccelerationStructureKHR_PROXY
	VkResult createAccelerationStructureKHR(const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) {
		return fp_vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
	}
#endif
#ifndef PFN_vkDestroyAccelerationStructureKHR_PROXY
#define PFN_vkDestroyAccelerationStructureKHR_PROXY
	void destroyAccelerationStructureKHR(VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
	}
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresKHR_PROXY
#define PFN_vkCmdBuildAccelerationStructuresKHR_PROXY
	void cmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
		fp_vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
	}
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresIndirectKHR_PROXY
#define PFN_vkCmdBuildAccelerationStructuresIndirectKHR_PROXY
	void cmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) {
		fp_vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
	}
#endif
#ifndef PFN_vkBuildAccelerationStructuresKHR_PROXY
#define PFN_vkBuildAccelerationStructuresKHR_PROXY
	VkResult buildAccelerationStructuresKHR(VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
		return fp_vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
	}
#endif
#ifndef PFN_vkCopyAccelerationStructureKHR_PROXY
#define PFN_vkCopyAccelerationStructureKHR_PROXY
	VkResult copyAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) {
		return fp_vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
	}
#endif
#ifndef PFN_vkCopyAccelerationStructureToMemoryKHR_PROXY
#define PFN_vkCopyAccelerationStructureToMemoryKHR_PROXY
	VkResult copyAccelerationStructureToMemoryKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
		return fp_vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
	}
#endif
#ifndef PFN_vkCopyMemoryToAccelerationStructureKHR_PROXY
#define PFN_vkCopyMemoryToAccelerationStructureKHR_PROXY
	VkResult copyMemoryToAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
		return fp_vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
	}
#endif
#ifndef PFN_vkWriteAccelerationStructuresPropertiesKHR_PROXY
#define PFN_vkWriteAccelerationStructuresPropertiesKHR_PROXY
	VkResult writeAccelerationStructuresPropertiesKHR(uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) {
		return fp_vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
	}
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureKHR_PROXY
#define PFN_vkCmdCopyAccelerationStructureKHR_PROXY
	void cmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
		fp_vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
	}
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureToMemoryKHR_PROXY
#define PFN_vkCmdCopyAccelerationStructureToMemoryKHR_PROXY
	void cmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
		fp_vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
	}
#endif
#ifndef PFN_vkCmdCopyMemoryToAccelerationStructureKHR_PROXY
#define PFN_vkCmdCopyMemoryToAccelerationStructureKHR_PROXY
	void cmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
		fp_vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
	}
#endif
#ifndef PFN_vkGetAccelerationStructureDeviceAddressKHR_PROXY
#define PFN_vkGetAccelerationStructureDeviceAddressKHR_PROXY
	VkDeviceAddress getAccelerationStructureDeviceAddressKHR(const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) {
		return fp_vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
	}
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_PROXY
#define PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_PROXY
	void cmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
		fp_vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
	}
#endif
#ifndef PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_PROXY
#define PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_PROXY
	void getDeviceAccelerationStructureCompatibilityKHR(const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
		fp_vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
	}
#endif
#ifndef PFN_vkGetAccelerationStructureBuildSizesKHR_PROXY
#define PFN_vkGetAccelerationStructureBuildSizesKHR_PROXY
	void getAccelerationStructureBuildSizesKHR(VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
		fp_vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
	}
#endif
#endif
#if defined(VK_KHR_ray_tracing_pipeline) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdTraceRaysKHR_PROXY
#define PFN_vkCmdTraceRaysKHR_PROXY
	void cmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
		fp_vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
	}
#endif
#ifndef PFN_vkCreateRayTracingPipelinesKHR_PROXY
#define PFN_vkCreateRayTracingPipelinesKHR_PROXY
	VkResult createRayTracingPipelinesKHR(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
		return fp_vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesKHR_PROXY
#define PFN_vkGetRayTracingShaderGroupHandlesKHR_PROXY
	VkResult getRayTracingShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
		return fp_vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#ifndef PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_PROXY
#define PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_PROXY
	VkResult getRayTracingCaptureReplayShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
		return fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#ifndef PFN_vkCmdTraceRaysIndirectKHR_PROXY
#define PFN_vkCmdTraceRaysIndirectKHR_PROXY
	void cmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
		fp_vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
	}
#endif
#ifndef PFN_vkGetRayTracingShaderGroupStackSizeKHR_PROXY
#define PFN_vkGetRayTracingShaderGroupStackSizeKHR_PROXY
	VkDeviceSize getRayTracingShaderGroupStackSizeKHR(VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) {
		return fp_vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
	}
#endif
#ifndef PFN_vkCmdSetRayTracingPipelineStackSizeKHR_PROXY
#define PFN_vkCmdSetRayTracingPipelineStackSizeKHR_PROXY
	void cmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
		fp_vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
	}
#endif
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSamplerYcbcrConversionKHR_PROXY
#define PFN_vkCreateSamplerYcbcrConversionKHR_PROXY
	VkResult createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
		return fp_vkCreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
	}
#endif
#ifndef PFN_vkDestroySamplerYcbcrConversionKHR_PROXY
#define PFN_vkDestroySamplerYcbcrConversionKHR_PROXY
	void destroySamplerYcbcrConversionKHR(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
	}
#endif
#endif
#if defined(VK_KHR_bind_memory2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkBindBufferMemory2KHR_PROXY
#define PFN_vkBindBufferMemory2KHR_PROXY
	VkResult bindBufferMemory2KHR(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
		return fp_vkBindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
	}
#endif
#ifndef PFN_vkBindImageMemory2KHR_PROXY
#define PFN_vkBindImageMemory2KHR_PROXY
	VkResult bindImageMemory2KHR(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
		return fp_vkBindImageMemory2KHR(device, bindInfoCount, pBindInfos);
	}
#endif
#endif
#if defined(VK_EXT_image_drm_format_modifier) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageDrmFormatModifierPropertiesEXT_PROXY
#define PFN_vkGetImageDrmFormatModifierPropertiesEXT_PROXY
	VkResult getImageDrmFormatModifierPropertiesEXT(VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) {
		return fp_vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
	}
#endif
#endif
#if defined(VK_EXT_validation_cache) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateValidationCacheEXT_PROXY
#define PFN_vkCreateValidationCacheEXT_PROXY
	VkResult createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) {
		return fp_vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
	}
#endif
#ifndef PFN_vkDestroyValidationCacheEXT_PROXY
#define PFN_vkDestroyValidationCacheEXT_PROXY
	void destroyValidationCacheEXT(VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
	}
#endif
#ifndef PFN_vkMergeValidationCachesEXT_PROXY
#define PFN_vkMergeValidationCachesEXT_PROXY
	VkResult mergeValidationCachesEXT(VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) {
		return fp_vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
	}
#endif
#ifndef PFN_vkGetValidationCacheDataEXT_PROXY
#define PFN_vkGetValidationCacheDataEXT_PROXY
	VkResult getValidationCacheDataEXT(VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) {
		return fp_vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
	}
#endif
#endif
#if defined(VK_NV_shading_rate_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindShadingRateImageNV_PROXY
#define PFN_vkCmdBindShadingRateImageNV_PROXY
	void cmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
		fp_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
	}
#endif
#ifndef PFN_vkCmdSetViewportShadingRatePaletteNV_PROXY
#define PFN_vkCmdSetViewportShadingRatePaletteNV_PROXY
	void cmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) {
		fp_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
	}
#endif
#ifndef PFN_vkCmdSetCoarseSampleOrderNV_PROXY
#define PFN_vkCmdSetCoarseSampleOrderNV_PROXY
	void cmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
		fp_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
	}
#endif
#endif
#if defined(VK_NV_ray_tracing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureNV_PROXY
#define PFN_vkCreateAccelerationStructureNV_PROXY
	VkResult createAccelerationStructureNV(const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) {
		return fp_vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
	}
#endif
#ifndef PFN_vkDestroyAccelerationStructureNV_PROXY
#define PFN_vkDestroyAccelerationStructureNV_PROXY
	void destroyAccelerationStructureNV(VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
	}
#endif
#ifndef PFN_vkGetAccelerationStructureMemoryRequirementsNV_PROXY
#define PFN_vkGetAccelerationStructureMemoryRequirementsNV_PROXY
	void getAccelerationStructureMemoryRequirementsNV(const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) {
		fp_vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
	}
#endif
#ifndef PFN_vkBindAccelerationStructureMemoryNV_PROXY
#define PFN_vkBindAccelerationStructureMemoryNV_PROXY
	VkResult bindAccelerationStructureMemoryNV(uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) {
		return fp_vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
	}
#endif
#ifndef PFN_vkCmdBuildAccelerationStructureNV_PROXY
#define PFN_vkCmdBuildAccelerationStructureNV_PROXY
	void cmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {
		fp_vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
	}
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureNV_PROXY
#define PFN_vkCmdCopyAccelerationStructureNV_PROXY
	void cmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
		fp_vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
	}
#endif
#ifndef PFN_vkCmdTraceRaysNV_PROXY
#define PFN_vkCmdTraceRaysNV_PROXY
	void cmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
		fp_vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
	}
#endif
#ifndef PFN_vkCreateRayTracingPipelinesNV_PROXY
#define PFN_vkCreateRayTracingPipelinesNV_PROXY
	VkResult createRayTracingPipelinesNV(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
		return fp_vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesNV_PROXY
#define PFN_vkGetRayTracingShaderGroupHandlesNV_PROXY
	VkResult getRayTracingShaderGroupHandlesNV(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
		return fp_vkGetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#ifndef PFN_vkGetAccelerationStructureHandleNV_PROXY
#define PFN_vkGetAccelerationStructureHandleNV_PROXY
	VkResult getAccelerationStructureHandleNV(VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) {
		return fp_vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
	}
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesNV_PROXY
#define PFN_vkCmdWriteAccelerationStructuresPropertiesNV_PROXY
	void cmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
		fp_vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
	}
#endif
#ifndef PFN_vkCompileDeferredNV_PROXY
#define PFN_vkCompileDeferredNV_PROXY
	VkResult compileDeferredNV(VkPipeline pipeline, uint32_t shader) {
		return fp_vkCompileDeferredNV(device, pipeline, shader);
	}
#endif
#endif
#if defined(VK_KHR_maintenance3) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDescriptorSetLayoutSupportKHR_PROXY
#define PFN_vkGetDescriptorSetLayoutSupportKHR_PROXY
	void getDescriptorSetLayoutSupportKHR(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
		fp_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
	}
#endif
#endif
#if defined(VK_EXT_external_memory_host) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryHostPointerPropertiesEXT_PROXY
#define PFN_vkGetMemoryHostPointerPropertiesEXT_PROXY
	VkResult getMemoryHostPointerPropertiesEXT(VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
		return fp_vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
	}
#endif
#endif
#if defined(VK_AMD_buffer_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdWriteBufferMarkerAMD_PROXY
#define PFN_vkCmdWriteBufferMarkerAMD_PROXY
	void cmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
		fp_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
	}
#endif
#endif
#if defined(VK_EXT_calibrated_timestamps) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetCalibratedTimestampsEXT_PROXY
#define PFN_vkGetCalibratedTimestampsEXT_PROXY
	VkResult getCalibratedTimestampsEXT(uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
		return fp_vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
	}
#endif
#endif
#if defined(VK_NV_mesh_shader) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawMeshTasksNV_PROXY
#define PFN_vkCmdDrawMeshTasksNV_PROXY
	void cmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
		fp_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
	}
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectNV_PROXY
#define PFN_vkCmdDrawMeshTasksIndirectNV_PROXY
	void cmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
		fp_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
	}
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectCountNV_PROXY
#define PFN_vkCmdDrawMeshTasksIndirectCountNV_PROXY
	void cmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
		fp_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#endif
#if defined(VK_NV_scissor_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetExclusiveScissorNV_PROXY
#define PFN_vkCmdSetExclusiveScissorNV_PROXY
	void cmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
		fp_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
	}
#endif
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCheckpointNV_PROXY
#define PFN_vkCmdSetCheckpointNV_PROXY
	void cmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
		fp_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
	}
#endif
#ifndef PFN_vkGetQueueCheckpointDataNV_PROXY
#define PFN_vkGetQueueCheckpointDataNV_PROXY
	void getQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) {
		fp_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
	}
#endif
#endif
#if defined(VK_KHR_timeline_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSemaphoreCounterValueKHR_PROXY
#define PFN_vkGetSemaphoreCounterValueKHR_PROXY
	VkResult getSemaphoreCounterValueKHR(VkSemaphore semaphore, uint64_t* pValue) {
		return fp_vkGetSemaphoreCounterValueKHR(device, semaphore, pValue);
	}
#endif
#ifndef PFN_vkWaitSemaphoresKHR_PROXY
#define PFN_vkWaitSemaphoresKHR_PROXY
	VkResult waitSemaphoresKHR(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
		return fp_vkWaitSemaphoresKHR(device, pWaitInfo, timeout);
	}
#endif
#ifndef PFN_vkSignalSemaphoreKHR_PROXY
#define PFN_vkSignalSemaphoreKHR_PROXY
	VkResult signalSemaphoreKHR(const VkSemaphoreSignalInfo* pSignalInfo) {
		return fp_vkSignalSemaphoreKHR(device, pSignalInfo);
	}
#endif
#endif
#if defined(VK_INTEL_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkInitializePerformanceApiINTEL_PROXY
#define PFN_vkInitializePerformanceApiINTEL_PROXY
	VkResult initializePerformanceApiINTEL(const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) {
		return fp_vkInitializePerformanceApiINTEL(device, pInitializeInfo);
	}
#endif
#ifndef PFN_vkUninitializePerformanceApiINTEL_PROXY
#define PFN_vkUninitializePerformanceApiINTEL_PROXY
	void uninitializePerformanceApiINTEL() {
		fp_vkUninitializePerformanceApiINTEL(device);
	}
#endif
#ifndef PFN_vkCmdSetPerformanceMarkerINTEL_PROXY
#define PFN_vkCmdSetPerformanceMarkerINTEL_PROXY
	VkResult cmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
		return fp_vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
	}
#endif
#ifndef PFN_vkCmdSetPerformanceStreamMarkerINTEL_PROXY
#define PFN_vkCmdSetPerformanceStreamMarkerINTEL_PROXY
	VkResult cmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
		return fp_vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
	}
#endif
#ifndef PFN_vkCmdSetPerformanceOverrideINTEL_PROXY
#define PFN_vkCmdSetPerformanceOverrideINTEL_PROXY
	VkResult cmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
		return fp_vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
	}
#endif
#ifndef PFN_vkAcquirePerformanceConfigurationINTEL_PROXY
#define PFN_vkAcquirePerformanceConfigurationINTEL_PROXY
	VkResult acquirePerformanceConfigurationINTEL(const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) {
		return fp_vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
	}
#endif
#ifndef PFN_vkReleasePerformanceConfigurationINTEL_PROXY
#define PFN_vkReleasePerformanceConfigurationINTEL_PROXY
	VkResult releasePerformanceConfigurationINTEL(VkPerformanceConfigurationINTEL configuration) {
		return fp_vkReleasePerformanceConfigurationINTEL(device, configuration);
	}
#endif
#ifndef PFN_vkQueueSetPerformanceConfigurationINTEL_PROXY
#define PFN_vkQueueSetPerformanceConfigurationINTEL_PROXY
	VkResult queueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) {
		return fp_vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
	}
#endif
#ifndef PFN_vkGetPerformanceParameterINTEL_PROXY
#define PFN_vkGetPerformanceParameterINTEL_PROXY
	VkResult getPerformanceParameterINTEL(VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) {
		return fp_vkGetPerformanceParameterINTEL(device, parameter, pValue);
	}
#endif
#endif
#if defined(VK_AMD_display_native_hdr) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetLocalDimmingAMD_PROXY
#define PFN_vkSetLocalDimmingAMD_PROXY
	void setLocalDimmingAMD(VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {
		fp_vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
	}
#endif
#endif
#if defined(VK_KHR_fragment_shading_rate) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateKHR_PROXY
#define PFN_vkCmdSetFragmentShadingRateKHR_PROXY
	void cmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
		fp_vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
	}
#endif
#endif
#if defined(VK_EXT_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferDeviceAddressEXT_PROXY
#define PFN_vkGetBufferDeviceAddressEXT_PROXY
	VkDeviceAddress getBufferDeviceAddressEXT(const VkBufferDeviceAddressInfo* pInfo) {
		return fp_vkGetBufferDeviceAddressEXT(device, pInfo);
	}
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireFullScreenExclusiveModeEXT_PROXY
#define PFN_vkAcquireFullScreenExclusiveModeEXT_PROXY
	VkResult acquireFullScreenExclusiveModeEXT(VkSwapchainKHR swapchain) {
		return fp_vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
	}
#endif
#ifndef PFN_vkReleaseFullScreenExclusiveModeEXT_PROXY
#define PFN_vkReleaseFullScreenExclusiveModeEXT_PROXY
	VkResult releaseFullScreenExclusiveModeEXT(VkSwapchainKHR swapchain) {
		return fp_vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
	}
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_PROXY
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_PROXY
	VkResult getDeviceGroupSurfacePresentModes2EXT(const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) {
		return fp_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
	}
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_PROXY
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_PROXY
	VkResult getDeviceGroupSurfacePresentModes2EXT(const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) {
		return fp_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
	}
#endif
#endif
#if defined(VK_KHR_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferOpaqueCaptureAddressKHR_PROXY
#define PFN_vkGetBufferOpaqueCaptureAddressKHR_PROXY
	uint64_t getBufferOpaqueCaptureAddressKHR(const VkBufferDeviceAddressInfo* pInfo) {
		return fp_vkGetBufferOpaqueCaptureAddressKHR(device, pInfo);
	}
#endif
#ifndef PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_PROXY
#define PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_PROXY
	uint64_t getDeviceMemoryOpaqueCaptureAddressKHR(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
		return fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
	}
#endif
#endif
#if defined(VK_EXT_line_rasterization) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetLineStippleEXT_PROXY
#define PFN_vkCmdSetLineStippleEXT_PROXY
	void cmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
		fp_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
	}
#endif
#endif
#if defined(VK_EXT_host_query_reset) && defined(VK_VERSION_1_0)
#ifndef PFN_vkResetQueryPoolEXT_PROXY
#define PFN_vkResetQueryPoolEXT_PROXY
	void resetQueryPoolEXT(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
		fp_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
	}
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCullModeEXT_PROXY
#define PFN_vkCmdSetCullModeEXT_PROXY
	void cmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
		fp_vkCmdSetCullModeEXT(commandBuffer, cullMode);
	}
#endif
#ifndef PFN_vkCmdSetFrontFaceEXT_PROXY
#define PFN_vkCmdSetFrontFaceEXT_PROXY
	void cmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
		fp_vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
	}
#endif
#ifndef PFN_vkCmdSetPrimitiveTopologyEXT_PROXY
#define PFN_vkCmdSetPrimitiveTopologyEXT_PROXY
	void cmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
		fp_vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
	}
#endif
#ifndef PFN_vkCmdSetViewportWithCountEXT_PROXY
#define PFN_vkCmdSetViewportWithCountEXT_PROXY
	void cmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
		fp_vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
	}
#endif
#ifndef PFN_vkCmdSetScissorWithCountEXT_PROXY
#define PFN_vkCmdSetScissorWithCountEXT_PROXY
	void cmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
		fp_vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
	}
#endif
#ifndef PFN_vkCmdBindVertexBuffers2EXT_PROXY
#define PFN_vkCmdBindVertexBuffers2EXT_PROXY
	void cmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
		fp_vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
	}
#endif
#ifndef PFN_vkCmdSetDepthTestEnableEXT_PROXY
#define PFN_vkCmdSetDepthTestEnableEXT_PROXY
	void cmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
		fp_vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
	}
#endif
#ifndef PFN_vkCmdSetDepthWriteEnableEXT_PROXY
#define PFN_vkCmdSetDepthWriteEnableEXT_PROXY
	void cmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
		fp_vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
	}
#endif
#ifndef PFN_vkCmdSetDepthCompareOpEXT_PROXY
#define PFN_vkCmdSetDepthCompareOpEXT_PROXY
	void cmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
		fp_vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
	}
#endif
#ifndef PFN_vkCmdSetDepthBoundsTestEnableEXT_PROXY
#define PFN_vkCmdSetDepthBoundsTestEnableEXT_PROXY
	void cmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
		fp_vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
	}
#endif
#ifndef PFN_vkCmdSetStencilTestEnableEXT_PROXY
#define PFN_vkCmdSetStencilTestEnableEXT_PROXY
	void cmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
		fp_vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
	}
#endif
#ifndef PFN_vkCmdSetStencilOpEXT_PROXY
#define PFN_vkCmdSetStencilOpEXT_PROXY
	void cmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
		fp_vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
	}
#endif
#endif
#if defined(VK_KHR_deferred_host_operations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDeferredOperationKHR_PROXY
#define PFN_vkCreateDeferredOperationKHR_PROXY
	VkResult createDeferredOperationKHR(const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) {
		return fp_vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
	}
#endif
#ifndef PFN_vkDestroyDeferredOperationKHR_PROXY
#define PFN_vkDestroyDeferredOperationKHR_PROXY
	void destroyDeferredOperationKHR(VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyDeferredOperationKHR(device, operation, pAllocator);
	}
#endif
#ifndef PFN_vkGetDeferredOperationMaxConcurrencyKHR_PROXY
#define PFN_vkGetDeferredOperationMaxConcurrencyKHR_PROXY
	uint32_t getDeferredOperationMaxConcurrencyKHR(VkDeferredOperationKHR operation) {
		return fp_vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
	}
#endif
#ifndef PFN_vkGetDeferredOperationResultKHR_PROXY
#define PFN_vkGetDeferredOperationResultKHR_PROXY
	VkResult getDeferredOperationResultKHR(VkDeferredOperationKHR operation) {
		return fp_vkGetDeferredOperationResultKHR(device, operation);
	}
#endif
#ifndef PFN_vkDeferredOperationJoinKHR_PROXY
#define PFN_vkDeferredOperationJoinKHR_PROXY
	VkResult deferredOperationJoinKHR(VkDeferredOperationKHR operation) {
		return fp_vkDeferredOperationJoinKHR(device, operation);
	}
#endif
#endif
#if defined(VK_KHR_pipeline_executable_properties) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetPipelineExecutablePropertiesKHR_PROXY
#define PFN_vkGetPipelineExecutablePropertiesKHR_PROXY
	VkResult getPipelineExecutablePropertiesKHR(const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) {
		return fp_vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
	}
#endif
#ifndef PFN_vkGetPipelineExecutableStatisticsKHR_PROXY
#define PFN_vkGetPipelineExecutableStatisticsKHR_PROXY
	VkResult getPipelineExecutableStatisticsKHR(const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) {
		return fp_vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
	}
#endif
#ifndef PFN_vkGetPipelineExecutableInternalRepresentationsKHR_PROXY
#define PFN_vkGetPipelineExecutableInternalRepresentationsKHR_PROXY
	VkResult getPipelineExecutableInternalRepresentationsKHR(const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) {
		return fp_vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
	}
#endif
#endif
#if defined(VK_NV_device_generated_commands) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetGeneratedCommandsMemoryRequirementsNV_PROXY
#define PFN_vkGetGeneratedCommandsMemoryRequirementsNV_PROXY
	void getGeneratedCommandsMemoryRequirementsNV(const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
		fp_vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
	}
#endif
#ifndef PFN_vkCmdPreprocessGeneratedCommandsNV_PROXY
#define PFN_vkCmdPreprocessGeneratedCommandsNV_PROXY
	void cmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
		fp_vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
	}
#endif
#ifndef PFN_vkCmdExecuteGeneratedCommandsNV_PROXY
#define PFN_vkCmdExecuteGeneratedCommandsNV_PROXY
	void cmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
		fp_vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
	}
#endif
#ifndef PFN_vkCmdBindPipelineShaderGroupNV_PROXY
#define PFN_vkCmdBindPipelineShaderGroupNV_PROXY
	void cmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
		fp_vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
	}
#endif
#ifndef PFN_vkCreateIndirectCommandsLayoutNV_PROXY
#define PFN_vkCreateIndirectCommandsLayoutNV_PROXY
	VkResult createIndirectCommandsLayoutNV(const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) {
		return fp_vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
	}
#endif
#ifndef PFN_vkDestroyIndirectCommandsLayoutNV_PROXY
#define PFN_vkDestroyIndirectCommandsLayoutNV_PROXY
	void destroyIndirectCommandsLayoutNV(VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
	}
#endif
#endif
#if defined(VK_EXT_private_data) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreatePrivateDataSlotEXT_PROXY
#define PFN_vkCreatePrivateDataSlotEXT_PROXY
	VkResult createPrivateDataSlotEXT(const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot) {
		return fp_vkCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
	}
#endif
#ifndef PFN_vkDestroyPrivateDataSlotEXT_PROXY
#define PFN_vkDestroyPrivateDataSlotEXT_PROXY
	void destroyPrivateDataSlotEXT(VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator) {
		fp_vkDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
	}
#endif
#ifndef PFN_vkSetPrivateDataEXT_PROXY
#define PFN_vkSetPrivateDataEXT_PROXY
	VkResult setPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data) {
		return fp_vkSetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
	}
#endif
#ifndef PFN_vkGetPrivateDataEXT_PROXY
#define PFN_vkGetPrivateDataEXT_PROXY
	void getPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData) {
		fp_vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
	}
#endif
#endif
#if defined(VK_KHR_video_encode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdEncodeVideoKHR_PROXY
#define PFN_vkCmdEncodeVideoKHR_PROXY
	void cmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
		fp_vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
	}
#endif
#endif
#if defined(VK_KHR_synchronization2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetEvent2KHR_PROXY
#define PFN_vkCmdSetEvent2KHR_PROXY
	void cmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfoKHR* pDependencyInfo) {
		fp_vkCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
	}
#endif
#ifndef PFN_vkCmdResetEvent2KHR_PROXY
#define PFN_vkCmdResetEvent2KHR_PROXY
	void cmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2KHR stageMask) {
		fp_vkCmdResetEvent2KHR(commandBuffer, event, stageMask);
	}
#endif
#ifndef PFN_vkCmdWaitEvents2KHR_PROXY
#define PFN_vkCmdWaitEvents2KHR_PROXY
	void cmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfoKHR* pDependencyInfos) {
		fp_vkCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
	}
#endif
#ifndef PFN_vkCmdPipelineBarrier2KHR_PROXY
#define PFN_vkCmdPipelineBarrier2KHR_PROXY
	void cmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo) {
		fp_vkCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
	}
#endif
#ifndef PFN_vkCmdWriteTimestamp2KHR_PROXY
#define PFN_vkCmdWriteTimestamp2KHR_PROXY
	void cmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkQueryPool queryPool, uint32_t query) {
		fp_vkCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
	}
#endif
#ifndef PFN_vkQueueSubmit2KHR_PROXY
#define PFN_vkQueueSubmit2KHR_PROXY
	VkResult queueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2KHR* pSubmits, VkFence fence) {
		return fp_vkQueueSubmit2KHR(queue, submitCount, pSubmits, fence);
	}
#endif
#ifndef PFN_vkCmdWriteBufferMarker2AMD_PROXY
#define PFN_vkCmdWriteBufferMarker2AMD_PROXY
	void cmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
		fp_vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
	}
#endif
#ifndef PFN_vkGetQueueCheckpointData2NV_PROXY
#define PFN_vkGetQueueCheckpointData2NV_PROXY
	void getQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) {
		fp_vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
	}
#endif
#endif
#if defined(VK_NV_fragment_shading_rate_enums) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateEnumNV_PROXY
#define PFN_vkCmdSetFragmentShadingRateEnumNV_PROXY
	void cmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
		fp_vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
	}
#endif
#endif
#if defined(VK_KHR_copy_commands2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdCopyBuffer2KHR_PROXY
#define PFN_vkCmdCopyBuffer2KHR_PROXY
	void cmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) {
		fp_vkCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
	}
#endif
#ifndef PFN_vkCmdCopyImage2KHR_PROXY
#define PFN_vkCmdCopyImage2KHR_PROXY
	void cmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) {
		fp_vkCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
	}
#endif
#ifndef PFN_vkCmdCopyBufferToImage2KHR_PROXY
#define PFN_vkCmdCopyBufferToImage2KHR_PROXY
	void cmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) {
		fp_vkCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
	}
#endif
#ifndef PFN_vkCmdCopyImageToBuffer2KHR_PROXY
#define PFN_vkCmdCopyImageToBuffer2KHR_PROXY
	void cmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) {
		fp_vkCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
	}
#endif
#ifndef PFN_vkCmdBlitImage2KHR_PROXY
#define PFN_vkCmdBlitImage2KHR_PROXY
	void cmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) {
		fp_vkCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
	}
#endif
#ifndef PFN_vkCmdResolveImage2KHR_PROXY
#define PFN_vkCmdResolveImage2KHR_PROXY
	void cmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) {
		fp_vkCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
	}
#endif
#endif
#if defined(VK_EXT_vertex_input_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetVertexInputEXT_PROXY
#define PFN_vkCmdSetVertexInputEXT_PROXY
	void cmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
		fp_vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
	}
#endif
#endif
#if defined(VK_FUCHSIA_external_memory) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryZirconHandleFUCHSIA_PROXY
#define PFN_vkGetMemoryZirconHandleFUCHSIA_PROXY
	VkResult getMemoryZirconHandleFUCHSIA(const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
		return fp_vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
	}
#endif
#ifndef PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_PROXY
#define PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_PROXY
	VkResult getMemoryZirconHandlePropertiesFUCHSIA(VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) {
		return fp_vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
	}
#endif
#endif
#if defined(VK_FUCHSIA_external_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreZirconHandleFUCHSIA_PROXY
#define PFN_vkImportSemaphoreZirconHandleFUCHSIA_PROXY
	VkResult importSemaphoreZirconHandleFUCHSIA(const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) {
		return fp_vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
	}
#endif
#ifndef PFN_vkGetSemaphoreZirconHandleFUCHSIA_PROXY
#define PFN_vkGetSemaphoreZirconHandleFUCHSIA_PROXY
	VkResult getSemaphoreZirconHandleFUCHSIA(const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
		return fp_vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
	}
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetPatchControlPointsEXT_PROXY
#define PFN_vkCmdSetPatchControlPointsEXT_PROXY
	void cmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
		fp_vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
	}
#endif
#ifndef PFN_vkCmdSetRasterizerDiscardEnableEXT_PROXY
#define PFN_vkCmdSetRasterizerDiscardEnableEXT_PROXY
	void cmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
		fp_vkCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
	}
#endif
#ifndef PFN_vkCmdSetDepthBiasEnableEXT_PROXY
#define PFN_vkCmdSetDepthBiasEnableEXT_PROXY
	void cmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
		fp_vkCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
	}
#endif
#ifndef PFN_vkCmdSetLogicOpEXT_PROXY
#define PFN_vkCmdSetLogicOpEXT_PROXY
	void cmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
		fp_vkCmdSetLogicOpEXT(commandBuffer, logicOp);
	}
#endif
#ifndef PFN_vkCmdSetPrimitiveRestartEnableEXT_PROXY
#define PFN_vkCmdSetPrimitiveRestartEnableEXT_PROXY
	void cmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
		fp_vkCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
	}
#endif
#endif
#if defined(VK_EXT_color_write_enable) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetColorWriteEnableEXT_PROXY
#define PFN_vkCmdSetColorWriteEnableEXT_PROXY
	void cmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) {
		fp_vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
	}
#endif
#endif
#ifdef VK_VERSION_1_0
	PFN_vkGetDeviceQueue fp_vkGetDeviceQueue = nullptr;
	PFN_vkQueueSubmit fp_vkQueueSubmit = nullptr;
	PFN_vkQueueWaitIdle fp_vkQueueWaitIdle = nullptr;
	PFN_vkDeviceWaitIdle fp_vkDeviceWaitIdle = nullptr;
	PFN_vkAllocateMemory fp_vkAllocateMemory = nullptr;
	PFN_vkFreeMemory fp_vkFreeMemory = nullptr;
	PFN_vkMapMemory fp_vkMapMemory = nullptr;
	PFN_vkUnmapMemory fp_vkUnmapMemory = nullptr;
	PFN_vkFlushMappedMemoryRanges fp_vkFlushMappedMemoryRanges = nullptr;
	PFN_vkInvalidateMappedMemoryRanges fp_vkInvalidateMappedMemoryRanges = nullptr;
	PFN_vkGetDeviceMemoryCommitment fp_vkGetDeviceMemoryCommitment = nullptr;
	PFN_vkBindBufferMemory fp_vkBindBufferMemory = nullptr;
	PFN_vkBindImageMemory fp_vkBindImageMemory = nullptr;
	PFN_vkGetBufferMemoryRequirements fp_vkGetBufferMemoryRequirements = nullptr;
	PFN_vkGetImageMemoryRequirements fp_vkGetImageMemoryRequirements = nullptr;
	PFN_vkGetImageSparseMemoryRequirements fp_vkGetImageSparseMemoryRequirements = nullptr;
	PFN_vkQueueBindSparse fp_vkQueueBindSparse = nullptr;
	PFN_vkCreateFence fp_vkCreateFence = nullptr;
	PFN_vkDestroyFence fp_vkDestroyFence = nullptr;
	PFN_vkResetFences fp_vkResetFences = nullptr;
	PFN_vkGetFenceStatus fp_vkGetFenceStatus = nullptr;
	PFN_vkWaitForFences fp_vkWaitForFences = nullptr;
	PFN_vkCreateSemaphore fp_vkCreateSemaphore = nullptr;
	PFN_vkDestroySemaphore fp_vkDestroySemaphore = nullptr;
	PFN_vkCreateEvent fp_vkCreateEvent = nullptr;
	PFN_vkDestroyEvent fp_vkDestroyEvent = nullptr;
	PFN_vkGetEventStatus fp_vkGetEventStatus = nullptr;
	PFN_vkSetEvent fp_vkSetEvent = nullptr;
	PFN_vkResetEvent fp_vkResetEvent = nullptr;
	PFN_vkCreateQueryPool fp_vkCreateQueryPool = nullptr;
	PFN_vkDestroyQueryPool fp_vkDestroyQueryPool = nullptr;
	PFN_vkGetQueryPoolResults fp_vkGetQueryPoolResults = nullptr;
	PFN_vkCreateBuffer fp_vkCreateBuffer = nullptr;
	PFN_vkDestroyBuffer fp_vkDestroyBuffer = nullptr;
	PFN_vkCreateBufferView fp_vkCreateBufferView = nullptr;
	PFN_vkDestroyBufferView fp_vkDestroyBufferView = nullptr;
	PFN_vkCreateImage fp_vkCreateImage = nullptr;
	PFN_vkDestroyImage fp_vkDestroyImage = nullptr;
	PFN_vkGetImageSubresourceLayout fp_vkGetImageSubresourceLayout = nullptr;
	PFN_vkCreateImageView fp_vkCreateImageView = nullptr;
	PFN_vkDestroyImageView fp_vkDestroyImageView = nullptr;
	PFN_vkCreateShaderModule fp_vkCreateShaderModule = nullptr;
	PFN_vkDestroyShaderModule fp_vkDestroyShaderModule = nullptr;
	PFN_vkCreatePipelineCache fp_vkCreatePipelineCache = nullptr;
	PFN_vkDestroyPipelineCache fp_vkDestroyPipelineCache = nullptr;
	PFN_vkGetPipelineCacheData fp_vkGetPipelineCacheData = nullptr;
	PFN_vkMergePipelineCaches fp_vkMergePipelineCaches = nullptr;
	PFN_vkCreateGraphicsPipelines fp_vkCreateGraphicsPipelines = nullptr;
	PFN_vkCreateComputePipelines fp_vkCreateComputePipelines = nullptr;
	PFN_vkDestroyPipeline fp_vkDestroyPipeline = nullptr;
	PFN_vkCreatePipelineLayout fp_vkCreatePipelineLayout = nullptr;
	PFN_vkDestroyPipelineLayout fp_vkDestroyPipelineLayout = nullptr;
	PFN_vkCreateSampler fp_vkCreateSampler = nullptr;
	PFN_vkDestroySampler fp_vkDestroySampler = nullptr;
	PFN_vkCreateDescriptorSetLayout fp_vkCreateDescriptorSetLayout = nullptr;
	PFN_vkDestroyDescriptorSetLayout fp_vkDestroyDescriptorSetLayout = nullptr;
	PFN_vkCreateDescriptorPool fp_vkCreateDescriptorPool = nullptr;
	PFN_vkDestroyDescriptorPool fp_vkDestroyDescriptorPool = nullptr;
	PFN_vkResetDescriptorPool fp_vkResetDescriptorPool = nullptr;
	PFN_vkAllocateDescriptorSets fp_vkAllocateDescriptorSets = nullptr;
	PFN_vkFreeDescriptorSets fp_vkFreeDescriptorSets = nullptr;
	PFN_vkUpdateDescriptorSets fp_vkUpdateDescriptorSets = nullptr;
	PFN_vkCreateFramebuffer fp_vkCreateFramebuffer = nullptr;
	PFN_vkDestroyFramebuffer fp_vkDestroyFramebuffer = nullptr;
	PFN_vkCreateRenderPass fp_vkCreateRenderPass = nullptr;
	PFN_vkDestroyRenderPass fp_vkDestroyRenderPass = nullptr;
	PFN_vkGetRenderAreaGranularity fp_vkGetRenderAreaGranularity = nullptr;
	PFN_vkCreateCommandPool fp_vkCreateCommandPool = nullptr;
	PFN_vkDestroyCommandPool fp_vkDestroyCommandPool = nullptr;
	PFN_vkResetCommandPool fp_vkResetCommandPool = nullptr;
	PFN_vkAllocateCommandBuffers fp_vkAllocateCommandBuffers = nullptr;
	PFN_vkFreeCommandBuffers fp_vkFreeCommandBuffers = nullptr;
	PFN_vkBeginCommandBuffer fp_vkBeginCommandBuffer = nullptr;
	PFN_vkEndCommandBuffer fp_vkEndCommandBuffer = nullptr;
	PFN_vkResetCommandBuffer fp_vkResetCommandBuffer = nullptr;
	PFN_vkCmdBindPipeline fp_vkCmdBindPipeline = nullptr;
	PFN_vkCmdSetViewport fp_vkCmdSetViewport = nullptr;
	PFN_vkCmdSetScissor fp_vkCmdSetScissor = nullptr;
	PFN_vkCmdSetLineWidth fp_vkCmdSetLineWidth = nullptr;
	PFN_vkCmdSetDepthBias fp_vkCmdSetDepthBias = nullptr;
	PFN_vkCmdSetBlendConstants fp_vkCmdSetBlendConstants = nullptr;
	PFN_vkCmdSetDepthBounds fp_vkCmdSetDepthBounds = nullptr;
	PFN_vkCmdSetStencilCompareMask fp_vkCmdSetStencilCompareMask = nullptr;
	PFN_vkCmdSetStencilWriteMask fp_vkCmdSetStencilWriteMask = nullptr;
	PFN_vkCmdSetStencilReference fp_vkCmdSetStencilReference = nullptr;
	PFN_vkCmdBindDescriptorSets fp_vkCmdBindDescriptorSets = nullptr;
	PFN_vkCmdBindIndexBuffer fp_vkCmdBindIndexBuffer = nullptr;
	PFN_vkCmdBindVertexBuffers fp_vkCmdBindVertexBuffers = nullptr;
	PFN_vkCmdDraw fp_vkCmdDraw = nullptr;
	PFN_vkCmdDrawIndexed fp_vkCmdDrawIndexed = nullptr;
	PFN_vkCmdDrawIndirect fp_vkCmdDrawIndirect = nullptr;
	PFN_vkCmdDrawIndexedIndirect fp_vkCmdDrawIndexedIndirect = nullptr;
	PFN_vkCmdDispatch fp_vkCmdDispatch = nullptr;
	PFN_vkCmdDispatchIndirect fp_vkCmdDispatchIndirect = nullptr;
	PFN_vkCmdCopyBuffer fp_vkCmdCopyBuffer = nullptr;
	PFN_vkCmdCopyImage fp_vkCmdCopyImage = nullptr;
	PFN_vkCmdBlitImage fp_vkCmdBlitImage = nullptr;
	PFN_vkCmdCopyBufferToImage fp_vkCmdCopyBufferToImage = nullptr;
	PFN_vkCmdCopyImageToBuffer fp_vkCmdCopyImageToBuffer = nullptr;
	PFN_vkCmdUpdateBuffer fp_vkCmdUpdateBuffer = nullptr;
	PFN_vkCmdFillBuffer fp_vkCmdFillBuffer = nullptr;
	PFN_vkCmdClearColorImage fp_vkCmdClearColorImage = nullptr;
	PFN_vkCmdClearDepthStencilImage fp_vkCmdClearDepthStencilImage = nullptr;
	PFN_vkCmdClearAttachments fp_vkCmdClearAttachments = nullptr;
	PFN_vkCmdResolveImage fp_vkCmdResolveImage = nullptr;
	PFN_vkCmdSetEvent fp_vkCmdSetEvent = nullptr;
	PFN_vkCmdResetEvent fp_vkCmdResetEvent = nullptr;
	PFN_vkCmdWaitEvents fp_vkCmdWaitEvents = nullptr;
	PFN_vkCmdPipelineBarrier fp_vkCmdPipelineBarrier = nullptr;
	PFN_vkCmdBeginQuery fp_vkCmdBeginQuery = nullptr;
	PFN_vkCmdEndQuery fp_vkCmdEndQuery = nullptr;
	PFN_vkCmdResetQueryPool fp_vkCmdResetQueryPool = nullptr;
	PFN_vkCmdWriteTimestamp fp_vkCmdWriteTimestamp = nullptr;
	PFN_vkCmdCopyQueryPoolResults fp_vkCmdCopyQueryPoolResults = nullptr;
	PFN_vkCmdPushConstants fp_vkCmdPushConstants = nullptr;
	PFN_vkCmdBeginRenderPass fp_vkCmdBeginRenderPass = nullptr;
	PFN_vkCmdNextSubpass fp_vkCmdNextSubpass = nullptr;
	PFN_vkCmdEndRenderPass fp_vkCmdEndRenderPass = nullptr;
	PFN_vkCmdExecuteCommands fp_vkCmdExecuteCommands = nullptr;
#endif
#ifdef VK_VERSION_1_1
	PFN_vkBindBufferMemory2 fp_vkBindBufferMemory2 = nullptr;
	PFN_vkBindImageMemory2 fp_vkBindImageMemory2 = nullptr;
	PFN_vkGetDeviceGroupPeerMemoryFeatures fp_vkGetDeviceGroupPeerMemoryFeatures = nullptr;
	PFN_vkCmdSetDeviceMask fp_vkCmdSetDeviceMask = nullptr;
	PFN_vkCmdDispatchBase fp_vkCmdDispatchBase = nullptr;
	PFN_vkGetImageMemoryRequirements2 fp_vkGetImageMemoryRequirements2 = nullptr;
	PFN_vkGetBufferMemoryRequirements2 fp_vkGetBufferMemoryRequirements2 = nullptr;
	PFN_vkGetImageSparseMemoryRequirements2 fp_vkGetImageSparseMemoryRequirements2 = nullptr;
	PFN_vkTrimCommandPool fp_vkTrimCommandPool = nullptr;
	PFN_vkGetDeviceQueue2 fp_vkGetDeviceQueue2 = nullptr;
	PFN_vkCreateSamplerYcbcrConversion fp_vkCreateSamplerYcbcrConversion = nullptr;
	PFN_vkDestroySamplerYcbcrConversion fp_vkDestroySamplerYcbcrConversion = nullptr;
	PFN_vkCreateDescriptorUpdateTemplate fp_vkCreateDescriptorUpdateTemplate = nullptr;
	PFN_vkDestroyDescriptorUpdateTemplate fp_vkDestroyDescriptorUpdateTemplate = nullptr;
	PFN_vkUpdateDescriptorSetWithTemplate fp_vkUpdateDescriptorSetWithTemplate = nullptr;
	PFN_vkGetDescriptorSetLayoutSupport fp_vkGetDescriptorSetLayoutSupport = nullptr;
#endif
#ifdef VK_VERSION_1_2
	PFN_vkCmdDrawIndirectCount fp_vkCmdDrawIndirectCount = nullptr;
	PFN_vkCmdDrawIndexedIndirectCount fp_vkCmdDrawIndexedIndirectCount = nullptr;
	PFN_vkCreateRenderPass2 fp_vkCreateRenderPass2 = nullptr;
	PFN_vkCmdBeginRenderPass2 fp_vkCmdBeginRenderPass2 = nullptr;
	PFN_vkCmdNextSubpass2 fp_vkCmdNextSubpass2 = nullptr;
	PFN_vkCmdEndRenderPass2 fp_vkCmdEndRenderPass2 = nullptr;
	PFN_vkResetQueryPool fp_vkResetQueryPool = nullptr;
	PFN_vkGetSemaphoreCounterValue fp_vkGetSemaphoreCounterValue = nullptr;
	PFN_vkWaitSemaphores fp_vkWaitSemaphores = nullptr;
	PFN_vkSignalSemaphore fp_vkSignalSemaphore = nullptr;
	PFN_vkGetBufferDeviceAddress fp_vkGetBufferDeviceAddress = nullptr;
	PFN_vkGetBufferOpaqueCaptureAddress fp_vkGetBufferOpaqueCaptureAddress = nullptr;
	PFN_vkGetDeviceMemoryOpaqueCaptureAddress fp_vkGetDeviceMemoryOpaqueCaptureAddress = nullptr;
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSwapchainKHR_DECLARE
#define PFN_vkCreateSwapchainKHR_DECLARE
	PFN_vkCreateSwapchainKHR fp_vkCreateSwapchainKHR = nullptr;
#endif
#ifndef PFN_vkDestroySwapchainKHR_DECLARE
#define PFN_vkDestroySwapchainKHR_DECLARE
	PFN_vkDestroySwapchainKHR fp_vkDestroySwapchainKHR = nullptr;
#endif
#ifndef PFN_vkGetSwapchainImagesKHR_DECLARE
#define PFN_vkGetSwapchainImagesKHR_DECLARE
	PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImageKHR_DECLARE
#define PFN_vkAcquireNextImageKHR_DECLARE
	PFN_vkAcquireNextImageKHR fp_vkAcquireNextImageKHR = nullptr;
#endif
#ifndef PFN_vkQueuePresentKHR_DECLARE
#define PFN_vkQueuePresentKHR_DECLARE
	PFN_vkQueuePresentKHR fp_vkQueuePresentKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
	PFN_vkGetDeviceGroupPresentCapabilitiesKHR fp_vkGetDeviceGroupPresentCapabilitiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModesKHR fp_vkGetDeviceGroupSurfacePresentModesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImage2KHR_DECLARE
#define PFN_vkAcquireNextImage2KHR_DECLARE
	PFN_vkAcquireNextImage2KHR fp_vkAcquireNextImage2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_display_swapchain) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSharedSwapchainsKHR_DECLARE
#define PFN_vkCreateSharedSwapchainsKHR_DECLARE
	PFN_vkCreateSharedSwapchainsKHR fp_vkCreateSharedSwapchainsKHR = nullptr;
#endif
#endif
#if defined(VK_ANDROID_native_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainGrallocUsageANDROID_DECLARE
#define PFN_vkGetSwapchainGrallocUsageANDROID_DECLARE
	PFN_vkGetSwapchainGrallocUsageANDROID fp_vkGetSwapchainGrallocUsageANDROID = nullptr;
#endif
#ifndef PFN_vkAcquireImageANDROID_DECLARE
#define PFN_vkAcquireImageANDROID_DECLARE
	PFN_vkAcquireImageANDROID fp_vkAcquireImageANDROID = nullptr;
#endif
#ifndef PFN_vkQueueSignalReleaseImageANDROID_DECLARE
#define PFN_vkQueueSignalReleaseImageANDROID_DECLARE
	PFN_vkQueueSignalReleaseImageANDROID fp_vkQueueSignalReleaseImageANDROID = nullptr;
#endif
#ifndef PFN_vkGetSwapchainGrallocUsage2ANDROID_DECLARE
#define PFN_vkGetSwapchainGrallocUsage2ANDROID_DECLARE
	PFN_vkGetSwapchainGrallocUsage2ANDROID fp_vkGetSwapchainGrallocUsage2ANDROID = nullptr;
#endif
#endif
#if defined(VK_EXT_debug_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDebugMarkerSetObjectTagEXT_DECLARE
#define PFN_vkDebugMarkerSetObjectTagEXT_DECLARE
	PFN_vkDebugMarkerSetObjectTagEXT fp_vkDebugMarkerSetObjectTagEXT = nullptr;
#endif
#ifndef PFN_vkDebugMarkerSetObjectNameEXT_DECLARE
#define PFN_vkDebugMarkerSetObjectNameEXT_DECLARE
	PFN_vkDebugMarkerSetObjectNameEXT fp_vkDebugMarkerSetObjectNameEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerBeginEXT_DECLARE
#define PFN_vkCmdDebugMarkerBeginEXT_DECLARE
	PFN_vkCmdDebugMarkerBeginEXT fp_vkCmdDebugMarkerBeginEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerEndEXT_DECLARE
#define PFN_vkCmdDebugMarkerEndEXT_DECLARE
	PFN_vkCmdDebugMarkerEndEXT fp_vkCmdDebugMarkerEndEXT = nullptr;
#endif
#ifndef PFN_vkCmdDebugMarkerInsertEXT_DECLARE
#define PFN_vkCmdDebugMarkerInsertEXT_DECLARE
	PFN_vkCmdDebugMarkerInsertEXT fp_vkCmdDebugMarkerInsertEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_video_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateVideoSessionKHR_DECLARE
#define PFN_vkCreateVideoSessionKHR_DECLARE
	PFN_vkCreateVideoSessionKHR fp_vkCreateVideoSessionKHR = nullptr;
#endif
#ifndef PFN_vkDestroyVideoSessionKHR_DECLARE
#define PFN_vkDestroyVideoSessionKHR_DECLARE
	PFN_vkDestroyVideoSessionKHR fp_vkDestroyVideoSessionKHR = nullptr;
#endif
#ifndef PFN_vkGetVideoSessionMemoryRequirementsKHR_DECLARE
#define PFN_vkGetVideoSessionMemoryRequirementsKHR_DECLARE
	PFN_vkGetVideoSessionMemoryRequirementsKHR fp_vkGetVideoSessionMemoryRequirementsKHR = nullptr;
#endif
#ifndef PFN_vkBindVideoSessionMemoryKHR_DECLARE
#define PFN_vkBindVideoSessionMemoryKHR_DECLARE
	PFN_vkBindVideoSessionMemoryKHR fp_vkBindVideoSessionMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCreateVideoSessionParametersKHR_DECLARE
#define PFN_vkCreateVideoSessionParametersKHR_DECLARE
	PFN_vkCreateVideoSessionParametersKHR fp_vkCreateVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkUpdateVideoSessionParametersKHR_DECLARE
#define PFN_vkUpdateVideoSessionParametersKHR_DECLARE
	PFN_vkUpdateVideoSessionParametersKHR fp_vkUpdateVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkDestroyVideoSessionParametersKHR_DECLARE
#define PFN_vkDestroyVideoSessionParametersKHR_DECLARE
	PFN_vkDestroyVideoSessionParametersKHR fp_vkDestroyVideoSessionParametersKHR = nullptr;
#endif
#ifndef PFN_vkCmdBeginVideoCodingKHR_DECLARE
#define PFN_vkCmdBeginVideoCodingKHR_DECLARE
	PFN_vkCmdBeginVideoCodingKHR fp_vkCmdBeginVideoCodingKHR = nullptr;
#endif
#ifndef PFN_vkCmdEndVideoCodingKHR_DECLARE
#define PFN_vkCmdEndVideoCodingKHR_DECLARE
	PFN_vkCmdEndVideoCodingKHR fp_vkCmdEndVideoCodingKHR = nullptr;
#endif
#ifndef PFN_vkCmdControlVideoCodingKHR_DECLARE
#define PFN_vkCmdControlVideoCodingKHR_DECLARE
	PFN_vkCmdControlVideoCodingKHR fp_vkCmdControlVideoCodingKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_video_decode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDecodeVideoKHR_DECLARE
#define PFN_vkCmdDecodeVideoKHR_DECLARE
	PFN_vkCmdDecodeVideoKHR fp_vkCmdDecodeVideoKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_transform_feedback) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindTransformFeedbackBuffersEXT_DECLARE
#define PFN_vkCmdBindTransformFeedbackBuffersEXT_DECLARE
	PFN_vkCmdBindTransformFeedbackBuffersEXT fp_vkCmdBindTransformFeedbackBuffersEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginTransformFeedbackEXT_DECLARE
#define PFN_vkCmdBeginTransformFeedbackEXT_DECLARE
	PFN_vkCmdBeginTransformFeedbackEXT fp_vkCmdBeginTransformFeedbackEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndTransformFeedbackEXT_DECLARE
#define PFN_vkCmdEndTransformFeedbackEXT_DECLARE
	PFN_vkCmdEndTransformFeedbackEXT fp_vkCmdEndTransformFeedbackEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginQueryIndexedEXT_DECLARE
#define PFN_vkCmdBeginQueryIndexedEXT_DECLARE
	PFN_vkCmdBeginQueryIndexedEXT fp_vkCmdBeginQueryIndexedEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndQueryIndexedEXT_DECLARE
#define PFN_vkCmdEndQueryIndexedEXT_DECLARE
	PFN_vkCmdEndQueryIndexedEXT fp_vkCmdEndQueryIndexedEXT = nullptr;
#endif
#ifndef PFN_vkCmdDrawIndirectByteCountEXT_DECLARE
#define PFN_vkCmdDrawIndirectByteCountEXT_DECLARE
	PFN_vkCmdDrawIndirectByteCountEXT fp_vkCmdDrawIndirectByteCountEXT = nullptr;
#endif
#endif
#if defined(VK_NVX_binary_import) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateCuModuleNVX_DECLARE
#define PFN_vkCreateCuModuleNVX_DECLARE
	PFN_vkCreateCuModuleNVX fp_vkCreateCuModuleNVX = nullptr;
#endif
#ifndef PFN_vkCreateCuFunctionNVX_DECLARE
#define PFN_vkCreateCuFunctionNVX_DECLARE
	PFN_vkCreateCuFunctionNVX fp_vkCreateCuFunctionNVX = nullptr;
#endif
#ifndef PFN_vkDestroyCuModuleNVX_DECLARE
#define PFN_vkDestroyCuModuleNVX_DECLARE
	PFN_vkDestroyCuModuleNVX fp_vkDestroyCuModuleNVX = nullptr;
#endif
#ifndef PFN_vkDestroyCuFunctionNVX_DECLARE
#define PFN_vkDestroyCuFunctionNVX_DECLARE
	PFN_vkDestroyCuFunctionNVX fp_vkDestroyCuFunctionNVX = nullptr;
#endif
#ifndef PFN_vkCmdCuLaunchKernelNVX_DECLARE
#define PFN_vkCmdCuLaunchKernelNVX_DECLARE
	PFN_vkCmdCuLaunchKernelNVX fp_vkCmdCuLaunchKernelNVX = nullptr;
#endif
#endif
#if defined(VK_NVX_image_view_handle) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageViewHandleNVX_DECLARE
#define PFN_vkGetImageViewHandleNVX_DECLARE
	PFN_vkGetImageViewHandleNVX fp_vkGetImageViewHandleNVX = nullptr;
#endif
#ifndef PFN_vkGetImageViewAddressNVX_DECLARE
#define PFN_vkGetImageViewAddressNVX_DECLARE
	PFN_vkGetImageViewAddressNVX fp_vkGetImageViewAddressNVX = nullptr;
#endif
#endif
#if defined(VK_AMD_draw_indirect_count) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawIndirectCountAMD_DECLARE
#define PFN_vkCmdDrawIndirectCountAMD_DECLARE
	PFN_vkCmdDrawIndirectCountAMD fp_vkCmdDrawIndirectCountAMD = nullptr;
#endif
#ifndef PFN_vkCmdDrawIndexedIndirectCountAMD_DECLARE
#define PFN_vkCmdDrawIndexedIndirectCountAMD_DECLARE
	PFN_vkCmdDrawIndexedIndirectCountAMD fp_vkCmdDrawIndexedIndirectCountAMD = nullptr;
#endif
#endif
#if defined(VK_AMD_shader_info) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetShaderInfoAMD_DECLARE
#define PFN_vkGetShaderInfoAMD_DECLARE
	PFN_vkGetShaderInfoAMD fp_vkGetShaderInfoAMD = nullptr;
#endif
#endif
#if defined(VK_NV_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleNV_DECLARE
#define PFN_vkGetMemoryWin32HandleNV_DECLARE
	PFN_vkGetMemoryWin32HandleNV fp_vkGetMemoryWin32HandleNV = nullptr;
#endif
#endif
#if defined(VK_KHR_device_group) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_DECLARE
#define PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR_DECLARE
	PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR fp_vkGetDeviceGroupPeerMemoryFeaturesKHR = nullptr;
#endif
#ifndef PFN_vkCmdSetDeviceMaskKHR_DECLARE
#define PFN_vkCmdSetDeviceMaskKHR_DECLARE
	PFN_vkCmdSetDeviceMaskKHR fp_vkCmdSetDeviceMaskKHR = nullptr;
#endif
#ifndef PFN_vkCmdDispatchBaseKHR_DECLARE
#define PFN_vkCmdDispatchBaseKHR_DECLARE
	PFN_vkCmdDispatchBaseKHR fp_vkCmdDispatchBaseKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
#define PFN_vkGetDeviceGroupPresentCapabilitiesKHR_DECLARE
	PFN_vkGetDeviceGroupPresentCapabilitiesKHR fp_vkGetDeviceGroupPresentCapabilitiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModesKHR_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModesKHR fp_vkGetDeviceGroupSurfacePresentModesKHR = nullptr;
#endif
#ifndef PFN_vkAcquireNextImage2KHR_DECLARE
#define PFN_vkAcquireNextImage2KHR_DECLARE
	PFN_vkAcquireNextImage2KHR fp_vkAcquireNextImage2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_maintenance1) && defined(VK_VERSION_1_0)
#ifndef PFN_vkTrimCommandPoolKHR_DECLARE
#define PFN_vkTrimCommandPoolKHR_DECLARE
	PFN_vkTrimCommandPoolKHR fp_vkTrimCommandPoolKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_memory_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryWin32HandleKHR_DECLARE
#define PFN_vkGetMemoryWin32HandleKHR_DECLARE
	PFN_vkGetMemoryWin32HandleKHR fp_vkGetMemoryWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetMemoryWin32HandlePropertiesKHR_DECLARE
#define PFN_vkGetMemoryWin32HandlePropertiesKHR_DECLARE
	PFN_vkGetMemoryWin32HandlePropertiesKHR fp_vkGetMemoryWin32HandlePropertiesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_memory_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryFdKHR_DECLARE
#define PFN_vkGetMemoryFdKHR_DECLARE
	PFN_vkGetMemoryFdKHR fp_vkGetMemoryFdKHR = nullptr;
#endif
#ifndef PFN_vkGetMemoryFdPropertiesKHR_DECLARE
#define PFN_vkGetMemoryFdPropertiesKHR_DECLARE
	PFN_vkGetMemoryFdPropertiesKHR fp_vkGetMemoryFdPropertiesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_semaphore_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreWin32HandleKHR_DECLARE
#define PFN_vkImportSemaphoreWin32HandleKHR_DECLARE
	PFN_vkImportSemaphoreWin32HandleKHR fp_vkImportSemaphoreWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreWin32HandleKHR_DECLARE
#define PFN_vkGetSemaphoreWin32HandleKHR_DECLARE
	PFN_vkGetSemaphoreWin32HandleKHR fp_vkGetSemaphoreWin32HandleKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_semaphore_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreFdKHR_DECLARE
#define PFN_vkImportSemaphoreFdKHR_DECLARE
	PFN_vkImportSemaphoreFdKHR fp_vkImportSemaphoreFdKHR = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreFdKHR_DECLARE
#define PFN_vkGetSemaphoreFdKHR_DECLARE
	PFN_vkGetSemaphoreFdKHR fp_vkGetSemaphoreFdKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdPushDescriptorSetKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetKHR_DECLARE
	PFN_vkCmdPushDescriptorSetKHR fp_vkCmdPushDescriptorSetKHR = nullptr;
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR fp_vkCmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR fp_vkCmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_conditional_rendering) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBeginConditionalRenderingEXT_DECLARE
#define PFN_vkCmdBeginConditionalRenderingEXT_DECLARE
	PFN_vkCmdBeginConditionalRenderingEXT fp_vkCmdBeginConditionalRenderingEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndConditionalRenderingEXT_DECLARE
#define PFN_vkCmdEndConditionalRenderingEXT_DECLARE
	PFN_vkCmdEndConditionalRenderingEXT fp_vkCmdEndConditionalRenderingEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_descriptor_update_template) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDescriptorUpdateTemplateKHR_DECLARE
#define PFN_vkCreateDescriptorUpdateTemplateKHR_DECLARE
	PFN_vkCreateDescriptorUpdateTemplateKHR fp_vkCreateDescriptorUpdateTemplateKHR = nullptr;
#endif
#ifndef PFN_vkDestroyDescriptorUpdateTemplateKHR_DECLARE
#define PFN_vkDestroyDescriptorUpdateTemplateKHR_DECLARE
	PFN_vkDestroyDescriptorUpdateTemplateKHR fp_vkDestroyDescriptorUpdateTemplateKHR = nullptr;
#endif
#ifndef PFN_vkUpdateDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkUpdateDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkUpdateDescriptorSetWithTemplateKHR fp_vkUpdateDescriptorSetWithTemplateKHR = nullptr;
#endif
#ifndef PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
#define PFN_vkCmdPushDescriptorSetWithTemplateKHR_DECLARE
	PFN_vkCmdPushDescriptorSetWithTemplateKHR fp_vkCmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#endif
#if defined(VK_NV_clip_space_w_scaling) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetViewportWScalingNV_DECLARE
#define PFN_vkCmdSetViewportWScalingNV_DECLARE
	PFN_vkCmdSetViewportWScalingNV fp_vkCmdSetViewportWScalingNV = nullptr;
#endif
#endif
#if defined(VK_EXT_display_control) && defined(VK_VERSION_1_0)
#ifndef PFN_vkDisplayPowerControlEXT_DECLARE
#define PFN_vkDisplayPowerControlEXT_DECLARE
	PFN_vkDisplayPowerControlEXT fp_vkDisplayPowerControlEXT = nullptr;
#endif
#ifndef PFN_vkRegisterDeviceEventEXT_DECLARE
#define PFN_vkRegisterDeviceEventEXT_DECLARE
	PFN_vkRegisterDeviceEventEXT fp_vkRegisterDeviceEventEXT = nullptr;
#endif
#ifndef PFN_vkRegisterDisplayEventEXT_DECLARE
#define PFN_vkRegisterDisplayEventEXT_DECLARE
	PFN_vkRegisterDisplayEventEXT fp_vkRegisterDisplayEventEXT = nullptr;
#endif
#ifndef PFN_vkGetSwapchainCounterEXT_DECLARE
#define PFN_vkGetSwapchainCounterEXT_DECLARE
	PFN_vkGetSwapchainCounterEXT fp_vkGetSwapchainCounterEXT = nullptr;
#endif
#endif
#if defined(VK_GOOGLE_display_timing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetRefreshCycleDurationGOOGLE_DECLARE
#define PFN_vkGetRefreshCycleDurationGOOGLE_DECLARE
	PFN_vkGetRefreshCycleDurationGOOGLE fp_vkGetRefreshCycleDurationGOOGLE = nullptr;
#endif
#ifndef PFN_vkGetPastPresentationTimingGOOGLE_DECLARE
#define PFN_vkGetPastPresentationTimingGOOGLE_DECLARE
	PFN_vkGetPastPresentationTimingGOOGLE fp_vkGetPastPresentationTimingGOOGLE = nullptr;
#endif
#endif
#if defined(VK_EXT_discard_rectangles) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetDiscardRectangleEXT_DECLARE
#define PFN_vkCmdSetDiscardRectangleEXT_DECLARE
	PFN_vkCmdSetDiscardRectangleEXT fp_vkCmdSetDiscardRectangleEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_hdr_metadata) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetHdrMetadataEXT_DECLARE
#define PFN_vkSetHdrMetadataEXT_DECLARE
	PFN_vkSetHdrMetadataEXT fp_vkSetHdrMetadataEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_create_renderpass2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateRenderPass2KHR_DECLARE
#define PFN_vkCreateRenderPass2KHR_DECLARE
	PFN_vkCreateRenderPass2KHR fp_vkCreateRenderPass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdBeginRenderPass2KHR_DECLARE
#define PFN_vkCmdBeginRenderPass2KHR_DECLARE
	PFN_vkCmdBeginRenderPass2KHR fp_vkCmdBeginRenderPass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdNextSubpass2KHR_DECLARE
#define PFN_vkCmdNextSubpass2KHR_DECLARE
	PFN_vkCmdNextSubpass2KHR fp_vkCmdNextSubpass2KHR = nullptr;
#endif
#ifndef PFN_vkCmdEndRenderPass2KHR_DECLARE
#define PFN_vkCmdEndRenderPass2KHR_DECLARE
	PFN_vkCmdEndRenderPass2KHR fp_vkCmdEndRenderPass2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_shared_presentable_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSwapchainStatusKHR_DECLARE
#define PFN_vkGetSwapchainStatusKHR_DECLARE
	PFN_vkGetSwapchainStatusKHR fp_vkGetSwapchainStatusKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_fence_win32) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceWin32HandleKHR_DECLARE
#define PFN_vkImportFenceWin32HandleKHR_DECLARE
	PFN_vkImportFenceWin32HandleKHR fp_vkImportFenceWin32HandleKHR = nullptr;
#endif
#ifndef PFN_vkGetFenceWin32HandleKHR_DECLARE
#define PFN_vkGetFenceWin32HandleKHR_DECLARE
	PFN_vkGetFenceWin32HandleKHR fp_vkGetFenceWin32HandleKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_external_fence_fd) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportFenceFdKHR_DECLARE
#define PFN_vkImportFenceFdKHR_DECLARE
	PFN_vkImportFenceFdKHR fp_vkImportFenceFdKHR = nullptr;
#endif
#ifndef PFN_vkGetFenceFdKHR_DECLARE
#define PFN_vkGetFenceFdKHR_DECLARE
	PFN_vkGetFenceFdKHR fp_vkGetFenceFdKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireProfilingLockKHR_DECLARE
#define PFN_vkAcquireProfilingLockKHR_DECLARE
	PFN_vkAcquireProfilingLockKHR fp_vkAcquireProfilingLockKHR = nullptr;
#endif
#ifndef PFN_vkReleaseProfilingLockKHR_DECLARE
#define PFN_vkReleaseProfilingLockKHR_DECLARE
	PFN_vkReleaseProfilingLockKHR fp_vkReleaseProfilingLockKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_debug_utils) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetDebugUtilsObjectNameEXT_DECLARE
#define PFN_vkSetDebugUtilsObjectNameEXT_DECLARE
	PFN_vkSetDebugUtilsObjectNameEXT fp_vkSetDebugUtilsObjectNameEXT = nullptr;
#endif
#ifndef PFN_vkSetDebugUtilsObjectTagEXT_DECLARE
#define PFN_vkSetDebugUtilsObjectTagEXT_DECLARE
	PFN_vkSetDebugUtilsObjectTagEXT fp_vkSetDebugUtilsObjectTagEXT = nullptr;
#endif
#ifndef PFN_vkQueueBeginDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueBeginDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueBeginDebugUtilsLabelEXT fp_vkQueueBeginDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkQueueEndDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueEndDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueEndDebugUtilsLabelEXT fp_vkQueueEndDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkQueueInsertDebugUtilsLabelEXT_DECLARE
#define PFN_vkQueueInsertDebugUtilsLabelEXT_DECLARE
	PFN_vkQueueInsertDebugUtilsLabelEXT fp_vkQueueInsertDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdBeginDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdBeginDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdBeginDebugUtilsLabelEXT fp_vkCmdBeginDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdEndDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdEndDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdEndDebugUtilsLabelEXT fp_vkCmdEndDebugUtilsLabelEXT = nullptr;
#endif
#ifndef PFN_vkCmdInsertDebugUtilsLabelEXT_DECLARE
#define PFN_vkCmdInsertDebugUtilsLabelEXT_DECLARE
	PFN_vkCmdInsertDebugUtilsLabelEXT fp_vkCmdInsertDebugUtilsLabelEXT = nullptr;
#endif
#endif
#if defined(VK_ANDROID_external_memory_android_hardware_buffer) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetAndroidHardwareBufferPropertiesANDROID_DECLARE
#define PFN_vkGetAndroidHardwareBufferPropertiesANDROID_DECLARE
	PFN_vkGetAndroidHardwareBufferPropertiesANDROID fp_vkGetAndroidHardwareBufferPropertiesANDROID = nullptr;
#endif
#ifndef PFN_vkGetMemoryAndroidHardwareBufferANDROID_DECLARE
#define PFN_vkGetMemoryAndroidHardwareBufferANDROID_DECLARE
	PFN_vkGetMemoryAndroidHardwareBufferANDROID fp_vkGetMemoryAndroidHardwareBufferANDROID = nullptr;
#endif
#endif
#if defined(VK_EXT_sample_locations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetSampleLocationsEXT_DECLARE
#define PFN_vkCmdSetSampleLocationsEXT_DECLARE
	PFN_vkCmdSetSampleLocationsEXT fp_vkCmdSetSampleLocationsEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_get_memory_requirements2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageMemoryRequirements2KHR_DECLARE
#define PFN_vkGetImageMemoryRequirements2KHR_DECLARE
	PFN_vkGetImageMemoryRequirements2KHR fp_vkGetImageMemoryRequirements2KHR = nullptr;
#endif
#ifndef PFN_vkGetBufferMemoryRequirements2KHR_DECLARE
#define PFN_vkGetBufferMemoryRequirements2KHR_DECLARE
	PFN_vkGetBufferMemoryRequirements2KHR fp_vkGetBufferMemoryRequirements2KHR = nullptr;
#endif
#ifndef PFN_vkGetImageSparseMemoryRequirements2KHR_DECLARE
#define PFN_vkGetImageSparseMemoryRequirements2KHR_DECLARE
	PFN_vkGetImageSparseMemoryRequirements2KHR fp_vkGetImageSparseMemoryRequirements2KHR = nullptr;
#endif
#endif
#if defined(VK_KHR_acceleration_structure) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureKHR_DECLARE
#define PFN_vkCreateAccelerationStructureKHR_DECLARE
	PFN_vkCreateAccelerationStructureKHR fp_vkCreateAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkDestroyAccelerationStructureKHR_DECLARE
#define PFN_vkDestroyAccelerationStructureKHR_DECLARE
	PFN_vkDestroyAccelerationStructureKHR fp_vkDestroyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresKHR_DECLARE
#define PFN_vkCmdBuildAccelerationStructuresKHR_DECLARE
	PFN_vkCmdBuildAccelerationStructuresKHR fp_vkCmdBuildAccelerationStructuresKHR = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructuresIndirectKHR_DECLARE
#define PFN_vkCmdBuildAccelerationStructuresIndirectKHR_DECLARE
	PFN_vkCmdBuildAccelerationStructuresIndirectKHR fp_vkCmdBuildAccelerationStructuresIndirectKHR = nullptr;
#endif
#ifndef PFN_vkBuildAccelerationStructuresKHR_DECLARE
#define PFN_vkBuildAccelerationStructuresKHR_DECLARE
	PFN_vkBuildAccelerationStructuresKHR fp_vkBuildAccelerationStructuresKHR = nullptr;
#endif
#ifndef PFN_vkCopyAccelerationStructureKHR_DECLARE
#define PFN_vkCopyAccelerationStructureKHR_DECLARE
	PFN_vkCopyAccelerationStructureKHR fp_vkCopyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCopyAccelerationStructureToMemoryKHR_DECLARE
#define PFN_vkCopyAccelerationStructureToMemoryKHR_DECLARE
	PFN_vkCopyAccelerationStructureToMemoryKHR fp_vkCopyAccelerationStructureToMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCopyMemoryToAccelerationStructureKHR_DECLARE
#define PFN_vkCopyMemoryToAccelerationStructureKHR_DECLARE
	PFN_vkCopyMemoryToAccelerationStructureKHR fp_vkCopyMemoryToAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkWriteAccelerationStructuresPropertiesKHR_DECLARE
#define PFN_vkWriteAccelerationStructuresPropertiesKHR_DECLARE
	PFN_vkWriteAccelerationStructuresPropertiesKHR fp_vkWriteAccelerationStructuresPropertiesKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureKHR_DECLARE
#define PFN_vkCmdCopyAccelerationStructureKHR_DECLARE
	PFN_vkCmdCopyAccelerationStructureKHR fp_vkCmdCopyAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureToMemoryKHR_DECLARE
#define PFN_vkCmdCopyAccelerationStructureToMemoryKHR_DECLARE
	PFN_vkCmdCopyAccelerationStructureToMemoryKHR fp_vkCmdCopyAccelerationStructureToMemoryKHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyMemoryToAccelerationStructureKHR_DECLARE
#define PFN_vkCmdCopyMemoryToAccelerationStructureKHR_DECLARE
	PFN_vkCmdCopyMemoryToAccelerationStructureKHR fp_vkCmdCopyMemoryToAccelerationStructureKHR = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureDeviceAddressKHR_DECLARE
#define PFN_vkGetAccelerationStructureDeviceAddressKHR_DECLARE
	PFN_vkGetAccelerationStructureDeviceAddressKHR fp_vkGetAccelerationStructureDeviceAddressKHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_DECLARE
#define PFN_vkCmdWriteAccelerationStructuresPropertiesKHR_DECLARE
	PFN_vkCmdWriteAccelerationStructuresPropertiesKHR fp_vkCmdWriteAccelerationStructuresPropertiesKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_DECLARE
#define PFN_vkGetDeviceAccelerationStructureCompatibilityKHR_DECLARE
	PFN_vkGetDeviceAccelerationStructureCompatibilityKHR fp_vkGetDeviceAccelerationStructureCompatibilityKHR = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureBuildSizesKHR_DECLARE
#define PFN_vkGetAccelerationStructureBuildSizesKHR_DECLARE
	PFN_vkGetAccelerationStructureBuildSizesKHR fp_vkGetAccelerationStructureBuildSizesKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_ray_tracing_pipeline) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdTraceRaysKHR_DECLARE
#define PFN_vkCmdTraceRaysKHR_DECLARE
	PFN_vkCmdTraceRaysKHR fp_vkCmdTraceRaysKHR = nullptr;
#endif
#ifndef PFN_vkCreateRayTracingPipelinesKHR_DECLARE
#define PFN_vkCreateRayTracingPipelinesKHR_DECLARE
	PFN_vkCreateRayTracingPipelinesKHR fp_vkCreateRayTracingPipelinesKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesKHR_DECLARE
#define PFN_vkGetRayTracingShaderGroupHandlesKHR_DECLARE
	PFN_vkGetRayTracingShaderGroupHandlesKHR fp_vkGetRayTracingShaderGroupHandlesKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_DECLARE
#define PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR_DECLARE
	PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = nullptr;
#endif
#ifndef PFN_vkCmdTraceRaysIndirectKHR_DECLARE
#define PFN_vkCmdTraceRaysIndirectKHR_DECLARE
	PFN_vkCmdTraceRaysIndirectKHR fp_vkCmdTraceRaysIndirectKHR = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupStackSizeKHR_DECLARE
#define PFN_vkGetRayTracingShaderGroupStackSizeKHR_DECLARE
	PFN_vkGetRayTracingShaderGroupStackSizeKHR fp_vkGetRayTracingShaderGroupStackSizeKHR = nullptr;
#endif
#ifndef PFN_vkCmdSetRayTracingPipelineStackSizeKHR_DECLARE
#define PFN_vkCmdSetRayTracingPipelineStackSizeKHR_DECLARE
	PFN_vkCmdSetRayTracingPipelineStackSizeKHR fp_vkCmdSetRayTracingPipelineStackSizeKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_sampler_ycbcr_conversion) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateSamplerYcbcrConversionKHR_DECLARE
#define PFN_vkCreateSamplerYcbcrConversionKHR_DECLARE
	PFN_vkCreateSamplerYcbcrConversionKHR fp_vkCreateSamplerYcbcrConversionKHR = nullptr;
#endif
#ifndef PFN_vkDestroySamplerYcbcrConversionKHR_DECLARE
#define PFN_vkDestroySamplerYcbcrConversionKHR_DECLARE
	PFN_vkDestroySamplerYcbcrConversionKHR fp_vkDestroySamplerYcbcrConversionKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_bind_memory2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkBindBufferMemory2KHR_DECLARE
#define PFN_vkBindBufferMemory2KHR_DECLARE
	PFN_vkBindBufferMemory2KHR fp_vkBindBufferMemory2KHR = nullptr;
#endif
#ifndef PFN_vkBindImageMemory2KHR_DECLARE
#define PFN_vkBindImageMemory2KHR_DECLARE
	PFN_vkBindImageMemory2KHR fp_vkBindImageMemory2KHR = nullptr;
#endif
#endif
#if defined(VK_EXT_image_drm_format_modifier) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetImageDrmFormatModifierPropertiesEXT_DECLARE
#define PFN_vkGetImageDrmFormatModifierPropertiesEXT_DECLARE
	PFN_vkGetImageDrmFormatModifierPropertiesEXT fp_vkGetImageDrmFormatModifierPropertiesEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_validation_cache) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateValidationCacheEXT_DECLARE
#define PFN_vkCreateValidationCacheEXT_DECLARE
	PFN_vkCreateValidationCacheEXT fp_vkCreateValidationCacheEXT = nullptr;
#endif
#ifndef PFN_vkDestroyValidationCacheEXT_DECLARE
#define PFN_vkDestroyValidationCacheEXT_DECLARE
	PFN_vkDestroyValidationCacheEXT fp_vkDestroyValidationCacheEXT = nullptr;
#endif
#ifndef PFN_vkMergeValidationCachesEXT_DECLARE
#define PFN_vkMergeValidationCachesEXT_DECLARE
	PFN_vkMergeValidationCachesEXT fp_vkMergeValidationCachesEXT = nullptr;
#endif
#ifndef PFN_vkGetValidationCacheDataEXT_DECLARE
#define PFN_vkGetValidationCacheDataEXT_DECLARE
	PFN_vkGetValidationCacheDataEXT fp_vkGetValidationCacheDataEXT = nullptr;
#endif
#endif
#if defined(VK_NV_shading_rate_image) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdBindShadingRateImageNV_DECLARE
#define PFN_vkCmdBindShadingRateImageNV_DECLARE
	PFN_vkCmdBindShadingRateImageNV fp_vkCmdBindShadingRateImageNV = nullptr;
#endif
#ifndef PFN_vkCmdSetViewportShadingRatePaletteNV_DECLARE
#define PFN_vkCmdSetViewportShadingRatePaletteNV_DECLARE
	PFN_vkCmdSetViewportShadingRatePaletteNV fp_vkCmdSetViewportShadingRatePaletteNV = nullptr;
#endif
#ifndef PFN_vkCmdSetCoarseSampleOrderNV_DECLARE
#define PFN_vkCmdSetCoarseSampleOrderNV_DECLARE
	PFN_vkCmdSetCoarseSampleOrderNV fp_vkCmdSetCoarseSampleOrderNV = nullptr;
#endif
#endif
#if defined(VK_NV_ray_tracing) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateAccelerationStructureNV_DECLARE
#define PFN_vkCreateAccelerationStructureNV_DECLARE
	PFN_vkCreateAccelerationStructureNV fp_vkCreateAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkDestroyAccelerationStructureNV_DECLARE
#define PFN_vkDestroyAccelerationStructureNV_DECLARE
	PFN_vkDestroyAccelerationStructureNV fp_vkDestroyAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureMemoryRequirementsNV_DECLARE
#define PFN_vkGetAccelerationStructureMemoryRequirementsNV_DECLARE
	PFN_vkGetAccelerationStructureMemoryRequirementsNV fp_vkGetAccelerationStructureMemoryRequirementsNV = nullptr;
#endif
#ifndef PFN_vkBindAccelerationStructureMemoryNV_DECLARE
#define PFN_vkBindAccelerationStructureMemoryNV_DECLARE
	PFN_vkBindAccelerationStructureMemoryNV fp_vkBindAccelerationStructureMemoryNV = nullptr;
#endif
#ifndef PFN_vkCmdBuildAccelerationStructureNV_DECLARE
#define PFN_vkCmdBuildAccelerationStructureNV_DECLARE
	PFN_vkCmdBuildAccelerationStructureNV fp_vkCmdBuildAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkCmdCopyAccelerationStructureNV_DECLARE
#define PFN_vkCmdCopyAccelerationStructureNV_DECLARE
	PFN_vkCmdCopyAccelerationStructureNV fp_vkCmdCopyAccelerationStructureNV = nullptr;
#endif
#ifndef PFN_vkCmdTraceRaysNV_DECLARE
#define PFN_vkCmdTraceRaysNV_DECLARE
	PFN_vkCmdTraceRaysNV fp_vkCmdTraceRaysNV = nullptr;
#endif
#ifndef PFN_vkCreateRayTracingPipelinesNV_DECLARE
#define PFN_vkCreateRayTracingPipelinesNV_DECLARE
	PFN_vkCreateRayTracingPipelinesNV fp_vkCreateRayTracingPipelinesNV = nullptr;
#endif
#ifndef PFN_vkGetRayTracingShaderGroupHandlesNV_DECLARE
#define PFN_vkGetRayTracingShaderGroupHandlesNV_DECLARE
	PFN_vkGetRayTracingShaderGroupHandlesNV fp_vkGetRayTracingShaderGroupHandlesNV = nullptr;
#endif
#ifndef PFN_vkGetAccelerationStructureHandleNV_DECLARE
#define PFN_vkGetAccelerationStructureHandleNV_DECLARE
	PFN_vkGetAccelerationStructureHandleNV fp_vkGetAccelerationStructureHandleNV = nullptr;
#endif
#ifndef PFN_vkCmdWriteAccelerationStructuresPropertiesNV_DECLARE
#define PFN_vkCmdWriteAccelerationStructuresPropertiesNV_DECLARE
	PFN_vkCmdWriteAccelerationStructuresPropertiesNV fp_vkCmdWriteAccelerationStructuresPropertiesNV = nullptr;
#endif
#ifndef PFN_vkCompileDeferredNV_DECLARE
#define PFN_vkCompileDeferredNV_DECLARE
	PFN_vkCompileDeferredNV fp_vkCompileDeferredNV = nullptr;
#endif
#endif
#if defined(VK_KHR_maintenance3) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetDescriptorSetLayoutSupportKHR_DECLARE
#define PFN_vkGetDescriptorSetLayoutSupportKHR_DECLARE
	PFN_vkGetDescriptorSetLayoutSupportKHR fp_vkGetDescriptorSetLayoutSupportKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_external_memory_host) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryHostPointerPropertiesEXT_DECLARE
#define PFN_vkGetMemoryHostPointerPropertiesEXT_DECLARE
	PFN_vkGetMemoryHostPointerPropertiesEXT fp_vkGetMemoryHostPointerPropertiesEXT = nullptr;
#endif
#endif
#if defined(VK_AMD_buffer_marker) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdWriteBufferMarkerAMD_DECLARE
#define PFN_vkCmdWriteBufferMarkerAMD_DECLARE
	PFN_vkCmdWriteBufferMarkerAMD fp_vkCmdWriteBufferMarkerAMD = nullptr;
#endif
#endif
#if defined(VK_EXT_calibrated_timestamps) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetCalibratedTimestampsEXT_DECLARE
#define PFN_vkGetCalibratedTimestampsEXT_DECLARE
	PFN_vkGetCalibratedTimestampsEXT fp_vkGetCalibratedTimestampsEXT = nullptr;
#endif
#endif
#if defined(VK_NV_mesh_shader) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdDrawMeshTasksNV_DECLARE
#define PFN_vkCmdDrawMeshTasksNV_DECLARE
	PFN_vkCmdDrawMeshTasksNV fp_vkCmdDrawMeshTasksNV = nullptr;
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectNV_DECLARE
#define PFN_vkCmdDrawMeshTasksIndirectNV_DECLARE
	PFN_vkCmdDrawMeshTasksIndirectNV fp_vkCmdDrawMeshTasksIndirectNV = nullptr;
#endif
#ifndef PFN_vkCmdDrawMeshTasksIndirectCountNV_DECLARE
#define PFN_vkCmdDrawMeshTasksIndirectCountNV_DECLARE
	PFN_vkCmdDrawMeshTasksIndirectCountNV fp_vkCmdDrawMeshTasksIndirectCountNV = nullptr;
#endif
#endif
#if defined(VK_NV_scissor_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetExclusiveScissorNV_DECLARE
#define PFN_vkCmdSetExclusiveScissorNV_DECLARE
	PFN_vkCmdSetExclusiveScissorNV fp_vkCmdSetExclusiveScissorNV = nullptr;
#endif
#endif
#if defined(VK_NV_device_diagnostic_checkpoints) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCheckpointNV_DECLARE
#define PFN_vkCmdSetCheckpointNV_DECLARE
	PFN_vkCmdSetCheckpointNV fp_vkCmdSetCheckpointNV = nullptr;
#endif
#ifndef PFN_vkGetQueueCheckpointDataNV_DECLARE
#define PFN_vkGetQueueCheckpointDataNV_DECLARE
	PFN_vkGetQueueCheckpointDataNV fp_vkGetQueueCheckpointDataNV = nullptr;
#endif
#endif
#if defined(VK_KHR_timeline_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetSemaphoreCounterValueKHR_DECLARE
#define PFN_vkGetSemaphoreCounterValueKHR_DECLARE
	PFN_vkGetSemaphoreCounterValueKHR fp_vkGetSemaphoreCounterValueKHR = nullptr;
#endif
#ifndef PFN_vkWaitSemaphoresKHR_DECLARE
#define PFN_vkWaitSemaphoresKHR_DECLARE
	PFN_vkWaitSemaphoresKHR fp_vkWaitSemaphoresKHR = nullptr;
#endif
#ifndef PFN_vkSignalSemaphoreKHR_DECLARE
#define PFN_vkSignalSemaphoreKHR_DECLARE
	PFN_vkSignalSemaphoreKHR fp_vkSignalSemaphoreKHR = nullptr;
#endif
#endif
#if defined(VK_INTEL_performance_query) && defined(VK_VERSION_1_0)
#ifndef PFN_vkInitializePerformanceApiINTEL_DECLARE
#define PFN_vkInitializePerformanceApiINTEL_DECLARE
	PFN_vkInitializePerformanceApiINTEL fp_vkInitializePerformanceApiINTEL = nullptr;
#endif
#ifndef PFN_vkUninitializePerformanceApiINTEL_DECLARE
#define PFN_vkUninitializePerformanceApiINTEL_DECLARE
	PFN_vkUninitializePerformanceApiINTEL fp_vkUninitializePerformanceApiINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceMarkerINTEL_DECLARE
#define PFN_vkCmdSetPerformanceMarkerINTEL_DECLARE
	PFN_vkCmdSetPerformanceMarkerINTEL fp_vkCmdSetPerformanceMarkerINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceStreamMarkerINTEL_DECLARE
#define PFN_vkCmdSetPerformanceStreamMarkerINTEL_DECLARE
	PFN_vkCmdSetPerformanceStreamMarkerINTEL fp_vkCmdSetPerformanceStreamMarkerINTEL = nullptr;
#endif
#ifndef PFN_vkCmdSetPerformanceOverrideINTEL_DECLARE
#define PFN_vkCmdSetPerformanceOverrideINTEL_DECLARE
	PFN_vkCmdSetPerformanceOverrideINTEL fp_vkCmdSetPerformanceOverrideINTEL = nullptr;
#endif
#ifndef PFN_vkAcquirePerformanceConfigurationINTEL_DECLARE
#define PFN_vkAcquirePerformanceConfigurationINTEL_DECLARE
	PFN_vkAcquirePerformanceConfigurationINTEL fp_vkAcquirePerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkReleasePerformanceConfigurationINTEL_DECLARE
#define PFN_vkReleasePerformanceConfigurationINTEL_DECLARE
	PFN_vkReleasePerformanceConfigurationINTEL fp_vkReleasePerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkQueueSetPerformanceConfigurationINTEL_DECLARE
#define PFN_vkQueueSetPerformanceConfigurationINTEL_DECLARE
	PFN_vkQueueSetPerformanceConfigurationINTEL fp_vkQueueSetPerformanceConfigurationINTEL = nullptr;
#endif
#ifndef PFN_vkGetPerformanceParameterINTEL_DECLARE
#define PFN_vkGetPerformanceParameterINTEL_DECLARE
	PFN_vkGetPerformanceParameterINTEL fp_vkGetPerformanceParameterINTEL = nullptr;
#endif
#endif
#if defined(VK_AMD_display_native_hdr) && defined(VK_VERSION_1_0)
#ifndef PFN_vkSetLocalDimmingAMD_DECLARE
#define PFN_vkSetLocalDimmingAMD_DECLARE
	PFN_vkSetLocalDimmingAMD fp_vkSetLocalDimmingAMD = nullptr;
#endif
#endif
#if defined(VK_KHR_fragment_shading_rate) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateKHR_DECLARE
#define PFN_vkCmdSetFragmentShadingRateKHR_DECLARE
	PFN_vkCmdSetFragmentShadingRateKHR fp_vkCmdSetFragmentShadingRateKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferDeviceAddressEXT_DECLARE
#define PFN_vkGetBufferDeviceAddressEXT_DECLARE
	PFN_vkGetBufferDeviceAddressEXT fp_vkGetBufferDeviceAddressEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_0)
#ifndef PFN_vkAcquireFullScreenExclusiveModeEXT_DECLARE
#define PFN_vkAcquireFullScreenExclusiveModeEXT_DECLARE
	PFN_vkAcquireFullScreenExclusiveModeEXT fp_vkAcquireFullScreenExclusiveModeEXT = nullptr;
#endif
#ifndef PFN_vkReleaseFullScreenExclusiveModeEXT_DECLARE
#define PFN_vkReleaseFullScreenExclusiveModeEXT_DECLARE
	PFN_vkReleaseFullScreenExclusiveModeEXT fp_vkReleaseFullScreenExclusiveModeEXT = nullptr;
#endif
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModes2EXT fp_vkGetDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif
#endif
#if defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)
#ifndef PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
#define PFN_vkGetDeviceGroupSurfacePresentModes2EXT_DECLARE
	PFN_vkGetDeviceGroupSurfacePresentModes2EXT fp_vkGetDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif
#endif
#if defined(VK_KHR_buffer_device_address) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetBufferOpaqueCaptureAddressKHR_DECLARE
#define PFN_vkGetBufferOpaqueCaptureAddressKHR_DECLARE
	PFN_vkGetBufferOpaqueCaptureAddressKHR fp_vkGetBufferOpaqueCaptureAddressKHR = nullptr;
#endif
#ifndef PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_DECLARE
#define PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR_DECLARE
	PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR = nullptr;
#endif
#endif
#if defined(VK_EXT_line_rasterization) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetLineStippleEXT_DECLARE
#define PFN_vkCmdSetLineStippleEXT_DECLARE
	PFN_vkCmdSetLineStippleEXT fp_vkCmdSetLineStippleEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_host_query_reset) && defined(VK_VERSION_1_0)
#ifndef PFN_vkResetQueryPoolEXT_DECLARE
#define PFN_vkResetQueryPoolEXT_DECLARE
	PFN_vkResetQueryPoolEXT fp_vkResetQueryPoolEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetCullModeEXT_DECLARE
#define PFN_vkCmdSetCullModeEXT_DECLARE
	PFN_vkCmdSetCullModeEXT fp_vkCmdSetCullModeEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetFrontFaceEXT_DECLARE
#define PFN_vkCmdSetFrontFaceEXT_DECLARE
	PFN_vkCmdSetFrontFaceEXT fp_vkCmdSetFrontFaceEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetPrimitiveTopologyEXT_DECLARE
#define PFN_vkCmdSetPrimitiveTopologyEXT_DECLARE
	PFN_vkCmdSetPrimitiveTopologyEXT fp_vkCmdSetPrimitiveTopologyEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetViewportWithCountEXT_DECLARE
#define PFN_vkCmdSetViewportWithCountEXT_DECLARE
	PFN_vkCmdSetViewportWithCountEXT fp_vkCmdSetViewportWithCountEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetScissorWithCountEXT_DECLARE
#define PFN_vkCmdSetScissorWithCountEXT_DECLARE
	PFN_vkCmdSetScissorWithCountEXT fp_vkCmdSetScissorWithCountEXT = nullptr;
#endif
#ifndef PFN_vkCmdBindVertexBuffers2EXT_DECLARE
#define PFN_vkCmdBindVertexBuffers2EXT_DECLARE
	PFN_vkCmdBindVertexBuffers2EXT fp_vkCmdBindVertexBuffers2EXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthTestEnableEXT_DECLARE
#define PFN_vkCmdSetDepthTestEnableEXT_DECLARE
	PFN_vkCmdSetDepthTestEnableEXT fp_vkCmdSetDepthTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthWriteEnableEXT_DECLARE
#define PFN_vkCmdSetDepthWriteEnableEXT_DECLARE
	PFN_vkCmdSetDepthWriteEnableEXT fp_vkCmdSetDepthWriteEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthCompareOpEXT_DECLARE
#define PFN_vkCmdSetDepthCompareOpEXT_DECLARE
	PFN_vkCmdSetDepthCompareOpEXT fp_vkCmdSetDepthCompareOpEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthBoundsTestEnableEXT_DECLARE
#define PFN_vkCmdSetDepthBoundsTestEnableEXT_DECLARE
	PFN_vkCmdSetDepthBoundsTestEnableEXT fp_vkCmdSetDepthBoundsTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetStencilTestEnableEXT_DECLARE
#define PFN_vkCmdSetStencilTestEnableEXT_DECLARE
	PFN_vkCmdSetStencilTestEnableEXT fp_vkCmdSetStencilTestEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetStencilOpEXT_DECLARE
#define PFN_vkCmdSetStencilOpEXT_DECLARE
	PFN_vkCmdSetStencilOpEXT fp_vkCmdSetStencilOpEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_deferred_host_operations) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreateDeferredOperationKHR_DECLARE
#define PFN_vkCreateDeferredOperationKHR_DECLARE
	PFN_vkCreateDeferredOperationKHR fp_vkCreateDeferredOperationKHR = nullptr;
#endif
#ifndef PFN_vkDestroyDeferredOperationKHR_DECLARE
#define PFN_vkDestroyDeferredOperationKHR_DECLARE
	PFN_vkDestroyDeferredOperationKHR fp_vkDestroyDeferredOperationKHR = nullptr;
#endif
#ifndef PFN_vkGetDeferredOperationMaxConcurrencyKHR_DECLARE
#define PFN_vkGetDeferredOperationMaxConcurrencyKHR_DECLARE
	PFN_vkGetDeferredOperationMaxConcurrencyKHR fp_vkGetDeferredOperationMaxConcurrencyKHR = nullptr;
#endif
#ifndef PFN_vkGetDeferredOperationResultKHR_DECLARE
#define PFN_vkGetDeferredOperationResultKHR_DECLARE
	PFN_vkGetDeferredOperationResultKHR fp_vkGetDeferredOperationResultKHR = nullptr;
#endif
#ifndef PFN_vkDeferredOperationJoinKHR_DECLARE
#define PFN_vkDeferredOperationJoinKHR_DECLARE
	PFN_vkDeferredOperationJoinKHR fp_vkDeferredOperationJoinKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_pipeline_executable_properties) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetPipelineExecutablePropertiesKHR_DECLARE
#define PFN_vkGetPipelineExecutablePropertiesKHR_DECLARE
	PFN_vkGetPipelineExecutablePropertiesKHR fp_vkGetPipelineExecutablePropertiesKHR = nullptr;
#endif
#ifndef PFN_vkGetPipelineExecutableStatisticsKHR_DECLARE
#define PFN_vkGetPipelineExecutableStatisticsKHR_DECLARE
	PFN_vkGetPipelineExecutableStatisticsKHR fp_vkGetPipelineExecutableStatisticsKHR = nullptr;
#endif
#ifndef PFN_vkGetPipelineExecutableInternalRepresentationsKHR_DECLARE
#define PFN_vkGetPipelineExecutableInternalRepresentationsKHR_DECLARE
	PFN_vkGetPipelineExecutableInternalRepresentationsKHR fp_vkGetPipelineExecutableInternalRepresentationsKHR = nullptr;
#endif
#endif
#if defined(VK_NV_device_generated_commands) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetGeneratedCommandsMemoryRequirementsNV_DECLARE
#define PFN_vkGetGeneratedCommandsMemoryRequirementsNV_DECLARE
	PFN_vkGetGeneratedCommandsMemoryRequirementsNV fp_vkGetGeneratedCommandsMemoryRequirementsNV = nullptr;
#endif
#ifndef PFN_vkCmdPreprocessGeneratedCommandsNV_DECLARE
#define PFN_vkCmdPreprocessGeneratedCommandsNV_DECLARE
	PFN_vkCmdPreprocessGeneratedCommandsNV fp_vkCmdPreprocessGeneratedCommandsNV = nullptr;
#endif
#ifndef PFN_vkCmdExecuteGeneratedCommandsNV_DECLARE
#define PFN_vkCmdExecuteGeneratedCommandsNV_DECLARE
	PFN_vkCmdExecuteGeneratedCommandsNV fp_vkCmdExecuteGeneratedCommandsNV = nullptr;
#endif
#ifndef PFN_vkCmdBindPipelineShaderGroupNV_DECLARE
#define PFN_vkCmdBindPipelineShaderGroupNV_DECLARE
	PFN_vkCmdBindPipelineShaderGroupNV fp_vkCmdBindPipelineShaderGroupNV = nullptr;
#endif
#ifndef PFN_vkCreateIndirectCommandsLayoutNV_DECLARE
#define PFN_vkCreateIndirectCommandsLayoutNV_DECLARE
	PFN_vkCreateIndirectCommandsLayoutNV fp_vkCreateIndirectCommandsLayoutNV = nullptr;
#endif
#ifndef PFN_vkDestroyIndirectCommandsLayoutNV_DECLARE
#define PFN_vkDestroyIndirectCommandsLayoutNV_DECLARE
	PFN_vkDestroyIndirectCommandsLayoutNV fp_vkDestroyIndirectCommandsLayoutNV = nullptr;
#endif
#endif
#if defined(VK_EXT_private_data) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCreatePrivateDataSlotEXT_DECLARE
#define PFN_vkCreatePrivateDataSlotEXT_DECLARE
	PFN_vkCreatePrivateDataSlotEXT fp_vkCreatePrivateDataSlotEXT = nullptr;
#endif
#ifndef PFN_vkDestroyPrivateDataSlotEXT_DECLARE
#define PFN_vkDestroyPrivateDataSlotEXT_DECLARE
	PFN_vkDestroyPrivateDataSlotEXT fp_vkDestroyPrivateDataSlotEXT = nullptr;
#endif
#ifndef PFN_vkSetPrivateDataEXT_DECLARE
#define PFN_vkSetPrivateDataEXT_DECLARE
	PFN_vkSetPrivateDataEXT fp_vkSetPrivateDataEXT = nullptr;
#endif
#ifndef PFN_vkGetPrivateDataEXT_DECLARE
#define PFN_vkGetPrivateDataEXT_DECLARE
	PFN_vkGetPrivateDataEXT fp_vkGetPrivateDataEXT = nullptr;
#endif
#endif
#if defined(VK_KHR_video_encode_queue) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdEncodeVideoKHR_DECLARE
#define PFN_vkCmdEncodeVideoKHR_DECLARE
	PFN_vkCmdEncodeVideoKHR fp_vkCmdEncodeVideoKHR = nullptr;
#endif
#endif
#if defined(VK_KHR_synchronization2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetEvent2KHR_DECLARE
#define PFN_vkCmdSetEvent2KHR_DECLARE
	PFN_vkCmdSetEvent2KHR fp_vkCmdSetEvent2KHR = nullptr;
#endif
#ifndef PFN_vkCmdResetEvent2KHR_DECLARE
#define PFN_vkCmdResetEvent2KHR_DECLARE
	PFN_vkCmdResetEvent2KHR fp_vkCmdResetEvent2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWaitEvents2KHR_DECLARE
#define PFN_vkCmdWaitEvents2KHR_DECLARE
	PFN_vkCmdWaitEvents2KHR fp_vkCmdWaitEvents2KHR = nullptr;
#endif
#ifndef PFN_vkCmdPipelineBarrier2KHR_DECLARE
#define PFN_vkCmdPipelineBarrier2KHR_DECLARE
	PFN_vkCmdPipelineBarrier2KHR fp_vkCmdPipelineBarrier2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteTimestamp2KHR_DECLARE
#define PFN_vkCmdWriteTimestamp2KHR_DECLARE
	PFN_vkCmdWriteTimestamp2KHR fp_vkCmdWriteTimestamp2KHR = nullptr;
#endif
#ifndef PFN_vkQueueSubmit2KHR_DECLARE
#define PFN_vkQueueSubmit2KHR_DECLARE
	PFN_vkQueueSubmit2KHR fp_vkQueueSubmit2KHR = nullptr;
#endif
#ifndef PFN_vkCmdWriteBufferMarker2AMD_DECLARE
#define PFN_vkCmdWriteBufferMarker2AMD_DECLARE
	PFN_vkCmdWriteBufferMarker2AMD fp_vkCmdWriteBufferMarker2AMD = nullptr;
#endif
#ifndef PFN_vkGetQueueCheckpointData2NV_DECLARE
#define PFN_vkGetQueueCheckpointData2NV_DECLARE
	PFN_vkGetQueueCheckpointData2NV fp_vkGetQueueCheckpointData2NV = nullptr;
#endif
#endif
#if defined(VK_NV_fragment_shading_rate_enums) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetFragmentShadingRateEnumNV_DECLARE
#define PFN_vkCmdSetFragmentShadingRateEnumNV_DECLARE
	PFN_vkCmdSetFragmentShadingRateEnumNV fp_vkCmdSetFragmentShadingRateEnumNV = nullptr;
#endif
#endif
#if defined(VK_KHR_copy_commands2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdCopyBuffer2KHR_DECLARE
#define PFN_vkCmdCopyBuffer2KHR_DECLARE
	PFN_vkCmdCopyBuffer2KHR fp_vkCmdCopyBuffer2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyImage2KHR_DECLARE
#define PFN_vkCmdCopyImage2KHR_DECLARE
	PFN_vkCmdCopyImage2KHR fp_vkCmdCopyImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyBufferToImage2KHR_DECLARE
#define PFN_vkCmdCopyBufferToImage2KHR_DECLARE
	PFN_vkCmdCopyBufferToImage2KHR fp_vkCmdCopyBufferToImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdCopyImageToBuffer2KHR_DECLARE
#define PFN_vkCmdCopyImageToBuffer2KHR_DECLARE
	PFN_vkCmdCopyImageToBuffer2KHR fp_vkCmdCopyImageToBuffer2KHR = nullptr;
#endif
#ifndef PFN_vkCmdBlitImage2KHR_DECLARE
#define PFN_vkCmdBlitImage2KHR_DECLARE
	PFN_vkCmdBlitImage2KHR fp_vkCmdBlitImage2KHR = nullptr;
#endif
#ifndef PFN_vkCmdResolveImage2KHR_DECLARE
#define PFN_vkCmdResolveImage2KHR_DECLARE
	PFN_vkCmdResolveImage2KHR fp_vkCmdResolveImage2KHR = nullptr;
#endif
#endif
#if defined(VK_EXT_vertex_input_dynamic_state) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetVertexInputEXT_DECLARE
#define PFN_vkCmdSetVertexInputEXT_DECLARE
	PFN_vkCmdSetVertexInputEXT fp_vkCmdSetVertexInputEXT = nullptr;
#endif
#endif
#if defined(VK_FUCHSIA_external_memory) && defined(VK_VERSION_1_0)
#ifndef PFN_vkGetMemoryZirconHandleFUCHSIA_DECLARE
#define PFN_vkGetMemoryZirconHandleFUCHSIA_DECLARE
	PFN_vkGetMemoryZirconHandleFUCHSIA fp_vkGetMemoryZirconHandleFUCHSIA = nullptr;
#endif
#ifndef PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_DECLARE
#define PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA_DECLARE
	PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA fp_vkGetMemoryZirconHandlePropertiesFUCHSIA = nullptr;
#endif
#endif
#if defined(VK_FUCHSIA_external_semaphore) && defined(VK_VERSION_1_0)
#ifndef PFN_vkImportSemaphoreZirconHandleFUCHSIA_DECLARE
#define PFN_vkImportSemaphoreZirconHandleFUCHSIA_DECLARE
	PFN_vkImportSemaphoreZirconHandleFUCHSIA fp_vkImportSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#ifndef PFN_vkGetSemaphoreZirconHandleFUCHSIA_DECLARE
#define PFN_vkGetSemaphoreZirconHandleFUCHSIA_DECLARE
	PFN_vkGetSemaphoreZirconHandleFUCHSIA fp_vkGetSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#endif
#if defined(VK_EXT_extended_dynamic_state2) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetPatchControlPointsEXT_DECLARE
#define PFN_vkCmdSetPatchControlPointsEXT_DECLARE
	PFN_vkCmdSetPatchControlPointsEXT fp_vkCmdSetPatchControlPointsEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetRasterizerDiscardEnableEXT_DECLARE
#define PFN_vkCmdSetRasterizerDiscardEnableEXT_DECLARE
	PFN_vkCmdSetRasterizerDiscardEnableEXT fp_vkCmdSetRasterizerDiscardEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetDepthBiasEnableEXT_DECLARE
#define PFN_vkCmdSetDepthBiasEnableEXT_DECLARE
	PFN_vkCmdSetDepthBiasEnableEXT fp_vkCmdSetDepthBiasEnableEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetLogicOpEXT_DECLARE
#define PFN_vkCmdSetLogicOpEXT_DECLARE
	PFN_vkCmdSetLogicOpEXT fp_vkCmdSetLogicOpEXT = nullptr;
#endif
#ifndef PFN_vkCmdSetPrimitiveRestartEnableEXT_DECLARE
#define PFN_vkCmdSetPrimitiveRestartEnableEXT_DECLARE
	PFN_vkCmdSetPrimitiveRestartEnableEXT fp_vkCmdSetPrimitiveRestartEnableEXT = nullptr;
#endif
#endif
#if defined(VK_EXT_color_write_enable) && defined(VK_VERSION_1_0)
#ifndef PFN_vkCmdSetColorWriteEnableEXT_DECLARE
#define PFN_vkCmdSetColorWriteEnableEXT_DECLARE
	PFN_vkCmdSetColorWriteEnableEXT fp_vkCmdSetColorWriteEnableEXT = nullptr;
#endif
#endif
	VkDevice device = VK_NULL_HANDLE;
};

} // namespace vkb