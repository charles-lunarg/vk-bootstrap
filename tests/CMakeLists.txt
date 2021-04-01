add_executable(vk-bootstrap-test main.cpp bootstrap_tests.cpp error_code_tests.cpp unit_tests.cpp)
target_link_libraries(vk-bootstrap-test
    PRIVATE
    vk-bootstrap
    vk-boostrap-vulkan-headers
    vk-bootstrap-compiler-warnings
    glfw
    Catch2
)