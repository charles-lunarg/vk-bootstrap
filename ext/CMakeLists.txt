option(GLFW_BUILD_TESTS "" OFF)
option(GLFW_BUILD_DOCS "" OFF)
option(GLFW_INSTALL "" OFF)
option(GLFW_BUILD_EXAMPLES "" OFF)

option(CATCH_BUILD_TESTING "" OFF)
option(CATCH_ENABLE_WERROR "" OFF)
option(CATCH_INSTALL_DOCS "" OFF)
option(CATCH_INSTALL_HELPERS "" OFF)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1) #remove Catch2 target spam

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        3.3.2
)
FetchContent_MakeAvailable(glfw)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG        v2.13.7
)
FetchContent_MakeAvailable(Catch2)