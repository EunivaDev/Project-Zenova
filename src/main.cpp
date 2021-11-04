// Description: Project Zenova
// Date Started: 11/3/2021
// Developers: Kevin Tran

// mingw32-make -f Makefile

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

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
        window.render(grassTexture);
        window.display();
    }






    window.cleanUp();
    SDL_Quit();

    return 0;
}