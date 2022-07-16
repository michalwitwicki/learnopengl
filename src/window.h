#ifndef _WINDOW_H_
#define _WINDOW_H_

#define GLFW_INCLUDE_NONE
#include <glfw3.h>

struct Window
{
    GLFWwindow* glfwWindow;
};

void initWindow(struct Window* window);

#endif // _WINDOW_H_