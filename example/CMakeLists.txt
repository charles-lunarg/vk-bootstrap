add_executable(vk-bootstrap-triangle triangle.cpp)
target_link_libraries(vk-bootstrap-triangle
    PRIVATE
        glfw
        vk-bootstrap
        vk-bootstrap-compiler-warnings
        Vulkan::Headers)
target_include_directories(vk-bootstrap-triangle PRIVATE ${CMAKE_CURRENT_BINARY_DIR}) # path to build directory for shaders

add_custom_command(
    TARGET vk-bootstrap-triangle
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/example/shaders ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR})

configure_file (
    "${PROJECT_SOURCE_DIR}/example/example_config.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/example_config.h"
)
