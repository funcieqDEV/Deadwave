#pragma once
#include "entity/entity.hpp"
#include <SDL2/SDL.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <SDL_video.h>
#include <vector>
class Engine {
  public:
    Engine() {}
    ~Engine();
    SDL_Window *window;
    SDL_Renderer *_render;
    float getDeltaTime();
    void update();
    void render();
    void start();
    int init(const char *title, int width, int height);
    bool isRunning();
    void addEntity(Entity* entity){entites.push_back(entity);}
  private:
    bool _isRunning = false;
    Uint32 lastTime;
    Uint32 currentTime;
    float _delta;
    SDL_Event event;
    std::vector<Entity*> entites;
};
