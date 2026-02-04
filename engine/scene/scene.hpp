#pragma once
#include "../entity/entity.hpp"
#include <SDL_render.h>
#include <vector>

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
        entities.insert(entities.end(), toAdd.begin(), toAdd.end());
        toAdd.clear();
    }

    virtual void render(SDL_Renderer *renderer) {
        for (auto e : entities)
            e->render(renderer);
    }

    void addEntity(Entity *e) { toAdd.push_back(e); }
    void addPrior(Entity *e) { entities.push_back(e); }

  protected:
    std::vector<Entity *> entities;
    std::vector<Entity *> toAdd;
};
