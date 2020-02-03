#include "VkBootstrap.h"

#include <stdio.h>
#include <string.h>

namespace vkb
{

const char* DebugMessageSeverity (VkDebugUtilsMessageSeverityFlagBitsEXT s)
{
	switch (s)
	{
		case VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
			return "VERBOSE";
		case VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
			return "ERROR";
		case VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
			return "WARNING";
		case VkDebugUtilsMessageSeverityFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
			return "INFO";
		default:
			return "UNKNOWN";
	}
}
const char* DebugMessageType (VkDebugUtilsMessageTypeFlagsEXT s)
{
	switch (s)
	{
		case VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
			return "General";
		case VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
			return "Validation";
		case VkDebugUtilsMessageTypeFlagBitsEXT::VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
			return "Performance";
		default:
			return "Unknown";
	}
}

namespace detail
{

VkResult create_debug_utils_messenger (VkInstance instance,
    PFN_vkDebugUtilsMessengerCallbackEXT debug_callback,
    VkDebugUtilsMessageSeverityFlagsEXT severity,
    VkDebugUtilsMessageTypeFlagsEXT type,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger)
{
	if (debug_callback == nullptr) debug_callback = default_debug_callback;
	VkDebugUtilsMessengerCreateInfoEXT messengerCreateInfo = {};
	messengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	messengerCreateInfo.pNext = nullptr;
	messengerCreateInfo.messageSeverity = severity;
	messengerCreateInfo.messageType = type;
	messengerCreateInfo.pfnUserCallback = debug_callback;


	auto vkCreateDebugUtilsMessengerEXT_func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr (
	    instance, "vkCreateDebugUtilsMessengerEXT");
	if (vkCreateDebugUtilsMessengerEXT_func != nullptr)
	{
		return vkCreateDebugUtilsMessengerEXT_func (instance, &messengerCreateInfo, pAllocator, pDebugMessenger);
	}
	else
	{
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void destroy_debug_utils_messenger (
    VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator)
{
	auto vkDestroyDebugUtilsMessengerEXT_func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr (
	    instance, "vkDestroyDebugUtilsMessengerEXT");
	if (vkDestroyDebugUtilsMessengerEXT_func != nullptr)
	{
		vkDestroyDebugUtilsMessengerEXT_func (instance, debugMessenger, pAllocator);
	}
}

VkBool32 default_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData)
{
	auto ms = DebugMessageSeverity (messageSeverity);
	auto mt = DebugMessageType (messageType);
	printf ("[%s: %s]\n%s\n", ms, mt, pCallbackData->pMessage);
	return VK_FALSE;
}

bool check_layers_supported (std::vector<const char*> layer_names)
{
	auto available_layers = detail::get_vector<VkLayerProperties> (vkEnumerateInstanceLayerProperties);
	if (!available_layers.has_value ())
	{
		return false; // maybe report error?
	}
	bool all_found = true;
	for (const auto& layer_name : layer_names)
	{
		bool found = false;
		for (const auto& layer_properties : available_layers.value ())
		{
			if (strcmp (layer_name, layer_properties.layerName) == 0)
			{
				found = true;
				break;
			}
		}
		if (!found) all_found = false;
	}

	return all_found;
}
template <typename T>
void setup_pNext_chain (T& structure, std::vector<VkBaseOutStructure*>& structs)
{
	structure.pNext = nullptr;
	if (structs.size () <= 0) return;
	for (int i = 0; i < structs.size () - 1; i++)
	{
		VkBaseOutStructure* cur = reinterpret_cast<VkBaseOutStructure*> (&structs[i]);
		cur = reinterpret_cast<VkBaseOutStructure*> (&structs[i + 1]);
	}
	structure.pNext = &structs.at (0);
}
} // namespace detail

void destroy_instance (Instance instance)
{
	if (instance.debug_messenger != nullptr)
		detail::destroy_debug_utils_messenger (instance.instance, instance.debug_messenger, instance.allocator);
	if (instance.instance != VK_NULL_HANDLE)
		vkDestroyInstance (instance.instance, instance.allocator);
}

detail::Expected<Instance, VkResult> InstanceBuilder::build ()
{

	VkApplicationInfo app_info = {};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pNext = nullptr;
	app_info.pApplicationName = info.app_name.c_str ();
	app_info.applicationVersion = info.application_version;
	app_info.pEngineName = info.engine_name.c_str ();
	app_info.engineVersion = info.engine_version;
	app_info.apiVersion = info.api_version;

	std::vector<const char*> extensions;
	for (auto& ext : info.extensions)
		extensions.push_back (ext.c_str ());
	if (info.debug_callback != nullptr)
	{
		extensions.push_back ("VK_EXT_debug_utils");
	}

	if (!info.headless_context)
	{
		extensions.push_back (VK_KHR_SURFACE_EXTENSION_NAME);
#if defined(_WIN32)
		extensions.push_back ("VK_KHR_win32_surface");
#elif defined(__ANDROID__)
		extensions.push_back (VK_KHR_ANDROID_SURFACE_EXTENSION_NAME);
#elif defined(_DIRECT2DISPLAY)
		extensions.push_back (VK_KHR_DISPLAY_EXTENSION_NAME);
#elif defined(__linux__)
		extensions.push_back ("VK_KHR_xcb_surface");
		extensions.push_back ("VK_KHR_xlib_surface");
		extensions.push_back ("VK_KHR_wayland_surface");
#elif defined(__APPLE__)
		extensions.push_back ("VK_KHR_metal_surface");
#endif
	}
	std::vector<const char*> layers;
	for (auto& layer : info.layers)
		layers.push_back (layer.c_str ());

	if (info.enable_validation_layers)
	{
		layers.push_back ("VK_LAYER_KHRONOS_validation");
	}
	bool all_layers_supported = detail::check_layers_supported (layers);
	if (!all_layers_supported)
	{
		return detail::Error{ VK_ERROR_LAYER_NOT_PRESENT, "Not all layers supported!" };
	}

	VkDebugUtilsMessengerCreateInfoEXT messengerCreateInfo = {};
	if (info.use_debug_messenger)
	{
		messengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		messengerCreateInfo.pNext = nullptr;
		messengerCreateInfo.messageSeverity = info.debug_message_severity;
		messengerCreateInfo.messageType = info.debug_message_type;
		messengerCreateInfo.pfnUserCallback = info.debug_callback;
		info.pNext_elements.push_back (reinterpret_cast<VkBaseOutStructure*> (&messengerCreateInfo));
	}

	VkValidationFeaturesEXT features{};
	if (info.enabled_validation_features.size () != 0 || info.disabled_validation_features.size ())
	{
		features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
		features.pNext = nullptr;
		features.enabledValidationFeatureCount = info.enabled_validation_features.size ();
		features.pEnabledValidationFeatures = info.enabled_validation_features.data ();
		features.disabledValidationFeatureCount = info.disabled_validation_features.size ();
		features.pDisabledValidationFeatures = info.disabled_validation_features.data ();
		info.pNext_elements.push_back (reinterpret_cast<VkBaseOutStructure*> (&features));
	}

	VkValidationFlagsEXT checks{};
	if (info.disabled_validation_checks.size () != 0)
	{
		checks.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
		checks.pNext = nullptr;
		checks.disabledValidationCheckCount = info.disabled_validation_checks.size ();
		checks.pDisabledValidationChecks = info.disabled_validation_checks.data ();
		info.pNext_elements.push_back (reinterpret_cast<VkBaseOutStructure*> (&checks));
	}

	VkInstanceCreateInfo instance_create_info = {};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	detail::setup_pNext_chain (instance_create_info, info.pNext_elements);
	instance_create_info.flags = info.flags;
	instance_create_info.pApplicationInfo = &app_info;
	instance_create_info.enabledExtensionCount = static_cast<uint32_t> (extensions.size ());
	instance_create_info.ppEnabledExtensionNames = extensions.data ();
	instance_create_info.enabledLayerCount = static_cast<uint32_t> (layers.size ());
	instance_create_info.ppEnabledLayerNames = layers.data ();

	Instance instance;
	VkResult res = vkCreateInstance (&instance_create_info, nullptr, &instance.instance);
	if (res != VK_SUCCESS) return detail::Error{ res, "Failed to create instance" };

	if (info.use_debug_messenger)
	{
		res = detail::create_debug_utils_messenger (instance.instance,
		    info.debug_callback,
		    info.debug_message_severity,
		    info.debug_message_type,
		    info.allocator,
		    &instance.debug_messenger);
		if (res != VK_SUCCESS)
		{
			return detail::Error{ res, "Failed to create setup debug callback" };
		}
	}

	if (info.headless_context)
	{
		instance.headless = true;
	}
	return instance;
}

InstanceBuilder& InstanceBuilder::set_app_name (std::string app_name)
{
	info.app_name = app_name;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_engine_name (std::string engine_name)
{
	info.engine_name = engine_name;
	return *this;
}

InstanceBuilder& InstanceBuilder::set_app_version (uint32_t major, uint32_t minor, uint32_t patch)
{
	info.application_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}
InstanceBuilder& InstanceBuilder::set_engine_version (uint32_t major, uint32_t minor, uint32_t patch)
{
	info.engine_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}
InstanceBuilder& InstanceBuilder::set_api_version (uint32_t major, uint32_t minor, uint32_t patch)
{
	info.api_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}

InstanceBuilder& InstanceBuilder::add_layer (std::string layer_name)
{
	info.layers.push_back (layer_name);
	return *this;
}
InstanceBuilder& InstanceBuilder::add_extension (std::string extension_name)
{
	info.extensions.push_back (extension_name);
	return *this;
}

InstanceBuilder& InstanceBuilder::setup_validation_layers (bool enable_validation)
{
	info.enable_validation_layers = enable_validation;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_default_debug_messenger ()
{
	info.use_debug_messenger = true;
	info.debug_callback = detail::default_debug_callback;
	return *this;
}

InstanceBuilder& InstanceBuilder::set_debug_callback (PFN_vkDebugUtilsMessengerCallbackEXT callback)
{
	info.use_debug_messenger = true;
	info.debug_callback = callback;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_headless (bool headless)
{
	info.headless_context = headless;
	return *this;
}

InstanceBuilder& InstanceBuilder::set_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity)
{
	info.debug_message_severity = severity;
	return *this;
}
InstanceBuilder& InstanceBuilder::add_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity)
{
	info.debug_message_severity = info.debug_message_severity | severity;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type)
{
	info.debug_message_type = type;
	return *this;
}
InstanceBuilder& InstanceBuilder::add_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type)
{
	info.debug_message_type = info.debug_message_type | type;
	return *this;
}

InstanceBuilder& InstanceBuilder::add_validation_disable (VkValidationCheckEXT check)
{
	info.disabled_validation_checks.push_back (check);
	return *this;
}
InstanceBuilder& InstanceBuilder::add_validation_feature_enable (VkValidationFeatureEnableEXT enable)
{
	info.enabled_validation_features.push_back (enable);
	return *this;
}
InstanceBuilder& InstanceBuilder::add_validation_feature_disable (VkValidationFeatureDisableEXT disable)
{
	info.disabled_validation_features.push_back (disable);
	return *this;
}

InstanceBuilder& InstanceBuilder::set_allocator_callback (VkAllocationCallbacks* allocator)
{
	info.allocator = allocator;
	return *this;
}

namespace detail
{
Expected<SurfaceSupportDetails, VkResult> query_surface_support_details (
    VkPhysicalDevice phys_device, VkSurfaceKHR surface)
{
	if (surface == VK_NULL_HANDLE)
		return Error{ VK_ERROR_INITIALIZATION_FAILED, "surface handle was null" };

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
		return detail::Error{ formats.error ().error_code, "Couldn't get surface formats" };
	auto present_modes = detail::get_vector<VkPresentModeKHR> (
	    vkGetPhysicalDeviceSurfacePresentModesKHR, phys_device, surface);
	if (!present_modes.has_value ())
		return detail::Error{ formats.error ().error_code, "Couldn't get surface present modes" };

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

std::vector<std::string> check_device_extension_support (
    VkPhysicalDevice device, std::vector<std::string> desired_extensions)
{
	auto available_extensions =
	    detail::get_vector<VkExtensionProperties> (vkEnumerateDeviceExtensionProperties, device, nullptr);
	if (!available_extensions.has_value ()) return {};

	std::vector<std::string> extensions_to_enable;
	for (const auto& extension : available_extensions.value ())
	{
		for (auto& req_ext : desired_extensions)
		{
			if (req_ext == extension.extensionName) extensions_to_enable.push_back (req_ext);
			break;
		}
	}
	return extensions_to_enable;
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

	auto required_extensions_supported =
	    detail::check_device_extension_support (phys_device, criteria.required_extensions);
	if (required_extensions_supported.size () != criteria.required_extensions.size ())
		suitable = Suitable::no;

	auto desired_extensions_supported =
	    detail::check_device_extension_support (phys_device, criteria.desired_extensions);
	if (desired_extensions_supported.size () != criteria.desired_extensions.size ())
		suitable = Suitable::partial;


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

PhysicalDeviceSelector::PhysicalDeviceSelector (Instance instance)
{
	info.instance = instance.instance;
	info.headless = instance.headless;
	criteria.require_present = !instance.headless;
}

detail::Expected<PhysicalDevice, VkResult> PhysicalDeviceSelector::select ()
{
	auto physical_devices = detail::get_vector<VkPhysicalDevice> (vkEnumeratePhysicalDevices, info.instance);
	if (!physical_devices.has_value ())
	{
		return detail::Error{ physical_devices.error ().error_code, "Failed to find physical devices" };
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
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "Failed to find a suitable GPU!" };
	}
	detail::populate_physical_device_details (physical_device);
	physical_device.surface = info.surface;

	physical_device.physical_device_features = criteria.required_features;

	physical_device.queue_family_properties =
	    detail::find_queue_families (physical_device.phys_device, info.surface);

	physical_device.extensions_to_enable.insert (physical_device.extensions_to_enable.end (),
	    criteria.required_extensions.begin (),
	    criteria.required_extensions.end ());
	auto desired_extensions_supported =
	    detail::check_device_extension_support (physical_device.phys_device, criteria.desired_extensions);
	physical_device.extensions_to_enable.insert (physical_device.extensions_to_enable.end (),
	    desired_extensions_supported.begin (),
	    desired_extensions_supported.end ());
	return physical_device;
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
DeviceBuilder::DeviceBuilder (PhysicalDevice phys_device)
{
	info.physical_device = phys_device;
	info.extensions = phys_device.extensions_to_enable;
}

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
	detail::setup_pNext_chain (device_create_info, info.pNext_chain);
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
		return detail::Error{ res, "Couldn't create device" };
	}
	device.allocator = info.allocator;
	device.physical_device = info.physical_device;
	device.surface = info.physical_device.surface;
	return device;
}

template <typename T> DeviceBuilder& DeviceBuilder::add_pNext (T* structure)
{
	info.pNext_chain.push_back (reinterpret_cast<VkBaseOutStructure*> (structure));
	return *this;
}

// ---- Queue ---- //

uint32_t get_queue_index_present (Device const& device)
{
	return device.physical_device.queue_family_properties.present;
}
uint32_t get_queue_index_graphics (Device const& device)
{
	return device.physical_device.queue_family_properties.graphics;
}
uint32_t get_queue_index_compute (Device const& device)
{
	return device.physical_device.queue_family_properties.compute;
}
uint32_t get_queue_index_transfer (Device const& device)
{
	return device.physical_device.queue_family_properties.transfer;
}
uint32_t get_queue_index_sparse (Device const& device)
{
	return device.physical_device.queue_family_properties.sparse;
}

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
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "requested graphics queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.graphics, index);
}
detail::Expected<VkQueue, VkResult> get_queue_compute (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_compute)
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "requested compute queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.compute, index);
}
detail::Expected<VkQueue, VkResult> get_queue_transfer (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_transfer)
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "requested transfer queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.transfer, index);
}

