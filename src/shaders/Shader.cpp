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
        std::cerr << "ERROR::SHADER:: (" << type_of_shader << ") ::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
};

Shader::Shader(Shader& vertex_shader, Shader& fragment_shader)  /*!!! comment in .h file*/
{
    id = glCreateProgram();
    glAttachShader(id, vertex_shader.give_id());
    glAttachShader(id, fragment_shader.give_id());
    glLinkProgram(id);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
};

GLuint Shader::give_id() {
    return id;
};

void Shader::delete_shader() {     /*!!! comment in .h file*/
    glDeleteShader(id);
    id = 0;
};
