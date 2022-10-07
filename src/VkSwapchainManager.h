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
 * Copyright © 2026 Charles Giessen (charles@lunarg.com)
 */

#pragma once

#include "VkBootstrap.h"

namespace vkb {

/**
 * The SwapchainManager is a utility which automates creating swapchain specific
resources, acquiring swapchain images, presenting said images, and re-creating the swapchain.
 * */

namespace detail {

const uint32_t NO_ACQUIRED_IMAGE_VALUE = UINT32_MAX;

} // namespace detail

// Struct returned from SwapchainManager::acquire_image()
struct SwapchainAcquireInfo {
    // image view to use this frame
    VkImageView image_view{};
    // image to use this frame
    VkImage image{};
    // index of the swapchain image to use this frame
    uint32_t image_index = detail::NO_ACQUIRED_IMAGE_VALUE;
    VkSemaphore signal_semaphore{};
    VkSemaphore wait_semaphore{};
};

/**
 * Swapchain Manager
 *
 * Creation:
 * Call the function `create(SwapchainBuilder const& builder, VkQueue present_queue)`, passing
 * in a vkb::SwapchainBuilder with the desired swapchain setup parameters and a VkQueue that the manager will present to
 * SwapchainManager will store the passed in SwapchainBuilder to use during calls to recreate().
 * This function will return a vkb::Swapchain, so that the application can
 * query the current extent, format, and usage flags of the created swapchain.
 *
 * Destruction:
 * To destroy the SwapchainManager, call `destroy()`. Additionally, SwapchainManager will call
 * `destroy()` automatically in its destructor.
 *
 * SYNCHRONIZATION GUARANTEES (or lack thereof):
 * The SwapchainManager does NOT have internal synchronization. Thus applications must never call any
 * of its functions from multiple threads at the same time. This is because the `VkSwapchainKHR` parameter in
 * vkAcquireNextImageKHR & vkQueuePresentKHR, and the oldSwapchain parameter VkSwapchainCreateInfoKHR are externally
 * synchronized, so these three calls can never be run concurrently.
 *
 * QUEUE SUBMISSION:
 * The SwapchainManager presents to the VkQueue passed into `create()`. Thus, the user must guarantee that calling `present()`
 * does not overlap with any other calls which use the same queue (which in most cases is the graphics queue).
 *
 *
 * Example Initialization of SwapchainManager:
 * {
 *     auto swapchain_manager_ret = vkb::SwapchainManager::create(vkb::SwapchainBuilder{ vk_device }, present_queue);
 *     if (!swapchain_manager_ret) {
 *         std::cout << swapchain_manager_ret.error().message() << "\n";
 *         return -1;
 *     }
 *     swapchain = renderer.swapchain_manager_ret.value();
 * }
 *
 * Example Application Usage during main rendering:
 * {
 *     auto acquire_ret = renderer.swapchain_manager.acquire_image();
 *     if (acquire_ret.matches_error(vkb::SwapchainManagerError::swapchain_out_of_date)) {
 *         should_recreate = true;
 *         return; //abort rendering this frame
 *     } else if (!acquire_ret.has_value()) {
 *         return; //error out
 *     }
 *
 *         //holds the image view, image index, and semaphores needed for submission
 *     auto acquire_info = acquire_ret.value();
 *     VkImageView image_view =  acquire_info.image_view;
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
 * The SwapchainManager internally keeps track of the current 'state' of the swapchain. These states are:
 * - ready_to_acquire: initial state, indicates is is safe to call `acquire_image`
 * - ready_to_present: set after acquiring, indicates it is ready to accept command buffers to submit.
 * - expired: the swapchain needs to be recreated, calling `acquire_image` while in this state will fail
 * - destroyed: the swapchain was destroyed (likely manually), prevents further usage of the SwapchainManager
 * After a successful call to `acquire_image()`, the state is set to `ready_to_present`
 * After a successful call to `present()`, the state is set back to `ready_to_present`
 * After a successful call to `recreate()`, the state is set back to `ready_to_acquire`
 * Note that a successful call indicates that the return value didn't produce an error *and* the `out_of_date` parameter
 * in `SwapchainAcquireInfo` or `SwapchainSubmitInfo` is false.
 *
 * Type Characteristics:
 * SwapchainManager contains a default constructor, allowing it to be created in null state and initialized at a later
 * point. SwapchainManager is a move-only type, due to it owning various Vulkan objects. Therefore it will make any
 * struct or class that has a SwapchainManager member into a move-only type.
 *
 * Informative Details - Semaphores:
 * SwapchainManager keeps all semaphore management internal, thus they are not an aspect a user
 * needs to be involved with.
 **/
class SwapchainManager {
    public:
    explicit SwapchainManager() = default;
    ~SwapchainManager() noexcept;

    Result<Swapchain> create(SwapchainBuilder builder, VkQueue present_queue) noexcept;
    void destroy() noexcept;

    SwapchainManager(SwapchainManager const& other) = delete;
    SwapchainManager& operator=(SwapchainManager const& other) = delete;
    SwapchainManager(SwapchainManager&& other) noexcept;
    SwapchainManager& operator=(SwapchainManager&& other) noexcept;

    // Primary API
    // Get a VkImageView handle to use in rendering
    Result<SwapchainAcquireInfo> acquire_image() noexcept;

    Result<std::monostate> present() noexcept;

    // Recreate the swapchain.
    // Width and height should be the desired width and height values to use. They must be greater than zero
    Result<Swapchain> recreate(uint32_t desired_width, uint32_t desired_height) noexcept;

    // Give ownership of the framebuffer(s) to the SwapchainManager to delete them when they are no longer in use
    void destroy_framebuffer(VkFramebuffer framebuffer) noexcept;
    void destroy_framebuffers(uint32_t framebuffer_count, const VkFramebuffer* framebuffers) noexcept;
    void destroy_framebuffers(std::vector<VkFramebuffer> const& framebuffers) noexcept;
    void destroy_framebuffers(std::vector<VkFramebuffer>&& framebuffers) noexcept;

    // Get info about the swapchain
    Result<Swapchain> get_swapchain() noexcept;

    // Returns a vector of swapchain images
    // The image handles become stale when recreate() is called
    std::vector<VkImage> get_swapchain_images() noexcept;
    // Returns a vector of swapchain image views managed by the SwapchainManager - they are freed automatically by
    // destroy() The image view handles become stale when recreate() is called
    std::vector<VkImageView> get_swapchain_image_views() noexcept;
    // The combined output of get_swapchain_images() and get_swapchain_image_views()
    std::pair<std::vector<VkImage>, std::vector<VkImageView>> get_swapchain_images_and_views() noexcept;

    // Access the internal builder. This is how an application can alter how the swapchain is recreated.
    SwapchainBuilder& get_swapchain_builder() noexcept;

    private:
    constexpr static uint32_t max_concurrent_acquires = 3;
    constexpr static uint32_t delay_delete_queue_depth = 3;

    struct DelaySets {
        std::vector<VkImage> images;
        std::vector<VkImageView> views;
        std::vector<VkFramebuffer> framebuffers;
        std::vector<VkSwapchainKHR> swapchains;
        std::vector<VkSemaphore> semaphores;
    };

    enum class Status {
        not_ready,
        ready_to_acquire,
        ready_to_present,
        expired,   // needs to be recreated
        destroyed, // no longer usable
    };
    VkDevice device = VK_NULL_HANDLE;
    struct Details {
        uint32_t instance_version = VKB_VK_API_VERSION_1_0;
        Status current_status = Status::not_ready;
        VkQueue present_queue{};

        // swapchain, its builder, current images & image views
        vkb::SwapchainBuilder builder;
        vkb::Swapchain current_swapchain;
        std::vector<VkImage> swapchain_images{};
        std::vector<VkImageView> swapchain_image_views{};

        uint32_t current_image_index = detail::NO_ACQUIRED_IMAGE_VALUE;
        std::vector<VkSemaphore> acquire_semaphores{};
        VkSemaphore next_acquire_semaphore{};
        std::vector<VkSemaphore> submit_semaphores{};

        PFN_vkAcquireNextImageKHR fp_vkAcquireNextImageKHR{};
        PFN_vkQueuePresentKHR fp_vkQueuePresentKHR{};
        PFN_vkCreateSemaphore fp_vkCreateSemaphore{};
        PFN_vkDestroyImage fp_vkDestroyImage{};
        PFN_vkDestroyImageView fp_vkDestroyImageView{};
        PFN_vkDestroyFramebuffer fp_vkDestroyFramebuffer{};
        PFN_vkDestroySemaphore fp_vkDestroySemaphore{};
        PFN_vkDestroySwapchainKHR fp_vkDestroySwapchainKHR{};

        uint32_t current_delete_index = 0;
        std::vector<DelaySets> delete_sets{};
    } detail;

    void delete_queue_clear_set(vkb::SwapchainManager::DelaySets& set) noexcept;

    Result<std::monostate> create_sync_resources() noexcept;
};
} // namespace vkb
