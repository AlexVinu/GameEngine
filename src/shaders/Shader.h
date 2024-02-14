#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
	GLuint id;
public:
	Shader(GLenum type_of_shader, const GLchar* shader);
	Shader(Shader& vertex_shader, Shader& fragment_shader);   /*constructor for shader program*/
	GLuint give_id();
	void delete_shader();   /*only for shaders, not shader programs*/
};