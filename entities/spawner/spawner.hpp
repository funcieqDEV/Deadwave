#pragma once
#include "../../engine/engine.hpp"
#include "../entities.hpp"
#include <SDL_render.h>
class Spawner : public Entity {
  public:
    Spawner(Scene *scene, Player *p) : scene(scene), player(p) {}

    void start() override;
    void update(float deltaTime) override;
    void render(SDL_Renderer *render) override {}

  private:
    float timer = 0.0f;
    const float interval = 0.25f;
    Scene *scene;
    Player *player;
};
