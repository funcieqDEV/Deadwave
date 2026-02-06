#pragma once
#include "../entity/entity.hpp"
#include <SDL_stdinc.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


class Text : public Entity{
  public:
    Text(int x, int y, std::string text){
        this->x = ;
        this->y = y;
        this->text = text;
    }
    void start() override;
  private:
    int x;
    int y;
    std::string text;
};
