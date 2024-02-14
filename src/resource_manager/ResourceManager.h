#pragma once
#include<fstream>
#include<sstream>
#include <map>
#include<memory>
#include "../shaders/Shader.h"

class ResourceManager {
	std::string relPath;
public:
	ResourceManager(const std::string& main_path);
	std::string get_file_string(std::string name_of_file, const std::string& file_rel_path);
	
};