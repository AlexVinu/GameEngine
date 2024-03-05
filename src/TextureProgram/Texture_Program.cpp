#include "Texture_Program.h"

Texture::Texture(unsigned char* image, const int& width, const int& height, const int& channels)
{
	/*Its logically clearer to put this variables into class object*/
	this->image = image;
	this->width = width;
	this->height = height;
	this->channels = channels;
	/*-----------------------------*/

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);   /*set texture wrapping(if texcoords more 1 or less -1*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);   /*same*/

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);     /*texture filters*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);     /*same*/

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->image);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::give_id()
{
	return this->id;
}
