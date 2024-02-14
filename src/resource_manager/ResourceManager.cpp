#include"ResourceManager.h"
#include<iostream>

ResourceManager::ResourceManager(const std::string& main_path) {
	unsigned end_of_string = main_path.find_last_of("/\\");
	relPath = main_path.substr(0, end_of_string);
};

std::string ResourceManager::get_file_string(std::string name_of_file, const std::string& file_rel_path) {
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
}

