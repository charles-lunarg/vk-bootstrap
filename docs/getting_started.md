# Getting Started

`vk-bootstrap` reduces the complexity of setting up a vulkan application by simplifying the three initial steps; instance creation, Physical device selection, and device creation.

## Instance Creation

Creating an instance with `vk-bootstrap` uses the `vkb::InstanceBuilder` class.

Simply create a builder variable and call the `build()` member function.
```cpp
vkb::InstanceBuilder instance_builder;
auto instance_builder_return = instance_builder.build();
```
Because creating an instance may fail, the builder returns an 'Result' type. This contains either a valid `vkb::Instance` struct, which includes a `VkInstance` handle, or contains an `vkb::InstanceError`.
```cpp
if (!instance_builder_return) {
    std::cerr << "Failed to create Vulkan instance. Error: " << instance_builder_return.error().message() << "\n";
    return -1;
}
```
Once any possible errors have been dealt with, we can pull the `vkb::Instance` struct out of the `Result`.
```cpp
vkb::Instance vkb_instance = instance_builder_return.value();
```
This is enough to create a usable `VkInstance` handle but many will want to customize it a bit. To configure instance creation, simply call the member functions on the `vkb::InstanceBuilder` object before `build()` is called.

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

To query the available layers and extensions, get a `SystemInfo` struct from `SystemInfo::get_system_info()`. It contains a `is_layer_available()` and `is_extension_available()` function to check for a layer or extensions before enabling it. It also has booleans for if the validation layers are present and if the VK_EXT_debug_utils extension is available.

```cpp
auto system_info_ret = vkb::SystemInfo::get_system_info();
if (!system_info_ret) {
    printf("%s\n", system_info_ret.error().message());
    return -1;
}
auto system_info = system_info_ret.value();
if (system_info.is_layer_available("VK_LAYER_LUNARG_api_dump")) {
    instance_builder.enable_layer("VK_LAYER_LUNARG_api_dump");
}
if (system_info.validation_layers_available){
    instance_builder.enable_validation_layers();
}
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

Presenting images to the screen Vulkan requires creating a surface, encapsulated in a `VkSurfaceKHR` handle. Creating a surface is the responsibility of the windowing system, thus is out of scope for `vk-bootstrap`. However, `vk-bootstrap` does try to make the process as painless as possible by automatically enabling the correct windowing extensions in `VkInstance` creation.

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
auto phys_device = physical_device_selector_return.value ();
```

To select a physical device, call `select()` on the `vkb::PhysicalDeviceSelector` object.
By default, this will prefer a discrete GPU.

No cleanup is required for `vkb::PhysicalDevice`.

The `vkb::PhysicalDeviceSelector` will look for the first device in the list that satisfied all the specified criteria, and if none is found, will return the first device that partially satisfies the criteria.

The various "require" functions indicate to `vk-bootstrap` what features and capabilities are necessary for an application. A "require" function will fail any `VkPhysicalDevice` that doesn't satisfy the constraint.

For example, "requiring" certain device extensions to be supported is done as follows:

```cpp
// Application cannot function without this extension
phys_device_selector.add_required_extension("VK_KHR_timeline_semaphore");

// Application can deal with the lack of this extension
phys_device_selector.add_desired_extension("VK_KHR_imageless_framebuffer");
```

While requiring that certain features are available is as follows:

```cpp
VkPhysicalDeviceFeatures required_features{};
required_features.multiViewport = true;

phys_device_selector.set_required_features(required_features);
```

To enable features for newer versions of Vulkan, use `set_required_features_11()`, `set_required_features_12()`, and `set_required_features_13()` and follow the same pattern as `set_required_features()` of passing in the features struct, corresponding to the version.

Note that `set_required_features_11()` was released with 1.2, so it cannot be used for 1.1 only capable Vulkan devices.

Features only available through extensions need to use `add_required_extension_features()`. For example:

```cpp
VkPhysicalDeviceDescriptorIndexingFeatures descriptor_indexing_features{};
descriptor_indexing_features.<features_used> = true;

phys_device_selector.add_required_extension_features(descriptor_indexing_features);
```

The features and extensions used as selection criteria in `vkb::PhysicalDeviceSelector` automatically propagate into `vkb::DeviceBuilder`. That means the application only needs to state the feature requirement once, and `vk-bootstrap` will handle enabling it on the resulting device.

Note:

Because `vk-bootstrap` does not manage creating a `VkSurfaceKHR` handle, it is explicitly passed into the `vkb::PhysicalDeviceSelector` for proper querying of surface support details. Unless the `vkb::InstanceBuilder::set_headless()` function was called, the physical device selector will emit `no_surface_provided` error. If an application does intend to present but cannot create a `VkSurfaceKHR` handle before physical device selection, use `defer_surface_initialization()` to disable the `no_surface_provided` error.

## Physical Device

The `vkb::PhysicalDevice` represents a chosen physical device, along with all the necessary details about how to create a `VkDevice` from it with the requested features and extensions. While most use cases will simply give the  `vkb::PhysicalDevice` to `vkb::DeviceBuilder`, there are a handful of useful things that can be done with it.

