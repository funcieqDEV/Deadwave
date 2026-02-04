#pragma once
#include "../../engine/entity/entity.hpp"
#include "../player/player.hpp"
#include <SDL_render.h>
#include <SDL_stdinc.h>
class Zombie : public Entity {
  public:
    Zombie(Player* p){this->target = p;}
    float posX;
    float posY;
    int size; // zombie are also rectangles for now
    int speed;
    Uint16 damage;
    int hp;
    Uint16 maxHp;
    Player* target;
    void start() override;
    void render(SDL_Renderer *render) override;
    void update(float deltaTime) override;
    void follow(float deltaTime);
};
