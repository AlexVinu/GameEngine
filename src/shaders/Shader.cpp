#include "Shader.h"
#include <iostream>

Shader::Shader(GLenum type_of_shader, const GLchar* shader) {
    id = glCreateShader(type_of_shader);
    glShaderSource(id, 1, &shader, NULL);
    glCompileShader(id);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER:: (" << type_of_shader << ") ::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
};

GLuint Shader::give_id() {
    return id;
};

void Shader::delete_shader() {
    glDeleteShader(id);
    id = 0;
}
