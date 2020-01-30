#include "Instance.h"

#include <stdio.h>
#include <string.h>

namespace vkbs
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
	if (!available_layers.has_value ()) return false; // maybe report error?
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
		extensions.push_back (VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	if (!info.headless_context)
	{
		extensions.push_back (VK_KHR_SURFACE_EXTENSION_NAME);
#if defined(_WIN32)
		extentions.push_back (VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
		extentions.push_back (VK_KHR_ANDROID_SURFACE_EXTENSION_NAME);
#elif defined(_DIRECT2DISPLAY)
		extentions.push_back (VK_KHR_DISPLAY_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
		extentions.push_back (VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_XCB_KHR)
		extentions.push_back (VK_KHR_XCB_SURFACE_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_X11_HKR)
		extentions.push_back (VK_KHR_X11_SURFACE_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_IOS_MVK)
		extentions.push_back (VK_MVK_IOS_SURFACE_EXTENSION_NAME);
#elif defined(VK_USE_PLATFORM_MACOS_MVK)
		extentions.push_back (VK_MVK_MACOS_SURFACE_EXTENSION_NAME);
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
		return detail::Error<VkResult>{ VK_ERROR_LAYER_NOT_PRESENT, "Not all layers supported!" };
	}

	VkBaseOutStructure pNext_chain;
	pNext_chain.pNext = (VkBaseOutStructure*)info.pNext;
	if (info.use_debug_messenger)
	{
		VkDebugUtilsMessengerCreateInfoEXT messengerCreateInfo = {};
		messengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		messengerCreateInfo.messageSeverity = info.debug_message_severity;
		messengerCreateInfo.messageType = info.debug_message_type;
		messengerCreateInfo.pfnUserCallback = info.debug_callback;
		detail::pNext_append (&pNext_chain, &messengerCreateInfo);
	}

	if (info.enabled_validation_features.size () != 0 || info.disabled_validation_features.size ())
	{
		VkValidationFeaturesEXT features{};
		features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
		features.pNext = nullptr;
		features.enabledValidationFeatureCount = info.enabled_validation_features.size ();
		features.pEnabledValidationFeatures = info.enabled_validation_features.data ();
		features.disabledValidationFeatureCount = info.disabled_validation_features.size ();
		features.pDisabledValidationFeatures = info.disabled_validation_features.data ();
		detail::pNext_append (&pNext_chain, &features);
	}

	if (info.disabled_validation_checks.size () != 0)
	{
		VkValidationFlagsEXT checks{};
		checks.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
		checks.pNext = nullptr;
		checks.disabledValidationCheckCount = info.disabled_validation_checks.size ();
		checks.pDisabledValidationChecks = info.disabled_validation_checks.data ();
		detail::pNext_append (&pNext_chain, &checks);
	}

	VkInstanceCreateInfo instance_create_info = {};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pNext = pNext_chain.pNext;
	instance_create_info.flags = info.flags;
	instance_create_info.pApplicationInfo = &app_info;
	instance_create_info.enabledExtensionCount = static_cast<uint32_t> (extensions.size ());
	instance_create_info.ppEnabledExtensionNames = extensions.data ();
	instance_create_info.enabledLayerCount = static_cast<uint32_t> (layers.size ());
	instance_create_info.ppEnabledLayerNames = layers.data ();

	Instance instance;
	VkResult res = vkCreateInstance (&instance_create_info, info.allocator, &instance.instance);
	if (res != VK_SUCCESS) return detail::Error<VkResult>{ res, "Failed to create instance" };

	res = detail::create_debug_utils_messenger (instance.instance,
	    info.debug_callback,
	    info.debug_message_severity,
	    info.debug_message_type,
	    info.allocator,
	    &instance.debug_messenger);
	if (res != VK_SUCCESS)
		return detail::Error<VkResult>{ res, "Failed to create setup debug callback" };

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

} // namespace vkbs