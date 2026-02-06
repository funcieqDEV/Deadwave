#pragma once

#include "../engine/engine.hpp"
#include "../engine/scene/scene.hpp"
#include "../entities/player/player.hpp"
#include "../entities/spawner/spawner.hpp"

class GameScene : public Scene {
  public:
    explicit GameScene(Engine *eng) : engine(eng) {}

    void start() override {
        Player *player = new Player();
        Spawner *spawner = new Spawner(this, player);

        addPrior(player);
        player->start();
        addEntity(spawner);
        
        spawner->start();
    }

    void update(float deltaTime) override { Scene::update(deltaTime); }

    void render(SDL_Renderer *renderer) override { Scene::render(renderer); }

  private:
    Engine *engine;
};
