#include "scene_manager.hpp"
#include "scene.hpp"
#include <SDL_render.h>

SceneManager::~SceneManager() { delete currentScene; }

void SceneManager::setScene(Scene *scene) {
    if (currentScene)
        delete currentScene;
    currentScene = scene;
    currentScene->start();
}

void SceneManager::update(float deltaTime) {
    if (currentScene)
        currentScene->update(deltaTime);
}

void SceneManager::render(SDL_Renderer *render) {
    if (currentScene)
        currentScene->render(render);
}
