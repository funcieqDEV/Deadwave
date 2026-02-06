#include "engine.hpp"
#include <SDL2/SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <SDL_image.h>
#include <iostream>

Engine::~Engine() {
    if (_render)
        SDL_DestroyRenderer(_render);
    if (window)
        SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

int Engine::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL init error: " << SDL_GetError() << "\n";
        return 1;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (!window) {
        std::cerr << "Window creation error: " << SDL_GetError() << "\n";
        return 1;
    }

    _render = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!_render) {
        std::cerr << "Renderer creation error: " << SDL_GetError() << "\n";
        return 1;
    }
    TTF_Init();
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("Error during initialization SDL_image: %s\n", IMG_GetError());
}


    _isRunning = true;
    lastTime = SDL_GetTicks();
    return 0;
}

void Engine::update() {
    Uint32 now = SDL_GetTicks();
    _delta = (now - lastTime) / 1000.0f;
    lastTime = now;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            _isRunning = false;
    }
    if (!sceneStack.empty())
        sceneStack.back()->update(getDeltaTime());
}

void Engine::render() {
    SDL_SetRenderDrawColor(_render, 30, 30, 40, 255);
    SDL_RenderClear(_render);

    if (!sceneStack.empty())
        sceneStack.back()->render(_render);

    SDL_RenderPresent(_render);
}

bool Engine::isRunning() const { return _isRunning; }
