#include "vulkan_library_loader.hpp"

#include "vulkan_mock.hpp"

#include <algorithm>

#include <catch2/catch_test_macros.hpp>

vkb::Instance get_instance(uint32_t minor_version = 0) {
    auto instance_ret = vkb::InstanceBuilder().request_validation_layers().require_api_version(1, minor_version).build();
    REQUIRE(instance_ret.has_value());
    return instance_ret.value();
}
vkb::Instance get_headless_instance(uint32_t minor_version = 0) {
    auto instance_ret =
        vkb::InstanceBuilder().request_validation_layers().require_api_version(1, minor_version).set_headless().build();
    REQUIRE(instance_ret.has_value());
    return instance_ret.value();
}

VkExtensionProperties get_extension_properties(const char* extName) {
    VkExtensionProperties ext_props{};
    std::copy_n(extName, VK_MAX_EXTENSION_NAME_SIZE, ext_props.extensionName);
    return ext_props;
}

VulkanMock& get_and_setup_default() {
    VulkanMock& mock = *get_vulkan_mock();
    mock.instance_extensions.push_back(get_extension_properties(VK_KHR_SURFACE_EXTENSION_NAME));
#if defined(_WIN32)
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_win32_surface"));
#elif defined(__ANDROID__)
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_android_surface"));
#elif defined(_DIRECT2DISPLAY)
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_android_surface"));
#elif defined(__linux__)
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_xcb_surface"));
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_xlib_surface"));
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_wayland_surface"));
#elif defined(__APPLE__)
    mock.instance_extensions.push_back(get_extension_properties("VK_EXT_metal_surface"));
#endif
    mock.instance_extensions.push_back(get_extension_properties(VK_EXT_DEBUG_UTILS_EXTENSION_NAME));
    VulkanMock::PhysicalDeviceDetails physical_device_details{};
    physical_device_details.extensions.push_back(get_extension_properties(VK_KHR_SWAPCHAIN_EXTENSION_NAME));
    physical_device_details.properties.apiVersion = VK_API_VERSION_1_0;
    VkQueueFamilyProperties queue_family_properties{};
    queue_family_properties.queueCount = 1;
    queue_family_properties.queueFlags = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT;
    queue_family_properties.minImageTransferGranularity = { 1, 1, 1 };
    physical_device_details.queue_family_properties.push_back(queue_family_properties);
    mock.add_physical_device(std::move(physical_device_details));
    return mock;
}

VulkanMock::SurfaceDetails get_basic_surface_details() {
    VulkanMock::SurfaceDetails details;
    details.present_modes.push_back(VK_PRESENT_MODE_FIFO_KHR);
    details.surface_formats.push_back(VkSurfaceFormatKHR{ VK_FORMAT_R8G8B8_SRGB, VK_COLORSPACE_SRGB_NONLINEAR_KHR });
    details.capabilities.minImageCount = 2;
    details.capabilities.minImageExtent = { 600, 800 };
    details.capabilities.currentExtent = { 600, 800 };
    details.capabilities.supportedUsageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    return details;
}

// TODO
// changing present modes and/or image formats

