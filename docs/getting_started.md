# Getting Started

`vk-bootstrap` reduces the complexity of setting up a vulkan application into 3 main steps; instance creation, Physical device selection, and device creation. 

## Instance Creation

Creating an instance with `vk-bootstrap` uses the `vkb::InstanceBuilder` class.

Simply create a builder variable and call the `build()` member function.
```cpp
vkb::InstanceBuilder instance_builder;
auto instance_builder_return = instance_builder.build();
```
Because creating an instance may fail, the builder returns an 'Expected' type which can be either a valid `vkb::Instance` struct, containing the `VkInstance` handle, or the builder returns an error.
```cpp
if (!instance_builder_return) {
    printf("Failed to create Vulkan instance. Cause %s\n", 
        vkb::to_string(instance_builder_return.error().type));
    return -1;
} 
```
Now that any possible errors have been handled, 
```cpp
vkb::Instance vkb_instance = instance_builder_return.value();
```
This is enough to create a usable `VkInstance` but most use cases will want to customize it a bit. To do so, simply call the member functions on the `vkb::InstanceBuilder` object before `build()` is called.

The most common customization to instance creation is enabling the "Validation Layers", an invaluable tool for any vulkan application developer. 
```cpp
instance_builder.request_validation_layers ();
```
The other common customization point is setting up the `Debug Messenger Callback`, the mechanism in which an application can control what and where the "Validation Layers" log its output.
```cpp
instance_builder.set_debug_callback (
    [] (VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	    VkDebugUtilsMessageTypeFlagsEXT messageType,
	    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	    void *pUserData) 
        -> VkBool32 {
			auto severity = vkb::to_string_message_severity (messageSeverity);
			auto type = vkb::to_string_message_type (messageType);
			printf ("[%s: %s] %s\n", severity, type, pCallbackData->pMessage);
			return VK_FALSE;
		}
    );
```
Alternatively, `vk-bootstrap` provides a 'default debug messenger' that prints to standard output.
```cpp
instance_builder.use_default_debug_messenger();
```
Configuration can be chained together and done inline with building, like so.
```cpp
auto inst_builder_ret = instance_builder 
        .set_app_name ("Awesome Vulkan Application")
        .set_engine_name("Excellent Game Engine")
        .require_api_version(1,0,0)
        .build();
```

The `vkb::Instance` struct is meant to hold all the necessary instance level data to enable proper Physical Device selection. It also is meant for easy destructuring into custom classes if so desired.
```cpp
struct CustomVulkanWrapper {
    VkInstance instance;
    //...
};
CustomVulkanWrapper custom_vk_class;
custom_vk_class.instance = vkb_instance.instance;
```

When the application is finished with the vulkan, call `vkb::destroy_instance()` to dispose of the instance and associated data. 
```cpp
// cleanup 
vkb::destroy_instance(vkb_instance);
```
### Instance Creation Summary
```cpp
vkb::InstanceBuilder instance_builder;
auto instance_builder_return = instance_builder
        // Instance creation configuration
        .request_validation_layers()
        .use_default_debug_messenger()
        .build ();
if (!instance_builder_return) {
    // Handle error
} 
vkb::Instance vkb_instance = instance_builder_return.value ();

// at program end
vkb::destroy_instance(vkb_instance);
```
## Surface Creation

Vulkan requires manually creating a surface, called `VkSurfaceKHR`. Creating a surface is the responsibility of the windowing system, thus is out of scope for `vk-bootstrap`. However, it does try to make the process as painless as possible by automatically enabling the correct windowing extensions in `VkInstance` creation. 

Windowing libraries which support Vulkan usually provide a way of getting the `VkSurfaceKHR` handle for the window. These methods require a valid Vulkan instance, thus must be done after instance creation.

Examples for GLFW and SDL2 are listed below. 
```cpp
vkb::Instance vkb_instance; //valid vkb::Instance
VkSurfaceKHR surface = nullptr;
// window is a valid library specific Window handle

// GLFW
VkResult err = glfwCreateWindowSurface (vkb_instance.instance, window, NULL, &surface);
if (err != VK_SUCCESS) { /* handle error */ }

// SDL2
SDL_bool err = SDL_Vulkan_CreateSurface(window, vkb_instance.instance, &surface);
if (!err){ /* handle error */ }

```

## Physical Device Selection

Once a Vulkan instance has been created, the next step is to find a suitable GPU for the application to use. `vk-bootstrap` provide the `vkb::PhysicalDeviceSelector` class to streamline this process.

Creating a `vkb::PhysicalDeviceSelector` requires a valid `vkb::Instance` to construct.

It follows the same pattern laid out by `vkb::InstanceBuilder`.
```cpp
vkb::PhysicalDeviceSelector phys_device_selector (vkb_instance); 
auto physical_device_selector_return = phys_device_selector
        .set_surface(surface_handle)
        .select ();
if (!physical_device_selector_return) {
    // Handle error
}
auto phys_device = phys_device_ret.value ();
```

To select a physical device, call `select()` on the `vkb::PhysicalDeviceSelector` object.
By default, this will prefer a discrete GPU.

No cleanup is required for `vkb::PhysicalDevice`.

// TODO -- configuring selection, querying phys device details, explaining why a surface is needed

## Device Creation
// TODO
## Swapchain
// TODO
## Error Handling
// TODO

