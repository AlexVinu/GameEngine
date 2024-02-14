cmake_minimum_required(VERSION 3.26.4 FATAL_ERROR)

set(PROJECT_NAME GameEngine)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/buffers/vbo.h
	src/buffers/vbo.cpp
	src/shaders/Shader.h
	src/shaders/Shader.cpp
	src/resource_manager/ResourceManager.h
	src/resource_manager/ResourceManager.cpp
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)