TEST_CASE("Instance with surface", "[VkBootstrap.bootstrap]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_KHR_multiview"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_KHR_driver_properties"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_EXT_robustness2"));
    auto surface = mock.get_new_surface(get_basic_surface_details());
    GIVEN("A window and a vulkan instance") {

        auto sys_info_ret = vkb::SystemInfo::get_system_info();
        REQUIRE(sys_info_ret);

        vkb::InstanceBuilder instance_builder;
        auto instance_ret = instance_builder.require_api_version(1, 1, 0)
                                .set_minimum_instance_version(1, 0, 0)
                                .use_default_debug_messenger()
                                .build();
        REQUIRE(instance_ret);
        vkb::Instance instance = instance_ret.value();

        GIVEN("A default selected physical device") {
            vkb::PhysicalDeviceSelector phys_device_selector(instance);
            auto phys_device_ret = phys_device_selector.set_surface(surface).select();
            REQUIRE(phys_device_ret);
            vkb::PhysicalDevice physical_device = phys_device_ret.value();

            GIVEN("A device created with default parameters") {
                vkb::DeviceBuilder device_builder(physical_device);
                auto device_ret = device_builder.build();
                REQUIRE(device_ret);
                vkb::Device device = device_ret.value();

                // possible swapchain creation...

                vkb::destroy_device(device);
            }
        }

        THEN("Can select physical device with customized requirements") {
            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_surface(surface)
                                    .add_desired_extension(VK_KHR_MULTIVIEW_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME)
                                    .set_minimum_version(1, 0)
                                    .select();
            REQUIRE(phys_dev_ret.has_value());

            REQUIRE(phys_dev_ret->is_extension_present(VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME));
            REQUIRE(!phys_dev_ret->is_extension_present(VK_KHR_16BIT_STORAGE_EXTENSION_NAME));

            REQUIRE(phys_dev_ret->enable_extension_if_present(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME));
            REQUIRE(!phys_dev_ret->enable_extension_if_present(VK_KHR_16BIT_STORAGE_EXTENSION_NAME));

            const std::vector<const char*> extension_set_1 = { VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME, 
                VK_EXT_ROBUSTNESS_2_EXTENSION_NAME };
            const std::vector<const char*> extension_set_2 = { VK_KHR_16BIT_STORAGE_EXTENSION_NAME, 
                VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME };

            REQUIRE(phys_dev_ret->enable_extensions_if_present(extension_set_1));
            REQUIRE(!phys_dev_ret->enable_extensions_if_present(extension_set_2));

            auto device_ret = vkb::DeviceBuilder(phys_dev_ret.value()).build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }

        vkb::destroy_surface(instance, surface);
        vkb::destroy_instance(instance);
    }
    GIVEN("Two Instances") {
        vkb::InstanceBuilder instance_builder1;
        auto instance_ret1 = instance_builder1.use_default_debug_messenger().build();
        REQUIRE(instance_ret1);
        vkb::InstanceBuilder instance_builder2;
        auto instance_ret2 = instance_builder2.use_default_debug_messenger().build();
        REQUIRE(instance_ret2);

        vkb::destroy_instance(instance_ret1.value());
        vkb::destroy_instance(instance_ret2.value());
    }
}

TEST_CASE("instance configuration", "[VkBootstrap.bootstrap]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    SECTION("custom debug callback") {
        vkb::InstanceBuilder builder;

        auto instance_ret = builder.request_validation_layers()
                                .set_app_name("test app")
                                .set_app_version(1, 0, 0)
                                .set_engine_name("engine_name")
                                .set_engine_version(9, 9, 9)
                                .set_debug_callback([](VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void*
                                                        /*pUserData*/) -> VkBool32 {
                                    auto ms = vkb::to_string_message_severity(messageSeverity);
                                    auto mt = vkb::to_string_message_type(messageType);
                                    printf("[%s: %s](user defined)\n%s\n", ms, mt, pCallbackData->pMessage);
                                    return VK_FALSE;
                                })
                                .build();

        REQUIRE(instance_ret.has_value());

        vkb::destroy_instance(instance_ret.value());
    }
    SECTION("Validation configuration") {
        vkb::InstanceBuilder builder;

        auto instance_ret =
            builder.request_validation_layers()
                .require_api_version(1, 0, 34)
                .use_default_debug_messenger()
                .add_validation_feature_enable(VkValidationFeatureEnableEXT::VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT)
                .add_validation_feature_disable(VkValidationFeatureDisableEXT::VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT)
                .add_validation_disable(VkValidationCheckEXT::VK_VALIDATION_CHECK_SHADERS_EXT)
                .build();
        REQUIRE(instance_ret.has_value());
        vkb::destroy_instance(instance_ret.value());
    }
}

TEST_CASE("Headless Vulkan", "[VkBootstrap.bootstrap]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    auto instance = get_headless_instance();

    vkb::PhysicalDeviceSelector phys_device_selector(instance);
    auto phys_device_ret = phys_device_selector.select();
    REQUIRE(phys_device_ret.has_value());
    auto phys_device = phys_device_ret.value();

    vkb::DeviceBuilder device_builder(phys_device);
    auto device_ret = device_builder.build();
    REQUIRE(device_ret.has_value());
    vkb::destroy_device(device_ret.value());

    vkb::destroy_instance(instance);
}

