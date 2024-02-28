#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>


class Shader_Program {
	GLuint id;
	/*inner class for single shader*/
	class Shader { 
		GLuint id;
	public:
		Shader(GLenum type_of_shader, const std::string& shader);
		GLuint give_id();
		void delete_shader();
	};
	/*----------------*/
public:
	Shader_Program(const std::string& vertex_shader_str, const std::string& fragment_shader_str);
	void set_uniform(const GLchar* name_uniform, GLuint num_of_type);
	GLuint give_id();
};