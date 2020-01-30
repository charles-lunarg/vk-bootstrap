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

vkbs::PhysicalDeviceSelector;
selector.set_instance(inst)
    .set_surface (/* from user created window*/)
    .set_minimum_version (1, 0)
    .require_dedicated_transfer_queue();
auto phys_ret = selector.select ();
vkbs::PhysicalDevice phys;
if (phys_ret.has_value()) {
    // successfully selected a sufficient physical device
    phys = phys_ret.value();
}

vkbs::DeviceBuilder device_builder;
device_builder.set_physical_device (phys_dev); 
auto dev_ret = device_builder.build ();
if(dev_ret.has_value()){
    // successfully created a vulkan device
}
	
```

## Building

