#include "HistoryState.h"

using namespace std;

string HistoryState::s_HistoryID = "HISTORY";

vector<GameObject*> HistoryState::m_gameObjects;

void HistoryState::update()
{
    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        SDL_ShowCursor(1);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        Game::get_Instance()->getStateMachine()->changeState(new MenuState());
        return;
    }
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();
}

void HistoryState::render()
{
    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))return;
    m_gameObjects[0]->draw(1, 1);
    ifstream file("Assets/History.txt");
    if(!file.is_open())return;
    int hBall = 0, hBot = 0;
    double hAver = 0;
    file>>hBall;
    file>>hBot;
    file>>hAver;
    TextureManager::get_Instance()->draw("hFrame", 375, 75, 500, 500,
                                         Game::get_Instance()->getRenderer(), 1, 1);
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->draw(1, 1);

    string Text2 = "MAXBALLS:                                    " +
                   to_string(hBall);
    TextManager::Get_Instance()->print_Text(Text2, "hCALIBRI",
    {255, 0, 170, 255}, 430, 250, Game::get_Instance()->getRenderer());

    string Text1 = "MAXBOTS:                                     " +
                   to_string(hBot);
    TextManager::Get_Instance()->print_Text(Text1, "hCALIBRI",
    {255, 0, 170, 255}, 430, 300, Game::get_Instance()->getRenderer());

    string Text3 = "%AVERAGEHEADSHOT:                 " +
                   to_string((int)hAver) + '%';
    TextManager::Get_Instance()->print_Text(Text3, "hCALIBRI",
    {255, 0, 170, 255}, 430, 350, Game::get_Instance()->getRenderer());
}

bool HistoryState::onEnter()
{
    TextManager::Get_Instance()->
    add_Font("Assets/CALIBRI.ttf", "hCALIBRI", 25);
    TextureManager::get_Instance()->
    load("Assets/History_frame.png", "hFrame", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/resetall_button.png", "hcleanButton", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/menu_background.png", "hGround", Game::get_Instance()->getRenderer());
    m_gameObjects.push_back(new BG(new LoaderParams(0, 0,
                                   2560, 600,"hGround")));
    m_gameObjects.push_back(new MenuButton(new LoaderParams(535, 445,
                                           200, 70, "hcleanButton"), s_clearHistory));
    return true;
}

bool HistoryState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->clean();
    m_gameObjects.clear();
    TextManager::Get_Instance()->clearFrom_mFont("hCALIBRI");
    TextureManager::get_Instance()->clearFromTextureMap("hFrame");
    TextureManager::get_Instance()->clearFromTextureMap("hcleanButton");
    TextureManager::get_Instance()->clearFromTextureMap("hGround");
    return true;
}

void HistoryState::s_clearHistory()
{
    Game::get_Instance()->upd_timeplay(0);
    ofstream file("Assets/History.txt", ios::trunc);
    file<<0<<"\n"<<0<<"\n"<<0;
    file.close();
}
