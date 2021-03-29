/*
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
 * Copyright © 2020 Charles Giessen (charles@lunarg.com)
 */

#pragma once

#include <cassert>
#include <cstdio>

#include <array>
#include <vector>
#include <system_error>

#include <vulkan/vulkan.h>

#include "VkBootstrapDispatch.h"

namespace vkb {

namespace detail {

struct Error {
	std::error_code type;
	VkResult vk_result = VK_SUCCESS; // optional error value if a vulkan call failed
};

template <typename T> class Result {
	public:
	Result(const T& value) noexcept : m_value{ value }, m_init{ true } {}
	Result(T&& value) noexcept : m_value{ std::move(value) }, m_init{ true } {}

	Result(Error error) noexcept : m_error{ error }, m_init{ false } {}

	Result(std::error_code error_code, VkResult result = VK_SUCCESS) noexcept
	: m_error{ error_code, result }, m_init{ false } {}

	~Result() noexcept { destroy(); }
	Result(Result const& expected) noexcept : m_init(expected.m_init) {
		if (m_init)
			new (&m_value) T{ expected.m_value };
		else
			m_error = expected.m_error;
	}
	Result(Result&& expected) noexcept : m_init(expected.m_init) {
		if (m_init)
			new (&m_value) T{ std::move(expected.m_value) };
		else
			m_error = std::move(expected.m_error);
		expected.destroy();
	}

	Result& operator=(const T& expect) noexcept {
		destroy();
		m_init = true;
		new (&m_value) T{ expect };
		return *this;
	}
	Result& operator=(T&& expect) noexcept {
		destroy();
		m_init = true;
		new (&m_value) T{ std::move(expect) };
		return *this;
	}
	Result& operator=(const Error& error) noexcept {
		destroy();
		m_init = false;
		m_error = error;
		return *this;
	}
	Result& operator=(Error&& error) noexcept {
		destroy();
		m_init = false;
		m_error = error;
		return *this;
	}
	// clang-format off
	const T* operator-> () const noexcept { assert (m_init); return &m_value; }
	T*       operator-> ()       noexcept { assert (m_init); return &m_value; }
	const T& operator* () const& noexcept { assert (m_init);	return m_value; }
	T&       operator* () &      noexcept { assert (m_init); return m_value; }
	T&&      operator* () &&	 noexcept { assert (m_init); return std::move (m_value); }
	const T&  value () const&    noexcept { assert (m_init); return m_value; }
	T&        value () &         noexcept { assert (m_init); return m_value; }
	const T&& value () const&&   noexcept { assert (m_init); return std::move (m_value); }
	T&&       value () &&        noexcept { assert (m_init); return std::move (m_value); }

    // std::error_code associated with the error
    std::error_code error() const { assert (!m_init); return m_error.type; }
    // optional VkResult that could of been produced due to the error
    VkResult vk_result() const { assert (!m_init); return m_error.vk_result; }
    // Returns the struct that holds the std::error_code and VkResult
    Error full_error() const { assert (!m_init); return m_error; }
	// clang-format on

	// check if the result has an error that matches a specific error case
	template <typename E> bool matches_error(E error_enum_value) const {
		return !m_init && static_cast<E>(m_error.type.value()) == error_enum_value;
	}

	bool has_value() const { return m_init; }
	explicit operator bool() const { return m_init; }

	private:
	void destroy() {
		if (m_init) m_value.~T();
	}
	union {
		T m_value;
		Error m_error;
	};
	bool m_init;
};

struct GenericFeaturesPNextNode {

	GenericFeaturesPNextNode();

	template <typename T> GenericFeaturesPNextNode(T const& features) noexcept {
		*reinterpret_cast<T*>(this) = features;
	}

	static bool match(GenericFeaturesPNextNode const& requested, GenericFeaturesPNextNode const& supported) noexcept;

	VkStructureType sType = static_cast<VkStructureType>(0);
	void* pNext = nullptr;
	static const uint32_t field_capacity = 256;
	VkBool32 fields[field_capacity];
};

} // namespace detail

enum class InstanceError {
	vulkan_unavailable,
	vulkan_version_unavailable,
	vulkan_version_1_1_unavailable,
	vulkan_version_1_2_unavailable,
	failed_create_instance,
	failed_create_debug_messenger,
	requested_layers_not_present,
	requested_extensions_not_present,
	windowing_extensions_not_present,
};
enum class PhysicalDeviceError {
	no_surface_provided,
	failed_enumerate_physical_devices,
	no_physical_devices_found,
	no_suitable_device,
};
enum class QueueError {
	present_unavailable,
	graphics_unavailable,
	compute_unavailable,
	transfer_unavailable,
	queue_index_out_of_range,
	invalid_queue_family_index
};
enum class DeviceError {
	failed_create_device,
};
enum class SwapchainError {
	surface_handle_not_provided,
	failed_query_surface_support_details,
	failed_create_swapchain,
	failed_get_swapchain_images,
	failed_create_swapchain_image_views,
};
enum class SwapchainManagerError {
	swapchain_suboptimal,
	swapchain_out_of_date,
	surface_lost,
	must_call_acquire_image_first,
	acquire_next_image_error,
	queue_present_error,
	surface_handle_not_provided,
	failed_query_surface_support_details,
	failed_create_swapchain,
	failed_get_swapchain_images,
	failed_create_swapchain_image_views,
};

std::error_code make_error_code(InstanceError instance_error);
std::error_code make_error_code(PhysicalDeviceError physical_device_error);
std::error_code make_error_code(QueueError queue_error);
std::error_code make_error_code(DeviceError device_error);
std::error_code make_error_code(SwapchainError swapchain_error);
std::error_code make_error_code(SwapchainManagerError swapchain_error);


const char* to_string_message_severity(VkDebugUtilsMessageSeverityFlagBitsEXT s);
const char* to_string_message_type(VkDebugUtilsMessageTypeFlagsEXT s);

const char* to_string(InstanceError err);
const char* to_string(PhysicalDeviceError err);
const char* to_string(QueueError err);
const char* to_string(DeviceError err);
const char* to_string(SwapchainError err);
const char* to_string(SwapchainManagerError err);


// Gathers useful information about the available vulkan capabilities, like layers and instance
// extensions. Use this for enabling features conditionally, ie if you would like an extension but
// can use a fallback if it isn't supported but need to know if support is available first.
struct SystemInfo {
	private:
	SystemInfo();

