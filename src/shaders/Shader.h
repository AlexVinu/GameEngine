#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
	GLuint id;
public:
	Shader(GLenum type_of_shader, const GLchar* shader);
	GLuint give_id();
	void delete_shader();
};