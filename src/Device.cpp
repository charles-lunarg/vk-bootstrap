#include "Device.h"

#include <set>

namespace vkbs
{

namespace detail
{
Expected<SurfaceSupportDetails, VkResult> query_surface_support_details (
    VkPhysicalDevice phys_device, VkSurfaceKHR surface)
{
	if (surface == VK_NULL_HANDLE)
		return Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED, "surface handle was null" };

	VkSurfaceCapabilitiesKHR capabilities;
	VkResult res = vkGetPhysicalDeviceSurfaceCapabilitiesKHR (phys_device, surface, &capabilities);
	if (res != VK_SUCCESS)
	{
		// error
		/* possible errors
		VK_ERROR_OUT_OF_HOST_MEMORY
		VK_ERROR_OUT_OF_DEVICE_MEMORY
		VK_ERROR_SURFACE_LOST_KHR
		*/
	}
	auto formats = detail::get_vector<VkSurfaceFormatKHR> (
	    vkGetPhysicalDeviceSurfaceFormatsKHR, phys_device, surface);
	if (!formats.has_value ())
		return detail::Error<VkResult>{ formats.error ().error_code, "Couldn't get surface formats" };
	auto present_modes = detail::get_vector<VkPresentModeKHR> (
	    vkGetPhysicalDeviceSurfacePresentModesKHR, phys_device, surface);
	if (!present_modes.has_value ())
		return detail::Error<VkResult>{ formats.error ().error_code, "Couldn't get surface present modes" };

	return SurfaceSupportDetails{ capabilities, formats.value (), present_modes.value () };
}


// Given a list of formats, return a format supported by the hardware, else return VK_FORMAT_UNDEFINED
VkFormat find_supported_format (
    VkPhysicalDevice physical_device, const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features)
{
	for (VkFormat format : candidates)
	{
		VkFormatProperties props;
		vkGetPhysicalDeviceFormatProperties (physical_device, format, &props);

		if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & features) == features)
		{
			return format;
		}
		else if (tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & features) == features)
		{
			return format;
		}
	}
	return VK_FORMAT_UNDEFINED;
}

bool check_device_extension_support (VkPhysicalDevice device, std::vector<std::string> extensions)
{
	auto available_extensions =
	    detail::get_vector<VkExtensionProperties> (vkEnumerateDeviceExtensionProperties, device, nullptr);
	if (!available_extensions.has_value ()) return false; // maybe handle error

	bool all_available = true;
	for (const auto& extension : available_extensions.value ())
	{
		bool found = false;
		for (auto& req_ext : extensions)
		{
			if (req_ext == extension.extensionName) found = true;
			break;
		}
		if (!found) all_available = false;
	}
	return all_available;
}