	public:
	// Use get_system_info to create a SystemInfo struct. This is because loading vulkan could fail.
	static detail::Result<SystemInfo> get_system_info();
	static detail::Result<SystemInfo> get_system_info(PFN_vkGetInstanceProcAddr fp_vkGetInstanceProcAddr);

	// Returns true if a layer is available
	bool is_layer_available(const char* layer_name) const;
	// Returns true if an extension is available
	bool is_extension_available(const char* extension_name) const;

	std::vector<VkLayerProperties> available_layers;
	std::vector<VkExtensionProperties> available_extensions;
	bool validation_layers_available = false;
	bool debug_utils_available = false;
};

// Forward declared - check VkBoostrap.cpp for implementations
const char* to_string_message_severity(VkDebugUtilsMessageSeverityFlagBitsEXT s);
const char* to_string_message_type(VkDebugUtilsMessageTypeFlagsEXT s);

// Default debug messenger
// Feel free to copy-paste it into your own code, change it as needed, then call `set_debug_callback()` to use that instead
inline VKAPI_ATTR VkBool32 VKAPI_CALL default_debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void*) {
	auto ms = to_string_message_severity(messageSeverity);
	auto mt = to_string_message_type(messageType);
	printf("[%s: %s]\n%s\n", ms, mt, pCallbackData->pMessage);

	return VK_FALSE; // Applications must return false here
}

class InstanceBuilder;
class PhysicalDeviceSelector;

struct Instance {
	VkInstance instance = VK_NULL_HANDLE;
	VkDebugUtilsMessengerEXT debug_messenger = VK_NULL_HANDLE;
	VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;
	PFN_vkGetInstanceProcAddr fp_vkGetInstanceProcAddr = nullptr;
	PFN_vkGetDeviceProcAddr fp_vkGetDeviceProcAddr = nullptr;

	private:
	bool headless = false;
	bool supports_properties2_ext = false;
	uint32_t instance_version = VK_MAKE_VERSION(1, 0, 0);

	friend class InstanceBuilder;
	friend class PhysicalDeviceSelector;
};

void destroy_surface(Instance instance, VkSurfaceKHR surface); // release surface handle
void destroy_surface(VkInstance instance, VkSurfaceKHR surface, VkAllocationCallbacks* callbacks = nullptr); // release surface handle
void destroy_instance(Instance instance); // release instance resources

class InstanceBuilder {
	public:
	// Default constructor, will load vulkan.
	explicit InstanceBuilder();
	// Optional: Can use your own PFN_vkGetInstanceProcAddr
	explicit InstanceBuilder(PFN_vkGetInstanceProcAddr fp_vkGetInstanceProcAddr);

	// Create a VkInstance. Return an error if it failed.
	detail::Result<Instance> build() const;

	// Sets the name of the application. Defaults to "" if none is provided.
	InstanceBuilder& set_app_name(const char* app_name);
	// Sets the name of the engine. Defaults to "" if none is provided.
	InstanceBuilder& set_engine_name(const char* engine_name);
	// Sets the (major, minor, patch) version of the application.
	InstanceBuilder& set_app_version(uint32_t major, uint32_t minor, uint32_t patch = 0);
	// Sets the (major, minor, patch) version of the engine.
	InstanceBuilder& set_engine_version(uint32_t major, uint32_t minor, uint32_t patch = 0);
	// Require a vulkan instance API version. Will fail to create if this version isn't available.
	InstanceBuilder& require_api_version(uint32_t major, uint32_t minor, uint32_t patch = 0);
	// Prefer a vulkan instance API version. If the desired version isn't available, it will use the highest version available.
	InstanceBuilder& desire_api_version(uint32_t major, uint32_t minor, uint32_t patch = 0);

	// Adds a layer to be enabled. Will fail to create an instance if the layer isn't available.
	InstanceBuilder& enable_layer(const char* layer_name);
	// Adds an extension to be enabled. Will fail to create an instance if the extension isn't available.
	InstanceBuilder& enable_extension(const char* extension_name);

	// Headless Mode does not load the required extensions for presentation. Defaults to true.
	InstanceBuilder& set_headless(bool headless = true);

	// Enables the validation layers. Will fail to create an instance if the validation layers aren't available.
	InstanceBuilder& enable_validation_layers(bool require_validation = true);
	// Checks if the validation layers are available and loads them if they are.
	InstanceBuilder& request_validation_layers(bool enable_validation = true);

	// Use a default debug callback that prints to standard out.
	InstanceBuilder& use_default_debug_messenger();
	// Provide a user defined debug callback.
	InstanceBuilder& set_debug_callback(PFN_vkDebugUtilsMessengerCallbackEXT callback);
	// Sets the void* to use in the debug messenger - only useful with a custom callback
	InstanceBuilder& set_debug_callback_user_data_pointer(void* user_data_pointer);
	// Set what message severity is needed to trigger the callback.
	InstanceBuilder& set_debug_messenger_severity(VkDebugUtilsMessageSeverityFlagsEXT severity);
	// Add a message severity to the list that triggers the callback.
	InstanceBuilder& add_debug_messenger_severity(VkDebugUtilsMessageSeverityFlagsEXT severity);
	// Set what message type triggers the callback.
	InstanceBuilder& set_debug_messenger_type(VkDebugUtilsMessageTypeFlagsEXT type);
	// Add a message type to the list of that triggers the callback.
	InstanceBuilder& add_debug_messenger_type(VkDebugUtilsMessageTypeFlagsEXT type);

	// Disable some validation checks.
	// Checks: All, and Shaders
	InstanceBuilder& add_validation_disable(VkValidationCheckEXT check);

	// Enables optional parts of the validation layers.
	// Parts: best practices, gpu assisted, and gpu assisted reserve binding slot.
	InstanceBuilder& add_validation_feature_enable(VkValidationFeatureEnableEXT enable);

	// Disables sections of the validation layers.
	// Options: All, shaders, thread safety, api parameters, object lifetimes, core checks, and unique handles.
	InstanceBuilder& add_validation_feature_disable(VkValidationFeatureDisableEXT disable);

	// Provide custom allocation callbacks.
	InstanceBuilder& set_allocation_callbacks(VkAllocationCallbacks* callbacks);

