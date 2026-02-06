#include "spawner.hpp"
#include "../../engine/consts.hpp"
#include "../../utils/utils.hpp"
#include <iostream>
#include <cmath>
#include <random>

void Spawner::start() { 
    timer = 0;
    gen.seed(static_cast<unsigned>(std::time(nullptr)));
}

void Spawner::update(float deltaTime) {
    timer += deltaTime;

    while (timer >= interval) {
        //yeah I need to fix spawning
        Zombie *z = new Zombie(player);
        std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * 3.14159265359f);
        float angle = angleDist(gen);
        
        z->posX = player->posX + spawnRadius * cos(angle);
        z->posY = player->posY + spawnRadius * sin(angle);

        scene->addEntity(z);
        timer -= interval;
    }
}

void Spawner::loadTexture(SDL_Renderer* render, const char* path) {
    // Spawner doesn't need a texture
}