detail::Expected<VkQueue, VkResult> get_queue_sparse (Device const& device, uint32_t index)
{
	if (index >= device.physical_device.queue_family_properties.count_sparse)
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "requested sparse queue index is out of bounds" };
	return detail::get_queue (device, device.physical_device.queue_family_properties.sparse, index);
}

namespace detail
{
VkSurfaceFormatKHR find_surface_format (std::vector<VkSurfaceFormatKHR> const& available_formats,
    std::vector<VkSurfaceFormatKHR> const& desired_formats)
{
	for (auto const& desired_format : desired_formats)
	{
		for (auto const& available_format : available_formats)
		{
			// finds the first format that is desired and available
			if (desired_format.format == available_format.format &&
			    desired_format.colorSpace == available_format.colorSpace)
			{
				return desired_format;
			}
		}
	}

	// use the first available one if any desired formats aren't found
	return available_formats[0];
}

VkPresentModeKHR find_present_mode (std::vector<VkPresentModeKHR> const& available_resent_modes,
    std::vector<VkPresentModeKHR> const& desired_present_modes)
{
	for (auto const& desired_pm : desired_present_modes)
	{
		for (auto const& available_pm : available_resent_modes)
		{
			// finds the first present mode that is desired and available
			if (desired_pm == available_pm) return desired_pm;
		}
	}
	// only present mode required, use as a fallback
	return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D find_extent (VkSurfaceCapabilitiesKHR const& capabilities, uint32_t desired_width, uint32_t desired_height)
{
	if (capabilities.currentExtent.width != UINT32_MAX)
	{
		return capabilities.currentExtent;
	}
	else
	{
		const int WIDTH = 800;
		const int HEIGHT = 600;
		VkExtent2D actualExtent = { WIDTH, HEIGHT };

		actualExtent.width = std::max (capabilities.minImageExtent.width,
		    std::min (capabilities.maxImageExtent.width, actualExtent.width));
		actualExtent.height = std::max (capabilities.minImageExtent.height,
		    std::min (capabilities.maxImageExtent.height, actualExtent.height));

		return actualExtent;
	}
}
} // namespace detail

SwapchainBuilder::SwapchainBuilder (Device const& device)
{
	info.device = device.device;
	info.physical_device = device.physical_device;
	info.surface = device.surface;
}

detail::Expected<Swapchain, VkResult> SwapchainBuilder::build ()
{
	auto surface_support =
	    detail::query_surface_support_details (info.physical_device.phys_device, info.surface);
	if (!surface_support.has_value ()) return surface_support.error ();
	VkSurfaceFormatKHR surface_format =
	    detail::find_surface_format (surface_support.value ().formats, info.desired_formats);
	VkPresentModeKHR present_mode =
	    detail::find_present_mode (surface_support.value ().present_modes, info.desired_present_modes);
	VkExtent2D extent = detail::find_extent (
	    surface_support.value ().capabilities, info.desired_width, info.desired_height);

	uint32_t imageCount = surface_support.value ().capabilities.minImageCount + 1;
	if (surface_support.value ().capabilities.maxImageCount > 0 &&
	    imageCount > surface_support.value ().capabilities.maxImageCount)
	{
		imageCount = surface_support.value ().capabilities.maxImageCount;
	}

	VkSwapchainCreateInfoKHR swapchain_create_info = {};
	swapchain_create_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	swapchain_create_info.surface = info.surface;

	swapchain_create_info.minImageCount = imageCount;
	swapchain_create_info.imageFormat = surface_format.format;
	swapchain_create_info.imageColorSpace = surface_format.colorSpace;
	swapchain_create_info.imageExtent = extent;
	swapchain_create_info.imageArrayLayers = 1;
	swapchain_create_info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

	detail::QueueFamilies indices =
	    detail::find_queue_families (info.physical_device.phys_device, info.surface);
	uint32_t queueFamilyIndices[] = { static_cast<uint32_t> (indices.graphics),
		static_cast<uint32_t> (indices.present) };

	if (indices.graphics != indices.present)
	{
		swapchain_create_info.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
		swapchain_create_info.queueFamilyIndexCount = 2;
		swapchain_create_info.pQueueFamilyIndices = queueFamilyIndices;
	}
	else
	{
		swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	}

	swapchain_create_info.preTransform = surface_support.value ().capabilities.currentTransform;
	swapchain_create_info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	swapchain_create_info.presentMode = present_mode;
	swapchain_create_info.clipped = VK_TRUE;
	swapchain_create_info.oldSwapchain = info.old_swapchain;
	Swapchain swapchain;
	VkResult res = vkCreateSwapchainKHR (info.device, &swapchain_create_info, nullptr, &swapchain.swapchain);
	if (res != VK_SUCCESS)
	{
		return detail::Error{ res, "Failed to create swapchain" };
	}
	auto swapchain_images =
	    detail::get_vector<VkImage> (vkGetSwapchainImagesKHR, info.device, swapchain.swapchain);
	if (!swapchain_images)
	{
		return detail::Error{ VK_ERROR_INITIALIZATION_FAILED, "Failed to get swapchain Images" };
	}
	swapchain.images = swapchain_images.value ();
	swapchain.image_format = surface_format.format;
	swapchain.extent = extent;

	return swapchain;
}
detail::Expected<Swapchain, VkResult> SwapchainBuilder::recreate (Swapchain const& swapchain)
{
	info.old_swapchain = swapchain.swapchain;
	return build ();
}

void destroy_swapchain (Swapchain const& swapchain)
{
	if (swapchain.device != VK_NULL_HANDLE && swapchain.swapchain != VK_NULL_HANDLE &&
	    swapchain.allocator != VK_NULL_HANDLE)
		vkDestroySwapchainKHR (swapchain.device, swapchain.swapchain, swapchain.allocator);
}

SwapchainBuilder& SwapchainBuilder::set_desired_format (VkSurfaceFormatKHR format)
{
	info.desired_formats.insert (info.desired_formats.begin (), format);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::add_fallback_format (VkSurfaceFormatKHR format)
{
	info.desired_formats.push_back (format);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::use_default_format_selection ()
{
	info.desired_formats.push_back ({ VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR });
	info.desired_formats.push_back ({ VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR });
	return *this;
}

SwapchainBuilder& SwapchainBuilder::set_desired_present_mode (VkPresentModeKHR present_mode)
{
	info.desired_present_modes.insert (info.desired_present_modes.begin (), present_mode);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::add_fallback_present_mode (VkPresentModeKHR present_mode)
{
	info.desired_present_modes.push_back (present_mode);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::use_default_present_mode_selection ()
{
	info.desired_present_modes.push_back (VK_PRESENT_MODE_MAILBOX_KHR);
	info.desired_present_modes.push_back (VK_PRESENT_MODE_FIFO_KHR);
	info.desired_present_modes.push_back (VK_PRESENT_MODE_FIFO_RELAXED_KHR);
	info.desired_present_modes.push_back (VK_PRESENT_MODE_IMMEDIATE_KHR);
	return *this;
}


} // namespace vkb