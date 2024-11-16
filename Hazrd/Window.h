#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "Boolean.h"

typedef struct Window
{
    GLFWwindow* glfwWindow;
    const char* name;
    const int width;
    const int height;
} Window;


Window createWindow(const char* name, const int w, const int h);

int windowRequestClose(Window window);

void cleanupWindow(Window target);

#endif
