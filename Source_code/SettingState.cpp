#include "SettingState.h"

using namespace std;

string SettingState::s_SettingID = "SETTING";
vector <GameObject*> SettingState::m_gameObjects;

void SettingState::update()
{
    m_gameObjects[0]->update();
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();
}

void SettingState::render()
{
    m_gameObjects[0]->draw(1, 1);
    TextureManager::get_Instance()->draw("settingFrame", 300, 0,
                                         600, 600, Game::get_Instance()->getRenderer(), 1, 1);
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->draw(1, 1);
    TextManager::Get_Instance()->print_Text("TYPE GUN", "sCALIBRI",
    {255, 225, 0, 255}, 360, 215, Game::get_Instance()->getRenderer());
    TextManager::Get_Instance()->print_Text("LEVEL", "sCALIBRI",
    {255, 225, 0, 255}, 360, 400, Game::get_Instance()->getRenderer());
}

bool SettingState::onEnter()
{
    TextureManager::get_Instance()->
    load("Assets/reload_button.png", "reload", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/unreload_button.png", "unreload", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/hard.png", "hard", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/easy.png", "easy", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/setting.png", "settingFrame", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/menu_background.png","smenu", Game::get_Instance()->getRenderer());
    TextManager::Get_Instance()->
    add_Font("Assets/CALIBRI.ttf", "sCALIBRI", 25);

    m_gameObjects.push_back(new BG(new LoaderParams(0, 0,
                                   2560, 600,"smenu")));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(560, 75,
                                           210, 125, "reload"), reloading));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(560, 200,
                                           210, 125, "unreload"), unreloading));

    m_gameObjects.push_back(new MenuButton(new LoaderParams(560, 300,
                                           210, 125, "hard"), harder));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(560, 425,
                                           210, 125, "easy"), easier));
    return true;
}

bool SettingState::onExit()
{
    for(GameObject *X : m_gameObjects)
        X->clean();
    m_gameObjects.clear();
    TextureManager::get_Instance()->clearFromTextureMap("reload");
    TextureManager::get_Instance()->clearFromTextureMap("unreload");
    TextureManager::get_Instance()->clearFromTextureMap("hard");
    TextureManager::get_Instance()->clearFromTextureMap("easy");
    TextureManager::get_Instance()->clearFromTextureMap("settingFrame");
    TextureManager::get_Instance()->clearFromTextureMap("smenu");
    TextManager::Get_Instance()->clearFrom_mFont("sCALIBRI");
    return true;
}

void SettingState::reloading()
{
    Game::get_Instance()->upd_reloadornot(0);
    Game::get_Instance()->getStateMachine()->clear_all();
    Game::get_Instance()->getStateMachine()->changeState(new PlayState());
}

void SettingState::unreloading()
{
    Game::get_Instance()->upd_reloadornot(1);
    Game::get_Instance()->getStateMachine()->clear_all();
    Game::get_Instance()->getStateMachine()->changeState(new PlayState());
}

void SettingState::easier()
{
    Game::get_Instance()->upd_easyorhard(0);
    Game::get_Instance()->getStateMachine()->clear_all();
    Game::get_Instance()->getStateMachine()->changeState(new PlayState());
}

void SettingState::harder()
{
    Game::get_Instance()->upd_easyorhard(1);
    Game::get_Instance()->getStateMachine()->clear_all();
    Game::get_Instance()->getStateMachine()->changeState(new PlayState());
}

