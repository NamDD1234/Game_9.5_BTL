#include "game.h"

using namespace std;

Game* Game::G_Instance = NULL;

Game::Game()
{
    m_pWindow = NULL;
    m_pRenderer = NULL;
    m_bRunning = true;
}
Game::~Game()
{

}
Game* Game::get_Instance()
{
    if(G_Instance == NULL)
    {
        G_Instance = new Game();
        return G_Instance;
    }
    return G_Instance;
}

bool Game::init(const char* title, int xpos, int ypos, int
                height, int width, int flags)
{
    if(TTF_Init() == -1)
    {
        cout<<"FailFont"<<" "<<TTF_GetError();
        return false;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {

        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     height, width, flags);

        if(m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                m_pGameStateMachine = new GameStateMachine();
                m_pGameStateMachine->pushState(new MenuState());
            }
            else
            {
                cout<<"fail";
                return false;
            }
        }
        else
        {
            cout<<"fail";
            return false;
        }
    }
    else
    {
        cout<<"fail";
        return false;
    }
    m_bRunning = true;
    return true;
}
void Game::update()
{
    m_pGameStateMachine->update();
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    m_pGameStateMachine ->render();
    SDL_RenderPresent(m_pRenderer);
}


void Game::clean()
{
    m_bRunning = false;
    InputHandle::Get_Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    quit();
}

void Game::quit()
{
    m_bRunning = false;
    SDL_Quit();
    TTF_Quit();
}
void Game::handleEvents()
{
    InputHandle ::Get_Instance() ->update();
}


