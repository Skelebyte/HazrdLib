#include "../Window.h"

Window createWindow(const char* name, const int w, const int h) {
    glfwInit(); // start glfw
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // GLFW_NO_API - disable opengl
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // GLFW_FALSE - disable window resizing

    Window newWindow = {
        glfwCreateWindow(w, h, name, NULL, NULL),
        name,
        w,
        h
    };

    return newWindow;
}

int windowRequestClose(Window window) {
    if(glfwWindowShouldClose(window.glfwWindow)) {
        printf("wants to close.\n");
        return 1;
    } else {
        return 0;
    }
}

void cleanupWindow(Window target) {
    glfwDestroyWindow(target.glfwWindow);
}
