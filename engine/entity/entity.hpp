#pragma once

#include <SDL_render.h>
#include <iostream>
class Entity {
  public:
    virtual ~Entity() = default;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer *render) = 0;
    virtual void start() = 0;
    virtual void loadTexture(SDL_Renderer* render, const char* path) {
        if (!render) {
            std::cerr << "ERROR: Renderer is nullptr!\n";
            return;
        }
        if (!path) {
            std::cerr << "ERROR: Texture path is nullptr!\n";
            return;
        }
    }
};
