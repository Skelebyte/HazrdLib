#include <stdio.h>
// #include <stdbool.h>
#include <SDL2/SDL.h>
// #include <SDL2/sdl_im


typedef int bool;
#define true 1
#define false 0

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define FAILURE false
#define SUCCESS true

SDL_Window* window = NULL; // window to render to
SDL_Surface* windowSurface = NULL; // surface of the window
SDL_Surface* imageSurface = NULL; // the image to renderer

bool init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to init SDL! SDL Error: %s\n", SDL_GetError());
        return FAILURE;
    }

    return SUCCESS;
}

bool createWindow(const char* name, int w, int h) {
    window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
        /*
        name - name of the window
        SDL_WINDOWPOS_CENTERED - centered window on the screen (x pos)
        SDL_WINDOWPOS_CENTERED - centered window on the screen (y pos)
        w - width of the window
        h - height of the window
        SDL_WINDOW_SHOWN - show the window
        */
    if(window == NULL) {
        printf("failed to create window! SDL_Error: %s\n", SDL_GetError());
        return FAILURE;
    }

    windowSurface = SDL_GetWindowSurface(window);
    if(windowSurface == NULL) {
        printf("failed to get surface from window! SDL_Error: %s\n", SDL_GetError());
        return FAILURE;
    }

    return SUCCESS;
}

void cleanup() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool loadMedia(const char* path) {
    // imageSurface = SDL_Load
}

int main() {

    if(init() == FAILURE) {
        return 1;
    }

    if(createWindow("Hi, mum!", WINDOW_WIDTH, WINDOW_HEIGHT) == FAILURE) {
        return 2;
    }

    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF)); // make window fill with white

    SDL_UpdateWindowSurface(window);

    SDL_Event event;
    bool running = true;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) running = false;
        }
    }

    // cleanup
    cleanup();

    return 0;
}

