#pragma once
#include "../../engine/entity/entity.hpp"
#include <SDL_stdinc.h>
#include <cstdint>
class Player : public Entity {
  public:
    int16_t hp;
    Uint16 maxHp;
    Uint16 damage;
    Uint16 speed;
    float posX;
    float posY;
    int size;
    void update(float deltaTime) override;
    void render(SDL_Renderer *render) override;
    void start() override;
};
