#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<fstream>
#include<sstream>
#include <map>
#include<memory>
#include<iostream>

#include "../shaders/Shader_Program.h"
#include "../TextureProgram/Texture_Program.h"

#include "C:/OpenGL/GameEngine/res/stb_image.h"

class ResourceManager {
	std::string relPath;   /*in this variable full path to exe file*/

	std::string get_file_string(const std::string& file_rel_path); /*gets contents from file in string type*/ /*!!!method only for other methods!!!*/

	typedef std::map<std::string, std::shared_ptr<Shader_Program>> ShaderMap;   
	ShaderMap shaderMap;   /*there are Shader_programs in it*/

	typedef std::map<std::string, std::shared_ptr<Texture>> TextureMap;
	TextureMap textureMap; /*there are textures in it*/
public:
	ResourceManager(const std::string& main_path);
	std::shared_ptr<Shader_Program> make_shader_program(std::string name, const std::string& vertex_shader_rel_path, const std::string& fragment_shader_rel_path); /*returns Shader_program, it exists in its own variable and in special map*/
	std::shared_ptr<Texture> make_texture_program(std::string name, const std::string& texture_rel_path);   /*returns texture_program, it exists in its own variable and in special map*/
};