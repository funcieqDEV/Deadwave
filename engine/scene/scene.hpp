#pragma once
#include "../entity/entity.hpp"
#include <SDL_render.h>
#include <vector>
#include <iostream>

class Scene {
  public:
    virtual ~Scene() {
        for (auto e : entities)
            delete e;
        entities.clear();
    }

    virtual void start() {}
    virtual void update(float deltaTime) {
        for (auto e : entities)
            e->update(deltaTime);
        // Load textures for newly added entities
        for (auto e : toAdd) {
            if (currentRenderer) {
                e->loadTexture(currentRenderer, "texture/enemy/zombie.png");
            }
            e->start();
        }
        entities.insert(entities.end(), toAdd.begin(), toAdd.end());
        toAdd.clear();
    }

    virtual void render(SDL_Renderer *renderer) {
        currentRenderer = renderer; //todo add maybe some global pointer or something
        for (auto e : entities)
            e->render(renderer);
    }

    void addEntity(Entity *e) { toAdd.push_back(e); }
    void addPrior(Entity *e) { entities.push_back(e); }
    void setRenderer(SDL_Renderer *r) { currentRenderer = r; }

  protected:
    std::vector<Entity *> entities;
    std::vector<Entity *> toAdd;
    SDL_Renderer *currentRenderer = nullptr;
};
