#include "common.h"

#include <catch2/catch.hpp>

// TODO
// Getting queues
// get dedicated vs distinct compute queues

// changing present modes and/or image formats

TEST_CASE ("Instance with surface", "[VkBootstrap.bootstrap]") {
	GIVEN ("A window and a vulkan instance") {

		auto window = create_window_glfw ();

		vkb::InstanceBuilder instance_builder;
		auto instance_ret = instance_builder.use_default_debug_messenger ().build ();
		REQUIRE (instance_ret);
		vkb::Instance instance = instance_ret.value ();
		auto surface = create_surface_glfw (instance.instance, window);

		GIVEN ("A default selected physical device") {
			vkb::PhysicalDeviceSelector phys_device_selector (instance);
			auto phys_device_ret = phys_device_selector.set_surface (surface).select ();
			REQUIRE (phys_device_ret);
			vkb::PhysicalDevice physical_device = phys_device_ret.value ();

			GIVEN ("A device created with default parameters") {
				vkb::DeviceBuilder device_builder (physical_device);
				auto device_ret = device_builder.build ();
				REQUIRE (device_ret);
				vkb::Device device = device_ret.value ();

				// possible swapchain creation...

				vkb::destroy_device (device);
			}
		}

		THEN ("Can select physical device with customized requirements") {
			vkb::PhysicalDeviceSelector selector (instance);
			auto phys_dev_ret = selector.set_surface (surface)
			                        .add_desired_extension (VK_KHR_MULTIVIEW_EXTENSION_NAME)
			                        .add_required_extension (VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME)
			                        .set_minimum_version (1, 0)
			                        .set_desired_version (1, 1)
			                        .select ();
			REQUIRE (phys_dev_ret.has_value ());
		}

		destroy_surface (instance.instance, surface);
		vkb::destroy_instance (instance);
		destroy_window_glfw (window);
	}
}

TEST_CASE ("instance configuration", "[VkBootstrap.bootstrap]") {
	SECTION ("custom debug callback") {
		vkb::InstanceBuilder builder;

		auto instance_ret =
		    builder.request_validation_layers ()
		        .set_app_name ("test app")
		        .set_app_version (1, 0, 0)
		        .set_engine_name ("engine_name")
		        .set_engine_version (9, 9, 9)
		        .set_debug_callback ([] (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		                                 VkDebugUtilsMessageTypeFlagsEXT messageType,
		                                 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		                                 void *
		                                 /*pUserData*/) -> VkBool32 {
			        auto ms = vkb::to_string_message_severity (messageSeverity);
			        auto mt = vkb::to_string_message_type (messageType);
			        printf ("[%s: %s](user defined)\n%s\n", ms, mt, pCallbackData->pMessage);
			        return VK_FALSE;
		        })
		        .build ();

		REQUIRE (instance_ret.has_value ());

		vkb::destroy_instance (instance_ret.value ());
	}
	SECTION ("Validation configuration") {
		vkb::InstanceBuilder builder;

		auto instance_ret =
		    builder.request_validation_layers ()
		        .require_api_version (1, 0, 34)
		        .use_default_debug_messenger ()
		        .add_validation_feature_enable (VkValidationFeatureEnableEXT::VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT)
		        .add_validation_feature_disable (
		            VkValidationFeatureDisableEXT::VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT)
		        .add_validation_disable (VkValidationCheckEXT::VK_VALIDATION_CHECK_SHADERS_EXT)
		        .build ();
		REQUIRE (instance_ret.has_value ());
		vkb::destroy_instance (instance_ret.value ());
	}
}

TEST_CASE ("Headless Vulkan", "[VkBootstrap.bootstrap]") {
	vkb::InstanceBuilder builder;

	auto instance_ret = builder.request_validation_layers ().set_headless ().build ();
	REQUIRE (instance_ret.has_value ());

	vkb::PhysicalDeviceSelector phys_device_selector (instance_ret.value ());
	auto phys_device_ret = phys_device_selector.select ();
	REQUIRE (phys_device_ret.has_value ());
	auto phys_device = phys_device_ret.value ();

	vkb::DeviceBuilder device_builder (phys_device);
	auto device_ret = device_builder.build ();
	REQUIRE (device_ret.has_value ());
	vkb::destroy_device (device_ret.value ());

	vkb::destroy_instance (instance_ret.value ());
}

