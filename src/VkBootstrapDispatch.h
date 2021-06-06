/* 
 * Copyright � 2021 Cody Goodson (contact@vibimanx.com)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the �Software�), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
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
	DispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr procAddr) : device(device), populated(true) {
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
		fp_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)procAddr(device, "vkGetBufferMemoryRequirements");
		fp_vkBindBufferMemory = (PFN_vkBindBufferMemory)procAddr(device, "vkBindBufferMemory");
		fp_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)procAddr(device, "vkGetImageMemoryRequirements");
		fp_vkBindImageMemory = (PFN_vkBindImageMemory)procAddr(device, "vkBindImageMemory");
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
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
		fp_vkResetQueryPool = (PFN_vkResetQueryPool)procAddr(device, "vkResetQueryPool");
#endif
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
#if (defined(VK_EXT_conditional_rendering))
		fp_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)procAddr(device, "vkCmdBeginConditionalRenderingEXT");
#endif
#if (defined(VK_EXT_conditional_rendering))
		fp_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)procAddr(device, "vkCmdEndConditionalRenderingEXT");
#endif
		fp_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)procAddr(device, "vkCmdResetQueryPool");
		fp_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)procAddr(device, "vkCmdWriteTimestamp");
		fp_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)procAddr(device, "vkCmdCopyQueryPoolResults");
		fp_vkCmdPushConstants = (PFN_vkCmdPushConstants)procAddr(device, "vkCmdPushConstants");
		fp_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)procAddr(device, "vkCmdBeginRenderPass");
		fp_vkCmdNextSubpass = (PFN_vkCmdNextSubpass)procAddr(device, "vkCmdNextSubpass");
		fp_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)procAddr(device, "vkCmdEndRenderPass");
		fp_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)procAddr(device, "vkCmdExecuteCommands");
#if (defined(VK_KHR_display_swapchain))
		fp_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)procAddr(device, "vkCreateSharedSwapchainsKHR");
#endif
#if (defined(VK_KHR_swapchain))
		fp_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)procAddr(device, "vkCreateSwapchainKHR");
#endif
#if (defined(VK_KHR_swapchain))
		fp_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)procAddr(device, "vkDestroySwapchainKHR");
#endif
#if (defined(VK_KHR_swapchain))
		fp_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)procAddr(device, "vkGetSwapchainImagesKHR");
#endif
#if (defined(VK_KHR_swapchain))
		fp_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)procAddr(device, "vkAcquireNextImageKHR");
#endif
#if (defined(VK_KHR_swapchain))
		fp_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)procAddr(device, "vkQueuePresentKHR");
#endif
#if (defined(VK_EXT_debug_marker))
		fp_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)procAddr(device, "vkDebugMarkerSetObjectNameEXT");
#endif
#if (defined(VK_EXT_debug_marker))
		fp_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)procAddr(device, "vkDebugMarkerSetObjectTagEXT");
#endif
#if (defined(VK_EXT_debug_marker))
		fp_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)procAddr(device, "vkCmdDebugMarkerBeginEXT");
#endif
#if (defined(VK_EXT_debug_marker))
		fp_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)procAddr(device, "vkCmdDebugMarkerEndEXT");
#endif
#if (defined(VK_EXT_debug_marker))
		fp_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)procAddr(device, "vkCmdDebugMarkerInsertEXT");
#endif
#if (defined(VK_NV_external_memory_win32))
		fp_vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)procAddr(device, "vkGetMemoryWin32HandleNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV)procAddr(device, "vkCmdExecuteGeneratedCommandsNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV)procAddr(device, "vkCmdPreprocessGeneratedCommandsNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)procAddr(device, "vkCmdBindPipelineShaderGroupNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)procAddr(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV)procAddr(device, "vkCreateIndirectCommandsLayoutNV");
#endif
#if (defined(VK_NV_device_generated_commands))
		fp_vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV)procAddr(device, "vkDestroyIndirectCommandsLayoutNV");
#endif
#if (defined(VK_KHR_push_descriptor))
		fp_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)procAddr(device, "vkCmdPushDescriptorSetKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
		fp_vkTrimCommandPool = (PFN_vkTrimCommandPool)procAddr(device, "vkTrimCommandPool");
#endif
#if (defined(VK_KHR_external_memory_win32))
		fp_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)procAddr(device, "vkGetMemoryWin32HandleKHR");
#endif
#if (defined(VK_KHR_external_memory_win32))
		fp_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)procAddr(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif
#if (defined(VK_KHR_external_memory_fd))
		fp_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)procAddr(device, "vkGetMemoryFdKHR");
#endif
#if (defined(VK_KHR_external_memory_fd))
		fp_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)procAddr(device, "vkGetMemoryFdPropertiesKHR");
#endif
#if (defined(VK_FUCHSIA_external_memory))
		fp_vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)procAddr(device, "vkGetMemoryZirconHandleFUCHSIA");
#endif
#if (defined(VK_FUCHSIA_external_memory))
		fp_vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)procAddr(device, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif
#if (defined(VK_KHR_external_semaphore_win32))
		fp_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)procAddr(device, "vkGetSemaphoreWin32HandleKHR");
#endif
#if (defined(VK_KHR_external_semaphore_win32))
		fp_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)procAddr(device, "vkImportSemaphoreWin32HandleKHR");
#endif
#if (defined(VK_KHR_external_semaphore_fd))
		fp_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)procAddr(device, "vkGetSemaphoreFdKHR");
#endif
#if (defined(VK_KHR_external_semaphore_fd))
		fp_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)procAddr(device, "vkImportSemaphoreFdKHR");
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
		fp_vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkGetSemaphoreZirconHandleFUCHSIA");
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
		fp_vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA)procAddr(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif
#if (defined(VK_KHR_external_fence_win32))
		fp_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)procAddr(device, "vkGetFenceWin32HandleKHR");
#endif
#if (defined(VK_KHR_external_fence_win32))
		fp_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)procAddr(device, "vkImportFenceWin32HandleKHR");
#endif
#if (defined(VK_KHR_external_fence_fd))
		fp_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)procAddr(device, "vkGetFenceFdKHR");
#endif
#if (defined(VK_KHR_external_fence_fd))
		fp_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)procAddr(device, "vkImportFenceFdKHR");
#endif
#if (defined(VK_EXT_display_control))
		fp_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)procAddr(device, "vkDisplayPowerControlEXT");
#endif
#if (defined(VK_EXT_display_control))
		fp_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)procAddr(device, "vkRegisterDeviceEventEXT");
#endif
#if (defined(VK_EXT_display_control))
		fp_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)procAddr(device, "vkRegisterDisplayEventEXT");
#endif
#if (defined(VK_EXT_display_control))
		fp_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)procAddr(device, "vkGetSwapchainCounterEXT");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)procAddr(device, "vkGetDeviceGroupPeerMemoryFeatures");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
		fp_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)procAddr(device, "vkBindBufferMemory2");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
		fp_vkBindImageMemory2 = (PFN_vkBindImageMemory2)procAddr(device, "vkBindImageMemory2");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)procAddr(device, "vkCmdSetDeviceMask");
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
		fp_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)procAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
		fp_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)procAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain))
		fp_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)procAddr(device, "vkAcquireNextImage2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkCmdDispatchBase = (PFN_vkCmdDispatchBase)procAddr(device, "vkCmdDispatchBase");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)procAddr(device, "vkCreateDescriptorUpdateTemplate");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)procAddr(device, "vkDestroyDescriptorUpdateTemplate");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)procAddr(device, "vkUpdateDescriptorSetWithTemplate");
#endif
#if (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template)) || (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor))
		fp_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)procAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif
#if (defined(VK_EXT_hdr_metadata))
		fp_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)procAddr(device, "vkSetHdrMetadataEXT");
#endif
#if (defined(VK_KHR_shared_presentable_image))
		fp_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)procAddr(device, "vkGetSwapchainStatusKHR");
#endif
#if (defined(VK_GOOGLE_display_timing))
		fp_vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)procAddr(device, "vkGetRefreshCycleDurationGOOGLE");
#endif
#if (defined(VK_GOOGLE_display_timing))
		fp_vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)procAddr(device, "vkGetPastPresentationTimingGOOGLE");
#endif
#if (defined(VK_NV_clip_space_w_scaling))
		fp_vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)procAddr(device, "vkCmdSetViewportWScalingNV");
#endif
#if (defined(VK_EXT_discard_rectangles))
		fp_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)procAddr(device, "vkCmdSetDiscardRectangleEXT");
#endif
#if (defined(VK_EXT_sample_locations))
		fp_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)procAddr(device, "vkCmdSetSampleLocationsEXT");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)procAddr(device, "vkGetBufferMemoryRequirements2");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)procAddr(device, "vkGetImageMemoryRequirements2");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)procAddr(device, "vkGetImageSparseMemoryRequirements2");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
		fp_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)procAddr(device, "vkCreateSamplerYcbcrConversion");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
		fp_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)procAddr(device, "vkDestroySamplerYcbcrConversion");
#endif
#if (defined(VK_VERSION_1_1))
		fp_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)procAddr(device, "vkGetDeviceQueue2");
#endif
#if (defined(VK_EXT_validation_cache))
		fp_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)procAddr(device, "vkCreateValidationCacheEXT");
#endif
#if (defined(VK_EXT_validation_cache))
		fp_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)procAddr(device, "vkDestroyValidationCacheEXT");
#endif
#if (defined(VK_EXT_validation_cache))
		fp_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)procAddr(device, "vkGetValidationCacheDataEXT");
#endif
#if (defined(VK_EXT_validation_cache))
		fp_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)procAddr(device, "vkMergeValidationCachesEXT");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
		fp_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)procAddr(device, "vkGetDescriptorSetLayoutSupport");
#endif
#if (defined(VK_ANDROID_native_buffer))
		fp_vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)procAddr(device, "vkGetSwapchainGrallocUsageANDROID");
#endif
#if (defined(VK_ANDROID_native_buffer))
		fp_vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)procAddr(device, "vkGetSwapchainGrallocUsage2ANDROID");
#endif
#if (defined(VK_ANDROID_native_buffer))
		fp_vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID)procAddr(device, "vkAcquireImageANDROID");
#endif
#if (defined(VK_ANDROID_native_buffer))
		fp_vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)procAddr(device, "vkQueueSignalReleaseImageANDROID");
#endif
#if (defined(VK_AMD_shader_info))
		fp_vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)procAddr(device, "vkGetShaderInfoAMD");
#endif
#if (defined(VK_AMD_display_native_hdr))
		fp_vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)procAddr(device, "vkSetLocalDimmingAMD");
#endif
#if (defined(VK_EXT_calibrated_timestamps))
		fp_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)procAddr(device, "vkGetCalibratedTimestampsEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)procAddr(device, "vkSetDebugUtilsObjectNameEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)procAddr(device, "vkSetDebugUtilsObjectTagEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)procAddr(device, "vkQueueBeginDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)procAddr(device, "vkQueueEndDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)procAddr(device, "vkQueueInsertDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)procAddr(device, "vkCmdBeginDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)procAddr(device, "vkCmdEndDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_debug_utils))
		fp_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)procAddr(device, "vkCmdInsertDebugUtilsLabelEXT");
#endif
#if (defined(VK_EXT_external_memory_host))
		fp_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)procAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif
#if (defined(VK_AMD_buffer_marker))
		fp_vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)procAddr(device, "vkCmdWriteBufferMarkerAMD");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2)procAddr(device, "vkCreateRenderPass2");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)procAddr(device, "vkCmdBeginRenderPass2");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2)procAddr(device, "vkCmdNextSubpass2");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)procAddr(device, "vkCmdEndRenderPass2");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)procAddr(device, "vkGetSemaphoreCounterValue");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkWaitSemaphores = (PFN_vkWaitSemaphores)procAddr(device, "vkWaitSemaphores");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkSignalSemaphore = (PFN_vkSignalSemaphore)procAddr(device, "vkSignalSemaphore");
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
		fp_vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)procAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
		fp_vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)procAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
		fp_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)procAddr(device, "vkCmdDrawIndirectCount");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
		fp_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)procAddr(device, "vkCmdDrawIndexedIndirectCount");
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
		fp_vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)procAddr(device, "vkCmdSetCheckpointNV");
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
		fp_vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)procAddr(device, "vkGetQueueCheckpointDataNV");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)procAddr(device, "vkCmdBindTransformFeedbackBuffersEXT");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)procAddr(device, "vkCmdBeginTransformFeedbackEXT");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)procAddr(device, "vkCmdEndTransformFeedbackEXT");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)procAddr(device, "vkCmdBeginQueryIndexedEXT");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)procAddr(device, "vkCmdEndQueryIndexedEXT");
#endif
#if (defined(VK_EXT_transform_feedback))
		fp_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)procAddr(device, "vkCmdDrawIndirectByteCountEXT");
#endif
#if (defined(VK_NV_scissor_exclusive))
		fp_vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)procAddr(device, "vkCmdSetExclusiveScissorNV");
#endif
#if (defined(VK_NV_shading_rate_image))
		fp_vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)procAddr(device, "vkCmdBindShadingRateImageNV");
#endif
#if (defined(VK_NV_shading_rate_image))
		fp_vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)procAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
#endif
#if (defined(VK_NV_shading_rate_image))
		fp_vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)procAddr(device, "vkCmdSetCoarseSampleOrderNV");
#endif
#if (defined(VK_NV_mesh_shader))
		fp_vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)procAddr(device, "vkCmdDrawMeshTasksNV");
#endif
#if (defined(VK_NV_mesh_shader))
		fp_vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)procAddr(device, "vkCmdDrawMeshTasksIndirectNV");
#endif
#if (defined(VK_NV_mesh_shader))
		fp_vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)procAddr(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCompileDeferredNV = (PFN_vkCompileDeferredNV)procAddr(device, "vkCompileDeferredNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)procAddr(device, "vkCreateAccelerationStructureNV");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR)procAddr(device, "vkDestroyAccelerationStructureKHR");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)procAddr(device, "vkDestroyAccelerationStructureNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)procAddr(device, "vkGetAccelerationStructureMemoryRequirementsNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)procAddr(device, "vkBindAccelerationStructureMemoryNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)procAddr(device, "vkCmdCopyAccelerationStructureNV");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR)procAddr(device, "vkCmdCopyAccelerationStructureKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)procAddr(device, "vkCopyAccelerationStructureKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCmdCopyAccelerationStructureToMemoryKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR)procAddr(device, "vkCopyAccelerationStructureToMemoryKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCmdCopyMemoryToAccelerationStructureKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR)procAddr(device, "vkCopyMemoryToAccelerationStructureKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)procAddr(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)procAddr(device, "vkCmdBuildAccelerationStructureNV");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR)procAddr(device, "vkWriteAccelerationStructuresPropertiesKHR");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)procAddr(device, "vkCmdTraceRaysKHR");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)procAddr(device, "vkCmdTraceRaysNV");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
		fp_vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingShaderGroupHandlesKHR");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)procAddr(device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)procAddr(device, "vkGetAccelerationStructureHandleNV");
#endif
#if (defined(VK_NV_ray_tracing))
		fp_vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)procAddr(device, "vkCreateRayTracingPipelinesNV");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)procAddr(device, "vkCreateRayTracingPipelinesKHR");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)procAddr(device, "vkCmdTraceRaysIndirectKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)procAddr(device, "vkGetDeviceAccelerationStructureCompatibilityKHR");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR)procAddr(device, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
		fp_vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)procAddr(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
#endif
#if (defined(VK_NVX_image_view_handle))
		fp_vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)procAddr(device, "vkGetImageViewHandleNVX");
#endif
#if (defined(VK_NVX_image_view_handle))
		fp_vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)procAddr(device, "vkGetImageViewAddressNVX");
#endif
#if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
		fp_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)procAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif
#if (defined(VK_EXT_full_screen_exclusive))
		fp_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)procAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif
#if (defined(VK_EXT_full_screen_exclusive))
		fp_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)procAddr(device, "vkReleaseFullScreenExclusiveModeEXT");
#endif
#if (defined(VK_KHR_performance_query))
		fp_vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)procAddr(device, "vkAcquireProfilingLockKHR");
#endif
#if (defined(VK_KHR_performance_query))
		fp_vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)procAddr(device, "vkReleaseProfilingLockKHR");
#endif
#if (defined(VK_EXT_image_drm_format_modifier))
		fp_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)procAddr(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
		fp_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)procAddr(device, "vkGetBufferOpaqueCaptureAddress");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
		fp_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)procAddr(device, "vkGetBufferDeviceAddress");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)procAddr(device, "vkInitializePerformanceApiINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)procAddr(device, "vkUninitializePerformanceApiINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)procAddr(device, "vkCmdSetPerformanceMarkerINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)procAddr(device, "vkCmdSetPerformanceStreamMarkerINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)procAddr(device, "vkCmdSetPerformanceOverrideINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)procAddr(device, "vkAcquirePerformanceConfigurationINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)procAddr(device, "vkReleasePerformanceConfigurationINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)procAddr(device, "vkQueueSetPerformanceConfigurationINTEL");
#endif
#if (defined(VK_INTEL_performance_query))
		fp_vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)procAddr(device, "vkGetPerformanceParameterINTEL");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
		fp_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
		fp_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)procAddr(device, "vkGetPipelineExecutablePropertiesKHR");
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
		fp_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)procAddr(device, "vkGetPipelineExecutableStatisticsKHR");
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
		fp_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)procAddr(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif
#if (defined(VK_EXT_line_rasterization))
		fp_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)procAddr(device, "vkCmdSetLineStippleEXT");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR)procAddr(device, "vkCreateAccelerationStructureKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR)procAddr(device, "vkCmdBuildAccelerationStructuresKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)procAddr(device, "vkCmdBuildAccelerationStructuresIndirectKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR)procAddr(device, "vkBuildAccelerationStructuresKHR");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR)procAddr(device, "vkGetAccelerationStructureDeviceAddressKHR");
#endif
#if (defined(VK_KHR_deferred_host_operations))
		fp_vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)procAddr(device, "vkCreateDeferredOperationKHR");
#endif
#if (defined(VK_KHR_deferred_host_operations))
		fp_vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)procAddr(device, "vkDestroyDeferredOperationKHR");
#endif
#if (defined(VK_KHR_deferred_host_operations))
		fp_vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR)procAddr(device, "vkGetDeferredOperationMaxConcurrencyKHR");
#endif
#if (defined(VK_KHR_deferred_host_operations))
		fp_vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR)procAddr(device, "vkGetDeferredOperationResultKHR");
#endif
#if (defined(VK_KHR_deferred_host_operations))
		fp_vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)procAddr(device, "vkDeferredOperationJoinKHR");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)procAddr(device, "vkCmdSetCullModeEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)procAddr(device, "vkCmdSetFrontFaceEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)procAddr(device, "vkCmdSetPrimitiveTopologyEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)procAddr(device, "vkCmdSetViewportWithCountEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)procAddr(device, "vkCmdSetScissorWithCountEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)procAddr(device, "vkCmdBindVertexBuffers2EXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)procAddr(device, "vkCmdSetDepthTestEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)procAddr(device, "vkCmdSetDepthWriteEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)procAddr(device, "vkCmdSetDepthCompareOpEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT)procAddr(device, "vkCmdSetDepthBoundsTestEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)procAddr(device, "vkCmdSetStencilTestEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state))
		fp_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)procAddr(device, "vkCmdSetStencilOpEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
		fp_vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)procAddr(device, "vkCmdSetPatchControlPointsEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
		fp_vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT)procAddr(device, "vkCmdSetRasterizerDiscardEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
		fp_vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)procAddr(device, "vkCmdSetDepthBiasEnableEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
		fp_vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)procAddr(device, "vkCmdSetLogicOpEXT");
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
		fp_vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT)procAddr(device, "vkCmdSetPrimitiveRestartEnableEXT");
#endif
#if (defined(VK_EXT_private_data))
		fp_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)procAddr(device, "vkCreatePrivateDataSlotEXT");
#endif
#if (defined(VK_EXT_private_data))
		fp_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)procAddr(device, "vkDestroyPrivateDataSlotEXT");
#endif
#if (defined(VK_EXT_private_data))
		fp_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)procAddr(device, "vkSetPrivateDataEXT");
#endif
#if (defined(VK_EXT_private_data))
		fp_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)procAddr(device, "vkGetPrivateDataEXT");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)procAddr(device, "vkCmdCopyBuffer2KHR");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)procAddr(device, "vkCmdCopyImage2KHR");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)procAddr(device, "vkCmdBlitImage2KHR");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)procAddr(device, "vkCmdCopyBufferToImage2KHR");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)procAddr(device, "vkCmdCopyImageToBuffer2KHR");
#endif
#if (defined(VK_KHR_copy_commands2))
		fp_vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)procAddr(device, "vkCmdResolveImage2KHR");
#endif
#if (defined(VK_KHR_fragment_shading_rate))
		fp_vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)procAddr(device, "vkCmdSetFragmentShadingRateKHR");
#endif
#if (defined(VK_NV_fragment_shading_rate_enums))
		fp_vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV)procAddr(device, "vkCmdSetFragmentShadingRateEnumNV");
#endif
#if (defined(VK_KHR_acceleration_structure))
		fp_vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR)procAddr(device, "vkGetAccelerationStructureBuildSizesKHR");
#endif
#if (defined(VK_EXT_vertex_input_dynamic_state))
		fp_vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)procAddr(device, "vkCmdSetVertexInputEXT");
#endif
#if (defined(VK_EXT_color_write_enable))
		fp_vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)procAddr(device, "vkCmdSetColorWriteEnableEXT");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)procAddr(device, "vkCmdSetEvent2KHR");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)procAddr(device, "vkCmdResetEvent2KHR");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)procAddr(device, "vkCmdWaitEvents2KHR");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)procAddr(device, "vkCmdPipelineBarrier2KHR");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)procAddr(device, "vkQueueSubmit2KHR");
#endif
#if (defined(VK_KHR_synchronization2))
		fp_vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)procAddr(device, "vkCmdWriteTimestamp2KHR");
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
		fp_vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)procAddr(device, "vkCmdWriteBufferMarker2AMD");
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
		fp_vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)procAddr(device, "vkGetQueueCheckpointData2NV");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)procAddr(device, "vkCreateVideoSessionKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)procAddr(device, "vkDestroyVideoSessionKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR)procAddr(device, "vkCreateVideoSessionParametersKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR)procAddr(device, "vkUpdateVideoSessionParametersKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR)procAddr(device, "vkDestroyVideoSessionParametersKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR)procAddr(device, "vkGetVideoSessionMemoryRequirementsKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)procAddr(device, "vkBindVideoSessionMemoryKHR");
#endif
#if (defined(VK_KHR_video_decode_queue))
		fp_vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)procAddr(device, "vkCmdDecodeVideoKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)procAddr(device, "vkCmdBeginVideoCodingKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)procAddr(device, "vkCmdControlVideoCodingKHR");
#endif
#if (defined(VK_KHR_video_queue))
		fp_vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)procAddr(device, "vkCmdEndVideoCodingKHR");
#endif
#if (defined(VK_KHR_video_encode_queue))
		fp_vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)procAddr(device, "vkCmdEncodeVideoKHR");
#endif
#if (defined(VK_NVX_binary_import))
		fp_vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)procAddr(device, "vkCreateCuModuleNVX");
#endif
#if (defined(VK_NVX_binary_import))
		fp_vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)procAddr(device, "vkCreateCuFunctionNVX");
#endif
#if (defined(VK_NVX_binary_import))
		fp_vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)procAddr(device, "vkDestroyCuModuleNVX");
#endif
#if (defined(VK_NVX_binary_import))
		fp_vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)procAddr(device, "vkDestroyCuFunctionNVX");
#endif
#if (defined(VK_NVX_binary_import))
		fp_vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)procAddr(device, "vkCmdCuLaunchKernelNVX");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
		fp_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)procAddr(device, "vkResetQueryPoolEXT");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
		fp_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)procAddr(device, "vkTrimCommandPoolKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)procAddr(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
		fp_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)procAddr(device, "vkBindBufferMemory2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
		fp_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)procAddr(device, "vkBindImageMemory2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)procAddr(device, "vkCmdSetDeviceMaskKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
		fp_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)procAddr(device, "vkCmdDispatchBaseKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)procAddr(device, "vkCreateDescriptorUpdateTemplateKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)procAddr(device, "vkDestroyDescriptorUpdateTemplateKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
		fp_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)procAddr(device, "vkUpdateDescriptorSetWithTemplateKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)procAddr(device, "vkGetBufferMemoryRequirements2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)procAddr(device, "vkGetImageMemoryRequirements2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
		fp_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)procAddr(device, "vkGetImageSparseMemoryRequirements2KHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
		fp_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)procAddr(device, "vkCreateSamplerYcbcrConversionKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
		fp_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)procAddr(device, "vkDestroySamplerYcbcrConversionKHR");
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
		fp_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)procAddr(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)procAddr(device, "vkCreateRenderPass2KHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)procAddr(device, "vkCmdBeginRenderPass2KHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)procAddr(device, "vkCmdNextSubpass2KHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
		fp_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)procAddr(device, "vkCmdEndRenderPass2KHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)procAddr(device, "vkGetSemaphoreCounterValueKHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)procAddr(device, "vkWaitSemaphoresKHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
		fp_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)procAddr(device, "vkSignalSemaphoreKHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
		fp_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)procAddr(device, "vkCmdDrawIndirectCountAMD");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
		fp_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)procAddr(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
		fp_vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)procAddr(device, "vkGetRayTracingShaderGroupHandlesNV");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
		fp_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)procAddr(device, "vkGetBufferOpaqueCaptureAddressKHR");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
		fp_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)procAddr(device, "vkGetBufferDeviceAddressEXT");
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
		fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)procAddr(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif
	}
	void getDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) const noexcept {
		fp_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
	}
	VkResult queueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) const noexcept {
		return fp_vkQueueSubmit(queue, submitCount, pSubmits, fence);
	}
	VkResult queueWaitIdle(VkQueue queue) const noexcept {
		return fp_vkQueueWaitIdle(queue);
	}
	VkResult deviceWaitIdle() const noexcept {
		return fp_vkDeviceWaitIdle(device);
	}
	VkResult allocateMemory(const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) const noexcept {
		return fp_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
	}
	void freeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkFreeMemory(device, memory, pAllocator);
	}
	VkResult mapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) const noexcept {
		return fp_vkMapMemory(device, memory, offset, size, flags, ppData);
	}
	void unmapMemory(VkDeviceMemory memory) const noexcept {
		fp_vkUnmapMemory(device, memory);
	}
	VkResult flushMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const noexcept {
		return fp_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	}
	VkResult invalidateMappedMemoryRanges(uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const noexcept {
		return fp_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	}
	void getDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) const noexcept {
		fp_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
	}
	void getBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) const noexcept {
		fp_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
	}
	VkResult bindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) const noexcept {
		return fp_vkBindBufferMemory(device, buffer, memory, memoryOffset);
	}
	void getImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements) const noexcept {
		fp_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
	}
	VkResult bindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) const noexcept {
		return fp_vkBindImageMemory(device, image, memory, memoryOffset);
	}
	void getImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) const noexcept {
		fp_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
	VkResult queueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) const noexcept {
		return fp_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
	}
	VkResult createFence(const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const noexcept {
		return fp_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
	}
	void destroyFence(VkFence fence, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyFence(device, fence, pAllocator);
	}
	VkResult resetFences(uint32_t fenceCount, const VkFence* pFences) const noexcept {
		return fp_vkResetFences(device, fenceCount, pFences);
	}
	VkResult getFenceStatus(VkFence fence) const noexcept {
		return fp_vkGetFenceStatus(device, fence);
	}
	VkResult waitForFences(uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) const noexcept {
		return fp_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
	}
	VkResult createSemaphore(const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) const noexcept {
		return fp_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
	}
	void destroySemaphore(VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroySemaphore(device, semaphore, pAllocator);
	}
	VkResult createEvent(const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) const noexcept {
		return fp_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
	}
	void destroyEvent(VkEvent event, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyEvent(device, event, pAllocator);
	}
	VkResult getEventStatus(VkEvent event) const noexcept {
		return fp_vkGetEventStatus(device, event);
	}
	VkResult setEvent(VkEvent event) const noexcept {
		return fp_vkSetEvent(device, event);
	}
	VkResult resetEvent(VkEvent event) const noexcept {
		return fp_vkResetEvent(device, event);
	}
	VkResult createQueryPool(const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) const noexcept {
		return fp_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
	}
	void destroyQueryPool(VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyQueryPool(device, queryPool, pAllocator);
	}
	VkResult getQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) const noexcept {
		return fp_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
	}
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
	void resetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const noexcept {
		fp_vkResetQueryPool(device, queryPool, firstQuery, queryCount);
	}
#endif
	VkResult createBuffer(const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) const noexcept {
		return fp_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
	}
	void destroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyBuffer(device, buffer, pAllocator);
	}
	VkResult createBufferView(const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) const noexcept {
		return fp_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
	}
	void destroyBufferView(VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyBufferView(device, bufferView, pAllocator);
	}
	VkResult createImage(const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) const noexcept {
		return fp_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
	}
	void destroyImage(VkImage image, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyImage(device, image, pAllocator);
	}
	void getImageSubresourceLayout(VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) const noexcept {
		fp_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
	}
	VkResult createImageView(const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) const noexcept {
		return fp_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
	}
	void destroyImageView(VkImageView imageView, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyImageView(device, imageView, pAllocator);
	}
	VkResult createShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) const noexcept {
		return fp_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
	}
	void destroyShaderModule(VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyShaderModule(device, shaderModule, pAllocator);
	}
	VkResult createPipelineCache(const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) const noexcept {
		return fp_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
	}
	void destroyPipelineCache(VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
	}
	VkResult getPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) const noexcept {
		return fp_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
	}
	VkResult mergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) const noexcept {
		return fp_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
	}
	VkResult createGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const noexcept {
		return fp_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
	VkResult createComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const noexcept {
		return fp_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
	void destroyPipeline(VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyPipeline(device, pipeline, pAllocator);
	}
	VkResult createPipelineLayout(const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) const noexcept {
		return fp_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
	}
	void destroyPipelineLayout(VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
	}
	VkResult createSampler(const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) const noexcept {
		return fp_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
	}
	void destroySampler(VkSampler sampler, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroySampler(device, sampler, pAllocator);
	}
	VkResult createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) const noexcept {
		return fp_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
	}
	void destroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
	}
	VkResult createDescriptorPool(const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) const noexcept {
		return fp_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
	}
	void destroyDescriptorPool(VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
	}
	VkResult resetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) const noexcept {
		return fp_vkResetDescriptorPool(device, descriptorPool, flags);
	}
	VkResult allocateDescriptorSets(const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) const noexcept {
		return fp_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
	}
	VkResult freeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) const noexcept {
		return fp_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
	}
	void updateDescriptorSets(uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) const noexcept {
		fp_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
	}
	VkResult createFramebuffer(const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) const noexcept {
		return fp_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
	}
	void destroyFramebuffer(VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyFramebuffer(device, framebuffer, pAllocator);
	}
	VkResult createRenderPass(const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const noexcept {
		return fp_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
	}
	void destroyRenderPass(VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyRenderPass(device, renderPass, pAllocator);
	}
	void getRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity) const noexcept {
		fp_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
	}
	VkResult createCommandPool(const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) const noexcept {
		return fp_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
	}
	void destroyCommandPool(VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyCommandPool(device, commandPool, pAllocator);
	}
	VkResult resetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags) const noexcept {
		return fp_vkResetCommandPool(device, commandPool, flags);
	}
	VkResult allocateCommandBuffers(const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) const noexcept {
		return fp_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
	}
	void freeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const noexcept {
		fp_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
	}
	VkResult beginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) const noexcept {
		return fp_vkBeginCommandBuffer(commandBuffer, pBeginInfo);
	}
	VkResult endCommandBuffer(VkCommandBuffer commandBuffer) const noexcept {
		return fp_vkEndCommandBuffer(commandBuffer);
	}
	VkResult resetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) const noexcept {
		return fp_vkResetCommandBuffer(commandBuffer, flags);
	}
	void cmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) const noexcept {
		fp_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
	}
	void cmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) const noexcept {
		fp_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
	}
	void cmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) const noexcept {
		fp_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
	}
	void cmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) const noexcept {
		fp_vkCmdSetLineWidth(commandBuffer, lineWidth);
	}
	void cmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const noexcept {
		fp_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
	}
	void cmdSetBlendConstants(VkCommandBuffer commandBuffer, float blendConstants[4]) const noexcept {
		fp_vkCmdSetBlendConstants(commandBuffer, blendConstants);
	}
	void cmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) const noexcept {
		fp_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
	}
	void cmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) const noexcept {
		fp_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
	}
	void cmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) const noexcept {
		fp_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
	}
	void cmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) const noexcept {
		fp_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
	}
	void cmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) const noexcept {
		fp_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
	}
	void cmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) const noexcept {
		fp_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
	}
	void cmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) const noexcept {
		fp_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
	}
	void cmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const noexcept {
		fp_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
	}
	void cmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const noexcept {
		fp_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
	}
	void cmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
	}
	void cmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
	}
	void cmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const noexcept {
		fp_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
	}
	void cmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) const noexcept {
		fp_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
	}
	void cmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) const noexcept {
		fp_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
	}
	void cmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) const noexcept {
		fp_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) const noexcept {
		fp_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
	}
	void cmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) const noexcept {
		fp_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) const noexcept {
		fp_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
	}
	void cmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) const noexcept {
		fp_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
	}
	void cmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) const noexcept {
		fp_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
	}
	void cmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const noexcept {
		fp_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
	}
	void cmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const noexcept {
		fp_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
	}
	void cmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) const noexcept {
		fp_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
	}
	void cmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) const noexcept {
		fp_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	}
	void cmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const noexcept {
		fp_vkCmdSetEvent(commandBuffer, event, stageMask);
	}
	void cmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const noexcept {
		fp_vkCmdResetEvent(commandBuffer, event, stageMask);
	}
	void cmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const noexcept {
		fp_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	}
	void cmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const noexcept {
		fp_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	}
	void cmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) const noexcept {
		fp_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
	}
	void cmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) const noexcept {
		fp_vkCmdEndQuery(commandBuffer, queryPool, query);
	}
#if (defined(VK_EXT_conditional_rendering))
	void cmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) const noexcept {
		fp_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
	}
#endif
#if (defined(VK_EXT_conditional_rendering))
	void cmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) const noexcept {
		fp_vkCmdEndConditionalRenderingEXT(commandBuffer);
	}
#endif
	void cmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const noexcept {
		fp_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
	}
	void cmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) const noexcept {
		fp_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
	}
	void cmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) const noexcept {
		fp_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
	}
	void cmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) const noexcept {
		fp_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
	}
	void cmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) const noexcept {
		fp_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
	}
	void cmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) const noexcept {
		fp_vkCmdNextSubpass(commandBuffer, contents);
	}
	void cmdEndRenderPass(VkCommandBuffer commandBuffer) const noexcept {
		fp_vkCmdEndRenderPass(commandBuffer);
	}
	void cmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const noexcept {
		fp_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
	}
#if (defined(VK_KHR_display_swapchain))
	VkResult createSharedSwapchainsKHR(uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) const noexcept {
		return fp_vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
	}
#endif
#if (defined(VK_KHR_swapchain))
	VkResult createSwapchainKHR(const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) const noexcept {
		return fp_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
	}
#endif
#if (defined(VK_KHR_swapchain))
	void destroySwapchainKHR(VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroySwapchainKHR(device, swapchain, pAllocator);
	}
#endif
#if (defined(VK_KHR_swapchain))
	VkResult getSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) const noexcept {
		return fp_vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
	}
#endif
#if (defined(VK_KHR_swapchain))
	VkResult acquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) const noexcept {
		return fp_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
	}
#endif
#if (defined(VK_KHR_swapchain))
	VkResult queuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) const noexcept {
		return fp_vkQueuePresentKHR(queue, pPresentInfo);
	}
#endif
#if (defined(VK_EXT_debug_marker))
	VkResult debugMarkerSetObjectNameEXT(const VkDebugMarkerObjectNameInfoEXT* pNameInfo) const noexcept {
		return fp_vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
	}
#endif
#if (defined(VK_EXT_debug_marker))
	VkResult debugMarkerSetObjectTagEXT(const VkDebugMarkerObjectTagInfoEXT* pTagInfo) const noexcept {
		return fp_vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
	}
#endif
#if (defined(VK_EXT_debug_marker))
	void cmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) const noexcept {
		fp_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
	}
#endif
#if (defined(VK_EXT_debug_marker))
	void cmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) const noexcept {
		fp_vkCmdDebugMarkerEndEXT(commandBuffer);
	}
#endif
#if (defined(VK_EXT_debug_marker))
	void cmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) const noexcept {
		fp_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
	}
#endif
#if (defined(VK_NV_external_memory_win32))
	VkResult getMemoryWin32HandleNV(VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) const noexcept {
		return fp_vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	void cmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) const noexcept {
		fp_vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	void cmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) const noexcept {
		fp_vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	void cmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) const noexcept {
		fp_vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	void getGeneratedCommandsMemoryRequirementsNV(const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) const noexcept {
		fp_vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	VkResult createIndirectCommandsLayoutNV(const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) const noexcept {
		return fp_vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
	}
#endif
#if (defined(VK_NV_device_generated_commands))
	void destroyIndirectCommandsLayoutNV(VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
	}
#endif
#if (defined(VK_KHR_push_descriptor))
	void cmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) const noexcept {
		fp_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
	void trimCommandPool(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) const noexcept {
		fp_vkTrimCommandPool(device, commandPool, flags);
	}
#endif
#if (defined(VK_KHR_external_memory_win32))
	VkResult getMemoryWin32HandleKHR(const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) const noexcept {
		return fp_vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#if (defined(VK_KHR_external_memory_win32))
	VkResult getMemoryWin32HandlePropertiesKHR(VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) const noexcept {
		return fp_vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
	}
#endif
#if (defined(VK_KHR_external_memory_fd))
	VkResult getMemoryFdKHR(const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) const noexcept {
		return fp_vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#if (defined(VK_KHR_external_memory_fd))
	VkResult getMemoryFdPropertiesKHR(VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) const noexcept {
		return fp_vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
	}
#endif
#if (defined(VK_FUCHSIA_external_memory))
	VkResult getMemoryZirconHandleFUCHSIA(const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) const noexcept {
		return fp_vkGetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
	}
#endif
#if (defined(VK_FUCHSIA_external_memory))
	VkResult getMemoryZirconHandlePropertiesFUCHSIA(VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) const noexcept {
		return fp_vkGetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
	}
#endif
#if (defined(VK_KHR_external_semaphore_win32))
	VkResult getSemaphoreWin32HandleKHR(const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) const noexcept {
		return fp_vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#if (defined(VK_KHR_external_semaphore_win32))
	VkResult importSemaphoreWin32HandleKHR(const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) const noexcept {
		return fp_vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
	}
#endif
#if (defined(VK_KHR_external_semaphore_fd))
	VkResult getSemaphoreFdKHR(const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) const noexcept {
		return fp_vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#if (defined(VK_KHR_external_semaphore_fd))
	VkResult importSemaphoreFdKHR(const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) const noexcept {
		return fp_vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
	}
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
	VkResult getSemaphoreZirconHandleFUCHSIA(const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) const noexcept {
		return fp_vkGetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
	}
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
	VkResult importSemaphoreZirconHandleFUCHSIA(const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) const noexcept {
		return fp_vkImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
	}
#endif
#if (defined(VK_KHR_external_fence_win32))
	VkResult getFenceWin32HandleKHR(const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) const noexcept {
		return fp_vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
	}
#endif
#if (defined(VK_KHR_external_fence_win32))
	VkResult importFenceWin32HandleKHR(const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) const noexcept {
		return fp_vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
	}
#endif
#if (defined(VK_KHR_external_fence_fd))
	VkResult getFenceFdKHR(const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) const noexcept {
		return fp_vkGetFenceFdKHR(device, pGetFdInfo, pFd);
	}
#endif
#if (defined(VK_KHR_external_fence_fd))
	VkResult importFenceFdKHR(const VkImportFenceFdInfoKHR* pImportFenceFdInfo) const noexcept {
		return fp_vkImportFenceFdKHR(device, pImportFenceFdInfo);
	}
#endif
#if (defined(VK_EXT_display_control))
	VkResult displayPowerControlEXT(VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) const noexcept {
		return fp_vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
	}
#endif
#if (defined(VK_EXT_display_control))
	VkResult registerDeviceEventEXT(const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const noexcept {
		return fp_vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
	}
#endif
#if (defined(VK_EXT_display_control))
	VkResult registerDisplayEventEXT(VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const noexcept {
		return fp_vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
	}
#endif
#if (defined(VK_EXT_display_control))
	VkResult getSwapchainCounterEXT(VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) const noexcept {
		return fp_vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void getDeviceGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) const noexcept {
		fp_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	VkResult bindBufferMemory2(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) const noexcept {
		return fp_vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	VkResult bindImageMemory2(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) const noexcept {
		return fp_vkBindImageMemory2(device, bindInfoCount, pBindInfos);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void cmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) const noexcept {
		fp_vkCmdSetDeviceMask(commandBuffer, deviceMask);
	}
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
	VkResult getDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) const noexcept {
		return fp_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
	}
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
	VkResult getDeviceGroupSurfacePresentModesKHR(VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) const noexcept {
		return fp_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
	}
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain))
	VkResult acquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) const noexcept {
		return fp_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void cmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const noexcept {
		fp_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	VkResult createDescriptorUpdateTemplate(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const noexcept {
		return fp_vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	void destroyDescriptorUpdateTemplate(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	void updateDescriptorSetWithTemplate(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) const noexcept {
		fp_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
	}
#endif
#if (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template)) || (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor))
	void cmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) const noexcept {
		fp_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
	}
#endif
#if (defined(VK_EXT_hdr_metadata))
	void setHdrMetadataEXT(uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) const noexcept {
		fp_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
	}
#endif
#if (defined(VK_KHR_shared_presentable_image))
	VkResult getSwapchainStatusKHR(VkSwapchainKHR swapchain) const noexcept {
		return fp_vkGetSwapchainStatusKHR(device, swapchain);
	}
#endif
#if (defined(VK_GOOGLE_display_timing))
	VkResult getRefreshCycleDurationGOOGLE(VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) const noexcept {
		return fp_vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
	}
#endif
#if (defined(VK_GOOGLE_display_timing))
	VkResult getPastPresentationTimingGOOGLE(VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) const noexcept {
		return fp_vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
	}
#endif
#if (defined(VK_NV_clip_space_w_scaling))
	void cmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) const noexcept {
		fp_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
	}
#endif
#if (defined(VK_EXT_discard_rectangles))
	void cmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) const noexcept {
		fp_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
	}
#endif
#if (defined(VK_EXT_sample_locations))
	void cmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) const noexcept {
		fp_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getBufferMemoryRequirements2(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const noexcept {
		fp_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getImageMemoryRequirements2(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const noexcept {
		fp_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getImageSparseMemoryRequirements2(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const noexcept {
		fp_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	VkResult createSamplerYcbcrConversion(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) const noexcept {
		return fp_vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	void destroySamplerYcbcrConversion(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
	}
#endif
#if (defined(VK_VERSION_1_1))
	void getDeviceQueue2(const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) const noexcept {
		fp_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
	}
#endif
#if (defined(VK_EXT_validation_cache))
	VkResult createValidationCacheEXT(const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) const noexcept {
		return fp_vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
	}
#endif
#if (defined(VK_EXT_validation_cache))
	void destroyValidationCacheEXT(VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
	}
#endif
#if (defined(VK_EXT_validation_cache))
	VkResult getValidationCacheDataEXT(VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) const noexcept {
		return fp_vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
	}
#endif
#if (defined(VK_EXT_validation_cache))
	VkResult mergeValidationCachesEXT(VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) const noexcept {
		return fp_vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
	void getDescriptorSetLayoutSupport(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) const noexcept {
		fp_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
	}
#endif
#if (defined(VK_ANDROID_native_buffer))
	VkResult getSwapchainGrallocUsageANDROID(VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) const noexcept {
		return fp_vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
	}
#endif
#if (defined(VK_ANDROID_native_buffer))
	VkResult getSwapchainGrallocUsage2ANDROID(VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) const noexcept {
		return fp_vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
	}
#endif
#if (defined(VK_ANDROID_native_buffer))
	VkResult acquireImageANDROID(VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) const noexcept {
		return fp_vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
	}
#endif
#if (defined(VK_ANDROID_native_buffer))
	VkResult queueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) const noexcept {
		return fp_vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
	}
#endif
#if (defined(VK_AMD_shader_info))
	VkResult getShaderInfoAMD(VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) const noexcept {
		return fp_vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
	}
#endif
#if (defined(VK_AMD_display_native_hdr))
	void setLocalDimmingAMD(VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) const noexcept {
		fp_vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
	}
#endif
#if (defined(VK_EXT_calibrated_timestamps))
	VkResult getCalibratedTimestampsEXT(uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) const noexcept {
		return fp_vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	VkResult setDebugUtilsObjectNameEXT(const VkDebugUtilsObjectNameInfoEXT* pNameInfo) const noexcept {
		return fp_vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	VkResult setDebugUtilsObjectTagEXT(const VkDebugUtilsObjectTagInfoEXT* pTagInfo) const noexcept {
		return fp_vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void queueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const noexcept {
		fp_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void queueEndDebugUtilsLabelEXT(VkQueue queue) const noexcept {
		fp_vkQueueEndDebugUtilsLabelEXT(queue);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void queueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const noexcept {
		fp_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void cmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const noexcept {
		fp_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void cmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) const noexcept {
		fp_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
	}
#endif
#if (defined(VK_EXT_debug_utils))
	void cmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const noexcept {
		fp_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	}
#endif
#if (defined(VK_EXT_external_memory_host))
	VkResult getMemoryHostPointerPropertiesEXT(VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) const noexcept {
		return fp_vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
	}
#endif
#if (defined(VK_AMD_buffer_marker))
	void cmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) const noexcept {
		fp_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	VkResult createRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const noexcept {
		return fp_vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) const noexcept {
		fp_vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) const noexcept {
		fp_vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) const noexcept {
		fp_vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult getSemaphoreCounterValue(VkSemaphore semaphore, uint64_t* pValue) const noexcept {
		return fp_vkGetSemaphoreCounterValue(device, semaphore, pValue);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult waitSemaphores(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) const noexcept {
		return fp_vkWaitSemaphores(device, pWaitInfo, timeout);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult signalSemaphore(const VkSemaphoreSignalInfo* pSignalInfo) const noexcept {
		return fp_vkSignalSemaphore(device, pSignalInfo);
	}
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
	VkResult getAndroidHardwareBufferPropertiesANDROID(AHardwareBuffer buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) const noexcept {
		return fp_vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
	}
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
	VkResult getMemoryAndroidHardwareBufferANDROID(const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, AHardwareBuffer pBuffer) const noexcept {
		return fp_vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	void cmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	void cmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
	void cmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) const noexcept {
		fp_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
	}
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
	void getQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) const noexcept {
		fp_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) const noexcept {
		fp_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) const noexcept {
		fp_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) const noexcept {
		fp_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) const noexcept {
		fp_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) const noexcept {
		fp_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
	}
#endif
#if (defined(VK_EXT_transform_feedback))
	void cmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) const noexcept {
		fp_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
	}
#endif
#if (defined(VK_NV_scissor_exclusive))
	void cmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) const noexcept {
		fp_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
	}
#endif
#if (defined(VK_NV_shading_rate_image))
	void cmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) const noexcept {
		fp_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
	}
#endif
#if (defined(VK_NV_shading_rate_image))
	void cmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) const noexcept {
		fp_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
	}
#endif
#if (defined(VK_NV_shading_rate_image))
	void cmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) const noexcept {
		fp_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
	}
#endif
#if (defined(VK_NV_mesh_shader))
	void cmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) const noexcept {
		fp_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
	}
#endif
#if (defined(VK_NV_mesh_shader))
	void cmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
	}
#endif
#if (defined(VK_NV_mesh_shader))
	void cmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	VkResult compileDeferredNV(VkPipeline pipeline, uint32_t shader) const noexcept {
		return fp_vkCompileDeferredNV(device, pipeline, shader);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	VkResult createAccelerationStructureNV(const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) const noexcept {
		return fp_vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void destroyAccelerationStructureKHR(VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void destroyAccelerationStructureNV(VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void getAccelerationStructureMemoryRequirementsNV(const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) const noexcept {
		fp_vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	VkResult bindAccelerationStructureMemoryNV(uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) const noexcept {
		return fp_vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void cmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) const noexcept {
		fp_vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) const noexcept {
		fp_vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult copyAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) const noexcept {
		return fp_vkCopyAccelerationStructureKHR(device, deferredOperation, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) const noexcept {
		fp_vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult copyAccelerationStructureToMemoryKHR(VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) const noexcept {
		return fp_vkCopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) const noexcept {
		fp_vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult copyMemoryToAccelerationStructureKHR(VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) const noexcept {
		return fp_vkCopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) const noexcept {
		fp_vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void cmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) const noexcept {
		fp_vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void cmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) const noexcept {
		fp_vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult writeAccelerationStructuresPropertiesKHR(uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) const noexcept {
		return fp_vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	void cmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) const noexcept {
		fp_vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	void cmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) const noexcept {
		fp_vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
	VkResult getRayTracingShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) const noexcept {
		return fp_vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	VkResult getRayTracingCaptureReplayShaderGroupHandlesKHR(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) const noexcept {
		return fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	VkResult getAccelerationStructureHandleNV(VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) const noexcept {
		return fp_vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
	}
#endif
#if (defined(VK_NV_ray_tracing))
	VkResult createRayTracingPipelinesNV(VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const noexcept {
		return fp_vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	VkResult createRayTracingPipelinesKHR(VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const noexcept {
		return fp_vkCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	void cmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) const noexcept {
		fp_vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void getDeviceAccelerationStructureCompatibilityKHR(const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) const noexcept {
		fp_vkGetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	VkDeviceSize getRayTracingShaderGroupStackSizeKHR(VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) const noexcept {
		return fp_vkGetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	void cmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) const noexcept {
		fp_vkCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
	}
#endif
#if (defined(VK_NVX_image_view_handle))
	uint32_t getImageViewHandleNVX(const VkImageViewHandleInfoNVX* pInfo) const noexcept {
		return fp_vkGetImageViewHandleNVX(device, pInfo);
	}
#endif
#if (defined(VK_NVX_image_view_handle))
	VkResult getImageViewAddressNVX(VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) const noexcept {
		return fp_vkGetImageViewAddressNVX(device, imageView, pProperties);
	}
#endif
#if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
	VkResult getDeviceGroupSurfacePresentModes2EXT(const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) const noexcept {
		return fp_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
	}
#endif
#if (defined(VK_EXT_full_screen_exclusive))
	VkResult acquireFullScreenExclusiveModeEXT(VkSwapchainKHR swapchain) const noexcept {
		return fp_vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
	}
#endif
#if (defined(VK_EXT_full_screen_exclusive))
	VkResult releaseFullScreenExclusiveModeEXT(VkSwapchainKHR swapchain) const noexcept {
		return fp_vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
	}
#endif
#if (defined(VK_KHR_performance_query))
	VkResult acquireProfilingLockKHR(const VkAcquireProfilingLockInfoKHR* pInfo) const noexcept {
		return fp_vkAcquireProfilingLockKHR(device, pInfo);
	}
#endif
#if (defined(VK_KHR_performance_query))
	void releaseProfilingLockKHR() const noexcept {
		fp_vkReleaseProfilingLockKHR(device);
	}
#endif
#if (defined(VK_EXT_image_drm_format_modifier))
	VkResult getImageDrmFormatModifierPropertiesEXT(VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) const noexcept {
		return fp_vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	uint64_t getBufferOpaqueCaptureAddress(const VkBufferDeviceAddressInfo* pInfo) const noexcept {
		return fp_vkGetBufferOpaqueCaptureAddress(device, pInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
	VkDeviceAddress getBufferDeviceAddress(const VkBufferDeviceAddressInfo* pInfo) const noexcept {
		return fp_vkGetBufferDeviceAddress(device, pInfo);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult initializePerformanceApiINTEL(const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) const noexcept {
		return fp_vkInitializePerformanceApiINTEL(device, pInitializeInfo);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	void uninitializePerformanceApiINTEL() const noexcept {
		fp_vkUninitializePerformanceApiINTEL(device);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult cmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) const noexcept {
		return fp_vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult cmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) const noexcept {
		return fp_vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult cmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) const noexcept {
		return fp_vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult acquirePerformanceConfigurationINTEL(const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) const noexcept {
		return fp_vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult releasePerformanceConfigurationINTEL(VkPerformanceConfigurationINTEL configuration) const noexcept {
		return fp_vkReleasePerformanceConfigurationINTEL(device, configuration);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult queueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) const noexcept {
		return fp_vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
	}
#endif
#if (defined(VK_INTEL_performance_query))
	VkResult getPerformanceParameterINTEL(VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) const noexcept {
		return fp_vkGetPerformanceParameterINTEL(device, parameter, pValue);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	uint64_t getDeviceMemoryOpaqueCaptureAddress(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const noexcept {
		return fp_vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
	}
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	VkResult getPipelineExecutablePropertiesKHR(const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) const noexcept {
		return fp_vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
	}
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	VkResult getPipelineExecutableStatisticsKHR(const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) const noexcept {
		return fp_vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
	}
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	VkResult getPipelineExecutableInternalRepresentationsKHR(const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) const noexcept {
		return fp_vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
	}
#endif
#if (defined(VK_EXT_line_rasterization))
	void cmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) const noexcept {
		fp_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult createAccelerationStructureKHR(const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) const noexcept {
		return fp_vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) const noexcept {
		fp_vkCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void cmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) const noexcept {
		fp_vkCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkResult buildAccelerationStructuresKHR(VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) const noexcept {
		return fp_vkBuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	VkDeviceAddress getAccelerationStructureDeviceAddressKHR(const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) const noexcept {
		return fp_vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
	}
#endif
#if (defined(VK_KHR_deferred_host_operations))
	VkResult createDeferredOperationKHR(const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) const noexcept {
		return fp_vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
	}
#endif
#if (defined(VK_KHR_deferred_host_operations))
	void destroyDeferredOperationKHR(VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyDeferredOperationKHR(device, operation, pAllocator);
	}
#endif
#if (defined(VK_KHR_deferred_host_operations))
	uint32_t getDeferredOperationMaxConcurrencyKHR(VkDeferredOperationKHR operation) const noexcept {
		return fp_vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
	}
#endif
#if (defined(VK_KHR_deferred_host_operations))
	VkResult getDeferredOperationResultKHR(VkDeferredOperationKHR operation) const noexcept {
		return fp_vkGetDeferredOperationResultKHR(device, operation);
	}
#endif
#if (defined(VK_KHR_deferred_host_operations))
	VkResult deferredOperationJoinKHR(VkDeferredOperationKHR operation) const noexcept {
		return fp_vkDeferredOperationJoinKHR(device, operation);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) const noexcept {
		fp_vkCmdSetCullModeEXT(commandBuffer, cullMode);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) const noexcept {
		fp_vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) const noexcept {
		fp_vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) const noexcept {
		fp_vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) const noexcept {
		fp_vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) const noexcept {
		fp_vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) const noexcept {
		fp_vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) const noexcept {
		fp_vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) const noexcept {
		fp_vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) const noexcept {
		fp_vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) const noexcept {
		fp_vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	void cmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) const noexcept {
		fp_vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	void cmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) const noexcept {
		fp_vkCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	void cmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) const noexcept {
		fp_vkCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	void cmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) const noexcept {
		fp_vkCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	void cmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) const noexcept {
		fp_vkCmdSetLogicOpEXT(commandBuffer, logicOp);
	}
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	void cmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) const noexcept {
		fp_vkCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
	}
#endif
#if (defined(VK_EXT_private_data))
	VkResult createPrivateDataSlotEXT(const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot) const noexcept {
		return fp_vkCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
	}
#endif
#if (defined(VK_EXT_private_data))
	void destroyPrivateDataSlotEXT(VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
	}
#endif
#if (defined(VK_EXT_private_data))
	VkResult setPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data) const noexcept {
		return fp_vkSetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
	}
#endif
#if (defined(VK_EXT_private_data))
	void getPrivateDataEXT(VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData) const noexcept {
		fp_vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) const noexcept {
		fp_vkCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) const noexcept {
		fp_vkCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) const noexcept {
		fp_vkCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) const noexcept {
		fp_vkCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) const noexcept {
		fp_vkCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
	}
#endif
#if (defined(VK_KHR_copy_commands2))
	void cmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) const noexcept {
		fp_vkCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
	}
#endif
#if (defined(VK_KHR_fragment_shading_rate))
	void cmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, VkFragmentShadingRateCombinerOpKHR combinerOps[2]) const noexcept {
		fp_vkCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
	}
#endif
#if (defined(VK_NV_fragment_shading_rate_enums))
	void cmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, VkFragmentShadingRateCombinerOpKHR combinerOps[2]) const noexcept {
		fp_vkCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
	}
#endif
#if (defined(VK_KHR_acceleration_structure))
	void getAccelerationStructureBuildSizesKHR(VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) const noexcept {
		fp_vkGetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
	}
#endif
#if (defined(VK_EXT_vertex_input_dynamic_state))
	void cmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) const noexcept {
		fp_vkCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
	}
#endif
#if (defined(VK_EXT_color_write_enable))
	void cmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) const noexcept {
		fp_vkCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	void cmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfoKHR* pDependencyInfo) const noexcept {
		fp_vkCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	void cmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2KHR stageMask) const noexcept {
		fp_vkCmdResetEvent2KHR(commandBuffer, event, stageMask);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	void cmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfoKHR* pDependencyInfos) const noexcept {
		fp_vkCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	void cmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo) const noexcept {
		fp_vkCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	VkResult queueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2KHR* pSubmits, VkFence fence) const noexcept {
		return fp_vkQueueSubmit2KHR(queue, submitCount, pSubmits, fence);
	}
#endif
#if (defined(VK_KHR_synchronization2))
	void cmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkQueryPool queryPool, uint32_t query) const noexcept {
		fp_vkCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
	}
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
	void cmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) const noexcept {
		fp_vkCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
	}
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
	void getQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) const noexcept {
		fp_vkGetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
	}
#endif
#if (defined(VK_KHR_video_queue))
	VkResult createVideoSessionKHR(const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) const noexcept {
		return fp_vkCreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
	}
#endif
#if (defined(VK_KHR_video_queue))
	void destroyVideoSessionKHR(VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyVideoSessionKHR(device, videoSession, pAllocator);
	}
#endif
#if (defined(VK_KHR_video_queue))
	VkResult createVideoSessionParametersKHR(const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) const noexcept {
		return fp_vkCreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
	}
#endif
#if (defined(VK_KHR_video_queue))
	VkResult updateVideoSessionParametersKHR(VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) const noexcept {
		return fp_vkUpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
	}
#endif
#if (defined(VK_KHR_video_queue))
	void destroyVideoSessionParametersKHR(VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
	}
#endif
#if (defined(VK_KHR_video_queue))
	VkResult getVideoSessionMemoryRequirementsKHR(VkVideoSessionKHR videoSession, uint32_t* pVideoSessionMemoryRequirementsCount, VkVideoGetMemoryPropertiesKHR* pVideoSessionMemoryRequirements) const noexcept {
		return fp_vkGetVideoSessionMemoryRequirementsKHR(device, videoSession, pVideoSessionMemoryRequirementsCount, pVideoSessionMemoryRequirements);
	}
#endif
#if (defined(VK_KHR_video_queue))
	VkResult bindVideoSessionMemoryKHR(VkVideoSessionKHR videoSession, uint32_t videoSessionBindMemoryCount, const VkVideoBindMemoryKHR* pVideoSessionBindMemories) const noexcept {
		return fp_vkBindVideoSessionMemoryKHR(device, videoSession, videoSessionBindMemoryCount, pVideoSessionBindMemories);
	}
#endif
#if (defined(VK_KHR_video_decode_queue))
	void cmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pFrameInfo) const noexcept {
		fp_vkCmdDecodeVideoKHR(commandBuffer, pFrameInfo);
	}
#endif
#if (defined(VK_KHR_video_queue))
	void cmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) const noexcept {
		fp_vkCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
	}
#endif
#if (defined(VK_KHR_video_queue))
	void cmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) const noexcept {
		fp_vkCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
	}
#endif
#if (defined(VK_KHR_video_queue))
	void cmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) const noexcept {
		fp_vkCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
	}
#endif
#if (defined(VK_KHR_video_encode_queue))
	void cmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) const noexcept {
		fp_vkCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
	}
#endif
#if (defined(VK_NVX_binary_import))
	VkResult createCuModuleNVX(const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) const noexcept {
		return fp_vkCreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
	}
#endif
#if (defined(VK_NVX_binary_import))
	VkResult createCuFunctionNVX(const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) const noexcept {
		return fp_vkCreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
	}
#endif
#if (defined(VK_NVX_binary_import))
	void destroyCuModuleNVX(VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyCuModuleNVX(device, module, pAllocator);
	}
#endif
#if (defined(VK_NVX_binary_import))
	void destroyCuFunctionNVX(VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyCuFunctionNVX(device, function, pAllocator);
	}
#endif
#if (defined(VK_NVX_binary_import))
	void cmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) const noexcept {
		fp_vkCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
	void resetQueryPoolEXT(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const noexcept {
		fp_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
	void trimCommandPoolKHR(VkCommandPool commandPool, VkCommandPoolTrimFlags flags) const noexcept {
		fp_vkTrimCommandPoolKHR(device, commandPool, flags);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void getDeviceGroupPeerMemoryFeaturesKHR(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) const noexcept {
		fp_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	VkResult bindBufferMemory2KHR(uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) const noexcept {
		return fp_vkBindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	VkResult bindImageMemory2KHR(uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) const noexcept {
		return fp_vkBindImageMemory2KHR(device, bindInfoCount, pBindInfos);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void cmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) const noexcept {
		fp_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	void cmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const noexcept {
		fp_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	VkResult createDescriptorUpdateTemplateKHR(const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) const noexcept {
		return fp_vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	void destroyDescriptorUpdateTemplateKHR(VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	void updateDescriptorSetWithTemplateKHR(VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) const noexcept {
		fp_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getBufferMemoryRequirements2KHR(const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const noexcept {
		fp_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getImageMemoryRequirements2KHR(const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const noexcept {
		fp_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	void getImageSparseMemoryRequirements2KHR(const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) const noexcept {
		fp_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	VkResult createSamplerYcbcrConversionKHR(const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) const noexcept {
		return fp_vkCreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	void destroySamplerYcbcrConversionKHR(VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) const noexcept {
		fp_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
	}
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
	void getDescriptorSetLayoutSupportKHR(const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) const noexcept {
		fp_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	VkResult createRenderPass2KHR(const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const noexcept {
		return fp_vkCreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) const noexcept {
		fp_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) const noexcept {
		fp_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	void cmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) const noexcept {
		fp_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult getSemaphoreCounterValueKHR(VkSemaphore semaphore, uint64_t* pValue) const noexcept {
		return fp_vkGetSemaphoreCounterValueKHR(device, semaphore, pValue);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult waitSemaphoresKHR(const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) const noexcept {
		return fp_vkWaitSemaphoresKHR(device, pWaitInfo, timeout);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	VkResult signalSemaphoreKHR(const VkSemaphoreSignalInfo* pSignalInfo) const noexcept {
		return fp_vkSignalSemaphoreKHR(device, pSignalInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	void cmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	void cmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const noexcept {
		fp_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	}
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
	VkResult getRayTracingShaderGroupHandlesNV(VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) const noexcept {
		return fp_vkGetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	uint64_t getBufferOpaqueCaptureAddressKHR(const VkBufferDeviceAddressInfo* pInfo) const noexcept {
		return fp_vkGetBufferOpaqueCaptureAddressKHR(device, pInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
	VkDeviceAddress getBufferDeviceAddressEXT(const VkBufferDeviceAddressInfo* pInfo) const noexcept {
		return fp_vkGetBufferDeviceAddressEXT(device, pInfo);
	}
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	uint64_t getDeviceMemoryOpaqueCaptureAddressKHR(const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const noexcept {
		return fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
	}
#endif
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
	PFN_vkGetBufferMemoryRequirements fp_vkGetBufferMemoryRequirements = nullptr;
	PFN_vkBindBufferMemory fp_vkBindBufferMemory = nullptr;
	PFN_vkGetImageMemoryRequirements fp_vkGetImageMemoryRequirements = nullptr;
	PFN_vkBindImageMemory fp_vkBindImageMemory = nullptr;
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
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
	PFN_vkResetQueryPool fp_vkResetQueryPool = nullptr;
#endif
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
#if (defined(VK_EXT_conditional_rendering))
	PFN_vkCmdBeginConditionalRenderingEXT fp_vkCmdBeginConditionalRenderingEXT = nullptr;
#endif
#if (defined(VK_EXT_conditional_rendering))
	PFN_vkCmdEndConditionalRenderingEXT fp_vkCmdEndConditionalRenderingEXT = nullptr;
#endif
	PFN_vkCmdResetQueryPool fp_vkCmdResetQueryPool = nullptr;
	PFN_vkCmdWriteTimestamp fp_vkCmdWriteTimestamp = nullptr;
	PFN_vkCmdCopyQueryPoolResults fp_vkCmdCopyQueryPoolResults = nullptr;
	PFN_vkCmdPushConstants fp_vkCmdPushConstants = nullptr;
	PFN_vkCmdBeginRenderPass fp_vkCmdBeginRenderPass = nullptr;
	PFN_vkCmdNextSubpass fp_vkCmdNextSubpass = nullptr;
	PFN_vkCmdEndRenderPass fp_vkCmdEndRenderPass = nullptr;
	PFN_vkCmdExecuteCommands fp_vkCmdExecuteCommands = nullptr;
#if (defined(VK_KHR_display_swapchain))
	PFN_vkCreateSharedSwapchainsKHR fp_vkCreateSharedSwapchainsKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain))
	PFN_vkCreateSwapchainKHR fp_vkCreateSwapchainKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain))
	PFN_vkDestroySwapchainKHR fp_vkDestroySwapchainKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain))
	PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain))
	PFN_vkAcquireNextImageKHR fp_vkAcquireNextImageKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain))
	PFN_vkQueuePresentKHR fp_vkQueuePresentKHR = nullptr;
#endif
#if (defined(VK_EXT_debug_marker))
	PFN_vkDebugMarkerSetObjectNameEXT fp_vkDebugMarkerSetObjectNameEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_marker))
	PFN_vkDebugMarkerSetObjectTagEXT fp_vkDebugMarkerSetObjectTagEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_marker))
	PFN_vkCmdDebugMarkerBeginEXT fp_vkCmdDebugMarkerBeginEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_marker))
	PFN_vkCmdDebugMarkerEndEXT fp_vkCmdDebugMarkerEndEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_marker))
	PFN_vkCmdDebugMarkerInsertEXT fp_vkCmdDebugMarkerInsertEXT = nullptr;
#endif
#if (defined(VK_NV_external_memory_win32))
	PFN_vkGetMemoryWin32HandleNV fp_vkGetMemoryWin32HandleNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkCmdExecuteGeneratedCommandsNV fp_vkCmdExecuteGeneratedCommandsNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkCmdPreprocessGeneratedCommandsNV fp_vkCmdPreprocessGeneratedCommandsNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkCmdBindPipelineShaderGroupNV fp_vkCmdBindPipelineShaderGroupNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkGetGeneratedCommandsMemoryRequirementsNV fp_vkGetGeneratedCommandsMemoryRequirementsNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkCreateIndirectCommandsLayoutNV fp_vkCreateIndirectCommandsLayoutNV = nullptr;
#endif
#if (defined(VK_NV_device_generated_commands))
	PFN_vkDestroyIndirectCommandsLayoutNV fp_vkDestroyIndirectCommandsLayoutNV = nullptr;
#endif
#if (defined(VK_KHR_push_descriptor))
	PFN_vkCmdPushDescriptorSetKHR fp_vkCmdPushDescriptorSetKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
	PFN_vkTrimCommandPool fp_vkTrimCommandPool = nullptr;
#endif
#if (defined(VK_KHR_external_memory_win32))
	PFN_vkGetMemoryWin32HandleKHR fp_vkGetMemoryWin32HandleKHR = nullptr;
#endif
#if (defined(VK_KHR_external_memory_win32))
	PFN_vkGetMemoryWin32HandlePropertiesKHR fp_vkGetMemoryWin32HandlePropertiesKHR = nullptr;
#endif
#if (defined(VK_KHR_external_memory_fd))
	PFN_vkGetMemoryFdKHR fp_vkGetMemoryFdKHR = nullptr;
#endif
#if (defined(VK_KHR_external_memory_fd))
	PFN_vkGetMemoryFdPropertiesKHR fp_vkGetMemoryFdPropertiesKHR = nullptr;
#endif
#if (defined(VK_FUCHSIA_external_memory))
	PFN_vkGetMemoryZirconHandleFUCHSIA fp_vkGetMemoryZirconHandleFUCHSIA = nullptr;
#endif
#if (defined(VK_FUCHSIA_external_memory))
	PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA fp_vkGetMemoryZirconHandlePropertiesFUCHSIA = nullptr;
#endif
#if (defined(VK_KHR_external_semaphore_win32))
	PFN_vkGetSemaphoreWin32HandleKHR fp_vkGetSemaphoreWin32HandleKHR = nullptr;
#endif
#if (defined(VK_KHR_external_semaphore_win32))
	PFN_vkImportSemaphoreWin32HandleKHR fp_vkImportSemaphoreWin32HandleKHR = nullptr;
#endif
#if (defined(VK_KHR_external_semaphore_fd))
	PFN_vkGetSemaphoreFdKHR fp_vkGetSemaphoreFdKHR = nullptr;
#endif
#if (defined(VK_KHR_external_semaphore_fd))
	PFN_vkImportSemaphoreFdKHR fp_vkImportSemaphoreFdKHR = nullptr;
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
	PFN_vkGetSemaphoreZirconHandleFUCHSIA fp_vkGetSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#if (defined(VK_FUCHSIA_external_semaphore))
	PFN_vkImportSemaphoreZirconHandleFUCHSIA fp_vkImportSemaphoreZirconHandleFUCHSIA = nullptr;
#endif
#if (defined(VK_KHR_external_fence_win32))
	PFN_vkGetFenceWin32HandleKHR fp_vkGetFenceWin32HandleKHR = nullptr;
#endif
#if (defined(VK_KHR_external_fence_win32))
	PFN_vkImportFenceWin32HandleKHR fp_vkImportFenceWin32HandleKHR = nullptr;
#endif
#if (defined(VK_KHR_external_fence_fd))
	PFN_vkGetFenceFdKHR fp_vkGetFenceFdKHR = nullptr;
#endif
#if (defined(VK_KHR_external_fence_fd))
	PFN_vkImportFenceFdKHR fp_vkImportFenceFdKHR = nullptr;
#endif
#if (defined(VK_EXT_display_control))
	PFN_vkDisplayPowerControlEXT fp_vkDisplayPowerControlEXT = nullptr;
#endif
#if (defined(VK_EXT_display_control))
	PFN_vkRegisterDeviceEventEXT fp_vkRegisterDeviceEventEXT = nullptr;
#endif
#if (defined(VK_EXT_display_control))
	PFN_vkRegisterDisplayEventEXT fp_vkRegisterDisplayEventEXT = nullptr;
#endif
#if (defined(VK_EXT_display_control))
	PFN_vkGetSwapchainCounterEXT fp_vkGetSwapchainCounterEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkGetDeviceGroupPeerMemoryFeatures fp_vkGetDeviceGroupPeerMemoryFeatures = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	PFN_vkBindBufferMemory2 fp_vkBindBufferMemory2 = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	PFN_vkBindImageMemory2 fp_vkBindImageMemory2 = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkCmdSetDeviceMask fp_vkCmdSetDeviceMask = nullptr;
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
	PFN_vkGetDeviceGroupPresentCapabilitiesKHR fp_vkGetDeviceGroupPresentCapabilitiesKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_surface))
	PFN_vkGetDeviceGroupSurfacePresentModesKHR fp_vkGetDeviceGroupSurfacePresentModesKHR = nullptr;
#endif
#if (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain))
	PFN_vkAcquireNextImage2KHR fp_vkAcquireNextImage2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkCmdDispatchBase fp_vkCmdDispatchBase = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkCreateDescriptorUpdateTemplate fp_vkCreateDescriptorUpdateTemplate = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkDestroyDescriptorUpdateTemplate fp_vkDestroyDescriptorUpdateTemplate = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkUpdateDescriptorSetWithTemplate fp_vkUpdateDescriptorSetWithTemplate = nullptr;
#endif
#if (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template)) || (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor))
	PFN_vkCmdPushDescriptorSetWithTemplateKHR fp_vkCmdPushDescriptorSetWithTemplateKHR = nullptr;
#endif
#if (defined(VK_EXT_hdr_metadata))
	PFN_vkSetHdrMetadataEXT fp_vkSetHdrMetadataEXT = nullptr;
#endif
#if (defined(VK_KHR_shared_presentable_image))
	PFN_vkGetSwapchainStatusKHR fp_vkGetSwapchainStatusKHR = nullptr;
#endif
#if (defined(VK_GOOGLE_display_timing))
	PFN_vkGetRefreshCycleDurationGOOGLE fp_vkGetRefreshCycleDurationGOOGLE = nullptr;
#endif
#if (defined(VK_GOOGLE_display_timing))
	PFN_vkGetPastPresentationTimingGOOGLE fp_vkGetPastPresentationTimingGOOGLE = nullptr;
#endif
#if (defined(VK_NV_clip_space_w_scaling))
	PFN_vkCmdSetViewportWScalingNV fp_vkCmdSetViewportWScalingNV = nullptr;
#endif
#if (defined(VK_EXT_discard_rectangles))
	PFN_vkCmdSetDiscardRectangleEXT fp_vkCmdSetDiscardRectangleEXT = nullptr;
#endif
#if (defined(VK_EXT_sample_locations))
	PFN_vkCmdSetSampleLocationsEXT fp_vkCmdSetSampleLocationsEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetBufferMemoryRequirements2 fp_vkGetBufferMemoryRequirements2 = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetImageMemoryRequirements2 fp_vkGetImageMemoryRequirements2 = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetImageSparseMemoryRequirements2 fp_vkGetImageSparseMemoryRequirements2 = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	PFN_vkCreateSamplerYcbcrConversion fp_vkCreateSamplerYcbcrConversion = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	PFN_vkDestroySamplerYcbcrConversion fp_vkDestroySamplerYcbcrConversion = nullptr;
#endif
#if (defined(VK_VERSION_1_1))
	PFN_vkGetDeviceQueue2 fp_vkGetDeviceQueue2 = nullptr;
#endif
#if (defined(VK_EXT_validation_cache))
	PFN_vkCreateValidationCacheEXT fp_vkCreateValidationCacheEXT = nullptr;
#endif
#if (defined(VK_EXT_validation_cache))
	PFN_vkDestroyValidationCacheEXT fp_vkDestroyValidationCacheEXT = nullptr;
#endif
#if (defined(VK_EXT_validation_cache))
	PFN_vkGetValidationCacheDataEXT fp_vkGetValidationCacheDataEXT = nullptr;
#endif
#if (defined(VK_EXT_validation_cache))
	PFN_vkMergeValidationCachesEXT fp_vkMergeValidationCachesEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
	PFN_vkGetDescriptorSetLayoutSupport fp_vkGetDescriptorSetLayoutSupport = nullptr;
#endif
#if (defined(VK_ANDROID_native_buffer))
	PFN_vkGetSwapchainGrallocUsageANDROID fp_vkGetSwapchainGrallocUsageANDROID = nullptr;
#endif
#if (defined(VK_ANDROID_native_buffer))
	PFN_vkGetSwapchainGrallocUsage2ANDROID fp_vkGetSwapchainGrallocUsage2ANDROID = nullptr;
#endif
#if (defined(VK_ANDROID_native_buffer))
	PFN_vkAcquireImageANDROID fp_vkAcquireImageANDROID = nullptr;
#endif
#if (defined(VK_ANDROID_native_buffer))
	PFN_vkQueueSignalReleaseImageANDROID fp_vkQueueSignalReleaseImageANDROID = nullptr;
#endif
#if (defined(VK_AMD_shader_info))
	PFN_vkGetShaderInfoAMD fp_vkGetShaderInfoAMD = nullptr;
#endif
#if (defined(VK_AMD_display_native_hdr))
	PFN_vkSetLocalDimmingAMD fp_vkSetLocalDimmingAMD = nullptr;
#endif
#if (defined(VK_EXT_calibrated_timestamps))
	PFN_vkGetCalibratedTimestampsEXT fp_vkGetCalibratedTimestampsEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkSetDebugUtilsObjectNameEXT fp_vkSetDebugUtilsObjectNameEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkSetDebugUtilsObjectTagEXT fp_vkSetDebugUtilsObjectTagEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkQueueBeginDebugUtilsLabelEXT fp_vkQueueBeginDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkQueueEndDebugUtilsLabelEXT fp_vkQueueEndDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkQueueInsertDebugUtilsLabelEXT fp_vkQueueInsertDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkCmdBeginDebugUtilsLabelEXT fp_vkCmdBeginDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkCmdEndDebugUtilsLabelEXT fp_vkCmdEndDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_debug_utils))
	PFN_vkCmdInsertDebugUtilsLabelEXT fp_vkCmdInsertDebugUtilsLabelEXT = nullptr;
#endif
#if (defined(VK_EXT_external_memory_host))
	PFN_vkGetMemoryHostPointerPropertiesEXT fp_vkGetMemoryHostPointerPropertiesEXT = nullptr;
#endif
#if (defined(VK_AMD_buffer_marker))
	PFN_vkCmdWriteBufferMarkerAMD fp_vkCmdWriteBufferMarkerAMD = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCreateRenderPass2 fp_vkCreateRenderPass2 = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdBeginRenderPass2 fp_vkCmdBeginRenderPass2 = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdNextSubpass2 fp_vkCmdNextSubpass2 = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdEndRenderPass2 fp_vkCmdEndRenderPass2 = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkGetSemaphoreCounterValue fp_vkGetSemaphoreCounterValue = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkWaitSemaphores fp_vkWaitSemaphores = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkSignalSemaphore fp_vkSignalSemaphore = nullptr;
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
	PFN_vkGetAndroidHardwareBufferPropertiesANDROID fp_vkGetAndroidHardwareBufferPropertiesANDROID = nullptr;
#endif
#if (defined(VK_ANDROID_external_memory_android_hardware_buffer))
	PFN_vkGetMemoryAndroidHardwareBufferANDROID fp_vkGetMemoryAndroidHardwareBufferANDROID = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	PFN_vkCmdDrawIndirectCount fp_vkCmdDrawIndirectCount = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	PFN_vkCmdDrawIndexedIndirectCount fp_vkCmdDrawIndexedIndirectCount = nullptr;
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
	PFN_vkCmdSetCheckpointNV fp_vkCmdSetCheckpointNV = nullptr;
#endif
#if (defined(VK_NV_device_diagnostic_checkpoints))
	PFN_vkGetQueueCheckpointDataNV fp_vkGetQueueCheckpointDataNV = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdBindTransformFeedbackBuffersEXT fp_vkCmdBindTransformFeedbackBuffersEXT = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdBeginTransformFeedbackEXT fp_vkCmdBeginTransformFeedbackEXT = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdEndTransformFeedbackEXT fp_vkCmdEndTransformFeedbackEXT = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdBeginQueryIndexedEXT fp_vkCmdBeginQueryIndexedEXT = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdEndQueryIndexedEXT fp_vkCmdEndQueryIndexedEXT = nullptr;
#endif
#if (defined(VK_EXT_transform_feedback))
	PFN_vkCmdDrawIndirectByteCountEXT fp_vkCmdDrawIndirectByteCountEXT = nullptr;
#endif
#if (defined(VK_NV_scissor_exclusive))
	PFN_vkCmdSetExclusiveScissorNV fp_vkCmdSetExclusiveScissorNV = nullptr;
#endif
#if (defined(VK_NV_shading_rate_image))
	PFN_vkCmdBindShadingRateImageNV fp_vkCmdBindShadingRateImageNV = nullptr;
#endif
#if (defined(VK_NV_shading_rate_image))
	PFN_vkCmdSetViewportShadingRatePaletteNV fp_vkCmdSetViewportShadingRatePaletteNV = nullptr;
#endif
#if (defined(VK_NV_shading_rate_image))
	PFN_vkCmdSetCoarseSampleOrderNV fp_vkCmdSetCoarseSampleOrderNV = nullptr;
#endif
#if (defined(VK_NV_mesh_shader))
	PFN_vkCmdDrawMeshTasksNV fp_vkCmdDrawMeshTasksNV = nullptr;
#endif
#if (defined(VK_NV_mesh_shader))
	PFN_vkCmdDrawMeshTasksIndirectNV fp_vkCmdDrawMeshTasksIndirectNV = nullptr;
#endif
#if (defined(VK_NV_mesh_shader))
	PFN_vkCmdDrawMeshTasksIndirectCountNV fp_vkCmdDrawMeshTasksIndirectCountNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCompileDeferredNV fp_vkCompileDeferredNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCreateAccelerationStructureNV fp_vkCreateAccelerationStructureNV = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkDestroyAccelerationStructureKHR fp_vkDestroyAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkDestroyAccelerationStructureNV fp_vkDestroyAccelerationStructureNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkGetAccelerationStructureMemoryRequirementsNV fp_vkGetAccelerationStructureMemoryRequirementsNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkBindAccelerationStructureMemoryNV fp_vkBindAccelerationStructureMemoryNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCmdCopyAccelerationStructureNV fp_vkCmdCopyAccelerationStructureNV = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdCopyAccelerationStructureKHR fp_vkCmdCopyAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCopyAccelerationStructureKHR fp_vkCopyAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdCopyAccelerationStructureToMemoryKHR fp_vkCmdCopyAccelerationStructureToMemoryKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCopyAccelerationStructureToMemoryKHR fp_vkCopyAccelerationStructureToMemoryKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdCopyMemoryToAccelerationStructureKHR fp_vkCmdCopyMemoryToAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCopyMemoryToAccelerationStructureKHR fp_vkCopyMemoryToAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdWriteAccelerationStructuresPropertiesKHR fp_vkCmdWriteAccelerationStructuresPropertiesKHR = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCmdWriteAccelerationStructuresPropertiesNV fp_vkCmdWriteAccelerationStructuresPropertiesNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCmdBuildAccelerationStructureNV fp_vkCmdBuildAccelerationStructureNV = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkWriteAccelerationStructuresPropertiesKHR fp_vkWriteAccelerationStructuresPropertiesKHR = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkCmdTraceRaysKHR fp_vkCmdTraceRaysKHR = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCmdTraceRaysNV fp_vkCmdTraceRaysNV = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
	PFN_vkGetRayTracingShaderGroupHandlesKHR fp_vkGetRayTracingShaderGroupHandlesKHR = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR fp_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkGetAccelerationStructureHandleNV fp_vkGetAccelerationStructureHandleNV = nullptr;
#endif
#if (defined(VK_NV_ray_tracing))
	PFN_vkCreateRayTracingPipelinesNV fp_vkCreateRayTracingPipelinesNV = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkCreateRayTracingPipelinesKHR fp_vkCreateRayTracingPipelinesKHR = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkCmdTraceRaysIndirectKHR fp_vkCmdTraceRaysIndirectKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkGetDeviceAccelerationStructureCompatibilityKHR fp_vkGetDeviceAccelerationStructureCompatibilityKHR = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkGetRayTracingShaderGroupStackSizeKHR fp_vkGetRayTracingShaderGroupStackSizeKHR = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline))
	PFN_vkCmdSetRayTracingPipelineStackSizeKHR fp_vkCmdSetRayTracingPipelineStackSizeKHR = nullptr;
#endif
#if (defined(VK_NVX_image_view_handle))
	PFN_vkGetImageViewHandleNVX fp_vkGetImageViewHandleNVX = nullptr;
#endif
#if (defined(VK_NVX_image_view_handle))
	PFN_vkGetImageViewAddressNVX fp_vkGetImageViewAddressNVX = nullptr;
#endif
#if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
	PFN_vkGetDeviceGroupSurfacePresentModes2EXT fp_vkGetDeviceGroupSurfacePresentModes2EXT = nullptr;
#endif
#if (defined(VK_EXT_full_screen_exclusive))
	PFN_vkAcquireFullScreenExclusiveModeEXT fp_vkAcquireFullScreenExclusiveModeEXT = nullptr;
#endif
#if (defined(VK_EXT_full_screen_exclusive))
	PFN_vkReleaseFullScreenExclusiveModeEXT fp_vkReleaseFullScreenExclusiveModeEXT = nullptr;
#endif
#if (defined(VK_KHR_performance_query))
	PFN_vkAcquireProfilingLockKHR fp_vkAcquireProfilingLockKHR = nullptr;
#endif
#if (defined(VK_KHR_performance_query))
	PFN_vkReleaseProfilingLockKHR fp_vkReleaseProfilingLockKHR = nullptr;
#endif
#if (defined(VK_EXT_image_drm_format_modifier))
	PFN_vkGetImageDrmFormatModifierPropertiesEXT fp_vkGetImageDrmFormatModifierPropertiesEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	PFN_vkGetBufferOpaqueCaptureAddress fp_vkGetBufferOpaqueCaptureAddress = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
	PFN_vkGetBufferDeviceAddress fp_vkGetBufferDeviceAddress = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkInitializePerformanceApiINTEL fp_vkInitializePerformanceApiINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkUninitializePerformanceApiINTEL fp_vkUninitializePerformanceApiINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkCmdSetPerformanceMarkerINTEL fp_vkCmdSetPerformanceMarkerINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkCmdSetPerformanceStreamMarkerINTEL fp_vkCmdSetPerformanceStreamMarkerINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkCmdSetPerformanceOverrideINTEL fp_vkCmdSetPerformanceOverrideINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkAcquirePerformanceConfigurationINTEL fp_vkAcquirePerformanceConfigurationINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkReleasePerformanceConfigurationINTEL fp_vkReleasePerformanceConfigurationINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkQueueSetPerformanceConfigurationINTEL fp_vkQueueSetPerformanceConfigurationINTEL = nullptr;
#endif
#if (defined(VK_INTEL_performance_query))
	PFN_vkGetPerformanceParameterINTEL fp_vkGetPerformanceParameterINTEL = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	PFN_vkGetDeviceMemoryOpaqueCaptureAddress fp_vkGetDeviceMemoryOpaqueCaptureAddress = nullptr;
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	PFN_vkGetPipelineExecutablePropertiesKHR fp_vkGetPipelineExecutablePropertiesKHR = nullptr;
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	PFN_vkGetPipelineExecutableStatisticsKHR fp_vkGetPipelineExecutableStatisticsKHR = nullptr;
#endif
#if (defined(VK_KHR_pipeline_executable_properties))
	PFN_vkGetPipelineExecutableInternalRepresentationsKHR fp_vkGetPipelineExecutableInternalRepresentationsKHR = nullptr;
#endif
#if (defined(VK_EXT_line_rasterization))
	PFN_vkCmdSetLineStippleEXT fp_vkCmdSetLineStippleEXT = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCreateAccelerationStructureKHR fp_vkCreateAccelerationStructureKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdBuildAccelerationStructuresKHR fp_vkCmdBuildAccelerationStructuresKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkCmdBuildAccelerationStructuresIndirectKHR fp_vkCmdBuildAccelerationStructuresIndirectKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkBuildAccelerationStructuresKHR fp_vkBuildAccelerationStructuresKHR = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkGetAccelerationStructureDeviceAddressKHR fp_vkGetAccelerationStructureDeviceAddressKHR = nullptr;
#endif
#if (defined(VK_KHR_deferred_host_operations))
	PFN_vkCreateDeferredOperationKHR fp_vkCreateDeferredOperationKHR = nullptr;
#endif
#if (defined(VK_KHR_deferred_host_operations))
	PFN_vkDestroyDeferredOperationKHR fp_vkDestroyDeferredOperationKHR = nullptr;
#endif
#if (defined(VK_KHR_deferred_host_operations))
	PFN_vkGetDeferredOperationMaxConcurrencyKHR fp_vkGetDeferredOperationMaxConcurrencyKHR = nullptr;
#endif
#if (defined(VK_KHR_deferred_host_operations))
	PFN_vkGetDeferredOperationResultKHR fp_vkGetDeferredOperationResultKHR = nullptr;
#endif
#if (defined(VK_KHR_deferred_host_operations))
	PFN_vkDeferredOperationJoinKHR fp_vkDeferredOperationJoinKHR = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetCullModeEXT fp_vkCmdSetCullModeEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetFrontFaceEXT fp_vkCmdSetFrontFaceEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetPrimitiveTopologyEXT fp_vkCmdSetPrimitiveTopologyEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetViewportWithCountEXT fp_vkCmdSetViewportWithCountEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetScissorWithCountEXT fp_vkCmdSetScissorWithCountEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdBindVertexBuffers2EXT fp_vkCmdBindVertexBuffers2EXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetDepthTestEnableEXT fp_vkCmdSetDepthTestEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetDepthWriteEnableEXT fp_vkCmdSetDepthWriteEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetDepthCompareOpEXT fp_vkCmdSetDepthCompareOpEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetDepthBoundsTestEnableEXT fp_vkCmdSetDepthBoundsTestEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetStencilTestEnableEXT fp_vkCmdSetStencilTestEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state))
	PFN_vkCmdSetStencilOpEXT fp_vkCmdSetStencilOpEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	PFN_vkCmdSetPatchControlPointsEXT fp_vkCmdSetPatchControlPointsEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	PFN_vkCmdSetRasterizerDiscardEnableEXT fp_vkCmdSetRasterizerDiscardEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	PFN_vkCmdSetDepthBiasEnableEXT fp_vkCmdSetDepthBiasEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	PFN_vkCmdSetLogicOpEXT fp_vkCmdSetLogicOpEXT = nullptr;
#endif
#if (defined(VK_EXT_extended_dynamic_state2))
	PFN_vkCmdSetPrimitiveRestartEnableEXT fp_vkCmdSetPrimitiveRestartEnableEXT = nullptr;
#endif
#if (defined(VK_EXT_private_data))
	PFN_vkCreatePrivateDataSlotEXT fp_vkCreatePrivateDataSlotEXT = nullptr;
#endif
#if (defined(VK_EXT_private_data))
	PFN_vkDestroyPrivateDataSlotEXT fp_vkDestroyPrivateDataSlotEXT = nullptr;
#endif
#if (defined(VK_EXT_private_data))
	PFN_vkSetPrivateDataEXT fp_vkSetPrivateDataEXT = nullptr;
#endif
#if (defined(VK_EXT_private_data))
	PFN_vkGetPrivateDataEXT fp_vkGetPrivateDataEXT = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdCopyBuffer2KHR fp_vkCmdCopyBuffer2KHR = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdCopyImage2KHR fp_vkCmdCopyImage2KHR = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdBlitImage2KHR fp_vkCmdBlitImage2KHR = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdCopyBufferToImage2KHR fp_vkCmdCopyBufferToImage2KHR = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdCopyImageToBuffer2KHR fp_vkCmdCopyImageToBuffer2KHR = nullptr;
#endif
#if (defined(VK_KHR_copy_commands2))
	PFN_vkCmdResolveImage2KHR fp_vkCmdResolveImage2KHR = nullptr;
#endif
#if (defined(VK_KHR_fragment_shading_rate))
	PFN_vkCmdSetFragmentShadingRateKHR fp_vkCmdSetFragmentShadingRateKHR = nullptr;
#endif
#if (defined(VK_NV_fragment_shading_rate_enums))
	PFN_vkCmdSetFragmentShadingRateEnumNV fp_vkCmdSetFragmentShadingRateEnumNV = nullptr;
#endif
#if (defined(VK_KHR_acceleration_structure))
	PFN_vkGetAccelerationStructureBuildSizesKHR fp_vkGetAccelerationStructureBuildSizesKHR = nullptr;
#endif
#if (defined(VK_EXT_vertex_input_dynamic_state))
	PFN_vkCmdSetVertexInputEXT fp_vkCmdSetVertexInputEXT = nullptr;
#endif
#if (defined(VK_EXT_color_write_enable))
	PFN_vkCmdSetColorWriteEnableEXT fp_vkCmdSetColorWriteEnableEXT = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkCmdSetEvent2KHR fp_vkCmdSetEvent2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkCmdResetEvent2KHR fp_vkCmdResetEvent2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkCmdWaitEvents2KHR fp_vkCmdWaitEvents2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkCmdPipelineBarrier2KHR fp_vkCmdPipelineBarrier2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkQueueSubmit2KHR fp_vkQueueSubmit2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2))
	PFN_vkCmdWriteTimestamp2KHR fp_vkCmdWriteTimestamp2KHR = nullptr;
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
	PFN_vkCmdWriteBufferMarker2AMD fp_vkCmdWriteBufferMarker2AMD = nullptr;
#endif
#if (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
	PFN_vkGetQueueCheckpointData2NV fp_vkGetQueueCheckpointData2NV = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkCreateVideoSessionKHR fp_vkCreateVideoSessionKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkDestroyVideoSessionKHR fp_vkDestroyVideoSessionKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkCreateVideoSessionParametersKHR fp_vkCreateVideoSessionParametersKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkUpdateVideoSessionParametersKHR fp_vkUpdateVideoSessionParametersKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkDestroyVideoSessionParametersKHR fp_vkDestroyVideoSessionParametersKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkGetVideoSessionMemoryRequirementsKHR fp_vkGetVideoSessionMemoryRequirementsKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkBindVideoSessionMemoryKHR fp_vkBindVideoSessionMemoryKHR = nullptr;
#endif
#if (defined(VK_KHR_video_decode_queue))
	PFN_vkCmdDecodeVideoKHR fp_vkCmdDecodeVideoKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkCmdBeginVideoCodingKHR fp_vkCmdBeginVideoCodingKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkCmdControlVideoCodingKHR fp_vkCmdControlVideoCodingKHR = nullptr;
#endif
#if (defined(VK_KHR_video_queue))
	PFN_vkCmdEndVideoCodingKHR fp_vkCmdEndVideoCodingKHR = nullptr;
#endif
#if (defined(VK_KHR_video_encode_queue))
	PFN_vkCmdEncodeVideoKHR fp_vkCmdEncodeVideoKHR = nullptr;
#endif
#if (defined(VK_NVX_binary_import))
	PFN_vkCreateCuModuleNVX fp_vkCreateCuModuleNVX = nullptr;
#endif
#if (defined(VK_NVX_binary_import))
	PFN_vkCreateCuFunctionNVX fp_vkCreateCuFunctionNVX = nullptr;
#endif
#if (defined(VK_NVX_binary_import))
	PFN_vkDestroyCuModuleNVX fp_vkDestroyCuModuleNVX = nullptr;
#endif
#if (defined(VK_NVX_binary_import))
	PFN_vkDestroyCuFunctionNVX fp_vkDestroyCuFunctionNVX = nullptr;
#endif
#if (defined(VK_NVX_binary_import))
	PFN_vkCmdCuLaunchKernelNVX fp_vkCmdCuLaunchKernelNVX = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_host_query_reset))
	PFN_vkResetQueryPoolEXT fp_vkResetQueryPoolEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance1))
	PFN_vkTrimCommandPoolKHR fp_vkTrimCommandPoolKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR fp_vkGetDeviceGroupPeerMemoryFeaturesKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	PFN_vkBindBufferMemory2KHR fp_vkBindBufferMemory2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_bind_memory2))
	PFN_vkBindImageMemory2KHR fp_vkBindImageMemory2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkCmdSetDeviceMaskKHR fp_vkCmdSetDeviceMaskKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_device_group))
	PFN_vkCmdDispatchBaseKHR fp_vkCmdDispatchBaseKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkCreateDescriptorUpdateTemplateKHR fp_vkCreateDescriptorUpdateTemplateKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkDestroyDescriptorUpdateTemplateKHR fp_vkDestroyDescriptorUpdateTemplateKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_descriptor_update_template))
	PFN_vkUpdateDescriptorSetWithTemplateKHR fp_vkUpdateDescriptorSetWithTemplateKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetBufferMemoryRequirements2KHR fp_vkGetBufferMemoryRequirements2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetImageMemoryRequirements2KHR fp_vkGetImageMemoryRequirements2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_get_memory_requirements2))
	PFN_vkGetImageSparseMemoryRequirements2KHR fp_vkGetImageSparseMemoryRequirements2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	PFN_vkCreateSamplerYcbcrConversionKHR fp_vkCreateSamplerYcbcrConversionKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_sampler_ycbcr_conversion))
	PFN_vkDestroySamplerYcbcrConversionKHR fp_vkDestroySamplerYcbcrConversionKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_1)) || (defined(VK_KHR_maintenance3))
	PFN_vkGetDescriptorSetLayoutSupportKHR fp_vkGetDescriptorSetLayoutSupportKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCreateRenderPass2KHR fp_vkCreateRenderPass2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdBeginRenderPass2KHR fp_vkCmdBeginRenderPass2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdNextSubpass2KHR fp_vkCmdNextSubpass2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_create_renderpass2))
	PFN_vkCmdEndRenderPass2KHR fp_vkCmdEndRenderPass2KHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkGetSemaphoreCounterValueKHR fp_vkGetSemaphoreCounterValueKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkWaitSemaphoresKHR fp_vkWaitSemaphoresKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_timeline_semaphore))
	PFN_vkSignalSemaphoreKHR fp_vkSignalSemaphoreKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	PFN_vkCmdDrawIndirectCountAMD fp_vkCmdDrawIndirectCountAMD = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_AMD_draw_indirect_count))
	PFN_vkCmdDrawIndexedIndirectCountAMD fp_vkCmdDrawIndexedIndirectCountAMD = nullptr;
#endif
#if (defined(VK_KHR_ray_tracing_pipeline)) || (defined(VK_NV_ray_tracing))
	PFN_vkGetRayTracingShaderGroupHandlesNV fp_vkGetRayTracingShaderGroupHandlesNV = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	PFN_vkGetBufferOpaqueCaptureAddressKHR fp_vkGetBufferOpaqueCaptureAddressKHR = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_EXT_buffer_device_address))
	PFN_vkGetBufferDeviceAddressEXT fp_vkGetBufferDeviceAddressEXT = nullptr;
#endif
#if (defined(VK_VERSION_1_2)) || (defined(VK_KHR_buffer_device_address))
	PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR fp_vkGetDeviceMemoryOpaqueCaptureAddressKHR = nullptr;
#endif
	bool is_populated() const { return populated; }
	VkDevice device = VK_NULL_HANDLE;
private:
	 bool populated = false;
};

} // namespace vkb