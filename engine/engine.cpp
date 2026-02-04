#include "engine.hpp"
#include <SDL2/SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <cstdio>
#include <iostream>


Engine::~Engine() {
    SDL_DestroyRenderer(_render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Engine::init(const char *title, int width, int height) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL video init error: " << SDL_GetError() << "\n";
        return 1;
    }

    Engine::window =
        SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED_DISPLAY(1),
                         SDL_WINDOWPOS_CENTERED_DISPLAY(1), width, height, 0);

    if (!window) {
        std::cerr << "Error during window creation: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    Engine::_render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!_render) {
        std::cerr << "Error during renderer creation: " << SDL_GetError()
                  << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    return 0;
}

void Engine::start() {
    _isRunning = true;
    for(auto e: entites){
        e->start();
    }
    lastTime = SDL_GetTicks();
}

void Engine::update() {
    Uint32 currentTime = SDL_GetTicks();
    _delta = (currentTime - lastTime) / 1000.0f; // delta (seconds)
    lastTime = currentTime;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }

    //update entities
    for(auto e : entites){
        e->update(getDeltaTime());
    }
    //render everything
    this->render(); 
}

void Engine::render(){
    SDL_SetRenderDrawColor(_render, 30, 30, 40, 255);
    SDL_RenderClear(_render);
    for(auto e: entites){
        e->render(_render);
    }
    //show frame
    SDL_RenderPresent(_render);
}

float Engine::getDeltaTime() { return Engine::_delta; }

bool Engine::isRunning() { return _isRunning; }
