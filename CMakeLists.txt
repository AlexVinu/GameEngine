cmake_minimum_required(VERSION 3.26.4 FATAL_ERROR)

set(PROJECT_NAME GameEngine)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/buffers/buffer_virtual.h
	src/buffers/vbo.h
	src/buffers/vbo.cpp
	src/buffers/ebo.h
	src/buffers/ebo.cpp
	src/shaders/Shader_program.h
	src/shaders/Shader_program.cpp
	src/resource_manager/ResourceManager.h
	src/resource_manager/ResourceManager.cpp
	src/TextureProgram/Texture_Program.h
	src/TextureProgram/Texture_Program.cpp
	src/auxillary/GLnum_plus.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

include_directories(external/glm)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)