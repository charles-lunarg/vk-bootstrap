#pragma once

#include "Util.h"
#include "Instance.h"
#include "Device.h"

namespace vkbs
{
namespace detail
{
VkSurfaceFormatKHR choose_swapchain_surface_format (std::vector<VkSurfaceFormatKHR> const& availableFormats);
VkPresentModeKHR choose_swap_present_mode (std::vector<VkPresentModeKHR> const& availablePresentModes);
VkExtent2D choose_swap_extent (VkSurfaceCapabilitiesKHR const& capabilities);
} // namespace detail

struct Swapchain
{
	VkDevice device = VK_NULL_HANDLE;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;
	VkAllocationCallbacks* allocator = VK_NULL_HANDLE;
	std::vector<VkImage> images;
	VkFormat image_format = VK_FORMAT_UNDEFINED;
	VkExtent2D extent = { 0, 0 };
};

class SwapchainBuilder
{
	public:
	SwapchainBuilder (Device const& device);

	detail::Expected<Swapchain, VkResult> build ();
	detail::Expected<Swapchain, VkResult> recreate (Swapchain const& swapchain);
	void destroy (Swapchain const& swapchain);

	SwapchainBuilder& set_desired_format (VkFormat format);
	SwapchainBuilder& set_fallback_format (VkFormat format);

	SwapchainBuilder& set_desired_present_mode (VkPresentModeKHR present_mode);
	SwapchainBuilder& set_fallback_present_mode (VkPresentModeKHR present_mode);


	private:
	struct SwapchainInfo
	{
		VkDevice device = VK_NULL_HANDLE;
		PhysicalDevice physical_device;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		VkSwapchainKHR old_swapchain = VK_NULL_HANDLE;
		VkFormat desired_format = VK_FORMAT_R8G8B8A8_UNORM;
		VkFormat fallback_format = VK_FORMAT_R8G8B8A8_UNORM;
		VkPresentModeKHR desired_present_mode = VK_PRESENT_MODE_FIFO_KHR;
		VkPresentModeKHR fallback_present_mode = VK_PRESENT_MODE_FIFO_KHR;
		std::vector<VkPresentModeKHR> acceptable_present_modes;
		uint32_t desired_width = 256;
		uint32_t desired_height = 256;
	} info;
};
} // namespace vkbs