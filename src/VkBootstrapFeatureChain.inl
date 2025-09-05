/*
 * Copyright © 2025 Charles Giessen (charles@lunarg.com)
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
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace vkb::detail {

void compare_VkPhysicalDeviceFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceFeatures const& supported, VkPhysicalDeviceFeatures const& requested) {
    if (requested.robustBufferAccess && !supported.robustBufferAccess) {
        error_list.push_back("VkPhysicalDeviceFeatures::robustBufferAccess");
    }
    if (requested.fullDrawIndexUint32 && !supported.fullDrawIndexUint32) {
        error_list.push_back("VkPhysicalDeviceFeatures::fullDrawIndexUint32");
    }
    if (requested.imageCubeArray && !supported.imageCubeArray) {
        error_list.push_back("VkPhysicalDeviceFeatures::imageCubeArray");
    }
    if (requested.independentBlend && !supported.independentBlend) {
        error_list.push_back("VkPhysicalDeviceFeatures::independentBlend");
    }
    if (requested.geometryShader && !supported.geometryShader) {
        error_list.push_back("VkPhysicalDeviceFeatures::geometryShader");
    }
    if (requested.tessellationShader && !supported.tessellationShader) {
        error_list.push_back("VkPhysicalDeviceFeatures::tessellationShader");
    }
    if (requested.sampleRateShading && !supported.sampleRateShading) {
        error_list.push_back("VkPhysicalDeviceFeatures::sampleRateShading");
    }
    if (requested.dualSrcBlend && !supported.dualSrcBlend) {
        error_list.push_back("VkPhysicalDeviceFeatures::dualSrcBlend");
    }
    if (requested.logicOp && !supported.logicOp) {
        error_list.push_back("VkPhysicalDeviceFeatures::logicOp");
    }
    if (requested.multiDrawIndirect && !supported.multiDrawIndirect) {
        error_list.push_back("VkPhysicalDeviceFeatures::multiDrawIndirect");
    }
    if (requested.drawIndirectFirstInstance && !supported.drawIndirectFirstInstance) {
        error_list.push_back("VkPhysicalDeviceFeatures::drawIndirectFirstInstance");
    }
    if (requested.depthClamp && !supported.depthClamp) {
        error_list.push_back("VkPhysicalDeviceFeatures::depthClamp");
    }
    if (requested.depthBiasClamp && !supported.depthBiasClamp) {
        error_list.push_back("VkPhysicalDeviceFeatures::depthBiasClamp");
    }
    if (requested.fillModeNonSolid && !supported.fillModeNonSolid) {
        error_list.push_back("VkPhysicalDeviceFeatures::fillModeNonSolid");
    }
    if (requested.depthBounds && !supported.depthBounds) {
        error_list.push_back("VkPhysicalDeviceFeatures::depthBounds");
    }
    if (requested.wideLines && !supported.wideLines) {
        error_list.push_back("VkPhysicalDeviceFeatures::wideLines");
    }
    if (requested.largePoints && !supported.largePoints) {
        error_list.push_back("VkPhysicalDeviceFeatures::largePoints");
    }
    if (requested.alphaToOne && !supported.alphaToOne) {
        error_list.push_back("VkPhysicalDeviceFeatures::alphaToOne");
    }
    if (requested.multiViewport && !supported.multiViewport) {
        error_list.push_back("VkPhysicalDeviceFeatures::multiViewport");
    }
    if (requested.samplerAnisotropy && !supported.samplerAnisotropy) {
        error_list.push_back("VkPhysicalDeviceFeatures::samplerAnisotropy");
    }
    if (requested.textureCompressionETC2 && !supported.textureCompressionETC2) {
        error_list.push_back("VkPhysicalDeviceFeatures::textureCompressionETC2");
    }
    if (requested.textureCompressionASTC_LDR && !supported.textureCompressionASTC_LDR) {
        error_list.push_back("VkPhysicalDeviceFeatures::textureCompressionASTC_LDR");
    }
    if (requested.textureCompressionBC && !supported.textureCompressionBC) {
        error_list.push_back("VkPhysicalDeviceFeatures::textureCompressionBC");
    }
    if (requested.occlusionQueryPrecise && !supported.occlusionQueryPrecise) {
        error_list.push_back("VkPhysicalDeviceFeatures::occlusionQueryPrecise");
    }
    if (requested.pipelineStatisticsQuery && !supported.pipelineStatisticsQuery) {
        error_list.push_back("VkPhysicalDeviceFeatures::pipelineStatisticsQuery");
    }
    if (requested.vertexPipelineStoresAndAtomics && !supported.vertexPipelineStoresAndAtomics) {
        error_list.push_back("VkPhysicalDeviceFeatures::vertexPipelineStoresAndAtomics");
    }
    if (requested.fragmentStoresAndAtomics && !supported.fragmentStoresAndAtomics) {
        error_list.push_back("VkPhysicalDeviceFeatures::fragmentStoresAndAtomics");
    }
    if (requested.shaderTessellationAndGeometryPointSize && !supported.shaderTessellationAndGeometryPointSize) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderTessellationAndGeometryPointSize");
    }
    if (requested.shaderImageGatherExtended && !supported.shaderImageGatherExtended) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderImageGatherExtended");
    }
    if (requested.shaderStorageImageExtendedFormats && !supported.shaderStorageImageExtendedFormats) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageImageExtendedFormats");
    }
    if (requested.shaderStorageImageMultisample && !supported.shaderStorageImageMultisample) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageImageMultisample");
    }
    if (requested.shaderStorageImageReadWithoutFormat && !supported.shaderStorageImageReadWithoutFormat) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageImageReadWithoutFormat");
    }
    if (requested.shaderStorageImageWriteWithoutFormat && !supported.shaderStorageImageWriteWithoutFormat) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageImageWriteWithoutFormat");
    }
    if (requested.shaderUniformBufferArrayDynamicIndexing && !supported.shaderUniformBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderUniformBufferArrayDynamicIndexing");
    }
    if (requested.shaderSampledImageArrayDynamicIndexing && !supported.shaderSampledImageArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderSampledImageArrayDynamicIndexing");
    }
    if (requested.shaderStorageBufferArrayDynamicIndexing && !supported.shaderStorageBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageBufferArrayDynamicIndexing");
    }
    if (requested.shaderStorageImageArrayDynamicIndexing && !supported.shaderStorageImageArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderStorageImageArrayDynamicIndexing");
    }
    if (requested.shaderClipDistance && !supported.shaderClipDistance) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderClipDistance");
    }
    if (requested.shaderCullDistance && !supported.shaderCullDistance) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderCullDistance");
    }
    if (requested.shaderFloat64 && !supported.shaderFloat64) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderFloat64");
    }
    if (requested.shaderInt64 && !supported.shaderInt64) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderInt64");
    }
    if (requested.shaderInt16 && !supported.shaderInt16) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderInt16");
    }
    if (requested.shaderResourceResidency && !supported.shaderResourceResidency) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderResourceResidency");
    }
    if (requested.shaderResourceMinLod && !supported.shaderResourceMinLod) {
        error_list.push_back("VkPhysicalDeviceFeatures::shaderResourceMinLod");
    }
    if (requested.sparseBinding && !supported.sparseBinding) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseBinding");
    }
    if (requested.sparseResidencyBuffer && !supported.sparseResidencyBuffer) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidencyBuffer");
    }
    if (requested.sparseResidencyImage2D && !supported.sparseResidencyImage2D) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidencyImage2D");
    }
    if (requested.sparseResidencyImage3D && !supported.sparseResidencyImage3D) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidencyImage3D");
    }
    if (requested.sparseResidency2Samples && !supported.sparseResidency2Samples) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidency2Samples");
    }
    if (requested.sparseResidency4Samples && !supported.sparseResidency4Samples) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidency4Samples");
    }
    if (requested.sparseResidency8Samples && !supported.sparseResidency8Samples) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidency8Samples");
    }
    if (requested.sparseResidency16Samples && !supported.sparseResidency16Samples) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidency16Samples");
    }
    if (requested.sparseResidencyAliased && !supported.sparseResidencyAliased) {
        error_list.push_back("VkPhysicalDeviceFeatures::sparseResidencyAliased");
    }
    if (requested.variableMultisampleRate && !supported.variableMultisampleRate) {
        error_list.push_back("VkPhysicalDeviceFeatures::variableMultisampleRate");
    }
    if (requested.inheritedQueries && !supported.inheritedQueries) {
        error_list.push_back("VkPhysicalDeviceFeatures::inheritedQueries");
    }
}
void merge_VkPhysicalDeviceFeatures(VkPhysicalDeviceFeatures & current, VkPhysicalDeviceFeatures const& merge_in) {
    current.robustBufferAccess = current.robustBufferAccess || merge_in.robustBufferAccess;
    current.fullDrawIndexUint32 = current.fullDrawIndexUint32 || merge_in.fullDrawIndexUint32;
    current.imageCubeArray = current.imageCubeArray || merge_in.imageCubeArray;
    current.independentBlend = current.independentBlend || merge_in.independentBlend;
    current.geometryShader = current.geometryShader || merge_in.geometryShader;
    current.tessellationShader = current.tessellationShader || merge_in.tessellationShader;
    current.sampleRateShading = current.sampleRateShading || merge_in.sampleRateShading;
    current.dualSrcBlend = current.dualSrcBlend || merge_in.dualSrcBlend;
    current.logicOp = current.logicOp || merge_in.logicOp;
    current.multiDrawIndirect = current.multiDrawIndirect || merge_in.multiDrawIndirect;
    current.drawIndirectFirstInstance = current.drawIndirectFirstInstance || merge_in.drawIndirectFirstInstance;
    current.depthClamp = current.depthClamp || merge_in.depthClamp;
    current.depthBiasClamp = current.depthBiasClamp || merge_in.depthBiasClamp;
    current.fillModeNonSolid = current.fillModeNonSolid || merge_in.fillModeNonSolid;
    current.depthBounds = current.depthBounds || merge_in.depthBounds;
    current.wideLines = current.wideLines || merge_in.wideLines;
    current.largePoints = current.largePoints || merge_in.largePoints;
    current.alphaToOne = current.alphaToOne || merge_in.alphaToOne;
    current.multiViewport = current.multiViewport || merge_in.multiViewport;
    current.samplerAnisotropy = current.samplerAnisotropy || merge_in.samplerAnisotropy;
    current.textureCompressionETC2 = current.textureCompressionETC2 || merge_in.textureCompressionETC2;
    current.textureCompressionASTC_LDR = current.textureCompressionASTC_LDR || merge_in.textureCompressionASTC_LDR;
    current.textureCompressionBC = current.textureCompressionBC || merge_in.textureCompressionBC;
    current.occlusionQueryPrecise = current.occlusionQueryPrecise || merge_in.occlusionQueryPrecise;
    current.pipelineStatisticsQuery = current.pipelineStatisticsQuery || merge_in.pipelineStatisticsQuery;
    current.vertexPipelineStoresAndAtomics = current.vertexPipelineStoresAndAtomics || merge_in.vertexPipelineStoresAndAtomics;
    current.fragmentStoresAndAtomics = current.fragmentStoresAndAtomics || merge_in.fragmentStoresAndAtomics;
    current.shaderTessellationAndGeometryPointSize = current.shaderTessellationAndGeometryPointSize || merge_in.shaderTessellationAndGeometryPointSize;
    current.shaderImageGatherExtended = current.shaderImageGatherExtended || merge_in.shaderImageGatherExtended;
    current.shaderStorageImageExtendedFormats = current.shaderStorageImageExtendedFormats || merge_in.shaderStorageImageExtendedFormats;
    current.shaderStorageImageMultisample = current.shaderStorageImageMultisample || merge_in.shaderStorageImageMultisample;
    current.shaderStorageImageReadWithoutFormat = current.shaderStorageImageReadWithoutFormat || merge_in.shaderStorageImageReadWithoutFormat;
    current.shaderStorageImageWriteWithoutFormat = current.shaderStorageImageWriteWithoutFormat || merge_in.shaderStorageImageWriteWithoutFormat;
    current.shaderUniformBufferArrayDynamicIndexing = current.shaderUniformBufferArrayDynamicIndexing || merge_in.shaderUniformBufferArrayDynamicIndexing;
    current.shaderSampledImageArrayDynamicIndexing = current.shaderSampledImageArrayDynamicIndexing || merge_in.shaderSampledImageArrayDynamicIndexing;
    current.shaderStorageBufferArrayDynamicIndexing = current.shaderStorageBufferArrayDynamicIndexing || merge_in.shaderStorageBufferArrayDynamicIndexing;
    current.shaderStorageImageArrayDynamicIndexing = current.shaderStorageImageArrayDynamicIndexing || merge_in.shaderStorageImageArrayDynamicIndexing;
    current.shaderClipDistance = current.shaderClipDistance || merge_in.shaderClipDistance;
    current.shaderCullDistance = current.shaderCullDistance || merge_in.shaderCullDistance;
    current.shaderFloat64 = current.shaderFloat64 || merge_in.shaderFloat64;
    current.shaderInt64 = current.shaderInt64 || merge_in.shaderInt64;
    current.shaderInt16 = current.shaderInt16 || merge_in.shaderInt16;
    current.shaderResourceResidency = current.shaderResourceResidency || merge_in.shaderResourceResidency;
    current.shaderResourceMinLod = current.shaderResourceMinLod || merge_in.shaderResourceMinLod;
    current.sparseBinding = current.sparseBinding || merge_in.sparseBinding;
    current.sparseResidencyBuffer = current.sparseResidencyBuffer || merge_in.sparseResidencyBuffer;
    current.sparseResidencyImage2D = current.sparseResidencyImage2D || merge_in.sparseResidencyImage2D;
    current.sparseResidencyImage3D = current.sparseResidencyImage3D || merge_in.sparseResidencyImage3D;
    current.sparseResidency2Samples = current.sparseResidency2Samples || merge_in.sparseResidency2Samples;
    current.sparseResidency4Samples = current.sparseResidency4Samples || merge_in.sparseResidency4Samples;
    current.sparseResidency8Samples = current.sparseResidency8Samples || merge_in.sparseResidency8Samples;
    current.sparseResidency16Samples = current.sparseResidency16Samples || merge_in.sparseResidency16Samples;
    current.sparseResidencyAliased = current.sparseResidencyAliased || merge_in.sparseResidencyAliased;
    current.variableMultisampleRate = current.variableMultisampleRate || merge_in.variableMultisampleRate;
    current.inheritedQueries = current.inheritedQueries || merge_in.inheritedQueries;
}
void compare_VkPhysicalDevice16BitStorageFeatures(std::vector<std::string> & error_list, VkPhysicalDevice16BitStorageFeatures const& supported, VkPhysicalDevice16BitStorageFeatures const& requested) {
    if (requested.storageBuffer16BitAccess && !supported.storageBuffer16BitAccess) {
        error_list.push_back("VkPhysicalDevice16BitStorageFeatures::storageBuffer16BitAccess");
    }
    if (requested.uniformAndStorageBuffer16BitAccess && !supported.uniformAndStorageBuffer16BitAccess) {
        error_list.push_back("VkPhysicalDevice16BitStorageFeatures::uniformAndStorageBuffer16BitAccess");
    }
    if (requested.storagePushConstant16 && !supported.storagePushConstant16) {
        error_list.push_back("VkPhysicalDevice16BitStorageFeatures::storagePushConstant16");
    }
    if (requested.storageInputOutput16 && !supported.storageInputOutput16) {
        error_list.push_back("VkPhysicalDevice16BitStorageFeatures::storageInputOutput16");
    }
}
void merge_VkPhysicalDevice16BitStorageFeatures(VkPhysicalDevice16BitStorageFeatures & current, VkPhysicalDevice16BitStorageFeatures const& merge_in) {
    current.storageBuffer16BitAccess = current.storageBuffer16BitAccess || merge_in.storageBuffer16BitAccess;
    current.uniformAndStorageBuffer16BitAccess = current.uniformAndStorageBuffer16BitAccess || merge_in.uniformAndStorageBuffer16BitAccess;
    current.storagePushConstant16 = current.storagePushConstant16 || merge_in.storagePushConstant16;
    current.storageInputOutput16 = current.storageInputOutput16 || merge_in.storageInputOutput16;
}
void compare_VkPhysicalDeviceMultiviewFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceMultiviewFeatures const& supported, VkPhysicalDeviceMultiviewFeatures const& requested) {
    if (requested.multiview && !supported.multiview) {
        error_list.push_back("VkPhysicalDeviceMultiviewFeatures::multiview");
    }
    if (requested.multiviewGeometryShader && !supported.multiviewGeometryShader) {
        error_list.push_back("VkPhysicalDeviceMultiviewFeatures::multiviewGeometryShader");
    }
    if (requested.multiviewTessellationShader && !supported.multiviewTessellationShader) {
        error_list.push_back("VkPhysicalDeviceMultiviewFeatures::multiviewTessellationShader");
    }
}
void merge_VkPhysicalDeviceMultiviewFeatures(VkPhysicalDeviceMultiviewFeatures & current, VkPhysicalDeviceMultiviewFeatures const& merge_in) {
    current.multiview = current.multiview || merge_in.multiview;
    current.multiviewGeometryShader = current.multiviewGeometryShader || merge_in.multiviewGeometryShader;
    current.multiviewTessellationShader = current.multiviewTessellationShader || merge_in.multiviewTessellationShader;
}
void compare_VkPhysicalDeviceVariablePointersFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceVariablePointersFeatures const& supported, VkPhysicalDeviceVariablePointersFeatures const& requested) {
    if (requested.variablePointersStorageBuffer && !supported.variablePointersStorageBuffer) {
        error_list.push_back("VkPhysicalDeviceVariablePointersFeatures::variablePointersStorageBuffer");
    }
    if (requested.variablePointers && !supported.variablePointers) {
        error_list.push_back("VkPhysicalDeviceVariablePointersFeatures::variablePointers");
    }
}
void merge_VkPhysicalDeviceVariablePointersFeatures(VkPhysicalDeviceVariablePointersFeatures & current, VkPhysicalDeviceVariablePointersFeatures const& merge_in) {
    current.variablePointersStorageBuffer = current.variablePointersStorageBuffer || merge_in.variablePointersStorageBuffer;
    current.variablePointers = current.variablePointers || merge_in.variablePointers;
}
void compare_VkPhysicalDeviceProtectedMemoryFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceProtectedMemoryFeatures const& supported, VkPhysicalDeviceProtectedMemoryFeatures const& requested) {
    if (requested.protectedMemory && !supported.protectedMemory) {
        error_list.push_back("VkPhysicalDeviceProtectedMemoryFeatures::protectedMemory");
    }
}
void merge_VkPhysicalDeviceProtectedMemoryFeatures(VkPhysicalDeviceProtectedMemoryFeatures & current, VkPhysicalDeviceProtectedMemoryFeatures const& merge_in) {
    current.protectedMemory = current.protectedMemory || merge_in.protectedMemory;
}
void compare_VkPhysicalDeviceSamplerYcbcrConversionFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceSamplerYcbcrConversionFeatures const& supported, VkPhysicalDeviceSamplerYcbcrConversionFeatures const& requested) {
    if (requested.samplerYcbcrConversion && !supported.samplerYcbcrConversion) {
        error_list.push_back("VkPhysicalDeviceSamplerYcbcrConversionFeatures::samplerYcbcrConversion");
    }
}
void merge_VkPhysicalDeviceSamplerYcbcrConversionFeatures(VkPhysicalDeviceSamplerYcbcrConversionFeatures & current, VkPhysicalDeviceSamplerYcbcrConversionFeatures const& merge_in) {
    current.samplerYcbcrConversion = current.samplerYcbcrConversion || merge_in.samplerYcbcrConversion;
}
void compare_VkPhysicalDeviceShaderDrawParametersFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderDrawParametersFeatures const& supported, VkPhysicalDeviceShaderDrawParametersFeatures const& requested) {
    if (requested.shaderDrawParameters && !supported.shaderDrawParameters) {
        error_list.push_back("VkPhysicalDeviceShaderDrawParametersFeatures::shaderDrawParameters");
    }
}
void merge_VkPhysicalDeviceShaderDrawParametersFeatures(VkPhysicalDeviceShaderDrawParametersFeatures & current, VkPhysicalDeviceShaderDrawParametersFeatures const& merge_in) {
    current.shaderDrawParameters = current.shaderDrawParameters || merge_in.shaderDrawParameters;
}
void compare_VkPhysicalDeviceVulkan11Features(std::vector<std::string> & error_list, VkPhysicalDeviceVulkan11Features const& supported, VkPhysicalDeviceVulkan11Features const& requested) {
    if (requested.storageBuffer16BitAccess && !supported.storageBuffer16BitAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::storageBuffer16BitAccess");
    }
    if (requested.uniformAndStorageBuffer16BitAccess && !supported.uniformAndStorageBuffer16BitAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::uniformAndStorageBuffer16BitAccess");
    }
    if (requested.storagePushConstant16 && !supported.storagePushConstant16) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::storagePushConstant16");
    }
    if (requested.storageInputOutput16 && !supported.storageInputOutput16) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::storageInputOutput16");
    }
    if (requested.multiview && !supported.multiview) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::multiview");
    }
    if (requested.multiviewGeometryShader && !supported.multiviewGeometryShader) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::multiviewGeometryShader");
    }
    if (requested.multiviewTessellationShader && !supported.multiviewTessellationShader) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::multiviewTessellationShader");
    }
    if (requested.variablePointersStorageBuffer && !supported.variablePointersStorageBuffer) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::variablePointersStorageBuffer");
    }
    if (requested.variablePointers && !supported.variablePointers) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::variablePointers");
    }
    if (requested.protectedMemory && !supported.protectedMemory) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::protectedMemory");
    }
    if (requested.samplerYcbcrConversion && !supported.samplerYcbcrConversion) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::samplerYcbcrConversion");
    }
    if (requested.shaderDrawParameters && !supported.shaderDrawParameters) {
        error_list.push_back("VkPhysicalDeviceVulkan11Features::shaderDrawParameters");
    }
}
void merge_VkPhysicalDeviceVulkan11Features(VkPhysicalDeviceVulkan11Features & current, VkPhysicalDeviceVulkan11Features const& merge_in) {
    current.storageBuffer16BitAccess = current.storageBuffer16BitAccess || merge_in.storageBuffer16BitAccess;
    current.uniformAndStorageBuffer16BitAccess = current.uniformAndStorageBuffer16BitAccess || merge_in.uniformAndStorageBuffer16BitAccess;
    current.storagePushConstant16 = current.storagePushConstant16 || merge_in.storagePushConstant16;
    current.storageInputOutput16 = current.storageInputOutput16 || merge_in.storageInputOutput16;
    current.multiview = current.multiview || merge_in.multiview;
    current.multiviewGeometryShader = current.multiviewGeometryShader || merge_in.multiviewGeometryShader;
    current.multiviewTessellationShader = current.multiviewTessellationShader || merge_in.multiviewTessellationShader;
    current.variablePointersStorageBuffer = current.variablePointersStorageBuffer || merge_in.variablePointersStorageBuffer;
    current.variablePointers = current.variablePointers || merge_in.variablePointers;
    current.protectedMemory = current.protectedMemory || merge_in.protectedMemory;
    current.samplerYcbcrConversion = current.samplerYcbcrConversion || merge_in.samplerYcbcrConversion;
    current.shaderDrawParameters = current.shaderDrawParameters || merge_in.shaderDrawParameters;
}
void compare_VkPhysicalDeviceVulkan12Features(std::vector<std::string> & error_list, VkPhysicalDeviceVulkan12Features const& supported, VkPhysicalDeviceVulkan12Features const& requested) {
    if (requested.samplerMirrorClampToEdge && !supported.samplerMirrorClampToEdge) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::samplerMirrorClampToEdge");
    }
    if (requested.drawIndirectCount && !supported.drawIndirectCount) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::drawIndirectCount");
    }
    if (requested.storageBuffer8BitAccess && !supported.storageBuffer8BitAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::storageBuffer8BitAccess");
    }
    if (requested.uniformAndStorageBuffer8BitAccess && !supported.uniformAndStorageBuffer8BitAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::uniformAndStorageBuffer8BitAccess");
    }
    if (requested.storagePushConstant8 && !supported.storagePushConstant8) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::storagePushConstant8");
    }
    if (requested.shaderBufferInt64Atomics && !supported.shaderBufferInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderBufferInt64Atomics");
    }
    if (requested.shaderSharedInt64Atomics && !supported.shaderSharedInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderSharedInt64Atomics");
    }
    if (requested.shaderFloat16 && !supported.shaderFloat16) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderFloat16");
    }
    if (requested.shaderInt8 && !supported.shaderInt8) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderInt8");
    }
    if (requested.descriptorIndexing && !supported.descriptorIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorIndexing");
    }
    if (requested.shaderInputAttachmentArrayDynamicIndexing && !supported.shaderInputAttachmentArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderInputAttachmentArrayDynamicIndexing");
    }
    if (requested.shaderUniformTexelBufferArrayDynamicIndexing && !supported.shaderUniformTexelBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayDynamicIndexing");
    }
    if (requested.shaderStorageTexelBufferArrayDynamicIndexing && !supported.shaderStorageTexelBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayDynamicIndexing");
    }
    if (requested.shaderUniformBufferArrayNonUniformIndexing && !supported.shaderUniformBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderUniformBufferArrayNonUniformIndexing");
    }
    if (requested.shaderSampledImageArrayNonUniformIndexing && !supported.shaderSampledImageArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderSampledImageArrayNonUniformIndexing");
    }
    if (requested.shaderStorageBufferArrayNonUniformIndexing && !supported.shaderStorageBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderStorageBufferArrayNonUniformIndexing");
    }
    if (requested.shaderStorageImageArrayNonUniformIndexing && !supported.shaderStorageImageArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderStorageImageArrayNonUniformIndexing");
    }
    if (requested.shaderInputAttachmentArrayNonUniformIndexing && !supported.shaderInputAttachmentArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderInputAttachmentArrayNonUniformIndexing");
    }
    if (requested.shaderUniformTexelBufferArrayNonUniformIndexing && !supported.shaderUniformTexelBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderUniformTexelBufferArrayNonUniformIndexing");
    }
    if (requested.shaderStorageTexelBufferArrayNonUniformIndexing && !supported.shaderStorageTexelBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderStorageTexelBufferArrayNonUniformIndexing");
    }
    if (requested.descriptorBindingUniformBufferUpdateAfterBind && !supported.descriptorBindingUniformBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingUniformBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingSampledImageUpdateAfterBind && !supported.descriptorBindingSampledImageUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingSampledImageUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageImageUpdateAfterBind && !supported.descriptorBindingStorageImageUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingStorageImageUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageBufferUpdateAfterBind && !supported.descriptorBindingStorageBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingStorageBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingUniformTexelBufferUpdateAfterBind && !supported.descriptorBindingUniformTexelBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingUniformTexelBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageTexelBufferUpdateAfterBind && !supported.descriptorBindingStorageTexelBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingStorageTexelBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingUpdateUnusedWhilePending && !supported.descriptorBindingUpdateUnusedWhilePending) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingUpdateUnusedWhilePending");
    }
    if (requested.descriptorBindingPartiallyBound && !supported.descriptorBindingPartiallyBound) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingPartiallyBound");
    }
    if (requested.descriptorBindingVariableDescriptorCount && !supported.descriptorBindingVariableDescriptorCount) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::descriptorBindingVariableDescriptorCount");
    }
    if (requested.runtimeDescriptorArray && !supported.runtimeDescriptorArray) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::runtimeDescriptorArray");
    }
    if (requested.samplerFilterMinmax && !supported.samplerFilterMinmax) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::samplerFilterMinmax");
    }
    if (requested.scalarBlockLayout && !supported.scalarBlockLayout) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::scalarBlockLayout");
    }
    if (requested.imagelessFramebuffer && !supported.imagelessFramebuffer) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::imagelessFramebuffer");
    }
    if (requested.uniformBufferStandardLayout && !supported.uniformBufferStandardLayout) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::uniformBufferStandardLayout");
    }
    if (requested.shaderSubgroupExtendedTypes && !supported.shaderSubgroupExtendedTypes) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderSubgroupExtendedTypes");
    }
    if (requested.separateDepthStencilLayouts && !supported.separateDepthStencilLayouts) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::separateDepthStencilLayouts");
    }
    if (requested.hostQueryReset && !supported.hostQueryReset) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::hostQueryReset");
    }
    if (requested.timelineSemaphore && !supported.timelineSemaphore) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::timelineSemaphore");
    }
    if (requested.bufferDeviceAddress && !supported.bufferDeviceAddress) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::bufferDeviceAddress");
    }
    if (requested.bufferDeviceAddressCaptureReplay && !supported.bufferDeviceAddressCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::bufferDeviceAddressCaptureReplay");
    }
    if (requested.bufferDeviceAddressMultiDevice && !supported.bufferDeviceAddressMultiDevice) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::bufferDeviceAddressMultiDevice");
    }
    if (requested.vulkanMemoryModel && !supported.vulkanMemoryModel) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::vulkanMemoryModel");
    }
    if (requested.vulkanMemoryModelDeviceScope && !supported.vulkanMemoryModelDeviceScope) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::vulkanMemoryModelDeviceScope");
    }
    if (requested.vulkanMemoryModelAvailabilityVisibilityChains && !supported.vulkanMemoryModelAvailabilityVisibilityChains) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::vulkanMemoryModelAvailabilityVisibilityChains");
    }
    if (requested.shaderOutputViewportIndex && !supported.shaderOutputViewportIndex) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderOutputViewportIndex");
    }
    if (requested.shaderOutputLayer && !supported.shaderOutputLayer) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::shaderOutputLayer");
    }
    if (requested.subgroupBroadcastDynamicId && !supported.subgroupBroadcastDynamicId) {
        error_list.push_back("VkPhysicalDeviceVulkan12Features::subgroupBroadcastDynamicId");
    }
}
void merge_VkPhysicalDeviceVulkan12Features(VkPhysicalDeviceVulkan12Features & current, VkPhysicalDeviceVulkan12Features const& merge_in) {
    current.samplerMirrorClampToEdge = current.samplerMirrorClampToEdge || merge_in.samplerMirrorClampToEdge;
    current.drawIndirectCount = current.drawIndirectCount || merge_in.drawIndirectCount;
    current.storageBuffer8BitAccess = current.storageBuffer8BitAccess || merge_in.storageBuffer8BitAccess;
    current.uniformAndStorageBuffer8BitAccess = current.uniformAndStorageBuffer8BitAccess || merge_in.uniformAndStorageBuffer8BitAccess;
    current.storagePushConstant8 = current.storagePushConstant8 || merge_in.storagePushConstant8;
    current.shaderBufferInt64Atomics = current.shaderBufferInt64Atomics || merge_in.shaderBufferInt64Atomics;
    current.shaderSharedInt64Atomics = current.shaderSharedInt64Atomics || merge_in.shaderSharedInt64Atomics;
    current.shaderFloat16 = current.shaderFloat16 || merge_in.shaderFloat16;
    current.shaderInt8 = current.shaderInt8 || merge_in.shaderInt8;
    current.descriptorIndexing = current.descriptorIndexing || merge_in.descriptorIndexing;
    current.shaderInputAttachmentArrayDynamicIndexing = current.shaderInputAttachmentArrayDynamicIndexing || merge_in.shaderInputAttachmentArrayDynamicIndexing;
    current.shaderUniformTexelBufferArrayDynamicIndexing = current.shaderUniformTexelBufferArrayDynamicIndexing || merge_in.shaderUniformTexelBufferArrayDynamicIndexing;
    current.shaderStorageTexelBufferArrayDynamicIndexing = current.shaderStorageTexelBufferArrayDynamicIndexing || merge_in.shaderStorageTexelBufferArrayDynamicIndexing;
    current.shaderUniformBufferArrayNonUniformIndexing = current.shaderUniformBufferArrayNonUniformIndexing || merge_in.shaderUniformBufferArrayNonUniformIndexing;
    current.shaderSampledImageArrayNonUniformIndexing = current.shaderSampledImageArrayNonUniformIndexing || merge_in.shaderSampledImageArrayNonUniformIndexing;
    current.shaderStorageBufferArrayNonUniformIndexing = current.shaderStorageBufferArrayNonUniformIndexing || merge_in.shaderStorageBufferArrayNonUniformIndexing;
    current.shaderStorageImageArrayNonUniformIndexing = current.shaderStorageImageArrayNonUniformIndexing || merge_in.shaderStorageImageArrayNonUniformIndexing;
    current.shaderInputAttachmentArrayNonUniformIndexing = current.shaderInputAttachmentArrayNonUniformIndexing || merge_in.shaderInputAttachmentArrayNonUniformIndexing;
    current.shaderUniformTexelBufferArrayNonUniformIndexing = current.shaderUniformTexelBufferArrayNonUniformIndexing || merge_in.shaderUniformTexelBufferArrayNonUniformIndexing;
    current.shaderStorageTexelBufferArrayNonUniformIndexing = current.shaderStorageTexelBufferArrayNonUniformIndexing || merge_in.shaderStorageTexelBufferArrayNonUniformIndexing;
    current.descriptorBindingUniformBufferUpdateAfterBind = current.descriptorBindingUniformBufferUpdateAfterBind || merge_in.descriptorBindingUniformBufferUpdateAfterBind;
    current.descriptorBindingSampledImageUpdateAfterBind = current.descriptorBindingSampledImageUpdateAfterBind || merge_in.descriptorBindingSampledImageUpdateAfterBind;
    current.descriptorBindingStorageImageUpdateAfterBind = current.descriptorBindingStorageImageUpdateAfterBind || merge_in.descriptorBindingStorageImageUpdateAfterBind;
    current.descriptorBindingStorageBufferUpdateAfterBind = current.descriptorBindingStorageBufferUpdateAfterBind || merge_in.descriptorBindingStorageBufferUpdateAfterBind;
    current.descriptorBindingUniformTexelBufferUpdateAfterBind = current.descriptorBindingUniformTexelBufferUpdateAfterBind || merge_in.descriptorBindingUniformTexelBufferUpdateAfterBind;
    current.descriptorBindingStorageTexelBufferUpdateAfterBind = current.descriptorBindingStorageTexelBufferUpdateAfterBind || merge_in.descriptorBindingStorageTexelBufferUpdateAfterBind;
    current.descriptorBindingUpdateUnusedWhilePending = current.descriptorBindingUpdateUnusedWhilePending || merge_in.descriptorBindingUpdateUnusedWhilePending;
    current.descriptorBindingPartiallyBound = current.descriptorBindingPartiallyBound || merge_in.descriptorBindingPartiallyBound;
    current.descriptorBindingVariableDescriptorCount = current.descriptorBindingVariableDescriptorCount || merge_in.descriptorBindingVariableDescriptorCount;
    current.runtimeDescriptorArray = current.runtimeDescriptorArray || merge_in.runtimeDescriptorArray;
    current.samplerFilterMinmax = current.samplerFilterMinmax || merge_in.samplerFilterMinmax;
    current.scalarBlockLayout = current.scalarBlockLayout || merge_in.scalarBlockLayout;
    current.imagelessFramebuffer = current.imagelessFramebuffer || merge_in.imagelessFramebuffer;
    current.uniformBufferStandardLayout = current.uniformBufferStandardLayout || merge_in.uniformBufferStandardLayout;
    current.shaderSubgroupExtendedTypes = current.shaderSubgroupExtendedTypes || merge_in.shaderSubgroupExtendedTypes;
    current.separateDepthStencilLayouts = current.separateDepthStencilLayouts || merge_in.separateDepthStencilLayouts;
    current.hostQueryReset = current.hostQueryReset || merge_in.hostQueryReset;
    current.timelineSemaphore = current.timelineSemaphore || merge_in.timelineSemaphore;
    current.bufferDeviceAddress = current.bufferDeviceAddress || merge_in.bufferDeviceAddress;
    current.bufferDeviceAddressCaptureReplay = current.bufferDeviceAddressCaptureReplay || merge_in.bufferDeviceAddressCaptureReplay;
    current.bufferDeviceAddressMultiDevice = current.bufferDeviceAddressMultiDevice || merge_in.bufferDeviceAddressMultiDevice;
    current.vulkanMemoryModel = current.vulkanMemoryModel || merge_in.vulkanMemoryModel;
    current.vulkanMemoryModelDeviceScope = current.vulkanMemoryModelDeviceScope || merge_in.vulkanMemoryModelDeviceScope;
    current.vulkanMemoryModelAvailabilityVisibilityChains = current.vulkanMemoryModelAvailabilityVisibilityChains || merge_in.vulkanMemoryModelAvailabilityVisibilityChains;
    current.shaderOutputViewportIndex = current.shaderOutputViewportIndex || merge_in.shaderOutputViewportIndex;
    current.shaderOutputLayer = current.shaderOutputLayer || merge_in.shaderOutputLayer;
    current.subgroupBroadcastDynamicId = current.subgroupBroadcastDynamicId || merge_in.subgroupBroadcastDynamicId;
}
void compare_VkPhysicalDevice8BitStorageFeatures(std::vector<std::string> & error_list, VkPhysicalDevice8BitStorageFeatures const& supported, VkPhysicalDevice8BitStorageFeatures const& requested) {
    if (requested.storageBuffer8BitAccess && !supported.storageBuffer8BitAccess) {
        error_list.push_back("VkPhysicalDevice8BitStorageFeatures::storageBuffer8BitAccess");
    }
    if (requested.uniformAndStorageBuffer8BitAccess && !supported.uniformAndStorageBuffer8BitAccess) {
        error_list.push_back("VkPhysicalDevice8BitStorageFeatures::uniformAndStorageBuffer8BitAccess");
    }
    if (requested.storagePushConstant8 && !supported.storagePushConstant8) {
        error_list.push_back("VkPhysicalDevice8BitStorageFeatures::storagePushConstant8");
    }
}
void merge_VkPhysicalDevice8BitStorageFeatures(VkPhysicalDevice8BitStorageFeatures & current, VkPhysicalDevice8BitStorageFeatures const& merge_in) {
    current.storageBuffer8BitAccess = current.storageBuffer8BitAccess || merge_in.storageBuffer8BitAccess;
    current.uniformAndStorageBuffer8BitAccess = current.uniformAndStorageBuffer8BitAccess || merge_in.uniformAndStorageBuffer8BitAccess;
    current.storagePushConstant8 = current.storagePushConstant8 || merge_in.storagePushConstant8;
}
void compare_VkPhysicalDeviceShaderAtomicInt64Features(std::vector<std::string> & error_list, VkPhysicalDeviceShaderAtomicInt64Features const& supported, VkPhysicalDeviceShaderAtomicInt64Features const& requested) {
    if (requested.shaderBufferInt64Atomics && !supported.shaderBufferInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicInt64Features::shaderBufferInt64Atomics");
    }
    if (requested.shaderSharedInt64Atomics && !supported.shaderSharedInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicInt64Features::shaderSharedInt64Atomics");
    }
}
void merge_VkPhysicalDeviceShaderAtomicInt64Features(VkPhysicalDeviceShaderAtomicInt64Features & current, VkPhysicalDeviceShaderAtomicInt64Features const& merge_in) {
    current.shaderBufferInt64Atomics = current.shaderBufferInt64Atomics || merge_in.shaderBufferInt64Atomics;
    current.shaderSharedInt64Atomics = current.shaderSharedInt64Atomics || merge_in.shaderSharedInt64Atomics;
}
void compare_VkPhysicalDeviceShaderFloat16Int8Features(std::vector<std::string> & error_list, VkPhysicalDeviceShaderFloat16Int8Features const& supported, VkPhysicalDeviceShaderFloat16Int8Features const& requested) {
    if (requested.shaderFloat16 && !supported.shaderFloat16) {
        error_list.push_back("VkPhysicalDeviceShaderFloat16Int8Features::shaderFloat16");
    }
    if (requested.shaderInt8 && !supported.shaderInt8) {
        error_list.push_back("VkPhysicalDeviceShaderFloat16Int8Features::shaderInt8");
    }
}
void merge_VkPhysicalDeviceShaderFloat16Int8Features(VkPhysicalDeviceShaderFloat16Int8Features & current, VkPhysicalDeviceShaderFloat16Int8Features const& merge_in) {
    current.shaderFloat16 = current.shaderFloat16 || merge_in.shaderFloat16;
    current.shaderInt8 = current.shaderInt8 || merge_in.shaderInt8;
}
void compare_VkPhysicalDeviceDescriptorIndexingFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceDescriptorIndexingFeatures const& supported, VkPhysicalDeviceDescriptorIndexingFeatures const& requested) {
    if (requested.shaderInputAttachmentArrayDynamicIndexing && !supported.shaderInputAttachmentArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderInputAttachmentArrayDynamicIndexing");
    }
    if (requested.shaderUniformTexelBufferArrayDynamicIndexing && !supported.shaderUniformTexelBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderUniformTexelBufferArrayDynamicIndexing");
    }
    if (requested.shaderStorageTexelBufferArrayDynamicIndexing && !supported.shaderStorageTexelBufferArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderStorageTexelBufferArrayDynamicIndexing");
    }
    if (requested.shaderUniformBufferArrayNonUniformIndexing && !supported.shaderUniformBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderUniformBufferArrayNonUniformIndexing");
    }
    if (requested.shaderSampledImageArrayNonUniformIndexing && !supported.shaderSampledImageArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderSampledImageArrayNonUniformIndexing");
    }
    if (requested.shaderStorageBufferArrayNonUniformIndexing && !supported.shaderStorageBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderStorageBufferArrayNonUniformIndexing");
    }
    if (requested.shaderStorageImageArrayNonUniformIndexing && !supported.shaderStorageImageArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderStorageImageArrayNonUniformIndexing");
    }
    if (requested.shaderInputAttachmentArrayNonUniformIndexing && !supported.shaderInputAttachmentArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderInputAttachmentArrayNonUniformIndexing");
    }
    if (requested.shaderUniformTexelBufferArrayNonUniformIndexing && !supported.shaderUniformTexelBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderUniformTexelBufferArrayNonUniformIndexing");
    }
    if (requested.shaderStorageTexelBufferArrayNonUniformIndexing && !supported.shaderStorageTexelBufferArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::shaderStorageTexelBufferArrayNonUniformIndexing");
    }
    if (requested.descriptorBindingUniformBufferUpdateAfterBind && !supported.descriptorBindingUniformBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingUniformBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingSampledImageUpdateAfterBind && !supported.descriptorBindingSampledImageUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingSampledImageUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageImageUpdateAfterBind && !supported.descriptorBindingStorageImageUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingStorageImageUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageBufferUpdateAfterBind && !supported.descriptorBindingStorageBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingStorageBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingUniformTexelBufferUpdateAfterBind && !supported.descriptorBindingUniformTexelBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingUniformTexelBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingStorageTexelBufferUpdateAfterBind && !supported.descriptorBindingStorageTexelBufferUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingStorageTexelBufferUpdateAfterBind");
    }
    if (requested.descriptorBindingUpdateUnusedWhilePending && !supported.descriptorBindingUpdateUnusedWhilePending) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingUpdateUnusedWhilePending");
    }
    if (requested.descriptorBindingPartiallyBound && !supported.descriptorBindingPartiallyBound) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingPartiallyBound");
    }
    if (requested.descriptorBindingVariableDescriptorCount && !supported.descriptorBindingVariableDescriptorCount) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::descriptorBindingVariableDescriptorCount");
    }
    if (requested.runtimeDescriptorArray && !supported.runtimeDescriptorArray) {
        error_list.push_back("VkPhysicalDeviceDescriptorIndexingFeatures::runtimeDescriptorArray");
    }
}
void merge_VkPhysicalDeviceDescriptorIndexingFeatures(VkPhysicalDeviceDescriptorIndexingFeatures & current, VkPhysicalDeviceDescriptorIndexingFeatures const& merge_in) {
    current.shaderInputAttachmentArrayDynamicIndexing = current.shaderInputAttachmentArrayDynamicIndexing || merge_in.shaderInputAttachmentArrayDynamicIndexing;
    current.shaderUniformTexelBufferArrayDynamicIndexing = current.shaderUniformTexelBufferArrayDynamicIndexing || merge_in.shaderUniformTexelBufferArrayDynamicIndexing;
    current.shaderStorageTexelBufferArrayDynamicIndexing = current.shaderStorageTexelBufferArrayDynamicIndexing || merge_in.shaderStorageTexelBufferArrayDynamicIndexing;
    current.shaderUniformBufferArrayNonUniformIndexing = current.shaderUniformBufferArrayNonUniformIndexing || merge_in.shaderUniformBufferArrayNonUniformIndexing;
    current.shaderSampledImageArrayNonUniformIndexing = current.shaderSampledImageArrayNonUniformIndexing || merge_in.shaderSampledImageArrayNonUniformIndexing;
    current.shaderStorageBufferArrayNonUniformIndexing = current.shaderStorageBufferArrayNonUniformIndexing || merge_in.shaderStorageBufferArrayNonUniformIndexing;
    current.shaderStorageImageArrayNonUniformIndexing = current.shaderStorageImageArrayNonUniformIndexing || merge_in.shaderStorageImageArrayNonUniformIndexing;
    current.shaderInputAttachmentArrayNonUniformIndexing = current.shaderInputAttachmentArrayNonUniformIndexing || merge_in.shaderInputAttachmentArrayNonUniformIndexing;
    current.shaderUniformTexelBufferArrayNonUniformIndexing = current.shaderUniformTexelBufferArrayNonUniformIndexing || merge_in.shaderUniformTexelBufferArrayNonUniformIndexing;
    current.shaderStorageTexelBufferArrayNonUniformIndexing = current.shaderStorageTexelBufferArrayNonUniformIndexing || merge_in.shaderStorageTexelBufferArrayNonUniformIndexing;
    current.descriptorBindingUniformBufferUpdateAfterBind = current.descriptorBindingUniformBufferUpdateAfterBind || merge_in.descriptorBindingUniformBufferUpdateAfterBind;
    current.descriptorBindingSampledImageUpdateAfterBind = current.descriptorBindingSampledImageUpdateAfterBind || merge_in.descriptorBindingSampledImageUpdateAfterBind;
    current.descriptorBindingStorageImageUpdateAfterBind = current.descriptorBindingStorageImageUpdateAfterBind || merge_in.descriptorBindingStorageImageUpdateAfterBind;
    current.descriptorBindingStorageBufferUpdateAfterBind = current.descriptorBindingStorageBufferUpdateAfterBind || merge_in.descriptorBindingStorageBufferUpdateAfterBind;
    current.descriptorBindingUniformTexelBufferUpdateAfterBind = current.descriptorBindingUniformTexelBufferUpdateAfterBind || merge_in.descriptorBindingUniformTexelBufferUpdateAfterBind;
    current.descriptorBindingStorageTexelBufferUpdateAfterBind = current.descriptorBindingStorageTexelBufferUpdateAfterBind || merge_in.descriptorBindingStorageTexelBufferUpdateAfterBind;
    current.descriptorBindingUpdateUnusedWhilePending = current.descriptorBindingUpdateUnusedWhilePending || merge_in.descriptorBindingUpdateUnusedWhilePending;
    current.descriptorBindingPartiallyBound = current.descriptorBindingPartiallyBound || merge_in.descriptorBindingPartiallyBound;
    current.descriptorBindingVariableDescriptorCount = current.descriptorBindingVariableDescriptorCount || merge_in.descriptorBindingVariableDescriptorCount;
    current.runtimeDescriptorArray = current.runtimeDescriptorArray || merge_in.runtimeDescriptorArray;
}
void compare_VkPhysicalDeviceScalarBlockLayoutFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceScalarBlockLayoutFeatures const& supported, VkPhysicalDeviceScalarBlockLayoutFeatures const& requested) {
    if (requested.scalarBlockLayout && !supported.scalarBlockLayout) {
        error_list.push_back("VkPhysicalDeviceScalarBlockLayoutFeatures::scalarBlockLayout");
    }
}
void merge_VkPhysicalDeviceScalarBlockLayoutFeatures(VkPhysicalDeviceScalarBlockLayoutFeatures & current, VkPhysicalDeviceScalarBlockLayoutFeatures const& merge_in) {
    current.scalarBlockLayout = current.scalarBlockLayout || merge_in.scalarBlockLayout;
}
void compare_VkPhysicalDeviceVulkanMemoryModelFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceVulkanMemoryModelFeatures const& supported, VkPhysicalDeviceVulkanMemoryModelFeatures const& requested) {
    if (requested.vulkanMemoryModel && !supported.vulkanMemoryModel) {
        error_list.push_back("VkPhysicalDeviceVulkanMemoryModelFeatures::vulkanMemoryModel");
    }
    if (requested.vulkanMemoryModelDeviceScope && !supported.vulkanMemoryModelDeviceScope) {
        error_list.push_back("VkPhysicalDeviceVulkanMemoryModelFeatures::vulkanMemoryModelDeviceScope");
    }
    if (requested.vulkanMemoryModelAvailabilityVisibilityChains && !supported.vulkanMemoryModelAvailabilityVisibilityChains) {
        error_list.push_back("VkPhysicalDeviceVulkanMemoryModelFeatures::vulkanMemoryModelAvailabilityVisibilityChains");
    }
}
void merge_VkPhysicalDeviceVulkanMemoryModelFeatures(VkPhysicalDeviceVulkanMemoryModelFeatures & current, VkPhysicalDeviceVulkanMemoryModelFeatures const& merge_in) {
    current.vulkanMemoryModel = current.vulkanMemoryModel || merge_in.vulkanMemoryModel;
    current.vulkanMemoryModelDeviceScope = current.vulkanMemoryModelDeviceScope || merge_in.vulkanMemoryModelDeviceScope;
    current.vulkanMemoryModelAvailabilityVisibilityChains = current.vulkanMemoryModelAvailabilityVisibilityChains || merge_in.vulkanMemoryModelAvailabilityVisibilityChains;
}
void compare_VkPhysicalDeviceImagelessFramebufferFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceImagelessFramebufferFeatures const& supported, VkPhysicalDeviceImagelessFramebufferFeatures const& requested) {
    if (requested.imagelessFramebuffer && !supported.imagelessFramebuffer) {
        error_list.push_back("VkPhysicalDeviceImagelessFramebufferFeatures::imagelessFramebuffer");
    }
}
void merge_VkPhysicalDeviceImagelessFramebufferFeatures(VkPhysicalDeviceImagelessFramebufferFeatures & current, VkPhysicalDeviceImagelessFramebufferFeatures const& merge_in) {
    current.imagelessFramebuffer = current.imagelessFramebuffer || merge_in.imagelessFramebuffer;
}
void compare_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceUniformBufferStandardLayoutFeatures const& supported, VkPhysicalDeviceUniformBufferStandardLayoutFeatures const& requested) {
    if (requested.uniformBufferStandardLayout && !supported.uniformBufferStandardLayout) {
        error_list.push_back("VkPhysicalDeviceUniformBufferStandardLayoutFeatures::uniformBufferStandardLayout");
    }
}
void merge_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(VkPhysicalDeviceUniformBufferStandardLayoutFeatures & current, VkPhysicalDeviceUniformBufferStandardLayoutFeatures const& merge_in) {
    current.uniformBufferStandardLayout = current.uniformBufferStandardLayout || merge_in.uniformBufferStandardLayout;
}
void compare_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const& supported, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const& requested) {
    if (requested.shaderSubgroupExtendedTypes && !supported.shaderSubgroupExtendedTypes) {
        error_list.push_back("VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures::shaderSubgroupExtendedTypes");
    }
}
void merge_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures & current, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const& merge_in) {
    current.shaderSubgroupExtendedTypes = current.shaderSubgroupExtendedTypes || merge_in.shaderSubgroupExtendedTypes;
}
void compare_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const& supported, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const& requested) {
    if (requested.separateDepthStencilLayouts && !supported.separateDepthStencilLayouts) {
        error_list.push_back("VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures::separateDepthStencilLayouts");
    }
}
void merge_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures & current, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const& merge_in) {
    current.separateDepthStencilLayouts = current.separateDepthStencilLayouts || merge_in.separateDepthStencilLayouts;
}
void compare_VkPhysicalDeviceHostQueryResetFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceHostQueryResetFeatures const& supported, VkPhysicalDeviceHostQueryResetFeatures const& requested) {
    if (requested.hostQueryReset && !supported.hostQueryReset) {
        error_list.push_back("VkPhysicalDeviceHostQueryResetFeatures::hostQueryReset");
    }
}
void merge_VkPhysicalDeviceHostQueryResetFeatures(VkPhysicalDeviceHostQueryResetFeatures & current, VkPhysicalDeviceHostQueryResetFeatures const& merge_in) {
    current.hostQueryReset = current.hostQueryReset || merge_in.hostQueryReset;
}
void compare_VkPhysicalDeviceTimelineSemaphoreFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceTimelineSemaphoreFeatures const& supported, VkPhysicalDeviceTimelineSemaphoreFeatures const& requested) {
    if (requested.timelineSemaphore && !supported.timelineSemaphore) {
        error_list.push_back("VkPhysicalDeviceTimelineSemaphoreFeatures::timelineSemaphore");
    }
}
void merge_VkPhysicalDeviceTimelineSemaphoreFeatures(VkPhysicalDeviceTimelineSemaphoreFeatures & current, VkPhysicalDeviceTimelineSemaphoreFeatures const& merge_in) {
    current.timelineSemaphore = current.timelineSemaphore || merge_in.timelineSemaphore;
}
void compare_VkPhysicalDeviceBufferDeviceAddressFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceBufferDeviceAddressFeatures const& supported, VkPhysicalDeviceBufferDeviceAddressFeatures const& requested) {
    if (requested.bufferDeviceAddress && !supported.bufferDeviceAddress) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeatures::bufferDeviceAddress");
    }
    if (requested.bufferDeviceAddressCaptureReplay && !supported.bufferDeviceAddressCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeatures::bufferDeviceAddressCaptureReplay");
    }
    if (requested.bufferDeviceAddressMultiDevice && !supported.bufferDeviceAddressMultiDevice) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeatures::bufferDeviceAddressMultiDevice");
    }
}
void merge_VkPhysicalDeviceBufferDeviceAddressFeatures(VkPhysicalDeviceBufferDeviceAddressFeatures & current, VkPhysicalDeviceBufferDeviceAddressFeatures const& merge_in) {
    current.bufferDeviceAddress = current.bufferDeviceAddress || merge_in.bufferDeviceAddress;
    current.bufferDeviceAddressCaptureReplay = current.bufferDeviceAddressCaptureReplay || merge_in.bufferDeviceAddressCaptureReplay;
    current.bufferDeviceAddressMultiDevice = current.bufferDeviceAddressMultiDevice || merge_in.bufferDeviceAddressMultiDevice;
}
void compare_VkPhysicalDeviceVulkan13Features(std::vector<std::string> & error_list, VkPhysicalDeviceVulkan13Features const& supported, VkPhysicalDeviceVulkan13Features const& requested) {
    if (requested.robustImageAccess && !supported.robustImageAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::robustImageAccess");
    }
    if (requested.inlineUniformBlock && !supported.inlineUniformBlock) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::inlineUniformBlock");
    }
    if (requested.descriptorBindingInlineUniformBlockUpdateAfterBind && !supported.descriptorBindingInlineUniformBlockUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::descriptorBindingInlineUniformBlockUpdateAfterBind");
    }
    if (requested.pipelineCreationCacheControl && !supported.pipelineCreationCacheControl) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::pipelineCreationCacheControl");
    }
    if (requested.privateData && !supported.privateData) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::privateData");
    }
    if (requested.shaderDemoteToHelperInvocation && !supported.shaderDemoteToHelperInvocation) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::shaderDemoteToHelperInvocation");
    }
    if (requested.shaderTerminateInvocation && !supported.shaderTerminateInvocation) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::shaderTerminateInvocation");
    }
    if (requested.subgroupSizeControl && !supported.subgroupSizeControl) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::subgroupSizeControl");
    }
    if (requested.computeFullSubgroups && !supported.computeFullSubgroups) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::computeFullSubgroups");
    }
    if (requested.synchronization2 && !supported.synchronization2) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::synchronization2");
    }
    if (requested.textureCompressionASTC_HDR && !supported.textureCompressionASTC_HDR) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::textureCompressionASTC_HDR");
    }
    if (requested.shaderZeroInitializeWorkgroupMemory && !supported.shaderZeroInitializeWorkgroupMemory) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::shaderZeroInitializeWorkgroupMemory");
    }
    if (requested.dynamicRendering && !supported.dynamicRendering) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::dynamicRendering");
    }
    if (requested.shaderIntegerDotProduct && !supported.shaderIntegerDotProduct) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::shaderIntegerDotProduct");
    }
    if (requested.maintenance4 && !supported.maintenance4) {
        error_list.push_back("VkPhysicalDeviceVulkan13Features::maintenance4");
    }
}
void merge_VkPhysicalDeviceVulkan13Features(VkPhysicalDeviceVulkan13Features & current, VkPhysicalDeviceVulkan13Features const& merge_in) {
    current.robustImageAccess = current.robustImageAccess || merge_in.robustImageAccess;
    current.inlineUniformBlock = current.inlineUniformBlock || merge_in.inlineUniformBlock;
    current.descriptorBindingInlineUniformBlockUpdateAfterBind = current.descriptorBindingInlineUniformBlockUpdateAfterBind || merge_in.descriptorBindingInlineUniformBlockUpdateAfterBind;
    current.pipelineCreationCacheControl = current.pipelineCreationCacheControl || merge_in.pipelineCreationCacheControl;
    current.privateData = current.privateData || merge_in.privateData;
    current.shaderDemoteToHelperInvocation = current.shaderDemoteToHelperInvocation || merge_in.shaderDemoteToHelperInvocation;
    current.shaderTerminateInvocation = current.shaderTerminateInvocation || merge_in.shaderTerminateInvocation;
    current.subgroupSizeControl = current.subgroupSizeControl || merge_in.subgroupSizeControl;
    current.computeFullSubgroups = current.computeFullSubgroups || merge_in.computeFullSubgroups;
    current.synchronization2 = current.synchronization2 || merge_in.synchronization2;
    current.textureCompressionASTC_HDR = current.textureCompressionASTC_HDR || merge_in.textureCompressionASTC_HDR;
    current.shaderZeroInitializeWorkgroupMemory = current.shaderZeroInitializeWorkgroupMemory || merge_in.shaderZeroInitializeWorkgroupMemory;
    current.dynamicRendering = current.dynamicRendering || merge_in.dynamicRendering;
    current.shaderIntegerDotProduct = current.shaderIntegerDotProduct || merge_in.shaderIntegerDotProduct;
    current.maintenance4 = current.maintenance4 || merge_in.maintenance4;
}
void compare_VkPhysicalDeviceShaderTerminateInvocationFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderTerminateInvocationFeatures const& supported, VkPhysicalDeviceShaderTerminateInvocationFeatures const& requested) {
    if (requested.shaderTerminateInvocation && !supported.shaderTerminateInvocation) {
        error_list.push_back("VkPhysicalDeviceShaderTerminateInvocationFeatures::shaderTerminateInvocation");
    }
}
void merge_VkPhysicalDeviceShaderTerminateInvocationFeatures(VkPhysicalDeviceShaderTerminateInvocationFeatures & current, VkPhysicalDeviceShaderTerminateInvocationFeatures const& merge_in) {
    current.shaderTerminateInvocation = current.shaderTerminateInvocation || merge_in.shaderTerminateInvocation;
}
void compare_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures const& supported, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures const& requested) {
    if (requested.shaderDemoteToHelperInvocation && !supported.shaderDemoteToHelperInvocation) {
        error_list.push_back("VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures::shaderDemoteToHelperInvocation");
    }
}
void merge_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures & current, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures const& merge_in) {
    current.shaderDemoteToHelperInvocation = current.shaderDemoteToHelperInvocation || merge_in.shaderDemoteToHelperInvocation;
}
void compare_VkPhysicalDevicePrivateDataFeatures(std::vector<std::string> & error_list, VkPhysicalDevicePrivateDataFeatures const& supported, VkPhysicalDevicePrivateDataFeatures const& requested) {
    if (requested.privateData && !supported.privateData) {
        error_list.push_back("VkPhysicalDevicePrivateDataFeatures::privateData");
    }
}
void merge_VkPhysicalDevicePrivateDataFeatures(VkPhysicalDevicePrivateDataFeatures & current, VkPhysicalDevicePrivateDataFeatures const& merge_in) {
    current.privateData = current.privateData || merge_in.privateData;
}
void compare_VkPhysicalDevicePipelineCreationCacheControlFeatures(std::vector<std::string> & error_list, VkPhysicalDevicePipelineCreationCacheControlFeatures const& supported, VkPhysicalDevicePipelineCreationCacheControlFeatures const& requested) {
    if (requested.pipelineCreationCacheControl && !supported.pipelineCreationCacheControl) {
        error_list.push_back("VkPhysicalDevicePipelineCreationCacheControlFeatures::pipelineCreationCacheControl");
    }
}
void merge_VkPhysicalDevicePipelineCreationCacheControlFeatures(VkPhysicalDevicePipelineCreationCacheControlFeatures & current, VkPhysicalDevicePipelineCreationCacheControlFeatures const& merge_in) {
    current.pipelineCreationCacheControl = current.pipelineCreationCacheControl || merge_in.pipelineCreationCacheControl;
}
void compare_VkPhysicalDeviceSynchronization2Features(std::vector<std::string> & error_list, VkPhysicalDeviceSynchronization2Features const& supported, VkPhysicalDeviceSynchronization2Features const& requested) {
    if (requested.synchronization2 && !supported.synchronization2) {
        error_list.push_back("VkPhysicalDeviceSynchronization2Features::synchronization2");
    }
}
void merge_VkPhysicalDeviceSynchronization2Features(VkPhysicalDeviceSynchronization2Features & current, VkPhysicalDeviceSynchronization2Features const& merge_in) {
    current.synchronization2 = current.synchronization2 || merge_in.synchronization2;
}
void compare_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures const& supported, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures const& requested) {
    if (requested.shaderZeroInitializeWorkgroupMemory && !supported.shaderZeroInitializeWorkgroupMemory) {
        error_list.push_back("VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures::shaderZeroInitializeWorkgroupMemory");
    }
}
void merge_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures & current, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures const& merge_in) {
    current.shaderZeroInitializeWorkgroupMemory = current.shaderZeroInitializeWorkgroupMemory || merge_in.shaderZeroInitializeWorkgroupMemory;
}
void compare_VkPhysicalDeviceImageRobustnessFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceImageRobustnessFeatures const& supported, VkPhysicalDeviceImageRobustnessFeatures const& requested) {
    if (requested.robustImageAccess && !supported.robustImageAccess) {
        error_list.push_back("VkPhysicalDeviceImageRobustnessFeatures::robustImageAccess");
    }
}
void merge_VkPhysicalDeviceImageRobustnessFeatures(VkPhysicalDeviceImageRobustnessFeatures & current, VkPhysicalDeviceImageRobustnessFeatures const& merge_in) {
    current.robustImageAccess = current.robustImageAccess || merge_in.robustImageAccess;
}
void compare_VkPhysicalDeviceSubgroupSizeControlFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceSubgroupSizeControlFeatures const& supported, VkPhysicalDeviceSubgroupSizeControlFeatures const& requested) {
    if (requested.subgroupSizeControl && !supported.subgroupSizeControl) {
        error_list.push_back("VkPhysicalDeviceSubgroupSizeControlFeatures::subgroupSizeControl");
    }
    if (requested.computeFullSubgroups && !supported.computeFullSubgroups) {
        error_list.push_back("VkPhysicalDeviceSubgroupSizeControlFeatures::computeFullSubgroups");
    }
}
void merge_VkPhysicalDeviceSubgroupSizeControlFeatures(VkPhysicalDeviceSubgroupSizeControlFeatures & current, VkPhysicalDeviceSubgroupSizeControlFeatures const& merge_in) {
    current.subgroupSizeControl = current.subgroupSizeControl || merge_in.subgroupSizeControl;
    current.computeFullSubgroups = current.computeFullSubgroups || merge_in.computeFullSubgroups;
}
void compare_VkPhysicalDeviceInlineUniformBlockFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceInlineUniformBlockFeatures const& supported, VkPhysicalDeviceInlineUniformBlockFeatures const& requested) {
    if (requested.inlineUniformBlock && !supported.inlineUniformBlock) {
        error_list.push_back("VkPhysicalDeviceInlineUniformBlockFeatures::inlineUniformBlock");
    }
    if (requested.descriptorBindingInlineUniformBlockUpdateAfterBind && !supported.descriptorBindingInlineUniformBlockUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceInlineUniformBlockFeatures::descriptorBindingInlineUniformBlockUpdateAfterBind");
    }
}
void merge_VkPhysicalDeviceInlineUniformBlockFeatures(VkPhysicalDeviceInlineUniformBlockFeatures & current, VkPhysicalDeviceInlineUniformBlockFeatures const& merge_in) {
    current.inlineUniformBlock = current.inlineUniformBlock || merge_in.inlineUniformBlock;
    current.descriptorBindingInlineUniformBlockUpdateAfterBind = current.descriptorBindingInlineUniformBlockUpdateAfterBind || merge_in.descriptorBindingInlineUniformBlockUpdateAfterBind;
}
void compare_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceTextureCompressionASTCHDRFeatures const& supported, VkPhysicalDeviceTextureCompressionASTCHDRFeatures const& requested) {
    if (requested.textureCompressionASTC_HDR && !supported.textureCompressionASTC_HDR) {
        error_list.push_back("VkPhysicalDeviceTextureCompressionASTCHDRFeatures::textureCompressionASTC_HDR");
    }
}
void merge_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(VkPhysicalDeviceTextureCompressionASTCHDRFeatures & current, VkPhysicalDeviceTextureCompressionASTCHDRFeatures const& merge_in) {
    current.textureCompressionASTC_HDR = current.textureCompressionASTC_HDR || merge_in.textureCompressionASTC_HDR;
}
void compare_VkPhysicalDeviceDynamicRenderingFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceDynamicRenderingFeatures const& supported, VkPhysicalDeviceDynamicRenderingFeatures const& requested) {
    if (requested.dynamicRendering && !supported.dynamicRendering) {
        error_list.push_back("VkPhysicalDeviceDynamicRenderingFeatures::dynamicRendering");
    }
}
void merge_VkPhysicalDeviceDynamicRenderingFeatures(VkPhysicalDeviceDynamicRenderingFeatures & current, VkPhysicalDeviceDynamicRenderingFeatures const& merge_in) {
    current.dynamicRendering = current.dynamicRendering || merge_in.dynamicRendering;
}
void compare_VkPhysicalDeviceShaderIntegerDotProductFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderIntegerDotProductFeatures const& supported, VkPhysicalDeviceShaderIntegerDotProductFeatures const& requested) {
    if (requested.shaderIntegerDotProduct && !supported.shaderIntegerDotProduct) {
        error_list.push_back("VkPhysicalDeviceShaderIntegerDotProductFeatures::shaderIntegerDotProduct");
    }
}
void merge_VkPhysicalDeviceShaderIntegerDotProductFeatures(VkPhysicalDeviceShaderIntegerDotProductFeatures & current, VkPhysicalDeviceShaderIntegerDotProductFeatures const& merge_in) {
    current.shaderIntegerDotProduct = current.shaderIntegerDotProduct || merge_in.shaderIntegerDotProduct;
}
void compare_VkPhysicalDeviceMaintenance4Features(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance4Features const& supported, VkPhysicalDeviceMaintenance4Features const& requested) {
    if (requested.maintenance4 && !supported.maintenance4) {
        error_list.push_back("VkPhysicalDeviceMaintenance4Features::maintenance4");
    }
}
void merge_VkPhysicalDeviceMaintenance4Features(VkPhysicalDeviceMaintenance4Features & current, VkPhysicalDeviceMaintenance4Features const& merge_in) {
    current.maintenance4 = current.maintenance4 || merge_in.maintenance4;
}
void compare_VkPhysicalDeviceVulkan14Features(std::vector<std::string> & error_list, VkPhysicalDeviceVulkan14Features const& supported, VkPhysicalDeviceVulkan14Features const& requested) {
    if (requested.globalPriorityQuery && !supported.globalPriorityQuery) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::globalPriorityQuery");
    }
    if (requested.shaderSubgroupRotate && !supported.shaderSubgroupRotate) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::shaderSubgroupRotate");
    }
    if (requested.shaderSubgroupRotateClustered && !supported.shaderSubgroupRotateClustered) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::shaderSubgroupRotateClustered");
    }
    if (requested.shaderFloatControls2 && !supported.shaderFloatControls2) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::shaderFloatControls2");
    }
    if (requested.shaderExpectAssume && !supported.shaderExpectAssume) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::shaderExpectAssume");
    }
    if (requested.rectangularLines && !supported.rectangularLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::rectangularLines");
    }
    if (requested.bresenhamLines && !supported.bresenhamLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::bresenhamLines");
    }
    if (requested.smoothLines && !supported.smoothLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::smoothLines");
    }
    if (requested.stippledRectangularLines && !supported.stippledRectangularLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::stippledRectangularLines");
    }
    if (requested.stippledBresenhamLines && !supported.stippledBresenhamLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::stippledBresenhamLines");
    }
    if (requested.stippledSmoothLines && !supported.stippledSmoothLines) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::stippledSmoothLines");
    }
    if (requested.vertexAttributeInstanceRateDivisor && !supported.vertexAttributeInstanceRateDivisor) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::vertexAttributeInstanceRateDivisor");
    }
    if (requested.vertexAttributeInstanceRateZeroDivisor && !supported.vertexAttributeInstanceRateZeroDivisor) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::vertexAttributeInstanceRateZeroDivisor");
    }
    if (requested.indexTypeUint8 && !supported.indexTypeUint8) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::indexTypeUint8");
    }
    if (requested.dynamicRenderingLocalRead && !supported.dynamicRenderingLocalRead) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::dynamicRenderingLocalRead");
    }
    if (requested.maintenance5 && !supported.maintenance5) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::maintenance5");
    }
    if (requested.maintenance6 && !supported.maintenance6) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::maintenance6");
    }
    if (requested.pipelineProtectedAccess && !supported.pipelineProtectedAccess) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::pipelineProtectedAccess");
    }
    if (requested.pipelineRobustness && !supported.pipelineRobustness) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::pipelineRobustness");
    }
    if (requested.hostImageCopy && !supported.hostImageCopy) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::hostImageCopy");
    }
    if (requested.pushDescriptor && !supported.pushDescriptor) {
        error_list.push_back("VkPhysicalDeviceVulkan14Features::pushDescriptor");
    }
}
void merge_VkPhysicalDeviceVulkan14Features(VkPhysicalDeviceVulkan14Features & current, VkPhysicalDeviceVulkan14Features const& merge_in) {
    current.globalPriorityQuery = current.globalPriorityQuery || merge_in.globalPriorityQuery;
    current.shaderSubgroupRotate = current.shaderSubgroupRotate || merge_in.shaderSubgroupRotate;
    current.shaderSubgroupRotateClustered = current.shaderSubgroupRotateClustered || merge_in.shaderSubgroupRotateClustered;
    current.shaderFloatControls2 = current.shaderFloatControls2 || merge_in.shaderFloatControls2;
    current.shaderExpectAssume = current.shaderExpectAssume || merge_in.shaderExpectAssume;
    current.rectangularLines = current.rectangularLines || merge_in.rectangularLines;
    current.bresenhamLines = current.bresenhamLines || merge_in.bresenhamLines;
    current.smoothLines = current.smoothLines || merge_in.smoothLines;
    current.stippledRectangularLines = current.stippledRectangularLines || merge_in.stippledRectangularLines;
    current.stippledBresenhamLines = current.stippledBresenhamLines || merge_in.stippledBresenhamLines;
    current.stippledSmoothLines = current.stippledSmoothLines || merge_in.stippledSmoothLines;
    current.vertexAttributeInstanceRateDivisor = current.vertexAttributeInstanceRateDivisor || merge_in.vertexAttributeInstanceRateDivisor;
    current.vertexAttributeInstanceRateZeroDivisor = current.vertexAttributeInstanceRateZeroDivisor || merge_in.vertexAttributeInstanceRateZeroDivisor;
    current.indexTypeUint8 = current.indexTypeUint8 || merge_in.indexTypeUint8;
    current.dynamicRenderingLocalRead = current.dynamicRenderingLocalRead || merge_in.dynamicRenderingLocalRead;
    current.maintenance5 = current.maintenance5 || merge_in.maintenance5;
    current.maintenance6 = current.maintenance6 || merge_in.maintenance6;
    current.pipelineProtectedAccess = current.pipelineProtectedAccess || merge_in.pipelineProtectedAccess;
    current.pipelineRobustness = current.pipelineRobustness || merge_in.pipelineRobustness;
    current.hostImageCopy = current.hostImageCopy || merge_in.hostImageCopy;
    current.pushDescriptor = current.pushDescriptor || merge_in.pushDescriptor;
}
void compare_VkPhysicalDeviceGlobalPriorityQueryFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceGlobalPriorityQueryFeatures const& supported, VkPhysicalDeviceGlobalPriorityQueryFeatures const& requested) {
    if (requested.globalPriorityQuery && !supported.globalPriorityQuery) {
        error_list.push_back("VkPhysicalDeviceGlobalPriorityQueryFeatures::globalPriorityQuery");
    }
}
void merge_VkPhysicalDeviceGlobalPriorityQueryFeatures(VkPhysicalDeviceGlobalPriorityQueryFeatures & current, VkPhysicalDeviceGlobalPriorityQueryFeatures const& merge_in) {
    current.globalPriorityQuery = current.globalPriorityQuery || merge_in.globalPriorityQuery;
}
void compare_VkPhysicalDeviceShaderSubgroupRotateFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderSubgroupRotateFeatures const& supported, VkPhysicalDeviceShaderSubgroupRotateFeatures const& requested) {
    if (requested.shaderSubgroupRotate && !supported.shaderSubgroupRotate) {
        error_list.push_back("VkPhysicalDeviceShaderSubgroupRotateFeatures::shaderSubgroupRotate");
    }
    if (requested.shaderSubgroupRotateClustered && !supported.shaderSubgroupRotateClustered) {
        error_list.push_back("VkPhysicalDeviceShaderSubgroupRotateFeatures::shaderSubgroupRotateClustered");
    }
}
void merge_VkPhysicalDeviceShaderSubgroupRotateFeatures(VkPhysicalDeviceShaderSubgroupRotateFeatures & current, VkPhysicalDeviceShaderSubgroupRotateFeatures const& merge_in) {
    current.shaderSubgroupRotate = current.shaderSubgroupRotate || merge_in.shaderSubgroupRotate;
    current.shaderSubgroupRotateClustered = current.shaderSubgroupRotateClustered || merge_in.shaderSubgroupRotateClustered;
}
void compare_VkPhysicalDeviceShaderFloatControls2Features(std::vector<std::string> & error_list, VkPhysicalDeviceShaderFloatControls2Features const& supported, VkPhysicalDeviceShaderFloatControls2Features const& requested) {
    if (requested.shaderFloatControls2 && !supported.shaderFloatControls2) {
        error_list.push_back("VkPhysicalDeviceShaderFloatControls2Features::shaderFloatControls2");
    }
}
void merge_VkPhysicalDeviceShaderFloatControls2Features(VkPhysicalDeviceShaderFloatControls2Features & current, VkPhysicalDeviceShaderFloatControls2Features const& merge_in) {
    current.shaderFloatControls2 = current.shaderFloatControls2 || merge_in.shaderFloatControls2;
}
void compare_VkPhysicalDeviceShaderExpectAssumeFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceShaderExpectAssumeFeatures const& supported, VkPhysicalDeviceShaderExpectAssumeFeatures const& requested) {
    if (requested.shaderExpectAssume && !supported.shaderExpectAssume) {
        error_list.push_back("VkPhysicalDeviceShaderExpectAssumeFeatures::shaderExpectAssume");
    }
}
void merge_VkPhysicalDeviceShaderExpectAssumeFeatures(VkPhysicalDeviceShaderExpectAssumeFeatures & current, VkPhysicalDeviceShaderExpectAssumeFeatures const& merge_in) {
    current.shaderExpectAssume = current.shaderExpectAssume || merge_in.shaderExpectAssume;
}
void compare_VkPhysicalDeviceLineRasterizationFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceLineRasterizationFeatures const& supported, VkPhysicalDeviceLineRasterizationFeatures const& requested) {
    if (requested.rectangularLines && !supported.rectangularLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::rectangularLines");
    }
    if (requested.bresenhamLines && !supported.bresenhamLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::bresenhamLines");
    }
    if (requested.smoothLines && !supported.smoothLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::smoothLines");
    }
    if (requested.stippledRectangularLines && !supported.stippledRectangularLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::stippledRectangularLines");
    }
    if (requested.stippledBresenhamLines && !supported.stippledBresenhamLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::stippledBresenhamLines");
    }
    if (requested.stippledSmoothLines && !supported.stippledSmoothLines) {
        error_list.push_back("VkPhysicalDeviceLineRasterizationFeatures::stippledSmoothLines");
    }
}
void merge_VkPhysicalDeviceLineRasterizationFeatures(VkPhysicalDeviceLineRasterizationFeatures & current, VkPhysicalDeviceLineRasterizationFeatures const& merge_in) {
    current.rectangularLines = current.rectangularLines || merge_in.rectangularLines;
    current.bresenhamLines = current.bresenhamLines || merge_in.bresenhamLines;
    current.smoothLines = current.smoothLines || merge_in.smoothLines;
    current.stippledRectangularLines = current.stippledRectangularLines || merge_in.stippledRectangularLines;
    current.stippledBresenhamLines = current.stippledBresenhamLines || merge_in.stippledBresenhamLines;
    current.stippledSmoothLines = current.stippledSmoothLines || merge_in.stippledSmoothLines;
}
void compare_VkPhysicalDeviceVertexAttributeDivisorFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceVertexAttributeDivisorFeatures const& supported, VkPhysicalDeviceVertexAttributeDivisorFeatures const& requested) {
    if (requested.vertexAttributeInstanceRateDivisor && !supported.vertexAttributeInstanceRateDivisor) {
        error_list.push_back("VkPhysicalDeviceVertexAttributeDivisorFeatures::vertexAttributeInstanceRateDivisor");
    }
    if (requested.vertexAttributeInstanceRateZeroDivisor && !supported.vertexAttributeInstanceRateZeroDivisor) {
        error_list.push_back("VkPhysicalDeviceVertexAttributeDivisorFeatures::vertexAttributeInstanceRateZeroDivisor");
    }
}
void merge_VkPhysicalDeviceVertexAttributeDivisorFeatures(VkPhysicalDeviceVertexAttributeDivisorFeatures & current, VkPhysicalDeviceVertexAttributeDivisorFeatures const& merge_in) {
    current.vertexAttributeInstanceRateDivisor = current.vertexAttributeInstanceRateDivisor || merge_in.vertexAttributeInstanceRateDivisor;
    current.vertexAttributeInstanceRateZeroDivisor = current.vertexAttributeInstanceRateZeroDivisor || merge_in.vertexAttributeInstanceRateZeroDivisor;
}
void compare_VkPhysicalDeviceIndexTypeUint8Features(std::vector<std::string> & error_list, VkPhysicalDeviceIndexTypeUint8Features const& supported, VkPhysicalDeviceIndexTypeUint8Features const& requested) {
    if (requested.indexTypeUint8 && !supported.indexTypeUint8) {
        error_list.push_back("VkPhysicalDeviceIndexTypeUint8Features::indexTypeUint8");
    }
}
void merge_VkPhysicalDeviceIndexTypeUint8Features(VkPhysicalDeviceIndexTypeUint8Features & current, VkPhysicalDeviceIndexTypeUint8Features const& merge_in) {
    current.indexTypeUint8 = current.indexTypeUint8 || merge_in.indexTypeUint8;
}
void compare_VkPhysicalDeviceMaintenance5Features(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance5Features const& supported, VkPhysicalDeviceMaintenance5Features const& requested) {
    if (requested.maintenance5 && !supported.maintenance5) {
        error_list.push_back("VkPhysicalDeviceMaintenance5Features::maintenance5");
    }
}
void merge_VkPhysicalDeviceMaintenance5Features(VkPhysicalDeviceMaintenance5Features & current, VkPhysicalDeviceMaintenance5Features const& merge_in) {
    current.maintenance5 = current.maintenance5 || merge_in.maintenance5;
}
void compare_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceDynamicRenderingLocalReadFeatures const& supported, VkPhysicalDeviceDynamicRenderingLocalReadFeatures const& requested) {
    if (requested.dynamicRenderingLocalRead && !supported.dynamicRenderingLocalRead) {
        error_list.push_back("VkPhysicalDeviceDynamicRenderingLocalReadFeatures::dynamicRenderingLocalRead");
    }
}
void merge_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(VkPhysicalDeviceDynamicRenderingLocalReadFeatures & current, VkPhysicalDeviceDynamicRenderingLocalReadFeatures const& merge_in) {
    current.dynamicRenderingLocalRead = current.dynamicRenderingLocalRead || merge_in.dynamicRenderingLocalRead;
}
void compare_VkPhysicalDeviceMaintenance6Features(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance6Features const& supported, VkPhysicalDeviceMaintenance6Features const& requested) {
    if (requested.maintenance6 && !supported.maintenance6) {
        error_list.push_back("VkPhysicalDeviceMaintenance6Features::maintenance6");
    }
}
void merge_VkPhysicalDeviceMaintenance6Features(VkPhysicalDeviceMaintenance6Features & current, VkPhysicalDeviceMaintenance6Features const& merge_in) {
    current.maintenance6 = current.maintenance6 || merge_in.maintenance6;
}
void compare_VkPhysicalDevicePipelineProtectedAccessFeatures(std::vector<std::string> & error_list, VkPhysicalDevicePipelineProtectedAccessFeatures const& supported, VkPhysicalDevicePipelineProtectedAccessFeatures const& requested) {
    if (requested.pipelineProtectedAccess && !supported.pipelineProtectedAccess) {
        error_list.push_back("VkPhysicalDevicePipelineProtectedAccessFeatures::pipelineProtectedAccess");
    }
}
void merge_VkPhysicalDevicePipelineProtectedAccessFeatures(VkPhysicalDevicePipelineProtectedAccessFeatures & current, VkPhysicalDevicePipelineProtectedAccessFeatures const& merge_in) {
    current.pipelineProtectedAccess = current.pipelineProtectedAccess || merge_in.pipelineProtectedAccess;
}
void compare_VkPhysicalDevicePipelineRobustnessFeatures(std::vector<std::string> & error_list, VkPhysicalDevicePipelineRobustnessFeatures const& supported, VkPhysicalDevicePipelineRobustnessFeatures const& requested) {
    if (requested.pipelineRobustness && !supported.pipelineRobustness) {
        error_list.push_back("VkPhysicalDevicePipelineRobustnessFeatures::pipelineRobustness");
    }
}
void merge_VkPhysicalDevicePipelineRobustnessFeatures(VkPhysicalDevicePipelineRobustnessFeatures & current, VkPhysicalDevicePipelineRobustnessFeatures const& merge_in) {
    current.pipelineRobustness = current.pipelineRobustness || merge_in.pipelineRobustness;
}
void compare_VkPhysicalDeviceHostImageCopyFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceHostImageCopyFeatures const& supported, VkPhysicalDeviceHostImageCopyFeatures const& requested) {
    if (requested.hostImageCopy && !supported.hostImageCopy) {
        error_list.push_back("VkPhysicalDeviceHostImageCopyFeatures::hostImageCopy");
    }
}
void merge_VkPhysicalDeviceHostImageCopyFeatures(VkPhysicalDeviceHostImageCopyFeatures & current, VkPhysicalDeviceHostImageCopyFeatures const& merge_in) {
    current.hostImageCopy = current.hostImageCopy || merge_in.hostImageCopy;
}
void compare_VkPhysicalDevicePerformanceQueryFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePerformanceQueryFeaturesKHR const& supported, VkPhysicalDevicePerformanceQueryFeaturesKHR const& requested) {
    if (requested.performanceCounterQueryPools && !supported.performanceCounterQueryPools) {
        error_list.push_back("VkPhysicalDevicePerformanceQueryFeaturesKHR::performanceCounterQueryPools");
    }
    if (requested.performanceCounterMultipleQueryPools && !supported.performanceCounterMultipleQueryPools) {
        error_list.push_back("VkPhysicalDevicePerformanceQueryFeaturesKHR::performanceCounterMultipleQueryPools");
    }
}
void merge_VkPhysicalDevicePerformanceQueryFeaturesKHR(VkPhysicalDevicePerformanceQueryFeaturesKHR & current, VkPhysicalDevicePerformanceQueryFeaturesKHR const& merge_in) {
    current.performanceCounterQueryPools = current.performanceCounterQueryPools || merge_in.performanceCounterQueryPools;
    current.performanceCounterMultipleQueryPools = current.performanceCounterMultipleQueryPools || merge_in.performanceCounterMultipleQueryPools;
}
void compare_VkPhysicalDeviceShaderBfloat16FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderBfloat16FeaturesKHR const& supported, VkPhysicalDeviceShaderBfloat16FeaturesKHR const& requested) {
    if (requested.shaderBFloat16Type && !supported.shaderBFloat16Type) {
        error_list.push_back("VkPhysicalDeviceShaderBfloat16FeaturesKHR::shaderBFloat16Type");
    }
    if (requested.shaderBFloat16DotProduct && !supported.shaderBFloat16DotProduct) {
        error_list.push_back("VkPhysicalDeviceShaderBfloat16FeaturesKHR::shaderBFloat16DotProduct");
    }
    if (requested.shaderBFloat16CooperativeMatrix && !supported.shaderBFloat16CooperativeMatrix) {
        error_list.push_back("VkPhysicalDeviceShaderBfloat16FeaturesKHR::shaderBFloat16CooperativeMatrix");
    }
}
void merge_VkPhysicalDeviceShaderBfloat16FeaturesKHR(VkPhysicalDeviceShaderBfloat16FeaturesKHR & current, VkPhysicalDeviceShaderBfloat16FeaturesKHR const& merge_in) {
    current.shaderBFloat16Type = current.shaderBFloat16Type || merge_in.shaderBFloat16Type;
    current.shaderBFloat16DotProduct = current.shaderBFloat16DotProduct || merge_in.shaderBFloat16DotProduct;
    current.shaderBFloat16CooperativeMatrix = current.shaderBFloat16CooperativeMatrix || merge_in.shaderBFloat16CooperativeMatrix;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDevicePortabilitySubsetFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePortabilitySubsetFeaturesKHR const& supported, VkPhysicalDevicePortabilitySubsetFeaturesKHR const& requested) {
    if (requested.constantAlphaColorBlendFactors && !supported.constantAlphaColorBlendFactors) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::constantAlphaColorBlendFactors");
    }
    if (requested.events && !supported.events) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::events");
    }
    if (requested.imageViewFormatReinterpretation && !supported.imageViewFormatReinterpretation) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::imageViewFormatReinterpretation");
    }
    if (requested.imageViewFormatSwizzle && !supported.imageViewFormatSwizzle) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::imageViewFormatSwizzle");
    }
    if (requested.imageView2DOn3DImage && !supported.imageView2DOn3DImage) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::imageView2DOn3DImage");
    }
    if (requested.multisampleArrayImage && !supported.multisampleArrayImage) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::multisampleArrayImage");
    }
    if (requested.mutableComparisonSamplers && !supported.mutableComparisonSamplers) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::mutableComparisonSamplers");
    }
    if (requested.pointPolygons && !supported.pointPolygons) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::pointPolygons");
    }
    if (requested.samplerMipLodBias && !supported.samplerMipLodBias) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::samplerMipLodBias");
    }
    if (requested.separateStencilMaskRef && !supported.separateStencilMaskRef) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::separateStencilMaskRef");
    }
    if (requested.shaderSampleRateInterpolationFunctions && !supported.shaderSampleRateInterpolationFunctions) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::shaderSampleRateInterpolationFunctions");
    }
    if (requested.tessellationIsolines && !supported.tessellationIsolines) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::tessellationIsolines");
    }
    if (requested.tessellationPointMode && !supported.tessellationPointMode) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::tessellationPointMode");
    }
    if (requested.triangleFans && !supported.triangleFans) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::triangleFans");
    }
    if (requested.vertexAttributeAccessBeyondStride && !supported.vertexAttributeAccessBeyondStride) {
        error_list.push_back("VkPhysicalDevicePortabilitySubsetFeaturesKHR::vertexAttributeAccessBeyondStride");
    }
}
void merge_VkPhysicalDevicePortabilitySubsetFeaturesKHR(VkPhysicalDevicePortabilitySubsetFeaturesKHR & current, VkPhysicalDevicePortabilitySubsetFeaturesKHR const& merge_in) {
    current.constantAlphaColorBlendFactors = current.constantAlphaColorBlendFactors || merge_in.constantAlphaColorBlendFactors;
    current.events = current.events || merge_in.events;
    current.imageViewFormatReinterpretation = current.imageViewFormatReinterpretation || merge_in.imageViewFormatReinterpretation;
    current.imageViewFormatSwizzle = current.imageViewFormatSwizzle || merge_in.imageViewFormatSwizzle;
    current.imageView2DOn3DImage = current.imageView2DOn3DImage || merge_in.imageView2DOn3DImage;
    current.multisampleArrayImage = current.multisampleArrayImage || merge_in.multisampleArrayImage;
    current.mutableComparisonSamplers = current.mutableComparisonSamplers || merge_in.mutableComparisonSamplers;
    current.pointPolygons = current.pointPolygons || merge_in.pointPolygons;
    current.samplerMipLodBias = current.samplerMipLodBias || merge_in.samplerMipLodBias;
    current.separateStencilMaskRef = current.separateStencilMaskRef || merge_in.separateStencilMaskRef;
    current.shaderSampleRateInterpolationFunctions = current.shaderSampleRateInterpolationFunctions || merge_in.shaderSampleRateInterpolationFunctions;
    current.tessellationIsolines = current.tessellationIsolines || merge_in.tessellationIsolines;
    current.tessellationPointMode = current.tessellationPointMode || merge_in.tessellationPointMode;
    current.triangleFans = current.triangleFans || merge_in.triangleFans;
    current.vertexAttributeAccessBeyondStride = current.vertexAttributeAccessBeyondStride || merge_in.vertexAttributeAccessBeyondStride;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceShaderClockFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderClockFeaturesKHR const& supported, VkPhysicalDeviceShaderClockFeaturesKHR const& requested) {
    if (requested.shaderSubgroupClock && !supported.shaderSubgroupClock) {
        error_list.push_back("VkPhysicalDeviceShaderClockFeaturesKHR::shaderSubgroupClock");
    }
    if (requested.shaderDeviceClock && !supported.shaderDeviceClock) {
        error_list.push_back("VkPhysicalDeviceShaderClockFeaturesKHR::shaderDeviceClock");
    }
}
void merge_VkPhysicalDeviceShaderClockFeaturesKHR(VkPhysicalDeviceShaderClockFeaturesKHR & current, VkPhysicalDeviceShaderClockFeaturesKHR const& merge_in) {
    current.shaderSubgroupClock = current.shaderSubgroupClock || merge_in.shaderSubgroupClock;
    current.shaderDeviceClock = current.shaderDeviceClock || merge_in.shaderDeviceClock;
}
void compare_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentShadingRateFeaturesKHR const& supported, VkPhysicalDeviceFragmentShadingRateFeaturesKHR const& requested) {
    if (requested.pipelineFragmentShadingRate && !supported.pipelineFragmentShadingRate) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateFeaturesKHR::pipelineFragmentShadingRate");
    }
    if (requested.primitiveFragmentShadingRate && !supported.primitiveFragmentShadingRate) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateFeaturesKHR::primitiveFragmentShadingRate");
    }
    if (requested.attachmentFragmentShadingRate && !supported.attachmentFragmentShadingRate) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateFeaturesKHR::attachmentFragmentShadingRate");
    }
}
void merge_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(VkPhysicalDeviceFragmentShadingRateFeaturesKHR & current, VkPhysicalDeviceFragmentShadingRateFeaturesKHR const& merge_in) {
    current.pipelineFragmentShadingRate = current.pipelineFragmentShadingRate || merge_in.pipelineFragmentShadingRate;
    current.primitiveFragmentShadingRate = current.primitiveFragmentShadingRate || merge_in.primitiveFragmentShadingRate;
    current.attachmentFragmentShadingRate = current.attachmentFragmentShadingRate || merge_in.attachmentFragmentShadingRate;
}
void compare_VkPhysicalDeviceShaderQuadControlFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderQuadControlFeaturesKHR const& supported, VkPhysicalDeviceShaderQuadControlFeaturesKHR const& requested) {
    if (requested.shaderQuadControl && !supported.shaderQuadControl) {
        error_list.push_back("VkPhysicalDeviceShaderQuadControlFeaturesKHR::shaderQuadControl");
    }
}
void merge_VkPhysicalDeviceShaderQuadControlFeaturesKHR(VkPhysicalDeviceShaderQuadControlFeaturesKHR & current, VkPhysicalDeviceShaderQuadControlFeaturesKHR const& merge_in) {
    current.shaderQuadControl = current.shaderQuadControl || merge_in.shaderQuadControl;
}
void compare_VkPhysicalDevicePresentWaitFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePresentWaitFeaturesKHR const& supported, VkPhysicalDevicePresentWaitFeaturesKHR const& requested) {
    if (requested.presentWait && !supported.presentWait) {
        error_list.push_back("VkPhysicalDevicePresentWaitFeaturesKHR::presentWait");
    }
}
void merge_VkPhysicalDevicePresentWaitFeaturesKHR(VkPhysicalDevicePresentWaitFeaturesKHR & current, VkPhysicalDevicePresentWaitFeaturesKHR const& merge_in) {
    current.presentWait = current.presentWait || merge_in.presentWait;
}
void compare_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const& supported, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const& requested) {
    if (requested.pipelineExecutableInfo && !supported.pipelineExecutableInfo) {
        error_list.push_back("VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR::pipelineExecutableInfo");
    }
}
void merge_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR & current, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const& merge_in) {
    current.pipelineExecutableInfo = current.pipelineExecutableInfo || merge_in.pipelineExecutableInfo;
}
void compare_VkPhysicalDevicePresentIdFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePresentIdFeaturesKHR const& supported, VkPhysicalDevicePresentIdFeaturesKHR const& requested) {
    if (requested.presentId && !supported.presentId) {
        error_list.push_back("VkPhysicalDevicePresentIdFeaturesKHR::presentId");
    }
}
void merge_VkPhysicalDevicePresentIdFeaturesKHR(VkPhysicalDevicePresentIdFeaturesKHR & current, VkPhysicalDevicePresentIdFeaturesKHR const& merge_in) {
    current.presentId = current.presentId || merge_in.presentId;
}
void compare_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR const& supported, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR const& requested) {
    if (requested.fragmentShaderBarycentric && !supported.fragmentShaderBarycentric) {
        error_list.push_back("VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR::fragmentShaderBarycentric");
    }
}
void merge_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR & current, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR const& merge_in) {
    current.fragmentShaderBarycentric = current.fragmentShaderBarycentric || merge_in.fragmentShaderBarycentric;
}
void compare_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR const& supported, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR const& requested) {
    if (requested.shaderSubgroupUniformControlFlow && !supported.shaderSubgroupUniformControlFlow) {
        error_list.push_back("VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR::shaderSubgroupUniformControlFlow");
    }
}
void merge_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR & current, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR const& merge_in) {
    current.shaderSubgroupUniformControlFlow = current.shaderSubgroupUniformControlFlow || merge_in.shaderSubgroupUniformControlFlow;
}
void compare_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR const& supported, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR const& requested) {
    if (requested.workgroupMemoryExplicitLayout && !supported.workgroupMemoryExplicitLayout) {
        error_list.push_back("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout");
    }
    if (requested.workgroupMemoryExplicitLayoutScalarBlockLayout && !supported.workgroupMemoryExplicitLayoutScalarBlockLayout) {
        error_list.push_back("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayoutScalarBlockLayout");
    }
    if (requested.workgroupMemoryExplicitLayout8BitAccess && !supported.workgroupMemoryExplicitLayout8BitAccess) {
        error_list.push_back("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout8BitAccess");
    }
    if (requested.workgroupMemoryExplicitLayout16BitAccess && !supported.workgroupMemoryExplicitLayout16BitAccess) {
        error_list.push_back("VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR::workgroupMemoryExplicitLayout16BitAccess");
    }
}
void merge_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR & current, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR const& merge_in) {
    current.workgroupMemoryExplicitLayout = current.workgroupMemoryExplicitLayout || merge_in.workgroupMemoryExplicitLayout;
    current.workgroupMemoryExplicitLayoutScalarBlockLayout = current.workgroupMemoryExplicitLayoutScalarBlockLayout || merge_in.workgroupMemoryExplicitLayoutScalarBlockLayout;
    current.workgroupMemoryExplicitLayout8BitAccess = current.workgroupMemoryExplicitLayout8BitAccess || merge_in.workgroupMemoryExplicitLayout8BitAccess;
    current.workgroupMemoryExplicitLayout16BitAccess = current.workgroupMemoryExplicitLayout16BitAccess || merge_in.workgroupMemoryExplicitLayout16BitAccess;
}
void compare_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR const& supported, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR const& requested) {
    if (requested.rayTracingMaintenance1 && !supported.rayTracingMaintenance1) {
        error_list.push_back("VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR::rayTracingMaintenance1");
    }
    if (requested.rayTracingPipelineTraceRaysIndirect2 && !supported.rayTracingPipelineTraceRaysIndirect2) {
        error_list.push_back("VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR::rayTracingPipelineTraceRaysIndirect2");
    }
}
void merge_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR & current, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR const& merge_in) {
    current.rayTracingMaintenance1 = current.rayTracingMaintenance1 || merge_in.rayTracingMaintenance1;
    current.rayTracingPipelineTraceRaysIndirect2 = current.rayTracingPipelineTraceRaysIndirect2 || merge_in.rayTracingPipelineTraceRaysIndirect2;
}
void compare_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderUntypedPointersFeaturesKHR const& supported, VkPhysicalDeviceShaderUntypedPointersFeaturesKHR const& requested) {
    if (requested.shaderUntypedPointers && !supported.shaderUntypedPointers) {
        error_list.push_back("VkPhysicalDeviceShaderUntypedPointersFeaturesKHR::shaderUntypedPointers");
    }
}
void merge_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR & current, VkPhysicalDeviceShaderUntypedPointersFeaturesKHR const& merge_in) {
    current.shaderUntypedPointers = current.shaderUntypedPointers || merge_in.shaderUntypedPointers;
}
void compare_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR const& supported, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR const& requested) {
    if (requested.shaderMaximalReconvergence && !supported.shaderMaximalReconvergence) {
        error_list.push_back("VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR::shaderMaximalReconvergence");
    }
}
void merge_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR & current, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR const& merge_in) {
    current.shaderMaximalReconvergence = current.shaderMaximalReconvergence || merge_in.shaderMaximalReconvergence;
}
void compare_VkPhysicalDevicePresentId2FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePresentId2FeaturesKHR const& supported, VkPhysicalDevicePresentId2FeaturesKHR const& requested) {
    if (requested.presentId2 && !supported.presentId2) {
        error_list.push_back("VkPhysicalDevicePresentId2FeaturesKHR::presentId2");
    }
}
void merge_VkPhysicalDevicePresentId2FeaturesKHR(VkPhysicalDevicePresentId2FeaturesKHR & current, VkPhysicalDevicePresentId2FeaturesKHR const& merge_in) {
    current.presentId2 = current.presentId2 || merge_in.presentId2;
}
void compare_VkPhysicalDevicePresentWait2FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePresentWait2FeaturesKHR const& supported, VkPhysicalDevicePresentWait2FeaturesKHR const& requested) {
    if (requested.presentWait2 && !supported.presentWait2) {
        error_list.push_back("VkPhysicalDevicePresentWait2FeaturesKHR::presentWait2");
    }
}
void merge_VkPhysicalDevicePresentWait2FeaturesKHR(VkPhysicalDevicePresentWait2FeaturesKHR & current, VkPhysicalDevicePresentWait2FeaturesKHR const& merge_in) {
    current.presentWait2 = current.presentWait2 || merge_in.presentWait2;
}
void compare_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR const& supported, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR const& requested) {
    if (requested.rayTracingPositionFetch && !supported.rayTracingPositionFetch) {
        error_list.push_back("VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR::rayTracingPositionFetch");
    }
}
void merge_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR & current, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR const& merge_in) {
    current.rayTracingPositionFetch = current.rayTracingPositionFetch || merge_in.rayTracingPositionFetch;
}
void compare_VkPhysicalDevicePipelineBinaryFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePipelineBinaryFeaturesKHR const& supported, VkPhysicalDevicePipelineBinaryFeaturesKHR const& requested) {
    if (requested.pipelineBinaries && !supported.pipelineBinaries) {
        error_list.push_back("VkPhysicalDevicePipelineBinaryFeaturesKHR::pipelineBinaries");
    }
}
void merge_VkPhysicalDevicePipelineBinaryFeaturesKHR(VkPhysicalDevicePipelineBinaryFeaturesKHR & current, VkPhysicalDevicePipelineBinaryFeaturesKHR const& merge_in) {
    current.pipelineBinaries = current.pipelineBinaries || merge_in.pipelineBinaries;
}
void compare_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR const& supported, VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR const& requested) {
    if (requested.swapchainMaintenance1 && !supported.swapchainMaintenance1) {
        error_list.push_back("VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR::swapchainMaintenance1");
    }
}
void merge_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR & current, VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR const& merge_in) {
    current.swapchainMaintenance1 = current.swapchainMaintenance1 || merge_in.swapchainMaintenance1;
}
void compare_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceCooperativeMatrixFeaturesKHR const& supported, VkPhysicalDeviceCooperativeMatrixFeaturesKHR const& requested) {
    if (requested.cooperativeMatrix && !supported.cooperativeMatrix) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrixFeaturesKHR::cooperativeMatrix");
    }
    if (requested.cooperativeMatrixRobustBufferAccess && !supported.cooperativeMatrixRobustBufferAccess) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrixFeaturesKHR::cooperativeMatrixRobustBufferAccess");
    }
}
void merge_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(VkPhysicalDeviceCooperativeMatrixFeaturesKHR & current, VkPhysicalDeviceCooperativeMatrixFeaturesKHR const& merge_in) {
    current.cooperativeMatrix = current.cooperativeMatrix || merge_in.cooperativeMatrix;
    current.cooperativeMatrixRobustBufferAccess = current.cooperativeMatrixRobustBufferAccess || merge_in.cooperativeMatrixRobustBufferAccess;
}
void compare_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR const& supported, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR const& requested) {
    if (requested.computeDerivativeGroupQuads && !supported.computeDerivativeGroupQuads) {
        error_list.push_back("VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR::computeDerivativeGroupQuads");
    }
    if (requested.computeDerivativeGroupLinear && !supported.computeDerivativeGroupLinear) {
        error_list.push_back("VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR::computeDerivativeGroupLinear");
    }
}
void merge_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR & current, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR const& merge_in) {
    current.computeDerivativeGroupQuads = current.computeDerivativeGroupQuads || merge_in.computeDerivativeGroupQuads;
    current.computeDerivativeGroupLinear = current.computeDerivativeGroupLinear || merge_in.computeDerivativeGroupLinear;
}
void compare_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR const& supported, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR const& requested) {
    if (requested.videoEncodeAV1 && !supported.videoEncodeAV1) {
        error_list.push_back("VkPhysicalDeviceVideoEncodeAV1FeaturesKHR::videoEncodeAV1");
    }
}
void merge_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR & current, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR const& merge_in) {
    current.videoEncodeAV1 = current.videoEncodeAV1 || merge_in.videoEncodeAV1;
}
void compare_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoDecodeVP9FeaturesKHR const& supported, VkPhysicalDeviceVideoDecodeVP9FeaturesKHR const& requested) {
    if (requested.videoDecodeVP9 && !supported.videoDecodeVP9) {
        error_list.push_back("VkPhysicalDeviceVideoDecodeVP9FeaturesKHR::videoDecodeVP9");
    }
}
void merge_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR & current, VkPhysicalDeviceVideoDecodeVP9FeaturesKHR const& merge_in) {
    current.videoDecodeVP9 = current.videoDecodeVP9 || merge_in.videoDecodeVP9;
}
void compare_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoMaintenance1FeaturesKHR const& supported, VkPhysicalDeviceVideoMaintenance1FeaturesKHR const& requested) {
    if (requested.videoMaintenance1 && !supported.videoMaintenance1) {
        error_list.push_back("VkPhysicalDeviceVideoMaintenance1FeaturesKHR::videoMaintenance1");
    }
}
void merge_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(VkPhysicalDeviceVideoMaintenance1FeaturesKHR & current, VkPhysicalDeviceVideoMaintenance1FeaturesKHR const& merge_in) {
    current.videoMaintenance1 = current.videoMaintenance1 || merge_in.videoMaintenance1;
}
void compare_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR const& supported, VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR const& requested) {
    if (requested.unifiedImageLayouts && !supported.unifiedImageLayouts) {
        error_list.push_back("VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR::unifiedImageLayouts");
    }
    if (requested.unifiedImageLayoutsVideo && !supported.unifiedImageLayoutsVideo) {
        error_list.push_back("VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR::unifiedImageLayoutsVideo");
    }
}
void merge_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR & current, VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR const& merge_in) {
    current.unifiedImageLayouts = current.unifiedImageLayouts || merge_in.unifiedImageLayouts;
    current.unifiedImageLayoutsVideo = current.unifiedImageLayoutsVideo || merge_in.unifiedImageLayoutsVideo;
}
void compare_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR const& supported, VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR const& requested) {
    if (requested.videoEncodeIntraRefresh && !supported.videoEncodeIntraRefresh) {
        error_list.push_back("VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR::videoEncodeIntraRefresh");
    }
}
void merge_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR & current, VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR const& merge_in) {
    current.videoEncodeIntraRefresh = current.videoEncodeIntraRefresh || merge_in.videoEncodeIntraRefresh;
}
void compare_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR const& supported, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR const& requested) {
    if (requested.videoEncodeQuantizationMap && !supported.videoEncodeQuantizationMap) {
        error_list.push_back("VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR::videoEncodeQuantizationMap");
    }
}
void merge_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR & current, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR const& merge_in) {
    current.videoEncodeQuantizationMap = current.videoEncodeQuantizationMap || merge_in.videoEncodeQuantizationMap;
}
void compare_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR const& supported, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR const& requested) {
    if (requested.shaderRelaxedExtendedInstruction && !supported.shaderRelaxedExtendedInstruction) {
        error_list.push_back("VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR::shaderRelaxedExtendedInstruction");
    }
}
void merge_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR & current, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR const& merge_in) {
    current.shaderRelaxedExtendedInstruction = current.shaderRelaxedExtendedInstruction || merge_in.shaderRelaxedExtendedInstruction;
}
void compare_VkPhysicalDeviceMaintenance7FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance7FeaturesKHR const& supported, VkPhysicalDeviceMaintenance7FeaturesKHR const& requested) {
    if (requested.maintenance7 && !supported.maintenance7) {
        error_list.push_back("VkPhysicalDeviceMaintenance7FeaturesKHR::maintenance7");
    }
}
void merge_VkPhysicalDeviceMaintenance7FeaturesKHR(VkPhysicalDeviceMaintenance7FeaturesKHR & current, VkPhysicalDeviceMaintenance7FeaturesKHR const& merge_in) {
    current.maintenance7 = current.maintenance7 || merge_in.maintenance7;
}
void compare_VkPhysicalDeviceMaintenance8FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance8FeaturesKHR const& supported, VkPhysicalDeviceMaintenance8FeaturesKHR const& requested) {
    if (requested.maintenance8 && !supported.maintenance8) {
        error_list.push_back("VkPhysicalDeviceMaintenance8FeaturesKHR::maintenance8");
    }
}
void merge_VkPhysicalDeviceMaintenance8FeaturesKHR(VkPhysicalDeviceMaintenance8FeaturesKHR & current, VkPhysicalDeviceMaintenance8FeaturesKHR const& merge_in) {
    current.maintenance8 = current.maintenance8 || merge_in.maintenance8;
}
void compare_VkPhysicalDeviceMaintenance9FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceMaintenance9FeaturesKHR const& supported, VkPhysicalDeviceMaintenance9FeaturesKHR const& requested) {
    if (requested.maintenance9 && !supported.maintenance9) {
        error_list.push_back("VkPhysicalDeviceMaintenance9FeaturesKHR::maintenance9");
    }
}
void merge_VkPhysicalDeviceMaintenance9FeaturesKHR(VkPhysicalDeviceMaintenance9FeaturesKHR & current, VkPhysicalDeviceMaintenance9FeaturesKHR const& merge_in) {
    current.maintenance9 = current.maintenance9 || merge_in.maintenance9;
}
void compare_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceVideoMaintenance2FeaturesKHR const& supported, VkPhysicalDeviceVideoMaintenance2FeaturesKHR const& requested) {
    if (requested.videoMaintenance2 && !supported.videoMaintenance2) {
        error_list.push_back("VkPhysicalDeviceVideoMaintenance2FeaturesKHR::videoMaintenance2");
    }
}
void merge_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(VkPhysicalDeviceVideoMaintenance2FeaturesKHR & current, VkPhysicalDeviceVideoMaintenance2FeaturesKHR const& merge_in) {
    current.videoMaintenance2 = current.videoMaintenance2 || merge_in.videoMaintenance2;
}
void compare_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR const& supported, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR const& requested) {
    if (requested.depthClampZeroOne && !supported.depthClampZeroOne) {
        error_list.push_back("VkPhysicalDeviceDepthClampZeroOneFeaturesKHR::depthClampZeroOne");
    }
}
void merge_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR & current, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR const& merge_in) {
    current.depthClampZeroOne = current.depthClampZeroOne || merge_in.depthClampZeroOne;
}
void compare_VkPhysicalDeviceRobustness2FeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceRobustness2FeaturesKHR const& supported, VkPhysicalDeviceRobustness2FeaturesKHR const& requested) {
    if (requested.robustBufferAccess2 && !supported.robustBufferAccess2) {
        error_list.push_back("VkPhysicalDeviceRobustness2FeaturesKHR::robustBufferAccess2");
    }
    if (requested.robustImageAccess2 && !supported.robustImageAccess2) {
        error_list.push_back("VkPhysicalDeviceRobustness2FeaturesKHR::robustImageAccess2");
    }
    if (requested.nullDescriptor && !supported.nullDescriptor) {
        error_list.push_back("VkPhysicalDeviceRobustness2FeaturesKHR::nullDescriptor");
    }
}
void merge_VkPhysicalDeviceRobustness2FeaturesKHR(VkPhysicalDeviceRobustness2FeaturesKHR & current, VkPhysicalDeviceRobustness2FeaturesKHR const& merge_in) {
    current.robustBufferAccess2 = current.robustBufferAccess2 || merge_in.robustBufferAccess2;
    current.robustImageAccess2 = current.robustImageAccess2 || merge_in.robustImageAccess2;
    current.nullDescriptor = current.nullDescriptor || merge_in.nullDescriptor;
}
void compare_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR const& supported, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR const& requested) {
    if (requested.presentModeFifoLatestReady && !supported.presentModeFifoLatestReady) {
        error_list.push_back("VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR::presentModeFifoLatestReady");
    }
}
void merge_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR & current, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR const& merge_in) {
    current.presentModeFifoLatestReady = current.presentModeFifoLatestReady || merge_in.presentModeFifoLatestReady;
}
void compare_VkPhysicalDeviceTransformFeedbackFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceTransformFeedbackFeaturesEXT const& supported, VkPhysicalDeviceTransformFeedbackFeaturesEXT const& requested) {
    if (requested.transformFeedback && !supported.transformFeedback) {
        error_list.push_back("VkPhysicalDeviceTransformFeedbackFeaturesEXT::transformFeedback");
    }
    if (requested.geometryStreams && !supported.geometryStreams) {
        error_list.push_back("VkPhysicalDeviceTransformFeedbackFeaturesEXT::geometryStreams");
    }
}
void merge_VkPhysicalDeviceTransformFeedbackFeaturesEXT(VkPhysicalDeviceTransformFeedbackFeaturesEXT & current, VkPhysicalDeviceTransformFeedbackFeaturesEXT const& merge_in) {
    current.transformFeedback = current.transformFeedback || merge_in.transformFeedback;
    current.geometryStreams = current.geometryStreams || merge_in.geometryStreams;
}
void compare_VkPhysicalDeviceCornerSampledImageFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCornerSampledImageFeaturesNV const& supported, VkPhysicalDeviceCornerSampledImageFeaturesNV const& requested) {
    if (requested.cornerSampledImage && !supported.cornerSampledImage) {
        error_list.push_back("VkPhysicalDeviceCornerSampledImageFeaturesNV::cornerSampledImage");
    }
}
void merge_VkPhysicalDeviceCornerSampledImageFeaturesNV(VkPhysicalDeviceCornerSampledImageFeaturesNV & current, VkPhysicalDeviceCornerSampledImageFeaturesNV const& merge_in) {
    current.cornerSampledImage = current.cornerSampledImage || merge_in.cornerSampledImage;
}
void compare_VkPhysicalDeviceASTCDecodeFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceASTCDecodeFeaturesEXT const& supported, VkPhysicalDeviceASTCDecodeFeaturesEXT const& requested) {
    if (requested.decodeModeSharedExponent && !supported.decodeModeSharedExponent) {
        error_list.push_back("VkPhysicalDeviceASTCDecodeFeaturesEXT::decodeModeSharedExponent");
    }
}
void merge_VkPhysicalDeviceASTCDecodeFeaturesEXT(VkPhysicalDeviceASTCDecodeFeaturesEXT & current, VkPhysicalDeviceASTCDecodeFeaturesEXT const& merge_in) {
    current.decodeModeSharedExponent = current.decodeModeSharedExponent || merge_in.decodeModeSharedExponent;
}
void compare_VkPhysicalDeviceConditionalRenderingFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceConditionalRenderingFeaturesEXT const& supported, VkPhysicalDeviceConditionalRenderingFeaturesEXT const& requested) {
    if (requested.conditionalRendering && !supported.conditionalRendering) {
        error_list.push_back("VkPhysicalDeviceConditionalRenderingFeaturesEXT::conditionalRendering");
    }
    if (requested.inheritedConditionalRendering && !supported.inheritedConditionalRendering) {
        error_list.push_back("VkPhysicalDeviceConditionalRenderingFeaturesEXT::inheritedConditionalRendering");
    }
}
void merge_VkPhysicalDeviceConditionalRenderingFeaturesEXT(VkPhysicalDeviceConditionalRenderingFeaturesEXT & current, VkPhysicalDeviceConditionalRenderingFeaturesEXT const& merge_in) {
    current.conditionalRendering = current.conditionalRendering || merge_in.conditionalRendering;
    current.inheritedConditionalRendering = current.inheritedConditionalRendering || merge_in.inheritedConditionalRendering;
}
void compare_VkPhysicalDeviceDepthClipEnableFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDepthClipEnableFeaturesEXT const& supported, VkPhysicalDeviceDepthClipEnableFeaturesEXT const& requested) {
    if (requested.depthClipEnable && !supported.depthClipEnable) {
        error_list.push_back("VkPhysicalDeviceDepthClipEnableFeaturesEXT::depthClipEnable");
    }
}
void merge_VkPhysicalDeviceDepthClipEnableFeaturesEXT(VkPhysicalDeviceDepthClipEnableFeaturesEXT & current, VkPhysicalDeviceDepthClipEnableFeaturesEXT const& merge_in) {
    current.depthClipEnable = current.depthClipEnable || merge_in.depthClipEnable;
}
void compare_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(std::vector<std::string> & error_list, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG const& supported, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG const& requested) {
    if (requested.relaxedLineRasterization && !supported.relaxedLineRasterization) {
        error_list.push_back("VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG::relaxedLineRasterization");
    }
}
void merge_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG & current, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG const& merge_in) {
    current.relaxedLineRasterization = current.relaxedLineRasterization || merge_in.relaxedLineRasterization;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(std::vector<std::string> & error_list, VkPhysicalDeviceShaderEnqueueFeaturesAMDX const& supported, VkPhysicalDeviceShaderEnqueueFeaturesAMDX const& requested) {
    if (requested.shaderEnqueue && !supported.shaderEnqueue) {
        error_list.push_back("VkPhysicalDeviceShaderEnqueueFeaturesAMDX::shaderEnqueue");
    }
    if (requested.shaderMeshEnqueue && !supported.shaderMeshEnqueue) {
        error_list.push_back("VkPhysicalDeviceShaderEnqueueFeaturesAMDX::shaderMeshEnqueue");
    }
}
void merge_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(VkPhysicalDeviceShaderEnqueueFeaturesAMDX & current, VkPhysicalDeviceShaderEnqueueFeaturesAMDX const& merge_in) {
    current.shaderEnqueue = current.shaderEnqueue || merge_in.shaderEnqueue;
    current.shaderMeshEnqueue = current.shaderMeshEnqueue || merge_in.shaderMeshEnqueue;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const& supported, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const& requested) {
    if (requested.advancedBlendCoherentOperations && !supported.advancedBlendCoherentOperations) {
        error_list.push_back("VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT::advancedBlendCoherentOperations");
    }
}
void merge_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT & current, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const& merge_in) {
    current.advancedBlendCoherentOperations = current.advancedBlendCoherentOperations || merge_in.advancedBlendCoherentOperations;
}
void compare_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const& supported, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const& requested) {
    if (requested.shaderSMBuiltins && !supported.shaderSMBuiltins) {
        error_list.push_back("VkPhysicalDeviceShaderSMBuiltinsFeaturesNV::shaderSMBuiltins");
    }
}
void merge_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV & current, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const& merge_in) {
    current.shaderSMBuiltins = current.shaderSMBuiltins || merge_in.shaderSMBuiltins;
}
void compare_VkPhysicalDeviceShadingRateImageFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceShadingRateImageFeaturesNV const& supported, VkPhysicalDeviceShadingRateImageFeaturesNV const& requested) {
    if (requested.shadingRateImage && !supported.shadingRateImage) {
        error_list.push_back("VkPhysicalDeviceShadingRateImageFeaturesNV::shadingRateImage");
    }
    if (requested.shadingRateCoarseSampleOrder && !supported.shadingRateCoarseSampleOrder) {
        error_list.push_back("VkPhysicalDeviceShadingRateImageFeaturesNV::shadingRateCoarseSampleOrder");
    }
}
void merge_VkPhysicalDeviceShadingRateImageFeaturesNV(VkPhysicalDeviceShadingRateImageFeaturesNV & current, VkPhysicalDeviceShadingRateImageFeaturesNV const& merge_in) {
    current.shadingRateImage = current.shadingRateImage || merge_in.shadingRateImage;
    current.shadingRateCoarseSampleOrder = current.shadingRateCoarseSampleOrder || merge_in.shadingRateCoarseSampleOrder;
}
void compare_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const& supported, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const& requested) {
    if (requested.representativeFragmentTest && !supported.representativeFragmentTest) {
        error_list.push_back("VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV::representativeFragmentTest");
    }
}
void merge_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV & current, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const& merge_in) {
    current.representativeFragmentTest = current.representativeFragmentTest || merge_in.representativeFragmentTest;
}
void compare_VkPhysicalDeviceMeshShaderFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceMeshShaderFeaturesNV const& supported, VkPhysicalDeviceMeshShaderFeaturesNV const& requested) {
    if (requested.taskShader && !supported.taskShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesNV::taskShader");
    }
    if (requested.meshShader && !supported.meshShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesNV::meshShader");
    }
}
void merge_VkPhysicalDeviceMeshShaderFeaturesNV(VkPhysicalDeviceMeshShaderFeaturesNV & current, VkPhysicalDeviceMeshShaderFeaturesNV const& merge_in) {
    current.taskShader = current.taskShader || merge_in.taskShader;
    current.meshShader = current.meshShader || merge_in.meshShader;
}
void compare_VkPhysicalDeviceShaderImageFootprintFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceShaderImageFootprintFeaturesNV const& supported, VkPhysicalDeviceShaderImageFootprintFeaturesNV const& requested) {
    if (requested.imageFootprint && !supported.imageFootprint) {
        error_list.push_back("VkPhysicalDeviceShaderImageFootprintFeaturesNV::imageFootprint");
    }
}
void merge_VkPhysicalDeviceShaderImageFootprintFeaturesNV(VkPhysicalDeviceShaderImageFootprintFeaturesNV & current, VkPhysicalDeviceShaderImageFootprintFeaturesNV const& merge_in) {
    current.imageFootprint = current.imageFootprint || merge_in.imageFootprint;
}
void compare_VkPhysicalDeviceExclusiveScissorFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceExclusiveScissorFeaturesNV const& supported, VkPhysicalDeviceExclusiveScissorFeaturesNV const& requested) {
    if (requested.exclusiveScissor && !supported.exclusiveScissor) {
        error_list.push_back("VkPhysicalDeviceExclusiveScissorFeaturesNV::exclusiveScissor");
    }
}
void merge_VkPhysicalDeviceExclusiveScissorFeaturesNV(VkPhysicalDeviceExclusiveScissorFeaturesNV & current, VkPhysicalDeviceExclusiveScissorFeaturesNV const& merge_in) {
    current.exclusiveScissor = current.exclusiveScissor || merge_in.exclusiveScissor;
}
void compare_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(std::vector<std::string> & error_list, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const& supported, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const& requested) {
    if (requested.shaderIntegerFunctions2 && !supported.shaderIntegerFunctions2) {
        error_list.push_back("VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL::shaderIntegerFunctions2");
    }
}
void merge_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL & current, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const& merge_in) {
    current.shaderIntegerFunctions2 = current.shaderIntegerFunctions2 || merge_in.shaderIntegerFunctions2;
}
void compare_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentDensityMapFeaturesEXT const& supported, VkPhysicalDeviceFragmentDensityMapFeaturesEXT const& requested) {
    if (requested.fragmentDensityMap && !supported.fragmentDensityMap) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMapFeaturesEXT::fragmentDensityMap");
    }
    if (requested.fragmentDensityMapDynamic && !supported.fragmentDensityMapDynamic) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMapFeaturesEXT::fragmentDensityMapDynamic");
    }
    if (requested.fragmentDensityMapNonSubsampledImages && !supported.fragmentDensityMapNonSubsampledImages) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMapFeaturesEXT::fragmentDensityMapNonSubsampledImages");
    }
}
void merge_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(VkPhysicalDeviceFragmentDensityMapFeaturesEXT & current, VkPhysicalDeviceFragmentDensityMapFeaturesEXT const& merge_in) {
    current.fragmentDensityMap = current.fragmentDensityMap || merge_in.fragmentDensityMap;
    current.fragmentDensityMapDynamic = current.fragmentDensityMapDynamic || merge_in.fragmentDensityMapDynamic;
    current.fragmentDensityMapNonSubsampledImages = current.fragmentDensityMapNonSubsampledImages || merge_in.fragmentDensityMapNonSubsampledImages;
}
void compare_VkPhysicalDeviceCoherentMemoryFeaturesAMD(std::vector<std::string> & error_list, VkPhysicalDeviceCoherentMemoryFeaturesAMD const& supported, VkPhysicalDeviceCoherentMemoryFeaturesAMD const& requested) {
    if (requested.deviceCoherentMemory && !supported.deviceCoherentMemory) {
        error_list.push_back("VkPhysicalDeviceCoherentMemoryFeaturesAMD::deviceCoherentMemory");
    }
}
void merge_VkPhysicalDeviceCoherentMemoryFeaturesAMD(VkPhysicalDeviceCoherentMemoryFeaturesAMD & current, VkPhysicalDeviceCoherentMemoryFeaturesAMD const& merge_in) {
    current.deviceCoherentMemory = current.deviceCoherentMemory || merge_in.deviceCoherentMemory;
}
void compare_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT const& supported, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT const& requested) {
    if (requested.shaderImageInt64Atomics && !supported.shaderImageInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT::shaderImageInt64Atomics");
    }
    if (requested.sparseImageInt64Atomics && !supported.sparseImageInt64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT::sparseImageInt64Atomics");
    }
}
void merge_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT & current, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT const& merge_in) {
    current.shaderImageInt64Atomics = current.shaderImageInt64Atomics || merge_in.shaderImageInt64Atomics;
    current.sparseImageInt64Atomics = current.sparseImageInt64Atomics || merge_in.sparseImageInt64Atomics;
}
void compare_VkPhysicalDeviceMemoryPriorityFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMemoryPriorityFeaturesEXT const& supported, VkPhysicalDeviceMemoryPriorityFeaturesEXT const& requested) {
    if (requested.memoryPriority && !supported.memoryPriority) {
        error_list.push_back("VkPhysicalDeviceMemoryPriorityFeaturesEXT::memoryPriority");
    }
}
void merge_VkPhysicalDeviceMemoryPriorityFeaturesEXT(VkPhysicalDeviceMemoryPriorityFeaturesEXT & current, VkPhysicalDeviceMemoryPriorityFeaturesEXT const& merge_in) {
    current.memoryPriority = current.memoryPriority || merge_in.memoryPriority;
}
void compare_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const& supported, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const& requested) {
    if (requested.dedicatedAllocationImageAliasing && !supported.dedicatedAllocationImageAliasing) {
        error_list.push_back("VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV::dedicatedAllocationImageAliasing");
    }
}
void merge_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV & current, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const& merge_in) {
    current.dedicatedAllocationImageAliasing = current.dedicatedAllocationImageAliasing || merge_in.dedicatedAllocationImageAliasing;
}
void compare_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const& supported, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const& requested) {
    if (requested.bufferDeviceAddress && !supported.bufferDeviceAddress) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT::bufferDeviceAddress");
    }
    if (requested.bufferDeviceAddressCaptureReplay && !supported.bufferDeviceAddressCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT::bufferDeviceAddressCaptureReplay");
    }
    if (requested.bufferDeviceAddressMultiDevice && !supported.bufferDeviceAddressMultiDevice) {
        error_list.push_back("VkPhysicalDeviceBufferDeviceAddressFeaturesEXT::bufferDeviceAddressMultiDevice");
    }
}
void merge_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT & current, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const& merge_in) {
    current.bufferDeviceAddress = current.bufferDeviceAddress || merge_in.bufferDeviceAddress;
    current.bufferDeviceAddressCaptureReplay = current.bufferDeviceAddressCaptureReplay || merge_in.bufferDeviceAddressCaptureReplay;
    current.bufferDeviceAddressMultiDevice = current.bufferDeviceAddressMultiDevice || merge_in.bufferDeviceAddressMultiDevice;
}
void compare_VkPhysicalDeviceCooperativeMatrixFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCooperativeMatrixFeaturesNV const& supported, VkPhysicalDeviceCooperativeMatrixFeaturesNV const& requested) {
    if (requested.cooperativeMatrix && !supported.cooperativeMatrix) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrixFeaturesNV::cooperativeMatrix");
    }
    if (requested.cooperativeMatrixRobustBufferAccess && !supported.cooperativeMatrixRobustBufferAccess) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrixFeaturesNV::cooperativeMatrixRobustBufferAccess");
    }
}
void merge_VkPhysicalDeviceCooperativeMatrixFeaturesNV(VkPhysicalDeviceCooperativeMatrixFeaturesNV & current, VkPhysicalDeviceCooperativeMatrixFeaturesNV const& merge_in) {
    current.cooperativeMatrix = current.cooperativeMatrix || merge_in.cooperativeMatrix;
    current.cooperativeMatrixRobustBufferAccess = current.cooperativeMatrixRobustBufferAccess || merge_in.cooperativeMatrixRobustBufferAccess;
}
void compare_VkPhysicalDeviceCoverageReductionModeFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCoverageReductionModeFeaturesNV const& supported, VkPhysicalDeviceCoverageReductionModeFeaturesNV const& requested) {
    if (requested.coverageReductionMode && !supported.coverageReductionMode) {
        error_list.push_back("VkPhysicalDeviceCoverageReductionModeFeaturesNV::coverageReductionMode");
    }
}
void merge_VkPhysicalDeviceCoverageReductionModeFeaturesNV(VkPhysicalDeviceCoverageReductionModeFeaturesNV & current, VkPhysicalDeviceCoverageReductionModeFeaturesNV const& merge_in) {
    current.coverageReductionMode = current.coverageReductionMode || merge_in.coverageReductionMode;
}
void compare_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const& supported, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const& requested) {
    if (requested.fragmentShaderSampleInterlock && !supported.fragmentShaderSampleInterlock) {
        error_list.push_back("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderSampleInterlock");
    }
    if (requested.fragmentShaderPixelInterlock && !supported.fragmentShaderPixelInterlock) {
        error_list.push_back("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderPixelInterlock");
    }
    if (requested.fragmentShaderShadingRateInterlock && !supported.fragmentShaderShadingRateInterlock) {
        error_list.push_back("VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT::fragmentShaderShadingRateInterlock");
    }
}
void merge_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT & current, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const& merge_in) {
    current.fragmentShaderSampleInterlock = current.fragmentShaderSampleInterlock || merge_in.fragmentShaderSampleInterlock;
    current.fragmentShaderPixelInterlock = current.fragmentShaderPixelInterlock || merge_in.fragmentShaderPixelInterlock;
    current.fragmentShaderShadingRateInterlock = current.fragmentShaderShadingRateInterlock || merge_in.fragmentShaderShadingRateInterlock;
}
void compare_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const& supported, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const& requested) {
    if (requested.ycbcrImageArrays && !supported.ycbcrImageArrays) {
        error_list.push_back("VkPhysicalDeviceYcbcrImageArraysFeaturesEXT::ycbcrImageArrays");
    }
}
void merge_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT & current, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const& merge_in) {
    current.ycbcrImageArrays = current.ycbcrImageArrays || merge_in.ycbcrImageArrays;
}
void compare_VkPhysicalDeviceProvokingVertexFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceProvokingVertexFeaturesEXT const& supported, VkPhysicalDeviceProvokingVertexFeaturesEXT const& requested) {
    if (requested.provokingVertexLast && !supported.provokingVertexLast) {
        error_list.push_back("VkPhysicalDeviceProvokingVertexFeaturesEXT::provokingVertexLast");
    }
    if (requested.transformFeedbackPreservesProvokingVertex && !supported.transformFeedbackPreservesProvokingVertex) {
        error_list.push_back("VkPhysicalDeviceProvokingVertexFeaturesEXT::transformFeedbackPreservesProvokingVertex");
    }
}
void merge_VkPhysicalDeviceProvokingVertexFeaturesEXT(VkPhysicalDeviceProvokingVertexFeaturesEXT & current, VkPhysicalDeviceProvokingVertexFeaturesEXT const& merge_in) {
    current.provokingVertexLast = current.provokingVertexLast || merge_in.provokingVertexLast;
    current.transformFeedbackPreservesProvokingVertex = current.transformFeedbackPreservesProvokingVertex || merge_in.transformFeedbackPreservesProvokingVertex;
}
void compare_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT const& supported, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT const& requested) {
    if (requested.shaderBufferFloat32Atomics && !supported.shaderBufferFloat32Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat32Atomics");
    }
    if (requested.shaderBufferFloat32AtomicAdd && !supported.shaderBufferFloat32AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat32AtomicAdd");
    }
    if (requested.shaderBufferFloat64Atomics && !supported.shaderBufferFloat64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat64Atomics");
    }
    if (requested.shaderBufferFloat64AtomicAdd && !supported.shaderBufferFloat64AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderBufferFloat64AtomicAdd");
    }
    if (requested.shaderSharedFloat32Atomics && !supported.shaderSharedFloat32Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat32Atomics");
    }
    if (requested.shaderSharedFloat32AtomicAdd && !supported.shaderSharedFloat32AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat32AtomicAdd");
    }
    if (requested.shaderSharedFloat64Atomics && !supported.shaderSharedFloat64Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat64Atomics");
    }
    if (requested.shaderSharedFloat64AtomicAdd && !supported.shaderSharedFloat64AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderSharedFloat64AtomicAdd");
    }
    if (requested.shaderImageFloat32Atomics && !supported.shaderImageFloat32Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderImageFloat32Atomics");
    }
    if (requested.shaderImageFloat32AtomicAdd && !supported.shaderImageFloat32AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::shaderImageFloat32AtomicAdd");
    }
    if (requested.sparseImageFloat32Atomics && !supported.sparseImageFloat32Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::sparseImageFloat32Atomics");
    }
    if (requested.sparseImageFloat32AtomicAdd && !supported.sparseImageFloat32AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloatFeaturesEXT::sparseImageFloat32AtomicAdd");
    }
}
void merge_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT & current, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT const& merge_in) {
    current.shaderBufferFloat32Atomics = current.shaderBufferFloat32Atomics || merge_in.shaderBufferFloat32Atomics;
    current.shaderBufferFloat32AtomicAdd = current.shaderBufferFloat32AtomicAdd || merge_in.shaderBufferFloat32AtomicAdd;
    current.shaderBufferFloat64Atomics = current.shaderBufferFloat64Atomics || merge_in.shaderBufferFloat64Atomics;
    current.shaderBufferFloat64AtomicAdd = current.shaderBufferFloat64AtomicAdd || merge_in.shaderBufferFloat64AtomicAdd;
    current.shaderSharedFloat32Atomics = current.shaderSharedFloat32Atomics || merge_in.shaderSharedFloat32Atomics;
    current.shaderSharedFloat32AtomicAdd = current.shaderSharedFloat32AtomicAdd || merge_in.shaderSharedFloat32AtomicAdd;
    current.shaderSharedFloat64Atomics = current.shaderSharedFloat64Atomics || merge_in.shaderSharedFloat64Atomics;
    current.shaderSharedFloat64AtomicAdd = current.shaderSharedFloat64AtomicAdd || merge_in.shaderSharedFloat64AtomicAdd;
    current.shaderImageFloat32Atomics = current.shaderImageFloat32Atomics || merge_in.shaderImageFloat32Atomics;
    current.shaderImageFloat32AtomicAdd = current.shaderImageFloat32AtomicAdd || merge_in.shaderImageFloat32AtomicAdd;
    current.sparseImageFloat32Atomics = current.sparseImageFloat32Atomics || merge_in.sparseImageFloat32Atomics;
    current.sparseImageFloat32AtomicAdd = current.sparseImageFloat32AtomicAdd || merge_in.sparseImageFloat32AtomicAdd;
}
void compare_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT const& supported, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT const& requested) {
    if (requested.extendedDynamicState && !supported.extendedDynamicState) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicStateFeaturesEXT::extendedDynamicState");
    }
}
void merge_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT & current, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT const& merge_in) {
    current.extendedDynamicState = current.extendedDynamicState || merge_in.extendedDynamicState;
}
void compare_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT const& supported, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT const& requested) {
    if (requested.memoryMapPlaced && !supported.memoryMapPlaced) {
        error_list.push_back("VkPhysicalDeviceMapMemoryPlacedFeaturesEXT::memoryMapPlaced");
    }
    if (requested.memoryMapRangePlaced && !supported.memoryMapRangePlaced) {
        error_list.push_back("VkPhysicalDeviceMapMemoryPlacedFeaturesEXT::memoryMapRangePlaced");
    }
    if (requested.memoryUnmapReserve && !supported.memoryUnmapReserve) {
        error_list.push_back("VkPhysicalDeviceMapMemoryPlacedFeaturesEXT::memoryUnmapReserve");
    }
}
void merge_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT & current, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT const& merge_in) {
    current.memoryMapPlaced = current.memoryMapPlaced || merge_in.memoryMapPlaced;
    current.memoryMapRangePlaced = current.memoryMapRangePlaced || merge_in.memoryMapRangePlaced;
    current.memoryUnmapReserve = current.memoryUnmapReserve || merge_in.memoryUnmapReserve;
}
void compare_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT const& supported, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT const& requested) {
    if (requested.shaderBufferFloat16Atomics && !supported.shaderBufferFloat16Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat16Atomics");
    }
    if (requested.shaderBufferFloat16AtomicAdd && !supported.shaderBufferFloat16AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat16AtomicAdd");
    }
    if (requested.shaderBufferFloat16AtomicMinMax && !supported.shaderBufferFloat16AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat16AtomicMinMax");
    }
    if (requested.shaderBufferFloat32AtomicMinMax && !supported.shaderBufferFloat32AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat32AtomicMinMax");
    }
    if (requested.shaderBufferFloat64AtomicMinMax && !supported.shaderBufferFloat64AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderBufferFloat64AtomicMinMax");
    }
    if (requested.shaderSharedFloat16Atomics && !supported.shaderSharedFloat16Atomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat16Atomics");
    }
    if (requested.shaderSharedFloat16AtomicAdd && !supported.shaderSharedFloat16AtomicAdd) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat16AtomicAdd");
    }
    if (requested.shaderSharedFloat16AtomicMinMax && !supported.shaderSharedFloat16AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat16AtomicMinMax");
    }
    if (requested.shaderSharedFloat32AtomicMinMax && !supported.shaderSharedFloat32AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat32AtomicMinMax");
    }
    if (requested.shaderSharedFloat64AtomicMinMax && !supported.shaderSharedFloat64AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderSharedFloat64AtomicMinMax");
    }
    if (requested.shaderImageFloat32AtomicMinMax && !supported.shaderImageFloat32AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::shaderImageFloat32AtomicMinMax");
    }
    if (requested.sparseImageFloat32AtomicMinMax && !supported.sparseImageFloat32AtomicMinMax) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT::sparseImageFloat32AtomicMinMax");
    }
}
void merge_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT & current, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT const& merge_in) {
    current.shaderBufferFloat16Atomics = current.shaderBufferFloat16Atomics || merge_in.shaderBufferFloat16Atomics;
    current.shaderBufferFloat16AtomicAdd = current.shaderBufferFloat16AtomicAdd || merge_in.shaderBufferFloat16AtomicAdd;
    current.shaderBufferFloat16AtomicMinMax = current.shaderBufferFloat16AtomicMinMax || merge_in.shaderBufferFloat16AtomicMinMax;
    current.shaderBufferFloat32AtomicMinMax = current.shaderBufferFloat32AtomicMinMax || merge_in.shaderBufferFloat32AtomicMinMax;
    current.shaderBufferFloat64AtomicMinMax = current.shaderBufferFloat64AtomicMinMax || merge_in.shaderBufferFloat64AtomicMinMax;
    current.shaderSharedFloat16Atomics = current.shaderSharedFloat16Atomics || merge_in.shaderSharedFloat16Atomics;
    current.shaderSharedFloat16AtomicAdd = current.shaderSharedFloat16AtomicAdd || merge_in.shaderSharedFloat16AtomicAdd;
    current.shaderSharedFloat16AtomicMinMax = current.shaderSharedFloat16AtomicMinMax || merge_in.shaderSharedFloat16AtomicMinMax;
    current.shaderSharedFloat32AtomicMinMax = current.shaderSharedFloat32AtomicMinMax || merge_in.shaderSharedFloat32AtomicMinMax;
    current.shaderSharedFloat64AtomicMinMax = current.shaderSharedFloat64AtomicMinMax || merge_in.shaderSharedFloat64AtomicMinMax;
    current.shaderImageFloat32AtomicMinMax = current.shaderImageFloat32AtomicMinMax || merge_in.shaderImageFloat32AtomicMinMax;
    current.sparseImageFloat32AtomicMinMax = current.sparseImageFloat32AtomicMinMax || merge_in.sparseImageFloat32AtomicMinMax;
}
void compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const& supported, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const& requested) {
    if (requested.deviceGeneratedCommands && !supported.deviceGeneratedCommands) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV::deviceGeneratedCommands");
    }
}
void merge_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV & current, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const& merge_in) {
    current.deviceGeneratedCommands = current.deviceGeneratedCommands || merge_in.deviceGeneratedCommands;
}
void compare_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceInheritedViewportScissorFeaturesNV const& supported, VkPhysicalDeviceInheritedViewportScissorFeaturesNV const& requested) {
    if (requested.inheritedViewportScissor2D && !supported.inheritedViewportScissor2D) {
        error_list.push_back("VkPhysicalDeviceInheritedViewportScissorFeaturesNV::inheritedViewportScissor2D");
    }
}
void merge_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(VkPhysicalDeviceInheritedViewportScissorFeaturesNV & current, VkPhysicalDeviceInheritedViewportScissorFeaturesNV const& merge_in) {
    current.inheritedViewportScissor2D = current.inheritedViewportScissor2D || merge_in.inheritedViewportScissor2D;
}
void compare_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const& supported, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const& requested) {
    if (requested.texelBufferAlignment && !supported.texelBufferAlignment) {
        error_list.push_back("VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT::texelBufferAlignment");
    }
}
void merge_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT & current, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const& merge_in) {
    current.texelBufferAlignment = current.texelBufferAlignment || merge_in.texelBufferAlignment;
}
void compare_VkPhysicalDeviceDepthBiasControlFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDepthBiasControlFeaturesEXT const& supported, VkPhysicalDeviceDepthBiasControlFeaturesEXT const& requested) {
    if (requested.depthBiasControl && !supported.depthBiasControl) {
        error_list.push_back("VkPhysicalDeviceDepthBiasControlFeaturesEXT::depthBiasControl");
    }
    if (requested.leastRepresentableValueForceUnormRepresentation && !supported.leastRepresentableValueForceUnormRepresentation) {
        error_list.push_back("VkPhysicalDeviceDepthBiasControlFeaturesEXT::leastRepresentableValueForceUnormRepresentation");
    }
    if (requested.floatRepresentation && !supported.floatRepresentation) {
        error_list.push_back("VkPhysicalDeviceDepthBiasControlFeaturesEXT::floatRepresentation");
    }
    if (requested.depthBiasExact && !supported.depthBiasExact) {
        error_list.push_back("VkPhysicalDeviceDepthBiasControlFeaturesEXT::depthBiasExact");
    }
}
void merge_VkPhysicalDeviceDepthBiasControlFeaturesEXT(VkPhysicalDeviceDepthBiasControlFeaturesEXT & current, VkPhysicalDeviceDepthBiasControlFeaturesEXT const& merge_in) {
    current.depthBiasControl = current.depthBiasControl || merge_in.depthBiasControl;
    current.leastRepresentableValueForceUnormRepresentation = current.leastRepresentableValueForceUnormRepresentation || merge_in.leastRepresentableValueForceUnormRepresentation;
    current.floatRepresentation = current.floatRepresentation || merge_in.floatRepresentation;
    current.depthBiasExact = current.depthBiasExact || merge_in.depthBiasExact;
}
void compare_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT const& supported, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT const& requested) {
    if (requested.deviceMemoryReport && !supported.deviceMemoryReport) {
        error_list.push_back("VkPhysicalDeviceDeviceMemoryReportFeaturesEXT::deviceMemoryReport");
    }
}
void merge_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT & current, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT const& merge_in) {
    current.deviceMemoryReport = current.deviceMemoryReport || merge_in.deviceMemoryReport;
}
void compare_VkPhysicalDeviceCustomBorderColorFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceCustomBorderColorFeaturesEXT const& supported, VkPhysicalDeviceCustomBorderColorFeaturesEXT const& requested) {
    if (requested.customBorderColors && !supported.customBorderColors) {
        error_list.push_back("VkPhysicalDeviceCustomBorderColorFeaturesEXT::customBorderColors");
    }
    if (requested.customBorderColorWithoutFormat && !supported.customBorderColorWithoutFormat) {
        error_list.push_back("VkPhysicalDeviceCustomBorderColorFeaturesEXT::customBorderColorWithoutFormat");
    }
}
void merge_VkPhysicalDeviceCustomBorderColorFeaturesEXT(VkPhysicalDeviceCustomBorderColorFeaturesEXT & current, VkPhysicalDeviceCustomBorderColorFeaturesEXT const& merge_in) {
    current.customBorderColors = current.customBorderColors || merge_in.customBorderColors;
    current.customBorderColorWithoutFormat = current.customBorderColorWithoutFormat || merge_in.customBorderColorWithoutFormat;
}
void compare_VkPhysicalDevicePresentBarrierFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDevicePresentBarrierFeaturesNV const& supported, VkPhysicalDevicePresentBarrierFeaturesNV const& requested) {
    if (requested.presentBarrier && !supported.presentBarrier) {
        error_list.push_back("VkPhysicalDevicePresentBarrierFeaturesNV::presentBarrier");
    }
}
void merge_VkPhysicalDevicePresentBarrierFeaturesNV(VkPhysicalDevicePresentBarrierFeaturesNV & current, VkPhysicalDevicePresentBarrierFeaturesNV const& merge_in) {
    current.presentBarrier = current.presentBarrier || merge_in.presentBarrier;
}
void compare_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDiagnosticsConfigFeaturesNV const& supported, VkPhysicalDeviceDiagnosticsConfigFeaturesNV const& requested) {
    if (requested.diagnosticsConfig && !supported.diagnosticsConfig) {
        error_list.push_back("VkPhysicalDeviceDiagnosticsConfigFeaturesNV::diagnosticsConfig");
    }
}
void merge_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(VkPhysicalDeviceDiagnosticsConfigFeaturesNV & current, VkPhysicalDeviceDiagnosticsConfigFeaturesNV const& merge_in) {
    current.diagnosticsConfig = current.diagnosticsConfig || merge_in.diagnosticsConfig;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCudaKernelLaunchFeaturesNV const& supported, VkPhysicalDeviceCudaKernelLaunchFeaturesNV const& requested) {
    if (requested.cudaKernelLaunchFeatures && !supported.cudaKernelLaunchFeatures) {
        error_list.push_back("VkPhysicalDeviceCudaKernelLaunchFeaturesNV::cudaKernelLaunchFeatures");
    }
}
void merge_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(VkPhysicalDeviceCudaKernelLaunchFeaturesNV & current, VkPhysicalDeviceCudaKernelLaunchFeaturesNV const& merge_in) {
    current.cudaKernelLaunchFeatures = current.cudaKernelLaunchFeatures || merge_in.cudaKernelLaunchFeatures;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceTileShadingFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceTileShadingFeaturesQCOM const& supported, VkPhysicalDeviceTileShadingFeaturesQCOM const& requested) {
    if (requested.tileShading && !supported.tileShading) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShading");
    }
    if (requested.tileShadingFragmentStage && !supported.tileShadingFragmentStage) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingFragmentStage");
    }
    if (requested.tileShadingColorAttachments && !supported.tileShadingColorAttachments) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingColorAttachments");
    }
    if (requested.tileShadingDepthAttachments && !supported.tileShadingDepthAttachments) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingDepthAttachments");
    }
    if (requested.tileShadingStencilAttachments && !supported.tileShadingStencilAttachments) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingStencilAttachments");
    }
    if (requested.tileShadingInputAttachments && !supported.tileShadingInputAttachments) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingInputAttachments");
    }
    if (requested.tileShadingSampledAttachments && !supported.tileShadingSampledAttachments) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingSampledAttachments");
    }
    if (requested.tileShadingPerTileDraw && !supported.tileShadingPerTileDraw) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingPerTileDraw");
    }
    if (requested.tileShadingPerTileDispatch && !supported.tileShadingPerTileDispatch) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingPerTileDispatch");
    }
    if (requested.tileShadingDispatchTile && !supported.tileShadingDispatchTile) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingDispatchTile");
    }
    if (requested.tileShadingApron && !supported.tileShadingApron) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingApron");
    }
    if (requested.tileShadingAnisotropicApron && !supported.tileShadingAnisotropicApron) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingAnisotropicApron");
    }
    if (requested.tileShadingAtomicOps && !supported.tileShadingAtomicOps) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingAtomicOps");
    }
    if (requested.tileShadingImageProcessing && !supported.tileShadingImageProcessing) {
        error_list.push_back("VkPhysicalDeviceTileShadingFeaturesQCOM::tileShadingImageProcessing");
    }
}
void merge_VkPhysicalDeviceTileShadingFeaturesQCOM(VkPhysicalDeviceTileShadingFeaturesQCOM & current, VkPhysicalDeviceTileShadingFeaturesQCOM const& merge_in) {
    current.tileShading = current.tileShading || merge_in.tileShading;
    current.tileShadingFragmentStage = current.tileShadingFragmentStage || merge_in.tileShadingFragmentStage;
    current.tileShadingColorAttachments = current.tileShadingColorAttachments || merge_in.tileShadingColorAttachments;
    current.tileShadingDepthAttachments = current.tileShadingDepthAttachments || merge_in.tileShadingDepthAttachments;
    current.tileShadingStencilAttachments = current.tileShadingStencilAttachments || merge_in.tileShadingStencilAttachments;
    current.tileShadingInputAttachments = current.tileShadingInputAttachments || merge_in.tileShadingInputAttachments;
    current.tileShadingSampledAttachments = current.tileShadingSampledAttachments || merge_in.tileShadingSampledAttachments;
    current.tileShadingPerTileDraw = current.tileShadingPerTileDraw || merge_in.tileShadingPerTileDraw;
    current.tileShadingPerTileDispatch = current.tileShadingPerTileDispatch || merge_in.tileShadingPerTileDispatch;
    current.tileShadingDispatchTile = current.tileShadingDispatchTile || merge_in.tileShadingDispatchTile;
    current.tileShadingApron = current.tileShadingApron || merge_in.tileShadingApron;
    current.tileShadingAnisotropicApron = current.tileShadingAnisotropicApron || merge_in.tileShadingAnisotropicApron;
    current.tileShadingAtomicOps = current.tileShadingAtomicOps || merge_in.tileShadingAtomicOps;
    current.tileShadingImageProcessing = current.tileShadingImageProcessing || merge_in.tileShadingImageProcessing;
}
void compare_VkPhysicalDeviceDescriptorBufferFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDescriptorBufferFeaturesEXT const& supported, VkPhysicalDeviceDescriptorBufferFeaturesEXT const& requested) {
    if (requested.descriptorBuffer && !supported.descriptorBuffer) {
        error_list.push_back("VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBuffer");
    }
    if (requested.descriptorBufferCaptureReplay && !supported.descriptorBufferCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferCaptureReplay");
    }
    if (requested.descriptorBufferImageLayoutIgnored && !supported.descriptorBufferImageLayoutIgnored) {
        error_list.push_back("VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferImageLayoutIgnored");
    }
    if (requested.descriptorBufferPushDescriptors && !supported.descriptorBufferPushDescriptors) {
        error_list.push_back("VkPhysicalDeviceDescriptorBufferFeaturesEXT::descriptorBufferPushDescriptors");
    }
}
void merge_VkPhysicalDeviceDescriptorBufferFeaturesEXT(VkPhysicalDeviceDescriptorBufferFeaturesEXT & current, VkPhysicalDeviceDescriptorBufferFeaturesEXT const& merge_in) {
    current.descriptorBuffer = current.descriptorBuffer || merge_in.descriptorBuffer;
    current.descriptorBufferCaptureReplay = current.descriptorBufferCaptureReplay || merge_in.descriptorBufferCaptureReplay;
    current.descriptorBufferImageLayoutIgnored = current.descriptorBufferImageLayoutIgnored || merge_in.descriptorBufferImageLayoutIgnored;
    current.descriptorBufferPushDescriptors = current.descriptorBufferPushDescriptors || merge_in.descriptorBufferPushDescriptors;
}
void compare_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT const& supported, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT const& requested) {
    if (requested.graphicsPipelineLibrary && !supported.graphicsPipelineLibrary) {
        error_list.push_back("VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT::graphicsPipelineLibrary");
    }
}
void merge_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT & current, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT const& merge_in) {
    current.graphicsPipelineLibrary = current.graphicsPipelineLibrary || merge_in.graphicsPipelineLibrary;
}
void compare_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(std::vector<std::string> & error_list, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD const& supported, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD const& requested) {
    if (requested.shaderEarlyAndLateFragmentTests && !supported.shaderEarlyAndLateFragmentTests) {
        error_list.push_back("VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD::shaderEarlyAndLateFragmentTests");
    }
}
void merge_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD & current, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD const& merge_in) {
    current.shaderEarlyAndLateFragmentTests = current.shaderEarlyAndLateFragmentTests || merge_in.shaderEarlyAndLateFragmentTests;
}
void compare_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV const& supported, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV const& requested) {
    if (requested.fragmentShadingRateEnums && !supported.fragmentShadingRateEnums) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV::fragmentShadingRateEnums");
    }
    if (requested.supersampleFragmentShadingRates && !supported.supersampleFragmentShadingRates) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV::supersampleFragmentShadingRates");
    }
    if (requested.noInvocationFragmentShadingRates && !supported.noInvocationFragmentShadingRates) {
        error_list.push_back("VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV::noInvocationFragmentShadingRates");
    }
}
void merge_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV & current, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV const& merge_in) {
    current.fragmentShadingRateEnums = current.fragmentShadingRateEnums || merge_in.fragmentShadingRateEnums;
    current.supersampleFragmentShadingRates = current.supersampleFragmentShadingRates || merge_in.supersampleFragmentShadingRates;
    current.noInvocationFragmentShadingRates = current.noInvocationFragmentShadingRates || merge_in.noInvocationFragmentShadingRates;
}
void compare_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV const& supported, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV const& requested) {
    if (requested.rayTracingMotionBlur && !supported.rayTracingMotionBlur) {
        error_list.push_back("VkPhysicalDeviceRayTracingMotionBlurFeaturesNV::rayTracingMotionBlur");
    }
    if (requested.rayTracingMotionBlurPipelineTraceRaysIndirect && !supported.rayTracingMotionBlurPipelineTraceRaysIndirect) {
        error_list.push_back("VkPhysicalDeviceRayTracingMotionBlurFeaturesNV::rayTracingMotionBlurPipelineTraceRaysIndirect");
    }
}
void merge_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV & current, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV const& merge_in) {
    current.rayTracingMotionBlur = current.rayTracingMotionBlur || merge_in.rayTracingMotionBlur;
    current.rayTracingMotionBlurPipelineTraceRaysIndirect = current.rayTracingMotionBlurPipelineTraceRaysIndirect || merge_in.rayTracingMotionBlurPipelineTraceRaysIndirect;
}
void compare_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT const& supported, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT const& requested) {
    if (requested.ycbcr2plane444Formats && !supported.ycbcr2plane444Formats) {
        error_list.push_back("VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT::ycbcr2plane444Formats");
    }
}
void merge_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT & current, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT const& merge_in) {
    current.ycbcr2plane444Formats = current.ycbcr2plane444Formats || merge_in.ycbcr2plane444Formats;
}
void compare_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT const& supported, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT const& requested) {
    if (requested.fragmentDensityMapDeferred && !supported.fragmentDensityMapDeferred) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMap2FeaturesEXT::fragmentDensityMapDeferred");
    }
}
void merge_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT & current, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT const& merge_in) {
    current.fragmentDensityMapDeferred = current.fragmentDensityMapDeferred || merge_in.fragmentDensityMapDeferred;
}
void compare_VkPhysicalDeviceImageCompressionControlFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceImageCompressionControlFeaturesEXT const& supported, VkPhysicalDeviceImageCompressionControlFeaturesEXT const& requested) {
    if (requested.imageCompressionControl && !supported.imageCompressionControl) {
        error_list.push_back("VkPhysicalDeviceImageCompressionControlFeaturesEXT::imageCompressionControl");
    }
}
void merge_VkPhysicalDeviceImageCompressionControlFeaturesEXT(VkPhysicalDeviceImageCompressionControlFeaturesEXT & current, VkPhysicalDeviceImageCompressionControlFeaturesEXT const& merge_in) {
    current.imageCompressionControl = current.imageCompressionControl || merge_in.imageCompressionControl;
}
void compare_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT const& supported, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT const& requested) {
    if (requested.attachmentFeedbackLoopLayout && !supported.attachmentFeedbackLoopLayout) {
        error_list.push_back("VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT::attachmentFeedbackLoopLayout");
    }
}
void merge_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT & current, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT const& merge_in) {
    current.attachmentFeedbackLoopLayout = current.attachmentFeedbackLoopLayout || merge_in.attachmentFeedbackLoopLayout;
}
void compare_VkPhysicalDevice4444FormatsFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevice4444FormatsFeaturesEXT const& supported, VkPhysicalDevice4444FormatsFeaturesEXT const& requested) {
    if (requested.formatA4R4G4B4 && !supported.formatA4R4G4B4) {
        error_list.push_back("VkPhysicalDevice4444FormatsFeaturesEXT::formatA4R4G4B4");
    }
    if (requested.formatA4B4G4R4 && !supported.formatA4B4G4R4) {
        error_list.push_back("VkPhysicalDevice4444FormatsFeaturesEXT::formatA4B4G4R4");
    }
}
void merge_VkPhysicalDevice4444FormatsFeaturesEXT(VkPhysicalDevice4444FormatsFeaturesEXT & current, VkPhysicalDevice4444FormatsFeaturesEXT const& merge_in) {
    current.formatA4R4G4B4 = current.formatA4R4G4B4 || merge_in.formatA4R4G4B4;
    current.formatA4B4G4R4 = current.formatA4B4G4R4 || merge_in.formatA4B4G4R4;
}
void compare_VkPhysicalDeviceFaultFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFaultFeaturesEXT const& supported, VkPhysicalDeviceFaultFeaturesEXT const& requested) {
    if (requested.deviceFault && !supported.deviceFault) {
        error_list.push_back("VkPhysicalDeviceFaultFeaturesEXT::deviceFault");
    }
    if (requested.deviceFaultVendorBinary && !supported.deviceFaultVendorBinary) {
        error_list.push_back("VkPhysicalDeviceFaultFeaturesEXT::deviceFaultVendorBinary");
    }
}
void merge_VkPhysicalDeviceFaultFeaturesEXT(VkPhysicalDeviceFaultFeaturesEXT & current, VkPhysicalDeviceFaultFeaturesEXT const& merge_in) {
    current.deviceFault = current.deviceFault || merge_in.deviceFault;
    current.deviceFaultVendorBinary = current.deviceFaultVendorBinary || merge_in.deviceFaultVendorBinary;
}
void compare_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT const& supported, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT const& requested) {
    if (requested.rasterizationOrderColorAttachmentAccess && !supported.rasterizationOrderColorAttachmentAccess) {
        error_list.push_back("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT::rasterizationOrderColorAttachmentAccess");
    }
    if (requested.rasterizationOrderDepthAttachmentAccess && !supported.rasterizationOrderDepthAttachmentAccess) {
        error_list.push_back("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT::rasterizationOrderDepthAttachmentAccess");
    }
    if (requested.rasterizationOrderStencilAttachmentAccess && !supported.rasterizationOrderStencilAttachmentAccess) {
        error_list.push_back("VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT::rasterizationOrderStencilAttachmentAccess");
    }
}
void merge_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT & current, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT const& merge_in) {
    current.rasterizationOrderColorAttachmentAccess = current.rasterizationOrderColorAttachmentAccess || merge_in.rasterizationOrderColorAttachmentAccess;
    current.rasterizationOrderDepthAttachmentAccess = current.rasterizationOrderDepthAttachmentAccess || merge_in.rasterizationOrderDepthAttachmentAccess;
    current.rasterizationOrderStencilAttachmentAccess = current.rasterizationOrderStencilAttachmentAccess || merge_in.rasterizationOrderStencilAttachmentAccess;
}
void compare_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT const& supported, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT const& requested) {
    if (requested.formatRgba10x6WithoutYCbCrSampler && !supported.formatRgba10x6WithoutYCbCrSampler) {
        error_list.push_back("VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT::formatRgba10x6WithoutYCbCrSampler");
    }
}
void merge_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT & current, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT const& merge_in) {
    current.formatRgba10x6WithoutYCbCrSampler = current.formatRgba10x6WithoutYCbCrSampler || merge_in.formatRgba10x6WithoutYCbCrSampler;
}
void compare_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT const& supported, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT const& requested) {
    if (requested.mutableDescriptorType && !supported.mutableDescriptorType) {
        error_list.push_back("VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT::mutableDescriptorType");
    }
}
void merge_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT & current, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT const& merge_in) {
    current.mutableDescriptorType = current.mutableDescriptorType || merge_in.mutableDescriptorType;
}
void compare_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT const& supported, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT const& requested) {
    if (requested.vertexInputDynamicState && !supported.vertexInputDynamicState) {
        error_list.push_back("VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT::vertexInputDynamicState");
    }
}
void merge_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT & current, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT const& merge_in) {
    current.vertexInputDynamicState = current.vertexInputDynamicState || merge_in.vertexInputDynamicState;
}
void compare_VkPhysicalDeviceAddressBindingReportFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceAddressBindingReportFeaturesEXT const& supported, VkPhysicalDeviceAddressBindingReportFeaturesEXT const& requested) {
    if (requested.reportAddressBinding && !supported.reportAddressBinding) {
        error_list.push_back("VkPhysicalDeviceAddressBindingReportFeaturesEXT::reportAddressBinding");
    }
}
void merge_VkPhysicalDeviceAddressBindingReportFeaturesEXT(VkPhysicalDeviceAddressBindingReportFeaturesEXT & current, VkPhysicalDeviceAddressBindingReportFeaturesEXT const& merge_in) {
    current.reportAddressBinding = current.reportAddressBinding || merge_in.reportAddressBinding;
}
void compare_VkPhysicalDeviceDepthClipControlFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDepthClipControlFeaturesEXT const& supported, VkPhysicalDeviceDepthClipControlFeaturesEXT const& requested) {
    if (requested.depthClipControl && !supported.depthClipControl) {
        error_list.push_back("VkPhysicalDeviceDepthClipControlFeaturesEXT::depthClipControl");
    }
}
void merge_VkPhysicalDeviceDepthClipControlFeaturesEXT(VkPhysicalDeviceDepthClipControlFeaturesEXT & current, VkPhysicalDeviceDepthClipControlFeaturesEXT const& merge_in) {
    current.depthClipControl = current.depthClipControl || merge_in.depthClipControl;
}
void compare_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT const& supported, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT const& requested) {
    if (requested.primitiveTopologyListRestart && !supported.primitiveTopologyListRestart) {
        error_list.push_back("VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT::primitiveTopologyListRestart");
    }
    if (requested.primitiveTopologyPatchListRestart && !supported.primitiveTopologyPatchListRestart) {
        error_list.push_back("VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT::primitiveTopologyPatchListRestart");
    }
}
void merge_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT & current, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT const& merge_in) {
    current.primitiveTopologyListRestart = current.primitiveTopologyListRestart || merge_in.primitiveTopologyListRestart;
    current.primitiveTopologyPatchListRestart = current.primitiveTopologyPatchListRestart || merge_in.primitiveTopologyPatchListRestart;
}
void compare_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(std::vector<std::string> & error_list, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI const& supported, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI const& requested) {
    if (requested.subpassShading && !supported.subpassShading) {
        error_list.push_back("VkPhysicalDeviceSubpassShadingFeaturesHUAWEI::subpassShading");
    }
}
void merge_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI & current, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI const& merge_in) {
    current.subpassShading = current.subpassShading || merge_in.subpassShading;
}
void compare_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(std::vector<std::string> & error_list, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI const& supported, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI const& requested) {
    if (requested.invocationMask && !supported.invocationMask) {
        error_list.push_back("VkPhysicalDeviceInvocationMaskFeaturesHUAWEI::invocationMask");
    }
}
void merge_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI & current, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI const& merge_in) {
    current.invocationMask = current.invocationMask || merge_in.invocationMask;
}
void compare_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV const& supported, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV const& requested) {
    if (requested.externalMemoryRDMA && !supported.externalMemoryRDMA) {
        error_list.push_back("VkPhysicalDeviceExternalMemoryRDMAFeaturesNV::externalMemoryRDMA");
    }
}
void merge_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV & current, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV const& merge_in) {
    current.externalMemoryRDMA = current.externalMemoryRDMA || merge_in.externalMemoryRDMA;
}
void compare_VkPhysicalDevicePipelinePropertiesFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevicePipelinePropertiesFeaturesEXT const& supported, VkPhysicalDevicePipelinePropertiesFeaturesEXT const& requested) {
    if (requested.pipelinePropertiesIdentifier && !supported.pipelinePropertiesIdentifier) {
        error_list.push_back("VkPhysicalDevicePipelinePropertiesFeaturesEXT::pipelinePropertiesIdentifier");
    }
}
void merge_VkPhysicalDevicePipelinePropertiesFeaturesEXT(VkPhysicalDevicePipelinePropertiesFeaturesEXT & current, VkPhysicalDevicePipelinePropertiesFeaturesEXT const& merge_in) {
    current.pipelinePropertiesIdentifier = current.pipelinePropertiesIdentifier || merge_in.pipelinePropertiesIdentifier;
}
void compare_VkPhysicalDeviceFrameBoundaryFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFrameBoundaryFeaturesEXT const& supported, VkPhysicalDeviceFrameBoundaryFeaturesEXT const& requested) {
    if (requested.frameBoundary && !supported.frameBoundary) {
        error_list.push_back("VkPhysicalDeviceFrameBoundaryFeaturesEXT::frameBoundary");
    }
}
void merge_VkPhysicalDeviceFrameBoundaryFeaturesEXT(VkPhysicalDeviceFrameBoundaryFeaturesEXT & current, VkPhysicalDeviceFrameBoundaryFeaturesEXT const& merge_in) {
    current.frameBoundary = current.frameBoundary || merge_in.frameBoundary;
}
void compare_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT const& supported, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT const& requested) {
    if (requested.multisampledRenderToSingleSampled && !supported.multisampledRenderToSingleSampled) {
        error_list.push_back("VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT::multisampledRenderToSingleSampled");
    }
}
void merge_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT & current, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT const& merge_in) {
    current.multisampledRenderToSingleSampled = current.multisampledRenderToSingleSampled || merge_in.multisampledRenderToSingleSampled;
}
void compare_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT const& supported, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT const& requested) {
    if (requested.extendedDynamicState2 && !supported.extendedDynamicState2) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT::extendedDynamicState2");
    }
    if (requested.extendedDynamicState2LogicOp && !supported.extendedDynamicState2LogicOp) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT::extendedDynamicState2LogicOp");
    }
    if (requested.extendedDynamicState2PatchControlPoints && !supported.extendedDynamicState2PatchControlPoints) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState2FeaturesEXT::extendedDynamicState2PatchControlPoints");
    }
}
void merge_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT & current, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT const& merge_in) {
    current.extendedDynamicState2 = current.extendedDynamicState2 || merge_in.extendedDynamicState2;
    current.extendedDynamicState2LogicOp = current.extendedDynamicState2LogicOp || merge_in.extendedDynamicState2LogicOp;
    current.extendedDynamicState2PatchControlPoints = current.extendedDynamicState2PatchControlPoints || merge_in.extendedDynamicState2PatchControlPoints;
}
void compare_VkPhysicalDeviceColorWriteEnableFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceColorWriteEnableFeaturesEXT const& supported, VkPhysicalDeviceColorWriteEnableFeaturesEXT const& requested) {
    if (requested.colorWriteEnable && !supported.colorWriteEnable) {
        error_list.push_back("VkPhysicalDeviceColorWriteEnableFeaturesEXT::colorWriteEnable");
    }
}
void merge_VkPhysicalDeviceColorWriteEnableFeaturesEXT(VkPhysicalDeviceColorWriteEnableFeaturesEXT & current, VkPhysicalDeviceColorWriteEnableFeaturesEXT const& merge_in) {
    current.colorWriteEnable = current.colorWriteEnable || merge_in.colorWriteEnable;
}
void compare_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT const& supported, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT const& requested) {
    if (requested.primitivesGeneratedQuery && !supported.primitivesGeneratedQuery) {
        error_list.push_back("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT::primitivesGeneratedQuery");
    }
    if (requested.primitivesGeneratedQueryWithRasterizerDiscard && !supported.primitivesGeneratedQueryWithRasterizerDiscard) {
        error_list.push_back("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT::primitivesGeneratedQueryWithRasterizerDiscard");
    }
    if (requested.primitivesGeneratedQueryWithNonZeroStreams && !supported.primitivesGeneratedQueryWithNonZeroStreams) {
        error_list.push_back("VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT::primitivesGeneratedQueryWithNonZeroStreams");
    }
}
void merge_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT & current, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT const& merge_in) {
    current.primitivesGeneratedQuery = current.primitivesGeneratedQuery || merge_in.primitivesGeneratedQuery;
    current.primitivesGeneratedQueryWithRasterizerDiscard = current.primitivesGeneratedQueryWithRasterizerDiscard || merge_in.primitivesGeneratedQueryWithRasterizerDiscard;
    current.primitivesGeneratedQueryWithNonZeroStreams = current.primitivesGeneratedQueryWithNonZeroStreams || merge_in.primitivesGeneratedQueryWithNonZeroStreams;
}
void compare_VkPhysicalDeviceImageViewMinLodFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceImageViewMinLodFeaturesEXT const& supported, VkPhysicalDeviceImageViewMinLodFeaturesEXT const& requested) {
    if (requested.minLod && !supported.minLod) {
        error_list.push_back("VkPhysicalDeviceImageViewMinLodFeaturesEXT::minLod");
    }
}
void merge_VkPhysicalDeviceImageViewMinLodFeaturesEXT(VkPhysicalDeviceImageViewMinLodFeaturesEXT & current, VkPhysicalDeviceImageViewMinLodFeaturesEXT const& merge_in) {
    current.minLod = current.minLod || merge_in.minLod;
}
void compare_VkPhysicalDeviceMultiDrawFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMultiDrawFeaturesEXT const& supported, VkPhysicalDeviceMultiDrawFeaturesEXT const& requested) {
    if (requested.multiDraw && !supported.multiDraw) {
        error_list.push_back("VkPhysicalDeviceMultiDrawFeaturesEXT::multiDraw");
    }
}
void merge_VkPhysicalDeviceMultiDrawFeaturesEXT(VkPhysicalDeviceMultiDrawFeaturesEXT & current, VkPhysicalDeviceMultiDrawFeaturesEXT const& merge_in) {
    current.multiDraw = current.multiDraw || merge_in.multiDraw;
}
void compare_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT const& supported, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT const& requested) {
    if (requested.image2DViewOf3D && !supported.image2DViewOf3D) {
        error_list.push_back("VkPhysicalDeviceImage2DViewOf3DFeaturesEXT::image2DViewOf3D");
    }
    if (requested.sampler2DViewOf3D && !supported.sampler2DViewOf3D) {
        error_list.push_back("VkPhysicalDeviceImage2DViewOf3DFeaturesEXT::sampler2DViewOf3D");
    }
}
void merge_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT & current, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT const& merge_in) {
    current.image2DViewOf3D = current.image2DViewOf3D || merge_in.image2DViewOf3D;
    current.sampler2DViewOf3D = current.sampler2DViewOf3D || merge_in.sampler2DViewOf3D;
}
void compare_VkPhysicalDeviceShaderTileImageFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderTileImageFeaturesEXT const& supported, VkPhysicalDeviceShaderTileImageFeaturesEXT const& requested) {
    if (requested.shaderTileImageColorReadAccess && !supported.shaderTileImageColorReadAccess) {
        error_list.push_back("VkPhysicalDeviceShaderTileImageFeaturesEXT::shaderTileImageColorReadAccess");
    }
    if (requested.shaderTileImageDepthReadAccess && !supported.shaderTileImageDepthReadAccess) {
        error_list.push_back("VkPhysicalDeviceShaderTileImageFeaturesEXT::shaderTileImageDepthReadAccess");
    }
    if (requested.shaderTileImageStencilReadAccess && !supported.shaderTileImageStencilReadAccess) {
        error_list.push_back("VkPhysicalDeviceShaderTileImageFeaturesEXT::shaderTileImageStencilReadAccess");
    }
}
void merge_VkPhysicalDeviceShaderTileImageFeaturesEXT(VkPhysicalDeviceShaderTileImageFeaturesEXT & current, VkPhysicalDeviceShaderTileImageFeaturesEXT const& merge_in) {
    current.shaderTileImageColorReadAccess = current.shaderTileImageColorReadAccess || merge_in.shaderTileImageColorReadAccess;
    current.shaderTileImageDepthReadAccess = current.shaderTileImageDepthReadAccess || merge_in.shaderTileImageDepthReadAccess;
    current.shaderTileImageStencilReadAccess = current.shaderTileImageStencilReadAccess || merge_in.shaderTileImageStencilReadAccess;
}
void compare_VkPhysicalDeviceOpacityMicromapFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceOpacityMicromapFeaturesEXT const& supported, VkPhysicalDeviceOpacityMicromapFeaturesEXT const& requested) {
    if (requested.micromap && !supported.micromap) {
        error_list.push_back("VkPhysicalDeviceOpacityMicromapFeaturesEXT::micromap");
    }
    if (requested.micromapCaptureReplay && !supported.micromapCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceOpacityMicromapFeaturesEXT::micromapCaptureReplay");
    }
    if (requested.micromapHostCommands && !supported.micromapHostCommands) {
        error_list.push_back("VkPhysicalDeviceOpacityMicromapFeaturesEXT::micromapHostCommands");
    }
}
void merge_VkPhysicalDeviceOpacityMicromapFeaturesEXT(VkPhysicalDeviceOpacityMicromapFeaturesEXT & current, VkPhysicalDeviceOpacityMicromapFeaturesEXT const& merge_in) {
    current.micromap = current.micromap || merge_in.micromap;
    current.micromapCaptureReplay = current.micromapCaptureReplay || merge_in.micromapCaptureReplay;
    current.micromapHostCommands = current.micromapHostCommands || merge_in.micromapHostCommands;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceDisplacementMicromapFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDisplacementMicromapFeaturesNV const& supported, VkPhysicalDeviceDisplacementMicromapFeaturesNV const& requested) {
    if (requested.displacementMicromap && !supported.displacementMicromap) {
        error_list.push_back("VkPhysicalDeviceDisplacementMicromapFeaturesNV::displacementMicromap");
    }
}
void merge_VkPhysicalDeviceDisplacementMicromapFeaturesNV(VkPhysicalDeviceDisplacementMicromapFeaturesNV & current, VkPhysicalDeviceDisplacementMicromapFeaturesNV const& merge_in) {
    current.displacementMicromap = current.displacementMicromap || merge_in.displacementMicromap;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(std::vector<std::string> & error_list, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI const& supported, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI const& requested) {
    if (requested.clustercullingShader && !supported.clustercullingShader) {
        error_list.push_back("VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI::clustercullingShader");
    }
    if (requested.multiviewClusterCullingShader && !supported.multiviewClusterCullingShader) {
        error_list.push_back("VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI::multiviewClusterCullingShader");
    }
}
void merge_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI & current, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI const& merge_in) {
    current.clustercullingShader = current.clustercullingShader || merge_in.clustercullingShader;
    current.multiviewClusterCullingShader = current.multiviewClusterCullingShader || merge_in.multiviewClusterCullingShader;
}
void compare_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT const& supported, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT const& requested) {
    if (requested.borderColorSwizzle && !supported.borderColorSwizzle) {
        error_list.push_back("VkPhysicalDeviceBorderColorSwizzleFeaturesEXT::borderColorSwizzle");
    }
    if (requested.borderColorSwizzleFromImage && !supported.borderColorSwizzleFromImage) {
        error_list.push_back("VkPhysicalDeviceBorderColorSwizzleFeaturesEXT::borderColorSwizzleFromImage");
    }
}
void merge_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT & current, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT const& merge_in) {
    current.borderColorSwizzle = current.borderColorSwizzle || merge_in.borderColorSwizzle;
    current.borderColorSwizzleFromImage = current.borderColorSwizzleFromImage || merge_in.borderColorSwizzleFromImage;
}
void compare_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT const& supported, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT const& requested) {
    if (requested.pageableDeviceLocalMemory && !supported.pageableDeviceLocalMemory) {
        error_list.push_back("VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT::pageableDeviceLocalMemory");
    }
}
void merge_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT & current, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT const& merge_in) {
    current.pageableDeviceLocalMemory = current.pageableDeviceLocalMemory || merge_in.pageableDeviceLocalMemory;
}
void compare_VkPhysicalDeviceSchedulingControlsFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceSchedulingControlsFeaturesARM const& supported, VkPhysicalDeviceSchedulingControlsFeaturesARM const& requested) {
    if (requested.schedulingControls && !supported.schedulingControls) {
        error_list.push_back("VkPhysicalDeviceSchedulingControlsFeaturesARM::schedulingControls");
    }
}
void merge_VkPhysicalDeviceSchedulingControlsFeaturesARM(VkPhysicalDeviceSchedulingControlsFeaturesARM & current, VkPhysicalDeviceSchedulingControlsFeaturesARM const& merge_in) {
    current.schedulingControls = current.schedulingControls || merge_in.schedulingControls;
}
void compare_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT const& supported, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT const& requested) {
    if (requested.imageSlicedViewOf3D && !supported.imageSlicedViewOf3D) {
        error_list.push_back("VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT::imageSlicedViewOf3D");
    }
}
void merge_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT & current, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT const& merge_in) {
    current.imageSlicedViewOf3D = current.imageSlicedViewOf3D || merge_in.imageSlicedViewOf3D;
}
void compare_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(std::vector<std::string> & error_list, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE const& supported, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE const& requested) {
    if (requested.descriptorSetHostMapping && !supported.descriptorSetHostMapping) {
        error_list.push_back("VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE::descriptorSetHostMapping");
    }
}
void merge_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE & current, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE const& merge_in) {
    current.descriptorSetHostMapping = current.descriptorSetHostMapping || merge_in.descriptorSetHostMapping;
}
void compare_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT const& supported, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT const& requested) {
    if (requested.nonSeamlessCubeMap && !supported.nonSeamlessCubeMap) {
        error_list.push_back("VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT::nonSeamlessCubeMap");
    }
}
void merge_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT & current, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT const& merge_in) {
    current.nonSeamlessCubeMap = current.nonSeamlessCubeMap || merge_in.nonSeamlessCubeMap;
}
void compare_VkPhysicalDeviceRenderPassStripedFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceRenderPassStripedFeaturesARM const& supported, VkPhysicalDeviceRenderPassStripedFeaturesARM const& requested) {
    if (requested.renderPassStriped && !supported.renderPassStriped) {
        error_list.push_back("VkPhysicalDeviceRenderPassStripedFeaturesARM::renderPassStriped");
    }
}
void merge_VkPhysicalDeviceRenderPassStripedFeaturesARM(VkPhysicalDeviceRenderPassStripedFeaturesARM & current, VkPhysicalDeviceRenderPassStripedFeaturesARM const& merge_in) {
    current.renderPassStriped = current.renderPassStriped || merge_in.renderPassStriped;
}
void compare_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT const& supported, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT const& requested) {
    if (requested.fragmentDensityMapOffset && !supported.fragmentDensityMapOffset) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT::fragmentDensityMapOffset");
    }
}
void merge_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT & current, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT const& merge_in) {
    current.fragmentDensityMapOffset = current.fragmentDensityMapOffset || merge_in.fragmentDensityMapOffset;
}
void compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV const& supported, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV const& requested) {
    if (requested.indirectCopy && !supported.indirectCopy) {
        error_list.push_back("VkPhysicalDeviceCopyMemoryIndirectFeaturesNV::indirectCopy");
    }
}
void merge_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV & current, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV const& merge_in) {
    current.indirectCopy = current.indirectCopy || merge_in.indirectCopy;
}
void compare_VkPhysicalDeviceMemoryDecompressionFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceMemoryDecompressionFeaturesNV const& supported, VkPhysicalDeviceMemoryDecompressionFeaturesNV const& requested) {
    if (requested.memoryDecompression && !supported.memoryDecompression) {
        error_list.push_back("VkPhysicalDeviceMemoryDecompressionFeaturesNV::memoryDecompression");
    }
}
void merge_VkPhysicalDeviceMemoryDecompressionFeaturesNV(VkPhysicalDeviceMemoryDecompressionFeaturesNV & current, VkPhysicalDeviceMemoryDecompressionFeaturesNV const& merge_in) {
    current.memoryDecompression = current.memoryDecompression || merge_in.memoryDecompression;
}
void compare_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV const& supported, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV const& requested) {
    if (requested.deviceGeneratedCompute && !supported.deviceGeneratedCompute) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV::deviceGeneratedCompute");
    }
    if (requested.deviceGeneratedComputePipelines && !supported.deviceGeneratedComputePipelines) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV::deviceGeneratedComputePipelines");
    }
    if (requested.deviceGeneratedComputeCaptureReplay && !supported.deviceGeneratedComputeCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV::deviceGeneratedComputeCaptureReplay");
    }
}
void merge_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV & current, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV const& merge_in) {
    current.deviceGeneratedCompute = current.deviceGeneratedCompute || merge_in.deviceGeneratedCompute;
    current.deviceGeneratedComputePipelines = current.deviceGeneratedComputePipelines || merge_in.deviceGeneratedComputePipelines;
    current.deviceGeneratedComputeCaptureReplay = current.deviceGeneratedComputeCaptureReplay || merge_in.deviceGeneratedComputeCaptureReplay;
}
void compare_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV const& supported, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV const& requested) {
    if (requested.spheres && !supported.spheres) {
        error_list.push_back("VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV::spheres");
    }
    if (requested.linearSweptSpheres && !supported.linearSweptSpheres) {
        error_list.push_back("VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV::linearSweptSpheres");
    }
}
void merge_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV & current, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV const& merge_in) {
    current.spheres = current.spheres || merge_in.spheres;
    current.linearSweptSpheres = current.linearSweptSpheres || merge_in.linearSweptSpheres;
}
void compare_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceLinearColorAttachmentFeaturesNV const& supported, VkPhysicalDeviceLinearColorAttachmentFeaturesNV const& requested) {
    if (requested.linearColorAttachment && !supported.linearColorAttachment) {
        error_list.push_back("VkPhysicalDeviceLinearColorAttachmentFeaturesNV::linearColorAttachment");
    }
}
void merge_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(VkPhysicalDeviceLinearColorAttachmentFeaturesNV & current, VkPhysicalDeviceLinearColorAttachmentFeaturesNV const& merge_in) {
    current.linearColorAttachment = current.linearColorAttachment || merge_in.linearColorAttachment;
}
void compare_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT const& supported, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT const& requested) {
    if (requested.imageCompressionControlSwapchain && !supported.imageCompressionControlSwapchain) {
        error_list.push_back("VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT::imageCompressionControlSwapchain");
    }
}
void merge_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT & current, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT const& merge_in) {
    current.imageCompressionControlSwapchain = current.imageCompressionControlSwapchain || merge_in.imageCompressionControlSwapchain;
}
void compare_VkPhysicalDeviceImageProcessingFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceImageProcessingFeaturesQCOM const& supported, VkPhysicalDeviceImageProcessingFeaturesQCOM const& requested) {
    if (requested.textureSampleWeighted && !supported.textureSampleWeighted) {
        error_list.push_back("VkPhysicalDeviceImageProcessingFeaturesQCOM::textureSampleWeighted");
    }
    if (requested.textureBoxFilter && !supported.textureBoxFilter) {
        error_list.push_back("VkPhysicalDeviceImageProcessingFeaturesQCOM::textureBoxFilter");
    }
    if (requested.textureBlockMatch && !supported.textureBlockMatch) {
        error_list.push_back("VkPhysicalDeviceImageProcessingFeaturesQCOM::textureBlockMatch");
    }
}
void merge_VkPhysicalDeviceImageProcessingFeaturesQCOM(VkPhysicalDeviceImageProcessingFeaturesQCOM & current, VkPhysicalDeviceImageProcessingFeaturesQCOM const& merge_in) {
    current.textureSampleWeighted = current.textureSampleWeighted || merge_in.textureSampleWeighted;
    current.textureBoxFilter = current.textureBoxFilter || merge_in.textureBoxFilter;
    current.textureBlockMatch = current.textureBlockMatch || merge_in.textureBlockMatch;
}
void compare_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceNestedCommandBufferFeaturesEXT const& supported, VkPhysicalDeviceNestedCommandBufferFeaturesEXT const& requested) {
    if (requested.nestedCommandBuffer && !supported.nestedCommandBuffer) {
        error_list.push_back("VkPhysicalDeviceNestedCommandBufferFeaturesEXT::nestedCommandBuffer");
    }
    if (requested.nestedCommandBufferRendering && !supported.nestedCommandBufferRendering) {
        error_list.push_back("VkPhysicalDeviceNestedCommandBufferFeaturesEXT::nestedCommandBufferRendering");
    }
    if (requested.nestedCommandBufferSimultaneousUse && !supported.nestedCommandBufferSimultaneousUse) {
        error_list.push_back("VkPhysicalDeviceNestedCommandBufferFeaturesEXT::nestedCommandBufferSimultaneousUse");
    }
}
void merge_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(VkPhysicalDeviceNestedCommandBufferFeaturesEXT & current, VkPhysicalDeviceNestedCommandBufferFeaturesEXT const& merge_in) {
    current.nestedCommandBuffer = current.nestedCommandBuffer || merge_in.nestedCommandBuffer;
    current.nestedCommandBufferRendering = current.nestedCommandBufferRendering || merge_in.nestedCommandBufferRendering;
    current.nestedCommandBufferSimultaneousUse = current.nestedCommandBufferSimultaneousUse || merge_in.nestedCommandBufferSimultaneousUse;
}
void compare_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT const& supported, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT const& requested) {
    if (requested.extendedDynamicState3TessellationDomainOrigin && !supported.extendedDynamicState3TessellationDomainOrigin) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3TessellationDomainOrigin");
    }
    if (requested.extendedDynamicState3DepthClampEnable && !supported.extendedDynamicState3DepthClampEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3DepthClampEnable");
    }
    if (requested.extendedDynamicState3PolygonMode && !supported.extendedDynamicState3PolygonMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3PolygonMode");
    }
    if (requested.extendedDynamicState3RasterizationSamples && !supported.extendedDynamicState3RasterizationSamples) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3RasterizationSamples");
    }
    if (requested.extendedDynamicState3SampleMask && !supported.extendedDynamicState3SampleMask) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3SampleMask");
    }
    if (requested.extendedDynamicState3AlphaToCoverageEnable && !supported.extendedDynamicState3AlphaToCoverageEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3AlphaToCoverageEnable");
    }
    if (requested.extendedDynamicState3AlphaToOneEnable && !supported.extendedDynamicState3AlphaToOneEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3AlphaToOneEnable");
    }
    if (requested.extendedDynamicState3LogicOpEnable && !supported.extendedDynamicState3LogicOpEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3LogicOpEnable");
    }
    if (requested.extendedDynamicState3ColorBlendEnable && !supported.extendedDynamicState3ColorBlendEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ColorBlendEnable");
    }
    if (requested.extendedDynamicState3ColorBlendEquation && !supported.extendedDynamicState3ColorBlendEquation) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ColorBlendEquation");
    }
    if (requested.extendedDynamicState3ColorWriteMask && !supported.extendedDynamicState3ColorWriteMask) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ColorWriteMask");
    }
    if (requested.extendedDynamicState3RasterizationStream && !supported.extendedDynamicState3RasterizationStream) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3RasterizationStream");
    }
    if (requested.extendedDynamicState3ConservativeRasterizationMode && !supported.extendedDynamicState3ConservativeRasterizationMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ConservativeRasterizationMode");
    }
    if (requested.extendedDynamicState3ExtraPrimitiveOverestimationSize && !supported.extendedDynamicState3ExtraPrimitiveOverestimationSize) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ExtraPrimitiveOverestimationSize");
    }
    if (requested.extendedDynamicState3DepthClipEnable && !supported.extendedDynamicState3DepthClipEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3DepthClipEnable");
    }
    if (requested.extendedDynamicState3SampleLocationsEnable && !supported.extendedDynamicState3SampleLocationsEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3SampleLocationsEnable");
    }
    if (requested.extendedDynamicState3ColorBlendAdvanced && !supported.extendedDynamicState3ColorBlendAdvanced) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ColorBlendAdvanced");
    }
    if (requested.extendedDynamicState3ProvokingVertexMode && !supported.extendedDynamicState3ProvokingVertexMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ProvokingVertexMode");
    }
    if (requested.extendedDynamicState3LineRasterizationMode && !supported.extendedDynamicState3LineRasterizationMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3LineRasterizationMode");
    }
    if (requested.extendedDynamicState3LineStippleEnable && !supported.extendedDynamicState3LineStippleEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3LineStippleEnable");
    }
    if (requested.extendedDynamicState3DepthClipNegativeOneToOne && !supported.extendedDynamicState3DepthClipNegativeOneToOne) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3DepthClipNegativeOneToOne");
    }
    if (requested.extendedDynamicState3ViewportWScalingEnable && !supported.extendedDynamicState3ViewportWScalingEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ViewportWScalingEnable");
    }
    if (requested.extendedDynamicState3ViewportSwizzle && !supported.extendedDynamicState3ViewportSwizzle) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ViewportSwizzle");
    }
    if (requested.extendedDynamicState3CoverageToColorEnable && !supported.extendedDynamicState3CoverageToColorEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageToColorEnable");
    }
    if (requested.extendedDynamicState3CoverageToColorLocation && !supported.extendedDynamicState3CoverageToColorLocation) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageToColorLocation");
    }
    if (requested.extendedDynamicState3CoverageModulationMode && !supported.extendedDynamicState3CoverageModulationMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageModulationMode");
    }
    if (requested.extendedDynamicState3CoverageModulationTableEnable && !supported.extendedDynamicState3CoverageModulationTableEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageModulationTableEnable");
    }
    if (requested.extendedDynamicState3CoverageModulationTable && !supported.extendedDynamicState3CoverageModulationTable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageModulationTable");
    }
    if (requested.extendedDynamicState3CoverageReductionMode && !supported.extendedDynamicState3CoverageReductionMode) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3CoverageReductionMode");
    }
    if (requested.extendedDynamicState3RepresentativeFragmentTestEnable && !supported.extendedDynamicState3RepresentativeFragmentTestEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3RepresentativeFragmentTestEnable");
    }
    if (requested.extendedDynamicState3ShadingRateImageEnable && !supported.extendedDynamicState3ShadingRateImageEnable) {
        error_list.push_back("VkPhysicalDeviceExtendedDynamicState3FeaturesEXT::extendedDynamicState3ShadingRateImageEnable");
    }
}
void merge_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT & current, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT const& merge_in) {
    current.extendedDynamicState3TessellationDomainOrigin = current.extendedDynamicState3TessellationDomainOrigin || merge_in.extendedDynamicState3TessellationDomainOrigin;
    current.extendedDynamicState3DepthClampEnable = current.extendedDynamicState3DepthClampEnable || merge_in.extendedDynamicState3DepthClampEnable;
    current.extendedDynamicState3PolygonMode = current.extendedDynamicState3PolygonMode || merge_in.extendedDynamicState3PolygonMode;
    current.extendedDynamicState3RasterizationSamples = current.extendedDynamicState3RasterizationSamples || merge_in.extendedDynamicState3RasterizationSamples;
    current.extendedDynamicState3SampleMask = current.extendedDynamicState3SampleMask || merge_in.extendedDynamicState3SampleMask;
    current.extendedDynamicState3AlphaToCoverageEnable = current.extendedDynamicState3AlphaToCoverageEnable || merge_in.extendedDynamicState3AlphaToCoverageEnable;
    current.extendedDynamicState3AlphaToOneEnable = current.extendedDynamicState3AlphaToOneEnable || merge_in.extendedDynamicState3AlphaToOneEnable;
    current.extendedDynamicState3LogicOpEnable = current.extendedDynamicState3LogicOpEnable || merge_in.extendedDynamicState3LogicOpEnable;
    current.extendedDynamicState3ColorBlendEnable = current.extendedDynamicState3ColorBlendEnable || merge_in.extendedDynamicState3ColorBlendEnable;
    current.extendedDynamicState3ColorBlendEquation = current.extendedDynamicState3ColorBlendEquation || merge_in.extendedDynamicState3ColorBlendEquation;
    current.extendedDynamicState3ColorWriteMask = current.extendedDynamicState3ColorWriteMask || merge_in.extendedDynamicState3ColorWriteMask;
    current.extendedDynamicState3RasterizationStream = current.extendedDynamicState3RasterizationStream || merge_in.extendedDynamicState3RasterizationStream;
    current.extendedDynamicState3ConservativeRasterizationMode = current.extendedDynamicState3ConservativeRasterizationMode || merge_in.extendedDynamicState3ConservativeRasterizationMode;
    current.extendedDynamicState3ExtraPrimitiveOverestimationSize = current.extendedDynamicState3ExtraPrimitiveOverestimationSize || merge_in.extendedDynamicState3ExtraPrimitiveOverestimationSize;
    current.extendedDynamicState3DepthClipEnable = current.extendedDynamicState3DepthClipEnable || merge_in.extendedDynamicState3DepthClipEnable;
    current.extendedDynamicState3SampleLocationsEnable = current.extendedDynamicState3SampleLocationsEnable || merge_in.extendedDynamicState3SampleLocationsEnable;
    current.extendedDynamicState3ColorBlendAdvanced = current.extendedDynamicState3ColorBlendAdvanced || merge_in.extendedDynamicState3ColorBlendAdvanced;
    current.extendedDynamicState3ProvokingVertexMode = current.extendedDynamicState3ProvokingVertexMode || merge_in.extendedDynamicState3ProvokingVertexMode;
    current.extendedDynamicState3LineRasterizationMode = current.extendedDynamicState3LineRasterizationMode || merge_in.extendedDynamicState3LineRasterizationMode;
    current.extendedDynamicState3LineStippleEnable = current.extendedDynamicState3LineStippleEnable || merge_in.extendedDynamicState3LineStippleEnable;
    current.extendedDynamicState3DepthClipNegativeOneToOne = current.extendedDynamicState3DepthClipNegativeOneToOne || merge_in.extendedDynamicState3DepthClipNegativeOneToOne;
    current.extendedDynamicState3ViewportWScalingEnable = current.extendedDynamicState3ViewportWScalingEnable || merge_in.extendedDynamicState3ViewportWScalingEnable;
    current.extendedDynamicState3ViewportSwizzle = current.extendedDynamicState3ViewportSwizzle || merge_in.extendedDynamicState3ViewportSwizzle;
    current.extendedDynamicState3CoverageToColorEnable = current.extendedDynamicState3CoverageToColorEnable || merge_in.extendedDynamicState3CoverageToColorEnable;
    current.extendedDynamicState3CoverageToColorLocation = current.extendedDynamicState3CoverageToColorLocation || merge_in.extendedDynamicState3CoverageToColorLocation;
    current.extendedDynamicState3CoverageModulationMode = current.extendedDynamicState3CoverageModulationMode || merge_in.extendedDynamicState3CoverageModulationMode;
    current.extendedDynamicState3CoverageModulationTableEnable = current.extendedDynamicState3CoverageModulationTableEnable || merge_in.extendedDynamicState3CoverageModulationTableEnable;
    current.extendedDynamicState3CoverageModulationTable = current.extendedDynamicState3CoverageModulationTable || merge_in.extendedDynamicState3CoverageModulationTable;
    current.extendedDynamicState3CoverageReductionMode = current.extendedDynamicState3CoverageReductionMode || merge_in.extendedDynamicState3CoverageReductionMode;
    current.extendedDynamicState3RepresentativeFragmentTestEnable = current.extendedDynamicState3RepresentativeFragmentTestEnable || merge_in.extendedDynamicState3RepresentativeFragmentTestEnable;
    current.extendedDynamicState3ShadingRateImageEnable = current.extendedDynamicState3ShadingRateImageEnable || merge_in.extendedDynamicState3ShadingRateImageEnable;
}
void compare_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT const& supported, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT const& requested) {
    if (requested.subpassMergeFeedback && !supported.subpassMergeFeedback) {
        error_list.push_back("VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT::subpassMergeFeedback");
    }
}
void merge_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT & current, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT const& merge_in) {
    current.subpassMergeFeedback = current.subpassMergeFeedback || merge_in.subpassMergeFeedback;
}
void compare_VkPhysicalDeviceTensorFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceTensorFeaturesARM const& supported, VkPhysicalDeviceTensorFeaturesARM const& requested) {
    if (requested.tensorNonPacked && !supported.tensorNonPacked) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::tensorNonPacked");
    }
    if (requested.shaderTensorAccess && !supported.shaderTensorAccess) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::shaderTensorAccess");
    }
    if (requested.shaderStorageTensorArrayDynamicIndexing && !supported.shaderStorageTensorArrayDynamicIndexing) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::shaderStorageTensorArrayDynamicIndexing");
    }
    if (requested.shaderStorageTensorArrayNonUniformIndexing && !supported.shaderStorageTensorArrayNonUniformIndexing) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::shaderStorageTensorArrayNonUniformIndexing");
    }
    if (requested.descriptorBindingStorageTensorUpdateAfterBind && !supported.descriptorBindingStorageTensorUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::descriptorBindingStorageTensorUpdateAfterBind");
    }
    if (requested.tensors && !supported.tensors) {
        error_list.push_back("VkPhysicalDeviceTensorFeaturesARM::tensors");
    }
}
void merge_VkPhysicalDeviceTensorFeaturesARM(VkPhysicalDeviceTensorFeaturesARM & current, VkPhysicalDeviceTensorFeaturesARM const& merge_in) {
    current.tensorNonPacked = current.tensorNonPacked || merge_in.tensorNonPacked;
    current.shaderTensorAccess = current.shaderTensorAccess || merge_in.shaderTensorAccess;
    current.shaderStorageTensorArrayDynamicIndexing = current.shaderStorageTensorArrayDynamicIndexing || merge_in.shaderStorageTensorArrayDynamicIndexing;
    current.shaderStorageTensorArrayNonUniformIndexing = current.shaderStorageTensorArrayNonUniformIndexing || merge_in.shaderStorageTensorArrayNonUniformIndexing;
    current.descriptorBindingStorageTensorUpdateAfterBind = current.descriptorBindingStorageTensorUpdateAfterBind || merge_in.descriptorBindingStorageTensorUpdateAfterBind;
    current.tensors = current.tensors || merge_in.tensors;
}
void compare_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceDescriptorBufferTensorFeaturesARM const& supported, VkPhysicalDeviceDescriptorBufferTensorFeaturesARM const& requested) {
    if (requested.descriptorBufferTensorDescriptors && !supported.descriptorBufferTensorDescriptors) {
        error_list.push_back("VkPhysicalDeviceDescriptorBufferTensorFeaturesARM::descriptorBufferTensorDescriptors");
    }
}
void merge_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(VkPhysicalDeviceDescriptorBufferTensorFeaturesARM & current, VkPhysicalDeviceDescriptorBufferTensorFeaturesARM const& merge_in) {
    current.descriptorBufferTensorDescriptors = current.descriptorBufferTensorDescriptors || merge_in.descriptorBufferTensorDescriptors;
}
void compare_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT const& supported, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT const& requested) {
    if (requested.shaderModuleIdentifier && !supported.shaderModuleIdentifier) {
        error_list.push_back("VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT::shaderModuleIdentifier");
    }
}
void merge_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT & current, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT const& merge_in) {
    current.shaderModuleIdentifier = current.shaderModuleIdentifier || merge_in.shaderModuleIdentifier;
}
void compare_VkPhysicalDeviceOpticalFlowFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceOpticalFlowFeaturesNV const& supported, VkPhysicalDeviceOpticalFlowFeaturesNV const& requested) {
    if (requested.opticalFlow && !supported.opticalFlow) {
        error_list.push_back("VkPhysicalDeviceOpticalFlowFeaturesNV::opticalFlow");
    }
}
void merge_VkPhysicalDeviceOpticalFlowFeaturesNV(VkPhysicalDeviceOpticalFlowFeaturesNV & current, VkPhysicalDeviceOpticalFlowFeaturesNV const& merge_in) {
    current.opticalFlow = current.opticalFlow || merge_in.opticalFlow;
}
void compare_VkPhysicalDeviceLegacyDitheringFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceLegacyDitheringFeaturesEXT const& supported, VkPhysicalDeviceLegacyDitheringFeaturesEXT const& requested) {
    if (requested.legacyDithering && !supported.legacyDithering) {
        error_list.push_back("VkPhysicalDeviceLegacyDitheringFeaturesEXT::legacyDithering");
    }
}
void merge_VkPhysicalDeviceLegacyDitheringFeaturesEXT(VkPhysicalDeviceLegacyDitheringFeaturesEXT & current, VkPhysicalDeviceLegacyDitheringFeaturesEXT const& merge_in) {
    current.legacyDithering = current.legacyDithering || merge_in.legacyDithering;
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
void compare_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(std::vector<std::string> & error_list, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID const& supported, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID const& requested) {
    if (requested.externalFormatResolve && !supported.externalFormatResolve) {
        error_list.push_back("VkPhysicalDeviceExternalFormatResolveFeaturesANDROID::externalFormatResolve");
    }
}
void merge_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID & current, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID const& merge_in) {
    current.externalFormatResolve = current.externalFormatResolve || merge_in.externalFormatResolve;
}
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
void compare_VkPhysicalDeviceAntiLagFeaturesAMD(std::vector<std::string> & error_list, VkPhysicalDeviceAntiLagFeaturesAMD const& supported, VkPhysicalDeviceAntiLagFeaturesAMD const& requested) {
    if (requested.antiLag && !supported.antiLag) {
        error_list.push_back("VkPhysicalDeviceAntiLagFeaturesAMD::antiLag");
    }
}
void merge_VkPhysicalDeviceAntiLagFeaturesAMD(VkPhysicalDeviceAntiLagFeaturesAMD & current, VkPhysicalDeviceAntiLagFeaturesAMD const& merge_in) {
    current.antiLag = current.antiLag || merge_in.antiLag;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(std::vector<std::string> & error_list, VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX const& supported, VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX const& requested) {
    if (requested.denseGeometryFormat && !supported.denseGeometryFormat) {
        error_list.push_back("VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX::denseGeometryFormat");
    }
}
void merge_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX & current, VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX const& merge_in) {
    current.denseGeometryFormat = current.denseGeometryFormat || merge_in.denseGeometryFormat;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceShaderObjectFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderObjectFeaturesEXT const& supported, VkPhysicalDeviceShaderObjectFeaturesEXT const& requested) {
    if (requested.shaderObject && !supported.shaderObject) {
        error_list.push_back("VkPhysicalDeviceShaderObjectFeaturesEXT::shaderObject");
    }
}
void merge_VkPhysicalDeviceShaderObjectFeaturesEXT(VkPhysicalDeviceShaderObjectFeaturesEXT & current, VkPhysicalDeviceShaderObjectFeaturesEXT const& merge_in) {
    current.shaderObject = current.shaderObject || merge_in.shaderObject;
}
void compare_VkPhysicalDeviceTilePropertiesFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceTilePropertiesFeaturesQCOM const& supported, VkPhysicalDeviceTilePropertiesFeaturesQCOM const& requested) {
    if (requested.tileProperties && !supported.tileProperties) {
        error_list.push_back("VkPhysicalDeviceTilePropertiesFeaturesQCOM::tileProperties");
    }
}
void merge_VkPhysicalDeviceTilePropertiesFeaturesQCOM(VkPhysicalDeviceTilePropertiesFeaturesQCOM & current, VkPhysicalDeviceTilePropertiesFeaturesQCOM const& merge_in) {
    current.tileProperties = current.tileProperties || merge_in.tileProperties;
}
void compare_VkPhysicalDeviceAmigoProfilingFeaturesSEC(std::vector<std::string> & error_list, VkPhysicalDeviceAmigoProfilingFeaturesSEC const& supported, VkPhysicalDeviceAmigoProfilingFeaturesSEC const& requested) {
    if (requested.amigoProfiling && !supported.amigoProfiling) {
        error_list.push_back("VkPhysicalDeviceAmigoProfilingFeaturesSEC::amigoProfiling");
    }
}
void merge_VkPhysicalDeviceAmigoProfilingFeaturesSEC(VkPhysicalDeviceAmigoProfilingFeaturesSEC & current, VkPhysicalDeviceAmigoProfilingFeaturesSEC const& merge_in) {
    current.amigoProfiling = current.amigoProfiling || merge_in.amigoProfiling;
}
void compare_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM const& supported, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM const& requested) {
    if (requested.multiviewPerViewViewports && !supported.multiviewPerViewViewports) {
        error_list.push_back("VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM::multiviewPerViewViewports");
    }
}
void merge_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM & current, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM const& merge_in) {
    current.multiviewPerViewViewports = current.multiviewPerViewViewports || merge_in.multiviewPerViewViewports;
}
void compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV const& supported, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV const& requested) {
    if (requested.rayTracingInvocationReorder && !supported.rayTracingInvocationReorder) {
        error_list.push_back("VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV::rayTracingInvocationReorder");
    }
}
void merge_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV & current, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV const& merge_in) {
    current.rayTracingInvocationReorder = current.rayTracingInvocationReorder || merge_in.rayTracingInvocationReorder;
}
void compare_VkPhysicalDeviceCooperativeVectorFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCooperativeVectorFeaturesNV const& supported, VkPhysicalDeviceCooperativeVectorFeaturesNV const& requested) {
    if (requested.cooperativeVector && !supported.cooperativeVector) {
        error_list.push_back("VkPhysicalDeviceCooperativeVectorFeaturesNV::cooperativeVector");
    }
    if (requested.cooperativeVectorTraining && !supported.cooperativeVectorTraining) {
        error_list.push_back("VkPhysicalDeviceCooperativeVectorFeaturesNV::cooperativeVectorTraining");
    }
}
void merge_VkPhysicalDeviceCooperativeVectorFeaturesNV(VkPhysicalDeviceCooperativeVectorFeaturesNV & current, VkPhysicalDeviceCooperativeVectorFeaturesNV const& merge_in) {
    current.cooperativeVector = current.cooperativeVector || merge_in.cooperativeVector;
    current.cooperativeVectorTraining = current.cooperativeVectorTraining || merge_in.cooperativeVectorTraining;
}
void compare_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV const& supported, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV const& requested) {
    if (requested.extendedSparseAddressSpace && !supported.extendedSparseAddressSpace) {
        error_list.push_back("VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV::extendedSparseAddressSpace");
    }
}
void merge_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV & current, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV const& merge_in) {
    current.extendedSparseAddressSpace = current.extendedSparseAddressSpace || merge_in.extendedSparseAddressSpace;
}
void compare_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT const& supported, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT const& requested) {
    if (requested.legacyVertexAttributes && !supported.legacyVertexAttributes) {
        error_list.push_back("VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT::legacyVertexAttributes");
    }
}
void merge_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT & current, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT const& merge_in) {
    current.legacyVertexAttributes = current.legacyVertexAttributes || merge_in.legacyVertexAttributes;
}
void compare_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM const& supported, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM const& requested) {
    if (requested.shaderCoreBuiltins && !supported.shaderCoreBuiltins) {
        error_list.push_back("VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM::shaderCoreBuiltins");
    }
}
void merge_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM & current, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM const& merge_in) {
    current.shaderCoreBuiltins = current.shaderCoreBuiltins || merge_in.shaderCoreBuiltins;
}
void compare_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT const& supported, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT const& requested) {
    if (requested.pipelineLibraryGroupHandles && !supported.pipelineLibraryGroupHandles) {
        error_list.push_back("VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT::pipelineLibraryGroupHandles");
    }
}
void merge_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT & current, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT const& merge_in) {
    current.pipelineLibraryGroupHandles = current.pipelineLibraryGroupHandles || merge_in.pipelineLibraryGroupHandles;
}
void compare_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT const& supported, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT const& requested) {
    if (requested.dynamicRenderingUnusedAttachments && !supported.dynamicRenderingUnusedAttachments) {
        error_list.push_back("VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT::dynamicRenderingUnusedAttachments");
    }
}
void merge_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT & current, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT const& merge_in) {
    current.dynamicRenderingUnusedAttachments = current.dynamicRenderingUnusedAttachments || merge_in.dynamicRenderingUnusedAttachments;
}
void compare_VkPhysicalDeviceDataGraphFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceDataGraphFeaturesARM const& supported, VkPhysicalDeviceDataGraphFeaturesARM const& requested) {
    if (requested.dataGraph && !supported.dataGraph) {
        error_list.push_back("VkPhysicalDeviceDataGraphFeaturesARM::dataGraph");
    }
    if (requested.dataGraphUpdateAfterBind && !supported.dataGraphUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceDataGraphFeaturesARM::dataGraphUpdateAfterBind");
    }
    if (requested.dataGraphSpecializationConstants && !supported.dataGraphSpecializationConstants) {
        error_list.push_back("VkPhysicalDeviceDataGraphFeaturesARM::dataGraphSpecializationConstants");
    }
    if (requested.dataGraphDescriptorBuffer && !supported.dataGraphDescriptorBuffer) {
        error_list.push_back("VkPhysicalDeviceDataGraphFeaturesARM::dataGraphDescriptorBuffer");
    }
    if (requested.dataGraphShaderModule && !supported.dataGraphShaderModule) {
        error_list.push_back("VkPhysicalDeviceDataGraphFeaturesARM::dataGraphShaderModule");
    }
}
void merge_VkPhysicalDeviceDataGraphFeaturesARM(VkPhysicalDeviceDataGraphFeaturesARM & current, VkPhysicalDeviceDataGraphFeaturesARM const& merge_in) {
    current.dataGraph = current.dataGraph || merge_in.dataGraph;
    current.dataGraphUpdateAfterBind = current.dataGraphUpdateAfterBind || merge_in.dataGraphUpdateAfterBind;
    current.dataGraphSpecializationConstants = current.dataGraphSpecializationConstants || merge_in.dataGraphSpecializationConstants;
    current.dataGraphDescriptorBuffer = current.dataGraphDescriptorBuffer || merge_in.dataGraphDescriptorBuffer;
    current.dataGraphShaderModule = current.dataGraphShaderModule || merge_in.dataGraphShaderModule;
}
void compare_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM const& supported, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM const& requested) {
    if (requested.multiviewPerViewRenderAreas && !supported.multiviewPerViewRenderAreas) {
        error_list.push_back("VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM::multiviewPerViewRenderAreas");
    }
}
void merge_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM & current, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM const& merge_in) {
    current.multiviewPerViewRenderAreas = current.multiviewPerViewRenderAreas || merge_in.multiviewPerViewRenderAreas;
}
void compare_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDevicePerStageDescriptorSetFeaturesNV const& supported, VkPhysicalDevicePerStageDescriptorSetFeaturesNV const& requested) {
    if (requested.perStageDescriptorSet && !supported.perStageDescriptorSet) {
        error_list.push_back("VkPhysicalDevicePerStageDescriptorSetFeaturesNV::perStageDescriptorSet");
    }
    if (requested.dynamicPipelineLayout && !supported.dynamicPipelineLayout) {
        error_list.push_back("VkPhysicalDevicePerStageDescriptorSetFeaturesNV::dynamicPipelineLayout");
    }
}
void merge_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(VkPhysicalDevicePerStageDescriptorSetFeaturesNV & current, VkPhysicalDevicePerStageDescriptorSetFeaturesNV const& merge_in) {
    current.perStageDescriptorSet = current.perStageDescriptorSet || merge_in.perStageDescriptorSet;
    current.dynamicPipelineLayout = current.dynamicPipelineLayout || merge_in.dynamicPipelineLayout;
}
void compare_VkPhysicalDeviceImageProcessing2FeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceImageProcessing2FeaturesQCOM const& supported, VkPhysicalDeviceImageProcessing2FeaturesQCOM const& requested) {
    if (requested.textureBlockMatch2 && !supported.textureBlockMatch2) {
        error_list.push_back("VkPhysicalDeviceImageProcessing2FeaturesQCOM::textureBlockMatch2");
    }
}
void merge_VkPhysicalDeviceImageProcessing2FeaturesQCOM(VkPhysicalDeviceImageProcessing2FeaturesQCOM & current, VkPhysicalDeviceImageProcessing2FeaturesQCOM const& merge_in) {
    current.textureBlockMatch2 = current.textureBlockMatch2 || merge_in.textureBlockMatch2;
}
void compare_VkPhysicalDeviceCubicWeightsFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceCubicWeightsFeaturesQCOM const& supported, VkPhysicalDeviceCubicWeightsFeaturesQCOM const& requested) {
    if (requested.selectableCubicWeights && !supported.selectableCubicWeights) {
        error_list.push_back("VkPhysicalDeviceCubicWeightsFeaturesQCOM::selectableCubicWeights");
    }
}
void merge_VkPhysicalDeviceCubicWeightsFeaturesQCOM(VkPhysicalDeviceCubicWeightsFeaturesQCOM & current, VkPhysicalDeviceCubicWeightsFeaturesQCOM const& merge_in) {
    current.selectableCubicWeights = current.selectableCubicWeights || merge_in.selectableCubicWeights;
}
void compare_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM const& supported, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM const& requested) {
    if (requested.ycbcrDegamma && !supported.ycbcrDegamma) {
        error_list.push_back("VkPhysicalDeviceYcbcrDegammaFeaturesQCOM::ycbcrDegamma");
    }
}
void merge_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM & current, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM const& merge_in) {
    current.ycbcrDegamma = current.ycbcrDegamma || merge_in.ycbcrDegamma;
}
void compare_VkPhysicalDeviceCubicClampFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceCubicClampFeaturesQCOM const& supported, VkPhysicalDeviceCubicClampFeaturesQCOM const& requested) {
    if (requested.cubicRangeClamp && !supported.cubicRangeClamp) {
        error_list.push_back("VkPhysicalDeviceCubicClampFeaturesQCOM::cubicRangeClamp");
    }
}
void merge_VkPhysicalDeviceCubicClampFeaturesQCOM(VkPhysicalDeviceCubicClampFeaturesQCOM & current, VkPhysicalDeviceCubicClampFeaturesQCOM const& merge_in) {
    current.cubicRangeClamp = current.cubicRangeClamp || merge_in.cubicRangeClamp;
}
void compare_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT const& supported, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT const& requested) {
    if (requested.attachmentFeedbackLoopDynamicState && !supported.attachmentFeedbackLoopDynamicState) {
        error_list.push_back("VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT::attachmentFeedbackLoopDynamicState");
    }
}
void merge_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT & current, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT const& merge_in) {
    current.attachmentFeedbackLoopDynamicState = current.attachmentFeedbackLoopDynamicState || merge_in.attachmentFeedbackLoopDynamicState;
}
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
void compare_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(std::vector<std::string> & error_list, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX const& supported, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX const& requested) {
    if (requested.screenBufferImport && !supported.screenBufferImport) {
        error_list.push_back("VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX::screenBufferImport");
    }
}
void merge_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX & current, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX const& merge_in) {
    current.screenBufferImport = current.screenBufferImport || merge_in.screenBufferImport;
}
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
void compare_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV const& supported, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV const& requested) {
    if (requested.descriptorPoolOverallocation && !supported.descriptorPoolOverallocation) {
        error_list.push_back("VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV::descriptorPoolOverallocation");
    }
}
void merge_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV & current, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV const& merge_in) {
    current.descriptorPoolOverallocation = current.descriptorPoolOverallocation || merge_in.descriptorPoolOverallocation;
}
void compare_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(std::vector<std::string> & error_list, VkPhysicalDeviceTileMemoryHeapFeaturesQCOM const& supported, VkPhysicalDeviceTileMemoryHeapFeaturesQCOM const& requested) {
    if (requested.tileMemoryHeap && !supported.tileMemoryHeap) {
        error_list.push_back("VkPhysicalDeviceTileMemoryHeapFeaturesQCOM::tileMemoryHeap");
    }
}
void merge_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM & current, VkPhysicalDeviceTileMemoryHeapFeaturesQCOM const& merge_in) {
    current.tileMemoryHeap = current.tileMemoryHeap || merge_in.tileMemoryHeap;
}
void compare_VkPhysicalDeviceRawAccessChainsFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRawAccessChainsFeaturesNV const& supported, VkPhysicalDeviceRawAccessChainsFeaturesNV const& requested) {
    if (requested.shaderRawAccessChains && !supported.shaderRawAccessChains) {
        error_list.push_back("VkPhysicalDeviceRawAccessChainsFeaturesNV::shaderRawAccessChains");
    }
}
void merge_VkPhysicalDeviceRawAccessChainsFeaturesNV(VkPhysicalDeviceRawAccessChainsFeaturesNV & current, VkPhysicalDeviceRawAccessChainsFeaturesNV const& merge_in) {
    current.shaderRawAccessChains = current.shaderRawAccessChains || merge_in.shaderRawAccessChains;
}
void compare_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV const& supported, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV const& requested) {
    if (requested.commandBufferInheritance && !supported.commandBufferInheritance) {
        error_list.push_back("VkPhysicalDeviceCommandBufferInheritanceFeaturesNV::commandBufferInheritance");
    }
}
void merge_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV & current, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV const& merge_in) {
    current.commandBufferInheritance = current.commandBufferInheritance || merge_in.commandBufferInheritance;
}
void compare_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV const& supported, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV const& requested) {
    if (requested.shaderFloat16VectorAtomics && !supported.shaderFloat16VectorAtomics) {
        error_list.push_back("VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV::shaderFloat16VectorAtomics");
    }
}
void merge_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV & current, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV const& merge_in) {
    current.shaderFloat16VectorAtomics = current.shaderFloat16VectorAtomics || merge_in.shaderFloat16VectorAtomics;
}
void compare_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT const& supported, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT const& requested) {
    if (requested.shaderReplicatedComposites && !supported.shaderReplicatedComposites) {
        error_list.push_back("VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT::shaderReplicatedComposites");
    }
}
void merge_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT & current, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT const& merge_in) {
    current.shaderReplicatedComposites = current.shaderReplicatedComposites || merge_in.shaderReplicatedComposites;
}
void compare_VkPhysicalDeviceShaderFloat8FeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceShaderFloat8FeaturesEXT const& supported, VkPhysicalDeviceShaderFloat8FeaturesEXT const& requested) {
    if (requested.shaderFloat8 && !supported.shaderFloat8) {
        error_list.push_back("VkPhysicalDeviceShaderFloat8FeaturesEXT::shaderFloat8");
    }
    if (requested.shaderFloat8CooperativeMatrix && !supported.shaderFloat8CooperativeMatrix) {
        error_list.push_back("VkPhysicalDeviceShaderFloat8FeaturesEXT::shaderFloat8CooperativeMatrix");
    }
}
void merge_VkPhysicalDeviceShaderFloat8FeaturesEXT(VkPhysicalDeviceShaderFloat8FeaturesEXT & current, VkPhysicalDeviceShaderFloat8FeaturesEXT const& merge_in) {
    current.shaderFloat8 = current.shaderFloat8 || merge_in.shaderFloat8;
    current.shaderFloat8CooperativeMatrix = current.shaderFloat8CooperativeMatrix || merge_in.shaderFloat8CooperativeMatrix;
}
void compare_VkPhysicalDeviceRayTracingValidationFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingValidationFeaturesNV const& supported, VkPhysicalDeviceRayTracingValidationFeaturesNV const& requested) {
    if (requested.rayTracingValidation && !supported.rayTracingValidation) {
        error_list.push_back("VkPhysicalDeviceRayTracingValidationFeaturesNV::rayTracingValidation");
    }
}
void merge_VkPhysicalDeviceRayTracingValidationFeaturesNV(VkPhysicalDeviceRayTracingValidationFeaturesNV & current, VkPhysicalDeviceRayTracingValidationFeaturesNV const& merge_in) {
    current.rayTracingValidation = current.rayTracingValidation || merge_in.rayTracingValidation;
}
void compare_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV const& supported, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV const& requested) {
    if (requested.clusterAccelerationStructure && !supported.clusterAccelerationStructure) {
        error_list.push_back("VkPhysicalDeviceClusterAccelerationStructureFeaturesNV::clusterAccelerationStructure");
    }
}
void merge_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV & current, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV const& merge_in) {
    current.clusterAccelerationStructure = current.clusterAccelerationStructure || merge_in.clusterAccelerationStructure;
}
void compare_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV const& supported, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV const& requested) {
    if (requested.partitionedAccelerationStructure && !supported.partitionedAccelerationStructure) {
        error_list.push_back("VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV::partitionedAccelerationStructure");
    }
}
void merge_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV & current, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV const& merge_in) {
    current.partitionedAccelerationStructure = current.partitionedAccelerationStructure || merge_in.partitionedAccelerationStructure;
}
void compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT const& supported, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT const& requested) {
    if (requested.deviceGeneratedCommands && !supported.deviceGeneratedCommands) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT::deviceGeneratedCommands");
    }
    if (requested.dynamicGeneratedPipelineLayout && !supported.dynamicGeneratedPipelineLayout) {
        error_list.push_back("VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT::dynamicGeneratedPipelineLayout");
    }
}
void merge_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT & current, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT const& merge_in) {
    current.deviceGeneratedCommands = current.deviceGeneratedCommands || merge_in.deviceGeneratedCommands;
    current.dynamicGeneratedPipelineLayout = current.dynamicGeneratedPipelineLayout || merge_in.dynamicGeneratedPipelineLayout;
}
void compare_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(std::vector<std::string> & error_list, VkPhysicalDeviceImageAlignmentControlFeaturesMESA const& supported, VkPhysicalDeviceImageAlignmentControlFeaturesMESA const& requested) {
    if (requested.imageAlignmentControl && !supported.imageAlignmentControl) {
        error_list.push_back("VkPhysicalDeviceImageAlignmentControlFeaturesMESA::imageAlignmentControl");
    }
}
void merge_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(VkPhysicalDeviceImageAlignmentControlFeaturesMESA & current, VkPhysicalDeviceImageAlignmentControlFeaturesMESA const& merge_in) {
    current.imageAlignmentControl = current.imageAlignmentControl || merge_in.imageAlignmentControl;
}
void compare_VkPhysicalDeviceDepthClampControlFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceDepthClampControlFeaturesEXT const& supported, VkPhysicalDeviceDepthClampControlFeaturesEXT const& requested) {
    if (requested.depthClampControl && !supported.depthClampControl) {
        error_list.push_back("VkPhysicalDeviceDepthClampControlFeaturesEXT::depthClampControl");
    }
}
void merge_VkPhysicalDeviceDepthClampControlFeaturesEXT(VkPhysicalDeviceDepthClampControlFeaturesEXT & current, VkPhysicalDeviceDepthClampControlFeaturesEXT const& merge_in) {
    current.depthClampControl = current.depthClampControl || merge_in.depthClampControl;
}
void compare_VkPhysicalDeviceHdrVividFeaturesHUAWEI(std::vector<std::string> & error_list, VkPhysicalDeviceHdrVividFeaturesHUAWEI const& supported, VkPhysicalDeviceHdrVividFeaturesHUAWEI const& requested) {
    if (requested.hdrVivid && !supported.hdrVivid) {
        error_list.push_back("VkPhysicalDeviceHdrVividFeaturesHUAWEI::hdrVivid");
    }
}
void merge_VkPhysicalDeviceHdrVividFeaturesHUAWEI(VkPhysicalDeviceHdrVividFeaturesHUAWEI & current, VkPhysicalDeviceHdrVividFeaturesHUAWEI const& merge_in) {
    current.hdrVivid = current.hdrVivid || merge_in.hdrVivid;
}
void compare_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(std::vector<std::string> & error_list, VkPhysicalDeviceCooperativeMatrix2FeaturesNV const& supported, VkPhysicalDeviceCooperativeMatrix2FeaturesNV const& requested) {
    if (requested.cooperativeMatrixWorkgroupScope && !supported.cooperativeMatrixWorkgroupScope) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixWorkgroupScope");
    }
    if (requested.cooperativeMatrixFlexibleDimensions && !supported.cooperativeMatrixFlexibleDimensions) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixFlexibleDimensions");
    }
    if (requested.cooperativeMatrixReductions && !supported.cooperativeMatrixReductions) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixReductions");
    }
    if (requested.cooperativeMatrixConversions && !supported.cooperativeMatrixConversions) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixConversions");
    }
    if (requested.cooperativeMatrixPerElementOperations && !supported.cooperativeMatrixPerElementOperations) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixPerElementOperations");
    }
    if (requested.cooperativeMatrixTensorAddressing && !supported.cooperativeMatrixTensorAddressing) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixTensorAddressing");
    }
    if (requested.cooperativeMatrixBlockLoads && !supported.cooperativeMatrixBlockLoads) {
        error_list.push_back("VkPhysicalDeviceCooperativeMatrix2FeaturesNV::cooperativeMatrixBlockLoads");
    }
}
void merge_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(VkPhysicalDeviceCooperativeMatrix2FeaturesNV & current, VkPhysicalDeviceCooperativeMatrix2FeaturesNV const& merge_in) {
    current.cooperativeMatrixWorkgroupScope = current.cooperativeMatrixWorkgroupScope || merge_in.cooperativeMatrixWorkgroupScope;
    current.cooperativeMatrixFlexibleDimensions = current.cooperativeMatrixFlexibleDimensions || merge_in.cooperativeMatrixFlexibleDimensions;
    current.cooperativeMatrixReductions = current.cooperativeMatrixReductions || merge_in.cooperativeMatrixReductions;
    current.cooperativeMatrixConversions = current.cooperativeMatrixConversions || merge_in.cooperativeMatrixConversions;
    current.cooperativeMatrixPerElementOperations = current.cooperativeMatrixPerElementOperations || merge_in.cooperativeMatrixPerElementOperations;
    current.cooperativeMatrixTensorAddressing = current.cooperativeMatrixTensorAddressing || merge_in.cooperativeMatrixTensorAddressing;
    current.cooperativeMatrixBlockLoads = current.cooperativeMatrixBlockLoads || merge_in.cooperativeMatrixBlockLoads;
}
void compare_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM const& supported, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM const& requested) {
    if (requested.pipelineOpacityMicromap && !supported.pipelineOpacityMicromap) {
        error_list.push_back("VkPhysicalDevicePipelineOpacityMicromapFeaturesARM::pipelineOpacityMicromap");
    }
}
void merge_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM & current, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM const& merge_in) {
    current.pipelineOpacityMicromap = current.pipelineOpacityMicromap || merge_in.pipelineOpacityMicromap;
}
void compare_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT const& supported, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT const& requested) {
    if (requested.vertexAttributeRobustness && !supported.vertexAttributeRobustness) {
        error_list.push_back("VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT::vertexAttributeRobustness");
    }
}
void merge_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT & current, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT const& merge_in) {
    current.vertexAttributeRobustness = current.vertexAttributeRobustness || merge_in.vertexAttributeRobustness;
}
void compare_VkPhysicalDeviceFormatPackFeaturesARM(std::vector<std::string> & error_list, VkPhysicalDeviceFormatPackFeaturesARM const& supported, VkPhysicalDeviceFormatPackFeaturesARM const& requested) {
    if (requested.formatPack && !supported.formatPack) {
        error_list.push_back("VkPhysicalDeviceFormatPackFeaturesARM::formatPack");
    }
}
void merge_VkPhysicalDeviceFormatPackFeaturesARM(VkPhysicalDeviceFormatPackFeaturesARM & current, VkPhysicalDeviceFormatPackFeaturesARM const& merge_in) {
    current.formatPack = current.formatPack || merge_in.formatPack;
}
void compare_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(std::vector<std::string> & error_list, VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE const& supported, VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE const& requested) {
    if (requested.fragmentDensityMapLayered && !supported.fragmentDensityMapLayered) {
        error_list.push_back("VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE::fragmentDensityMapLayered");
    }
}
void merge_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE & current, VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE const& merge_in) {
    current.fragmentDensityMapLayered = current.fragmentDensityMapLayered || merge_in.fragmentDensityMapLayered;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDevicePresentMeteringFeaturesNV(std::vector<std::string> & error_list, VkPhysicalDevicePresentMeteringFeaturesNV const& supported, VkPhysicalDevicePresentMeteringFeaturesNV const& requested) {
    if (requested.presentMetering && !supported.presentMetering) {
        error_list.push_back("VkPhysicalDevicePresentMeteringFeaturesNV::presentMetering");
    }
}
void merge_VkPhysicalDevicePresentMeteringFeaturesNV(VkPhysicalDevicePresentMeteringFeaturesNV & current, VkPhysicalDevicePresentMeteringFeaturesNV const& merge_in) {
    current.presentMetering = current.presentMetering || merge_in.presentMetering;
}
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
void compare_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT const& supported, VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT const& requested) {
    if (requested.zeroInitializeDeviceMemory && !supported.zeroInitializeDeviceMemory) {
        error_list.push_back("VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT::zeroInitializeDeviceMemory");
    }
}
void merge_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT & current, VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT const& merge_in) {
    current.zeroInitializeDeviceMemory = current.zeroInitializeDeviceMemory || merge_in.zeroInitializeDeviceMemory;
}
void compare_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(std::vector<std::string> & error_list, VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC const& supported, VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC const& requested) {
    if (requested.pipelineCacheIncrementalMode && !supported.pipelineCacheIncrementalMode) {
        error_list.push_back("VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC::pipelineCacheIncrementalMode");
    }
}
void merge_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC & current, VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC const& merge_in) {
    current.pipelineCacheIncrementalMode = current.pipelineCacheIncrementalMode || merge_in.pipelineCacheIncrementalMode;
}
void compare_VkPhysicalDeviceAccelerationStructureFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceAccelerationStructureFeaturesKHR const& supported, VkPhysicalDeviceAccelerationStructureFeaturesKHR const& requested) {
    if (requested.accelerationStructure && !supported.accelerationStructure) {
        error_list.push_back("VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructure");
    }
    if (requested.accelerationStructureCaptureReplay && !supported.accelerationStructureCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructureCaptureReplay");
    }
    if (requested.accelerationStructureIndirectBuild && !supported.accelerationStructureIndirectBuild) {
        error_list.push_back("VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructureIndirectBuild");
    }
    if (requested.accelerationStructureHostCommands && !supported.accelerationStructureHostCommands) {
        error_list.push_back("VkPhysicalDeviceAccelerationStructureFeaturesKHR::accelerationStructureHostCommands");
    }
    if (requested.descriptorBindingAccelerationStructureUpdateAfterBind && !supported.descriptorBindingAccelerationStructureUpdateAfterBind) {
        error_list.push_back("VkPhysicalDeviceAccelerationStructureFeaturesKHR::descriptorBindingAccelerationStructureUpdateAfterBind");
    }
}
void merge_VkPhysicalDeviceAccelerationStructureFeaturesKHR(VkPhysicalDeviceAccelerationStructureFeaturesKHR & current, VkPhysicalDeviceAccelerationStructureFeaturesKHR const& merge_in) {
    current.accelerationStructure = current.accelerationStructure || merge_in.accelerationStructure;
    current.accelerationStructureCaptureReplay = current.accelerationStructureCaptureReplay || merge_in.accelerationStructureCaptureReplay;
    current.accelerationStructureIndirectBuild = current.accelerationStructureIndirectBuild || merge_in.accelerationStructureIndirectBuild;
    current.accelerationStructureHostCommands = current.accelerationStructureHostCommands || merge_in.accelerationStructureHostCommands;
    current.descriptorBindingAccelerationStructureUpdateAfterBind = current.descriptorBindingAccelerationStructureUpdateAfterBind || merge_in.descriptorBindingAccelerationStructureUpdateAfterBind;
}
void compare_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceRayTracingPipelineFeaturesKHR const& supported, VkPhysicalDeviceRayTracingPipelineFeaturesKHR const& requested) {
    if (requested.rayTracingPipeline && !supported.rayTracingPipeline) {
        error_list.push_back("VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipeline");
    }
    if (requested.rayTracingPipelineShaderGroupHandleCaptureReplay && !supported.rayTracingPipelineShaderGroupHandleCaptureReplay) {
        error_list.push_back("VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipelineShaderGroupHandleCaptureReplay");
    }
    if (requested.rayTracingPipelineShaderGroupHandleCaptureReplayMixed && !supported.rayTracingPipelineShaderGroupHandleCaptureReplayMixed) {
        error_list.push_back("VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipelineShaderGroupHandleCaptureReplayMixed");
    }
    if (requested.rayTracingPipelineTraceRaysIndirect && !supported.rayTracingPipelineTraceRaysIndirect) {
        error_list.push_back("VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTracingPipelineTraceRaysIndirect");
    }
    if (requested.rayTraversalPrimitiveCulling && !supported.rayTraversalPrimitiveCulling) {
        error_list.push_back("VkPhysicalDeviceRayTracingPipelineFeaturesKHR::rayTraversalPrimitiveCulling");
    }
}
void merge_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(VkPhysicalDeviceRayTracingPipelineFeaturesKHR & current, VkPhysicalDeviceRayTracingPipelineFeaturesKHR const& merge_in) {
    current.rayTracingPipeline = current.rayTracingPipeline || merge_in.rayTracingPipeline;
    current.rayTracingPipelineShaderGroupHandleCaptureReplay = current.rayTracingPipelineShaderGroupHandleCaptureReplay || merge_in.rayTracingPipelineShaderGroupHandleCaptureReplay;
    current.rayTracingPipelineShaderGroupHandleCaptureReplayMixed = current.rayTracingPipelineShaderGroupHandleCaptureReplayMixed || merge_in.rayTracingPipelineShaderGroupHandleCaptureReplayMixed;
    current.rayTracingPipelineTraceRaysIndirect = current.rayTracingPipelineTraceRaysIndirect || merge_in.rayTracingPipelineTraceRaysIndirect;
    current.rayTraversalPrimitiveCulling = current.rayTraversalPrimitiveCulling || merge_in.rayTraversalPrimitiveCulling;
}
void compare_VkPhysicalDeviceRayQueryFeaturesKHR(std::vector<std::string> & error_list, VkPhysicalDeviceRayQueryFeaturesKHR const& supported, VkPhysicalDeviceRayQueryFeaturesKHR const& requested) {
    if (requested.rayQuery && !supported.rayQuery) {
        error_list.push_back("VkPhysicalDeviceRayQueryFeaturesKHR::rayQuery");
    }
}
void merge_VkPhysicalDeviceRayQueryFeaturesKHR(VkPhysicalDeviceRayQueryFeaturesKHR & current, VkPhysicalDeviceRayQueryFeaturesKHR const& merge_in) {
    current.rayQuery = current.rayQuery || merge_in.rayQuery;
}
void compare_VkPhysicalDeviceMeshShaderFeaturesEXT(std::vector<std::string> & error_list, VkPhysicalDeviceMeshShaderFeaturesEXT const& supported, VkPhysicalDeviceMeshShaderFeaturesEXT const& requested) {
    if (requested.taskShader && !supported.taskShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesEXT::taskShader");
    }
    if (requested.meshShader && !supported.meshShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesEXT::meshShader");
    }
    if (requested.multiviewMeshShader && !supported.multiviewMeshShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesEXT::multiviewMeshShader");
    }
    if (requested.primitiveFragmentShadingRateMeshShader && !supported.primitiveFragmentShadingRateMeshShader) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesEXT::primitiveFragmentShadingRateMeshShader");
    }
    if (requested.meshShaderQueries && !supported.meshShaderQueries) {
        error_list.push_back("VkPhysicalDeviceMeshShaderFeaturesEXT::meshShaderQueries");
    }
}
void merge_VkPhysicalDeviceMeshShaderFeaturesEXT(VkPhysicalDeviceMeshShaderFeaturesEXT & current, VkPhysicalDeviceMeshShaderFeaturesEXT const& merge_in) {
    current.taskShader = current.taskShader || merge_in.taskShader;
    current.meshShader = current.meshShader || merge_in.meshShader;
    current.multiviewMeshShader = current.multiviewMeshShader || merge_in.multiviewMeshShader;
    current.primitiveFragmentShadingRateMeshShader = current.primitiveFragmentShadingRateMeshShader || merge_in.primitiveFragmentShadingRateMeshShader;
    current.meshShaderQueries = current.meshShaderQueries || merge_in.meshShaderQueries;
}
void compare_feature_struct(VkStructureType sType, std::vector<std::string> & error_list, const void* supported, const void* requested) {
    switch (sType) {
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES):
            compare_VkPhysicalDevice16BitStorageFeatures(error_list, *reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES):
            compare_VkPhysicalDeviceMultiviewFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES):
            compare_VkPhysicalDeviceVariablePointersFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES):
            compare_VkPhysicalDeviceProtectedMemoryFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES):
            compare_VkPhysicalDeviceSamplerYcbcrConversionFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES):
            compare_VkPhysicalDeviceShaderDrawParametersFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES):
            compare_VkPhysicalDeviceVulkan11Features(error_list, *reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES):
            compare_VkPhysicalDeviceVulkan12Features(error_list, *reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES):
            compare_VkPhysicalDevice8BitStorageFeatures(error_list, *reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES):
            compare_VkPhysicalDeviceShaderAtomicInt64Features(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES):
            compare_VkPhysicalDeviceShaderFloat16Int8Features(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES):
            compare_VkPhysicalDeviceDescriptorIndexingFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES):
            compare_VkPhysicalDeviceScalarBlockLayoutFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES):
            compare_VkPhysicalDeviceVulkanMemoryModelFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES):
            compare_VkPhysicalDeviceImagelessFramebufferFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES):
            compare_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES):
            compare_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES):
            compare_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES):
            compare_VkPhysicalDeviceHostQueryResetFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES):
            compare_VkPhysicalDeviceTimelineSemaphoreFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES):
            compare_VkPhysicalDeviceBufferDeviceAddressFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES):
            compare_VkPhysicalDeviceVulkan13Features(error_list, *reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES):
            compare_VkPhysicalDeviceShaderTerminateInvocationFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES):
            compare_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES):
            compare_VkPhysicalDevicePrivateDataFeatures(error_list, *reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES):
            compare_VkPhysicalDevicePipelineCreationCacheControlFeatures(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES):
            compare_VkPhysicalDeviceSynchronization2Features(error_list, *reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES):
            compare_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES):
            compare_VkPhysicalDeviceImageRobustnessFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES):
            compare_VkPhysicalDeviceSubgroupSizeControlFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES):
            compare_VkPhysicalDeviceInlineUniformBlockFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES):
            compare_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES):
            compare_VkPhysicalDeviceDynamicRenderingFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES):
            compare_VkPhysicalDeviceShaderIntegerDotProductFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES):
            compare_VkPhysicalDeviceMaintenance4Features(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES):
            compare_VkPhysicalDeviceVulkan14Features(error_list, *reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES):
            compare_VkPhysicalDeviceGlobalPriorityQueryFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES):
            compare_VkPhysicalDeviceShaderSubgroupRotateFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES):
            compare_VkPhysicalDeviceShaderFloatControls2Features(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES):
            compare_VkPhysicalDeviceShaderExpectAssumeFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES):
            compare_VkPhysicalDeviceLineRasterizationFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES):
            compare_VkPhysicalDeviceVertexAttributeDivisorFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES):
            compare_VkPhysicalDeviceIndexTypeUint8Features(error_list, *reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES):
            compare_VkPhysicalDeviceMaintenance5Features(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES):
            compare_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES):
            compare_VkPhysicalDeviceMaintenance6Features(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES):
            compare_VkPhysicalDevicePipelineProtectedAccessFeatures(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES):
            compare_VkPhysicalDevicePipelineRobustnessFeatures(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES):
            compare_VkPhysicalDeviceHostImageCopyFeatures(error_list, *reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(supported), *reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR):
            compare_VkPhysicalDevicePerformanceQueryFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderBfloat16FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR):
            compare_VkPhysicalDevicePortabilitySubsetFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderClockFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR):
            compare_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderQuadControlFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR):
            compare_VkPhysicalDevicePresentWaitFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR):
            compare_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR):
            compare_VkPhysicalDevicePresentIdFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR):
            compare_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR):
            compare_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR):
            compare_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR):
            compare_VkPhysicalDevicePresentId2FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR):
            compare_VkPhysicalDevicePresentWait2FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR):
            compare_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR):
            compare_VkPhysicalDevicePipelineBinaryFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR):
            compare_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR):
            compare_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR):
            compare_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR):
            compare_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR):
            compare_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR):
            compare_VkPhysicalDeviceMaintenance7FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR):
            compare_VkPhysicalDeviceMaintenance8FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR):
            compare_VkPhysicalDeviceMaintenance9FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR):
            compare_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance2FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance2FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR):
            compare_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR):
            compare_VkPhysicalDeviceRobustness2FeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR):
            compare_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT):
            compare_VkPhysicalDeviceTransformFeedbackFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV):
            compare_VkPhysicalDeviceCornerSampledImageFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT):
            compare_VkPhysicalDeviceASTCDecodeFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT):
            compare_VkPhysicalDeviceConditionalRenderingFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT):
            compare_VkPhysicalDeviceDepthClipEnableFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG):
            compare_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(error_list, *reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(supported), *reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX):
            compare_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderEnqueueFeaturesAMDX*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderEnqueueFeaturesAMDX*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT):
            compare_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV):
            compare_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV):
            compare_VkPhysicalDeviceShadingRateImageFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV):
            compare_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV):
            compare_VkPhysicalDeviceMeshShaderFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV):
            compare_VkPhysicalDeviceShaderImageFootprintFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV):
            compare_VkPhysicalDeviceExclusiveScissorFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL):
            compare_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT):
            compare_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD):
            compare_VkPhysicalDeviceCoherentMemoryFeaturesAMD(error_list, *reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(supported), *reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT):
            compare_VkPhysicalDeviceMemoryPriorityFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV):
            compare_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT):
            compare_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV):
            compare_VkPhysicalDeviceCooperativeMatrixFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV):
            compare_VkPhysicalDeviceCoverageReductionModeFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT):
            compare_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT):
            compare_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT):
            compare_VkPhysicalDeviceProvokingVertexFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT):
            compare_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT):
            compare_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV):
            compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV):
            compare_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT):
            compare_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT):
            compare_VkPhysicalDeviceDepthBiasControlFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT):
            compare_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT):
            compare_VkPhysicalDeviceCustomBorderColorFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV):
            compare_VkPhysicalDevicePresentBarrierFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV):
            compare_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV):
            compare_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCudaKernelLaunchFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCudaKernelLaunchFeaturesNV*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM):
            compare_VkPhysicalDeviceTileShadingFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT):
            compare_VkPhysicalDeviceDescriptorBufferFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT):
            compare_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD):
            compare_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV):
            compare_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV):
            compare_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT):
            compare_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT):
            compare_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT):
            compare_VkPhysicalDeviceImageCompressionControlFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT):
            compare_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT):
            compare_VkPhysicalDevice4444FormatsFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT):
            compare_VkPhysicalDeviceFaultFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT):
            compare_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT):
            compare_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT):
            compare_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT):
            compare_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT):
            compare_VkPhysicalDeviceAddressBindingReportFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT):
            compare_VkPhysicalDeviceDepthClipControlFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT):
            compare_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI):
            compare_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(error_list, *reinterpret_cast<const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*>(supported), *reinterpret_cast<const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI):
            compare_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(error_list, *reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(supported), *reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV):
            compare_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT):
            compare_VkPhysicalDevicePipelinePropertiesFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevicePipelinePropertiesFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelinePropertiesFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT):
            compare_VkPhysicalDeviceFrameBoundaryFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT):
            compare_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT):
            compare_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT):
            compare_VkPhysicalDeviceColorWriteEnableFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT):
            compare_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT):
            compare_VkPhysicalDeviceImageViewMinLodFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT):
            compare_VkPhysicalDeviceMultiDrawFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT):
            compare_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderTileImageFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT):
            compare_VkPhysicalDeviceOpacityMicromapFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV):
            compare_VkPhysicalDeviceDisplacementMicromapFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI):
            compare_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(error_list, *reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(supported), *reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT):
            compare_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT):
            compare_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM):
            compare_VkPhysicalDeviceSchedulingControlsFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT):
            compare_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE):
            compare_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(error_list, *reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(supported), *reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT):
            compare_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM):
            compare_VkPhysicalDeviceRenderPassStripedFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT):
            compare_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV):
            compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV):
            compare_VkPhysicalDeviceMemoryDecompressionFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV):
            compare_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV):
            compare_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV):
            compare_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT):
            compare_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM):
            compare_VkPhysicalDeviceImageProcessingFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT):
            compare_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT):
            compare_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT):
            compare_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM):
            compare_VkPhysicalDeviceTensorFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceTensorFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceTensorFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM):
            compare_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV):
            compare_VkPhysicalDeviceOpticalFlowFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT):
            compare_VkPhysicalDeviceLegacyDitheringFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(requested));
            break;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID):
            compare_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(error_list, *reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(supported), *reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(requested));
            break;
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD):
            compare_VkPhysicalDeviceAntiLagFeaturesAMD(error_list, *reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(supported), *reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX):
            compare_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(error_list, *reinterpret_cast<const VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*>(supported), *reinterpret_cast<const VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderObjectFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM):
            compare_VkPhysicalDeviceTilePropertiesFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC):
            compare_VkPhysicalDeviceAmigoProfilingFeaturesSEC(error_list, *reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(supported), *reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM):
            compare_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV):
            compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV):
            compare_VkPhysicalDeviceCooperativeVectorFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV):
            compare_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT):
            compare_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM):
            compare_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT):
            compare_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT):
            compare_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM):
            compare_VkPhysicalDeviceDataGraphFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM):
            compare_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV):
            compare_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM):
            compare_VkPhysicalDeviceImageProcessing2FeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM):
            compare_VkPhysicalDeviceCubicWeightsFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM):
            compare_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM):
            compare_VkPhysicalDeviceCubicClampFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT):
            compare_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(requested));
            break;
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX):
            compare_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(error_list, *reinterpret_cast<const VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*>(supported), *reinterpret_cast<const VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*>(requested));
            break;
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV):
            compare_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM):
            compare_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(error_list, *reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(supported), *reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV):
            compare_VkPhysicalDeviceRawAccessChainsFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV):
            compare_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV):
            compare_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT):
            compare_VkPhysicalDeviceShaderFloat8FeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV):
            compare_VkPhysicalDeviceRayTracingValidationFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV):
            compare_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV):
            compare_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT):
            compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA):
            compare_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(error_list, *reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(supported), *reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT):
            compare_VkPhysicalDeviceDepthClampControlFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI):
            compare_VkPhysicalDeviceHdrVividFeaturesHUAWEI(error_list, *reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(supported), *reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV):
            compare_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM):
            compare_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT):
            compare_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM):
            compare_VkPhysicalDeviceFormatPackFeaturesARM(error_list, *reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(supported), *reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE):
            compare_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(error_list, *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(supported), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(requested));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV):
            compare_VkPhysicalDevicePresentMeteringFeaturesNV(error_list, *reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(supported), *reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(requested));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT):
            compare_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC):
            compare_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(error_list, *reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(supported), *reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR):
            compare_VkPhysicalDeviceAccelerationStructureFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR):
            compare_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR):
            compare_VkPhysicalDeviceRayQueryFeaturesKHR(error_list, *reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(supported), *reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(requested));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT):
            compare_VkPhysicalDeviceMeshShaderFeaturesEXT(error_list, *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(supported), *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(requested));
            break;
        default:
            break;
    }
}
void merge_feature_struct(VkStructureType sType, void* current, const void* merge_in) {
    switch (sType) {
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES):
            merge_VkPhysicalDevice16BitStorageFeatures(*reinterpret_cast<VkPhysicalDevice16BitStorageFeatures*>(current), *reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES):
            merge_VkPhysicalDeviceMultiviewFeatures(*reinterpret_cast<VkPhysicalDeviceMultiviewFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES):
            merge_VkPhysicalDeviceVariablePointersFeatures(*reinterpret_cast<VkPhysicalDeviceVariablePointersFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES):
            merge_VkPhysicalDeviceProtectedMemoryFeatures(*reinterpret_cast<VkPhysicalDeviceProtectedMemoryFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES):
            merge_VkPhysicalDeviceSamplerYcbcrConversionFeatures(*reinterpret_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES):
            merge_VkPhysicalDeviceShaderDrawParametersFeatures(*reinterpret_cast<VkPhysicalDeviceShaderDrawParametersFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES):
            merge_VkPhysicalDeviceVulkan11Features(*reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(current), *reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES):
            merge_VkPhysicalDeviceVulkan12Features(*reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(current), *reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES):
            merge_VkPhysicalDevice8BitStorageFeatures(*reinterpret_cast<VkPhysicalDevice8BitStorageFeatures*>(current), *reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES):
            merge_VkPhysicalDeviceShaderAtomicInt64Features(*reinterpret_cast<VkPhysicalDeviceShaderAtomicInt64Features*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES):
            merge_VkPhysicalDeviceShaderFloat16Int8Features(*reinterpret_cast<VkPhysicalDeviceShaderFloat16Int8Features*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES):
            merge_VkPhysicalDeviceDescriptorIndexingFeatures(*reinterpret_cast<VkPhysicalDeviceDescriptorIndexingFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES):
            merge_VkPhysicalDeviceScalarBlockLayoutFeatures(*reinterpret_cast<VkPhysicalDeviceScalarBlockLayoutFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES):
            merge_VkPhysicalDeviceVulkanMemoryModelFeatures(*reinterpret_cast<VkPhysicalDeviceVulkanMemoryModelFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES):
            merge_VkPhysicalDeviceImagelessFramebufferFeatures(*reinterpret_cast<VkPhysicalDeviceImagelessFramebufferFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES):
            merge_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(*reinterpret_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES):
            merge_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(*reinterpret_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES):
            merge_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(*reinterpret_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES):
            merge_VkPhysicalDeviceHostQueryResetFeatures(*reinterpret_cast<VkPhysicalDeviceHostQueryResetFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES):
            merge_VkPhysicalDeviceTimelineSemaphoreFeatures(*reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES):
            merge_VkPhysicalDeviceBufferDeviceAddressFeatures(*reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES):
            merge_VkPhysicalDeviceVulkan13Features(*reinterpret_cast<VkPhysicalDeviceVulkan13Features*>(current), *reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES):
            merge_VkPhysicalDeviceShaderTerminateInvocationFeatures(*reinterpret_cast<VkPhysicalDeviceShaderTerminateInvocationFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES):
            merge_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(*reinterpret_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES):
            merge_VkPhysicalDevicePrivateDataFeatures(*reinterpret_cast<VkPhysicalDevicePrivateDataFeatures*>(current), *reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES):
            merge_VkPhysicalDevicePipelineCreationCacheControlFeatures(*reinterpret_cast<VkPhysicalDevicePipelineCreationCacheControlFeatures*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES):
            merge_VkPhysicalDeviceSynchronization2Features(*reinterpret_cast<VkPhysicalDeviceSynchronization2Features*>(current), *reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES):
            merge_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(*reinterpret_cast<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES):
            merge_VkPhysicalDeviceImageRobustnessFeatures(*reinterpret_cast<VkPhysicalDeviceImageRobustnessFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES):
            merge_VkPhysicalDeviceSubgroupSizeControlFeatures(*reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES):
            merge_VkPhysicalDeviceInlineUniformBlockFeatures(*reinterpret_cast<VkPhysicalDeviceInlineUniformBlockFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES):
            merge_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(*reinterpret_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES):
            merge_VkPhysicalDeviceDynamicRenderingFeatures(*reinterpret_cast<VkPhysicalDeviceDynamicRenderingFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES):
            merge_VkPhysicalDeviceShaderIntegerDotProductFeatures(*reinterpret_cast<VkPhysicalDeviceShaderIntegerDotProductFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES):
            merge_VkPhysicalDeviceMaintenance4Features(*reinterpret_cast<VkPhysicalDeviceMaintenance4Features*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES):
            merge_VkPhysicalDeviceVulkan14Features(*reinterpret_cast<VkPhysicalDeviceVulkan14Features*>(current), *reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES):
            merge_VkPhysicalDeviceGlobalPriorityQueryFeatures(*reinterpret_cast<VkPhysicalDeviceGlobalPriorityQueryFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES):
            merge_VkPhysicalDeviceShaderSubgroupRotateFeatures(*reinterpret_cast<VkPhysicalDeviceShaderSubgroupRotateFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES):
            merge_VkPhysicalDeviceShaderFloatControls2Features(*reinterpret_cast<VkPhysicalDeviceShaderFloatControls2Features*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES):
            merge_VkPhysicalDeviceShaderExpectAssumeFeatures(*reinterpret_cast<VkPhysicalDeviceShaderExpectAssumeFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES):
            merge_VkPhysicalDeviceLineRasterizationFeatures(*reinterpret_cast<VkPhysicalDeviceLineRasterizationFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES):
            merge_VkPhysicalDeviceVertexAttributeDivisorFeatures(*reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES):
            merge_VkPhysicalDeviceIndexTypeUint8Features(*reinterpret_cast<VkPhysicalDeviceIndexTypeUint8Features*>(current), *reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES):
            merge_VkPhysicalDeviceMaintenance5Features(*reinterpret_cast<VkPhysicalDeviceMaintenance5Features*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES):
            merge_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(*reinterpret_cast<VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES):
            merge_VkPhysicalDeviceMaintenance6Features(*reinterpret_cast<VkPhysicalDeviceMaintenance6Features*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES):
            merge_VkPhysicalDevicePipelineProtectedAccessFeatures(*reinterpret_cast<VkPhysicalDevicePipelineProtectedAccessFeatures*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES):
            merge_VkPhysicalDevicePipelineRobustnessFeatures(*reinterpret_cast<VkPhysicalDevicePipelineRobustnessFeatures*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES):
            merge_VkPhysicalDeviceHostImageCopyFeatures(*reinterpret_cast<VkPhysicalDeviceHostImageCopyFeatures*>(current), *reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR):
            merge_VkPhysicalDevicePerformanceQueryFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderBfloat16FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR):
            merge_VkPhysicalDevicePortabilitySubsetFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderClockFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderClockFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR):
            merge_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderQuadControlFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR):
            merge_VkPhysicalDevicePresentWaitFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePresentWaitFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR):
            merge_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR):
            merge_VkPhysicalDevicePresentIdFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePresentIdFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR):
            merge_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR):
            merge_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR):
            merge_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR):
            merge_VkPhysicalDevicePresentId2FeaturesKHR(*reinterpret_cast<VkPhysicalDevicePresentId2FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR):
            merge_VkPhysicalDevicePresentWait2FeaturesKHR(*reinterpret_cast<VkPhysicalDevicePresentWait2FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR):
            merge_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR):
            merge_VkPhysicalDevicePipelineBinaryFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePipelineBinaryFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR):
            merge_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR):
            merge_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR):
            merge_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR):
            merge_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR):
            merge_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR):
            merge_VkPhysicalDeviceMaintenance7FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceMaintenance7FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR):
            merge_VkPhysicalDeviceMaintenance8FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceMaintenance8FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR):
            merge_VkPhysicalDeviceMaintenance9FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceMaintenance9FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR):
            merge_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceVideoMaintenance2FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceVideoMaintenance2FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR):
            merge_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR):
            merge_VkPhysicalDeviceRobustness2FeaturesKHR(*reinterpret_cast<VkPhysicalDeviceRobustness2FeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR):
            merge_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(*reinterpret_cast<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT):
            merge_VkPhysicalDeviceTransformFeedbackFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV):
            merge_VkPhysicalDeviceCornerSampledImageFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT):
            merge_VkPhysicalDeviceASTCDecodeFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT):
            merge_VkPhysicalDeviceConditionalRenderingFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT):
            merge_VkPhysicalDeviceDepthClipEnableFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG):
            merge_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(*reinterpret_cast<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(current), *reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX):
            merge_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(*reinterpret_cast<VkPhysicalDeviceShaderEnqueueFeaturesAMDX*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderEnqueueFeaturesAMDX*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT):
            merge_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV):
            merge_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(*reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV):
            merge_VkPhysicalDeviceShadingRateImageFeaturesNV(*reinterpret_cast<VkPhysicalDeviceShadingRateImageFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV):
            merge_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV):
            merge_VkPhysicalDeviceMeshShaderFeaturesNV(*reinterpret_cast<VkPhysicalDeviceMeshShaderFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV):
            merge_VkPhysicalDeviceShaderImageFootprintFeaturesNV(*reinterpret_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV):
            merge_VkPhysicalDeviceExclusiveScissorFeaturesNV(*reinterpret_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL):
            merge_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(*reinterpret_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT):
            merge_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD):
            merge_VkPhysicalDeviceCoherentMemoryFeaturesAMD(*reinterpret_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(current), *reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT):
            merge_VkPhysicalDeviceMemoryPriorityFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV):
            merge_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT):
            merge_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV):
            merge_VkPhysicalDeviceCooperativeMatrixFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV):
            merge_VkPhysicalDeviceCoverageReductionModeFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT):
            merge_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT):
            merge_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT):
            merge_VkPhysicalDeviceProvokingVertexFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceProvokingVertexFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT):
            merge_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT):
            merge_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV):
            merge_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV):
            merge_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(*reinterpret_cast<VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT):
            merge_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT):
            merge_VkPhysicalDeviceDepthBiasControlFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT):
            merge_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT):
            merge_VkPhysicalDeviceCustomBorderColorFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV):
            merge_VkPhysicalDevicePresentBarrierFeaturesNV(*reinterpret_cast<VkPhysicalDevicePresentBarrierFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV):
            merge_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV):
            merge_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCudaKernelLaunchFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCudaKernelLaunchFeaturesNV*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM):
            merge_VkPhysicalDeviceTileShadingFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceTileShadingFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT):
            merge_VkPhysicalDeviceDescriptorBufferFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT):
            merge_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD):
            merge_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(*reinterpret_cast<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV):
            merge_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(*reinterpret_cast<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV):
            merge_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT):
            merge_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT):
            merge_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT):
            merge_VkPhysicalDeviceImageCompressionControlFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT):
            merge_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT):
            merge_VkPhysicalDevice4444FormatsFeaturesEXT(*reinterpret_cast<VkPhysicalDevice4444FormatsFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT):
            merge_VkPhysicalDeviceFaultFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFaultFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT):
            merge_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT):
            merge_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT):
            merge_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT):
            merge_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT):
            merge_VkPhysicalDeviceAddressBindingReportFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT):
            merge_VkPhysicalDeviceDepthClipControlFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDepthClipControlFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT):
            merge_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(*reinterpret_cast<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI):
            merge_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(*reinterpret_cast<VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*>(current), *reinterpret_cast<const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI):
            merge_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(*reinterpret_cast<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(current), *reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV):
            merge_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(*reinterpret_cast<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT):
            merge_VkPhysicalDevicePipelinePropertiesFeaturesEXT(*reinterpret_cast<VkPhysicalDevicePipelinePropertiesFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevicePipelinePropertiesFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT):
            merge_VkPhysicalDeviceFrameBoundaryFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT):
            merge_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT):
            merge_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT):
            merge_VkPhysicalDeviceColorWriteEnableFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT):
            merge_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(*reinterpret_cast<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT):
            merge_VkPhysicalDeviceImageViewMinLodFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT):
            merge_VkPhysicalDeviceMultiDrawFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMultiDrawFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT):
            merge_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderTileImageFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderTileImageFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT):
            merge_VkPhysicalDeviceOpacityMicromapFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV):
            merge_VkPhysicalDeviceDisplacementMicromapFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI):
            merge_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(*reinterpret_cast<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(current), *reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT):
            merge_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT):
            merge_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(*reinterpret_cast<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM):
            merge_VkPhysicalDeviceSchedulingControlsFeaturesARM(*reinterpret_cast<VkPhysicalDeviceSchedulingControlsFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT):
            merge_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE):
            merge_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(*reinterpret_cast<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(current), *reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT):
            merge_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM):
            merge_VkPhysicalDeviceRenderPassStripedFeaturesARM(*reinterpret_cast<VkPhysicalDeviceRenderPassStripedFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT):
            merge_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV):
            merge_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV):
            merge_VkPhysicalDeviceMemoryDecompressionFeaturesNV(*reinterpret_cast<VkPhysicalDeviceMemoryDecompressionFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV):
            merge_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV):
            merge_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV):
            merge_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(*reinterpret_cast<VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT):
            merge_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM):
            merge_VkPhysicalDeviceImageProcessingFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceImageProcessingFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT):
            merge_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT):
            merge_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT):
            merge_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM):
            merge_VkPhysicalDeviceTensorFeaturesARM(*reinterpret_cast<VkPhysicalDeviceTensorFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceTensorFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM):
            merge_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(*reinterpret_cast<VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV):
            merge_VkPhysicalDeviceOpticalFlowFeaturesNV(*reinterpret_cast<VkPhysicalDeviceOpticalFlowFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT):
            merge_VkPhysicalDeviceLegacyDitheringFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(merge_in));
            break;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID):
            merge_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(*reinterpret_cast<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(current), *reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(merge_in));
            break;
#endif // defined(VK_USE_PLATFORM_ANDROID_KHR)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD):
            merge_VkPhysicalDeviceAntiLagFeaturesAMD(*reinterpret_cast<VkPhysicalDeviceAntiLagFeaturesAMD*>(current), *reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX):
            merge_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(*reinterpret_cast<VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*>(current), *reinterpret_cast<const VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderObjectFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderObjectFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM):
            merge_VkPhysicalDeviceTilePropertiesFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC):
            merge_VkPhysicalDeviceAmigoProfilingFeaturesSEC(*reinterpret_cast<VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(current), *reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM):
            merge_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV):
            merge_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV):
            merge_VkPhysicalDeviceCooperativeVectorFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCooperativeVectorFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV):
            merge_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(*reinterpret_cast<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT):
            merge_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM):
            merge_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(*reinterpret_cast<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT):
            merge_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(*reinterpret_cast<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT):
            merge_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM):
            merge_VkPhysicalDeviceDataGraphFeaturesARM(*reinterpret_cast<VkPhysicalDeviceDataGraphFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM):
            merge_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV):
            merge_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(*reinterpret_cast<VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM):
            merge_VkPhysicalDeviceImageProcessing2FeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM):
            merge_VkPhysicalDeviceCubicWeightsFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM):
            merge_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM):
            merge_VkPhysicalDeviceCubicClampFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceCubicClampFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT):
            merge_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(merge_in));
            break;
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX):
            merge_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(*reinterpret_cast<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*>(current), *reinterpret_cast<const VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*>(merge_in));
            break;
#endif // defined(VK_USE_PLATFORM_SCREEN_QNX)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV):
            merge_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(*reinterpret_cast<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM):
            merge_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(*reinterpret_cast<VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(current), *reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV):
            merge_VkPhysicalDeviceRawAccessChainsFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRawAccessChainsFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV):
            merge_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(*reinterpret_cast<VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV):
            merge_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(*reinterpret_cast<VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT):
            merge_VkPhysicalDeviceShaderFloat8FeaturesEXT(*reinterpret_cast<VkPhysicalDeviceShaderFloat8FeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV):
            merge_VkPhysicalDeviceRayTracingValidationFeaturesNV(*reinterpret_cast<VkPhysicalDeviceRayTracingValidationFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV):
            merge_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(*reinterpret_cast<VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV):
            merge_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(*reinterpret_cast<VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT):
            merge_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA):
            merge_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(*reinterpret_cast<VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(current), *reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT):
            merge_VkPhysicalDeviceDepthClampControlFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceDepthClampControlFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI):
            merge_VkPhysicalDeviceHdrVividFeaturesHUAWEI(*reinterpret_cast<VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(current), *reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV):
            merge_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(*reinterpret_cast<VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM):
            merge_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(*reinterpret_cast<VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT):
            merge_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM):
            merge_VkPhysicalDeviceFormatPackFeaturesARM(*reinterpret_cast<VkPhysicalDeviceFormatPackFeaturesARM*>(current), *reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE):
            merge_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(*reinterpret_cast<VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(current), *reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(merge_in));
            break;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV):
            merge_VkPhysicalDevicePresentMeteringFeaturesNV(*reinterpret_cast<VkPhysicalDevicePresentMeteringFeaturesNV*>(current), *reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(merge_in));
            break;
#endif // defined(VK_ENABLE_BETA_EXTENSIONS)
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT):
            merge_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC):
            merge_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(*reinterpret_cast<VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(current), *reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR):
            merge_VkPhysicalDeviceAccelerationStructureFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR):
            merge_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR):
            merge_VkPhysicalDeviceRayQueryFeaturesKHR(*reinterpret_cast<VkPhysicalDeviceRayQueryFeaturesKHR*>(current), *reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(merge_in));
            break;
        case(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT):
            merge_VkPhysicalDeviceMeshShaderFeaturesEXT(*reinterpret_cast<VkPhysicalDeviceMeshShaderFeaturesEXT*>(current), *reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(merge_in));
            break;
        default:
            break;
    }
}
} // namespace vkb