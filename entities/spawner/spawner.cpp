#include "spawner.hpp"
#include "../../engine/consts.hpp"
#include <iostream>
#include "../../utils/utils.hpp"
void Spawner::start(){
   timer = 0; 
}


void Spawner::update(float deltaTime) {
    timer += deltaTime;

    while (timer >= interval) {
        Zombie* z = new Zombie(player);

        bool leftSide = util::random(0, 1) == 0;

        int minY = player->posY - 150;
        int maxY = player->posY + 150;

        z->posY = util::random(minY, maxY);

        if (leftSide) {
            z->posX = -50;      
        } else {
            z->posX = 600 + 50;
        }

        engine->addEntity(z);
        timer -= interval;
    }
}

