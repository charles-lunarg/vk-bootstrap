#include "common.h"

#include <catch2/catch.hpp>

// TODO
// Getting queues
// get dedicated vs distinct compute queues
// Swapchain creation
// Swapchain recreation
// changing present modes and/or image formats

TEST_CASE ("Instance with surface") {
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

TEST_CASE ("basic instance") {
	vkb::InstanceBuilder builder;

	auto instance_ret =
	    builder.request_validation_layers ()
	        .set_app_name ("test")
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
	        .require_api_version (1, 2, 111)
	        .build ();

	REQUIRE (instance_ret.has_value ());

	vkb::destroy_instance (instance_ret.value ());
}

TEST_CASE ("headless instance") {
	vkb::InstanceBuilder builder;

	auto instance_ret =
	    builder.request_validation_layers ()
	        .set_headless ()
	        .set_app_version (4, 5, 6)
	        .set_app_name ("headless")
	        .set_engine_name ("nick")
	        .require_api_version (1, 0, 34)
	        .use_default_debug_messenger ()
	        .add_validation_feature_enable (VkValidationFeatureEnableEXT::VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT)
	        .add_validation_feature_disable (VkValidationFeatureDisableEXT::VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT)
	        .add_validation_disable (VkValidationCheckEXT::VK_VALIDATION_CHECK_SHADERS_EXT)
	        .build ();
	REQUIRE (instance_ret.has_value ());
	vkb::destroy_instance (instance_ret.value ());
}
