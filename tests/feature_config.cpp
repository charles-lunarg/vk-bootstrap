#include "common.h"

#include <catch2/catch.hpp>

TEST_CASE("TargetBaseVulkanDesktop", "[VkBootstrap.feature_config]") {

	auto window = create_window_glfw("Instance with surface");
	vkb::InstanceBuilder instance_builder;
	auto instance_ret = instance_builder.use_default_debug_messenger().request_validation_layers().build();
	REQUIRE(instance_ret);
	vkb::Instance instance = instance_ret.value();
	auto surface = create_surface_glfw(instance.instance, window);
	GIVEN("A window and a vulkan instance") {
		vkb::PhysicalDeviceSelector selector(instance);
		auto phys_dev_ret = selector.set_surface(surface)
		                        .set_vulkan_feature_config(vkb::get_feature_config_vulkan_1_0_desktop())
		                        .select();
		REQUIRE(phys_dev_ret);

		GIVEN("A physical device created with the TargetBaseVulkanDesktop") {
			vkb::DeviceBuilder device_builder(phys_dev_ret.value());
			auto device_ret = device_builder.build();
			REQUIRE(device_ret);
			vkb::Device device = device_ret.value();

			// possible swapchain creation...

			vkb::destroy_device(device);
		}
	}

	vkb::destroy_surface(instance, surface);
	vkb::destroy_instance(instance);
	destroy_window_glfw(window);
}