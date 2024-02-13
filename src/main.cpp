#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "buffers/vbo.h"

int WindowSizeX = 800;
int WindowSizeY = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void window_Size_Callback(GLFWwindow* window, int width, int height) {
    WindowSizeX = width;
    WindowSizeY = height;
    glViewport(0, 0, WindowSizeX, WindowSizeY);
};

std::vector<float> vertices = {
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // Нижний правый угол
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // Нижний левый угол
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // Верхний угол
};

const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 colors;\n "
"void main()\n"
"{\n"
"gl_Position = vec4(position, 1.0f);\n"
"colors = color;\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"in vec3 colors;\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(colors, 1.0f);\n"
"}\n\0";

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WindowSizeX, WindowSizeY, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Make callbacks for keys*/
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGL()) {
        std::cout << "gladLoadGL ERROR" << std::endl;
        return -1;
    }
    glfwSetWindowSizeCallback(window, window_Size_Callback);

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertex_shader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    VBO vbo(vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    vbo.unbind_vbo();
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /*clear colour buffer*/
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Render here */
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    vbo.delete_vbo();

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}