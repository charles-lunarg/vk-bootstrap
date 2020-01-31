#include <stdio.h>

#include <memory>
#include <iostream>

#include "VkBootstrap.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "catch2/catch.hpp"

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

	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
	if (!instance_ret)
	{
		std::cout << instance_ret.error ().msg << "\n";
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
	vkb::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}


int test_instance_basic ()
{

	vkb::InstanceBuilder builder;

	auto instance_ret =
	    builder.setup_validation_layers ()
	        .set_app_name ("test")
	        .set_debug_callback ([] (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	                                 VkDebugUtilsMessageTypeFlagsEXT messageType,
	                                 const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	                                 void* pUserData) -> VkBool32 {
		        auto ms = vkb::DebugMessageSeverity (messageSeverity);
		        auto mt = vkb::DebugMessageType (messageType);
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

	vkb::InstanceBuilder builder;

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
	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
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
	if (!phys_dev_ret.has_value ())
	{
		return -1;
	}
	vkb::destroy_instance (instance);
	destroy_window_glfw (window);
	return 0;
}

int test_device_creation ()
{
	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.set_default_debug_messenger ().build ();
	auto instance = instance_ret.value ();
	auto window = create_window_glfw ();
	auto surface = create_surface_glfw (instance.instance, window);

	vkb::PhysicalDeviceSelector selector (instance);
	auto phys_dev_ret = selector.set_surface (surface).select ();
	auto phys_dev = phys_dev_ret.value ();

	vkb::DeviceBuilder device_builder (phys_dev);
	auto dev_ret = device_builder.build ();
	if (!dev_ret.has_value ())
	{
		printf ("%s\n", dev_ret.error ().msg);
		return -1;
	}

	vkb::destroy_device (dev_ret.value ());
	vkb::destroy_instance (instance);
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