	private:
	struct InstanceInfo {
		// VkApplicationInfo
		const char* app_name = nullptr;
		const char* engine_name = nullptr;
		uint32_t application_version = 0;
		uint32_t engine_version = 0;
		uint32_t required_api_version = VK_MAKE_VERSION(1, 0, 0);
		uint32_t desired_api_version = VK_MAKE_VERSION(1, 0, 0);

		// VkInstanceCreateInfo
		std::vector<const char*> layers;
		std::vector<const char*> extensions;
		VkInstanceCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_elements;

		// debug callback - use the default so it is not nullptr
		PFN_vkDebugUtilsMessengerCallbackEXT debug_callback = default_debug_callback;
		VkDebugUtilsMessageSeverityFlagsEXT debug_message_severity =
		    VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		VkDebugUtilsMessageTypeFlagsEXT debug_message_type =
		    VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
		    VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		void* debug_user_data_pointer = nullptr;

		// validation features
		std::vector<VkValidationCheckEXT> disabled_validation_checks;
		std::vector<VkValidationFeatureEnableEXT> enabled_validation_features;
		std::vector<VkValidationFeatureDisableEXT> disabled_validation_features;

		// Custom allocator
		VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;

		bool request_validation_layers = false;
		bool enable_validation_layers = false;
		bool use_debug_messenger = false;
		bool headless_context = false;

		PFN_vkGetInstanceProcAddr fp_vkGetInstanceProcAddr = nullptr;
	} info;
};

VKAPI_ATTR VkBool32 VKAPI_CALL default_debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);

void destroy_debug_utils_messenger(VkInstance const instance,
    VkDebugUtilsMessengerEXT const messenger,
    VkAllocationCallbacks* allocation_callbacks = nullptr);

// ---- Physical Device ---- //
class PhysicalDeviceSelector;
class DeviceBuilder;

struct PhysicalDevice {
	VkPhysicalDevice physical_device = VK_NULL_HANDLE;
	VkSurfaceKHR surface = VK_NULL_HANDLE;

	// Note that this reflects selected features carried over from required features, not all features the physical device supports.
	VkPhysicalDeviceFeatures features{};
	VkPhysicalDeviceProperties properties{};
	VkPhysicalDeviceMemoryProperties memory_properties{};

	// Has a queue family that supports compute operations but not graphics nor transfer.
	bool has_dedicated_compute_queue() const;
	// Has a queue family that supports transfer operations but not graphics nor compute.
	bool has_dedicated_transfer_queue() const;

	// Has a queue family that supports transfer operations but not graphics.
	bool has_separate_compute_queue() const;
	// Has a queue family that supports transfer operations but not graphics.
	bool has_separate_transfer_queue() const;

	// Advanced: Get the VkQueueFamilyProperties of the device if special queue setup is needed
	std::vector<VkQueueFamilyProperties> get_queue_families() const;

	private:
	uint32_t instance_version = VK_MAKE_VERSION(1, 0, 0);
	std::vector<const char*> extensions_to_enable;
	std::vector<VkQueueFamilyProperties> queue_families;
	std::vector<detail::GenericFeaturesPNextNode> extended_features_chain;
	bool defer_surface_initialization = false;
	friend class PhysicalDeviceSelector;
	friend class DeviceBuilder;
};

enum class PreferredDeviceType {
	other = 0,
	integrated = 1,
	discrete = 2,
	virtual_gpu = 3,
	cpu = 4
};

class PhysicalDeviceSelector {
	public:
	// Requires a vkb::Instance to construct, needed to pass instance creation info.
	explicit PhysicalDeviceSelector(Instance const& instance);

	detail::Result<PhysicalDevice> select() const;

	// Set the surface in which the physical device should render to.
	PhysicalDeviceSelector& set_surface(VkSurfaceKHR surface);
	// Set the desired physical device type to select. Defaults to PreferredDeviceType::discrete.
	PhysicalDeviceSelector& prefer_gpu_device_type(PreferredDeviceType type = PreferredDeviceType::discrete);
	// Allow selection of a gpu device type that isn't the preferred physical device type. Defaults to true.
	PhysicalDeviceSelector& allow_any_gpu_device_type(bool allow_any_type = true);

	// Require that a physical device supports presentation. Defaults to true.
	PhysicalDeviceSelector& require_present(bool require = true);

	// Require a queue family that supports compute operations but not graphics nor transfer.
	PhysicalDeviceSelector& require_dedicated_compute_queue();
	// Require a queue family that supports transfer operations but not graphics nor compute.
	PhysicalDeviceSelector& require_dedicated_transfer_queue();

	// Require a queue family that supports compute operations but not graphics.
	PhysicalDeviceSelector& require_separate_compute_queue();
	// Require a queue family that supports transfer operations but not graphics.
	PhysicalDeviceSelector& require_separate_transfer_queue();

	// Require a memory heap from VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT with `size` memory available.
	PhysicalDeviceSelector& required_device_memory_size(VkDeviceSize size);
	// Prefer a memory heap from VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT with `size` memory available.
	PhysicalDeviceSelector& desired_device_memory_size(VkDeviceSize size);

	// Require a physical device which supports a specific extension.
	PhysicalDeviceSelector& add_required_extension(const char* extension);
	// Require a physical device which supports a set of extensions.
	PhysicalDeviceSelector& add_required_extensions(std::vector<const char*> extensions);

	// Prefer a physical device which supports a specific extension.
	PhysicalDeviceSelector& add_desired_extension(const char* extension);
	// Prefer a physical device which supports a set of extensions.
	PhysicalDeviceSelector& add_desired_extensions(std::vector<const char*> extensions);

	// Prefer a physical device that supports a (major, minor) version of vulkan.
	PhysicalDeviceSelector& set_desired_version(uint32_t major, uint32_t minor);
	// Require a physical device that supports a (major, minor) version of vulkan.
	PhysicalDeviceSelector& set_minimum_version(uint32_t major, uint32_t minor);

