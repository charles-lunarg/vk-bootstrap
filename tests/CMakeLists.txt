add_executable(vk-bootstrap-test
    bootstrap_tests.cpp
    error_code_tests.cpp
    unit_tests.cpp)

target_link_libraries(vk-bootstrap-test
    PRIVATE
    vk-bootstrap
    vk-bootstrap-vulkan-headers
    vk-bootstrap-compiler-warnings
    glfw
    Catch2::Catch2WithMain
)

# This should be how to make CTest aware of the tests, but unfortunately it fails to link. The tests run fine on their own, so this is left as a TODO
# list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
# include(CTest)
# include(Catch)
# catch_discover_tests(vk-bootstrap-test)
