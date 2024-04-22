#include "BallState.h"

using namespace std;

string BallState::s_ballID = "BALLSTATE";

vector < pair<GameObject*,double> > BallState::m_gameObjects;
vector<GameObject*> BallState::vtball;

void BallState::update()
{
    if(T == 0 || InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        SDL_ShowCursor(1);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        Game::get_Instance()->getStateMachine()->pushState(new EndState(sl_ball, -1, -1, T_max, T > 0));
        return;
    }

    SDL_ShowCursor(0);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    static_cast<BallBG*>(m_gameObjects[0].first)->setBall(vtball);

    m_gameObjects[0].first->update();

    m_gameObjects[1].first->update();

    vtball = static_cast<BallBG*>(m_gameObjects[0].first)->getBall();
    for(GameObject* bal:vtball)
        bal->update();

    sl_ball = static_cast<BallBG*>(m_gameObjects[0].first)->get_slball();
    time = (time + 1) % 60;
    if(time == 0) T--;
}

void BallState::render()
{
    if(T == 0 || InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) return;
    m_gameObjects[0].first->draw(m_gameObjects[0].second, 1);
    for(GameObject* bal:vtball)
        bal->draw(static_cast<Ball*>(bal)->get_zoom_bal(), 1);
    m_gameObjects[1].first->draw(m_gameObjects[1].second, 1);
     string TIME = to_string(T)+' '+'s';
     if(T < 10) TIME = '0' + TIME;

    TextManager::Get_Instance()->print_Text(TIME, "font2", {255, 0, 0, 255}, 630, 0, Game::get_Instance()->getRenderer());
}

bool BallState::onEnter()
{
    TextureManager::get_Instance()->
    load("Assets/r1.png","back1",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/crosshair.png","crs",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Ball.png","ball",Game::get_Instance()->getRenderer());
    TextManager::Get_Instance()->
    add_Font("Assets/BRADLEY.ttf", "font2", 75);
    SoundManager::Get_Instance()->load("Assets/Ball_break_sound.mp3","killball");
    m_gameObjects.push_back({new BallBG(new LoaderParams(-320, -180,
                                           2560, 1440,"back1")),1});
    m_gameObjects.push_back({new Crosshair(new LoaderParams (620,280,40,40,"crs")),1});

    vec = static_cast <BallBG*> (m_gameObjects[0].first)->get_position();
    for(int i = 0; i < 3; i++)
        vtball.push_back( new Ball ( new LoaderParams(vec.getX()+640+rand()%(1280 - 50),
                                         vec.getY()+300+rand()%(600 - 50),
                                         100,100,"ball")) );
    return true;
}

bool BallState::onExit()
{
    while(m_gameObjects.size())
    {
        m_gameObjects.back().first->clean();
        m_gameObjects.pop_back();
    }

    while(vtball.size())
    {
        vtball.back()->clean();
        vtball.pop_back();
    }

    TextureManager::get_Instance()->clearFromTextureMap("back1");
    TextureManager::get_Instance()->clearFromTextureMap("crs");
    TextureManager::get_Instance()->clearFromTextureMap("ball");
    TextManager::Get_Instance()->clearFrom_mFont("font2");
    SoundManager::Get_Instance()->delSound("killball");
    return true;
}
