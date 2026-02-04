#include "engine/engine.hpp"
#include "entities/entities.hpp"
#include <SDL2/SDL.h>
#include <ctime>
#include <cstdlib>
int main() {
    srand(time(NULL));
    Engine* engine = new Engine();
    if (engine->init("Deadwave v0.1", 800, 600) != 0)
        return 1;

    Player* player = new Player();
    Spawner* spawner = new Spawner(engine, player);
    engine->addPrior(player);
    engine->addEntity(spawner);
   

    engine->start();
    while (engine->isRunning()) {
        engine->update();
        engine->render();
    }

    delete engine;  
    return 0;
}

