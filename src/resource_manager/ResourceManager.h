#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<fstream>
#include<sstream>
#include <map>
#include<memory>
#include<iostream>
#include "../shaders/Shader_Program.h"

class ResourceManager {
	std::string relPath;   /*in this variable full path to main.py*/
	typedef std::map<std::string, std::shared_ptr<Shader_Program>> ShaderMapType;
	ShaderMapType shaderMap;
public:
	ResourceManager(const std::string& main_path);
	std::string get_file_string(const std::string& file_rel_path);
	std::shared_ptr<Shader_Program> make_shader_program(std::string name, const std::string& vertex_shader_rel_path, const std::string& fragment_shader_rel_path);
};