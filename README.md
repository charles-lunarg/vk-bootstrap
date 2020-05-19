# Vk-Bootstrap

A Vulkan utility library meant to jump start any Vulkan Application

This library simplifies the tedious process of:

* Instance Creation
* Picking a Physical Device
* Device Creation
* Getting Queues
* Swapchain Creation

It also adds several conveniences for:

* Enabling validation layers
* Adding a debug callback
* Select a gpu based on a set of criteria like features, extensions, memory, etc.

Read the [Getting Started](docs/getting_started.md) guide for a quick start on using `vk-bootstrap`

## Basic Usage

```cpp

#include "VkBootstrap.h"

void init_vulkan () {
    vkb::InstanceBuilder builder;
    auto inst_ret = builder.set_app_name ("Example Vulkan Application")
                        .request_validation_layers ()
                        .use_default_debug_messenger ()
                        .build ();
    if (!inst_ret) {
        printf("Failed to create Vulkan instance. Cause %s\n", 
            instance_builder_return.error().message());
        return;
    }
    vkb::Instance vkb_inst = inst_ret.value ();

    vkb::PhysicalDeviceSelector selector{ vkb_inst };
    auto phys_ret = selector.set_surface (/* from user created window*/)
                        .set_minimum_version (1, 1) // require a vulkan 1.1 capable device
                        .require_dedicated_transfer_queue ()
                        .select ();
    if (!phys_ret) {
        printf("Failed to select Vulkan Physical Device. Cause %s\n", 
            phys_ret.error().message());
        return;
    }

    vkb::DeviceBuilder device_builder{ phys_ret.value () };
    // automatically propagate needed data from instance & physical device
    auto dev_ret = device_builder.build ();
    if (!dev_ret) {
        printf("Failed to create Vulkan device. Cause %s\n", 
            dev_ret.error().message());
        return;
    }
    vkb::Device vkb_device = dev_ret.value ();

    // Get the VkDevice handle used in the rest of a vulkan application
    VkDevice device = vkb_device.device;

    // Get the graphics queue with a helper function
    auto graphics_queue_ret = vkb_device.get_queue (vkb::QueueType::graphics);
    if (!graphics_queue_ret) {
        printf("Failed to get graphics queue. Cause %s\n", 
            graphics_queue_ret.error().message());
        return;
    }
    VkQueue graphics_queue = graphics_queue_ret.value ();

    // Turned 400-500 lines of boilerplate into less than fifty.
}
```

See `example/triangle.cpp` for an example that renders a triangle to the screen.

## Setting up vk-bootstrap

### Simple

This library has no external dependencies beyond C++11 and the standard library.

Simply copy the `src/VkBootstrap.h` and `src/VkBootstrap.cpp` files into your project and compile them as you normally would

### With git-submodule + CMake

Add this project as a git-submodule

```bash
git submodule add https://github.com/charles-lunarg/vk-bootstrap
```

With CMake, add the project as a subdirectory

```cmake
add_subdirectory(vk-bootstrap)

target_link_libraries(your_application_name vk-bootstrap)
```

### Manually Building

```bash
git clone https://github.com/charles-lunarg/vk-bootstrap
cd vk-bootstrap
mkdir build
cd build
cmake ..
```

## Testing

To test, glfw and Catch2 are automatically included using git submodules.

In the project directory, run the following to get the required dependencies to test.

```bash
git submodule update --init
```

Tests will be enabled by default if you open this project standalone. If you include this project as a subdirectory,
you can force enable tests by adding `-DVK_BOOTSTRAP_TEST` to the cmake command line arguments

```bash
cmake ../path/to/your-project/ -DVK_BOOTSTRAP_TEST=ON
```
