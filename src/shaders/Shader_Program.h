#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>


class Shader_Program {
	GLuint id;
	class Shader {
		GLuint id;
	public:
		Shader(GLenum type_of_shader, const std::string& shader);
		GLuint give_id();
		void delete_shader();
	};
public:
	Shader_Program(const std::string& vertex_shader_str, const std::string& fragment_shader_str);
	GLuint give_id();
};