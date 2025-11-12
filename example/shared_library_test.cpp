
#include "VkBootstrap.h"
#include "shared_library_usage.h"

#include <iostream>

int main() {
    vkb::Instance inst = init_vulkan();
    vkb::PhysicalDeviceSelector selector{ inst };
    auto s = selector.select();
    if (!s.has_value()) {
        std::cout << "Couldn't pick physical device" << s.error().message() << "\n";
    } else {
        std::cout << "Physical Device name: " << s.value().properties.deviceName << "\n";
    }
}
