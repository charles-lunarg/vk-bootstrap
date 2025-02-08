add_executable(vk-bootstrap-triangle triangle.cpp)
target_link_libraries(vk-bootstrap-triangle
    PRIVATE
        glfw
        vk-bootstrap
        vk-bootstrap-compiler-warnings
        Vulkan::Headers)
target_include_directories(vk-bootstrap-triangle PRIVATE ${CMAKE_CURRENT_BINARY_DIR}) # path to build directory for shaders

find_program(GLSLANG_FOUND glslang)
if(GLSLANG_FOUND)
    message(STATUS "glslang found, will compile shaders automatically")

    set(COMPILED_SHADER_FILES)
    macro(compile_shader SHADER_NAME SHADER_STAGE)
        set(SHADER_SOURCE ${CMAKE_SOURCE_DIR}/example/shaders/${SHADER_NAME})
        set(SHADER_SPIRV ${CMAKE_SOURCE_DIR}/example/shaders/${SHADER_NAME}.spv)
        set(SHADER_DEST_SPIRV ${CMAKE_BINARY_DIR}/example/${SHADER_NAME}.spv)

        add_custom_command(
            OUTPUT ${SHADER_SPIRV}
            COMMAND glslang ${SHADER_SOURCE} -o ${SHADER_SPIRV} --target-env vulkan1.0 -S ${SHADER_STAGE}
            DEPENDS ${SHADER_SOURCE}
            COMMENT "Shader ${SHADER_NAME} compiled"
        )

        add_custom_command(
            OUTPUT ${SHADER_DEST_SPIRV}
            COMMAND ${CMAKE_COMMAND} -E copy ${SHADER_SPIRV} ${SHADER_DEST_SPIRV}
            DEPENDS ${SHADER_SPIRV}
        )
        list(APPEND COMPILED_SHADER_FILES ${SHADER_DEST_SPIRV})
    endmacro()

    compile_shader(frag.glsl frag)
    compile_shader(vert.glsl vert)
    add_custom_target(generate_shaders DEPENDS ${COMPILED_SHADER_FILES})
    add_dependencies(vk-bootstrap-triangle generate_shaders)
endif()


configure_file (
    "${PROJECT_SOURCE_DIR}/example/example_config.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/example_config.h"
)
