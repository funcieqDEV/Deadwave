
#pragma once

#include "../engine/engine.hpp"
#include "../engine/scene/scene.hpp"
#include "../engine/ui/button.hpp"
#include "game_scene.hpp"
#include <SDL_ttf.h>
#include <cstdio>

class MenuScene : public Scene {
public:
    explicit MenuScene(Engine *eng) : engine(eng) {}

    TTF_Font* arial = TTF_OpenFont("fonts/Arial.ttf", 24);

    void start() override {
        int screenW = 800;
        int screenH = 600;
        int btnW = 200;
        int btnH = 50;
        int spacing = 20;

        int centerX = (screenW - btnW) / 2;
        int startY = (screenH - (btnH * 2 + spacing)) / 2;


        Button* playBtn = new Button(
            centerX, startY, btnW, btnH, "Play",
            [en = engine]() { 
                en->pushScene(new GameScene(en)); 
            },
            arial,
            engine->getRenderer()
        );

        playBtn->onHover([playBtn]() { 
            playBtn->setColor(20, 100, 250); 
        });
        playBtn->onLeave([playBtn]() { 
            playBtn->setColor(200, 200, 200); 
        });

        addPrior(playBtn);


        Button* exitBtn = new Button(
            centerX, startY + btnH + spacing, btnW, btnH, "Exit",
            [engine = engine]() { engine->stop(); },
            arial,
            engine->getRenderer()
        );

        exitBtn->onHover([exitBtn]() { exitBtn->setColor(200, 50, 50); });
        exitBtn->onLeave([exitBtn]() { exitBtn->setColor(200, 200, 200); });

        addPrior(exitBtn);
    }

    void update(float deltaTime) override { Scene::update(deltaTime); }
    void render(SDL_Renderer* renderer) override { Scene::render(renderer); }

private:
    Engine* engine;
};

