#include "vulkan_library_loader.hpp"

#include "vulkan_mock.hpp"
#include "vulkan_mock_setup.hpp"

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
        auto instance_ret = instance_builder.require_api_version(1, 1, 0).use_default_debug_messenger().build();
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

TEST_CASE("SystemInfo Check Instance API Version", "[VkBootstrap.instance_api_version]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    auto info_ret = vkb::SystemInfo::get_system_info();
    REQUIRE(info_ret);
    auto system_info = info_ret.value();
    REQUIRE(system_info.is_instance_version_available(VK_MAKE_API_VERSION(0, 1, 0, 0)));
    REQUIRE(system_info.is_instance_version_available(VK_MAKE_API_VERSION(0, 1, 1, 0)));
    REQUIRE(system_info.is_instance_version_available(VK_MAKE_API_VERSION(0, 1, 2, 0)));
    REQUIRE(!system_info.is_instance_version_available(VK_MAKE_API_VERSION(0, 1, 3, 0)));
    REQUIRE(!system_info.is_instance_version_available(VK_MAKE_API_VERSION(0, 1, 4, 0)));

    REQUIRE(system_info.is_instance_version_available(1, 0));
    REQUIRE(system_info.is_instance_version_available(1, 1));
    REQUIRE(system_info.is_instance_version_available(1, 2));
    REQUIRE(!system_info.is_instance_version_available(1, 3));
    REQUIRE(!system_info.is_instance_version_available(1, 4));
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

TEST_CASE("Minimum instance API version", "[VkBootstrap.api_version]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_3;
    mock.physical_devices_details[0].properties.deviceID = 1;
    add_basic_physical_device(mock).properties.apiVersion = VK_API_VERSION_1_4;
    mock.physical_devices_details[1].properties.deviceID = 2;
    {
        auto ret = vkb::InstanceBuilder{}.set_headless().require_api_version(1, 4).set_minimum_instance_version(1, 2).build();
        REQUIRE(ret);
        auto pd_ret = vkb::PhysicalDeviceSelector{ ret.value() }.select();
        REQUIRE(pd_ret);
        REQUIRE(pd_ret.value().properties.deviceID == 2);
    }
    {
        auto ret = vkb::InstanceBuilder{}
                       .set_headless()
                       .require_api_version(VK_MAKE_API_VERSION(0, 1, 4, 0))
                       .set_minimum_instance_version(VK_MAKE_API_VERSION(0, 1, 2, 0))
                       .build();
        REQUIRE(ret);
        auto pd_ret = vkb::PhysicalDeviceSelector{ ret.value() }.select();
        REQUIRE(pd_ret);
        REQUIRE(pd_ret.value().properties.deviceID == 2);
    }
}
TEST_CASE("Minimum instance API version lower than VkPhysicalDevice", "[VkBootstrap.api_version]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_3;
    mock.physical_devices_details[0].properties.deviceID = 1;
    {
        auto ret = vkb::InstanceBuilder{}.set_headless().require_api_version(1, 4).set_minimum_instance_version(1, 2).build();
        REQUIRE(ret);
        auto pd_ret = vkb::PhysicalDeviceSelector{ ret.value() }.select();
        REQUIRE(pd_ret.error() == vkb::PhysicalDeviceError::no_suitable_device);
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
            REQUIRE(phys_dev_ret.has_value());

            REQUIRE(phys_dev_ret.value().are_extension_features_present(descriptor_indexing_features));

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            vkb::destroy_device(device_ret.value());
        }
        vkb::destroy_instance(instance);
    }
}