TEST_CASE("Device Configuration", "[VkBootstrap.bootstrap]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
    auto instance = get_instance(1);
    auto surface = mock.get_new_surface(get_basic_surface_details());

    vkb::PhysicalDeviceSelector phys_device_selector(instance);

    auto phys_device_ret = phys_device_selector.set_minimum_version(1, 1).set_surface(surface).select();
    REQUIRE(phys_device_ret.has_value());
    auto phys_device = phys_device_ret.value();


    SECTION("Custom queue setup") {
        std::vector<vkb::CustomQueueDescription> queue_descriptions;
        auto queue_families = phys_device.get_queue_families();
        for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
            if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                queue_descriptions.push_back(
                    vkb::CustomQueueDescription(i, std::vector<float>(queue_families[i].queueCount, 1.0f)));
            }
        }
        if (phys_device.has_dedicated_compute_queue()) {
            for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
                if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
                    (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0 &&
                    (queue_families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) == 0)
                    queue_descriptions.push_back(
                        vkb::CustomQueueDescription(i, std::vector<float>(queue_families[i].queueCount, 1.0f)));
            }
        } else if (phys_device.has_separate_compute_queue()) {
            for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
                if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
                    ((queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)) {
                    queue_descriptions.push_back(
                        vkb::CustomQueueDescription(i, std::vector<float>(queue_families[i].queueCount, 1.0f)));
                }
            }
        }

        vkb::DeviceBuilder device_builder(phys_device);
        auto device_ret = device_builder.custom_queue_setup(queue_descriptions).build();
        REQUIRE(device_ret.has_value());
        vkb::destroy_device(device_ret.value());
    }

    SECTION("VkPhysicalDeviceFeatures2 in pNext Chain") {
        VkPhysicalDeviceShaderDrawParameterFeatures shader_draw_features{};
        shader_draw_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES;

        vkb::DeviceBuilder device_builder(phys_device_ret.value());
        auto device_ret = device_builder.add_pNext(&shader_draw_features).build();
        REQUIRE(device_ret.has_value());
        vkb::destroy_device(device_ret.value());
    }

    vkb::destroy_surface(instance, surface);
    vkb::destroy_instance(instance);
}


TEST_CASE("Select all Physical Devices", "[VkBootstrap.bootstrap]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
    std::copy_n("mocking_gpus_for_fun_and_profit", VK_MAX_DRIVER_NAME_SIZE, mock.physical_devices_details[0].properties.deviceName);

    auto instance = get_instance(1);
    auto surface = mock.get_new_surface(get_basic_surface_details());

    auto instance_dispatch_table = instance.make_table();
    // needs to successfully create an instance dispatch table
    REQUIRE(instance_dispatch_table.fp_vkEnumeratePhysicalDevices);


    vkb::PhysicalDeviceSelector phys_device_selector(instance, surface);

    auto phys_device_ret = phys_device_selector.select_devices();
    REQUIRE(phys_device_ret.has_value());
    auto phys_devices = phys_device_ret.value();

    REQUIRE(phys_devices.at(0).name.size() > 0);

    auto phys_device_names_ret = phys_device_selector.select_device_names();
    REQUIRE(phys_device_names_ret.has_value());
    REQUIRE(phys_device_names_ret.value().at(0).size() > 0);

    vkb::DeviceBuilder device_builder(phys_devices.at(0));
    auto device_ret = device_builder.build();
    REQUIRE(device_ret.has_value());
    auto dispatch_table = device_ret.value().make_table();
    // needs to successfully create a dispatch table
    REQUIRE(dispatch_table.fp_vkCreateCommandPool);
}

TEST_CASE("Loading Dispatch Table", "[VkBootstrap.bootstrap]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    auto instance = get_headless_instance(0);
    {
        vkb::PhysicalDeviceSelector selector(instance);
        auto phys_dev_ret = selector.select_first_device_unconditionally().select();
        REQUIRE(phys_dev_ret.has_value());

        vkb::DeviceBuilder device_builder(phys_dev_ret.value());
        auto device_ret = device_builder.build();
        REQUIRE(device_ret.has_value());
        auto dispatch_table = device_ret.value().make_table();

        // Create a basic Device specific type to test with
        VkFenceCreateInfo info{};
        info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;

        VkFence fence = VK_NULL_HANDLE;
        dispatch_table.createFence(&info, nullptr, &fence);
        REQUIRE(fence != VK_NULL_HANDLE);

        dispatch_table.destroyFence(fence, nullptr);
        vkb::destroy_device(device_ret.value());
    }
    vkb::destroy_instance(instance);
}

