#include"ResourceManager.h"

/*init res object, put full path to exe file into variable*/
ResourceManager::ResourceManager(const std::string& main_path) {
	unsigned end_of_string = main_path.find_last_of("/\\");      
	relPath = main_path.substr(0, end_of_string);
};
/*----------------*/

std::string ResourceManager::get_file_string(const std::string& file_rel_path) {
	std::string file_path = relPath + "/" + file_rel_path.c_str();  /*full path of file*/
	std::ifstream File;
	File.open(file_path, std::ios::in | std::ios::binary);
	/*checking if file opened(if not, return nothing)*/
	if (!File.is_open()) {
		std::cerr << "File in path " + file_path + " isn`t open" << std::endl;
		return{};
	}
	/*-------------------*/
	/*returns contents of file in string type*/
	std::stringstream readbuffer;
	readbuffer << File.rdbuf();
	return readbuffer.str();
	/*-----------------------*/
};

std::shared_ptr<Shader_Program> ResourceManager::make_shader_program(std::string name, const std::string& vertex_shader_rel_path, const std::string& fragment_shader_rel_path)
{
	/*Getting shaders*/
	std::string vertex_shader_src = get_file_string(vertex_shader_rel_path);
	std::string fragment_shader_src = get_file_string(fragment_shader_rel_path);
	/*---------------*/

	std::shared_ptr<Shader_Program>& shader_program = std::make_shared<Shader_Program>(vertex_shader_src, fragment_shader_src);
	shaderMap.emplace(name, shader_program);   /*inserts shader_program into shaderMap*/
	return shader_program;
};

std::shared_ptr<Texture> ResourceManager::make_texture_program(std::string name, const std::string& texture_rel_path)
{
	std::string full_path = relPath + "/" + texture_rel_path;
	int width, height, channels; /*variables would be taken to a texture object*/
	unsigned char* image = stbi_load(full_path.c_str(), &width, &height, &channels, 0);

	/*checking if image loaded*/
	if (!image) {
		std::cerr << "image didnt loaded, name:: " << name << std::endl;
	}
	/*---------------------------*/

	std::shared_ptr<Texture>& texture_program = std::make_shared<Texture>(image, std::move(width), std::move(height), std::move(channels));
	stbi_image_free(image); /*deleting image*/
	textureMap.emplace(name, texture_program); /*inserts texture into textureMap*/
	return texture_program;
};

