# Vk-Bootstrap

A Vulkan utility library meant to jump start any Vulkan Application

This library simplifies the tedious process of:

* Instance Creation
* Picking a Physical Device
* Device Creation
* Getting Queues
* Swapchain Creation

It also adds several conveniences for:

* enabling validation layers
* setting up a debug callback
* select a gpu based on a set of common criteria like features, extensions, memory, etc.

## Example

```cpp

#include "VkBootstrap.h"

void init_vulkan()
{
    vkb::InstanceBuilder builder;
    builder.check_and_setup_validation_layers()
           .set_app_name ("Example Vulkan Application")
           .set_default_debug_messenger ();
    auto inst_ret = builder.build();
    if (!inst_ret.has_value()) {
        // error
    }
    vkb::Instance vkb_inst = inst_ret.value();

    vkb::PhysicalDeviceSelector selector{ inst };
    selector.set_surface (/* from user created window*/)
            .set_minimum_version (1, 1) //require a vulkan 1.1 capable device
            .require_dedicated_transfer_queue(); //require a transfer queue
    auto phys_ret = selector.select ();
    if (!phys_ret.has_value()) {
        // error
    }

    vkb::DeviceBuilder device_builder{ phys_ret.value() };
    auto dev_ret = device_builder.build ();
    if (!dev_ret.has_value()){
        // error
    }

    // Get the VkDevice handle used in the rest of a vulkan application
    VkDevice device = dev_ret.value().device;

    // Get the graphics queue with a helper function
    auto graphics_queue_ret = vkb::get_graphics_queue(dev_ret.value());
    if (!graphics_queue_ret.has_value()){
        // error
    }
    VkQueue graphics_queue = graphics_queue_ret.value();

    // Reduced 400-500 lines of boilerplate to a less than fifty.
}

```

See `example/triangle.cpp` for an example that renders a triangle to the screen.

## Setting up vk-bootstrap

### Simple

This library has no external dependencies.
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

In the build directory, enable tests by adding `-DVK_BOOTSTRAP_TEST` to the cmake command line arguments

```bash
cmake ../path/to/vk-bootstrap/ -DVK_BOOTSTRAP_TEST=ON
```

## Todo's

* Package library to be usable
* More examples
* Testing
* Documenting API
