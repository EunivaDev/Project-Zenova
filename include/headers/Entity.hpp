#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity
{
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Vector2f& getPos();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    ////////////
    void setPos(Vector2f p_pos);
    ////////////
};