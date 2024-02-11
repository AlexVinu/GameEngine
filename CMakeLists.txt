cmake_minimum_required(VERSION 3.26.4 FATAL_ERROR)

set(PROJECT_NAME GameEngine)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp)