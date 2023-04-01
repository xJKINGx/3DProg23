#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "XYZ.h"

#include <iostream>

// Here is just a basic definition of the screen size
const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;


int main()
{
    // OpenGL initializing functions
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Other inits
    XYZ* XYZptr = new XYZ();


    // Here we make some points for 3 triangles
    // Vertices coordinates
    GLfloat vertices[] =
    {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
        -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
        0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
        0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
    };

    // Indices for vertices order
    GLuint indices[] =
    {
        0, 3, 5, // Lower left triangle
        3, 2, 4, // Lower right triangle
        5, 4, 1 // Upper triangle
    };

    // Here we create the actual window that's gonna pop up
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bababooey", NULL, NULL);
    // if sentence to check nullptr exception
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Here we tell OpenGL to actually open the window we created
    glfwMakeContextCurrent(window);

    gladLoadGL();

    // This I think sets the coordinates of the screen. 0,0 being the smallest values,
    // and width, height being the max values
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Here we tell OpenGL to use our shader files
    Shader shaderProgram("default.vert", "default.frag");

    // Shader magic goes here
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    XYZptr->init(/*1*/);

    // Without this while loop the window will close the second it opens
    while (!glfwWindowShouldClose(window))
    {
        // glClearColor sets the color of the background in rgba, going from 0.0f to 1.0f
        glClearColor(0.07f, 0.13f, 0.17f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Shaders activate
        shaderProgram.Activate();
        VAO1.Bind();

        // The draw function will be moved eventually, the colors of the triangles can be
        // changed in the default.frag file
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        XYZptr->draw();

        glfwSwapBuffers(window);

        // PollEvents to make it so that the window actually listens for events
        // like clicking the "X" button on the top right of the window for example.
        glfwPollEvents();
    }

    // This is our garbage pile, we delete stuff we don't need here.
    // If we reach this point the program is over, and we need to delete this stuff
    // to save memory
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}