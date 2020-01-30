#include <stdio.h>

#include "VkBootstrap.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

GLFWwindow* create_window_glfw ()
{
	glfwInit ();
	glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
	return glfwCreateWindow (640, 480, "Window Title", NULL, NULL);
}
void destroy_window_glfw (GLFWwindow* window)
{
	glfwDestroyWindow (window);
	glfwTerminate ();
}
VkSurfaceKHR create_surface_glfw (VkInstance instance, GLFWwindow* window)
{
	VkSurfaceKHR surface = nullptr;
	VkResult err = glfwCreateWindowSurface (instance, window, NULL, &surface);
	if (err)
	{
		surface = nullptr;
	}
	return surface;
}
int test_happy_path ()
{
	auto window = create_window_glfw ();

	vkbs::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
	if (!instance_ret) return -1; // couldn't make instance
	vkbs::Instance instance = instance_ret.value ();

	auto surface = create_surface_glfw (instance.instance, window);

	vkbs::PhysicalDeviceSelector phys_device_selector;
	auto phys_device_ret = phys_device_selector.set_instance (instance).set_surface (surface).select ();
	if (!phys_device_ret) return -2; // couldn't select physical device
	vkbs::PhysicalDevice physical_device = phys_device_ret.value ();

	vkbs::DeviceBuilder device_builder;
	auto device_ret = device_builder.set_physical_device (physical_device).build ();
	if (!device_ret) return -3; // couldn't create device
	vkbs::Device device = device_ret.value ();

	// possible swapchain creation...

	vkbs::destroy_device (device);
	vkbs::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}


int test_instance_basic ()
{

	vkbs::InstanceBuilder builder;

	auto instance_ret =
	    builder.setup_validation_layers ()
	        .set_app_name ("test")
	        .set_debug_callback ([] (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	                                 VkDebugUtilsMessageTypeFlagsEXT messageType,
	                                 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	                                 void* pUserData) -> VkBool32 {
		        auto ms = vkbs::DebugMessageSeverity (messageSeverity);
		        auto mt = vkbs::DebugMessageType (messageType);
		        printf ("[%s: %s](user defined)\n%s\n", ms, mt, pCallbackData->pMessage);
		        return VK_FALSE;
	        })
	        .set_api_version (1, 2, 111)
	        .build ();
	if (!instance_ret.has_value ())
	{
		return 1;
	}
	return 0;
}

int test_instance_headless ()
{

	vkbs::InstanceBuilder builder;

	auto instance_ret = builder.setup_validation_layers ()
	                        .set_headless ()
	                        .set_app_version (4, 5, 6)
	                        .set_app_name ("headless")
	                        .set_engine_name ("nick")
	                        .set_api_version (1, 0, 34)
	                        .set_default_debug_messenger ()
	                        .build ();
	if (!instance_ret.has_value ())
	{
		return 1;
	}
	return 0;
}

int test_physical_device_selection ()
{
	vkbs::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
	auto instance = instance_ret.value ();
	auto window = create_window_glfw ();
	auto surface = create_surface_glfw (instance.instance, window);

	vkbs::PhysicalDeviceSelector selector;
	auto phys_dev_ret = selector.set_instance (instance)
	                        .set_surface (surface)
	                        .add_desired_extension (VK_KHR_MULTIVIEW_EXTENSION_NAME)
	                        .add_required_extension (VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME)
	                        .set_minimum_version (1, 0)
	                        .set_desired_version (1, 1)
	                        .select ();
	if (!phys_dev_ret.has_value ())
	{
		return -1;
	}
	vkbs::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}

int test_device_creation ()
{
	vkbs::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
	auto instance = instance_ret.value ();
	auto window = create_window_glfw ();
	auto surface = create_surface_glfw (instance.instance, window);

	vkbs::PhysicalDeviceSelector selector;
	auto phys_dev_ret = selector.set_instance (instance).set_surface (surface).select ();
	auto phys_dev = phys_dev_ret.value ();

	vkbs::DeviceBuilder device_builder;
	auto dev_ret = device_builder.set_physical_device (phys_dev).build ();
	if (!dev_ret.has_value ())
	{
		printf ("%s\n", dev_ret.error ().msg);
		return -1;
	}

	vkbs::destroy_device (dev_ret.value ());
	vkbs::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}

int main ()
{
	printf ("happy path\n");
	test_happy_path ();

	printf ("\nbasic instance\n");
	{
		auto ret = test_instance_basic ();
		if (ret != 0) printf ("test_failed\n");
	}
	printf ("\nheadless instance\n");
	{
		auto ret = test_instance_headless ();
		if (ret != 0) printf ("test_failed\n");
	}
	printf ("\nphysical device selection\n");
	{
		auto ret = test_physical_device_selection ();
		if (ret != 0) printf ("test_failed\n");
	}
	printf ("\ndevice creation\n");
	{
		auto ret = test_device_creation ();
		if (ret != 0) printf ("test_failed\n");
	}
}