TEST_CASE ("Device Configuration", "[VkBootstrap.bootstrap]") {

	auto window = create_window_glfw ();
	vkb::InstanceBuilder builder;

	auto instance_ret = builder.request_validation_layers ().build ();
	REQUIRE (instance_ret.has_value ());
	auto surface = create_surface_glfw (instance_ret.value ().instance, window);

	vkb::PhysicalDeviceSelector phys_device_selector (instance_ret.value ());

	auto phys_device_ret = phys_device_selector.set_surface (surface).select ();
	REQUIRE (phys_device_ret.has_value ());
	auto phys_device = phys_device_ret.value ();


	SECTION ("Custom queue setup") {
		std::vector<vkb::CustomQueueDescription> queue_descriptions;
		auto queue_families = phys_device.get_queue_families ();
		for (uint32_t i = 0; i < (uint32_t)queue_families.size (); i++) {
			if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
				queue_descriptions.push_back (vkb::CustomQueueDescription (
				    i, queue_families[i].queueCount, std::vector<float> (queue_families[i].queueCount, 1.0f)));
			}
		}
		if (phys_device.has_dedicated_compute_queue ()) {
			for (uint32_t i = 0; i < (uint32_t)queue_families.size (); i++) {
				if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
				    (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0 &&
				    (queue_families[i].queueFlags & VK_QUEUE_TRANSFER_BIT) == 0)
					queue_descriptions.push_back (vkb::CustomQueueDescription (i,
					    queue_families[i].queueCount,
					    std::vector<float> (queue_families[i].queueCount, 1.0f)));
			}
		} else if (phys_device.has_separate_compute_queue ()) {
			for (uint32_t i = 0; i < (uint32_t)queue_families.size (); i++) {
				if ((queue_families[i].queueFlags & VK_QUEUE_COMPUTE_BIT) &&
				    ((queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0)) {
					queue_descriptions.push_back (vkb::CustomQueueDescription (i,
					    queue_families[i].queueCount,
					    std::vector<float> (queue_families[i].queueCount, 1.0f)));
				}
			}
		}

		vkb::DeviceBuilder device_builder (phys_device);
		auto device_ret = device_builder.custom_queue_setup (queue_descriptions).build ();
		REQUIRE (device_ret.has_value ());
		vkb::destroy_device (device_ret.value ());
	}

	SECTION ("VkPhysicalDeviceFeatures2 in pNext Chain") {
		VkPhysicalDeviceFeatures2 phys_dev_feat_2{};

		vkb::DeviceBuilder device_builder (phys_device);
		auto device_ret = device_builder.add_pNext (&phys_dev_feat_2).build ();
		REQUIRE (device_ret.has_value ());
		vkb::destroy_device (device_ret.value ());
	}

	destroy_surface (instance_ret.value ().instance, surface);
	vkb::destroy_instance (instance_ret.value ());
}

