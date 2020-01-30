#include "Swapchain.h"

namespace vkbs
{
namespace detail
{
VkSurfaceFormatKHR choose_swapchain_surface_format (std::vector<VkSurfaceFormatKHR> const& availableFormats)
{
	for (const auto& availableFormat : availableFormats)
	{
		if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
		{
			return availableFormat;
		}
	}

	return availableFormats[0];
}

VkPresentModeKHR choose_swap_present_mode (std::vector<VkPresentModeKHR> const& availablePresentModes)
{
	for (const auto& availablePresentMode : availablePresentModes)
	{
		if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR)
		{
			return availablePresentMode;
		}
	}

	return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D choose_swap_extent (
    VkSurfaceCapabilitiesKHR const& capabilities, uint32_t desired_width, uint32_t desired_height)
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
	if (!surface_support.has_value ())
		return detail::Error<VkResult>{ surface_support.error ().error_code, "can't get surface support" };
	VkSurfaceFormatKHR surfaceFormat =
	    detail::choose_swapchain_surface_format (surface_support.value ().formats);
	VkPresentModeKHR presentMode = detail::choose_swap_present_mode (surface_support.value ().present_modes);
	VkExtent2D extent = detail::choose_swap_extent (surface_support.value ().capabilities);

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
	swapchain_create_info.imageFormat = surfaceFormat.format;
	swapchain_create_info.imageColorSpace = surfaceFormat.colorSpace;
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
	swapchain_create_info.presentMode = presentMode;
	swapchain_create_info.clipped = VK_TRUE;
	swapchain_create_info.oldSwapchain = info.old_swapchain;
	Swapchain swapchain;
	VkResult res = vkCreateSwapchainKHR (info.device, &swapchain_create_info, nullptr, &swapchain.swapchain);
	if (res != VK_SUCCESS)
	{
		return detail::Error<VkResult>{ res, "Failed to create swapchain" };
	}
	auto swapchain_images =
	    detail::get_vector<VkImage> (vkGetSwapchainImagesKHR, info.device, swapchain.swapchain);

	swapchain.image_format = surfaceFormat.format;
	swapchain.extent = extent;

	return swapchain;
}
detail::Expected<Swapchain, VkResult> SwapchainBuilder::recreate (Swapchain const& swapchain)
{
	info.old_swapchain = swapchain.swapchain;
	return build ();
}

void SwapchainBuilder::destroy (Swapchain const& swapchain)
{
	vkDestroySwapchainKHR (swapchain.device, swapchain.swapchain, swapchain.allocator);
}


SwapchainBuilder& SwapchainBuilder::set_desired_format (VkFormat format)
{
	info.desired_format = format;
	return *this;
}
SwapchainBuilder& SwapchainBuilder::set_fallback_format (VkFormat format)
{
	info.fallback_format = format;
	return *this;
}
SwapchainBuilder& SwapchainBuilder::set_desired_present_mode (VkPresentModeKHR present_mode)
{
	info.desired_present_mode = present_mode;
	return *this;
}
SwapchainBuilder& SwapchainBuilder::set_fallback_present_mode (VkPresentModeKHR present_mode)
{
	info.fallback_present_mode = present_mode;
	return *this;
}



} // namespace vkbs