TEST_CASE("Swapchain", "[VkBootstrap.bootstrap]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
    auto surface = mock.get_new_surface(get_basic_surface_details());
    GIVEN("A working instance, window, surface, and device") {
        auto instance = get_instance(1);

        vkb::PhysicalDeviceSelector phys_device_selector(instance);
        auto phys_device_ret = phys_device_selector.set_surface(surface).select();
        REQUIRE(phys_device_ret.has_value());
        auto phys_device = phys_device_ret.value();

        vkb::DeviceBuilder device_builder(phys_device);
        auto device_ret = device_builder.build();
        REQUIRE(device_ret.has_value());
        vkb::Device device = device_ret.value();

        auto graphics_queue_index = device.get_queue_index(vkb::QueueType::graphics).value();
        auto present_queue_index = device.get_queue_index(vkb::QueueType::present).value();

        THEN("Swapchain can be made") {
            vkb::SwapchainBuilder swapchain_builder(device);
            auto swapchain_ret = swapchain_builder.build();
            REQUIRE(swapchain_ret.has_value());
            auto swapchain = swapchain_ret.value();

            THEN("Acquire swapchain images and views") {
                auto images = swapchain.get_images();
                REQUIRE(images.has_value());
                REQUIRE(images.value().size() > 0);

                auto image_views = swapchain.get_image_views();
                REQUIRE(image_views.has_value());
                REQUIRE(image_views.value().size() > 0);
                swapchain.destroy_image_views(image_views.value());
            }
            AND_THEN("Acquire swapchain images views with nullptr pNext chain") {
                auto image_views = swapchain.get_image_views(nullptr);
                REQUIRE(image_views.has_value());
                REQUIRE(image_views.value().size() > 0);
                swapchain.destroy_image_views(image_views.value());
            }
            AND_THEN("Acquire swapchain image views with valid pNext chain") {
                VkImageViewUsageCreateInfo usage = { VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO, nullptr, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT };
                auto image_views = swapchain.get_image_views(&usage);
                REQUIRE(image_views.has_value());
                REQUIRE(image_views.value().size() > 0);
                swapchain.destroy_image_views(image_views.value());
            }

            vkb::destroy_swapchain(swapchain_ret.value());
        }

        AND_THEN("Swapchain configuration") {
            vkb::SwapchainBuilder swapchain_builder(device);
            auto swapchain_ret = swapchain_builder.set_desired_extent(256, 256)
                                     .set_desired_format({ VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR })
                                     .set_desired_present_mode(VK_PRESENT_MODE_IMMEDIATE_KHR)
                                     .set_pre_transform_flags(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
                                     .set_composite_alpha_flags(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR)
                                     .set_clipped(false)
                                     .set_image_array_layer_count(1)
                                     .build();
            REQUIRE(swapchain_ret.has_value());

            vkb::destroy_swapchain(swapchain_ret.value());
        }
        AND_THEN("Swapchain defaults can be used") {
            vkb::SwapchainBuilder swapchain_builder(device);
            auto swapchain_ret = swapchain_builder.use_default_format_selection()
                                     .use_default_present_mode_selection()
                                     .use_default_image_usage_flags()
                                     .build();
            REQUIRE(swapchain_ret.has_value());

            vkb::destroy_swapchain(swapchain_ret.value());
        }
        AND_THEN("Swapchain can be recreated") {
            vkb::SwapchainBuilder swapchain_builder(device);
            auto swapchain_ret = swapchain_builder.build();
            REQUIRE(swapchain_ret.has_value());

            auto swapchain = swapchain_ret.value();

            auto recreated_swapchain_ret = swapchain_builder.set_old_swapchain(swapchain).build();
            REQUIRE(recreated_swapchain_ret.has_value());

            vkb::destroy_swapchain(swapchain_ret.value());
            vkb::destroy_swapchain(recreated_swapchain_ret.value());
        }
        AND_THEN("Swapchain can be created from individual handles") {
            vkb::SwapchainBuilder swapchain_builder(
                device.physical_device.physical_device, device.device, surface, graphics_queue_index, present_queue_index);
            auto swapchain_ret = swapchain_builder.build();
            REQUIRE(swapchain_ret.has_value());

            auto swapchain = swapchain_ret.value();

            auto recreated_swapchain_ret = swapchain_builder.set_old_swapchain(swapchain).build();
            REQUIRE(recreated_swapchain_ret.has_value());

            vkb::destroy_swapchain(swapchain_ret.value());
            vkb::destroy_swapchain(recreated_swapchain_ret.value());
        }
        AND_THEN("Swapchain can be create with default gotten handles") {
            vkb::SwapchainBuilder swapchain_builder(device.physical_device.physical_device, device.device, surface);
            auto swapchain_ret = swapchain_builder.build();
            REQUIRE(swapchain_ret.has_value());

            auto swapchain = swapchain_ret.value();

            auto recreated_swapchain_ret = swapchain_builder.set_old_swapchain(swapchain).build();
            REQUIRE(recreated_swapchain_ret.has_value());

            vkb::destroy_swapchain(swapchain_ret.value());
            vkb::destroy_swapchain(recreated_swapchain_ret.value());
        }

        vkb::destroy_device(device_ret.value());
        vkb::destroy_surface(instance, surface);
        vkb::destroy_instance(instance);
    }
}

void* VKAPI_PTR shim_vkAllocationFunction(
    void* /*pUserData*/, size_t size, size_t /*alignment*/, VkSystemAllocationScope /*allocationScope*/) {
    return malloc(size);
}
void* VKAPI_PTR shim_vkReallocationFunction(
    void* /*pUserData*/, void* pOriginal, size_t size, size_t /*alignment*/, VkSystemAllocationScope /*allocationScope*/) {
    return realloc(pOriginal, size);
}
void VKAPI_PTR shim_vkFreeFunction(void* /*pUserData*/, void* pMemory) { return free(pMemory); }


TEST_CASE("Allocation Callbacks", "[VkBootstrap.bootstrap]") {
    VulkanMock& mock = get_and_setup_default();
    auto surface = mock.get_new_surface(get_basic_surface_details());

    VkAllocationCallbacks allocation_callbacks{};
    allocation_callbacks.pfnAllocation = &shim_vkAllocationFunction;
    allocation_callbacks.pfnReallocation = &shim_vkReallocationFunction;
    allocation_callbacks.pfnFree = &shim_vkFreeFunction;

    vkb::InstanceBuilder builder;

    auto instance_ret = builder.request_validation_layers()
                            .set_allocation_callbacks(&allocation_callbacks)
                            .use_default_debug_messenger()
                            .build();
    REQUIRE(instance_ret.has_value());

    vkb::PhysicalDeviceSelector phys_device_selector(instance_ret.value());

    auto phys_device_ret = phys_device_selector.set_surface(surface).select();
    REQUIRE(phys_device_ret.has_value());
    auto phys_device = phys_device_ret.value();

    vkb::DeviceBuilder device_builder(phys_device);
    auto device_ret = device_builder.set_allocation_callbacks(&allocation_callbacks).build();
    REQUIRE(device_ret.has_value());
    vkb::Device device = device_ret.value();

    vkb::SwapchainBuilder swapchain_builder(device);
    auto swapchain_ret = swapchain_builder.set_allocation_callbacks(&allocation_callbacks).build();
    REQUIRE(swapchain_ret.has_value());
    // auto swapchain = swapchain_ret.value ();

    vkb::destroy_swapchain(swapchain_ret.value());
    vkb::destroy_device(device_ret.value());

    vkb::destroy_surface(instance_ret.value(), surface);
    vkb::destroy_instance(instance_ret.value());
}

TEST_CASE("SystemInfo Loading Vulkan Automatically", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    auto info_ret = vkb::SystemInfo::get_system_info();
    REQUIRE(info_ret);
    vkb::InstanceBuilder builder;
    auto ret = builder.build();
    REQUIRE(ret);
}

TEST_CASE("SystemInfo Loading Vulkan Manually", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    VulkanLibrary vk_lib;
    REQUIRE(vk_lib.vkGetInstanceProcAddr);
    auto info_ret = vkb::SystemInfo::get_system_info(vk_lib.vkGetInstanceProcAddr);
    REQUIRE(info_ret);
    vkb::InstanceBuilder builder;
    auto ret = builder.build();
    REQUIRE(ret);
    vk_lib.close();
}

TEST_CASE("InstanceBuilder Loading Vulkan Automatically", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    vkb::InstanceBuilder builder;
    auto ret = builder.build();
    REQUIRE(ret);
}

TEST_CASE("InstanceBuilder Loading Vulkan Manually", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    VulkanLibrary vk_lib;
    REQUIRE(vk_lib.vkGetInstanceProcAddr);
    vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
    auto ret = builder.build();
    vk_lib.close();
}
TEST_CASE("ReLoading Vulkan Automatically", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    {
        vkb::InstanceBuilder builder;
        auto ret = builder.build();
        REQUIRE(ret);
    }
    {
        vkb::InstanceBuilder builder;
        auto ret = builder.build();
        REQUIRE(ret);
    }
}

TEST_CASE("ReLoading Vulkan Manually", "[VkBootstrap.loading]") {
    [[maybe_unused]] VulkanMock& mock = get_and_setup_default();
    {
        VulkanLibrary vk_lib;
        REQUIRE(vk_lib.vkGetInstanceProcAddr);
        vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
        auto ret = builder.build();
        REQUIRE(ret);
        vk_lib.close();
    }
    {
        VulkanLibrary vk_lib;
        REQUIRE(vk_lib.vkGetInstanceProcAddr);
        vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
        auto ret = builder.build();
        REQUIRE(ret);
        vk_lib.close();
    }
}

TEST_CASE("Querying Required Extension Features but with 1.0", "[VkBootstrap.select_features]") {
    VulkanMock& mock = get_and_setup_default();
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_get_physical_device_properties2"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_EXT_descriptor_indexing"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_KHR_maintenance3"));
    auto mock_descriptor_indexing_features = VkPhysicalDeviceDescriptorIndexingFeaturesEXT{};
    mock_descriptor_indexing_features.runtimeDescriptorArray = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_descriptor_indexing_features);
    GIVEN("A working instance") {
        auto instance = get_headless_instance();
        // Requires a device that supports runtime descriptor arrays via descriptor indexing extension.
        {
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
            descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            descriptor_indexing_features.runtimeDescriptorArray = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_MAINTENANCE3_EXTENSION_NAME)
                                    .add_required_extension_features(descriptor_indexing_features)
                                    .select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        vkb::destroy_instance(instance);
    }
}
TEST_CASE("Querying Required Extension Features", "[VkBootstrap.select_features]") {
    VulkanMock& mock = get_and_setup_default();
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_get_physical_device_properties2"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_EXT_descriptor_indexing"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_KHR_maintenance3"));
    auto mock_descriptor_indexing_features = VkPhysicalDeviceDescriptorIndexingFeaturesEXT{};
    mock_descriptor_indexing_features.runtimeDescriptorArray = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_descriptor_indexing_features);
    GIVEN("A working instance") {
        auto instance = get_headless_instance();
        // Requires a device that supports runtime descriptor arrays via descriptor indexing extension.
        {
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
            descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            descriptor_indexing_features.runtimeDescriptorArray = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_MAINTENANCE3_EXTENSION_NAME)
                                    .add_required_extension_features(descriptor_indexing_features)
                                    .select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        vkb::destroy_instance(instance);
    }
}

