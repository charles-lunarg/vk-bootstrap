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
 * Copyright © 2022 Charles Giessen (charles@lunarg.com)
 */

#pragma once

#include "VkBootstrap.h"

namespace vkb {
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
	ImagelessFramebufferBuilder& add_attachment(VkImageUsageFlags usage_flags, std::vector<VkFormat> const& formats);

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
	VkSemaphore signal_semaphore;
	VkSemaphore wait_semaphore;
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
 *     auto acquire_ret = renderer.swapchain_manager.acquire_image();
 *     if (!acquire_ret.has_value() && acquire_ret.error().value() ==
 *(int)vkb::SwapchainManagerError::swapchain_out_of_date) { should_recreate = true; return; //abort rendering this frame
 *     } else if (!acquire_ret.has_value()) {
 *         return; //error out
 *     }
 *
 *     auto acquire_info = acquire_ret.value(); //holds the image view, image index, and semaphores needed for
 *submission VkImageView image_view =  acquire_info.image_view;
 *
 *     // record command buffers that use image_view
 *
 *     // The semaphore that was passed into vkAcquireNextImageKHR (by the swapchain manager)
 *     VkSemaphore wait_semaphores[1] = { acquire_info.wait_semaphore }; //add in any user declared semaphores
 *
 *     // The semaphore that gets passed into vkQueuePresentKHR (by the swapchain manager)
 *     VkSemaphore signal_semaphores[1] = {  acquire_info.signal_semaphore }; //add in any user declared semaphores
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
 * Note that a successful call indicates that the return value didn't produce an error *and* the `out_of_date` parameter
 *in `SwapchainAcquireInfo` or `SwapchainSubmitInfo` is false.
 *
 * Type Characteristics:
 * SwapchainManager contains a default constructor, allowing it to be created in null state and initialized at a later
 *point. SwapchainManager is a move-only type, due to it owning various Vulkan objects. Therefore it will make any
 *struct or class that has a SwapchainManager member into a move-only type.
 *
 * Informative Details - Semaphores:
 * SwapchainManager keeps all semaphore management internal, thus they are not an aspect a user
 * needs to be involved with. However, it is possible to add additional wait and signal semaphores
 * in the call to vkQueueSubmit if so desired by passing in the semaphores into `submit`.
 **/
class SwapchainManager {
	public:
	static Result<SwapchainManager> create(SwapchainBuilder const& builder) noexcept;

	explicit SwapchainManager() = default;
	~SwapchainManager() noexcept;
	void destroy() noexcept;

	SwapchainManager(SwapchainManager const& other) = delete;
	SwapchainManager& operator=(SwapchainManager const& other) = delete;
	SwapchainManager(SwapchainManager&& other) noexcept;
	SwapchainManager& operator=(SwapchainManager&& other) noexcept;

	// Primary API

	// Get a VkImageView handle to use in rendering
	Result<SwapchainAcquireInfo> acquire_image() noexcept;

	Result<detail::void_t> cancel_acquire_frame() noexcept;
	Result<detail::void_t> cancel_present_frame() noexcept;

	Result<detail::void_t> present() noexcept;

	// Recreate the swapchain, putting currently in-use internal resources in a delete queue
	Result<SwapchainInfo> recreate(uint32_t width = 0, uint32_t height = 0) noexcept;

	// Get info about the swapchain
	Result<SwapchainInfo> get_info() noexcept;

	// Get access to the swapchain and resources associated with it
	Result<SwapchainResources> get_swapchain_resources() noexcept;

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
		uint32_t instance_version = VKB_VK_API_VERSION_1_0;
		Status current_status = Status::ready_to_acquire;
		VkQueue graphics_queue{};
		VkQueue present_queue{};
		SwapchainInfo current_info{};
		uint32_t current_image_index = detail::INDEX_MAX_VALUE;
		PFN_vkGetDeviceQueue fp_vkGetDeviceQueue{};
		PFN_vkAcquireNextImageKHR fp_vkAcquireNextImageKHR{};
		PFN_vkQueuePresentKHR fp_vkQueuePresentKHR{};
		PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR{};
		PFN_vkCreateImageView fp_vkCreateImageView{};
		PFN_vkQueueSubmit fp_vkQueueSubmit{};
	} detail;

	explicit SwapchainManager(SwapchainBuilder const& builder,
	    Swapchain swapchain,
	    SwapchainResources resources,
	    PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR,
	    PFN_vkCreateImageView fp_vkCreateImageView) noexcept;

	void update_swapchain_info() noexcept;

	static Result<SwapchainResources> create_swapchain_resources(vkb::Swapchain swapchain,
	    uint32_t instance_version,
	    PFN_vkGetSwapchainImagesKHR fp_vkGetSwapchainImagesKHR,
	    PFN_vkCreateImageView fp_vkCreateImageView) noexcept;

	VkResult WaitForSemaphore(VkSemaphore semaphore) noexcept;
};
} // namespace vkb
