#include "common.h"

int test_happy_path () {
	printf ("happy path\n");

	auto window = create_window_glfw ();

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.use_default_debug_messenger ().build ();
	if (!instance_ret) {
		std::cout << static_cast<uint32_t> (instance_ret.error ().type) << "\n";
		return -1; // couldn't make instance
	}
	vkb::Instance instance = instance_ret.value ();
	printf ("made instance\n");

	auto surface = create_surface_glfw (instance.instance, window);

	vkb::PhysicalDeviceSelector phys_device_selector (instance);
	auto phys_device_ret = phys_device_selector.set_surface (surface).select ();
	if (!phys_device_ret) return -2; // couldn't select physical device
	vkb::PhysicalDevice physical_device = phys_device_ret.value ();
	printf ("made physical device\n");

	vkb::DeviceBuilder device_builder (physical_device);
	auto device_ret = device_builder.build ();
	if (!device_ret) return -1; // couldn't create device
	vkb::Device device = device_ret.value ();
	printf ("made device\n");

	// possible swapchain creation...

	vkb::destroy_device (device);
	destroy_surface (instance.instance, surface);
	vkb::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}


int test_instance_basic () {
	printf ("\nbasic instance\n");

	vkb::InstanceBuilder builder;

	auto instance_ret =
	    builder.request_validation_layers ()
	        .set_app_name ("test")
	        .set_debug_callback ([] (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	                                 VkDebugUtilsMessageTypeFlagsEXT messageType,
	                                 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	                                 void* pUserData) -> VkBool32 {
		        auto ms = vkb::to_string_message_severity (messageSeverity);
		        auto mt = vkb::to_string_message_type (messageType);
		        printf ("[%s: %s](user defined)\n%s\n", ms, mt, pCallbackData->pMessage);
		        return VK_FALSE;
	        })
	        .require_api_version (1, 2, 111)
	        .build ();
	if (!instance_ret.has_value ()) {
		return 1;
	}
	vkb::destroy_instance (instance_ret.value ());

	return 0;
}

int test_instance_headless () {
	printf ("\nheadless instance\n");

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
	if (!instance_ret.has_value ()) {
		return 1;
	}
	vkb::destroy_instance (instance_ret.value ());
	return 0;
}

int test_physical_device_selection () {
	printf ("\nphysical device selection\n");

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.use_default_debug_messenger ().build ();
	auto instance = instance_ret.value ();
	auto window = create_window_glfw ();
	auto surface = create_surface_glfw (instance.instance, window);

	vkb::PhysicalDeviceSelector selector (instance);
	auto phys_dev_ret = selector.set_surface (surface)
	                        .add_desired_extension (VK_KHR_MULTIVIEW_EXTENSION_NAME)
	                        .add_required_extension (VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME)
	                        .set_minimum_version (1, 0)
	                        .set_desired_version (1, 1)
	                        .select ();
	if (!phys_dev_ret.has_value ()) {
		return -1;
	}
	destroy_surface (instance.instance, surface);
	vkb::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}

int test_device_creation () {
	printf ("\ndevice creation\n");
	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.use_default_debug_messenger ().build ();
	if (!instance_ret.has_value ()) {
		printf ("couldn't create instance %i\n", static_cast<uint32_t> (instance_ret.error ().type));
		return -1;
	}
	auto instance = instance_ret.value ();

	auto window = create_window_glfw ();
	auto surface = create_surface_glfw (instance.instance, window);

	vkb::PhysicalDeviceSelector selector (instance);
	auto phys_dev_ret = selector.set_surface (surface).select ();
	auto phys_dev = phys_dev_ret.value ();
	if (!phys_dev_ret.has_value ()) {
		printf ("couldn't select device %i\n", static_cast<uint32_t> (phys_dev_ret.error ().type));
		return -1;
	}

	vkb::DeviceBuilder device_builder (phys_dev);
	auto dev_ret = device_builder.build ();
	if (!dev_ret.has_value ()) {
		printf ("couldn't create device %i\n", static_cast<uint32_t> (dev_ret.error ().type));
		return -1;
	}
	vkb::destroy_device (dev_ret.value ());
	destroy_surface (instance.instance, surface);
	vkb::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}

// TODO
// Migrate to Catch2
// Getting queues
// get dedicated vs distinct compute queues
// Swapchain creation
// Swapchain recreation
// changing present modes and/or image formats

int main () {
	test_happy_path ();
	test_instance_basic ();
	test_instance_headless ();
	test_physical_device_selection ();
	test_device_creation ();
}