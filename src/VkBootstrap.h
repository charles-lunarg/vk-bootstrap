#pragma once

#include <cassert>

#include <vector>

#include <vulkan/vulkan.h>

namespace vkb {

namespace detail {
template <typename ErrorType> struct Error {
	explicit Error (ErrorType type, VkResult result = VK_SUCCESS)
	: type (type), vk_result (result) {}

	ErrorType type;
	VkResult vk_result; // optional error value if a vulkan call failed
};

template <typename E, typename U> class Expected {
	public:
	Expected (const E& expect) : m_expect{ expect }, m_init{ true } {}
	Expected (E&& expect) : m_expect{ std::move (expect) }, m_init{ true } {}
	Expected (const U& error) : m_error{ error }, m_init{ false } {}
	Expected (U&& error) : m_error{ std::move (error) }, m_init{ false } {}
	~Expected () { destroy (); }
	Expected (Expected const& expected) : m_init (expected.m_init) {
		if (m_init)
			new (&m_expect) E{ expected.m_expect };
		else
			new (&m_error) U{ expected.m_error };
	}
	Expected (Expected&& expected) : m_init (expected.m_init) {
		if (m_init)
			new (&m_expect) E{ std::move (expected.m_expect) };
		else
			new (&m_error) U{ std::move (expected.m_error) };
		expected.destroy ();
	}

	Expected& operator= (const E& expect) {
		destroy ();
		m_init = true;
		new (&m_expect) E{ expect };
		return *this;
	}
	Expected& operator= (E&& expect) {
		destroy ();
		m_init = true;
		new (&m_expect) E{ std::move (expect) };
		return *this;
	}
	Expected& operator= (const U& error) {
		destroy ();
		m_init = false;
		new (&m_error) U{ error };
		return *this;
	}
	Expected& operator= (U&& error) {
		destroy ();
		m_init = false;
		new (&m_error) U{ std::move (error) };
		return *this;
	}
	// clang-format off
	const E* operator-> () const { assert (m_init); return &m_expect; }
	E*       operator-> ()       { assert (m_init); return &m_expect; }
	const E& operator* () const& { assert (m_init);	return m_expect; }
	E&       operator* () &      { assert (m_init); return m_expect; }
	E&&      operator* () &&	 { assert (m_init); return std::move (m_expect); }
	const E&  value () const&    { assert (m_init); return m_expect; }
	E&        value () &         { assert (m_init); return m_expect; }
	const E&& value () const&&   { assert (m_init); return std::move (m_expect); }
	E&&       value () &&        { assert (m_init); return std::move (m_expect); }
	const U&  error () const&  { assert (!m_init); return m_error; }
	U&        error () &       { assert (!m_init); return m_error; }
	const U&& error () const&& { assert (!m_init); return std::move (m_error); }
	U&&       error () &&      { assert (!m_init); return std::move (m_error); }
	// clang-format on
	bool has_value () const { return m_init; }
	explicit operator bool () const { return m_init; }

	private:
	void destroy () {
		if (m_init)
			m_expect.~E ();
		else
			m_error.~U ();
	}
	union {
		E m_expect;
		U m_error;
	};
	bool m_init;
};

/* TODO implement operator == and operator != as friend or global */
} // namespace detail

enum class InstanceError {
	failed_create_instance,
	failed_create_debug_messenger,
	requested_layers_not_present,
	requested_extensions_not_present
};

class InstanceBuilder;
class PhysicalDeviceSelector;

struct Instance {
	VkInstance instance = VK_NULL_HANDLE;
	VkDebugUtilsMessengerEXT debug_messenger = VK_NULL_HANDLE;

	private:
	bool headless = false;

	friend class InstanceBuilder;
	friend class PhysicalDeviceSelector;
};

void destroy_instance (Instance instance); // release instance resources

// TODO utility function for users to check if layer/extension is supported

class InstanceBuilder {
	public:
	InstanceBuilder (); // automatically gets available layers and extensions.

