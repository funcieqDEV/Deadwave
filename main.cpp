#include "engine/engine.hpp"
#include "entities/player/player.hpp"
#include <SDL2/SDL.h>

int main() {
    Engine *engine = new Engine();
    int err = engine->init("Deadwave v0.1", 800, 600);
    if (err != 0) {
        return err;
    }
    Player p;
    engine->addEntity(&p);
    engine->start();
    while (engine->isRunning()) {
        engine->update();
    }

    delete engine;
    return 0;
}
