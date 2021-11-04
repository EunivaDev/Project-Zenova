#pragma once

#include <SDL.h>

namespace utils
{
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001;

        return t;
    }
}