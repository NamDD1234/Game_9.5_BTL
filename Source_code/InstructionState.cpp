#include "InstructionState.h"

using namespace std;

string InstructionState::s_InstructionStateID = "INSTRUCTION";

void InstructionState::update()
{
    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::get_Instance()->getStateMachine()->changeState(new MenuState());
        return;
    }
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();
}

void InstructionState::render()
{
    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) return;
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->draw(1, 1);
    TextureManager::get_Instance()->draw("info", 220, 0, 800, 600,
                                         Game::get_Instance()->getRenderer(), 1, 1);
}

bool InstructionState::onEnter()
{
    TextureManager::get_Instance()->load("Assets/instruction_info.png", "info", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->load("Assets/menu_background.png", "iBackground", Game::get_Instance()->getRenderer());
    m_gameObjects.push_back(new BG(new LoaderParams(0, 0,
                                   2560, 600,"iBackground")));
    return true;
}

bool InstructionState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->clean();
    m_gameObjects.clear();
    TextureManager::get_Instance()->clearFromTextureMap("info");
    TextureManager::get_Instance()->clearFromTextureMap("iBackground");
    return true;
}

