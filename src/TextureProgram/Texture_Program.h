#pragma once
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Texture {
	GLuint id;
	unsigned char* image;
	int width;
	int height;
	int channels;
public:
	Texture(unsigned char* image, int width, int height, int channels);
	GLuint give_id();
};