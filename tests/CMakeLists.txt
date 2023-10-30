if (WIN32)
    add_library(VulkanMock SHARED vulkan_mock.hpp vulkan_mock.cpp)
    # Need to name the target "vulkan-1" so that it'll be loaded instead of the *actual* vulkan-1.dll on the system
    set_target_properties(VulkanMock PROPERTIES OUTPUT_NAME "vulkan-1")
else()
    add_library(VulkanMock STATIC vulkan_mock.hpp vulkan_mock.cpp)
endif()
target_link_libraries(VulkanMock
    PUBLIC
        vk-bootstrap-vulkan-headers
    PRIVATE
        vk-bootstrap-compiler-warnings
)
target_compile_features(VulkanMock PUBLIC cxx_std_17)

add_executable(vk-bootstrap-test
    vulkan_library_loader.hpp
    bootstrap_tests.cpp
    error_code_tests.cpp
    unit_tests.cpp
    include_checks.cpp
)

target_link_libraries(vk-bootstrap-test
    PRIVATE
    vk-bootstrap
    vk-bootstrap-vulkan-headers
    vk-bootstrap-compiler-warnings
    VulkanMock
    Catch2::Catch2WithMain
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(vk-bootstrap-test PRIVATE -Wno-error=deprecated-declarations)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(vk-bootstrap-test PRIVATE /wd4996)
endif()

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(vk-bootstrap-test)
