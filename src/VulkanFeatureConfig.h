#pragma once

#include <vulkan/vulkan.h>

/*
The VulkanFeatureConfig mechanism of vk-bootstrap provides an easy way to select a VkPhysicalDevice based off of list of pre-made
configurations that specify the required version, features, extensions, and properties.
*/


namespace vkb {

namespace detail {

struct StructureWrapper {
	template <typename T> StructureWrapper(T const& structure) noexcept {
		T* ptr = new T();
		*ptr = structure;
		pStructure = reinterpret_cast<VkBaseOutStructure*>(ptr);
	}
	~StructureWrapper() noexcept { delete pStructure; }
	StructureWrapper(StructureWrapper const&) = delete;
	StructureWrapper& operator=(StructureWrapper const&) = delete;
	StructureWrapper(StructureWrapper&& other) noexcept : pStructure(other.pStructure) {
		other.pStructure = nullptr;
	}
	StructureWrapper& operator=(StructureWrapper&& other) noexcept {
		delete pStructure;
		pStructure = other.pStructure;
		other.pStructure = nullptr;
		return *this;
	}
	VkBaseOutStructure* pStructure = nullptr;
};

inline VkPhysicalDeviceFeatures get_common_1_0_features() {
	VkPhysicalDeviceFeatures features{};
	features.fullDrawIndexUint32 = true;
	features.imageCubeArray = true;
	features.independentBlend = true;
	features.geometryShader = true;
	features.tessellationShader = true;
	features.sampleRateShading = true;
	features.dualSrcBlend = true;
	features.logicOp = true;
	features.multiDrawIndirect = true;
	features.drawIndirectFirstInstance = true;
	features.depthClamp = true;
	features.depthBiasClamp = true;
	features.fillModeNonSolid = true;
	features.wideLines = true;
	features.largePoints = true;
	features.multiViewport = true;
	features.samplerAnisotropy = true;
	features.pipelineStatisticsQuery = true;
	features.textureCompressionBC = true;
	features.occlusionQueryPrecise = true;
	features.vertexPipelineStoresAndAtomics = true;
	features.fragmentStoresAndAtomics = true;
	features.shaderTessellationAndGeometryPointSize = true;
	features.shaderImageGatherExtended = true;
	features.shaderStorageImageExtendedFormats = true;
	features.shaderStorageImageWriteWithoutFormat = true;
	features.shaderUniformBufferArrayDynamicIndexing = true;
	features.shaderSampledImageArrayDynamicIndexing = true;
	features.shaderStorageBufferArrayDynamicIndexing = true;
	features.shaderStorageImageArrayDynamicIndexing = true;
	features.shaderClipDistance = true;
	features.shaderCullDistance = true;
	features.variableMultisampleRate = true;
	return features;
}

inline VkPhysicalDeviceVulkan11Features get_common_1_1_features() {
	VkPhysicalDeviceVulkan11Features features;
	features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
	features.storageBuffer16BitAccess = true;
	features.uniformAndStorageBuffer16BitAccess = true;
	features.multiview = true;
	features.multiviewTessellationShader = true;
	features.variablePointersStorageBuffer = true;
	features.variablePointers = true;
	features.shaderDrawParameters = true;
	return features;
}

inline VkPhysicalDeviceVulkan12Features get_common_1_2_features() {
	VkPhysicalDeviceVulkan12Features features{};
	features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
	features.samplerMirrorClampToEdge = true;
	features.drawIndirectCount = true;
	features.descriptorIndexing = true;
	features.scalarBlockLayout = true;
	features.imagelessFramebuffer = true;
	features.uniformBufferStandardLayout = true;
	features.shaderSubgroupExtendedTypes = true;
	features.separateDepthStencilLayouts = true;
	features.hostQueryReset = true;
	features.timelineSemaphore = true;
	features.bufferDeviceAddress = true;
	features.subgroupBroadcastDynamicId = true;
	return features;
}
} // namespace detail

/*
Stores all the possible versions, features, extensions, and properties for a VulkanFeatureConfig
*/
struct VulkanFeatureConfig {
	VulkanFeatureConfig() {
		features_1_1.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
		features_1_2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
	}
	uint32_t api_major_version = 1;
	uint32_t api_minor_version = 0;
	bool require_presentation = true;

	std::vector<const char*> required_extensions;

	VkPhysicalDeviceFeatures features_1_0{};
	VkPhysicalDeviceVulkan11Features features_1_1{};
	VkPhysicalDeviceVulkan12Features features_1_2{};

	VkPhysicalDeviceProperties properties_1_0{};
};

/*
Configuration for commonly available features in Vulkan 1.0 devices
*/

static VulkanFeatureConfig& get_feature_config_vulkan_1_0_desktop() {
	static VulkanFeatureConfig config{};
	config.features_1_0 = detail::get_common_1_0_features();
	return config;
}

/*
Configuration for commonly available features in Vulkan 1.1 devices
*/
static VulkanFeatureConfig& get_feature_config_vulkan_1_1_desktop() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 1;
	config.features_1_0 = detail::get_common_1_0_features();
	config.features_1_1 = detail::get_common_1_1_features();
	return config;
}

/*
Configuration for commonly available features in Vulkan 1.2 devices
*/
static VulkanFeatureConfig& get_feature_config_vulkan_1_2_desktop() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 2;
	config.features_1_0 = detail::get_common_1_0_features();
	config.features_1_1 = detail::get_common_1_1_features();
	config.features_1_2 = detail::get_common_1_2_features();
	return config;
}

/*
Configuration that requests features available only found in the most recent hardware
*/
static VulkanFeatureConfig& get_feature_config_bleeding_edge_desktop() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 2;
	config.required_extensions.push_back("VK_KHR_deferred_host_operations");
	config.required_extensions.push_back("VK_KHR_acceleration_structure");
	config.required_extensions.push_back("VK_KHR_ray_query");
	config.required_extensions.push_back("VK_KHR_pipeline_library");
	config.required_extensions.push_back("VK_KHR_ray_tracing_pipeline");
	config.required_extensions.push_back("VK_KHR_fragment_shading_rate");
	config.features_1_0 = detail::get_common_1_0_features();
	config.features_1_1 = detail::get_common_1_1_features();
	config.features_1_2 = detail::get_common_1_2_features();
	return config;
}

static VulkanFeatureConfig& get_feature_config_vulkan_1_0_mobile() {
	static VulkanFeatureConfig config{};
	return config;
}

static VulkanFeatureConfig& get_feature_config_vulkan_1_1_mobile() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 1;
	return config;
}

static VulkanFeatureConfig& get_feature_config_vulkan_1_2_mobile() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 2;
	return config;
}

static VulkanFeatureConfig& get_feature_config_virtual_reality_base() {
	static VulkanFeatureConfig config{};
	config.api_minor_version = 1;
	config.features_1_0 = detail::get_common_1_0_features();
	config.features_1_1 = detail::get_common_1_1_features();


	return config;
}

} // namespace vkb