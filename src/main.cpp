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

using namespace std;

int main(int argv, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "SDL_Init has failed. Error: " << SDL_GetError() << endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        cout << "IMG_Init has failed. Error: " << SDL_GetError() << endl;

    // opens the game window
    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/img/grass_1.png");

    vector<Entity> platform;

    for (int i = 0; i < 6; i++)
    {
        platform.push_back(Entity(i * 64, 0, grassTexture));
    }

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning == true)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();

        for (int i = 0; i < platform.size(); i++)
        {
            window.render(platform[i]);
        }

        window.display();
    }






    window.cleanUp();
    SDL_Quit();

    return 0;
}