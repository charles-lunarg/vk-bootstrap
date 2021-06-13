#include "common.h"

#include <catch2/catch.hpp>

vkb::Instance get_instance(uint32_t minor_version = 0) {
	auto instance_ret =
	    vkb::InstanceBuilder().request_validation_layers().require_api_version(1, minor_version).build();
	REQUIRE(instance_ret.has_value());
	return instance_ret.value();
}
vkb::Instance get_headless_instance(uint32_t minor_version = 0) {
	auto instance_ret = vkb::InstanceBuilder()
	                        .request_validation_layers()
	                        .require_api_version(1, minor_version)
	                        .set_headless()
	                        .build();
	REQUIRE(instance_ret.has_value());
	return instance_ret.value();
}

// TODO
// changing present modes and/or image formats

TEST_CASE("Instance with surface", "[VkBootstrap.bootstrap]") {
	GIVEN("A window and a vulkan instance") {

		auto window = create_window_glfw("Instance with surface");

		auto sys_info_ret = vkb::SystemInfo::get_system_info();
		REQUIRE(sys_info_ret);

		vkb::InstanceBuilder instance_builder;
		auto instance_ret = instance_builder.use_default_debug_messenger().build();
		REQUIRE(instance_ret);
		vkb::Instance instance = instance_ret.value();
		auto surface = create_surface_glfw(instance.instance, window);

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
			                        .set_desired_version(1, 1)
			                        .select();
			REQUIRE(phys_dev_ret.has_value());
		}

		vkb::destroy_surface(instance, surface);
		vkb::destroy_instance(instance);
		destroy_window_glfw(window);
	}
}

TEST_CASE("instance configuration", "[VkBootstrap.bootstrap]") {
	SECTION("custom debug callback") {
		vkb::InstanceBuilder builder;

		auto instance_ret =
		    builder.request_validation_layers()
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
		        .add_validation_feature_disable(
		            VkValidationFeatureDisableEXT::VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT)
		        .add_validation_disable(VkValidationCheckEXT::VK_VALIDATION_CHECK_SHADERS_EXT)
		        .build();
		REQUIRE(instance_ret.has_value());
		vkb::destroy_instance(instance_ret.value());
	}
}