	detail::Expected<Instance, detail::Error<InstanceError>> build ();

	// Sets the name of the application. Defaults to "" if none is provided.
	InstanceBuilder& set_app_name (const char* app_name);
	// Sets the name of the engine. Defaults to "" if none is provided.
	InstanceBuilder& set_engine_name (const char* engine_name);
	// Sets the (major, minor, patch) version of the application.
	InstanceBuilder& set_app_version (uint32_t major, uint32_t minor, uint32_t patch);
	// Sets the (major, minor, patch) version of the engine.
	InstanceBuilder& set_engine_version (uint32_t major, uint32_t minor, uint32_t patch);
	// Sets the vulkan API version to use.
	InstanceBuilder& set_api_version (uint32_t major, uint32_t minor, uint32_t patch);


	// Loads the specified layer if it is available.
	InstanceBuilder& check_and_add_layer (const char* layer_name);
	// Adds a layer to be enabled. Will fail to create an instance if the layer isn't available.
	InstanceBuilder& must_enable_layer (const char* layer_name);
	// Enables the specified extension if it is available.
	InstanceBuilder& check_and_add_extension (const char* extension_name);
	// Adds an extension to be enabled. Will fail to create an instance if the extension isn't available.
	InstanceBuilder& must_enable_extension (const char* extension_name);

	// Headless Mode does not load the required extensions for presentation. Defaults to false.
	InstanceBuilder& set_headless (bool headless = false);
	// Checks if the validation layers are available and loads them if they are.
	InstanceBuilder& check_and_setup_validation_layers (bool enable_validation = true);
	// Enables the validation layers. Will fail to create an instance if the validation layers aren't available.
	InstanceBuilder& must_enable_validation_layers (bool enable_validation = true);

	// Use a default debug callback that prints to standard out.
	InstanceBuilder& set_default_debug_messenger ();
	// Provide a user defined debug callback.
	InstanceBuilder& set_debug_callback (PFN_vkDebugUtilsMessengerCallbackEXT callback);
	// Set what message severity is needed to trigger the callback.
	InstanceBuilder& set_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	// Add a message severity to the list that triggers the callback.
	InstanceBuilder& add_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	// Set what message type triggers the callback.
	InstanceBuilder& set_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);
	// Add a message type to the list of that triggers the callback.
	InstanceBuilder& add_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);

	// Disable some validation checks.
	// Checks: All, and Shaders
	InstanceBuilder& add_validation_disable (VkValidationCheckEXT check);

	// Enables optional parts of the validation layers.
	// Parts: best practices, gpu assisted, and gpu assisted reserve binding slot.
	InstanceBuilder& add_validation_feature_enable (VkValidationFeatureEnableEXT enable);

	// Disables sections of the validation layers.
	// Options: All, shaders, thread safety, api parameters, object lifetimes, core checks, and unique handles.
	InstanceBuilder& add_validation_feature_disable (VkValidationFeatureDisableEXT disable);

	private:
	struct InstanceInfo {
		// VkApplicationInfo
		const char* app_name = nullptr;
		const char* engine_name = nullptr;
		uint32_t application_version = 0;
		uint32_t engine_version = 0;
		uint32_t api_version = VK_MAKE_VERSION (1, 0, 0);

		// VkInstanceCreateInfo
		std::vector<const char*> layers;
		std::vector<const char*> extensions;
		VkInstanceCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_elements;

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

	struct SystemInfo {
		std::vector<VkLayerProperties> available_layers;
		std::vector<VkExtensionProperties> available_extensions;
	} system;
};

const char* to_string_message_severity (VkDebugUtilsMessageSeverityFlagBitsEXT s);
const char* to_string_message_type (VkDebugUtilsMessageTypeFlagsEXT s);

