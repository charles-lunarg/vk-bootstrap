cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

find_package(Vulkan REQUIRED)

add_library(vk-bootstrap src/VkBootstrap.h src/VkBootstrap.cpp)

target_include_directories(vk-bootstrap PUBLIC src)

target_include_directories(vk-bootstrap PUBLIC ${Vulkan_INCLUDE_DIR})
target_link_libraries(vk-bootstrap PUBLIC ${Vulkan_LIBRARY})

target_compile_features(vk-bootstrap PUBLIC cxx_std_11)

option(VK_BOOTSTRAP_TEST "Test Vk-Bootstrap with glfw and Catch2" OFF)

if (VK_BOOTSTRAP_TEST)

    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(ext/glfw)
    add_subdirectory(ext/Catch2)

    add_executable(vk-bootstrap-test tests/run_tests.cpp)

    target_link_libraries(vk-bootstrap-test vk-bootstrap)
    target_link_libraries(vk-bootstrap-test glfw)
    target_link_libraries(vk-bootstrap-test Catch2)

    add_executable(vk-bootstrap-triangle example/triangle.cpp)
    target_link_libraries(vk-bootstrap-triangle vk-bootstrap)
    target_link_libraries(vk-bootstrap-triangle glfw)

    add_custom_command(
        TARGET vk-bootstrap-triangle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/example/shaders ${CMAKE_CURRENT_BINARY_DIR} 
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()