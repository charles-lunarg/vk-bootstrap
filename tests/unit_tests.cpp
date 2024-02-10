#include <catch2/catch_test_macros.hpp>

#include "VkBootstrap.cpp"

#include "vulkan_mock.hpp"

TEST_CASE("Single Queue Device", "[UnitTests.queue_selection_logic]") {
    std::vector<VkQueueFamilyProperties> families = { VkQueueFamilyProperties{
        VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } } };

    REQUIRE(0 == vkb::detail::get_first_queue_index(families, VK_QUEUE_GRAPHICS_BIT));
    REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
            vkb::detail::get_separate_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_GRAPHICS_BIT));
    REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
            vkb::detail::get_separate_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT));
    REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
            vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT));
    REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
            vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT));
}

TEST_CASE("Dedicated Compute Queue, Separate Transfer", "[UnitTests.queue_selection_logic]") {
    SECTION("Dedicated Queue First") {
        std::vector<VkQueueFamilyProperties> families = {
            VkQueueFamilyProperties{
                VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } }
        };

        REQUIRE(0 == vkb::detail::get_first_queue_index(families, VK_QUEUE_GRAPHICS_BIT));
        REQUIRE(1 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT, 0));
        REQUIRE(2 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, 0));
        REQUIRE(1 == vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT));
        REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
                vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT));
    }
    SECTION("Dedicated Queue Last") {
        std::vector<VkQueueFamilyProperties> families = {
            VkQueueFamilyProperties{
                VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } }
        };

        REQUIRE(0 == vkb::detail::get_first_queue_index(families, VK_QUEUE_GRAPHICS_BIT));
        REQUIRE(2 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT, 0));
        REQUIRE(1 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, 0));
        REQUIRE(2 == vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT));
        REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
                vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT));
    }
}

TEST_CASE("Dedicated Transfer Queue, Separate Compute", "[UnitTests.queue_selection_logic]") {
    SECTION("Dedicated Queue First") {
        std::vector<VkQueueFamilyProperties> families = {
            VkQueueFamilyProperties{
                VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } }
        };

        REQUIRE(0 == vkb::detail::get_first_queue_index(families, VK_QUEUE_GRAPHICS_BIT));
        REQUIRE(2 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT, 0));
        REQUIRE(1 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, 0));
        REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
                vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT));
        REQUIRE(1 == vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT));
    }
    SECTION("Dedicated Queue Last") {
        std::vector<VkQueueFamilyProperties> families = {
            VkQueueFamilyProperties{
                VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } },
            VkQueueFamilyProperties{ VK_QUEUE_TRANSFER_BIT, 1, 0, VkExtent3D{ 1, 1, 1 } }
        };

        REQUIRE(0 == vkb::detail::get_first_queue_index(families, VK_QUEUE_GRAPHICS_BIT));
        REQUIRE(1 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_TRANSFER_BIT, 0));
        REQUIRE(2 == vkb::detail::get_separate_queue_index(
                         families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT, 0));
        REQUIRE(vkb::detail::QUEUE_INDEX_MAX_VALUE ==
                vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT));
        REQUIRE(2 == vkb::detail::get_dedicated_queue_index(families, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_COMPUTE_BIT));
    }
}

vkb::Device setup_mock_for_queue_selection(std::vector<VkQueueFamilyProperties> const& queue_families) {
    VulkanMock& mock = get_vulkan_mock();
    VulkanMock::PhysicalDeviceDetails physical_device_details{};
    physical_device_details.properties.apiVersion = VK_API_VERSION_1_0;
    physical_device_details.queue_family_properties = queue_families;
    mock.add_physical_device(std::move(physical_device_details));

    return vkb::DeviceBuilder{
        vkb::PhysicalDeviceSelector{ vkb::InstanceBuilder{}.set_headless().build().value() }.select().value()
    }
        .build()
        .value();
}

TEST_CASE("Single Uber Queue", "[UnitTests.get_first_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_first_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_first_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 0 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_first_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 0 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_first_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_first_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_first_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Compute + Transfer", "[UnitTests.get_first_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_first_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_first_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 0 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_first_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 0 && q2.queue != nullptr));
}

TEST_CASE("Single Uber Queue", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 0 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 0 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Compute + Transfer", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 1 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 1 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Compute + Transfer, Compute", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 2 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 1 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Compute, Compute + Transfer", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 1 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 2 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Transfer, Compute + Transfer", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 2 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 1 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}

TEST_CASE("Uber, Compute + Transfer, Transfer", "[UnitTests.get_preferred_queue_and_index]") {
    vkb::Device d = setup_mock_for_queue_selection(
        { VkQueueFamilyProperties{ VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT, 1 },
            VkQueueFamilyProperties{ VK_QUEUE_TRANSFER_BIT, 1 } });

    vkb::QueueAndIndex q0 = d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT).value();
    CHECK((q0.index == 0 && q0.queue != nullptr));

    vkb::QueueAndIndex q1 = d.get_preferred_queue_and_index(VK_QUEUE_COMPUTE_BIT).value();
    CHECK((q1.index == 1 && q1.queue != nullptr));

    vkb::QueueAndIndex q2 = d.get_preferred_queue_and_index(VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q2.index == 2 && q2.queue != nullptr));

    vkb::QueueAndIndex q3 =
        d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT).value();
    CHECK((q3.index == 0 && q3.queue != nullptr));

    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_PROTECTED_BIT).matches_error(vkb::QueueError::queue_type_unavailable));
    CHECK(d.get_preferred_queue_and_index(VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT | VK_QUEUE_PROTECTED_BIT)
              .matches_error(vkb::QueueError::queue_type_unavailable));
}
