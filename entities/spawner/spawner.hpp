#pragma once
#include "../../engine/engine.hpp"
#include "../entities.hpp"
#include <SDL_render.h>
#include <random>
#include <ctime>

class Spawner : public Entity {
  public:
    Spawner(Scene *scene, Player *p) : scene(scene), player(p) {}

    void start() override;
    void update(float deltaTime) override;
    void render(SDL_Renderer *render) override {}
    void loadTexture(SDL_Renderer* render, const char* path) override;

  private:
    float timer = 0.0f;
    const float interval = 0.5f;  // Spawn every 0.5 seconds
    const float spawnRadius = 300.0f;  // Distance from player
    Scene *scene;
    Player *player;
    std::mt19937 gen;  // Mersenne Twister generator
};
