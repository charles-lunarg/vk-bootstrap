cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

find_package(Vulkan REQUIRED)

find_package(glfw3)

add_library(vk-bootstrap 
    src/VkBootstrap.h
    src/Instance.cpp
    src/Device.cpp
    src/Swapchain.cpp)

target_include_directories(vk-bootstrap PUBLIC src)

target_include_directories(vk-bootstrap PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(vk-bootstrap PRIVATE ${Vulkan_LIBRARIES})

target_compile_features(vk-bootstrap PUBLIC cxx_std_11)

target_compile_options(vk-bootstrap PUBLIC -fsanitize=address)
target_link_options(vk-bootstrap PUBLIC -fsanitize=address)



add_executable(vk-bootstrap-test tests/run_tests.cpp)

target_link_libraries(vk-bootstrap-test vk-bootstrap)
target_link_libraries(vk-bootstrap-test glfw)