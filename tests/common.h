#pragma once

#include <stdio.h>

#include <memory>
#include <iostream>

#if defined(_WIN32)
#include <fcntl.h>
#define NOMINMAX
#include <windows.h>
#endif // _WIN32

#if defined(__linux__) || defined(__APPLE__)
#include <dlfcn.h>
#endif

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "../src/VkBootstrap.h"

GLFWwindow* create_window_glfw (const char* window_name = "", bool resize = true) {
	glfwInit ();
	glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
	if (!resize) glfwWindowHint (GLFW_RESIZABLE, GLFW_FALSE);

	return glfwCreateWindow (1024, 1024, window_name, NULL, NULL);
}
void destroy_window_glfw (GLFWwindow* window) {
	glfwDestroyWindow (window);
	glfwTerminate ();
}
VkSurfaceKHR create_surface_glfw (VkInstance instance, GLFWwindow* window) {
	VkSurfaceKHR surface = nullptr;
	VkResult err = glfwCreateWindowSurface (instance, window, NULL, &surface);
	if (err) {
		const char* error_msg;
		int ret = glfwGetError (&error_msg);
		if (ret != 0) {
			std::cout << ret << " ";
			if (error_msg != nullptr) std::cout << error_msg;
			std::cout << "\n";
		}
		surface = nullptr;
	}
	return surface;
}

struct VulkanLibrary {
#if defined(__linux__) || defined(__APPLE__)
	void* library;
#elif defined(_WIN32)

	HMODULE library;
#endif
	PFN_vkGetInstanceProcAddr ptr_vkGetInstanceProcAddr = VK_NULL_HANDLE;

	VulkanLibrary () {
#if defined(__linux__)
		library = dlopen ("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
		if (!library) library = dlopen ("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
#elif defined(__APPLE__)
		library = dlopen ("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
		if (!library) library = dlopen ("libvulkan.1.dylib", RTLD_NOW | RTLD_LOCAL);
#elif defined(_WIN32)
		library = LoadLibrary (TEXT ("vulkan-1.dll"));
#else
		assert (false && "Unsupported platform");
#endif
		if (!library) return;
#if defined(__linux__) || defined(__APPLE__)
		ptr_vkGetInstanceProcAddr =
		    reinterpret_cast<PFN_vkGetInstanceProcAddr> (dlsym (library, "vkGetInstanceProcAddr"));
#elif defined(_WIN32)
		ptr_vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr> (
		    GetProcAddress (library, "vkGetInstanceProcAddr"));
#endif
	}

	void close () {
#if defined(__linux__) || defined(__APPLE__)
		dlclose (library);
#elif defined(_WIN32)
		FreeLibrary (library);
#endif
		library = 0;
	}
};
