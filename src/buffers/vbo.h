#pragma once
#include "buffer_virtual.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class VBO: public Buffer {
	GLuint id;
public:
	VBO(std::vector<GLfloat> &verts, GLenum type_of_shader); /*init object*/
	void unbind_buffer() const override;
	void delete_buffer() const override;
};