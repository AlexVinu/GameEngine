#include "ebo.h"

EBO::EBO(std::vector<GLuint> indicies, GLenum type_of_drawing)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLfloat), &indicies[0], type_of_drawing);

	GLint success;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_BINDING, &success);
	if (!success) {
		std::cerr << "Problems in EBO";
	}
};

void EBO::unbind_buffer() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	std::cerr << "unbind EBO " << id << std::endl;
	return;
};

void EBO::delete_buffer() const
{
	glDeleteBuffers(1, &id);
	return;
};


