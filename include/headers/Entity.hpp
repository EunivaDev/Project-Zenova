#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();

};