cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

find_package(Vulkan REQUIRED)

add_library(vk-bootstrap src/VkBootstrap.h src/VkBootstrap.cpp)
add_library(vk-bootstrap::vk-bootstrap ALIAS vk-bootstrap)

add_library(vk-bootstrap-compiler-warnings INTERFACE)
target_compile_options(vk-bootstrap-compiler-warnings
        INTERFACE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Wextra
        -pedantic-errors
        -Wconversion
        -Wsign-conversion>
        $<$<CXX_COMPILER_ID:MSVC>:
        /WX
        /W4>
        )

target_include_directories(vk-bootstrap PUBLIC src)
target_include_directories(vk-bootstrap PUBLIC ${Vulkan_INCLUDE_DIR})
target_link_libraries(vk-bootstrap
        PUBLIC ${Vulkan_LIBRARY}
        PRIVATE
        vk-bootstrap-compiler-warnings)

option(VK_BOOTSTRAP_TEST "Test Vk-Bootstrap with glfw and Catch2" OFF)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR VK_BOOTSTRAP_TEST)
    add_subdirectory(ext)
    add_subdirectory(tests)
    add_subdirectory(example)
endif ()
