#include "MenuState.h"

using namespace std;

string MenuState::s_menuID = "MENU";
vector<GameObject*> MenuState::m_gameObjects;
void MenuState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();
}

void MenuState::render()
{
    m_gameObjects[0]->draw(1, 1);
    TextureManager::get_Instance()->draw("picf", 270, -50, 720, 720,
                                         Game::get_Instance()->getRenderer(), 1, 1);
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->draw(1, 1);
}

bool MenuState::onEnter()
{
    TextureManager::get_Instance()->
    load("Assets/ball_button.png","ballbutton", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Exit_Button.png", "Exit", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Bot_button.png","playbutton", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/menu_background.png","menuuuu", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Menu_pictureframe.png","picf", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/history_button.png", "his", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/instruction_button.png", "ins", Game::get_Instance()->getRenderer());
    m_gameObjects.push_back(new BG(new LoaderParams(0, 0,
                                   2560, 600,"menuuuu")));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(540, 160,
                                           200, 80, "ballbutton"), s_option));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(550, 360,
                                           175, 70, "Exit"), s_exitFromMenu));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(550, 260,
                                           175, 70, "playbutton"), s_menuToPlay));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(375, 160,
                                           210, 270, "his"),s_history));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(685, 160,
                                           210, 270, "ins"),s_instruction));
    return true;
}

bool MenuState::onExit()
{
    while(m_gameObjects.size())
    {
        m_gameObjects.back()->clean();
        m_gameObjects.pop_back();
    }
    TextureManager::get_Instance()->clearFromTextureMap("playbutton");
    TextureManager::get_Instance()->clearFromTextureMap("Exit");
    TextureManager::get_Instance()->clearFromTextureMap("ballbutton");
    TextureManager::get_Instance()->clearFromTextureMap("menuuuu");
    TextureManager::get_Instance()->clearFromTextureMap("picf");
    TextureManager::get_Instance()->clearFromTextureMap("his");
    TextureManager::get_Instance()->clearFromTextureMap("ins");
    return true;
}

void MenuState::s_menuToPlay()
{
    Game::get_Instance()->
    getStateMachine()->
    changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    Game::get_Instance()->quit();
}

void MenuState::s_option()
{
    Game::get_Instance()->
    getStateMachine()->
    changeState(new BallState());
}

void MenuState::s_history()
{
    Game::get_Instance()->
    getStateMachine()->
    changeState(new HistoryState());
}

void MenuState::s_instruction()
{
    Game::get_Instance()->
    getStateMachine()->
    changeState(new InstructionState());
}
