#include "player.hpp"
#include "../../engine/consts.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
void Player::start() {
    this->hp = 100;
    this->maxHp = hp;
    this->speed = 200;
    this->damage = 5;
    this->size = 50; // player is an rectangle for now
    this->posX = 100;
    this->posY = 100;
}

void Player::update(float deltaTime) {
    const Uint8 *keys = getKeys();

    // movement
    if (keys[SDL_SCANCODE_W]) {
        this->posY -= speed * deltaTime;
    } else if (keys[SDL_SCANCODE_S]) {
        this->posY += speed * deltaTime;
    } else if (keys[SDL_SCANCODE_A]) {
        this->posX -= speed * deltaTime;
    } else if (keys[SDL_SCANCODE_D]) {
        this->posX += speed * deltaTime;
    }
}

void Player::render(SDL_Renderer *render) {
    SDL_Rect player{static_cast<int>(posX), static_cast<int>(posY), size, size};
    SDL_SetRenderDrawColor(render, 200, 40, 40, 255);
    SDL_RenderFillRect(render, &player);
}
