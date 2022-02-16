cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(VulkanBootstrap)

option(VK_BOOTSTRAP_WERROR "Enable warnings as errors during compilation" OFF)

add_library(vk-bootstrap-vulkan-headers INTERFACE)

set(VK_BOOTSTRAP_VULKAN_HEADER_DIR "" CACHE STRING "Specify the location of the Vulkan-Headers include directory.")
mark_as_advanced(VK_BOOTSTRAP_VULKAN_HEADER_DIR)

include(gen/CurrentBuildVulkanVersion.cmake)

if(NOT "${VK_BOOTSTRAP_VULKAN_HEADER_DIR}" STREQUAL "")
  target_include_directories(vk-bootstrap-vulkan-headers INTERFACE $<BUILD_INTERFACE:${VK_BOOTSTRAP_VULKAN_HEADER_DIR}>)
else ()
  find_package(Vulkan QUIET)

  if(${Vulkan_INCLUDE_DIR} STREQUAL "Vulkan_INCLUDE_DIR-NOTFOUND")
      include(FetchContent)
      FetchContent_Declare(
          VulkanHeaders
          GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers
          GIT_TAG        ${VK_BOOTSTRAP_SOURCE_HEADER_VERSION_GIT_TAG}
      )
      FetchContent_MakeAvailable(VulkanHeaders)
      target_link_libraries(vk-bootstrap-vulkan-headers INTERFACE Vulkan::Headers)
  else()
      set_target_properties(vk-bootstrap-vulkan-headers PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${Vulkan_INCLUDE_DIR})
  endif()
endif()

add_library(vk-bootstrap src/VkBootstrap.h src/VkBootstrap.cpp src/VkBootstrapDispatch.h)
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
        -Wconversion
        -Wsign-conversion>
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4>
        )

if(VK_BOOTSTRAP_WERROR)
  target_compile_options(vk-bootstrap-compiler-warnings
          INTERFACE
          $<$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>,${VK_BOOTSTRAP_COMPILER_CLANGPP}>:
          -pedantic-errors>
          $<$<CXX_COMPILER_ID:MSVC>:
          /WX>
          )
endif()

target_include_directories(vk-bootstrap PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)
target_link_libraries(vk-bootstrap
        PRIVATE
        vk-bootstrap-compiler-warnings
        vk-bootstrap-vulkan-headers
        ${CMAKE_DL_LIBS})
target_compile_features(vk-bootstrap PUBLIC cxx_std_14)

include(GNUInstallDirs)
install(FILES src/VkBootstrap.h src/VkBootstrapDispatch.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS vk-bootstrap vk-bootstrap-compiler-warnings vk-bootstrap-vulkan-headers
        EXPORT vk-bootstrap-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

option(VK_BOOTSTRAP_TEST "Test Vk-Bootstrap with glfw and Catch2" OFF)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR VK_BOOTSTRAP_TEST)

    add_subdirectory(ext)
    add_subdirectory(tests)
    add_subdirectory(example)
endif ()
