#pragma once
#include "scene.hpp"
#include <SDL_render.h>

class SceneManager {
  public:
    ~SceneManager();
    void update(float deltaTime);
    void render(SDL_Renderer *render);

  private:
    Scene *currentScene = nullptr;
};
