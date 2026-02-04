#include "scene_manager.hpp"
#include "scene.hpp"
#include <SDL_render.h>

SceneManager::~SceneManager() { delete currentScene; }

void SceneManager::update(float deltaTime) {
    if (currentScene)
        currentScene->update(deltaTime);
}

void SceneManager::render(SDL_Renderer *render) {
    if (currentScene)
        currentScene->render(render);
}
