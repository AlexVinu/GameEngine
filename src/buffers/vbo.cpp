#include "vbo.h"

/*init object, verticies must be in vector, idk why, but otherwise its not working*/
VBO::VBO(std::vector<GLfloat> &verts, GLenum type_of_shader) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), &verts[0], type_of_shader);   /*third argue must be start of array(&vector IS NOT &vector[0]*/

	/*checking for success*/
	GLint succes;
	glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_BINDING, &succes);    /*test for correctness*/
	if (!succes) {
		std::cerr << "Problems in vbo\n";
	}
	/*-------------------*/
};
void VBO::unbind_buffer() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	std::cerr << "unbind vbo " << id << std::endl;
	return;
};
void VBO::delete_buffer() const {
	glDeleteBuffers(1, &id);
	return;
};