#include "game.h"

using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;


int main(int argc, char* argv[])
{
    srand(time(NULL));
    Uint32 frameStart, frameTime;
    Game::get_Instance()->init("Chapter 1",
                               100, 100,
                               1280, 600,
                               SDL_WINDOW_SHOWN);
    while(Game::get_Instance()->running())
    {
        frameStart = SDL_GetTicks();
        Game::get_Instance()->handleEvents();
        Game::get_Instance()->update();
        Game::get_Instance()->render();
        frameTime = SDL_GetTicks() - frameStart;

        if(frameTime < DELAY_TIME)
            SDL_Delay((int)(DELAY_TIME - frameTime));
    }
    Game::get_Instance()->clean();
    return 0;
}