	// Require a physical device which supports a specific set of general/extension features.
#if defined(VK_API_VERSION_1_1)
	template <typename T>
	PhysicalDeviceSelector& add_required_extension_features(T const& features) {
		criteria.extended_features_chain.push_back(features);
		return *this;
	}
#endif
	// Require a physical device which supports the features in VkPhysicalDeviceFeatures.
	PhysicalDeviceSelector& set_required_features(VkPhysicalDeviceFeatures const& features);
#if defined(VK_API_VERSION_1_2)
	// Require a physical device which supports the features in VkPhysicalDeviceVulkan11Features.
	// Must have vulkan version 1.2 - This is due to the VkPhysicalDeviceVulkan11Features struct being added in 1.2, not 1.1
	PhysicalDeviceSelector& set_required_features_11(VkPhysicalDeviceVulkan11Features features_11);
	// Require a physical device which supports the features in VkPhysicalDeviceVulkan12Features.
	// Must have vulkan version 1.2
	PhysicalDeviceSelector& set_required_features_12(VkPhysicalDeviceVulkan12Features features_12);
#endif

	// Used when surface creation happens after physical device selection.
	// Warning: This disables checking if the physical device supports a given surface.
	PhysicalDeviceSelector& defer_surface_initialization();

	// Ignore all criteria and choose the first physical device that is available.
	// Only use when: The first gpu in the list may be set by global user preferences and an application may wish to respect it.
	PhysicalDeviceSelector& select_first_device_unconditionally(bool unconditionally = true);

	private:
	struct InstanceInfo {
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		uint32_t version = VK_MAKE_VERSION(1, 0, 0);
		bool headless = false;
		bool supports_properties2_ext = false;
	} instance_info;

	struct PhysicalDeviceDesc {
		VkPhysicalDevice phys_device = VK_NULL_HANDLE;
		std::vector<VkQueueFamilyProperties> queue_families;

		VkPhysicalDeviceFeatures device_features{};
		VkPhysicalDeviceProperties device_properties{};
		VkPhysicalDeviceMemoryProperties mem_properties{};

// Because the KHR version is a typedef in Vulkan 1.1, it is safe to define one or the other.
#if defined(VK_API_VERSION_1_1)
		VkPhysicalDeviceFeatures2 device_features2{};
#else
		VkPhysicalDeviceFeatures2KHR device_features2{};
#endif
		std::vector<detail::GenericFeaturesPNextNode> extended_features_chain;
	};

	// We copy the extension features stored in the selector criteria under the prose of a
	// "template" to ensure that after fetching everything is compared 1:1 during a match.

	PhysicalDeviceDesc populate_device_details(VkPhysicalDevice phys_device,
	    std::vector<detail::GenericFeaturesPNextNode> const& src_extended_features_chain) const;

	struct SelectionCriteria {
		PreferredDeviceType preferred_type = PreferredDeviceType::discrete;
		bool allow_any_type = true;
		bool require_present = true;
		bool require_dedicated_transfer_queue = false;
		bool require_dedicated_compute_queue = false;
		bool require_separate_transfer_queue = false;
		bool require_separate_compute_queue = false;
		VkDeviceSize required_mem_size = 0;
		VkDeviceSize desired_mem_size = 0;

		std::vector<const char*> required_extensions;
		std::vector<const char*> desired_extensions;

		uint32_t required_version = VK_MAKE_VERSION(1, 0, 0);
		uint32_t desired_version = VK_MAKE_VERSION(1, 0, 0);

		VkPhysicalDeviceFeatures required_features{};
#if defined(VK_API_VERSION_1_1)
		VkPhysicalDeviceFeatures2 required_features2{};
		std::vector<detail::GenericFeaturesPNextNode> extended_features_chain;
#endif
		bool defer_surface_initialization = false;
		bool use_first_gpu_unconditionally = false;
	} criteria;

	enum class Suitable { yes, partial, no };

	Suitable is_device_suitable(PhysicalDeviceDesc phys_device) const;
};

// ---- Queue ---- //
enum class QueueType { present, graphics, compute, transfer };

namespace detail {
// Sentinel value, used in implementation only
const uint32_t QUEUE_INDEX_MAX_VALUE = 65536;
const uint32_t INDEX_MAX_VALUE = 65536;

} // namespace detail

// ---- Device ---- //

struct Device {
	VkDevice device = VK_NULL_HANDLE;
	PhysicalDevice physical_device;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
	std::vector<VkQueueFamilyProperties> queue_families;
	VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;
	PFN_vkGetDeviceProcAddr fp_vkGetDeviceProcAddr = nullptr;

	detail::Result<uint32_t> get_queue_index(QueueType type) const;
	// Only a compute or transfer queue type is valid. All other queue types do not support a 'dedicated' queue index
	detail::Result<uint32_t> get_dedicated_queue_index(QueueType type) const;

	detail::Result<VkQueue> get_queue(QueueType type) const;
	// Only a compute or transfer queue type is valid. All other queue types do not support a 'dedicated' queue
	detail::Result<VkQueue> get_dedicated_queue(QueueType type) const;

	// Return a loaded dispatch table
	DispatchTable make_table() const;

	private:
	struct {
		PFN_vkGetDeviceQueue fp_vkGetDeviceQueue = nullptr;
		PFN_vkDestroyDevice fp_vkDestroyDevice = nullptr;
	} internal_table;
	friend class DeviceBuilder;
	friend void destroy_device(Device device);
};

// For advanced device queue setup
struct CustomQueueDescription {
	explicit CustomQueueDescription(uint32_t index, uint32_t count, std::vector<float> priorities);
	uint32_t index = 0;
	uint32_t count = 0;
	std::vector<float> priorities;
};

void destroy_device(Device device);

class DeviceBuilder {
	public:
	// Any features and extensions that are requested/required in PhysicalDeviceSelector are automatically enabled.
	explicit DeviceBuilder(PhysicalDevice physical_device);

	detail::Result<Device> build() const;

	// For Advanced Users: specify the exact list of VkDeviceQueueCreateInfo's needed for the application.
	// If a custom queue setup is provided, getting the queues and queue indexes is up to the application.
	DeviceBuilder& custom_queue_setup(std::vector<CustomQueueDescription> queue_descriptions);

	// Add a structure to the pNext chain of VkDeviceCreateInfo.
	// The structure must be valid when DeviceBuilder::build() is called.
	template <typename T> DeviceBuilder& add_pNext(T* structure) {
		info.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}

	// Provide custom allocation callbacks.
	DeviceBuilder& set_allocation_callbacks(VkAllocationCallbacks* callbacks);

