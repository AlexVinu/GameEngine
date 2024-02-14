#include"Shader_Program.h"

Shader_Program::Shader_Program(Shader& vertex_shader, Shader& fragment_shader)  /*!!! comment in .h file*/
{
    id = glCreateProgram();
    glAttachShader(id, vertex_shader.give_id());
    glAttachShader(id, fragment_shader.give_id());
    glLinkProgram(id);
    vertex_shader.delete_shader();
    fragment_shader.delete_shader();

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
};

GLuint Shader_Program::give_id()
{
    return id;
};