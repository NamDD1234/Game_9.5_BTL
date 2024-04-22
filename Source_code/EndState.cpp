#include "EndState.h"

using namespace std;

string EndState::s_endID = "ENDD";

vector < GameObject* > EndState::m_gameObjects;
int EndState::e_type = 0;
EndState::~EndState()
{

}
void EndState::update()
{
    m_gameObjects[0]->update();
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();
}
void EndState::render()
{
    m_gameObjects[0]->draw(1, 1);
    TextureManager::get_Instance()->draw("resultframe", 300, -75, 720, 720,
                                         Game::get_Instance()->getRenderer(),
                                         1, 1);
    if(!check_T)
    {
        TextureManager::get_Instance()->draw("result", 515, 50, 300, 53,
                                             Game::get_Instance()->getRenderer(),
                                             1, 1);
        string Text1 = "TIMES:                          " +
                       to_string(e_T_max);
        TextManager::Get_Instance()->print_Text(Text1, "calibri",
        {0, 255, 195, 255}, 432, 150, Game::get_Instance()->getRenderer());
        if(e_sl_ball >= 0)
        {
            string Text2 = "BALLS:                          " +
                           to_string(e_sl_ball);
            TextManager::Get_Instance()->print_Text(Text2, "calibri",
            {0, 255, 195, 255}, 432, 250, Game::get_Instance()->getRenderer());
        }
        else
        {
            string Text2 = "KILLS:                            " +
                           to_string(e_sl_bot);
            TextManager::Get_Instance()->print_Text(Text2, "calibri",
            {0, 255, 195, 255}, 432, 250, Game::get_Instance()->getRenderer());
            int percentage = (e_sl_bot != 0)?(int)(1.0*e_headshot_kills/e_sl_bot*100): 0;
            string Text3 = "%HEADSHOT:             " +
                           to_string(percentage) + '%';
            TextManager::Get_Instance()->print_Text(Text3, "calibri",
            {0, 255, 195, 255}, 432, 350, Game::get_Instance()->getRenderer());
        }
    }
    for(int i = 1; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->draw(1, 1);

}

bool EndState::onEnter()
{
    e_type = (e_sl_ball >= 0);
    TextureManager::get_Instance()->
    load("Assets/Resume_Button.png", "Resume", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/ExitMenu_Button.png", "ExitMenu", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Newgame_Button.png", "Newgame", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/result_pictureframe.png", "resultframe", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/result.png", "result", Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/menu_background.png","emenu", Game::get_Instance()->getRenderer());
    TextManager::Get_Instance()->
    add_Font("Assets/CALIBRI.ttf", "calibri", 45);
    m_gameObjects.push_back(new BG(new LoaderParams(0, 0,
                                   2560, 600,"emenu")));
    if(check_T)
    {
        m_gameObjects.push_back(new MenuButton(new LoaderParams(575, 150, 175, 70, "Resume"),s_Resume));
        m_gameObjects.push_back(new MenuButton(new LoaderParams(575, 230, 175, 70, "ExitMenu"),s_Backtomenu));
        m_gameObjects.push_back(new MenuButton(new LoaderParams(575, 310, 175, 70, "Newgame"),s_Newgame));
    }
    else
    {
        m_gameObjects.push_back(new MenuButton(new LoaderParams(475, 385, 175, 70, "Newgame"),s_Newgame));
        m_gameObjects.push_back(new MenuButton(new LoaderParams(675, 385, 175, 70, "ExitMenu"),s_Backtomenu));
    }
    return true;
}

bool EndState::onExit()
{
    if(!check_T)
    {
        ifstream file("Assets/History.txt");
        if(!file.is_open())return 1;
        int max_ball = 0;
        int max_bot = 0;
        double average = 0;
        file>>max_ball;
        file>>max_bot;
        file>>average;
        int t_play = Game::get_Instance()->get_timeplay();
        max_ball = max(max_ball, e_sl_ball);
        max_bot = max(max_bot, e_sl_bot);
        if(e_sl_bot > 0)
            average = (average * t_play / 100 + ((e_sl_bot != 0)?(1.0*e_headshot_kills/e_sl_bot): 0))/(t_play + 1) * 100;
        ofstream file1("Assets/History.txt", ios::trunc);
        file1<<max_ball<<"\n"<<max_bot<<"\n"<<average;
        file1.close();
        Game::get_Instance()->upd_timeplay(Game::get_Instance()->get_timeplay() + 1);
    }
    while(m_gameObjects.size())
    {
        m_gameObjects.back()->clean();
        m_gameObjects.pop_back();
    }

    TextureManager::get_Instance()->clearFromTextureMap("Resume");
    TextureManager::get_Instance()->clearFromTextureMap("ExitMenu");
    TextureManager::get_Instance()->clearFromTextureMap("Newgame");
    TextureManager::get_Instance()->clearFromTextureMap("resultframe");
    TextureManager::get_Instance()->clearFromTextureMap("result");
    TextureManager::get_Instance()->clearFromTextureMap("emenu");
    TextManager::Get_Instance()->clearFrom_mFont("calibri");

    return true;
}
void EndState::s_Resume()
{
    Game::get_Instance()->getStateMachine()->popState();
}

void EndState::s_Newgame()
{
    Game::get_Instance()->getStateMachine()->clear_all();
    if(e_type)Game::get_Instance()->getStateMachine()->changeState(new BallState());
    else Game::get_Instance()->getStateMachine()->changeState(new PlayState());
}

void EndState::s_Backtomenu()
{
    Game::get_Instance()->getStateMachine()->clear_all();
    Game::get_Instance()->getStateMachine()->changeState(new MenuState());
}
