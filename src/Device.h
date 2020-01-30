#pragma once

#include "Util.h"

#include "Instance.h"

namespace vkbs
{
namespace detail
{

struct SurfaceSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> present_modes;
};

Expected<SurfaceSupportDetails, VkResult> query_surface_support_details (
    VkPhysicalDevice phys_device, VkSurfaceKHR surface);

struct QueueFamilies
{
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

VkFormat find_supported_format (VkPhysicalDevice physical_device,
    const std::vector<VkFormat>& candidates,
    VkImageTiling tiling,
    VkFormatFeatureFlags features);

bool check_device_extension_support (VkPhysicalDevice device, std::vector<std::string> extensions);

detail::QueueFamilies find_queue_families (VkPhysicalDevice physDevice, VkSurfaceKHR windowSurface);

bool supports_features (VkPhysicalDeviceFeatures supported, VkPhysicalDeviceFeatures requested);

} // namespace detail

// ---- Physical Device ---- //

struct PhysicalDevice
{
	VkPhysicalDevice phys_device = VK_NULL_HANDLE;
	VkSurfaceKHR surface = VK_NULL_HANDLE;

	VkPhysicalDeviceProperties physical_device_properties{};
	VkPhysicalDeviceFeatures physical_device_features{};
	VkPhysicalDeviceMemoryProperties memory_properties{};

	detail::QueueFamilies queue_family_properties;
};

namespace detail
{
void populate_physical_device_details (PhysicalDevice physical_device);
} // namespace detail

struct PhysicalDeviceSelector
{
	public:
	PhysicalDeviceSelector (Instance instance);

	detail::Expected<PhysicalDevice, VkResult> select ();

	PhysicalDeviceSelector& set_surface (VkSurfaceKHR instance);

	PhysicalDeviceSelector& prefer_discrete (bool prefer_discrete = true);
	PhysicalDeviceSelector& prefer_integrated (bool prefer_integrated = true);
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
	struct PhysicalDeviceInfo
	{
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		bool headless = false;
	} info;

	struct SelectionCriteria
	{
		bool prefer_discrete = true;
		bool prefer_integrated = false;
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

	} criteria;

	enum class Suitable
	{
		yes,
		partial,
		no
	};

	Suitable is_device_suitable (VkPhysicalDevice phys_device);
};

// ---- Device ---- //

struct Device
{
	VkDevice device = VK_NULL_HANDLE;
	VkAllocationCallbacks* allocator = VK_NULL_HANDLE;
	PhysicalDevice physical_device;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
};

void destroy_device (Device device);

class DeviceBuilder
{
	public:
	DeviceBuilder (PhysicalDevice device);
	detail::Expected<Device, VkResult> build ();

	template <typename T> DeviceBuilder& add_pNext (T* structure);

	private:
	struct DeviceInfo
	{
		VkDeviceCreateFlags flags;
		VkBaseOutStructure* pNext_chain = nullptr;
		VkAllocationCallbacks* allocator = VK_NULL_HANDLE;
		PhysicalDevice physical_device;
		std::vector<std::string> extensions;
	} info;
};

// ---- Queue ---- //

namespace detail
{
VkQueue get_queue (Device const& device, uint32_t family, uint32_t index = 0);
}

detail::Expected<VkQueue, VkResult> get_queue_present (Device const& device);
detail::Expected<VkQueue, VkResult> get_queue_graphics (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_compute (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_transfer (Device const& device, uint32_t index = 0);
detail::Expected<VkQueue, VkResult> get_queue_sparse (Device const& device, uint32_t index = 0);



} // namespace vkbs