

#include "vulkan_mock.hpp"

#include <cstring>

#include <algorithm>

#if defined(__linux__) || defined(__APPLE__)
#include <dlfcn.h>
#endif

#define GPA_IMPL(x)                                                                                                    \
    if (strcmp(pName, #x) == 0) {                                                                                      \
        return reinterpret_cast<PFN_vkVoidFunction>(shim_##x);                                                         \
    }

VulkanMock mock;

extern "C" {
VulkanMock* get_vulkan_mock() {
    mock = VulkanMock{};
    return &mock;
}
}

template <typename T> VkResult fill_out_count_pointer_pair(std::vector<T> const& data_vec, uint32_t* pCount, T* pData) {
    if (pCount == nullptr) {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }
    if (pData == nullptr) {
        if (pCount) *pCount = static_cast<uint32_t>(data_vec.size());
        return VK_SUCCESS;
    } else {
        uint32_t amount_written = 0;
        uint32_t amount_to_write = static_cast<uint32_t>(data_vec.size());
        if (*pCount < data_vec.size()) {
            amount_to_write = *pCount;
        }
        for (size_t i = 0; i < amount_to_write; i++) {
            pData[i] = data_vec[i];
            amount_written++;
        }
        if (*pCount < data_vec.size()) {
            *pCount = amount_written;
            return VK_INCOMPLETE;
        }
        *pCount = amount_written;
        return VK_SUCCESS;
    }
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkEnumerateInstanceVersion(uint32_t* pApiVersion) {
    if (pApiVersion == nullptr) {
        return VK_ERROR_DEVICE_LOST;
    }
    *pApiVersion = mock.api_version;
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkEnumerateInstanceExtensionProperties(
    const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) {
    if (pLayerName) {
        for (size_t i = 0; i < mock.instance_layers.size(); i++) {
            if (strcmp(mock.instance_layers[i].layerName, pLayerName) == 0) {
                return fill_out_count_pointer_pair(mock.per_layer_instance_extension_properties[i], pPropertyCount, pProperties);
            }
        }
        // Layer not found, fill out with empty list
        return fill_out_count_pointer_pair({}, pPropertyCount, pProperties);
    }
    return fill_out_count_pointer_pair(mock.instance_extensions, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) {
    return fill_out_count_pointer_pair(mock.instance_layers, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateInstance([[maybe_unused]] const VkInstanceCreateInfo* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance) {
    if (pInstance == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    *pInstance = get_handle<VkInstance>(0x0000ABCDU);
    return VK_SUCCESS;
}
VKAPI_ATTR void VKAPI_CALL shim_vkDestroyInstance(
    [[maybe_unused]] VkInstance instance, [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateDebugUtilsMessengerEXT([[maybe_unused]] VkInstance instance,
    [[maybe_unused]] const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pMessenger) {
    if (instance == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    *pMessenger = get_uint64_handle<VkDebugUtilsMessengerEXT>(0xDEBE0000DEBE0000U);
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL shim_vkDestroyDebugUtilsMessengerEXT([[maybe_unused]] VkInstance instance,
    [[maybe_unused]] VkDebugUtilsMessengerEXT messenger,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkEnumeratePhysicalDevices(
    VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
    if (instance == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    return fill_out_count_pointer_pair(mock.physical_device_handles, pPhysicalDeviceCount, pPhysicalDevices);
}

VulkanMock::PhysicalDeviceDetails& get_physical_device_details(VkPhysicalDevice physicalDevice) {
    for (size_t i = 0; i < mock.physical_device_handles.size(); i++) {
        if (mock.physical_device_handles[i] == physicalDevice) return mock.physical_devices_details[i];
    }
    assert(false && "should never reach here!");
    return mock.physical_devices_details.front();
}

VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
    *pFeatures = get_physical_device_details(physicalDevice).features;
}
VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
    *pProperties = get_physical_device_details(physicalDevice).properties;
}

VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) {
    fill_out_count_pointer_pair(
        get_physical_device_details(physicalDevice).queue_family_properties, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    *pMemoryProperties = get_physical_device_details(physicalDevice).memory_properties;
}

VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    const auto& phys_dev = get_physical_device_details(physicalDevice);
    VkBaseOutStructure* current = static_cast<VkBaseOutStructure*>(pFeatures->pNext);
    while (current) {
        for (const auto& features_pNext : phys_dev.features_pNextChain) {
            if (features_pNext->sType == current->sType) {
                VkBaseOutStructure* next = static_cast<VkBaseOutStructure*>(current->pNext);
                std::memcpy(current, features_pNext.get(), get_pnext_chain_struct_size(features_pNext->sType));
                current->pNext = next;
                break;
            }
        }
        current = static_cast<VkBaseOutStructure*>(current->pNext);
    }
}
VKAPI_ATTR void VKAPI_CALL shim_vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    shim_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkEnumerateDeviceExtensionProperties(
    VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) {
    if (pLayerName) {
        for (size_t i = 0; i < mock.instance_layers.size(); i++) {
            if (strcmp(mock.instance_layers[i].layerName, pLayerName) == 0) {
                return fill_out_count_pointer_pair(mock.per_layer_device_extension_properties[i], pPropertyCount, pProperties);
            }
        }
        // Layer not found, fill out with empty list
        return fill_out_count_pointer_pair({}, pPropertyCount, pProperties);
    }
    return fill_out_count_pointer_pair(get_physical_device_details(physicalDevice).extensions, pPropertyCount, pProperties);
}


VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateDevice(VkPhysicalDevice physicalDevice,
    [[maybe_unused]] const VkDeviceCreateInfo* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkDevice* pDevice) {
    if (physicalDevice == nullptr) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    *pDevice = get_handle<VkDevice>(0x0000ABCDU);
    get_physical_device_details(physicalDevice).created_devices.push_back(*pDevice);
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL shim_vkDestroyDevice(
    [[maybe_unused]] VkDevice device, [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {
    for (auto& physical_devices : mock.physical_devices_details) {
        auto it = std::find(std::begin(physical_devices.created_devices), std::end(physical_devices.created_devices), device);
        if (it != std::end(physical_devices.created_devices)) {
            physical_devices.created_devices.erase(it);
        }
    }
}

VKAPI_ATTR void VKAPI_CALL shim_vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    for (auto& physical_devices : mock.physical_devices_details) {
        auto it = std::find(std::begin(physical_devices.created_devices), std::end(physical_devices.created_devices), device);
        if (it != std::end(physical_devices.created_devices)) {
            if (queueFamilyIndex < physical_devices.queue_family_properties.size() &&
                queueIndex < physical_devices.queue_family_properties[queueFamilyIndex].queueCount) {
                *pQueue = get_handle<VkQueue>(0x0000CCEEU);
                return;
            }
        }
    }
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateCommandPool([[maybe_unused]] VkDevice device,
    [[maybe_unused]] const VkCommandPoolCreateInfo* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkCommandPool* pCommandPool) {
    *pCommandPool = get_uint64_handle<VkCommandPool>(0x0000ABBBU);
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateFence([[maybe_unused]] VkDevice device,
    [[maybe_unused]] const VkFenceCreateInfo* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkFence* pFence) {
    *pFence = get_uint64_handle<VkFence>(0x0000AAACU);
    return VK_SUCCESS;
}
VKAPI_ATTR void VKAPI_CALL shim_vkDestroyFence(
    [[maybe_unused]] VkDevice device, [[maybe_unused]] VkFence fence, [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateSwapchainKHR([[maybe_unused]] VkDevice device,
    [[maybe_unused]] const VkSwapchainCreateInfoKHR* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkSwapchainKHR* pSwapchain) {
    *pSwapchain = get_uint64_handle<VkSwapchainKHR>(0x0000FFFEU);
    return VK_SUCCESS;
}
VKAPI_ATTR VkResult VKAPI_CALL shim_vkGetSwapchainImagesKHR(
    [[maybe_unused]] VkDevice device, [[maybe_unused]] VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {

    std::vector<VkImage> images{ get_uint64_handle<VkImage>(0x0000EDD0U),
        get_uint64_handle<VkImage>(0x0000EDD1U),
        get_uint64_handle<VkImage>(0x0000EDD1U) };
    return fill_out_count_pointer_pair(images, pSwapchainImageCount, pSwapchainImages);
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkCreateImageView([[maybe_unused]] VkDevice device,
    [[maybe_unused]] const VkImageViewCreateInfo* pCreateInfo,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator,
    VkImageView* pView) {
    if (pView) *pView = get_uint64_handle<VkImageView>(0x0000CCCEU);
    return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL shim_vkDestroyImageView([[maybe_unused]] VkDevice device,
    [[maybe_unused]] VkImageView imageView,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR void VKAPI_CALL shim_vkDestroySwapchainKHR([[maybe_unused]] VkDevice device,
    [[maybe_unused]] VkSwapchainKHR swapchain,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkAcquireNextImageKHR([[maybe_unused]] VkDevice device,
    [[maybe_unused]] VkSwapchainKHR swapchain,
    [[maybe_unused]] uint64_t timeout,
    [[maybe_unused]] VkSemaphore semaphore,
    [[maybe_unused]] VkFence fence,
    [[maybe_unused]] uint32_t* pImageIndex) {
    return VK_SUCCESS;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL shim_vkGetDeviceProcAddr(VkDevice device, const char* pName) {
    if (device == VK_NULL_HANDLE) {
        return nullptr;
    }
    GPA_IMPL(vkDestroyDevice)
    GPA_IMPL(vkGetDeviceQueue)
    GPA_IMPL(vkCreateCommandPool)
    GPA_IMPL(vkCreateFence)
    GPA_IMPL(vkDestroyFence)
    GPA_IMPL(vkCreateSwapchainKHR)
    GPA_IMPL(vkGetSwapchainImagesKHR)
    GPA_IMPL(vkCreateImageView)
    GPA_IMPL(vkDestroyImageView)
    GPA_IMPL(vkDestroySwapchainKHR)
    GPA_IMPL(vkAcquireNextImageKHR)

    return nullptr;
}

VKAPI_ATTR void VKAPI_CALL shim_vkDestroySurfaceKHR([[maybe_unused]] VkInstance instance,
    [[maybe_unused]] VkSurfaceKHR surface,
    [[maybe_unused]] const VkAllocationCallbacks* pAllocator) {}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) {

    for (size_t i = 0; i < mock.physical_device_handles.size(); i++) {
        if (physicalDevice == mock.physical_device_handles[i]) {
            if (queueFamilyIndex >= mock.physical_devices_details[i].queue_family_properties.size()) {
                return VK_ERROR_FORMAT_NOT_SUPPORTED;
            }
        }
    }
    if (surface && pSupported) {
        *pSupported = true;
    }
    return VK_SUCCESS;
}
VKAPI_ATTR VkResult VKAPI_CALL shim_vkGetPhysicalDeviceSurfaceFormatsKHR(
    [[maybe_unused]] VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) {
    for (size_t i = 0; i < mock.surface_handles.size(); i++) {
        if (mock.surface_handles[i] == surface) {
            return fill_out_count_pointer_pair(mock.surface_details[i].surface_formats, pSurfaceFormatCount, pSurfaceFormats);
        }
    }
    return VK_ERROR_SURFACE_LOST_KHR;
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkGetPhysicalDeviceSurfacePresentModesKHR(
    [[maybe_unused]] VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    for (size_t i = 0; i < mock.surface_handles.size(); i++) {
        if (mock.surface_handles[i] == surface) {
            return fill_out_count_pointer_pair(mock.surface_details[i].present_modes, pPresentModeCount, pPresentModes);
        }
    }
    return VK_ERROR_SURFACE_LOST_KHR;
}

VKAPI_ATTR VkResult VKAPI_CALL shim_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    [[maybe_unused]] VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    for (size_t i = 0; i < mock.surface_handles.size(); i++) {
        if (mock.surface_handles[i] == surface) {
            *pSurfaceCapabilities = mock.surface_details[i].capabilities;
            return VK_SUCCESS;
        }
    }
    return VK_ERROR_SURFACE_LOST_KHR;
}

PFN_vkVoidFunction shim_vkGetInstanceProcAddr([[maybe_unused]] VkInstance instance, [[maybe_unused]] const char* pName) {
    GPA_IMPL(vkEnumerateInstanceVersion)
    GPA_IMPL(vkEnumerateInstanceExtensionProperties)
    GPA_IMPL(vkEnumerateInstanceLayerProperties)
    GPA_IMPL(vkCreateInstance)

    GPA_IMPL(vkDestroyInstance)
    GPA_IMPL(vkCreateDebugUtilsMessengerEXT)
    GPA_IMPL(vkDestroyDebugUtilsMessengerEXT)
    GPA_IMPL(vkEnumeratePhysicalDevices)
    GPA_IMPL(vkGetPhysicalDeviceFeatures)
    GPA_IMPL(vkGetPhysicalDeviceFeatures2)
    GPA_IMPL(vkGetPhysicalDeviceFeatures2KHR)
    GPA_IMPL(vkGetPhysicalDeviceProperties)
    GPA_IMPL(vkGetPhysicalDeviceQueueFamilyProperties)
    GPA_IMPL(vkGetPhysicalDeviceMemoryProperties)
    GPA_IMPL(vkEnumerateDeviceExtensionProperties)

    GPA_IMPL(vkCreateDevice)
    GPA_IMPL(vkGetDeviceProcAddr)
    GPA_IMPL(vkGetDeviceQueue)
    GPA_IMPL(vkDestroyDevice)

    GPA_IMPL(vkDestroySurfaceKHR)
    GPA_IMPL(vkGetPhysicalDeviceSurfaceSupportKHR)
    GPA_IMPL(vkGetPhysicalDeviceSurfaceFormatsKHR)
    GPA_IMPL(vkGetPhysicalDeviceSurfacePresentModesKHR)
    GPA_IMPL(vkGetPhysicalDeviceSurfaceCapabilitiesKHR)

    // Only used by the tests, not by vk-bootstrap
    GPA_IMPL(vkCreateCommandPool)

    return nullptr;
}

extern "C" {
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName) {
    return shim_vkGetInstanceProcAddr(instance, pName);
}

#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__GNU__)
#define DLSYM_FUNC_NAME dlsym

#elif defined(__APPLE__)
#define DLSYM_FUNC_NAME my_dlsym
#endif

using PFN_DLSYM = void* (*)(void* handle, const char* symbol);


#if defined(__APPLE__)
#define real_dlsym dlsym
#else
PFN_DLSYM real_dlsym = nullptr;
#endif

void* DLSYM_FUNC_NAME([[maybe_unused]] void* handle, const char* symbol) {
    if (strcmp(symbol, "vkGetInstanceProcAddr") == 0) {
        return reinterpret_cast<void*>(shim_vkGetInstanceProcAddr);
    }

    return nullptr;
}

/* Shiming functions on apple is limited by the linker prefering to not use functions in the
 * executable in loaded dylibs. By adding an interposer, we redirect the linker to use our
 * version of the function over the real one, thus shimming the system function.
 */
#if defined(__APPLE__)
#define MACOS_ATTRIB __attribute__((section("__DATA,__interpose")))
#define VOIDCP_CAST(_func) reinterpret_cast<const void*>(&_func)

struct Interposer {
    const void* shim_function;
    const void* underlying_function;
};

__attribute__((used)) static Interposer _interpose_dlsym MACOS_ATTRIB = { VOIDCP_CAST(my_dlsym), VOIDCP_CAST(dlsym) };

#endif
}