detail::QueueFamilies find_queue_families (VkPhysicalDevice phys_device, VkSurfaceKHR surface)
{
	auto queue_families = detail::get_vector_noerror<VkQueueFamilyProperties> (
	    vkGetPhysicalDeviceQueueFamilyProperties, phys_device);

	QueueFamilies families;
	int dedicated_compute = -1;
	int dedicated_transfer = -1;

	for (int i = 0; i < queue_families.size (); i++)
	{
		auto& queueFlags = queue_families[i].queueFlags;
		if (queueFlags & VK_QUEUE_GRAPHICS_BIT) families.graphics = i;
		if (queueFlags & VK_QUEUE_COMPUTE_BIT) families.compute = i;
		if (queueFlags & VK_QUEUE_TRANSFER_BIT) families.transfer = i;
		if (queueFlags & VK_QUEUE_SPARSE_BINDING_BIT) families.sparse = i;

		// compute that isn't graphics
		if (queueFlags & VK_QUEUE_COMPUTE_BIT && ((queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0))
			dedicated_compute = i;

		// transfer that isn't computer or graphics
		if (queueFlags & VK_QUEUE_TRANSFER_BIT && ((queueFlags & VK_QUEUE_COMPUTE_BIT) == 0) &&
		    ((queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0))
			dedicated_transfer = i;

		VkBool32 presentSupport = false;
		if (surface != VK_NULL_HANDLE)
		{
			VkResult res = vkGetPhysicalDeviceSurfaceSupportKHR (phys_device, i, surface, &presentSupport);
		}
		if (presentSupport == true) families.present = i;
	}

	if (dedicated_compute != -1) families.compute = dedicated_compute;
	if (dedicated_transfer != -1) families.transfer = dedicated_transfer;

	// compute and transfer always supported on the graphics family
	if (families.compute != -1 && queue_families[families.graphics].queueFlags & VK_QUEUE_COMPUTE_BIT)
		families.compute = families.graphics;
	if (families.transfer != -1 && queue_families[families.graphics].queueFlags & VK_QUEUE_TRANSFER_BIT)
		families.transfer = families.graphics;

	families.count_graphics = queue_families[families.graphics].queueCount;
	families.count_transfer = queue_families[families.transfer].queueCount;
	families.count_compute = queue_families[families.compute].queueCount;
	if (families.sparse != -1) families.count_sparse = queue_families[families.sparse].queueCount;
	return families;
}

bool supports_features (VkPhysicalDeviceFeatures supported, VkPhysicalDeviceFeatures requested)
{
	// clang-format off
    if (requested.robustBufferAccess && ! supported.robustBufferAccess) return false;
    if (requested.fullDrawIndexUint32 && ! supported.fullDrawIndexUint32) return false;
    if (requested.imageCubeArray && ! supported.imageCubeArray) return false;
    if (requested.independentBlend && ! supported.independentBlend) return false;
    if (requested.geometryShader && ! supported.geometryShader) return false;
    if (requested.tessellationShader && ! supported.tessellationShader) return false;
    if (requested.sampleRateShading && ! supported.sampleRateShading) return false;
    if (requested.dualSrcBlend && ! supported.dualSrcBlend) return false;
    if (requested.logicOp && ! supported.logicOp) return false;
    if (requested.multiDrawIndirect && ! supported.multiDrawIndirect) return false;
    if (requested.drawIndirectFirstInstance && ! supported.drawIndirectFirstInstance) return false;
    if (requested.depthClamp && ! supported.depthClamp) return false;
    if (requested.depthBiasClamp && ! supported.depthBiasClamp) return false;
    if (requested.fillModeNonSolid && ! supported.fillModeNonSolid) return false;
    if (requested.depthBounds && ! supported.depthBounds) return false;
    if (requested.wideLines && ! supported.wideLines) return false;
    if (requested.largePoints && ! supported.largePoints) return false;
    if (requested.alphaToOne && ! supported.alphaToOne) return false;
    if (requested.multiViewport && ! supported.multiViewport) return false;
    if (requested.samplerAnisotropy && ! supported.samplerAnisotropy) return false;
    if (requested.textureCompressionETC2 && ! supported.textureCompressionETC2) return false;
    if (requested.textureCompressionASTC_LDR && ! supported.textureCompressionASTC_LDR) return false;
    if (requested.textureCompressionBC && ! supported.textureCompressionBC) return false;
    if (requested.occlusionQueryPrecise && ! supported.occlusionQueryPrecise) return false;
    if (requested.pipelineStatisticsQuery && ! supported.pipelineStatisticsQuery) return false;
    if (requested.vertexPipelineStoresAndAtomics && !supported.vertexPipelineStoresAndAtomics) return false;
    if (requested.fragmentStoresAndAtomics && !supported.fragmentStoresAndAtomics) return false;
    if (requested.shaderTessellationAndGeometryPointSize && !supported.shaderTessellationAndGeometryPointSize) return false;
    if (requested.shaderImageGatherExtended && !supported.shaderImageGatherExtended) return false;
    if (requested.shaderStorageImageExtendedFormats && !supported.shaderStorageImageExtendedFormats) return false;
    if (requested.shaderStorageImageMultisample && !supported.shaderStorageImageMultisample) return false;
    if (requested.shaderStorageImageReadWithoutFormat && !supported.shaderStorageImageReadWithoutFormat) return false;
    if (requested.shaderStorageImageWriteWithoutFormat && !supported.shaderStorageImageWriteWithoutFormat) return false;
    if (requested.shaderUniformBufferArrayDynamicIndexing && !supported.shaderUniformBufferArrayDynamicIndexing) return false;
    if (requested.shaderSampledImageArrayDynamicIndexing && !supported.shaderSampledImageArrayDynamicIndexing) return false;
    if (requested.shaderStorageBufferArrayDynamicIndexing && !supported.shaderStorageBufferArrayDynamicIndexing) return false;
    if (requested.shaderStorageImageArrayDynamicIndexing && !supported.shaderStorageImageArrayDynamicIndexing) return false;
    if (requested.shaderClipDistance && !supported.shaderClipDistance) return false;
    if (requested.shaderCullDistance && !supported.shaderCullDistance) return false;
    if (requested.shaderFloat64 && !supported.shaderFloat64) return false;
    if (requested.shaderInt64 && !supported.shaderInt64) return false;
    if (requested.shaderInt16 && !supported.shaderInt16) return false;
    if (requested.shaderResourceResidency && !supported.shaderResourceResidency) return false;
    if (requested.shaderResourceMinLod && !supported.shaderResourceMinLod) return false;
    if (requested.sparseBinding && !supported.sparseBinding) return false;
    if (requested.sparseResidencyBuffer && !supported.sparseResidencyBuffer) return false;
    if (requested.sparseResidencyImage2D && !supported.sparseResidencyImage2D) return false;
    if (requested.sparseResidencyImage3D && !supported.sparseResidencyImage3D) return false;
    if (requested.sparseResidency2Samples && !supported.sparseResidency2Samples) return false;
    if (requested.sparseResidency4Samples && !supported.sparseResidency4Samples) return false;
    if (requested.sparseResidency8Samples && !supported.sparseResidency8Samples) return false;
    if (requested.sparseResidency16Samples && !supported.sparseResidency16Samples) return false;
    if (requested.sparseResidencyAliased && !supported.sparseResidencyAliased) return false;
    if (requested.variableMultisampleRate && !supported.variableMultisampleRate) return false;
    if (requested.inheritedQueries && !supported.inheritedQueries) return false;
	// clang-format on
	return true;
}

void populate_physical_device_details (PhysicalDevice phys_device)
{
	vkGetPhysicalDeviceFeatures (phys_device.phys_device, &phys_device.physical_device_features);
	vkGetPhysicalDeviceProperties (phys_device.phys_device, &phys_device.physical_device_properties);
	vkGetPhysicalDeviceMemoryProperties (phys_device.phys_device, &phys_device.memory_properties);
}

} // namespace detail


PhysicalDeviceSelector::Suitable PhysicalDeviceSelector::is_device_suitable (VkPhysicalDevice phys_device)
{
	Suitable suitable = Suitable::yes;

	detail::QueueFamilies indices = detail::find_queue_families (phys_device, info.surface);

	if (criteria.require_dedicated_compute_queue && indices.graphics != indices.compute)
		suitable = Suitable::no;
	if (criteria.require_dedicated_transfer_queue && indices.graphics != indices.transfer)
		suitable = Suitable::no;
	if (criteria.require_present && indices.present == -1) suitable = Suitable::no;

	bool required_extensions_supported =
	    detail::check_device_extension_support (phys_device, criteria.required_extensions);
	if (!required_extensions_supported) suitable = Suitable::no;

	bool desired_extensions_supported =
	    detail::check_device_extension_support (phys_device, criteria.desired_extensions);
	if (!desired_extensions_supported) suitable = Suitable::partial;


	bool swapChainAdequate = false;
	if (!info.headless)
	{
		auto swapChainSupport_ret = detail::query_surface_support_details (phys_device, info.surface);
		if (swapChainSupport_ret.has_value ())
		{
			auto swapchain_support = swapChainSupport_ret.value ();
			swapChainAdequate =
			    !swapchain_support.formats.empty () && !swapchain_support.present_modes.empty ();
		}
	}
	if (criteria.require_present && !swapChainAdequate) suitable = Suitable::no;

	VkPhysicalDeviceMemoryProperties mem_properties;
	vkGetPhysicalDeviceMemoryProperties (phys_device, &mem_properties);

	bool has_required_memory = false;
	bool has_preferred_memory = false;
	for (int i = 0; i < mem_properties.memoryHeapCount; i++)
	{
		if (mem_properties.memoryHeaps[i].flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
		{
			if (mem_properties.memoryHeaps[i].size > criteria.required_mem_size)
			{
				has_required_memory = true;
			}
			if (mem_properties.memoryHeaps[i].size > criteria.desired_mem_size)
			{
				has_preferred_memory = true;
			}
		}
	}
	if (!has_required_memory) suitable = Suitable::no;
	if (!has_preferred_memory) suitable = Suitable::partial;

	VkPhysicalDeviceProperties device_properties;
	vkGetPhysicalDeviceProperties (phys_device, &device_properties);
	if ((criteria.prefer_discrete && device_properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) ||
	    (criteria.prefer_integrated && device_properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU))
	{
		if (criteria.allow_fallback)
			suitable = Suitable::partial;
		else
			suitable = Suitable::no;
	}
	if (criteria.required_version < device_properties.apiVersion) suitable = Suitable::no;
	if (criteria.desired_version < device_properties.apiVersion) suitable = Suitable::partial;

	VkPhysicalDeviceFeatures supported_features{};
	vkGetPhysicalDeviceFeatures (phys_device, &supported_features);
	bool all_features_supported = detail::supports_features (supported_features, criteria.required_features);

	return suitable;
}

detail::Expected<PhysicalDevice, VkResult> PhysicalDeviceSelector::select ()
{
	auto physical_devices = detail::get_vector<VkPhysicalDevice> (vkEnumeratePhysicalDevices, info.instance);
	if (!physical_devices.has_value ())
	{
		return detail::Error<VkResult>{ physical_devices.error ().error_code, "Failed to find physical devices" };
	}

	PhysicalDevice physical_device;
	for (const auto& device : physical_devices.value ())
	{
		auto suitable = is_device_suitable (device);
		if (suitable == Suitable::yes)
		{
			physical_device.phys_device = device;
			break;
		}
		else if (suitable == Suitable::partial)
		{
			physical_device.phys_device = device;
		}
	}

	if (physical_device.phys_device == VK_NULL_HANDLE)
	{
		return detail::Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED, "Failed to find a suitable GPU!" };
	}
	detail::populate_physical_device_details (physical_device);
	physical_device.physical_device_features = criteria.required_features;

	physical_device.queue_family_properties =
	    detail::find_queue_families (physical_device.phys_device, info.surface);
	return physical_device;
}

PhysicalDeviceSelector& PhysicalDeviceSelector::set_instance (Instance instance)
{
	info.instance = instance.instance;
	info.headless = instance.headless;
	criteria.require_present = !instance.headless;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_surface (VkSurfaceKHR surface)
{
	info.surface = surface;
	info.headless = false;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::prefer_discrete (bool prefer_discrete)
{
	criteria.prefer_discrete = prefer_discrete;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::prefer_integrated (bool prefer_integrated)
{
	criteria.prefer_integrated = prefer_integrated;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::allow_fallback (bool fallback)
{
	criteria.allow_fallback = fallback;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_present (bool require)
{
	criteria.require_present = require;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_dedicated_transfer_queue ()
{
	criteria.require_dedicated_transfer_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_dedicated_compute_queue ()
{
	criteria.require_dedicated_compute_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::required_device_memory_size (VkDeviceSize size)
{
	criteria.required_mem_size = size;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::desired_device_memory_size (VkDeviceSize size)
{
	criteria.desired_mem_size = size;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_required_extension (std::string extension)
{
	criteria.required_extensions.push_back (extension);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_desired_extension (std::string extension)
{
	criteria.desired_extensions.push_back (extension);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_minimum_version (uint32_t major, uint32_t minor)
{
	criteria.required_version = VK_MAKE_VERSION (major, minor, 0);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_desired_version (uint32_t major, uint32_t minor)
{
	criteria.desired_version = VK_MAKE_VERSION (major, minor, 0);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_required_features (VkPhysicalDeviceFeatures features)
{
	criteria.required_features = features;
	return *this;
}

// ---- Device ---- //

void destroy_device (Device device) { vkDestroyDevice (device.device, device.allocator); }

struct QueueFamily
{
	int32_t family;
	uint32_t count;
};
detail::Expected<Device, VkResult> DeviceBuilder::build ()
{
	auto& queue_properties = info.physical_device.queue_family_properties;
	std::vector<QueueFamily> families;
	families.push_back ({ queue_properties.graphics, queue_properties.count_graphics });
	if (queue_properties.compute != -1 && queue_properties.compute != queue_properties.graphics)
		families.push_back ({ queue_properties.compute, queue_properties.count_compute });
	if (queue_properties.transfer != -1 && queue_properties.transfer != queue_properties.graphics)
		families.push_back ({ queue_properties.transfer, queue_properties.count_transfer });
	if (queue_properties.sparse != -1)
		families.push_back ({ queue_properties.sparse, queue_properties.count_sparse });

	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	float queuePriority = 1.0f;
	for (auto& queue : families)
	{
		VkDeviceQueueCreateInfo queue_create_info = {};
		queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queue_create_info.queueFamilyIndex = static_cast<uint32_t> (queue.family);
		queue_create_info.queueCount = queue.count;
		queue_create_info.pQueuePriorities = &queuePriority;
		queueCreateInfos.push_back (queue_create_info);
	}

	std::vector<const char*> extensions;
	for (auto& ext : info.extensions)
		extensions.push_back (ext.c_str ());
	if (info.physical_device.surface != VK_NULL_HANDLE)
		extensions.push_back ({ VK_KHR_SWAPCHAIN_EXTENSION_NAME });

	VkDeviceCreateInfo device_create_info = {};
	device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	device_create_info.pNext = info.pNext_chain;
	device_create_info.flags = info.flags;
	device_create_info.queueCreateInfoCount = static_cast<uint32_t> (queueCreateInfos.size ());
	device_create_info.pQueueCreateInfos = queueCreateInfos.data ();
	device_create_info.enabledExtensionCount = static_cast<uint32_t> (extensions.size ());
	device_create_info.ppEnabledExtensionNames = extensions.data ();
	device_create_info.pEnabledFeatures = &info.physical_device.physical_device_features;

	Device device;
	VkResult res =
	    vkCreateDevice (info.physical_device.phys_device, &device_create_info, nullptr, &device.device);
	if (res != VK_SUCCESS)
	{
		return detail::Error<VkResult>{ res, "Couldn't create device" };
	}
	return device;
}

DeviceBuilder& DeviceBuilder::set_physical_device (PhysicalDevice const& phys_device)
{
	info.physical_device = phys_device;
	return *this;
}

template <typename T> DeviceBuilder& DeviceBuilder::add_pNext (T* structure)
{
	if (info.pNext_chain == nullptr)
		info.pNext_chain = (VkBaseOutStructure*)structure;
	else
		detail::pNext_append (info.pNext_chain, structure);
	return *this;
}

// ---- Queue ---- //

namespace detail
{
VkQueue get_queue (Device const& device, uint32_t family, uint32_t index)
{
	VkQueue queue;
	vkGetDeviceQueue (device.device, family, index, &queue);
	return queue;
}
} // namespace detail
detail::Expected<VkQueue, VkResult> get_queue_present (Device const& device)
{
	return detail::get_queue (device, device.physical_device.queue_family_properties.present, 0);
}
detail::Expected<VkQueue, VkResult> get_queue_graphics (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_graphics)
		return detail::Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED,
			"requested graphics queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.graphics, index);
}
detail::Expected<VkQueue, VkResult> get_queue_compute (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_compute)
		return detail::Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED,
			"requested compute queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.compute, index);
}
detail::Expected<VkQueue, VkResult> get_queue_transfer (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_transfer)
		return detail::Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED,
			"requested transfer queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.transfer, index);
}

detail::Expected<VkQueue, VkResult> get_queue_sparse (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_sparse)
		return detail::Error<VkResult>{ VK_ERROR_INITIALIZATION_FAILED,
			"requested sparse queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.sparse, index);
}


} // namespace vkbs