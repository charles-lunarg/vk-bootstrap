#include "VkBootstrap.h"

#include <stdio.h>
#include <string.h>

namespace vkb {

namespace detail {
// Helper for robustly executing the two-call pattern
template <typename T, typename F, typename... Ts>
auto get_vector (F&& f, Ts&&... ts) -> Expected<std::vector<T>, VkResult> {
	uint32_t count = 0;
	std::vector<T> results;
	VkResult err;
	do {
		err = f (ts..., &count, nullptr);
		if (err) {
			return err;
		};
		results.resize (count);
		err = f (ts..., &count, results.data ());
	} while (err == VK_INCOMPLETE);
	if (err != VK_SUCCESS) {
		return err;
	};
	return results;
}

template <typename T, typename F, typename... Ts>
auto get_vector_noerror (F&& f, Ts&&... ts) -> std::vector<T> {
	uint32_t count = 0;
	std::vector<T> results;
	f (ts..., &count, nullptr);
	results.resize (count);
	f (ts..., &count, results.data ());
	return results;
}
} // namespace detail

const char* to_string_message_severity (VkDebugUtilsMessageSeverityFlagBitsEXT s) {
	switch (s) {
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
const char* to_string_message_type (VkDebugUtilsMessageTypeFlagsEXT s) {
	if (s == 7) return "General | Validation | Performance";
	if (s == 6) return "Validation | Performance";
	if (s == 5) return "General | Performance";
	if (s == 4 /*VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT*/) return "Performance";
	if (s == 3) return "General | Validation";
	if (s == 2 /*VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT*/) return "Validation";
	if (s == 1 /*VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT*/) return "General";
	return "Unknown";
}

VkResult create_debug_utils_messenger (VkInstance instance,
    PFN_vkDebugUtilsMessengerCallbackEXT debug_callback,
    VkDebugUtilsMessageSeverityFlagsEXT severity,
    VkDebugUtilsMessageTypeFlagsEXT type,
    VkDebugUtilsMessengerEXT* pDebugMessenger) {
	if (debug_callback == nullptr) debug_callback = default_debug_callback;
	VkDebugUtilsMessengerCreateInfoEXT messengerCreateInfo = {};
	messengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	messengerCreateInfo.pNext = nullptr;
	messengerCreateInfo.messageSeverity = severity;
	messengerCreateInfo.messageType = type;
	messengerCreateInfo.pfnUserCallback = debug_callback;


	auto vkCreateDebugUtilsMessengerEXT_func = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT> (
	    vkGetInstanceProcAddr (instance, "vkCreateDebugUtilsMessengerEXT"));
	if (vkCreateDebugUtilsMessengerEXT_func != nullptr) {
		return vkCreateDebugUtilsMessengerEXT_func (instance, &messengerCreateInfo, nullptr, pDebugMessenger);
	} else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void destroy_debug_utils_messenger (VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger) {
	auto vkDestroyDebugUtilsMessengerEXT_func = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT> (
	    vkGetInstanceProcAddr (instance, "vkDestroyDebugUtilsMessengerEXT"));
	if (vkDestroyDebugUtilsMessengerEXT_func != nullptr) {
		vkDestroyDebugUtilsMessengerEXT_func (instance, debugMessenger, nullptr);
	}
}

VkBool32 default_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) {
	auto ms = to_string_message_severity (messageSeverity);
	auto mt = to_string_message_type (messageType);
	printf ("[%s: %s]\n%s\n", ms, mt, pCallbackData->pMessage);
	return VK_FALSE;
}

namespace detail {
bool check_layer_supported (std::vector<VkLayerProperties> available_layers, const char* layer_name) {
	if (!layer_name) return false;
	for (const auto& layer_properties : available_layers) {
		if (strcmp (layer_name, layer_properties.layerName) == 0) {
			return true;
		}
	}
	return false;
}

bool check_layers_supported (std::vector<VkLayerProperties> available_layers, std::vector<const char*> layer_names) {
	bool all_found = true;
	for (const auto& layer_name : layer_names) {
		bool found = check_layer_supported (available_layers, layer_name);
		if (!found) all_found = false;
	}
	return all_found;
}

bool check_extension_supported (std::vector<VkExtensionProperties> available_extensions, const char* extension_name) {
	if (!extension_name) return false;
	for (const auto& layer_properties : available_extensions) {
		if (strcmp (extension_name, layer_properties.extensionName) == 0) {
			return true;
		}
	}
	return false;
}

bool check_extensions_supported (std::vector<VkExtensionProperties> available_extensions,
    std::vector<const char*> extension_names) {
	bool all_found = true;
	for (const auto& extension_name : extension_names) {
		bool found = check_extension_supported (available_extensions, extension_name);
		if (!found) all_found = false;
	}
	return all_found;
}

template <typename T>
void setup_pNext_chain (T& structure, std::vector<VkBaseOutStructure*> const& structs) {
	structure.pNext = nullptr;
	if (structs.size () <= 0) return;
	for (int i = 0; i < structs.size () - 1; i++) {
		structs.at (i)->pNext = structs.at (i + 1);
	}
	structure.pNext = structs.at (0);
}
const char* validation_layer_name = "VK_LAYER_KHRONOS_validation";

} // namespace detail

SystemInfo::SystemInfo () {
	auto available_extensions =
	    detail::get_vector<VkExtensionProperties> (vkEnumerateInstanceExtensionProperties, nullptr);
	if (available_extensions.has_value ()) {
		this->available_extensions = available_extensions.value ();
	}
	for (auto& ext : this->available_extensions)
		if (strcmp (ext.extensionName, VK_EXT_DEBUG_UTILS_EXTENSION_NAME) == 0)
			debug_messenger_available = true;

	auto available_layers = detail::get_vector<VkLayerProperties> (vkEnumerateInstanceLayerProperties);
	if (available_layers.has_value ()) {
		this->available_layers = available_layers.value ();
	}
	for (auto& layer : this->available_layers)
		if (strcmp (layer.layerName, detail::validation_layer_name) == 0)
			validation_layers_available = true;
}
bool SystemInfo::is_extension_available (const char* extension_name) {
	if (!extension_name) return false;
	return detail::check_extension_supported (available_extensions, extension_name);
}
bool SystemInfo::is_layer_available (const char* layer_name) {
	if (!layer_name) return false;
	return detail::check_layer_supported (available_layers, layer_name);
}

const char* to_string (InstanceError err) {
	switch (err) {
		case InstanceError::failed_create_debug_messenger:
			return "failed_create_debug_messenger";
		case InstanceError::failed_create_instance:
			return "failed_create_instance";
		case InstanceError::requested_layers_not_present:
			return "requested_layers_not_present";
		case InstanceError::requested_extensions_not_present:
			return "requested_extensions_not_present";
		default:
			return "";
	}
}

void destroy_instance (Instance instance) {
	if (instance.instance != VK_NULL_HANDLE) {
		if (instance.debug_messenger != nullptr)
			destroy_debug_utils_messenger (instance.instance, instance.debug_messenger);
		vkDestroyInstance (instance.instance, nullptr);
	}
}

SystemInfo InstanceBuilder::get_system_info () { return system; }

detail::Expected<Instance, detail::Error<InstanceError>> InstanceBuilder::build () {

	VkApplicationInfo app_info = {};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pNext = nullptr;
	app_info.pApplicationName = info.app_name != nullptr ? info.app_name : "";
	app_info.applicationVersion = info.application_version;
	app_info.pEngineName = info.engine_name != nullptr ? info.engine_name : "";
	app_info.engineVersion = info.engine_version;
	app_info.apiVersion = info.api_version;

	std::vector<const char*> extensions;
	for (auto& ext : info.extensions)
		extensions.push_back (ext);
	if (info.debug_callback != nullptr) {
		extensions.push_back (VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	if (!info.headless_context) {
		extensions.push_back ("VK_KHR_surface");
#if defined(_WIN32)
		extensions.push_back ("VK_KHR_win32_surface");
#elif defined(__ANDROID__)
		extensions.push_back ("VK_KHR_android_surface");
#elif defined(_DIRECT2DISPLAY)
		extensions.push_back ("VK_KHR_display");
#elif defined(__linux__)
		extensions.push_back ("VK_KHR_xcb_surface");
		extensions.push_back ("VK_KHR_xlib_surface");
		extensions.push_back ("VK_KHR_wayland_surface");
#elif defined(__APPLE__)
		extensions.push_back ("VK_KHR_metal_surface");
#endif
	}
	bool all_extensions_supported = detail::check_extensions_supported (system.available_extensions, extensions);
	if (!all_extensions_supported) {
		return detail::Error<InstanceError>{ InstanceError::requested_extensions_not_present };
	}

	std::vector<const char*> layers;
	for (auto& layer : info.layers)
		layers.push_back (layer);

	if (info.enable_validation_layers) {
		layers.push_back (detail::validation_layer_name);
	}
	bool all_layers_supported = detail::check_layers_supported (system.available_layers, layers);
	if (!all_layers_supported) {
		return detail::Error<InstanceError>{ InstanceError::requested_layers_not_present };
	}

	VkDebugUtilsMessengerCreateInfoEXT messengerCreateInfo = {};
	if (info.use_debug_messenger) {
		messengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		messengerCreateInfo.pNext = nullptr;
		messengerCreateInfo.messageSeverity = info.debug_message_severity;
		messengerCreateInfo.messageType = info.debug_message_type;
		messengerCreateInfo.pfnUserCallback = info.debug_callback;
		info.pNext_elements.push_back (reinterpret_cast<VkBaseOutStructure*> (&messengerCreateInfo));
	}

	VkValidationFeaturesEXT features{};
	if (info.enabled_validation_features.size () != 0 || info.disabled_validation_features.size ()) {
		features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
		features.pNext = nullptr;
		features.enabledValidationFeatureCount = info.enabled_validation_features.size ();
		features.pEnabledValidationFeatures = info.enabled_validation_features.data ();
		features.disabledValidationFeatureCount = info.disabled_validation_features.size ();
		features.pDisabledValidationFeatures = info.disabled_validation_features.data ();
		info.pNext_elements.push_back (reinterpret_cast<VkBaseOutStructure*> (&features));
	}

	VkValidationFlagsEXT checks{};
	if (info.disabled_validation_checks.size () != 0) {
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
	if (res != VK_SUCCESS)
		return detail::Error<InstanceError>{ InstanceError::failed_create_instance, res };

	if (info.use_debug_messenger) {
		res = create_debug_utils_messenger (instance.instance,
		    info.debug_callback,
		    info.debug_message_severity,
		    info.debug_message_type,
		    &instance.debug_messenger);
		if (res != VK_SUCCESS) {
			return detail::Error<InstanceError>{ InstanceError::failed_create_debug_messenger, res };
		}
	}

	if (info.headless_context) {
		instance.headless = true;
	}
	return instance;
}

InstanceBuilder& InstanceBuilder::set_app_name (const char* app_name) {
	if (!app_name) return *this;
	info.app_name = app_name;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_engine_name (const char* engine_name) {
	if (!engine_name) return *this;
	info.engine_name = engine_name;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_app_version (uint32_t major, uint32_t minor, uint32_t patch) {
	info.application_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}
InstanceBuilder& InstanceBuilder::set_engine_version (uint32_t major, uint32_t minor, uint32_t patch) {
	info.engine_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}
InstanceBuilder& InstanceBuilder::set_api_version (uint32_t major, uint32_t minor, uint32_t patch) {
	info.api_version = VK_MAKE_VERSION (major, minor, patch);
	return *this;
}
InstanceBuilder& InstanceBuilder::enable_layer (const char* layer_name) {
	if (!layer_name) return *this;
	info.layers.push_back (layer_name);
	return *this;
}
InstanceBuilder& InstanceBuilder::enable_extension (const char* extension_name) {
	if (!extension_name) return *this;
	info.extensions.push_back (extension_name);
	return *this;
}
InstanceBuilder& InstanceBuilder::enable_validation_layers (bool enable_validation) {
	info.enable_validation_layers = enable_validation;
	return *this;
}
InstanceBuilder& InstanceBuilder::request_validation_layers (bool enable_validation) {
	info.enable_validation_layers =
	    enable_validation &&
	    detail::check_extension_supported (system.available_extensions, detail::validation_layer_name);
	return *this;
}
InstanceBuilder& InstanceBuilder::use_default_debug_messenger () {
	info.use_debug_messenger = true;
	info.debug_callback = default_debug_callback;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_debug_callback (PFN_vkDebugUtilsMessengerCallbackEXT callback) {
	info.use_debug_messenger = true;
	info.debug_callback = callback;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_headless (bool headless) {
	info.headless_context = headless;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity) {
	info.debug_message_severity = severity;
	return *this;
}
InstanceBuilder& InstanceBuilder::add_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity) {
	info.debug_message_severity = info.debug_message_severity | severity;
	return *this;
}
InstanceBuilder& InstanceBuilder::set_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type) {
	info.debug_message_type = type;
	return *this;
}
InstanceBuilder& InstanceBuilder::add_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type) {
	info.debug_message_type = info.debug_message_type | type;
	return *this;
}
InstanceBuilder& InstanceBuilder::add_validation_disable (VkValidationCheckEXT check) {
	info.disabled_validation_checks.push_back (check);
	return *this;
}
InstanceBuilder& InstanceBuilder::add_validation_feature_enable (VkValidationFeatureEnableEXT enable) {
	info.enabled_validation_features.push_back (enable);
	return *this;
}
InstanceBuilder& InstanceBuilder::add_validation_feature_disable (VkValidationFeatureDisableEXT disable) {
	info.disabled_validation_features.push_back (disable);
	return *this;
}

// ---- Physical Device ---- //

namespace detail {

struct SurfaceSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> present_modes;
};

enum class SurfaceSupportError {
	surface_handle_null,
	failed_get_surface_capabilities,
	failed_enumerate_surface_formats,
	failed_enumerate_present_modes
};

Expected<SurfaceSupportDetails, detail::Error<SurfaceSupportError>> query_surface_support_details (
    VkPhysicalDevice phys_device, VkSurfaceKHR surface) {
	if (surface == VK_NULL_HANDLE)
		return detail::Error<SurfaceSupportError>{ SurfaceSupportError::surface_handle_null };

	VkSurfaceCapabilitiesKHR capabilities;
	VkResult res = vkGetPhysicalDeviceSurfaceCapabilitiesKHR (phys_device, surface, &capabilities);
	if (res != VK_SUCCESS) {
		return detail::Error<SurfaceSupportError>{ SurfaceSupportError::failed_get_surface_capabilities, res };
	}
	auto formats = detail::get_vector<VkSurfaceFormatKHR> (
	    vkGetPhysicalDeviceSurfaceFormatsKHR, phys_device, surface);
	if (!formats.has_value ())
		return detail::Error<SurfaceSupportError>{ SurfaceSupportError::failed_enumerate_surface_formats,
			formats.error () };
	auto present_modes = detail::get_vector<VkPresentModeKHR> (
	    vkGetPhysicalDeviceSurfacePresentModesKHR, phys_device, surface);
	if (!present_modes.has_value ())
		return detail::Error<SurfaceSupportError>{ SurfaceSupportError::failed_enumerate_present_modes,
			formats.error () };
	return SurfaceSupportDetails{ capabilities, formats.value (), present_modes.value () };
}

std::vector<const char*> check_device_extension_support (
    VkPhysicalDevice device, std::vector<const char*> desired_extensions) {
	auto available_extensions =
	    detail::get_vector<VkExtensionProperties> (vkEnumerateDeviceExtensionProperties, device, nullptr);
	if (!available_extensions.has_value ()) return {};

	std::vector<const char*> extensions_to_enable;
	for (const auto& extension : available_extensions.value ()) {
		for (auto& req_ext : desired_extensions) {
			if (req_ext == extension.extensionName) extensions_to_enable.push_back (req_ext);
			break;
		}
	}
	return extensions_to_enable;
}

bool supports_features (VkPhysicalDeviceFeatures supported, VkPhysicalDeviceFeatures requested) {
	// clang-format off
    if (requested.robustBufferAccess && !supported.robustBufferAccess) return false;
    if (requested.fullDrawIndexUint32 && !supported.fullDrawIndexUint32) return false;
    if (requested.imageCubeArray && !supported.imageCubeArray) return false;
    if (requested.independentBlend && !supported.independentBlend) return false;
    if (requested.geometryShader && !supported.geometryShader) return false;
    if (requested.tessellationShader && !supported.tessellationShader) return false;
    if (requested.sampleRateShading && !supported.sampleRateShading) return false;
    if (requested.dualSrcBlend && !supported.dualSrcBlend) return false;
    if (requested.logicOp && !supported.logicOp) return false;
    if (requested.multiDrawIndirect && !supported.multiDrawIndirect) return false;
    if (requested.drawIndirectFirstInstance && !supported.drawIndirectFirstInstance) return false;
    if (requested.depthClamp && !supported.depthClamp) return false;
    if (requested.depthBiasClamp && !supported.depthBiasClamp) return false;
    if (requested.fillModeNonSolid && !supported.fillModeNonSolid) return false;
    if (requested.depthBounds && !supported.depthBounds) return false;
    if (requested.wideLines && !supported.wideLines) return false;
    if (requested.largePoints && !supported.largePoints) return false;
    if (requested.alphaToOne && !supported.alphaToOne) return false;
    if (requested.multiViewport && !supported.multiViewport) return false;
    if (requested.samplerAnisotropy && !supported.samplerAnisotropy) return false;
    if (requested.textureCompressionETC2 && !supported.textureCompressionETC2) return false;
    if (requested.textureCompressionASTC_LDR && !supported.textureCompressionASTC_LDR) return false;
    if (requested.textureCompressionBC && !supported.textureCompressionBC) return false;
    if (requested.occlusionQueryPrecise && !supported.occlusionQueryPrecise) return false;
    if (requested.pipelineStatisticsQuery && !supported.pipelineStatisticsQuery) return false;
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

// finds the first queue which supports graphics operations. returns -1 if none is found
int get_graphics_queue_index (std::vector<VkQueueFamilyProperties> const& families) {
	for (int i = 0; i < families.size (); i++) {
		if (families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) return i;
	}
	return -1;
}
// finds a compute queue which is distinct from the graphics queue and tries to find one without
// transfer support returns -1 if none is found
int get_distinct_compute_queue_index (std::vector<VkQueueFamilyProperties> const& families) {
	int compute = -1;
	for (int i = 0; i < families.size (); i++) {
		if ((families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
		    ((families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)) {
			if ((families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) == 0) {
				return i;
			} else {
				compute = i;
			}
		}
	}
	return compute;
}
// finds a transfer queue which is distinct from the graphics queue and tries to find one without
// compute support returns -1 if none is found
int get_distinct_transfer_queue_index (std::vector<VkQueueFamilyProperties> const& families) {
	int transfer = -1;
	for (int i = 0; i < families.size (); i++) {
		if ((families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) &&
		    ((families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)) {
			if ((families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) == 0) {
				return i;
			} else {
				transfer = i;
			}
		}
	}
	return transfer;
}
// finds the first queue which supports only compute (not graphics or transfer). returns -1 if none is found
int get_dedicated_compute_queue_index (std::vector<VkQueueFamilyProperties> const& families) {
	for (int i = 0; i < families.size (); i++) {
		if ((families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
		    (families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0 &&
		    (families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) == 0)
			return i;
	}
	return -1;
}
// finds the first queue which supports only transfer (not graphics or compute). returns -1 if none is found
int get_dedicated_transfer_queue_index (std::vector<VkQueueFamilyProperties> const& families) {
	for (int i = 0; i < families.size (); i++) {
		if ((families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) &&
		    (families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0 &&
		    (families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) == 0)
			return i;
	}
	return -1;
}
// finds the first queue which supports presenting. returns -1 if none is found
int get_present_queue_index (VkPhysicalDevice const phys_device,
    VkSurfaceKHR const surface,
    std::vector<VkQueueFamilyProperties> const& families) {
	for (int i = 0; i < families.size (); i++) {
		VkBool32 presentSupport = false;
		if (surface != VK_NULL_HANDLE) {
			VkResult res = vkGetPhysicalDeviceSurfaceSupportKHR (phys_device, i, surface, &presentSupport);
		}
		if (presentSupport == true) return i;
	}
	return -1;
}
} // namespace detail


const char* to_string (PhysicalDeviceError err) {
	switch (err) {
		case PhysicalDeviceError::failed_enumerate_physical_devices:
			return "failed_enumerate_physical_devices";
		case PhysicalDeviceError::no_physical_devices_found:
			return "no_physical_devices_found";
		case PhysicalDeviceError::no_suitable_device:
			return "no_suitable_device";
		default:
			return "";
	}
}

PhysicalDeviceSelector::PhysicalDeviceDesc PhysicalDeviceSelector::populate_device_details (
    VkPhysicalDevice phys_device) {
	PhysicalDeviceSelector::PhysicalDeviceDesc desc{};
	desc.phys_device = phys_device;
	auto queue_families = detail::get_vector_noerror<VkQueueFamilyProperties> (
	    vkGetPhysicalDeviceQueueFamilyProperties, phys_device);
	desc.queue_families = queue_families;

	vkGetPhysicalDeviceProperties (phys_device, &desc.device_properties);
	vkGetPhysicalDeviceFeatures (phys_device, &desc.device_features);
	vkGetPhysicalDeviceMemoryProperties (phys_device, &desc.mem_properties);
	return desc;
}

PhysicalDeviceSelector::Suitable PhysicalDeviceSelector::is_device_suitable (PhysicalDeviceDesc pd) {
	Suitable suitable = Suitable::yes;

	bool dedicated_compute = detail::get_dedicated_compute_queue_index (pd.queue_families) >= 0;
	bool dedicated_transfer = detail::get_dedicated_transfer_queue_index (pd.queue_families) >= 0;
	bool distinct_compute = detail::get_distinct_compute_queue_index (pd.queue_families) >= 0;
	bool distinct_transfer = detail::get_distinct_transfer_queue_index (pd.queue_families) >= 0;

	bool present_queue =
	    detail::get_present_queue_index (pd.phys_device, system_info.surface, pd.queue_families);

	if (criteria.require_dedicated_compute_queue && !dedicated_compute) suitable = Suitable::no;
	if (criteria.require_dedicated_transfer_queue && !dedicated_transfer) suitable = Suitable::no;
	if (criteria.require_distinct_compute_queue && !distinct_compute) suitable = Suitable::no;
	if (criteria.require_distinct_transfer_queue && !distinct_transfer) suitable = Suitable::no;
	if (criteria.require_present && !present_queue) suitable = Suitable::no;

	auto required_extensions_supported =
	    detail::check_device_extension_support (pd.phys_device, criteria.required_extensions);
	if (required_extensions_supported.size () != criteria.required_extensions.size ())
		suitable = Suitable::no;

	auto desired_extensions_supported =
	    detail::check_device_extension_support (pd.phys_device, criteria.desired_extensions);
	if (desired_extensions_supported.size () != criteria.desired_extensions.size ())
		suitable = Suitable::partial;


	bool swapChainAdequate = false;
	if (!system_info.headless) {
		auto swapChainSupport_ret =
		    detail::query_surface_support_details (pd.phys_device, system_info.surface);
		if (swapChainSupport_ret.has_value ()) {
			auto swapchain_support = swapChainSupport_ret.value ();
			swapChainAdequate =
			    !swapchain_support.formats.empty () && !swapchain_support.present_modes.empty ();
		}
	}
	if (criteria.require_present && !swapChainAdequate) suitable = Suitable::no;

	if ((criteria.preferred_type == PreferredDeviceType::discrete &&
	        pd.device_properties.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) ||
	    (criteria.preferred_type == PreferredDeviceType::integrated &&
	        pd.device_properties.deviceType != VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) ||
	    (criteria.preferred_type == PreferredDeviceType::virtual_gpu &&
	        pd.device_properties.deviceType != VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU)) {
		if (criteria.allow_fallback)
			suitable = Suitable::partial;
		else
			suitable = Suitable::no;
	}

	if (criteria.required_version < pd.device_properties.apiVersion) suitable = Suitable::no;
	if (criteria.desired_version < pd.device_properties.apiVersion) suitable = Suitable::partial;

	bool required_features_supported =
	    detail::supports_features (pd.device_features, criteria.required_features);
	if (!required_features_supported) suitable = Suitable::no;

	bool has_required_memory = false;
	bool has_preferred_memory = false;
	for (int i = 0; i < pd.mem_properties.memoryHeapCount; i++) {
		if (pd.mem_properties.memoryHeaps[i].flags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) {
			if (pd.mem_properties.memoryHeaps[i].size > criteria.required_mem_size) {
				has_required_memory = true;
			}
			if (pd.mem_properties.memoryHeaps[i].size > criteria.desired_mem_size) {
				has_preferred_memory = true;
			}
		}
	}
	if (!has_required_memory) suitable = Suitable::no;
	if (!has_preferred_memory) suitable = Suitable::partial;

	return suitable;
}

PhysicalDeviceSelector::PhysicalDeviceSelector (Instance const& instance) {
	system_info.instance = instance.instance;
	system_info.headless = instance.headless;
	criteria.require_present = !instance.headless;
}

detail::Expected<PhysicalDevice, detail::Error<PhysicalDeviceError>> PhysicalDeviceSelector::select () {
	auto physical_devices =
	    detail::get_vector<VkPhysicalDevice> (vkEnumeratePhysicalDevices, system_info.instance);
	if (!physical_devices.has_value ()) {
		return detail::Error<PhysicalDeviceError>{ PhysicalDeviceError::failed_enumerate_physical_devices,
			physical_devices.error () };
	}
	if (physical_devices.value ().size () == 0) {
		return detail::Error<PhysicalDeviceError>{ PhysicalDeviceError::no_physical_devices_found };
	}

	std::vector<PhysicalDeviceDesc> phys_device_descriptions;
	for (auto& phys_device : physical_devices.value ()) {
		phys_device_descriptions.push_back (populate_device_details (phys_device));
	}

	PhysicalDeviceDesc selected_device{};

	if (criteria.use_first_gpu_unconditionally) {
		selected_device = phys_device_descriptions.at (0);
	} else {
		for (const auto& device : phys_device_descriptions) {
			auto suitable = is_device_suitable (device);
			if (suitable == Suitable::yes) {
				selected_device = device;
				break;
			} else if (suitable == Suitable::partial) {
				selected_device = device;
			}
		}
	}

	if (selected_device.phys_device == VK_NULL_HANDLE) {
		return detail::Error<PhysicalDeviceError>{ PhysicalDeviceError::no_suitable_device };
	}
	PhysicalDevice out_device{};
	out_device.phys_device = selected_device.phys_device;
	out_device.surface = system_info.surface;
	out_device.features = criteria.required_features;
	out_device.queue_families = selected_device.queue_families;

	out_device.extensions_to_enable.insert (out_device.extensions_to_enable.end (),
	    criteria.required_extensions.begin (),
	    criteria.required_extensions.end ());
	auto desired_extensions_supported =
	    detail::check_device_extension_support (out_device.phys_device, criteria.desired_extensions);
	out_device.extensions_to_enable.insert (out_device.extensions_to_enable.end (),
	    desired_extensions_supported.begin (),
	    desired_extensions_supported.end ());
	return out_device;
}

PhysicalDeviceSelector& PhysicalDeviceSelector::set_surface (VkSurfaceKHR surface) {
	system_info.surface = surface;
	system_info.headless = false;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::prefer_gpu_device_type (PreferredDeviceType type) {
	criteria.preferred_type = type;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::allow_fallback_gpu_type (bool fallback) {
	criteria.allow_fallback = fallback;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_present (bool require) {
	criteria.require_present = require;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_dedicated_transfer_queue () {
	criteria.require_dedicated_transfer_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_dedicated_compute_queue () {
	criteria.require_dedicated_compute_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_distinct_transfer_queue () {
	criteria.require_distinct_transfer_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::require_distinct_compute_queue () {
	criteria.require_distinct_compute_queue = true;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::required_device_memory_size (VkDeviceSize size) {
	criteria.required_mem_size = size;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::desired_device_memory_size (VkDeviceSize size) {
	criteria.desired_mem_size = size;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_required_extension (const char* extension) {
	criteria.required_extensions.push_back (extension);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_required_extensions (std::vector<const char*> extensions) {
	criteria.required_extensions.insert (
	    criteria.required_extensions.end (), extensions.begin (), extensions.end ());
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_desired_extension (const char* extension) {
	criteria.desired_extensions.push_back (extension);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::add_desired_extensions (std::vector<const char*> extensions) {
	criteria.desired_extensions.insert (
	    criteria.desired_extensions.end (), extensions.begin (), extensions.end ());
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_minimum_version (uint32_t major, uint32_t minor) {
	criteria.required_version = VK_MAKE_VERSION (major, minor, 0);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_desired_version (uint32_t major, uint32_t minor) {
	criteria.desired_version = VK_MAKE_VERSION (major, minor, 0);
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::set_required_features (VkPhysicalDeviceFeatures features) {
	criteria.required_features = features;
	return *this;
}
PhysicalDeviceSelector& PhysicalDeviceSelector::select_first_device_unconditionally (bool unconditionally) {
	criteria.use_first_gpu_unconditionally = unconditionally;
	return *this;
}

// ---- Device ---- //
const char* to_string (DeviceError err) {
	switch (err) {
		case DeviceError::failed_create_device:
			return "failed_create_device";
		default:
			return "";
	}
}

void destroy_device (Device device) { vkDestroyDevice (device.device, nullptr); }

DeviceBuilder::DeviceBuilder (PhysicalDevice phys_device) {
	info.physical_device = phys_device;
	info.extensions = phys_device.extensions_to_enable;
	info.queue_families = phys_device.queue_families;
	info.dedicated_compute = phys_device.dedicated_compute;
	info.distinct_compute = phys_device.distinct_compute;
	info.dedicated_transfer = phys_device.dedicated_transfer;
	info.distinct_transfer = phys_device.distinct_transfer;
}

detail::Expected<Device, detail::Error<DeviceError>> DeviceBuilder::build () {

	std::vector<CustomQueueDescription> queue_descriptions;
	queue_descriptions.insert (
	    queue_descriptions.end (), info.queue_descriptions.begin (), info.queue_descriptions.end ());

	if (queue_descriptions.size () == 0) {
		int graphics = detail::get_graphics_queue_index (info.queue_families);
		if (graphics >= 0) {
			queue_descriptions.push_back ({ static_cast<uint32_t> (graphics), 1, std::vector<float>{ 1.0f } });
		}
		if (info.distinct_compute || info.dedicated_compute) {
			int compute = -1;
			if (info.dedicated_compute)
				compute = detail::get_distinct_compute_queue_index (info.queue_families);
			else if (info.distinct_compute) {
				compute = detail::get_distinct_compute_queue_index (info.queue_families);
				int transfer = detail::get_distinct_transfer_queue_index (info.queue_families);
				if (compute == transfer && compute >= 0) compute = -1;
			}

			if (compute >= 0) {
				queue_descriptions.push_back (
				    { static_cast<uint32_t> (compute), 1, std::vector<float>{ 1.0f } });
			}
		}
		if (info.distinct_transfer || info.dedicated_transfer) {
			int transfer = -1;
			if (info.dedicated_transfer)
				transfer = detail::get_dedicated_transfer_queue_index (info.queue_families);
			else if (info.distinct_transfer) {
				transfer = detail::get_distinct_transfer_queue_index (info.queue_families);
				int compute = detail::get_distinct_transfer_queue_index (info.queue_families);
				if (transfer == compute && transfer >= 0) transfer = -1;
			}
			if (transfer >= 0) {
				queue_descriptions.push_back (
				    { static_cast<uint32_t> (transfer), 1, std::vector<float>{ 1.0f } });
			}
		}
	}

	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	for (auto& desc : queue_descriptions) {
		VkDeviceQueueCreateInfo queue_create_info = {};
		queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queue_create_info.queueFamilyIndex = desc.index;
		queue_create_info.queueCount = desc.count;
		queue_create_info.pQueuePriorities = desc.priorities.data ();
		queueCreateInfos.push_back (queue_create_info);
	}

	std::vector<const char*> extensions;
	for (auto& ext : info.extensions)
		extensions.push_back (ext);
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
	device_create_info.pEnabledFeatures = &info.physical_device.features;

	Device device;
	VkResult res =
	    vkCreateDevice (info.physical_device.phys_device, &device_create_info, nullptr, &device.device);
	if (res != VK_SUCCESS) {
		return detail::Error<DeviceError>{ DeviceError::failed_create_device, res };
	}
	device.physical_device = info.physical_device;
	device.surface = info.physical_device.surface;
	device.queue_families = info.queue_families;
	return device;
}
DeviceBuilder& DeviceBuilder::request_dedicated_compute_queue (bool compute) {
	info.dedicated_compute = compute;
	return *this;
}
DeviceBuilder& DeviceBuilder::request_dedicated_transfer_queue (bool transfer) {
	info.dedicated_transfer = transfer;
	return *this;
}
DeviceBuilder& DeviceBuilder::request_distinct_compute_queue (bool compute) {
	info.distinct_compute = compute;
	return *this;
}
DeviceBuilder& DeviceBuilder::request_distinct_transfer_queue (bool transfer) {
	info.distinct_transfer = transfer;
	return *this;
}
DeviceBuilder& DeviceBuilder::custom_queue_setup (std::vector<CustomQueueDescription> queue_descriptions) {
	info.queue_descriptions = queue_descriptions;
	return *this;
}
template <typename T> DeviceBuilder& DeviceBuilder::add_pNext (T* structure) {
	info.pNext_chain.push_back (reinterpret_cast<VkBaseOutStructure*> (structure));
	return *this;
}


// ---- Queues ---- //
const char* to_string (QueueError err) {
	switch (err) {
		case QueueError::present_unavailable:
			return "present_unavailable";
		case QueueError::compute_unavailable:
			return "compute_unavailable";
		case QueueError::transfer_unavailable:
			return "transfer_unavailable";
		case QueueError::queue_index_out_of_range:
			return "queue_index_out_of_range";
		case QueueError::invalid_queue_family_index:
			return "invalid_queue_family_index";
		default:
			return "";
	}
}

bool DeviceBuilder::has_dedicated_compute_queue () {
	return detail::get_dedicated_compute_queue_index (info.queue_families) >= 0;
}
bool DeviceBuilder::has_distinct_compute_queue () {
	return detail::get_distinct_compute_queue_index (info.queue_families) >= 0;
}
bool DeviceBuilder::has_dedicated_transfer_queue () {
	return detail::get_dedicated_transfer_queue_index (info.queue_families) >= 0;
}
bool DeviceBuilder::has_distinct_transfer_queue () {
	return detail::get_distinct_transfer_queue_index (info.queue_families) >= 0;
}

detail::Expected<uint32_t, detail::Error<QueueError>> get_present_queue_index (Device const& device) {
	int present = detail::get_present_queue_index (
	    device.physical_device.phys_device, device.surface, device.queue_families);
	if (present < 0) return detail::Error<QueueError>{ QueueError::present_unavailable };
	return static_cast<uint32_t> (present);
}
detail::Expected<uint32_t, detail::Error<QueueError>> get_graphics_queue_index (Device const& device) {
	int graphics = detail::get_graphics_queue_index (device.queue_families);
	if (graphics < 0) return detail::Error<QueueError>{ QueueError::invalid_queue_family_index };
	return static_cast<uint32_t> (graphics);
}
detail::Expected<uint32_t, detail::Error<QueueError>> get_compute_queue_index (Device const& device) {
	int compute = detail::get_distinct_compute_queue_index (device.queue_families);
	if (compute < 0) return detail::Error<QueueError>{ QueueError::compute_unavailable };
	return static_cast<uint32_t> (compute);
}
detail::Expected<uint32_t, detail::Error<QueueError>> get_transfer_queue_index (Device const& device) {
	int transfer = detail::get_distinct_transfer_queue_index (device.queue_families);
	if (transfer < 0) return detail::Error<QueueError>{ QueueError::transfer_unavailable };
	return static_cast<uint32_t> (transfer);
}

VkQueue get_queue (VkDevice device, int32_t family) {
	VkQueue out_queue;
	vkGetDeviceQueue (device, family, 0, &out_queue);
	return out_queue;
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_present_queue (Device const& device) {
	int present = detail::get_present_queue_index (
	    device.physical_device.phys_device, device.surface, device.queue_families);
	if (present < 0) {
		return detail::Error<QueueError>{ QueueError::present_unavailable };
	}
	return get_queue (device.device, present);
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_graphics_queue (Device const& device) {
	int graphics = detail::get_graphics_queue_index (device.queue_families);
	if (graphics < 0) {
		return detail::Error<QueueError>{ QueueError::invalid_queue_family_index };
	}
	return get_queue (device.device, graphics);
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_dedicated_compute_queue (Device const& device) {
	int compute = detail::get_dedicated_compute_queue_index (device.queue_families);
	if (compute < 0) {
		return detail::Error<QueueError>{ QueueError::compute_unavailable };
	}
	return get_queue (device.device, compute);
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_dedicated_transfer_queue (Device const& device) {
	int transfer = detail::get_dedicated_transfer_queue_index (device.queue_families);
	if (transfer < 0) {
		return detail::Error<QueueError>{ QueueError::transfer_unavailable };
	}
	return get_queue (device.device, transfer);
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_distinct_compute_queue (Device const& device) {
	int compute = detail::get_distinct_compute_queue_index (device.queue_families);
	if (compute < 0) {
		return detail::Error<QueueError>{ QueueError::compute_unavailable };
	}
	return get_queue (device.device, compute);
}
detail::Expected<VkQueue, detail::Error<QueueError>> get_distinct_transfer_queue (Device const& device) {
	int transfer = detail::get_distinct_transfer_queue_index (device.queue_families);
	if (transfer < 0) {
		return detail::Error<QueueError>{ QueueError::transfer_unavailable };
	}
	return get_queue (device.device, transfer);
}

namespace detail {
VkSurfaceFormatKHR find_surface_format (std::vector<VkSurfaceFormatKHR> const& available_formats,
    std::vector<VkSurfaceFormatKHR> const& desired_formats) {
	for (auto const& desired_format : desired_formats) {
		for (auto const& available_format : available_formats) {
			// finds the first format that is desired and available
			if (desired_format.format == available_format.format &&
			    desired_format.colorSpace == available_format.colorSpace) {
				return desired_format;
			}
		}
	}

	// use the first available one if any desired formats aren't found
	return available_formats[0];
}

VkPresentModeKHR find_present_mode (std::vector<VkPresentModeKHR> const& available_resent_modes,
    std::vector<VkPresentModeKHR> const& desired_present_modes) {
	for (auto const& desired_pm : desired_present_modes) {
		for (auto const& available_pm : available_resent_modes) {
			// finds the first present mode that is desired and available
			if (desired_pm == available_pm) return desired_pm;
		}
	}
	// only present mode required, use as a fallback
	return VK_PRESENT_MODE_FIFO_KHR;
}

template <typename T> T minimum (T a, T b) { return a < b ? a : b; }
template <typename T> T maximum (T a, T b) { return a > b ? a : b; }

VkExtent2D find_extent (
    VkSurfaceCapabilitiesKHR const& capabilities, uint32_t desired_width, uint32_t desired_height) {
	if (capabilities.currentExtent.width != UINT32_MAX) {
		return capabilities.currentExtent;
	} else {
		const int WIDTH = 800;
		const int HEIGHT = 600;
		VkExtent2D actualExtent = { WIDTH, HEIGHT };

		actualExtent.width = maximum (capabilities.minImageExtent.width,
		    minimum (capabilities.maxImageExtent.width, actualExtent.width));
		actualExtent.height = maximum (capabilities.minImageExtent.height,
		    minimum (capabilities.maxImageExtent.height, actualExtent.height));

		return actualExtent;
	}
}
} // namespace detail

const char* to_string (SwapchainError err) {
	switch (err) {
		case SwapchainError::failed_query_surface_support_details:
			return "failed_query_surface_support_details";
		case SwapchainError::failed_create_swapchain:
			return "failed_create_swapchain";
		case SwapchainError::failed_get_swapchain_images:
			return "failed_get_swapchain_images";
		case SwapchainError::failed_create_swapchain_image_views:
			return "failed_create_swapchain_image_views";
		default:
			return "";
	}
}

SwapchainBuilder::SwapchainBuilder (Device const& device) {
	info.device = device.device;
	info.physical_device = device.physical_device.phys_device;
	info.surface = device.surface;
	int present = detail::get_present_queue_index (
	    device.physical_device.phys_device, device.surface, device.queue_families);
	int graphics = detail::get_graphics_queue_index (device.queue_families);

	info.graphics_queue_index = graphics;
	info.present_queue_index = present;
}

SwapchainBuilder::SwapchainBuilder (VkPhysicalDevice const physical_device,
    VkDevice const device,
    VkSurfaceKHR const surface,
    uint32_t graphics_queue_index,
    uint32_t present_queue_index) {
	info.physical_device = physical_device;
	info.device = device;
	info.surface = surface;
	info.graphics_queue_index = graphics_queue_index;
	info.present_queue_index = present_queue_index;
}

detail::Expected<Swapchain, detail::Error<SwapchainError>> SwapchainBuilder::build () {
	if (info.desired_formats.size () == 0) use_default_format_selection ();
	if (info.desired_present_modes.size () == 0) use_default_present_mode_selection ();

	auto surface_support = detail::query_surface_support_details (info.physical_device, info.surface);
	if (!surface_support.has_value ())
		return detail::Error<SwapchainError>{ SwapchainError::failed_query_surface_support_details,
			surface_support.error ().vk_result };
	VkSurfaceFormatKHR surface_format =
	    detail::find_surface_format (surface_support.value ().formats, info.desired_formats);
	VkPresentModeKHR present_mode =
	    detail::find_present_mode (surface_support.value ().present_modes, info.desired_present_modes);
	VkExtent2D extent = detail::find_extent (
	    surface_support.value ().capabilities, info.desired_width, info.desired_height);

	uint32_t imageCount = surface_support.value ().capabilities.minImageCount + 1;
	if (surface_support.value ().capabilities.maxImageCount > 0 &&
	    imageCount > surface_support.value ().capabilities.maxImageCount) {
		imageCount = surface_support.value ().capabilities.maxImageCount;
	}

	VkSwapchainCreateInfoKHR swapchain_create_info = {};
	swapchain_create_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	detail::setup_pNext_chain (swapchain_create_info, info.pNext_elements);
	swapchain_create_info.surface = info.surface;
	swapchain_create_info.minImageCount = imageCount;
	swapchain_create_info.imageFormat = surface_format.format;
	swapchain_create_info.imageColorSpace = surface_format.colorSpace;
	swapchain_create_info.imageExtent = extent;
	swapchain_create_info.imageArrayLayers = 1;
	swapchain_create_info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

	uint32_t queue_family_indices[] = { info.graphics_queue_index, info.present_queue_index };

	if (info.graphics_queue_index != info.present_queue_index) {
		swapchain_create_info.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
		swapchain_create_info.queueFamilyIndexCount = 2;
		swapchain_create_info.pQueueFamilyIndices = queue_family_indices;
	} else {
		swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	}

	swapchain_create_info.preTransform = surface_support.value ().capabilities.currentTransform;
	swapchain_create_info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	swapchain_create_info.presentMode = present_mode;
	swapchain_create_info.clipped = VK_TRUE;
	swapchain_create_info.oldSwapchain = info.old_swapchain;
	Swapchain swapchain{};
	VkResult res = vkCreateSwapchainKHR (info.device, &swapchain_create_info, nullptr, &swapchain.swapchain);
	if (res != VK_SUCCESS) {
		return detail::Error<SwapchainError>{ SwapchainError::failed_create_swapchain, res };
	}
	swapchain.device = info.device;
	swapchain.image_format = surface_format.format;
	swapchain.extent = extent;

	auto images = get_swapchain_images (swapchain);
	swapchain.image_count = images.value ().size ();
	return swapchain;
} // namespace vkb
detail::Expected<Swapchain, detail::Error<SwapchainError>> SwapchainBuilder::recreate (Swapchain const& swapchain) {
	info.old_swapchain = swapchain.swapchain;
	return build ();
}
detail::Expected<std::vector<VkImage>, detail::Error<SwapchainError>> get_swapchain_images (
    Swapchain const& swapchain) {
	auto swapchain_images =
	    detail::get_vector<VkImage> (vkGetSwapchainImagesKHR, swapchain.device, swapchain.swapchain);
	if (!swapchain_images) {
		return detail::Error<SwapchainError>{ SwapchainError::failed_get_swapchain_images,
			swapchain_images.error () };
	}
	return swapchain_images.value ();
}

detail::Expected<std::vector<VkImageView>, detail::Error<SwapchainError>>
get_swapchain_image_views (Swapchain const& swapchain, std::vector<VkImage> const& images) {
	std::vector<VkImageView> views{ swapchain.image_count };

	for (size_t i = 0; i < swapchain.image_count; i++) {
		VkImageViewCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		createInfo.image = images[i];
		createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		createInfo.format = swapchain.image_format;
		createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		createInfo.subresourceRange.baseMipLevel = 0;
		createInfo.subresourceRange.levelCount = 1;
		createInfo.subresourceRange.baseArrayLayer = 0;
		createInfo.subresourceRange.layerCount = 1;

		VkResult res = vkCreateImageView (swapchain.device, &createInfo, nullptr, &views[i]);
		if (res != VK_SUCCESS)
			return detail::Error<SwapchainError>{ SwapchainError::failed_create_swapchain_image_views, res };
	}
	return views;
}


void destroy_swapchain (Swapchain const& swapchain) {
	if (swapchain.device != VK_NULL_HANDLE && swapchain.swapchain != VK_NULL_HANDLE)
		vkDestroySwapchainKHR (swapchain.device, swapchain.swapchain, nullptr);
}

SwapchainBuilder& SwapchainBuilder::set_desired_format (VkSurfaceFormatKHR format) {
	info.desired_formats.insert (info.desired_formats.begin (), format);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::add_fallback_format (VkSurfaceFormatKHR format) {
	info.desired_formats.push_back (format);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::use_default_format_selection () {
	info.desired_formats.push_back ({ VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR });
	info.desired_formats.push_back ({ VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR });
	return *this;
}

SwapchainBuilder& SwapchainBuilder::set_desired_present_mode (VkPresentModeKHR present_mode) {
	info.desired_present_modes.insert (info.desired_present_modes.begin (), present_mode);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::add_fallback_present_mode (VkPresentModeKHR present_mode) {
	info.desired_present_modes.push_back (present_mode);
	return *this;
}
SwapchainBuilder& SwapchainBuilder::use_default_present_mode_selection () {
	info.desired_present_modes.push_back (VK_PRESENT_MODE_MAILBOX_KHR);
	info.desired_present_modes.push_back (VK_PRESENT_MODE_FIFO_KHR);
	return *this;
}


} // namespace vkb