TEST_CASE("Passing vkb classes to Vulkan handles", "[VkBootstrap.pass_class_to_handle]") {
    VulkanMock& mock = get_and_setup_default();
    auto surface = mock.get_new_surface(get_basic_surface_details());
    GIVEN("A working instance") {
        auto instance = get_instance();

        // Check if we can get instance functions.
        PFN_vkVoidFunction instanceFunction = instance.fp_vkGetInstanceProcAddr(instance, "vkEnumeratePhysicalDevices"); // validation layers should be provided.
        REQUIRE(instanceFunction);

        vkb::PhysicalDeviceSelector physicalDeviceSelector(instance);
        auto physicalDevice =
            physicalDeviceSelector.add_required_extension(VK_KHR_SWAPCHAIN_EXTENSION_NAME).set_surface(surface).select();
        REQUIRE(physicalDevice.has_value());
        vkb::DeviceBuilder deviceBuilder(physicalDevice.value());
        auto device = deviceBuilder.build();
        REQUIRE(device.has_value());

        // Check if we can get a device function address, passing vkb::Device to the function.
        PFN_vkVoidFunction deviceFunction = instance.fp_vkGetDeviceProcAddr(device.value(), "vkAcquireNextImageKHR");
        REQUIRE(deviceFunction);
    }
}

