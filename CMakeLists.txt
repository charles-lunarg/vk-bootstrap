cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

find_package(Vulkan REQUIRED)

add_library(vk-bootstrap 
    src/VkBootstrap.h
    src/Util.h
    src/Instance.h
    src/Device.h
    src/Swapchain.h
    src/Instance.cpp
    src/Device.cpp
    src/Swapchain.cpp)

target_include_directories(vk-bootstrap PUBLIC src)

target_include_directories(vk-bootstrap PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(vk-bootstrap PRIVATE ${Vulkan_LIBRARIES})

target_compile_features(vk-bootstrap PUBLIC cxx_std_11)

option(VK_BOOTSTRAP_TEST "Test Vk-Bootstrap with glfw and Catch2" OFF)

if (VK_BOOTSTRAP_TEST)

add_subdirectory(ext/glfw)
add_subdirectory(ext/Catch2)

add_executable(vk-bootstrap-test tests/run_tests.cpp)

target_link_libraries(vk-bootstrap-test vk-bootstrap)
target_link_libraries(vk-bootstrap-test glfw)

endif(VK_BOOTSTRAP_TEST)