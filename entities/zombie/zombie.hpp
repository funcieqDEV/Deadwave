#pragma once
#include "../../engine/entity/entity.hpp"
#include <SDL_render.h>
#include <SDL_stdinc.h>
class Zombie : public Entity {
  public:
    float posX;
    float posY;
    int size; // zombie are also rectangles for now
    int speed;
    Uint16 damage;
    int hp;
    Uint16 maxHp;
    void start() override;
    void render(SDL_Renderer *render) override;
    void update(float deltaTime) override;
};
