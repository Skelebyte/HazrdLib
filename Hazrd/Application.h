#ifndef APPLICATION_H
#define APPLICATION_H


#define GLFW_INCLUDE_VULKAN
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "Window.h"
#include "Boolean.h"
#include "Pipeline.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct Application
{
    Window window;
    Pipeline pipeline;

    float deltaTime;

} Application;

// void update_function(Application app) - app is temp, until i add functions to get that data and a seperate time struct for the deltaTime
// and other related variables. (Application.deltaTime is 0.0f currently)
// TODO: do game loop and time stuff
void run(void start_function(), void update_function(Application app));

#endif
