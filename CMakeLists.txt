cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

find_package(Vulkan REQUIRED)

add_library(vk-bootstrap src/VkBootstrap.h src/VkBootstrap.cpp)
add_library(vk-bootstrap::vk-bootstrap ALIAS vk-bootstrap)

add_library(vk-bootstrap-compiler-warnings INTERFACE)

# Determine whether we're compiling with clang++
string(FIND "${CMAKE_CXX_COMPILER}" "clang++" VK_BOOTSTRAP_COMPILER_CLANGPP)
if(VK_BOOTSTRAP_COMPILER_CLANGPP GREATER -1)
  set(VK_BOOTSTRAP_COMPILER_CLANGPP 1)
else()
  set(VK_BOOTSTRAP_COMPILER_CLANGPP 0)
endif()

target_compile_options(vk-bootstrap-compiler-warnings
        INTERFACE
        $<$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>,${VK_BOOTSTRAP_COMPILER_CLANGPP}>:
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
        PRIVATE
        vk-bootstrap-compiler-warnings)

option(VK_BOOTSTRAP_TEST "Test Vk-Bootstrap with glfw and Catch2" OFF)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR VK_BOOTSTRAP_TEST)

    add_subdirectory(ext)
    add_subdirectory(tests)
    add_subdirectory(example)
endif ()
