#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class VBO {
	GLuint id;
public:
	VBO(std::vector<GLfloat> &verts, GLenum type);
	void unbind_vbo();
	void delete_vbo();
};