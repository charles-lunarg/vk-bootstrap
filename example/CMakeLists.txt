add_executable(vk-bootstrap-triangle triangle.cpp)
target_link_libraries(vk-bootstrap-triangle
        PRIVATE
        glfw
        vk-bootstrap
        vk-bootstrap-compiler-warnings
        vk-boostrap-vulkan-headers)

add_custom_command(
        TARGET vk-bootstrap-triangle
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/example/shaders ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR})