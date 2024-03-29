#include"Shader_Program.h"

/*constructor for a single shader*/
Shader_Program::Shader::Shader(GLenum type_of_shader, const std::string& shader) {
    const GLchar* shader_char = shader.c_str();
    id = glCreateShader(type_of_shader);
    glShaderSource(id, 1, &shader_char, NULL);
    glCompileShader(id);

    /*checking for success*/
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER:: (" << type_of_shader << ") ::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    /*-------------------*/
};
/*------------------------------*/

GLuint Shader_Program::Shader::give_id() {
    return this->id;
}

/*set uniform into shader through shader program*/
void Shader_Program::Shader_Program::set_uniform(const GLchar* name_uniform, GLuint num_of_type)
{
    glUniform1i(glGetUniformLocation(id, name_uniform), num_of_type);
}
/*-------------------------------------*/

void Shader_Program::Shader::delete_shader() {
    glDeleteShader(id);
    id = 0;
}

/*constructor for shader program*/
Shader_Program::Shader_Program(const std::string& vertex_shader_str, const std::string& fragment_shader_str)  
{
    /*making single shaders*/
    Shader vertex_shader (GL_VERTEX_SHADER, vertex_shader_str);
    Shader fragment_shader (GL_FRAGMENT_SHADER, fragment_shader_str);
    /*-------------*/

    /*making shader program and attaching shaders, after linking shader program*/
    id = glCreateProgram();
    glAttachShader(id, vertex_shader.give_id());
    glAttachShader(id, fragment_shader.give_id());
    glLinkProgram(id);
    /*---------------------------------*/
    vertex_shader.delete_shader();
    fragment_shader.delete_shader();

    /*checking for succes*/
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    /*---------------------*/
};

GLuint Shader_Program::give_id()
{
    return this->id;
};