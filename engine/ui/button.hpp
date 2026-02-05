
#pragma once
#include "../entity/entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_stdinc.h>
#include <cstdint>
#include <functional>
#include <string>

class Button : public Entity {
  public:
    Button(int x, int y, int w, int h, const std::string &text,
           std::function<void()> onClick, TTF_Font *font,
           SDL_Renderer *renderer)
        : rect{x, y, w, h}, text(text), onClick(onClick), font(font) {
        createTexture(renderer);
    }

    ~Button() {
        if (texture)
            SDL_DestroyTexture(texture);
    }

    void start() override {}

    void update(float delta) override {
        int mx, my;
        Uint32 buttons = SDL_GetMouseState(&mx, &my);
        isHover = (mx >= rect.x && mx <= rect.x + rect.w && my >= rect.y &&
                   my <= rect.y + rect.h);

        bool leftPressed = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);

        if (isHover && leftPressed && !wasPressed) {
            if (onClick)
                onClick();
        }
        wasPressed = leftPressed;
    }

    void setColor(Uint8 r, Uint8 g, Uint8 b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alp) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->alpha = alp;
    }

    void onHover(std::function<void()> fn) { _onHover = fn; }

    void render(SDL_Renderer *renderer) override {
        if (!isHover) {
            SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
        } else {
            SDL_SetRenderDrawColor(renderer, hvR, hvG, hvB, hvAlpha);
        }

        SDL_RenderFillRect(renderer, &rect);

        if (texture) {
            SDL_Rect dst;
            dst.w = textW;
            dst.h = textH;
            dst.x = rect.x + (rect.w - dst.w) / 2;
            dst.y = rect.y + (rect.h - dst.h) / 2;
            SDL_RenderCopy(renderer, texture, NULL, &dst);
        }
    }

  private:
    SDL_Rect rect;
    std::string text;
    std::function<void()> onClick;
    std::function<void()> _onHover;
    bool wasPressed = false;
    TTF_Font *font = nullptr;
    SDL_Texture *texture = nullptr;
    int textW = 0;
    int textH = 0;
    Uint8 r = 200;
    Uint8 g = 200;
    Uint8 b = 200;
    Uint8 alpha = 200;
    Uint8 hvR = 20;
    Uint8 hvG = 100;
    Uint8 hvB = 250;
    Uint8 hvAlpha = 200;
    bool isHover;
    void createTexture(SDL_Renderer *renderer) {
        if (!font || !renderer)
            return;

        SDL_Color color = {0, 0, 0, 255};
        SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
        if (!surf) {
            SDL_Log("TTF_RenderText_Blended failed: %s", TTF_GetError());
            return;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surf);
        if (!texture) {
            SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        }

        textW = surf->w;
        textH = surf->h;
        SDL_FreeSurface(surf);
    }
};