	private:
	PhysicalDevice physical_device;
	struct DeviceInfo {
		VkDeviceCreateFlags flags = 0;
		std::vector<VkBaseOutStructure*> pNext_chain;
		std::vector<CustomQueueDescription> queue_descriptions;
		VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;
	} info;
};

// ---- Swapchain ---- //

struct Swapchain {
	VkDevice device = VK_NULL_HANDLE;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	uint32_t image_count = 0;
	VkFormat image_format = VK_FORMAT_UNDEFINED;
	VkImageUsageFlags image_usage_flags = 0;
	VkExtent2D extent = { 0, 0 };
	VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;

	// Returns a vector of VkImage handles to the swapchain.
	detail::Result<std::vector<VkImage>> get_images();

	// Returns a vector of VkImageView's to the VkImage's of the swapchain.
	// VkImageViews must be destroyed.
	detail::Result<std::vector<VkImageView>> get_image_views();
	void destroy_image_views(std::vector<VkImageView> const& image_views);

	private:
	struct {
		PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR = nullptr;
		PFN_vkCreateImageView fp_vkCreateImageView = nullptr;
		PFN_vkDestroyImageView fp_vkDestroyImageView = nullptr;
		PFN_vkDestroySwapchainKHR fp_vkDestroySwapchainKHR = nullptr;
	} internal_table;
	friend class SwapchainBuilder;
	friend void destroy_swapchain(Swapchain const& swapchain);
};

void destroy_swapchain(Swapchain const& swapchain);

class SwapchainBuilder {
	public:
	// Construct a SwapchainBuilder with a `vkb::Device`
	explicit SwapchainBuilder(Device const& device);
	// Construct a SwapchainBuilder with a specific VkSurfaceKHR handle and `vkb::Device`
	explicit SwapchainBuilder(Device const& device, VkSurfaceKHR const surface);
	// Construct a SwapchainBuilder with Vulkan handles for the physical device, device, and surface
	// Optionally can provide the uint32_t indices for the graphics and present queue
	// Note: The constructor will query the graphics & present queue if the indices are not provided
	explicit SwapchainBuilder(VkPhysicalDevice const physical_device,
	    VkDevice const device,
	    VkSurfaceKHR const surface,
	    uint32_t graphics_queue_index = detail::QUEUE_INDEX_MAX_VALUE,
	    uint32_t present_queue_index = detail::QUEUE_INDEX_MAX_VALUE);

	detail::Result<Swapchain> build() const;

	// Set the oldSwapchain member of VkSwapchainCreateInfoKHR.
	// For use in rebuilding a swapchain.
	SwapchainBuilder& set_old_swapchain(VkSwapchainKHR old_swapchain);
	SwapchainBuilder& set_old_swapchain(Swapchain const& swapchain);


	// Desired size of the swapchain. By default, the swapchain will use the size
	// of the window being drawn to.
	SwapchainBuilder& set_desired_extent(uint32_t width, uint32_t height);

	// When determining the surface format, make this the first to be used if supported.
	SwapchainBuilder& set_desired_format(VkSurfaceFormatKHR format);
	// Add this swapchain format to the end of the list of formats selected from.
	SwapchainBuilder& add_fallback_format(VkSurfaceFormatKHR format);
	// Use the default swapchain formats. This is done if no formats are provided.
	// Default surface format is {VK_FORMAT_B8G8R8A8_SRGB, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR}
	SwapchainBuilder& use_default_format_selection();

	// When determining the present mode, make this the first to be used if supported.
	SwapchainBuilder& set_desired_present_mode(VkPresentModeKHR present_mode);
	// Add this present mode to the end of the list of present modes selected from.
	SwapchainBuilder& add_fallback_present_mode(VkPresentModeKHR present_mode);
	// Use the default presentation mode. This is done if no present modes are provided.
	// Default present modes: VK_PRESENT_MODE_MAILBOX_KHR with fallback VK_PRESENT_MODE_FIFO_KHR
	SwapchainBuilder& use_default_present_mode_selection();

	// Set the bitmask of the image usage for acquired swapchain images.
	SwapchainBuilder& set_image_usage_flags(VkImageUsageFlags usage_flags);
	// Add a image usage to the bitmask for acquired swapchain images.
	SwapchainBuilder& add_image_usage_flags(VkImageUsageFlags usage_flags);
	// Use the default image usage bitmask values. This is the default if no image usages
	// are provided. The default is VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT
	SwapchainBuilder& use_default_image_usage_flags();

	// Set the bitmask of the format feature flag for acquired swapchain images.
	SwapchainBuilder& set_format_feature_flags(VkFormatFeatureFlags feature_flags);
	// Add a format feature to the bitmask for acquired swapchain images.
	SwapchainBuilder& add_format_feature_flags(VkFormatFeatureFlags feature_flags);
	// Use the default format feature bitmask values. This is the default if no format features
	// are provided. The default is VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT
	SwapchainBuilder& use_default_format_feature_flags();

	// Set the number of views in for multiview/stereo surface
	SwapchainBuilder& set_image_array_layer_count(uint32_t array_layer_count);

	// Set whether the Vulkan implementation is allowed to discard rendering operations that
	// affect regions of the surface that are not visible. Default is true.
	// Note: Applications should use the default of true if they do not expect to read back the content
	// of presentable images before presenting them or after reacquiring them, and if their fragment
	// shaders do not have any side effects that require them to run for all pixels in the presentable image.
	SwapchainBuilder& set_clipped(bool clipped = true);

	// Set the VkSwapchainCreateFlagBitsKHR.
	SwapchainBuilder& set_create_flags(VkSwapchainCreateFlagBitsKHR create_flags);
	// Set the transform to be applied, like a 90 degree rotation. Default is no transform.
	SwapchainBuilder& set_pre_transform_flags(VkSurfaceTransformFlagBitsKHR pre_transform_flags);
	// Set the alpha channel to be used with other windows in on the system. Default is VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR.
	SwapchainBuilder& set_composite_alpha_flags(VkCompositeAlphaFlagBitsKHR composite_alpha_flags);

	// Add a structure to the pNext chain of VkSwapchainCreateInfoKHR.
	// The structure must be valid when SwapchainBuilder::build() is called.
	template <typename T> SwapchainBuilder& add_pNext(T* structure) {
		info.pNext_chain.push_back(reinterpret_cast<VkBaseOutStructure*>(structure));
		return *this;
	}

