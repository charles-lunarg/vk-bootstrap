#pragma once

#include "Util.h"

namespace vkbs
{

const char* DebugMessageSeverity (VkDebugUtilsMessageSeverityFlagBitsEXT s);
const char* DebugMessageType (VkDebugUtilsMessageTypeFlagsEXT s);

namespace detail
{
VkResult create_debug_utils_messenger (VkInstance instance,
    PFN_vkDebugUtilsMessengerCallbackEXT debug_callback,
    VkDebugUtilsMessageSeverityFlagsEXT severity,
    VkDebugUtilsMessageTypeFlagsEXT type,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger);

void destroy_debug_utils_messenger (
    VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

static VKAPI_ATTR VkBool32 VKAPI_CALL default_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);

bool check_layers_supported (std::vector<const char*> layer_names);

} // namespace detail

struct Instance
{
	VkInstance instance = VK_NULL_HANDLE;
	VkAllocationCallbacks* allocator = VK_NULL_HANDLE;
	VkDebugUtilsMessengerEXT debug_messenger = VK_NULL_HANDLE;
	bool headless = false;
	bool validation_enabled = false;
	bool debug_callback_enabled = false;
};

void destroy_instance (Instance instance); // release instance resources

class InstanceBuilder
{
	public:
	detail::Expected<Instance, VkResult> build (); // use builder pattern

	InstanceBuilder& set_app_name (std::string app_name);
	InstanceBuilder& set_engine_name (std::string engine_name);

	InstanceBuilder& set_app_version (uint32_t major, uint32_t minor, uint32_t patch);
	InstanceBuilder& set_engine_version (uint32_t major, uint32_t minor, uint32_t patch);
	InstanceBuilder& set_api_version (uint32_t major, uint32_t minor, uint32_t patch);

	InstanceBuilder& add_layer (std::string app_name);
	InstanceBuilder& add_extension (std::string app_name);

	InstanceBuilder& setup_validation_layers (bool enable_validation = true);
	InstanceBuilder& set_headless (bool headless = false);

	InstanceBuilder& set_default_debug_messenger ();
	InstanceBuilder& set_debug_callback (PFN_vkDebugUtilsMessengerCallbackEXT callback);
	InstanceBuilder& set_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	InstanceBuilder& add_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	InstanceBuilder& set_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);
	InstanceBuilder& add_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);

	InstanceBuilder& add_validation_disable (VkValidationCheckEXT check);
	InstanceBuilder& add_validation_feature_enable (VkValidationFeatureEnableEXT enable);
	InstanceBuilder& add_validation_feature_disable (VkValidationFeatureDisableEXT disable);

	InstanceBuilder& set_allocator_callback (VkAllocationCallbacks* allocator);

	private:
	struct InstanceInfo
	{
		// VkApplicationInfo
		std::string app_name;
		std::string engine_name;
		uint32_t application_version = 0;
		uint32_t engine_version = 0;
		uint32_t api_version = VK_MAKE_VERSION (1, 0, 0);

		// VkInstanceCreateInfo
		std::vector<std::string> layers;
		std::vector<std::string> extensions;
		VkInstanceCreateFlags flags = 0;
		void* pNext = nullptr;
		VkAllocationCallbacks* allocator = nullptr;

		// debug callback
		PFN_vkDebugUtilsMessengerCallbackEXT debug_callback = nullptr;
		VkDebugUtilsMessageSeverityFlagsEXT debug_message_severity =
		    VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		VkDebugUtilsMessageTypeFlagsEXT debug_message_type =
		    VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
		    VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

		// validation features
		std::vector<VkValidationCheckEXT> disabled_validation_checks;
		std::vector<VkValidationFeatureEnableEXT> enabled_validation_features;
		std::vector<VkValidationFeatureDisableEXT> disabled_validation_features;

		// booleans
		bool ignore_non_critical_issues = true;
		bool enable_validation_layers = false;
		bool use_debug_messenger = false;
		bool headless_context = false;
	} info;
};

} // namespace vkbs