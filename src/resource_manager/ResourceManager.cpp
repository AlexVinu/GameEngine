#include"ResourceManager.h"

ResourceManager::ResourceManager(const std::string& main_path) {
	unsigned end_of_string = main_path.find_last_of("/\\");      
	relPath = main_path.substr(0, end_of_string);
};

std::string ResourceManager::get_file_string(const std::string& file_rel_path) {
	std::string file_path = relPath + "/" + file_rel_path.c_str();  /*full path of file*/
	std::ifstream File;
	File.open(file_path, std::ios::in | std::ios::binary);
	if (!File.is_open()) {
		std::cerr << "File in path " + file_path + " isn`t open" << std::endl;
		return{};
	}
	std::stringstream readbuffer;
	readbuffer << File.rdbuf();
	return readbuffer.str();
};

std::shared_ptr<Shader_Program> ResourceManager::make_shader_program(std::string name, const std::string& vertex_shader_rel_path, const std::string& fragment_shader_rel_path)
{
	std::string vertex_shader_src = get_file_string(vertex_shader_rel_path);
	std::string fragment_shader_src = get_file_string(fragment_shader_rel_path);
	auto& shader_program = std::make_shared<Shader_Program> (vertex_shader_src, fragment_shader_src);
	shaderMap.emplace(name, shader_program);
	return shader_program;
};

