#pragma once

#include <cassert>

#include <array>
#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace vkb {

namespace detail {

enum class BootstrapErrorType : uint32_t {

};

struct Error {
	VkResult error_code;
	const char* msg;
};
template <typename E, typename U> class Expected {
	public:
	Expected (const E& expect) : m_expect{ expect }, m_init{ true } {}
	Expected (E&& expect) : m_expect{ std::move (expect) }, m_init{ true } {}
	Expected (const Error& error) : m_error{ error }, m_init{ false } {}
	Expected (Error&& error) : m_error{ std::move (error) }, m_init{ false } {}
	~Expected () { destroy (); }
	Expected (Expected const& expected) : m_init (expected.m_init) {
		if (m_init)
			new (&m_expect) E{ expected.m_expect };
		else
			new (&m_error) Error{ expected.m_error };
	}
	Expected (Expected&& expected) : m_init (expected.m_init) {
		if (m_init)
			new (&m_expect) E{ std::move (expected.m_expect) };
		else
			new (&m_error) Error{ std::move (expected.m_error) };
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
	Expected& operator= (const Error& error) {
		destroy ();
		m_init = false;
		new (&m_error) Error{ error };
		return *this;
	}
	Expected& operator= (Error&& error) {
		destroy ();
		m_init = false;
		new (&m_error) Error{ std::move (error) };
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
	const Error&  error () const&  { assert (!m_init); return m_error; }
	Error&        error () &       { assert (!m_init); return m_error; }
	const Error&& error () const&& { assert (!m_init); return std::move (m_error); }
	Error&&       error () &&      { assert (!m_init); return std::move (m_error); }
	// clang-format on
	bool has_value () const { return m_init; }
	explicit operator bool () const { return m_init; }

	private:
	void destroy () {
		if (m_init)
			m_expect.~E ();
		else
			m_error.~Error ();
	}
	union {
		E m_expect;
		Error m_error;
	};
	bool m_init;
};

/* TODO implement operator == and operator != as friend or global */

} // namespace detail

class InstanceBuilder;
class PhysicalDeviceSelector;

struct Instance {
	VkInstance instance = VK_NULL_HANDLE;
	VkDebugUtilsMessengerEXT debug_messenger = VK_NULL_HANDLE;

	private:
	bool headless = false;
	bool validation_enabled = false;
	bool debug_callback_enabled = false;

	friend class InstanceBuilder;
	friend class PhysicalDeviceSelector;
};

void destroy_instance (Instance instance); // release instance resources

class InstanceBuilder {
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

	private:
	struct InstanceInfo {
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

struct QueueFamilies {
	int graphics = -1;
	int present = -1;
	int transfer = -1;
	int compute = -1;
	int sparse = -1;
	uint32_t count_graphics = 0;
	uint32_t count_transfer = 0;
	uint32_t count_compute = 0;
	uint32_t count_sparse = 0;
};

QueueFamilies find_queue_families (VkPhysicalDevice phys_device, VkSurfaceKHR surface);

// ---- Physical Device ---- //

struct PhysicalDevice {
	VkPhysicalDevice phys_device = VK_NULL_HANDLE;
	VkSurfaceKHR surface = VK_NULL_HANDLE;

	VkPhysicalDeviceFeatures features{};
	VkPhysicalDeviceProperties properties{};
	VkPhysicalDeviceMemoryProperties memory_properties{};

	QueueFamilies queue_family_properties;

	std::vector<std::string> extensions_to_enable;
};

struct PhysicalDeviceSelector {
	public:
	PhysicalDeviceSelector (Instance const& instance);

	detail::Expected<PhysicalDevice, VkResult> select ();

	PhysicalDeviceSelector& set_surface (VkSurfaceKHR instance);

	PhysicalDeviceSelector& prefer_discrete ();
	PhysicalDeviceSelector& prefer_integrated ();
	PhysicalDeviceSelector& prefer_virtual_gpu ();

	PhysicalDeviceSelector& allow_fallback (bool fallback = true);

	PhysicalDeviceSelector& require_present (bool require = true);
	PhysicalDeviceSelector& require_dedicated_transfer_queue ();
	PhysicalDeviceSelector& require_dedicated_compute_queue ();

	PhysicalDeviceSelector& required_device_memory_size (VkDeviceSize size);
	PhysicalDeviceSelector& desired_device_memory_size (VkDeviceSize size);

	PhysicalDeviceSelector& add_required_extension (std::string extension);
	PhysicalDeviceSelector& add_desired_extension (std::string extension);

	PhysicalDeviceSelector& set_desired_version (uint32_t major, uint32_t minor);
	PhysicalDeviceSelector& set_minimum_version (uint32_t major = 1, uint32_t minor = 0);

	PhysicalDeviceSelector& set_required_features (VkPhysicalDeviceFeatures features);

	private:
	struct PhysicalDeviceInfo {
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		bool headless = false;
	} info;

	enum PreferredDevice { discrete, integrated, virtual_gpu, cpu, dont_care };

	struct SelectionCriteria {
		PreferredDevice preferred_type = PreferredDevice::discrete;
		bool allow_fallback = true;
		bool require_present = true;
		bool require_dedicated_transfer_queue = false;
		bool require_dedicated_compute_queue = false;
		VkDeviceSize required_mem_size = 0;
		VkDeviceSize desired_mem_size = 0;

		std::vector<std::string> required_extensions;
		std::vector<std::string> desired_extensions;

		uint32_t required_version = VK_MAKE_VERSION (1, 0, 0);
		uint32_t desired_version = VK_MAKE_VERSION (1, 0, 0);

		VkPhysicalDeviceFeatures required_features{};
		VkPhysicalDeviceFeatures desired_features{};

	} criteria;

	enum class Suitable { yes, partial, no };

	Suitable is_device_suitable (VkPhysicalDevice phys_device);
};

// ---- Device ---- //

struct Device {
	VkDevice device = VK_NULL_HANDLE;
	PhysicalDevice physical_device;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
};

void destroy_device (Device device);

class DeviceBuilder {
	public:
	DeviceBuilder (PhysicalDevice device);
	detail::Expected<Device, VkResult> build ();

	template <typename T> DeviceBuilder& add_pNext (T* structure);

	private:
	struct DeviceInfo {
		VkDeviceCreateFlags flags;
		std::vector<VkBaseOutStructure*> pNext_chain;
		PhysicalDevice physical_device;
		std::vector<std::string> extensions;
	} info;
};

// ---- Queue ---- //

uint32_t get_queue_index_present (Device const& device);
uint32_t get_queue_index_graphics (Device const& device);
uint32_t get_queue_index_compute (Device const& device);
uint32_t get_queue_index_transfer (Device const& device);
uint32_t get_queue_index_sparse (Device const& device);

detail::Expected<VkQueue, VkResult> get_queue_present (Device const& device);
detail::Expected<VkQueue, VkResult> get_queue_graphics (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_compute (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_transfer (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_sparse (Device const& device, uint32_t index = 0);

struct Swapchain {
	VkDevice device = VK_NULL_HANDLE;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	uint32_t image_count = 0;
	VkFormat image_format = VK_FORMAT_UNDEFINED;
	VkExtent2D extent = { 0, 0 };
};

void destroy_swapchain (Swapchain const& swapchain);
detail::Expected<std::vector<VkImage>, VkResult> get_swapchain_images (Swapchain const& swapchain);
detail::Expected<std::vector<VkImageView>, VkResult> get_swapchain_image_views (
    Swapchain const& swapchain, std::vector<VkImage> const& images);

class SwapchainBuilder {
	public:
	SwapchainBuilder (Device const& device);
	SwapchainBuilder (VkPhysicalDevice const physical_device, VkDevice const device, VkSurfaceKHR const surface);

	detail::Expected<Swapchain, VkResult> build ();
	detail::Expected<Swapchain, VkResult> recreate (Swapchain const& swapchain);

	// SwapchainBuilder& set_desired_image_count (uint32_t count);
	// SwapchainBuilder& set_maximum_image_count (uint32_t count);

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
	} info;
};

} // namespace vkb