VkResult create_debug_utils_messenger (VkInstance instance,
    PFN_vkDebugUtilsMessengerCallbackEXT debug_callback,
    VkDebugUtilsMessageSeverityFlagsEXT severity,
    VkDebugUtilsMessageTypeFlagsEXT type,
    VkDebugUtilsMessengerEXT* pDebugMessenger);

void destroy_debug_utils_messenger (VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger);

static VKAPI_ATTR VkBool32 VKAPI_CALL default_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);

// ---- Physical Device ---- //
enum class PhysicalDeviceError {
	failed_enumerate_physical_devices,
	no_physical_devices_found,
	no_suitable_device,

};

class PhysicalDeviceSelector;
class DeviceBuilder;

struct PhysicalDevice {
	VkPhysicalDevice phys_device = VK_NULL_HANDLE;
	VkSurfaceKHR surface = VK_NULL_HANDLE;

	private:
	VkPhysicalDeviceFeatures features{};
	std::vector<const char*> extensions_to_enable;
	std::vector<VkQueueFamilyProperties> queue_families;
	bool dedicated_compute = false;
	bool distinct_compute = false;
	bool dedicated_transfer = false;
	bool distinct_transfer = false;
	friend class PhysicalDeviceSelector;
	friend class DeviceBuilder;
};

enum class PreferredDeviceType { discrete, integrated, virtual_gpu, cpu, dont_care };
class PhysicalDeviceSelector {
	public:
	// Requires a vkb::Instance to construct, needed to pass instance creation info.
	PhysicalDeviceSelector (Instance const& instance);

	detail::Expected<PhysicalDevice, detail::Error<PhysicalDeviceError>> select ();

	// Set the surface in which the physical device should render to.
	PhysicalDeviceSelector& set_surface (VkSurfaceKHR instance);
	// Set the desired physical device type to select. Defaults to PreferredDeviceType::discrete.
	PhysicalDeviceSelector& prefer_gpu_device_type (PreferredDeviceType type = PreferredDeviceType::discrete);
	// Allow fallback to a device type that isn't the preferred physical device type. Defaults to true.
	PhysicalDeviceSelector& allow_fallback_gpu (bool fallback = true);

	// Require that a physical device supports presentation. Defaults to true.
	PhysicalDeviceSelector& require_present (bool require = true);
	// Require a queue family that supports compute operations but not graphics nor transfer.
	PhysicalDeviceSelector& require_dedicated_compute_queue ();
	// Require a queue family that supports transfer operations but not graphics nor compute.
	PhysicalDeviceSelector& require_dedicated_transfer_queue ();
	// Require a queue family that supports compute operations but not graphics.
	PhysicalDeviceSelector& require_distinct_compute_queue ();
	// Require a queue family that supports transfer operations but not graphics.
	PhysicalDeviceSelector& require_distinct_transfer_queue ();

	// Require a memory heap from VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT with `size` memory available.
	PhysicalDeviceSelector& required_device_memory_size (VkDeviceSize size);
	// Prefer a memory heap from VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT with `size` memory available.
	PhysicalDeviceSelector& desired_device_memory_size (VkDeviceSize size);

	// Require a physical device which supports a specific extension.
	PhysicalDeviceSelector& add_required_extension (const char* extension);
	// Require a physical device which supports a set of extensions.
	PhysicalDeviceSelector& add_required_extensions (std::vector<const char*> extensions);

	// Prefer a physical device which supports a specific extension.
	PhysicalDeviceSelector& add_desired_extension (const char* extension);
	// Prefer a physical device which supports a set of extensions.
	PhysicalDeviceSelector& add_desired_extensions (std::vector<const char*> extensions);

	// Prefer a physical device that supports a (major, minor) version of vulkan.
	PhysicalDeviceSelector& set_desired_version (uint32_t major, uint32_t minor);
	// Require a physical device that supports a (major, minor) version of vulkan. Default is Vulkan 1.0.
	PhysicalDeviceSelector& set_minimum_version (uint32_t major = 1, uint32_t minor = 0);

