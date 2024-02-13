#include "vbo.h"
#include <iostream>

/*idk why, but it works only with vector*/
VBO::VBO(std::vector<GLfloat> &verts, GLenum type) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), &verts[0], type);/*third argue must be start of array(&vector IS NOT &vector[0]*/

	GLint succes;
	glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_BINDING, &succes);
	if (!succes) {
		std::cerr << "Problems in vbo\n";
	}
};
void VBO::unbind_vbo() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	std::cerr << "unbind vbo " << id << std::endl;
	return;
};
void VBO::delete_vbo() {
	glDeleteBuffers(1, &id);
	return;
};