TEST_CASE("Adding Optional Extension Features", "[VkBootstrap.enable_features_if_present]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_1;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_1;
    mock.instance_extensions.push_back(get_extension_properties("VK_KHR_get_physical_device_properties2"));
    auto vulkan_10_features = VkPhysicalDeviceFeatures{};
    vulkan_10_features.multiViewport = true;
    mock.physical_devices_details[0].features = vulkan_10_features;

    auto vulkan_11_features = VkPhysicalDeviceVulkan11Features{};
    vulkan_11_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
    vulkan_11_features.shaderDrawParameters = true;
    mock.physical_devices_details[0].add_features_pNext_struct(vulkan_11_features);

    auto vulkan_12_features = VkPhysicalDeviceVulkan12Features{};
    // Forget to set this sType - let vk-bootstrap deal with it
    vulkan_12_features.bufferDeviceAddress = true;
    mock.physical_devices_details[0].add_features_pNext_struct(vulkan_12_features);


    GIVEN("A working instance and physical device which has a VkPhysicalDeviceVulkan12Features in its features pNext "
          "chain") {
        auto instance = get_headless_instance();

        VkPhysicalDeviceVulkan12Features physical_device_features_12{};
        physical_device_features_12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
        physical_device_features_12.bufferDeviceAddress = true;

        vkb::PhysicalDeviceSelector selector(instance);
        selector.add_required_extension_features(physical_device_features_12);
        {

            SECTION("Require enable_features_if_present to work with an empty feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceFeatures phys_dev_features_empty{};
                REQUIRE(phys_dev.enable_features_if_present(phys_dev_features_empty));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                vkb::destroy_device(device);
            }
            SECTION("Require enable_features_if_present to fail with an unsupported feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceFeatures phys_dev_features_bad{};
                phys_dev_features_bad.depthClamp = true;
                REQUIRE(!phys_dev.enable_features_if_present(phys_dev_features_bad));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                REQUIRE(!mock.physical_devices_details.at(0).created_device_details.at(0).features.depthClamp);
                vkb::destroy_device(device);
            }
            SECTION("Require enable_features_if_present to work with a supported feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceFeatures phys_dev_features_good{};
                phys_dev_features_good.multiViewport = true;
                REQUIRE(phys_dev.enable_features_if_present(phys_dev_features_good));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                REQUIRE(mock.physical_devices_details.at(0).created_device_details.at(0).features.multiViewport);
                vkb::destroy_device(device);
            }

            SECTION("Require enable_extension_features_if_present to work with an empty 1.1 feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceVulkan11Features phys_dev_vulkan_11_features{};
                phys_dev_vulkan_11_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
                REQUIRE(phys_dev.enable_extension_features_if_present(phys_dev_vulkan_11_features));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                vkb::destroy_device(device);
            }
            SECTION("Require enable_extension_features_if_present to fail with an unsupported 1.1 feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceVulkan11Features phys_dev_vulkan_11_features{};
                phys_dev_vulkan_11_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
                phys_dev_vulkan_11_features.multiview = true;
                REQUIRE(!phys_dev.enable_extension_features_if_present(phys_dev_vulkan_11_features));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                auto* s = reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(
                    &mock.physical_devices_details.at(0).created_device_details.at(0).features_pNextChain.at(0));
                REQUIRE(s->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);
                vkb::destroy_device(device);
            }
            SECTION("Require enable_extension_features_if_present to work with a supported 1.1 feature struct") {
                auto phys_dev = selector.select().value();
                VkPhysicalDeviceVulkan11Features phys_dev_vulkan_11_features{};
                phys_dev_vulkan_11_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
                phys_dev_vulkan_11_features.shaderDrawParameters = true;
                REQUIRE(phys_dev.enable_extension_features_if_present(phys_dev_vulkan_11_features));
                auto device = vkb::DeviceBuilder(phys_dev).build().value();
                auto* s = reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(
                    &mock.physical_devices_details.at(0).created_device_details.at(0).features_pNextChain.at(1));
                REQUIRE(s->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);
                REQUIRE(s->shaderDrawParameters);
                vkb::destroy_device(device);
            }
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
            REQUIRE(phys_dev_ret.has_value());

            REQUIRE(phys_dev_ret.value().are_extension_features_present(descriptor_indexing_features));

            VkPhysicalDeviceASTCDecodeFeaturesEXT astc_features{};
            astc_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
            astc_features.decodeModeSharedExponent = true;
            REQUIRE(!phys_dev_ret.value().are_extension_features_present(astc_features));

            VkPhysicalDeviceDescriptorIndexingFeaturesEXT unsupported_descriptor_indexing_features{};
            unsupported_descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
            unsupported_descriptor_indexing_features.runtimeDescriptorArray = true;
            unsupported_descriptor_indexing_features.descriptorBindingUniformTexelBufferUpdateAfterBind = true;
            REQUIRE(!phys_dev_ret.value().are_extension_features_present(unsupported_descriptor_indexing_features));

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
            REQUIRE(phys_dev_ret.has_value());

            REQUIRE(!phys_dev_ret.value().are_extension_features_present(descriptor_indexing_features));

            VkPhysicalDeviceASTCDecodeFeaturesEXT astc_features{};
            astc_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
            astc_features.decodeModeSharedExponent = true;
            REQUIRE(!phys_dev_ret.value().are_extension_features_present(astc_features));

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
            REQUIRE(phys_dev_ret.has_value());

            REQUIRE(phys_dev_ret.value().are_extension_features_present(descriptor_indexing_features));

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
            features_12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
            features_12.bufferDeviceAddress = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_required_features_11(features_11).set_required_features_12(features_12).select();
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            auto* s1 = reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(
                &mock.physical_devices_details.at(0).created_device_details.at(0).features_pNextChain.at(0));
            REQUIRE(s1->multiview);
            auto* s2 = reinterpret_cast<VkPhysicalDeviceVulkan12Features*>(
                &mock.physical_devices_details.at(0).created_device_details.at(0).features_pNextChain.at(1));
            REQUIRE(s2->bufferDeviceAddress);

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
            REQUIRE(!phys_dev_ret.has_value());
        }
        vkb::destroy_instance(instance);
    }
}

