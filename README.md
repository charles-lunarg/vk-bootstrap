# Vk-Bootstrap

A Vulkan Utility library meant to jump start a Vulkan Application

This library simplifies the tedious process of:

* Instance Creation
* Physical Device Selection
* Device Creation
* Getting Queues
* Swapchain Creation

## Example

```cpp
vkbs::InstanceBuilder builder;
builder.setup_validation_layers()
       .set_app_name ("example")
       .set_default_debug_messenger ();
auto inst_ret = builder.build ();
vkbs::Instance inst;
if (inst_ret.has_value()) {
    // successfully created instance
    inst = inst_ret.value();
}

vkbs::PhysicalDeviceSelector(inst);
selector.set_surface (/* from user created window*/)
    .set_minimum_version (1, 0)
    .require_dedicated_transfer_queue();
auto phys_ret = selector.select ();
vkbs::PhysicalDevice phys;
if (phys_ret.has_value()) {
    // successfully selected a sufficient physical device
    phys = phys_ret.value();
}

vkbs::DeviceBuilder device_builder(phys_dev); 
auto dev_ret = device_builder.build ();
if(dev_ret.has_value()){
    // successfully created a vulkan device
}
```

## Building

Requires CMake and Vulkan installed on your system.

```bash
git clone https://github.com/charles-lunarg/vk-bootstrap
cd vk-bootstrap
mkdir build
cd build
cmake ..
```

To test, glfw and Catch2 are used and automatically included using git submodules.

In the project directory, run

```bash
git submodule update --init
```

to get the required dependencies for testing setup.

Then return to the build directory and enable tests with `VK_BOOTSTRAP_TEST`

```bash
cmake ../path/to/vk-bootstrap/ -DVK_BOOTSTRAP_TEST=ON
```