TEST_CASE("Headless Vulkan", "[VkBootstrap.bootstrap]") {
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

	auto window = create_window_glfw("Device Configuration");
	auto instance = get_instance(1);
	auto surface = create_surface_glfw(instance.instance, window);

	vkb::PhysicalDeviceSelector phys_device_selector(instance);

	auto phys_device_ret = phys_device_selector.set_minimum_version(1, 1).set_surface(surface).select();
	REQUIRE(phys_device_ret.has_value());
	auto phys_device = phys_device_ret.value();


	SECTION("Custom queue setup") {
		std::vector<vkb::CustomQueueDescription> queue_descriptions;
		auto queue_families = phys_device.get_queue_families();
		for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
			if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
				queue_descriptions.push_back(vkb::CustomQueueDescription(
				    i, queue_families[i].queueCount, std::vector<float>(queue_families[i].queueCount, 1.0f)));
			}
		}
		if (phys_device.has_dedicated_compute_queue()) {
			for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
				if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
				    (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0 &&
				    (queue_families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) == 0)
					queue_descriptions.push_back(vkb::CustomQueueDescription(i,
					    queue_families[i].queueCount,
					    std::vector<float>(queue_families[i].queueCount, 1.0f)));
			}
		} else if (phys_device.has_separate_compute_queue()) {
			for (uint32_t i = 0; i < (uint32_t)queue_families.size(); i++) {
				if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
				    ((queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)) {
					queue_descriptions.push_back(vkb::CustomQueueDescription(i,
					    queue_families[i].queueCount,
					    std::vector<float>(queue_families[i].queueCount, 1.0f)));
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

TEST_CASE("Loading Dispatch Table", "[VkBootstrap.bootstrap]") {
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
	GIVEN("A working instance, window, surface, and device") {
		auto window = create_window_glfw("Swapchain");
		auto instance = get_instance(1);
		auto surface = create_surface_glfw(instance.instance, window);

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

			vkb::destroy_swapchain(swapchain_ret.value());
		}

		AND_THEN("Swapchain configuration") {
			vkb::SwapchainBuilder swapchain_builder(device);
			auto swapchain_ret =
			    swapchain_builder.set_desired_extent(256, 256)
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

			vkb::destroy_swapchain(recreated_swapchain_ret.value());
		}
		AND_THEN("Swapchain can be create with default gotten handles") {
			vkb::SwapchainBuilder swapchain_builder(
			    device.physical_device.physical_device, device.device, surface);
			auto swapchain_ret = swapchain_builder.build();
			REQUIRE(swapchain_ret.has_value());

			auto swapchain = swapchain_ret.value();

			auto recreated_swapchain_ret = swapchain_builder.set_old_swapchain(swapchain).build();
			REQUIRE(recreated_swapchain_ret.has_value());

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
	VkAllocationCallbacks allocation_callbacks{};
	allocation_callbacks.pfnAllocation = &shim_vkAllocationFunction;
	allocation_callbacks.pfnReallocation = &shim_vkReallocationFunction;
	allocation_callbacks.pfnFree = &shim_vkFreeFunction;

	auto window = create_window_glfw("Allocation Callbacks");
	vkb::InstanceBuilder builder;

	auto instance_ret = builder.request_validation_layers()
	                        .set_allocation_callbacks(&allocation_callbacks)
	                        .use_default_debug_messenger()
	                        .build();
	REQUIRE(instance_ret.has_value());
	auto surface = create_surface_glfw(instance_ret.value().instance, window, &allocation_callbacks);

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
	auto info_ret = vkb::SystemInfo::get_system_info();
	REQUIRE(info_ret);
	vkb::InstanceBuilder builder;
	auto ret = builder.build();
	REQUIRE(ret);
}

TEST_CASE("SystemInfo Loading Vulkan Manually", "[VkBootstrap.loading]") {
	VulkanLibrary vk_lib;
	REQUIRE(vk_lib.vkGetInstanceProcAddr != NULL);
	auto info_ret = vkb::SystemInfo::get_system_info(vk_lib.vkGetInstanceProcAddr);
	REQUIRE(info_ret);
	vkb::InstanceBuilder builder;
	auto ret = builder.build();
	REQUIRE(ret);
	vk_lib.close();
}

TEST_CASE("InstanceBuilder Loading Vulkan Automatically", "[VkBootstrap.loading]") {
	vkb::InstanceBuilder builder;
	auto ret = builder.build();
	REQUIRE(ret);
}

TEST_CASE("InstanceBuilder Loading Vulkan Manually", "[VkBootstrap.loading]") {
	VulkanLibrary vk_lib;
	REQUIRE(vk_lib.vkGetInstanceProcAddr != NULL);
	vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
	auto ret = builder.build();
	vk_lib.close();
}
TEST_CASE("ReLoading Vulkan Automatically", "[VkBootstrap.loading]") {
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
	{
		VulkanLibrary vk_lib;
		REQUIRE(vk_lib.vkGetInstanceProcAddr != NULL);
		vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
		auto ret = builder.build();
		REQUIRE(ret);
		vk_lib.close();
	}
	{
		VulkanLibrary vk_lib;
		REQUIRE(vk_lib.vkGetInstanceProcAddr != NULL);
		vkb::InstanceBuilder builder{ vk_lib.vkGetInstanceProcAddr };
		auto ret = builder.build();
		REQUIRE(ret);
		vk_lib.close();
	}
}

TEST_CASE("Querying Required Extension Features but with 1.0", "[VkBootstrap.select_features]") {
	GIVEN("A working instance") {
		auto instance = get_headless_instance();
		// Requires a device that supports runtime descriptor arrays via descriptor indexing extension.
		{
			VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
			descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
			descriptor_indexing_features.runtimeDescriptorArray = true;

			vkb::PhysicalDeviceSelector selector(instance);
			auto phys_dev_ret =
			    selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
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
	GIVEN("A working instance") {
		auto instance = get_headless_instance();
		// Requires a device that supports runtime descriptor arrays via descriptor indexing extension.
		{
			VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
			descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
			descriptor_indexing_features.runtimeDescriptorArray = true;

			vkb::PhysicalDeviceSelector selector(instance);
			auto phys_dev_ret =
			    selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
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

#if defined(VK_API_VERSION_1_1)
TEST_CASE("Querying Required Extension Features in 1.1", "[VkBootstrap.version]") {
	GIVEN("A working instance") {
		auto instance = get_headless_instance();
		// Requires a device that supports runtime descriptor arrays via descriptor indexing extension.
		{
			VkPhysicalDeviceDescriptorIndexingFeaturesEXT descriptor_indexing_features{};
			descriptor_indexing_features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT;
			descriptor_indexing_features.runtimeDescriptorArray = true;

			vkb::PhysicalDeviceSelector selector(instance);
			auto phys_dev_ret =
			    selector.add_required_extension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME)
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
#endif

#if defined(VK_API_VERSION_1_2)
TEST_CASE("Querying Vulkan 1.1 and 1.2 features", "[VkBootstrap.version]") {
	GIVEN("A working instance") {
		vkb::InstanceBuilder builder;
		auto instance = get_headless_instance();
		// Requires a device that supports multiview and bufferDeviceAddress
		{
			VkPhysicalDeviceVulkan11Features features_11{};
			features_11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
			features_11.multiview = true;
			VkPhysicalDeviceVulkan12Features features_12{};
			features_11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
			features_12.bufferDeviceAddress = true;

			vkb::PhysicalDeviceSelector selector(instance);
			auto phys_dev_ret =
			    selector.set_required_features_11(features_11).set_required_features_12(features_12).select();
			// Ignore if hardware support isn't true
			REQUIRE(phys_dev_ret.has_value());

			vkb::DeviceBuilder device_builder(phys_dev_ret.value());
			auto device_ret = device_builder.build();
			REQUIRE(device_ret.has_value());
			vkb::destroy_device(device_ret.value());
		}
		// protectedMemory should NOT be supported
		{
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

#endif