TEST_CASE("Add required features in multiple calls", "[VkBootstrap.required_features]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].features.independentBlend = true;
    mock.physical_devices_details[0].features.shaderInt64 = true;

    GIVEN("A working instance") {
        auto instance = get_headless_instance(1); // make sure we use 1.1
        SECTION("Requires a device that supports independentBlend and shaderInt64") {
            VkPhysicalDeviceFeatures features1{};
            features1.independentBlend = true;
            VkPhysicalDeviceFeatures features2{};
            features2.shaderInt64 = true;

            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_required_features(features1).set_required_features(features2).select();
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());

            REQUIRE(mock.physical_devices_details.at(0).created_device_details.at(0).features.independentBlend);
            REQUIRE(mock.physical_devices_details.at(0).created_device_details.at(0).features.shaderInt64);

            vkb::destroy_device(device_ret.value());
        }
        vkb::destroy_instance(instance);
    }
}

TEST_CASE("Add required extension features in multiple calls", "[VkBootstrap.required_features]") {
    VulkanMock& mock = get_and_setup_default();
    mock.api_version = VK_API_VERSION_1_2;
    mock.physical_devices_details[0].properties.apiVersion = VK_API_VERSION_1_2;

    auto mock_vulkan_11_features = VkPhysicalDeviceVulkan11Features{};
    mock_vulkan_11_features.multiview = true;
    mock_vulkan_11_features.samplerYcbcrConversion = true;
    mock.physical_devices_details[0].add_features_pNext_struct(mock_vulkan_11_features);

    GIVEN("A working instance") {
        auto instance = get_headless_instance(1); // make sure we use 1.1
        SECTION("Requires a device that supports multiview and samplerYcbcrConversion") {
            VkPhysicalDeviceVulkan11Features features1{};
            features1.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
            features1.multiview = true;

            VkPhysicalDeviceVulkan11Features features2{};
            features2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
            features2.samplerYcbcrConversion = true;


            vkb::PhysicalDeviceSelector selector(instance);
            auto phys_dev_ret = selector.set_required_features_11(features1).set_required_features_11(features2).select();
            REQUIRE(phys_dev_ret.has_value());

            vkb::DeviceBuilder device_builder(phys_dev_ret.value());
            auto device_ret = device_builder.build();
            REQUIRE(device_ret.has_value());
            auto* s1 = reinterpret_cast<VkPhysicalDeviceVulkan11Features*>(
                &mock.physical_devices_details.at(0).created_device_details.at(0).features_pNextChain.at(0));
            REQUIRE(s1->multiview);
            REQUIRE(s1->samplerYcbcrConversion);

            vkb::destroy_device(device_ret.value());
        }
        vkb::destroy_instance(instance);
    }
}
