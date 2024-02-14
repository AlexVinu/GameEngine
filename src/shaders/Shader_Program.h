#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

#include"Shader.h"

class Shader_Program {
	GLuint id;
public:
	Shader_Program(Shader& vertex_shader, Shader& fragment_shader);
	GLuint give_id();
};