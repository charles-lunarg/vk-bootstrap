# Vk-Bootstrap

A Vulkan utility library meant to jump start a Vulkan Application

This library simplifies the tedious process of:

* Instance Creation
* Physical Device Selection
* Device Creation
* Getting Queues
* Swapchain Creation

It also adds several conveniences for:

* enabling validation layers
* setting up a debug callback
* selecting a gpu based on a small set of common criteria

## Example

```cpp

#include "VkBootstrap.h"

void device_init()
{
    vkb::InstanceBuilder builder;
    builder.setup_validation_layers()
           .set_app_name ("example")
           .set_default_debug_messenger ();
    auto inst_ret = builder.build();
    if (!inst_ret.has_value()) {
        // error
    }
    vkb::Instance inst = inst_ret.value();

    vkb::PhysicalDeviceSelector selector{ inst };
    selector.set_surface (/* from user created window*/)
            .set_minimum_version (1, 0)
            .require_dedicated_transfer_queue();
    auto phys_ret = selector.select ();
    if (!phys_ret.has_value()) {
        // error
    }
    vkb::PhysicalDevice physical_device = phys_ret.value();

    vkb::DeviceBuilder device_builder{ physical_device };
    auto dev_ret = device_builder.build ();
    if (!dev_ret.has_value()){
        // error
    }
    vkb::Device device = dev_ret.value();

    auto graphics_queue_ret = get_graphics_queue(device).value();
    if (!graphics_queue_ret.has_value()){
        //error
    }
    VkQueue graphics_queue = graphics_queue_ret.value();
}

```

## Using this library

#### Simple

Copy the `src/VkBootstrap.h` and `src/VkBootstrap.cpp` into your project

#### With git-submodule + CMake

add this project as a git-submodule

```bash
git submodule add https://github.com/charles-lunarg/vk-bootstrap
```

Then add the project with cmake

```cmake
add_subdirectory(vk-bootstrap)
```

## Manually Building

```bash
git clone https://github.com/charles-lunarg/vk-bootstrap
cd vk-bootstrap
mkdir build
cd build
cmake ..
```

To test, glfw and Catch2 are needed and automatically included using git submodules.

In the project directory, run

```bash
git submodule update --init
```

to get the required dependencies for testing setup.

Then return to the build directory and enable tests with `VK_BOOTSTRAP_TEST`

```bash
cmake ../path/to/vk-bootstrap/ -DVK_BOOTSTRAP_TEST=ON
```

## Todo's

* Package library to be usable
* More examples
* Testing
* Documenting API
* Fleshing out device configuration
