#pragma once
#include "../entities.hpp"
#include <SDL_render.h>
#include "../../engine/engine.hpp"
class Spawner : public Entity{
  public:
    Spawner(Engine* eng, Player* p){
        engine = eng;
        player = p;
    }
    void start() override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* render) override{};//{} spawner will be never visible
  private:
    float timer = 0.0f;
    const float interval = 0.25f;
    Engine* engine;
    Player* player;
};
