#define GLFW_INCLUDE_VULKAN
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "Hazrd/Application.h"

int bingo = 0;

void begin() {
    printf("hello, start!\n");
}

void update(Application app) {
    printf("hello, update! %d\n", bingo);
    bingo++;

    if(bingo > 1) {
        glfwSetWindowShouldClose(app.window.glfwWindow, true);
    }
}



int main() {

    run(begin, update);

    return 0;
}
