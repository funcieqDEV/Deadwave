#pragma once

#include <SDL2/SDL.h>
#include "scene/scene_manager.hpp"

class Engine {
public:
    Engine() = default;
    ~Engine();

    int init(const char* title, int width, int height);

    void update();
    void render();

    bool isRunning() const;

    inline SDL_Renderer* getRenderer() const { return _render; }
    inline float getDeltaTime() const { return _delta; }

    SceneManager sceneManager;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* _render = nullptr;

    bool _isRunning = false;

    float _delta = 0.0f;
    Uint32 lastTime = 0;
};

