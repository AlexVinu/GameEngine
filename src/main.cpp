#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "buffers/vbo.h"
#include "shaders/Shader_Program.h"
#include "resource_manager/ResourceManager.h"

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


int main(int argc, char* argv[])
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

    ResourceManager res(argv[0]);
    auto shader_program = res.make_shader_program("first", "res/shaders/first_vertex_shader.txt", "res/shaders/first_fragment_shader.txt");

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
        glUseProgram(shader_program->give_id());
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