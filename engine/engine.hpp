#pragma once

#include "scene/scene_manager.hpp"
#include <SDL2/SDL.h>

class Engine {
  public:
    Engine() = default;
    ~Engine();

    int init(const char *title, int width, int height);

    void update();
    void render();
    void stop() { _isRunning = false; }
    bool isRunning() const;
    void pushScene(Scene *scene) {
        sceneStack.push_back(scene);
        scene->start();
    }

    void popScene() {
        if (!sceneStack.empty()) {
            delete sceneStack.back();
            sceneStack.pop_back();
        }
    }

    Scene *currentScene() {
        return sceneStack.empty() ? nullptr : sceneStack.back();
    }

    inline SDL_Renderer *getRenderer() const { return _render; }
    inline float getDeltaTime() const { return _delta; }

    SceneManager sceneManager;

  private:
    SDL_Window *window = nullptr;
    SDL_Renderer *_render = nullptr;

    bool _isRunning = false;

    float _delta = 0.0f;
    Uint32 lastTime = 0;
    std::vector<Scene *> sceneStack;
};