Adding optional extensions. It is occasionally useful to enable features if they are present but not require that they be available on the physical device.

This is done using `enable_extension_if_present()` as follows.

```cpp
bool supported = phys_device.enable_extension_if_present("VK_KHR_timeline_semaphore");
if (supported){
    // allows easy feedback whether an extension is supported or not.
}
```

Use `enable_extensions_if_present()` to check if a group of extensions are available, and enable all of them if they are all present. This will *not* enable any extension unless they are all present, useful for handling dependencies between extensions, where one extension requires another one to be enabled.

## Device Creation

Once a `VkPhysicalDevice` has been selected, a `VkDevice` can be created. Facilitating that is the `vkb::DeviceBuilder`. Creation and usage follows the forms laid out by `vkb::InstanceBuilder`.

```cpp
vkb::DeviceBuilder device_builder{ phys_device};
auto dev_ret = device_builder.build ();
if (!dev_ret) {
    // error
}
vkb::Device vkb_device = dev_ret.value();
 ```

To destroy a `vkb::Device`, call `vkb::destroy_device()`.
```cpp
vkb::destroy_device(vkb_device);
```

### Queues

By default, `vkb::DeviceBuilder` will enable one queue from each queue family available on the `VkPhysicalDevice`. This is done because in practice, most use cases only need a single queue from each family.

To get a `VkQueue` or the index of a `VkQueue`, use the `get_queue(QueueType type)` and `get_queue_index(QueueType type)` functions of `vkb::Device`. These will return the appropriate `VkQueue` or `uint32_t` if they exist and were enabled, else they will return an error.

```cpp
auto queue_ret = vkb_device.get_queue (vkb::QueueType::graphics);
if (!queue_ret) {
    // handle error
}
graphics_queue = queue_ret.value ();
```

Queue families represent a set of queues with similar operations, such as graphics, transfer, and compute. Because not all Vulkan hardware has queue families for each operation category, an application should be able to handle the presence or lack of certain queue families. For this reason the `get_dedicated_queue`  and `get_dedicated_queue_index` functions of `vkb::Device` exist to allow applications to easily know if there is a queue dedicated to a particular operation, such as compute or transfer operations.

#### Custom queue setup

If an application wishes to have more fine grained control over their queue setup, they should create a `std::vector` of `vkb::CustomQueueDescription` which describe the index, count and a `std::vector<float>` of priorities. To build up such a vector, use the `get_queue_families` function in `vkb::PhysicalDevice` to get a `std::vector<VkQueueFamilyProperties>`

For example
```cpp
std::vector<vkb::CustomQueueDescription> queue_descriptions;
auto queue_families = phys_device.get_queue_families ();
for (uint32_t i = 0; i < static_cast<uint32_t>(queue_families.size ()); i++) {
    if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
        // Find the first queue family with graphics operations supported
        queue_descriptions.push_back (vkb::CustomQueueDescription (
            i, std::vector<float> (queue_families[i].queueCount, 1.0f)));
    }
}
```
## Swapchain

Creating a swapchain follows the same form outlined by `vkb::InstanceBuilder` and `vkb::DeviceBuilder`. Create the `vkb::SwapchainBuilder`, provide `vkb::Device`, call the appropriate builder functions, and call `build()`.

```cpp
vkb::SwapchainBuilder swapchain_builder{ device };
auto swap_ret = swapchain_builder.build ();
if (!swap_ret){

}
vkb::swapchain swapchain = swap_ret.value();
```

By default, the swapchain will use the VK_FORMAT_B8G8R8A8_SRGB or VK_FORMAT_R8G8B8A8_SRGB image format with the color space VK_COLOR_SPACE_SRGB_NONLINEAR_KHR. The present mode will default to VK_PRESENT_MODE_MAILBOX_KHR if available and fallback to VK_PRESENT_MODE_FIFO_KHR. The image usage default flag is VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT.

Recreating the swapchain is equivalent to creating a new swapchain but providing the old swapchain as a source. Be sure to not use the same `VkSwapchainKHR` again as it expires when it is recycled after trying to create a new swapchain.
```cpp
vkb::SwapchainBuilder swapchain_builder{ device };
auto swap_ret = swapchain_builder.set_old_swapchain (vkb_swapchain)
                                 .build ();
if !(swap_ret){
    // If it failed to create a swapchain, the old swapchain handle is invalid.
    vkb_swapchain.swapchain = VK_NULL_HANDLE;
}
// Even though we recycled the previous swapchain, we need to free its resources.
vkb::destroy_swapchain(vkb_swapchain);
// Get the new swapchain and place it in our variable
vkb_swapchain = swap_ret.value();
```

To destroy the swapchain, call `vkb::destroy_swapchain()`. This is null out the VkSwapchainHandle inside of it.

```cpp
vkb::destroy_swapchain(vkb_swapchain);
```