	// Require a physical device which supports the features in VkPhysicalDeviceFeatures.
	PhysicalDeviceSelector& set_required_features (VkPhysicalDeviceFeatures features);

	// Ignore all criteria and choose the first physical device that is available.
	// Only use when: The first gpu in the list may be set by global user preferences and an application may wish to respect it.
	PhysicalDeviceSelector& select_first_device_unconditionally (bool unconditionally = true);

	private:
	struct SystemInfo {
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		bool headless = false;
	} system_info;

	struct PhysicalDeviceDesc {
		VkPhysicalDevice phys_device = VK_NULL_HANDLE;
		std::vector<VkQueueFamilyProperties> queue_families;

		VkPhysicalDeviceFeatures device_features;
		VkPhysicalDeviceProperties device_properties;
		VkPhysicalDeviceMemoryProperties mem_properties;
	};
	PhysicalDeviceDesc populate_device_details (VkPhysicalDevice phys_device);

	struct SelectionCriteria {
		PreferredDeviceType preferred_type = PreferredDeviceType::discrete;
		bool allow_fallback = true;
		bool require_present = true;
		bool require_dedicated_transfer_queue = false;
		bool require_dedicated_compute_queue = false;
		bool require_distinct_transfer_queue = false;
		bool require_distinct_compute_queue = false;
		VkDeviceSize required_mem_size = 0;
		VkDeviceSize desired_mem_size = 0;

		std::vector<const char*> required_extensions;
		std::vector<const char*> desired_extensions;

		uint32_t required_version = VK_MAKE_VERSION (1, 0, 0);
		uint32_t desired_version = VK_MAKE_VERSION (1, 0, 0);

		VkPhysicalDeviceFeatures required_features{};

		bool use_first_gpu_unconditionally = false;
	} criteria;

	enum class Suitable { yes, partial, no };

	Suitable is_device_suitable (PhysicalDeviceDesc phys_device);
};

// ---- Device ---- //
enum class DeviceError {
	failed_create_device,
};

struct Device {
	VkDevice device = VK_NULL_HANDLE;
	PhysicalDevice physical_device;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
	std::vector<VkQueueFamilyProperties> queue_families;
};

void destroy_device (Device device);

struct CustomQueueDescription {
	CustomQueueDescription (uint32_t index, uint32_t count, std::vector<float> priorities)
	: index (index), count (count), priorities (priorities) {}
	uint32_t index = 0;
	uint32_t count = 0;
	std::vector<float> priorities;
};

class DeviceBuilder {
	public:
	DeviceBuilder (PhysicalDevice physical_device);

	detail::Expected<Device, detail::Error<DeviceError>> build ();

	bool has_dedicated_compute_queue ();
	bool has_distinct_compute_queue ();
	bool has_dedicated_transfer_queue ();
	bool has_distinct_transfer_queue ();

	// Require a queue family that supports compute operations but not graphics nor transfer.
	DeviceBuilder& request_dedicated_compute_queue (bool compute = true);
	// Require a queue family that supports transfer operations but not graphics nor compute.
	DeviceBuilder& request_dedicated_transfer_queue (bool transfer = true);

	// Require a queue family that supports compute operations but not graphics.
	DeviceBuilder& request_distinct_compute_queue (bool compute = true);
	// Require a queue family that supports transfer operations but not graphics.
	DeviceBuilder& request_distinct_transfer_queue (bool transfer = true);

	// For Advanced Users: specify the exact list of VkDeviceQueueCreateInfo's needed for the application.
	// If a custom queue setup is provided, getting the queues and queue indexes is up to the application.
	DeviceBuilder& custom_queue_setup (std::vector<CustomQueueDescription> queue_descriptions);

	// For Advanced Users: Add a structure to the pNext chain of VkDeviceCreateInfo.
	// The structure must be valid when DeviceBuilder::build() is called.
	template <typename T> DeviceBuilder& add_pNext (T* structure);

	private:
	struct DeviceInfo {
		VkDeviceCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		PhysicalDevice physical_device;
		std::vector<const char*> extensions;
		std::vector<VkQueueFamilyProperties> queue_families;
		std::vector<CustomQueueDescription> queue_descriptions;
		bool dedicated_compute = false;
		bool distinct_compute = false;
		bool dedicated_transfer = false;
		bool distinct_transfer = false;
	} info;
};

// ---- Queues ---- //

enum class QueueError {
	present_unavailable,
	compute_unavailable,
	transfer_unavailable,
	queue_index_out_of_range,
	invalid_queue_family_index
};

detail::Expected<uint32_t, detail::Error<QueueError>> get_present_queue_index (Device const& device);
detail::Expected<uint32_t, detail::Error<QueueError>> get_graphics_queue_index (Device const& device);
detail::Expected<uint32_t, detail::Error<QueueError>> get_compute_queue_index (Device const& device);
detail::Expected<uint32_t, detail::Error<QueueError>> get_transfer_queue_index (Device const& device);

detail::Expected<VkQueue, detail::Error<QueueError>> get_present_queue (Device const& device);
detail::Expected<VkQueue, detail::Error<QueueError>> get_graphics_queue (Device const& device);
detail::Expected<VkQueue, detail::Error<QueueError>> get_compute_queue (Device const& device);
detail::Expected<VkQueue, detail::Error<QueueError>> get_transfer_queue (Device const& device);


// ---- Swapchain ---- //

enum class SwapchainError {
	failed_query_surface_support_details,
	failed_create_swapchain,
	failed_get_swapchain_images,
	failed_create_swapchain_image_views,
};

struct Swapchain {
	VkDevice device = VK_NULL_HANDLE;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	uint32_t image_count = 0;
	VkFormat image_format = VK_FORMAT_UNDEFINED;
	VkExtent2D extent = { 0, 0 };
};

void destroy_swapchain (Swapchain const& swapchain);

detail::Expected<std::vector<VkImage>, detail::Error<SwapchainError>> get_swapchain_images (
    Swapchain const& swapchain);
detail::Expected<std::vector<VkImageView>, detail::Error<SwapchainError>>
get_swapchain_image_views (Swapchain const& swapchain, std::vector<VkImage> const& images);

class SwapchainBuilder {
	public:
	SwapchainBuilder (Device const& device);
	SwapchainBuilder (VkPhysicalDevice const physical_device,
	    VkDevice const device,
	    VkSurfaceKHR const surface,
	    uint32_t graphics_queue_index,
	    uint32_t present_queue_index);

	detail::Expected<Swapchain, detail::Error<SwapchainError>> build ();
	detail::Expected<Swapchain, detail::Error<SwapchainError>> recreate (Swapchain const& swapchain);

	SwapchainBuilder& set_desired_format (VkSurfaceFormatKHR format);
	SwapchainBuilder& add_fallback_format (VkSurfaceFormatKHR format);
	SwapchainBuilder& use_default_format_selection ();

	SwapchainBuilder& set_desired_present_mode (VkPresentModeKHR present_mode);
	SwapchainBuilder& add_fallback_present_mode (VkPresentModeKHR present_mode);
	SwapchainBuilder& use_default_present_mode_selection ();



	private:
	struct SwapchainInfo {
		VkPhysicalDevice physical_device = VK_NULL_HANDLE;
		VkDevice device = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		VkSwapchainKHR old_swapchain = VK_NULL_HANDLE;
		std::vector<VkSurfaceFormatKHR> desired_formats;
		std::vector<VkPresentModeKHR> desired_present_modes;
		uint32_t desired_width = 256;
		uint32_t desired_height = 256;
		std::vector<VkBaseOutStructure*> pNext_elements;
		uint32_t graphics_queue_index = 0;
		uint32_t present_queue_index = 0;
	} info;
};

} // namespace vkb