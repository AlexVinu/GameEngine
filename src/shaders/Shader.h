#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shader {
	GLuint id;
public:
	Shader(GLenum type_of_shader, const std::string& shader);  
	GLuint give_id();
	void delete_shader();   
};