#pragma once

#include <stdio.h>

#include <memory>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "../src/VkBootstrap.h"

GLFWwindow* create_window_glfw ()
{
	glfwInit ();
	glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
	return glfwCreateWindow (640, 480, "Vulkan Triangle", NULL, NULL);
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
		const char* error_msg;
		int ret = glfwGetError (&error_msg);
		if (ret != 0)
		{
			std::cout << ret << " ";
			if (error_msg != nullptr) std::cout << error_msg;
			std::cout << "\n";
		}
		surface = nullptr;
	}
	return surface;
}