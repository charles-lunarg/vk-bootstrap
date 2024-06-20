#pragma once

#include <algorithm>

#include "vulkan_mock.hpp"

#include <catch2/catch_test_macros.hpp>


vkb::Instance get_instance(uint32_t minor_version = 0);

vkb::Instance get_headless_instance(uint32_t minor_version = 0);

VkExtensionProperties get_extension_properties(const char* extName);

VulkanMock& get_and_setup_default();

VulkanMock::SurfaceDetails get_basic_surface_details();
