#include "zombie.hpp"
#include <SDL_render.h>

void Zombie::start() {
    this->hp = 100;
    this->maxHp = hp;
    this->speed = 300;
    this->damage = 5;
    this->size = 35; // zombie is an rectangle for now
    this->posX = 200;
    this->posY = 200;
}

void Zombie::render(SDL_Renderer *render) {
    SDL_Rect zombie{static_cast<int>(posX), static_cast<int>(posY), size, size};
    SDL_SetRenderDrawColor(render, 30, 230, 40, 255);
    SDL_RenderFillRect(render, &zombie);
}

void Zombie::update(float deltaTime) {}
