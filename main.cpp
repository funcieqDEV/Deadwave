#include "engine/engine.hpp"
#include "scenes/game_scene.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr));

    Engine engine;
    if (engine.init("Deadwave v0.1", 800, 600) != 0)
        return 1;

    engine.sceneManager.setScene(new GameScene(&engine));

    while (engine.isRunning()) {
        engine.update();
        engine.render();
    }

    return 0;
}
