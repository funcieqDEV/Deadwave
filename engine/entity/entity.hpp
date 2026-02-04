#pragma once

#include <SDL_render.h>
class Entity {
  public:
    virtual ~Entity() = default;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer *render) = 0;
    virtual void start() = 0;
};
