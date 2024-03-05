#pragma once
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Texture {
	GLuint id;
	/*variables for using in class object (!!!more info near class init!!!)*/
	int width;
	int height;
	int channels;
	/*-------------------------*/
public:
	unsigned char* image;
	Texture(unsigned char* image, const int& width, const int& height, const int& channels);   /*init object with variables, using rvalue refs (its logically clearer to put this variables into class object)*/
	GLuint give_id();
};