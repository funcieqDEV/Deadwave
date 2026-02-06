#pragma once
#include "../../engine/entity/entity.hpp"
#include "../player/player.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <iostream>
class Zombie : public Entity {
  public:
    Zombie(Player *p) {
        if (!p) {
            std::cerr << "ERROR: Zombie received nullptr player!" << std::endl;
            posX = posY = 0;
        } else {
            target = p;
            posX = target->posX;
            posY = target->posY;
        }
        size = 32;
        speed = 50;
    }
    float posX;
    float posY;
    int size; // zombies are also rectangles for now
    int speed;
    Uint16 damage;
    int hp;
    Uint16 maxHp;
    Player *target = nullptr;
    SDL_Texture* texture;
    void start() override;
    void render(SDL_Renderer *render) override;
    void update(float deltaTime) override;
    void follow(float deltaTime);
    void loadTexture(SDL_Renderer* render,const char* path) override;
  private:
    SDL_Rect dest;
};