TEST_CASE("Querying Required Extension Features in 1.1", "[VkBootstrap.version]") {
    VulkanMock& mock = get_and_setup_default();
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_get_physical_device_properties2"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_EXT_descriptor_indexing"));
    mock.physical_devices_details[0].extensions.push_back(get_extension_properties("VK_KHR_maintenance3"));
    auto mock_descriptor_indexing_features = VkPhysicalDeviceDescriptorIndexingFeaturesEXT{};
    mock_descriptor_indexing_features.runtimeDescriptorArray = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_descriptor_indexing_features);
    GIVEN("A working instance") {
        auto instance = get_headless_instance();
        SECTION("Requires a device that supports runtime descriptor arrays via descriptor indexing extension.") {
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
            descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            descriptor_indexing_features.runtimeDescriptorArray = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_MAINTENANCE3_EXTENSION_NAME)
                                    .add_required_extension_features(descriptor_indexing_features)
                                    .select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        SECTION("Add a custom VkPhysicalDeviceFeatures2 pNext chain to the DeviceBuilder, without using "
                "add_required_extension_features()") {
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
            descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            descriptor_indexing_features.runtimeDescriptorArray = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_MAINTENANCE3_EXTENSION_NAME)
                                    .select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            VkPhysicalDeviceFeatures2 phys_dev_feats2{};
            phys_dev_feats2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
            phys_dev_feats2.pNext = reinterpret_cast<void*>(&descriptor_indexing_features);

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.add_pNext(&phys_dev_feats2).build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        SECTION(
            "Try to add a custom VkPhysicalDeviceFeatures2 pNext chain to the DeviceBuilder, resulting in an error") {
            VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
            descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            descriptor_indexing_features.runtimeDescriptorArray = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
                                    .add_required_extension(VK_KHR_MAINTENANCE3_EXTENSION_NAME)
                                    .add_required_extension_features(descriptor_indexing_features)
                                    .select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            VkPhysicalDeviceFeatures2 phys_dev_feats2{};
            phys_dev_feats2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
            phys_dev_feats2.pNext = reinterpret_cast<void*>(&descriptor_indexing_features);

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.add_pNext(&phys_dev_feats2).build();
            REQUIRE(device_ret.error() ==
                    vkb::DeviceError::VkPhysicalDeviceFeatures2_in_pNext_chain_while_using_add_required_extension_features);
        }

        vkb::destroy_instance(instance);
    }
}

