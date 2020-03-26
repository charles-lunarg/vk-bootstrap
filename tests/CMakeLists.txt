add_executable(vk-bootstrap-test main.cpp run_tests.cpp)
target_link_libraries(vk-bootstrap-test
        PRIVATE
        vk-bootstrap
        vk-bootstrap-compiler-warnings
        glfw
        Catch2
        )