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
	detail::Expected<Instance, detail::Error<InstanceError>> build (); // use builder pattern

	InstanceBuilder& set_app_name (const char* app_name);
	InstanceBuilder& set_engine_name (const char* engine_name);

	InstanceBuilder& set_app_version (uint32_t major, uint32_t minor, uint32_t patch);
	InstanceBuilder& set_engine_version (uint32_t major, uint32_t minor, uint32_t patch);
	InstanceBuilder& set_api_version (uint32_t major, uint32_t minor, uint32_t patch);

	InstanceBuilder& add_layer (const char* app_name);
	InstanceBuilder& add_extension (const char* app_name);

	bool check_and_add_layer (const char* app_name);
	bool check_and_add_extension (const char* app_name);

	InstanceBuilder& setup_validation_layers (bool enable_validation = true);
	InstanceBuilder& set_headless (bool headless = false);

	bool check_and_setup_validation_layers (bool enable_validation = true);

	InstanceBuilder& set_default_debug_messenger ();
	InstanceBuilder& set_debug_callback (PFN_vkDebugUtilsMessengerCallbackEXT callback);
	InstanceBuilder& set_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	InstanceBuilder& add_debug_messenger_severity (VkDebugUtilsMessageSeverityFlagsEXT severity);
	InstanceBuilder& set_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);
	InstanceBuilder& add_debug_messenger_type (VkDebugUtilsMessageTypeFlagsEXT type);

	InstanceBuilder& add_validation_disable (VkValidationCheckEXT check);
	InstanceBuilder& add_validation_feature_enable (VkValidationFeatureEnableEXT enable);
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
	friend class PhysicalDeviceSelector;
	friend class DeviceBuilder;
};

struct PhysicalDeviceSelector {
	public:
	PhysicalDeviceSelector (Instance const& instance);

	detail::Expected<PhysicalDevice, detail::Error<PhysicalDeviceError>> select ();

	PhysicalDeviceSelector& set_surface (VkSurfaceKHR instance);

	enum PreferredDeviceType { discrete, integrated, virtual_gpu, cpu, dont_care };
	PhysicalDeviceSelector& prefer_gpu_device_type (PreferredDeviceType type = PreferredDeviceType::discrete);
	PhysicalDeviceSelector& allow_fallback_gpu (bool fallback = true);

	PhysicalDeviceSelector& require_present (bool require = true);
	PhysicalDeviceSelector& require_dedicated_transfer_queue ();
	PhysicalDeviceSelector& require_dedicated_compute_queue ();

	PhysicalDeviceSelector& required_device_memory_size (VkDeviceSize size);
	PhysicalDeviceSelector& desired_device_memory_size (VkDeviceSize size);

	PhysicalDeviceSelector& add_required_extension (const char* extension);
	PhysicalDeviceSelector& add_required_extensions (std::vector<const char*> extensions);

	PhysicalDeviceSelector& add_desired_extension (const char* extension);
	PhysicalDeviceSelector& add_desired_extensions (std::vector<const char*> extensions);

	PhysicalDeviceSelector& set_desired_version (uint32_t major, uint32_t minor);
	PhysicalDeviceSelector& set_minimum_version (uint32_t major = 1, uint32_t minor = 0);

	PhysicalDeviceSelector& set_required_features (VkPhysicalDeviceFeatures features);

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

	template <typename T> DeviceBuilder& add_pNext (T* structure);

	DeviceBuilder& request_dedicated_compute_queue (bool compute = true);
	DeviceBuilder& request_dedicated_transfer_queue (bool transfer = true);

	/* For advanced users */
	DeviceBuilder& custom_queue_setup (std::vector<CustomQueueDescription> queue_descriptions);

	private:
	struct DeviceInfo {
		VkDeviceCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		PhysicalDevice physical_device;
		std::vector<const char*> extensions;
		std::vector<VkQueueFamilyProperties> queue_families;
		std::vector<CustomQueueDescription> queue_descriptions;
		bool request_compute_queue = false;
		bool request_transfer_queue = false;
	} info;
};

// ---- Getting Queues ---- //

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