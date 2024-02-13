#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class VBO {
	GLuint id;
public:
	VBO(std::vector<GLfloat> &verts, GLenum type);
	VBO(const VBO&) = delete;          /*it shouldnt be copied or used with move()*/
	VBO(VBO&&) = delete;

	void unbind_vbo();
	void delete_vbo();
};