	// Provide custom allocation callbacks.
	SwapchainBuilder& set_allocation_callbacks(VkAllocationCallbacks* callbacks);

	private:
	void add_desired_formats(std::vector<VkSurfaceFormatKHR>& formats) const;
	void add_desired_present_modes(std::vector<VkPresentModeKHR>& modes) const;

	struct SwapchainInfo {
		VkPhysicalDevice physical_device = VK_NULL_HANDLE;
		VkDevice device = VK_NULL_HANDLE;
		std::vector<VkBaseOutStructure*> pNext_chain;
		VkSwapchainCreateFlagBitsKHR create_flags = static_cast<VkSwapchainCreateFlagBitsKHR>(0);
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		std::vector<VkSurfaceFormatKHR> desired_formats;
		uint32_t desired_width = 256;
		uint32_t desired_height = 256;
		uint32_t array_layer_count = 1;
		VkImageUsageFlags image_usage_flags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		VkFormatFeatureFlags format_feature_flags = VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
		uint32_t graphics_queue_index = 0;
		uint32_t present_queue_index = 0;
		VkSurfaceTransformFlagBitsKHR pre_transform = static_cast<VkSurfaceTransformFlagBitsKHR>(0);
		VkCompositeAlphaFlagBitsKHR composite_alpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		std::vector<VkPresentModeKHR> desired_present_modes;
		bool clipped = true;
		VkSwapchainKHR old_swapchain = VK_NULL_HANDLE;
		VkAllocationCallbacks* allocation_callbacks = VK_NULL_HANDLE;
	} info;

	friend class SwapchainManager;
	// To allow SwapchainManager to construct it 'emptily'
	explicit SwapchainBuilder() = default;
};

namespace detail {
// constants used for DeletionQueue and SwapchainManager
const int FRAMES_IN_FLIGHT = 3;
const int MAX_SWAPCHAIN_IMAGE_COUNT = 8;

} // namespace detail

// ImagelessFramebufferBuilder

struct ImagelessFramebufferBuilder {
	ImagelessFramebufferBuilder(Device const& device) noexcept;
	VkFramebuffer build() noexcept;
	ImagelessFramebufferBuilder& set_renderpass(VkRenderPass render_pass);
	ImagelessFramebufferBuilder& set_width(uint32_t width);
	ImagelessFramebufferBuilder& set_height(uint32_t height);
	ImagelessFramebufferBuilder& set_extent(VkExtent2D extent);
	ImagelessFramebufferBuilder& set_layers(uint32_t layer_count);
	ImagelessFramebufferBuilder& add_attachment(VkImageUsageFlags usage_flags, VkFormat format);
	ImagelessFramebufferBuilder& add_attachment(
	    VkImageUsageFlags usage_flags, std::vector<VkFormat> const& formats);

	private:
	struct Attachment {
		VkImageUsageFlags usage_flags;
		std::vector<VkFormat> formats;
	};
	VkDevice device = VK_NULL_HANDLE;
	PFN_vkCreateFramebuffer fp_vkCreateFramebuffer = nullptr;
	PFN_vkDestroyFramebuffer fp_vkDestroyFramebuffer = nullptr;
	VkRenderPass _render_pass = VK_NULL_HANDLE;
	uint32_t _width = 0;
	uint32_t _height = 0;
	uint32_t _layers = 1;
	std::vector<Attachment> _attachments;
};

/**
 * DeletionQueue is a helper utility that manages deleting of VkImages, VkImageViews,
 *VkFramebuffers, and VkSwapchains at a later time. It works by keeping a list of all submitted
 *handles in separate sets, and when a set is old enough, the DeletionQueue will iterate and delete
 *all of the handles.
 *
 * The `tick()` function is when the deletion happens as well as incrementing the internal frame
 *counter. Call `tick()` once per frame, preferably at the end.
 *
 * DeletionQueue is *not* a generic deletion queue that can execute arbitrary code to delete
 *objects. Thus it may not be suitable for all applications.
 *
 * To destroy the DeletionQueue, call `destroy()`. Additionally, `destroy()` will be called
 *automatically in DeletionQueue's destructor.
 **/
class DeletionQueue {
	public:
	// default constructor, must replace with non-default constructed DeletionQueue to be useable
	explicit DeletionQueue() noexcept = default;

	// Main Contstructor Parameters:
	// VkDevice device - VkDevice to use in the DeletionQueue
	// uint32_t deletion_delay - how many ticks objects elapse before an added handle is destroyed
	//    Ex: deletion_delay of 4 means that a VkImage added will be destroyed after 4 calls to `tick()`
	explicit DeletionQueue(VkDevice device, uint32_t deletion_delay) noexcept;
	explicit DeletionQueue(Device const& device, uint32_t deletion_delay) noexcept;
	~DeletionQueue() noexcept;
	DeletionQueue(DeletionQueue const& other) = delete;
	DeletionQueue& operator=(DeletionQueue const& other) = delete;
	DeletionQueue(DeletionQueue&& other) noexcept;
	DeletionQueue& operator=(DeletionQueue&& other) noexcept;

	// Add the corresponding handle or handles to be deleted in 'queue_depth' frames
	void add_image(VkImage) noexcept;
	void add_images(uint32_t images_count, const VkImage* images) noexcept;
	void add_image_view(VkImageView image_view) noexcept;
	void add_image_views(uint32_t image_view_count, const VkImageView* image_view) noexcept;
	void add_framebuffer(VkFramebuffer framebuffer) noexcept;
	void add_framebuffers(uint32_t framebuffer_count, const VkFramebuffer* framebuffers) noexcept;
	void add_swapchain(VkSwapchainKHR swapchain) noexcept;

	// Destroy the objects which have waited for `deletion_delay` ticks, then increment the current frame counter
	void tick() noexcept;

	// Destroys the DeletionQueue, including destroying all contained Vulkan handles. Make sure all contained handles are not in use.
	void destroy() noexcept;

