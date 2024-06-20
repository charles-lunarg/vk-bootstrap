#pragma once

#include <assert.h>
#include <cstdint>

#include <memory>
#include <utility>
#include <string>
#include <vector>

#include <vulkan/vulkan_core.h>

#include <VkBootstrap.h>

// Helper function to return the size of the sType if it is a known features struct, otherwise return 0
// Hand written, must be updated to include any used struct.
inline size_t check_if_features2_struct(VkStructureType type) {
    switch (type) {
        case (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES):
            return sizeof(VkPhysicalDeviceDescriptorIndexingFeatures);
        case (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES):
            return sizeof(VkPhysicalDeviceVulkan11Features);
        case (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES):
            return sizeof(VkPhysicalDeviceVulkan12Features);
        case (VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES):
            return sizeof(VkPhysicalDeviceSubgroupSizeControlFeatures);
        default:
            return 0;
    }
}

inline size_t get_pnext_chain_struct_size(VkStructureType type) {
    auto size = check_if_features2_struct(type);
    assert(size > 0 && "Must update get_pnext_chain_struct_size(VkStructureType type) to add type!");
    return size;
}

template <typename T> T get_handle(size_t value) { return reinterpret_cast<T>(value); }

#if INTPTR_MAX == INT32_MAX
template <typename T> uint64_t get_uint64_handle(uint64_t value) { return static_cast<T>(value); }
#elif INTPTR_MAX == INT64_MAX
template <typename T> T get_uint64_handle(uint64_t value) { return reinterpret_cast<T>(value); }
#endif

struct VulkanMock {
    uint32_t api_version = VK_API_VERSION_1_3;
    std::vector<VkExtensionProperties> instance_extensions;
    std::vector<VkLayerProperties> instance_layers;
    std::vector<std::vector<VkExtensionProperties>> per_layer_instance_extension_properties;
    std::vector<std::vector<VkExtensionProperties>> per_layer_device_extension_properties;

    void add_layer(VkLayerProperties layer_properties,
        std::vector<VkExtensionProperties> layer_instance_extensions,
        std::vector<VkExtensionProperties> layer_device_extensions) {
        instance_layers.push_back(layer_properties);
        per_layer_instance_extension_properties.push_back(layer_instance_extensions);
        per_layer_instance_extension_properties.push_back(layer_device_extensions);
    }

    struct SurfaceDetails {
        VkSurfaceCapabilitiesKHR capabilities{};
        std::vector<VkSurfaceFormatKHR> surface_formats;
        std::vector<VkPresentModeKHR> present_modes;
    };

    std::vector<VkSurfaceKHR> surface_handles;
    std::vector<SurfaceDetails> surface_details;

    VkSurfaceKHR get_new_surface(SurfaceDetails details) {
        surface_handles.push_back(
            get_uint64_handle<VkSurfaceKHR>(static_cast<uint64_t>(0x123456789ABU + surface_handles.size())));
        surface_details.push_back(details);
        return surface_handles.back();
    }

    struct CreatedDeviceDetails {
        VkPhysicalDeviceFeatures features{};
        std::vector<const char*> extensions;
        std::vector<vkb::detail::GenericFeaturesPNextNode> features_pNextChain;
    };

    struct PhysicalDeviceDetails {
        VkPhysicalDeviceProperties properties{};
        VkPhysicalDeviceFeatures features{};
        VkPhysicalDeviceMemoryProperties memory_properties{};
        std::vector<VkExtensionProperties> extensions;
        std::vector<VkQueueFamilyProperties> queue_family_properties;
        std::vector<vkb::detail::GenericFeaturesPNextNode> features_pNextChain;

        std::vector<VkDevice> created_device_handles;
        std::vector<CreatedDeviceDetails> created_device_details;

        template <typename T> void add_features_pNext_struct(T features) { features_pNextChain.push_back(features); }
    };

    std::vector<VkPhysicalDevice> physical_device_handles;
    std::vector<PhysicalDeviceDetails> physical_devices_details;

    void add_physical_device(PhysicalDeviceDetails details) {
        physical_device_handles.push_back(get_handle<VkPhysicalDevice>(0x22334455U + physical_device_handles.size()));
        physical_devices_details.emplace_back(std::move(details));
    }
};

extern "C" {
VulkanMock* get_vulkan_mock();
}
