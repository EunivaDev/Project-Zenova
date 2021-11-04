// Description: Project Zenova
// Date Started: 11/3/2021
// Developers: Kevin Tran

// mingw32-make -f Makefile

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argv, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "SDL_Init has failed. Error: " << SDL_GetError() << endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        cout << "IMG_Init has failed. Error: " << SDL_GetError() << endl;

    // opens the game window
    RenderWindow window("GAME v1.0", 1280, 720);
    int windowRefreshRate = window.getRefreshRate();

    cout << windowRefreshRate << endl;

    SDL_Texture* grassTexture = window.loadTexture("res/img/grass_1.png");

    vector<Entity> platform;

    for (int i = 0; i < 6; i++)
        platform.push_back(Entity(Vector2f(i * 32, 0), grassTexture));

    bool gameRunning = true;

    SDL_Event event;

    const float timeStep = 0.01;
    float accumulator = 0.0;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning == true)
    {
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
                if (event.type == SDL_QUIT)
                    gameRunning = false;

            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;

        window.clear();

        for (Entity& p : platform)
            window.render(p);

        window.display();

        int frameTicks = SDL_GetTicks() - startTicks;

        if (frameTicks < 1000 / window.getRefreshRate())
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
    }






    window.cleanUp();
    SDL_Quit();

    return 0;
}