	private:
	struct DelaySets {
		std::vector<VkImage> images;
		std::vector<VkImageView> views;
		std::vector<VkFramebuffer> framebuffers;
		std::vector<VkSwapchainKHR> swapchains;
	};
	VkDevice device;
	uint32_t queue_depth = 0;
	uint32_t current_index = 0;
	std::array<DelaySets, detail::MAX_SWAPCHAIN_IMAGE_COUNT> sets;
	struct {
		PFN_vkDestroyImage fp_vkDestroyImage;
		PFN_vkDestroyImageView fp_vkDestroyImageView;
		PFN_vkDestroyFramebuffer fp_vkDestroyFramebuffer;
		PFN_vkDestroySwapchainKHR fp_vkDestroySwapchainKHR;
	} internal_table;
	void clear_set(vkb::DeletionQueue::DelaySets& set) noexcept;
};

/**
 * The SwapchainManager is a utility class that handles the creation and recreation of the
 * swapchain, the acquiring of swapchain image indices, the submission of command buffers which
 * write to swapchain images, and the synchronization of the writing and presenting.
 * */

namespace detail {
class SemaphoreManager {
	public:
	explicit SemaphoreManager() noexcept = default;
	explicit SemaphoreManager(VkDevice device, uint32_t image_count) noexcept;
	~SemaphoreManager() noexcept;
	SemaphoreManager(SemaphoreManager const& other) = delete;
	SemaphoreManager& operator=(SemaphoreManager const& other) = delete;
	SemaphoreManager(SemaphoreManager&& other) noexcept;
	SemaphoreManager& operator=(SemaphoreManager&& other) noexcept;

	VkSemaphore get_next_acquire_semaphore() noexcept;
	void update_current_semaphore_index(uint32_t index) noexcept;
	VkSemaphore get_acquire_semaphore() noexcept;
	VkSemaphore get_submit_semaphore() noexcept;

	void recreate_swapchain_resources() noexcept;

	private:
	VkDevice device = VK_NULL_HANDLE;
	struct Details {
		uint32_t swapchain_image_count = 0;
		uint32_t current_swapchain_index = detail::INDEX_MAX_VALUE;
		std::array<bool, MAX_SWAPCHAIN_IMAGE_COUNT> in_use = {};
		std::array<VkSemaphore, MAX_SWAPCHAIN_IMAGE_COUNT> active_acquire_semaphores{};
		std::array<VkSemaphore, MAX_SWAPCHAIN_IMAGE_COUNT> active_submit_semaphores{};
		uint32_t current_submit_index = 0;
		std::array<std::vector<VkSemaphore>, FRAMES_IN_FLIGHT> expired_semaphores;
		std::vector<VkSemaphore> idle_semaphores;
		VkSemaphore current_acquire_semaphore = VK_NULL_HANDLE;
		PFN_vkCreateSemaphore fp_vkCreateSemaphore;
		PFN_vkDestroySemaphore fp_vkDestroySemaphore;
	} detail;
	void destroy() noexcept;

	VkSemaphore get_fresh_semaphore() noexcept;
};

// Used to signal that there may be an error that must be checked but there is no value returned
struct void_t {};

} // namespace detail

// Descriptive information about the current swapchain.
// Contains: image count, image format, extent (width & height), image usage flags
struct SwapchainInfo {
	uint32_t image_count = 0;
	VkFormat image_format = VK_FORMAT_UNDEFINED;
	VkExtent2D extent = { 0, 0 };
	VkImageUsageFlags image_usage_flags = 0;
};

// Vulkan Handles associated with the current swapchain
// Contains: VkSwapchainKHR handle, image count, array of VkImages, array of VkImageViews
// Caution: The image and image view arrays have `image_count` image/image views in them.
// This is for performance reasons, that way there isn't an extra indirection.
struct SwapchainResources {
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	uint32_t image_count = 0;
	std::array<VkImage, detail::MAX_SWAPCHAIN_IMAGE_COUNT> images{};
	std::array<VkImageView, detail::MAX_SWAPCHAIN_IMAGE_COUNT> image_views{};
};

// Struct returned from SwapchainManager::acquire_image()
struct SwapchainAcquireInfo {
	// image view to use this frame
	VkImageView image_view{};
	// index of the swapchain image to use this frame
	uint32_t image_index = detail::INDEX_MAX_VALUE;
};

struct SwapchainSubmitSemaphores {
	VkSemaphore signal;
	VkSemaphore wait;
};

