#pragma once
#include "buffer_virtual.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class EBO: public Buffer{
	GLuint id;
public:
	EBO(std::vector<GLuint> indicies, GLenum type_of_drawing);
	void unbind_buffer() const override;
	void delete_buffer() const override;
};