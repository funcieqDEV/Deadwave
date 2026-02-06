#include "zombie.hpp"
#include <SDL_image.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <iostream>

void Zombie::start() {
    this->hp = 100;
    this->maxHp = hp;
    this->speed = 50;
    this->damage = 5;
    this->posX = 200;
    this->posY = 200;
    dest.x = posX;
    dest.y = posX;
    dest.w = 64; //zombie.png is 16x16, scaled 7x
    dest.h = 64;
}

void Zombie::render(SDL_Renderer *render) {
    SDL_RenderCopy(render, texture, NULL, &dest); 
}

void Zombie::update(float deltaTime) {
    // follow player
    follow(deltaTime);
    //update dest position
    dest.x = posX;
    dest.y = posY;
}

void Zombie::follow(float deltaTime) {
    if (!target) {
        std::cout << "target is nullptr!\n";
    }
    // target is Player ofc
    int x = target->posX;
    int y = target->posY;

    if (posX > x) {
        posX -= speed * deltaTime;
    }
    if (posX < x) {
        posX += speed * deltaTime;
    }
    if (posY > y) {
        posY -= speed * deltaTime;
    }
    if (posY < y) {
        posY += speed * deltaTime;
    }
}

void Zombie::loadTexture(SDL_Renderer* render,const char* path){
   Entity::loadTexture(render, path);
   this->texture = IMG_LoadTexture(render, path);
   if (!this->texture) {
       std::cerr << "ERROR: Failed to load zombie texture from " << path << ": " << IMG_GetError() << "\n";
   }
}