/**
 * Swapchain Manager
 *
 * Creation:
 * Call the static function `SwapchainManager::create(SwapchainBuilder const& builder)` and pass
 * in a vkb::SwapchainBuilder. To configure the swapchain, use the member functions on the
 * SwapchainBuilder before it is passed in. SwapchainManager will keep an internal
 * copy of this builder. This function will also create a swapchain, so that the application can
 * query the current extent, format, and usage flags of the created swapchain.
 *
 * Destruction:
 * To destroy the SwapchainManager, call `destroy()`. Additionally, SwapchainManager will call
 * `destroy()` automatically in its destructor.
 *
 * SYNCHRONIZATION GUARANTEES (or lack thereof):
 * The SwapchainManager does NOT have internal synchronization. Thus applications must never call any
 * of its functions from multiple threads at the same time.
 *
 * QUEUE SUBMISSION:
 * The SwapchainManager uses the Presentation VkQueue. Thus, the user must guarantee that calling `present()`
 * does not overlap with any other calls which use the present queue (which in most cases is the graphics queue).
 *
 * Suggested Vulkan feature to enable:
 * Imageless Framebuffer - This feature makes it possible to create a framebuffer without a
 * VkImageView by making it a parameter that is passed in at vkCmdBeginRenderPass time. It is
 * recommended because it means one VkFrameBuffer is necessary for the entire swapchain, rather than
 * the previous case of N framebuffers, one for each swapchain image. Vulkan 1.2 guarantees support
 * for it.
 *
 * Example Initialization of SwapchainManager:
 * {
 *     auto swapchain_manager_ret = vkb::SwapchainManager::create(vkb::SwapchainBuilder{ vk_device });
 *     if (!swapchain_manager_ret) {
 *         std::cout << swapchain_manager_ret.error().message() << "\n";
 *         return -1;
 *     }
 *     swapchain_manager = std::move(swapchain_manager_ret.value());
 *     swapchain_info = renderer.swapchain_manager.get_info();
 * }
 *
 * Example Application Usage during main rendering:
 * {
 *      auto acquire_ret = renderer.swapchain_manager.acquire_image();
 *     if (!acquire_ret.has_value() && acquire_ret.error().value() == (int)vkb::SwapchainManagerError::swapchain_out_of_date) {
 *         should_recreate = true;
 *         return; //abort rendering this frame
 *     } else if (!acquire_ret.has_value()) {
 *         return; //error out
 *     }
 *     VkImageView image_view =  acquire_ret.value().image_view;
 *
 *     // record command buffers that use image_view
 *
 *     auto semaphores = renderer.swapchain_manager.get_submit_semaphores().value();
 *
 *     VkSemaphore wait_semaphores[1] = { semaphores.wait }; //add in any user declared semaphores
 *     VkSemaphore signal_semaphores[1] = { semaphores.signal }; //add in any user declared semaphores
 *     VkPipelineStageFlags wait_stages[1] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
 *
 *     VkSubmitInfo submit_info = {};
 *     submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
 *     submit_info.waitSemaphoreCount = 1;
 *     submit_info.pWaitSemaphores = wait_semaphores;
 *     submit_info.pWaitDstStageMask = wait_stages;
 *     submit_info.commandBufferCount = 1;
 *     submit_info.pCommandBuffers = &renderer.command_buffers[renderer.current_index];
 *     submit_info.signalSemaphoreCount = 1;
 *     submit_info.pSignalSemaphores = signal_semaphores;
 *
 * }
 *
 * Example Application Recreation
 *
 *
 * The SwapchainManager interally keeps track of the current 'state' of the swapchain. These states are:
 * - ready_to_acquire: initial state, indicates is is safe to call `acquire_image`
 * - ready_to_present: set after acquiring, indicates it is ready to accept command buffers to submit.
 * - expired: the swapchain needs to be recreated, calling `acquire_image` while in this state will fail
 * - destroyed: the swapchain was destroyed (likely manually), prevents further usage of the SwapchainManager
 * After a successful call to `acquire_image()`, the state is set to `ready_to_present`
 * After a successful call to `present()`, the state is set back to `ready_to_present`
 * After a successful call to `recreate()`, the state is set back to `ready_to_acquire`
 * Note that a successful call indicates that the return value didn't produce an error *and* the `out_of_date` parameter in
 * `SwapchainAcquireInfo` or `SwapchainSubmitInfo` is false.
 *
 * Type Characteristics:
 * SwapchainManager contains a default constructor, allowing it to be created in null state and initialized at a later point.
 * SwapchainManager is a move-only type, due to it owning various Vulkan objects. Therefore it will make any struct or class that
 * has a SwapchainManager member into a move-only type.
 *
 * Informative Details - Semaphores:
 * SwapchainManager keeps all semaphore management internal, thus they are not an aspect a user
 * needs to be involved with. However, it is possible to add additional wait and signal semaphores
 * in the call to vkQueueSubmit if so desired by passing in the semaphores into `submit`.
 **/
class SwapchainManager {
	public:
	static detail::Result<SwapchainManager> create(SwapchainBuilder const& builder) noexcept;

	explicit SwapchainManager() = default;
	~SwapchainManager() noexcept;
	void destroy() noexcept;

	SwapchainManager(SwapchainManager const& other) = delete;
	SwapchainManager& operator=(SwapchainManager const& other) = delete;
	SwapchainManager(SwapchainManager&& other) noexcept;
	SwapchainManager& operator=(SwapchainManager&& other) noexcept;

	// Primary API

	// Get a VkImageView handle to use in rendering
	detail::Result<SwapchainAcquireInfo> acquire_image() noexcept;

	detail::Result<SwapchainSubmitSemaphores> get_submit_semaphores() noexcept;

	detail::Result<detail::void_t> present() noexcept;

	// Recreate the swapchain, putting currently in-use internal resources in a delete queue
	detail::Result<SwapchainInfo> recreate(uint32_t width = 0, uint32_t height = 0) noexcept;

	// Get info about the swapchain
	detail::Result<SwapchainInfo> get_info() noexcept;

	// Get access to the swapchain and resources associated with it
	detail::Result<SwapchainResources> get_swapchain_resources() noexcept;

	// Access the internal builder. This is how an application can alter how the swapchain is recreated.
	SwapchainBuilder& get_builder() noexcept;

	private:
	enum class Status {
		ready_to_acquire,
		ready_to_present,
		expired,   // needs to be recreated
		destroyed, // no longer usable
	};
	VkDevice device = VK_NULL_HANDLE;
	struct Details {
		vkb::SwapchainBuilder builder;
		vkb::Swapchain current_swapchain;
		SwapchainResources swapchain_resources;
		detail::SemaphoreManager semaphore_manager;
		DeletionQueue delete_queue;
		Status current_status = Status::ready_to_acquire;
		VkQueue graphics_queue{};
		VkQueue present_queue{};
		SwapchainInfo current_info{};
		uint32_t current_image_index = detail::INDEX_MAX_VALUE;
		PFN_vkGetDeviceQueue fp_vkGetDeviceQueue;
		PFN_vkAcquireNextImageKHR fp_vkAcquireNextImageKHR;
		PFN_vkQueuePresentKHR fp_vkQueuePresentKHR;
		PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR;
		PFN_vkCreateImageView fp_vkCreateImageView;
	} detail;

	explicit SwapchainManager(SwapchainBuilder const& builder,
	    Swapchain swapchain,
	    SwapchainResources resources,
	    PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR,
	    PFN_vkCreateImageView fp_vkCreateImageView) noexcept;

	void update_swapchain_info() noexcept;

	static detail::Result<SwapchainResources> create_swapchain_resources(vkb::Swapchain swapchain,
	    PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR,
	    PFN_vkCreateImageView fp_vkCreateImageView) noexcept;
};
} // namespace vkb


namespace std {
template <> struct is_error_code_enum<vkb::InstanceError> : true_type {};
template <> struct is_error_code_enum<vkb::PhysicalDeviceError> : true_type {};
template <> struct is_error_code_enum<vkb::QueueError> : true_type {};
template <> struct is_error_code_enum<vkb::DeviceError> : true_type {};
template <> struct is_error_code_enum<vkb::SwapchainError> : true_type {};
template <> struct is_error_code_enum<vkb::SwapchainManagerError> : true_type {};

} // namespace std
