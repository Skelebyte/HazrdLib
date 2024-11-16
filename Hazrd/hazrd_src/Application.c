#include "../Application.h"
#include <GLFW/glfw3.h>

void run(void start_function(), void update_function(Application app)) {

    struct Application app = {
        createWindow("hi mum!", WIDTH, HEIGHT),
        createPipeline("data/shaders/SimpleShader.vert.spv", "data/shaders/SimpleShader.frag.spv"),
        0.0f
    };

    start_function();


    while(windowRequestClose(app.window) == 0) {

        glfwPollEvents();

        update_function(app);
    }

    destroyPipeline(&app.pipeline);
    cleanupWindow(app.window);
    glfwTerminate();

}