TEST_CASE("Querying Vulkan 1.1 and 1.2 features", "[VkBootstrap.version]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_2;

    auto mock_vulkan_11_features = VkPhysicalDeviceVulkan11Features{};
    mock_vulkan_11_features.multiview = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_vulkan_11_features);

    auto mock_vulkan_12_features = VkPhysicalDeviceVulkan12Features{};
    mock_vulkan_12_features.bufferDeviceAddress = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_vulkan_12_features);

    GIVEN("A working instance") {
        auto instance = get_headless_instance(2); // make sure we use 1.2
        SECTION("Requires a device that supports multiview and bufferDeviceAddress") {
            VkPhysicalDeviceVulkan11Features features_11{};
            features_11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
            features_11.multiview = true;
            VkPhysicalDeviceVulkan12Features features_12{};
            features_11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
            features_12.bufferDeviceAddress = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_required_features_11(features_11).set_required_features_12(features_12).select();
            // Ignore if hardware support isn't true
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        mock.api_version = VK_API_VERSION_1_1;
        mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
        SECTION("protectedMemory should NOT be supported") {
            VkPhysicalDeviceVulkan11Features features_11{};
            features_11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
            features_11.protectedMemory = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_required_features_11(features_11).select();
            // Ignore if hardware support differs
            REQUIRE(!phys_dev_ret.has_value());
        }
        vkb::destroy_instance(instance);
    }
}
