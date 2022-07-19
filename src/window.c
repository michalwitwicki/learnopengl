#include "window.h"

#include <gl.h>
// #define GLFW_INCLUDE_NONE
// #include <glfw3.h>

#include <stdlib.h>
#include <stdio.h>
// // #include <math.h>

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// --- GLFW setup ---
void windowInit(struct Window* window)
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window->glfwWindow = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

    if (!window->glfwWindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window->glfwWindow, key_callback);
    glfwSetFramebufferSizeCallback(window->glfwWindow, framebuffer_size_callback);

    glfwMakeContextCurrent(window->glfwWindow);
    if (!gladLoadGL(glfwGetProcAddress))
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSwapInterval(1);
}