TEST_CASE ("Swapchain", "[VkBootstrap.bootstrap]") {
	GIVEN ("A working instance, window, surface, and device") {
		auto window = create_window_glfw ();
		vkb::InstanceBuilder builder;

		auto instance_ret = builder.request_validation_layers ().build ();
		REQUIRE (instance_ret.has_value ());
		auto surface = create_surface_glfw (instance_ret.value ().instance, window);

		vkb::PhysicalDeviceSelector phys_device_selector (instance_ret.value ());
		auto phys_device_ret = phys_device_selector.set_surface (surface).select ();
		REQUIRE (phys_device_ret.has_value ());
		auto phys_device = phys_device_ret.value ();

		vkb::DeviceBuilder device_builder (phys_device);
		auto device_ret = device_builder.build ();
		REQUIRE (device_ret.has_value ());
		vkb::Device device = device_ret.value ();

		THEN ("Swapchain can be made") {
			vkb::SwapchainBuilder swapchain_builder (device);
			auto swapchain_ret = swapchain_builder.build ();
			REQUIRE (swapchain_ret.has_value ());
			auto swapchain = swapchain_ret.value ();

			THEN ("Acquire swapchain images and views") {
				auto images = swapchain.get_images ();
				REQUIRE (images.has_value ());
				REQUIRE (images.value ().size () > 0);

				auto image_views = swapchain.get_image_views ();
				REQUIRE (image_views.has_value ());
				REQUIRE (image_views.value ().size () > 0);
				swapchain.destroy_image_views (image_views.value ());
			}

			vkb::destroy_swapchain (swapchain_ret.value ());
		}

		AND_THEN ("Swapchain configuration") {
			vkb::SwapchainBuilder swapchain_builder (device);
			auto swapchain_ret =
			    swapchain_builder.set_desired_extent (256, 256)
			        .set_desired_format ({ VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR })
			        .set_desired_present_mode (VK_PRESENT_MODE_IMMEDIATE_KHR)
			        .build ();
			REQUIRE (swapchain_ret.has_value ());

			vkb::destroy_swapchain (swapchain_ret.value ());
		}
		AND_THEN ("Swapchain defaults can be used") {
			vkb::SwapchainBuilder swapchain_builder (device);
			auto swapchain_ret = swapchain_builder.use_default_format_selection ()
			                         .use_default_present_mode_selection ()
			                         .build ();
			REQUIRE (swapchain_ret.has_value ());

			vkb::destroy_swapchain (swapchain_ret.value ());
		}
		AND_THEN ("Swapchain can be recreated") {
			vkb::SwapchainBuilder swapchain_builder (device);
			auto swapchain_ret = swapchain_builder.build ();
			REQUIRE (swapchain_ret.has_value ());

			auto swapchain = swapchain_ret.value ();
			auto recreated_swapchain_ret = swapchain_builder.recreate (swapchain);
			REQUIRE (recreated_swapchain_ret.has_value ());

			vkb::destroy_swapchain (recreated_swapchain_ret.value ());
		}

		vkb::destroy_device (device_ret.value ());
		destroy_surface (instance_ret.value ().instance, surface);
		vkb::destroy_instance (instance_ret.value ());
	}
}

void* VKAPI_PTR shim_vkAllocationFunction (
    void* /*pUserData*/, size_t size, size_t /*alignment*/, VkSystemAllocationScope /*allocationScope*/) {
	return malloc (size);
}
void* VKAPI_PTR shim_vkReallocationFunction (
    void* /*pUserData*/, void* pOriginal, size_t size, size_t /*alignment*/, VkSystemAllocationScope /*allocationScope*/) {
	return realloc (pOriginal, size);
}
void VKAPI_PTR shim_vkFreeFunction (void* /*pUserData*/, void* pMemory) { return free (pMemory); }


TEST_CASE ("Allocation Callbacks", "[VkBootstrap.bootstrap]") {
	VkAllocationCallbacks allocation_callbacks{};
	allocation_callbacks.pfnAllocation = &shim_vkAllocationFunction;
	allocation_callbacks.pfnReallocation = &shim_vkReallocationFunction;
	allocation_callbacks.pfnFree = &shim_vkFreeFunction;

	auto window = create_window_glfw ();
	vkb::InstanceBuilder builder;

	auto instance_ret =
	    builder.request_validation_layers ().set_allocation_callbacks (&allocation_callbacks).build ();
	REQUIRE (instance_ret.has_value ());
	auto surface = create_surface_glfw (instance_ret.value ().instance, window);

	vkb::PhysicalDeviceSelector phys_device_selector (instance_ret.value ());

	auto phys_device_ret = phys_device_selector.set_surface (surface).select ();
	REQUIRE (phys_device_ret.has_value ());
	auto phys_device = phys_device_ret.value ();

	vkb::DeviceBuilder device_builder (phys_device);
	auto device_ret = device_builder.set_allocation_callbacks (&allocation_callbacks).build ();
	REQUIRE (device_ret.has_value ());
	vkb::Device device = device_ret.value ();

	vkb::SwapchainBuilder swapchain_builder (device);
	auto swapchain_ret = swapchain_builder.set_allocation_callbacks (&allocation_callbacks).build ();
	REQUIRE (swapchain_ret.has_value ());
	// auto swapchain = swapchain_ret.value ();

	vkb::destroy_swapchain (swapchain_ret.value ());
	vkb::destroy_device (device_ret.value ());

	destroy_surface (instance_ret.value ().instance, surface);
	vkb::destroy_instance (instance_ret.value ());
}
