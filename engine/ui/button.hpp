

#pragma once
#include "../entity/entity.hpp"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <functional>

class Button : public Entity {
public:
    Button(int x, int y, int w, int h, const std::string& text,
           std::function<void()> onClick, TTF_Font* font, SDL_Renderer* renderer)
        : rect{x, y, w, h}, text(text), onClick(onClick), font(font) 
    {
        createTexture(renderer);
        normalColor = {200, 200, 200, 255};
        hoverColor  = {20, 100, 250, 255};
        currentColor = normalColor;
    }

    ~Button() {
        if(texture) SDL_DestroyTexture(texture);
    }

    void start() override {}

    void update(float delta) override {
        int mx, my;
        Uint32 buttons = SDL_GetMouseState(&mx, &my);
        bool hoverNow = (mx >= rect.x && mx <= rect.x + rect.w &&
                         my >= rect.y && my <= rect.y + rect.h);


        if(hoverNow && !isHover && _onHover) _onHover();
        if(!hoverNow && isHover && _onLeave) _onLeave();

        isHover = hoverNow;
        currentColor = isHover ? hoverColor : normalColor;

        bool leftPressed = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
        if(isHover && leftPressed && !wasPressed && onClick) onClick();
        wasPressed = leftPressed;
    }


    void render(SDL_Renderer* renderer) override {
        SDL_SetRenderDrawColor(renderer,
                               currentColor.r,
                               currentColor.g,
                               currentColor.b,
                               currentColor.a);
        SDL_RenderFillRect(renderer, &rect);

        if(texture) {
            SDL_Rect dst{
                rect.x + (rect.w - textW)/2,
                rect.y + (rect.h - textH)/2,
                textW,
                textH
            };
            SDL_RenderCopy(renderer, texture, nullptr, &dst);
        }
    }

    // api
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a=255) { currentColor = {r,g,b,a}; }
    void onHover(std::function<void()> fn) { _onHover = fn; }
    void onLeave(std::function<void()> fn) { _onLeave = fn; }

private:
    SDL_Rect rect;
    std::string text;
    std::function<void()> onClick = [](){};
    std::function<void()> _onHover = [](){};
    std::function<void()> _onLeave = [](){};
    bool wasPressed = false;
    bool isHover = false;

    TTF_Font* font = nullptr;
    SDL_Texture* texture = nullptr;
    int textW = 0;
    int textH = 0;

    struct Color { Uint8 r,g,b,a; };
    Color normalColor, hoverColor, currentColor;

    void createTexture(SDL_Renderer* renderer) {
        if(!font || !renderer) return;

        SDL_Color color = {0,0,0,255};
        SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color);
        if(!surf) {
            SDL_Log("TTF_RenderText_Blended failed: %s", TTF_GetError());
            return;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surf);
        if(!texture) {
            SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        }

        textW = surf->w;
        textH = surf->h;
        SDL_FreeSurface(surf);
    }
};


