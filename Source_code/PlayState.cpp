#include "PlayState.h"

using namespace std;

static Specification* Phantom = new Specification(30, 60, 2.5, 11,
        iii(156, ii(39, 33)),
        iii(140, ii(35, 30)),
        iii(124, ii(31, 26)), 1);

static Specification* Vandal  = new Specification(25, 70, 2.5, 9.75,
        iii(160, ii(40, 34)),
        iii(160, ii(40, 34)),
        iii(160, ii(40, 34)), 1);

static Specification* Sheriff = new Specification(6, 20, 2.25, 4,
        iii(159, ii(55, 47)),
        iii(159, ii(55, 47)),
        iii(145, ii(50, 42)), 0);

const double zoom[] = {1, 1.5, 2.5};

Specification* PlayState::pinfo_gun;

vector < pair<GameObject*,double> > PlayState::m_gameObjects;
vector < Bot* >PlayState:: pBot;

string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    if(T == 0 || InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        SDL_ShowCursor(1);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        Game::get_Instance()->getStateMachine()->pushState(new EndState(-1,
                static_cast<Play_background*>(m_gameObjects[0].first)->get_slkill(),
                static_cast<Play_background*>(m_gameObjects[0].first)->get_slheadshot(),
                T_max, T > 0));
        return;
    }
    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_TAB))
    {
        SDL_ShowCursor(1);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        Game::get_Instance()->getStateMachine()->pushState(new SettingState());
        return;
    }
    if(InputHandle::Get_Instance()->get_B())
    {
        SDL_ShowCursor(1);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        m_gameObjects.push_back({new MenuButton(new LoaderParams(315, 100, 250, 120,"Phantom"),s_Phantom),1});
        m_gameObjects.push_back({new MenuButton(new LoaderParams(315, 230, 250, 120,"Vandal"),s_Vandal),1});
        m_gameObjects.push_back({new MenuButton(new LoaderParams(315, 360, 250, 120,"Sheriff"),s_Sheriff),1});
    }
    else if( T != 0 )
    {
        SDL_ShowCursor(0);
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }
    Vector2D vec = static_cast <Play_background*>
                   (m_gameObjects[0].first)->get_position();
    //return;
    int max_bot = (Game::get_Instance()->get_easyorhard())?1:8;
    while(pBot.size() < max_bot)
    {
        int rand_X = 0;
        double rand_zoom = 1;
        while(1)
        {
            rand_zoom = zoom[rand() % 3];
            rand_X = rand()%(1280 - 115);
            if(rand_zoom == 1 &&
                    !static_cast <Play_background*>(m_gameObjects[0].first)
                    ->get_Bot1 (rand_X,
                                rand_X + 225/rand_zoom))
            {
                static_cast <Play_background*>(m_gameObjects[0].first)->upd_Bot1(rand_X, rand_X + 225/rand_zoom, 1);
                break;
            }
            else if(rand_zoom  >= 1.4 && rand_zoom  <= 1.6 &&
                    !static_cast <Play_background*>(m_gameObjects[0].first)
                    ->get_Bot2 (rand_X,
                                rand_X + 225/rand_zoom))
            {
                static_cast <Play_background*>(m_gameObjects[0].first)->upd_Bot2(rand_X, rand_X + 225/rand_zoom, 1);
                break;
            }
            else if(rand_zoom  >= 2.4 && rand_zoom  <=2.6 &&
                    !static_cast <Play_background*>(m_gameObjects[0].first)
                    ->get_Bot3 (rand_X,
                                rand_X + 225/rand_zoom))
            {
                static_cast <Play_background*>(m_gameObjects[0].first)->upd_Bot3(rand_X, rand_X + 225/rand_zoom, 1);
                break;
            }
            //if(t == 10) break;
        }

        if(rand_zoom == 1)
            pBot.push_back(new Bot(new LoaderParams(vec.getX()+ 640 + rand_X,
                                                vec.getY()+ 300 + 350,
                                                225, 300,"bott" )));
        else if(rand_zoom >= 1.4 && rand_zoom <= 1.6)
            pBot.push_back(new Bot(new LoaderParams(vec.getX()+ 640 + rand_X,
                                                vec.getY()+ 300 + 350,
                                                150, 200,"bott2" )));
        else
            pBot.push_back(new Bot(new LoaderParams(vec.getX()+ 640 + rand_X,
                                                vec.getY()+ 300 + 350,
                                                90, 120,"bott3" )));
        pBot.back()->upd_zoombot(rand_zoom);
    }
    static_cast<Play_background*>
    (m_gameObjects[0].first)->setBot(pBot);
    if(!InputHandle::Get_Instance()->get_B())
    {
        m_gameObjects[0].first->update();
        m_gameObjects[1].first->update();
        while(m_gameObjects.size()>2)
        {
            m_gameObjects.back().first->clean();
            m_gameObjects.pop_back();
        }
        time = (time + 1) % 60;
        if(time == 0) T--;
    }
    if(InputHandle::Get_Instance()->get_B())
    {
        m_gameObjects[2].first->update();
        m_gameObjects[3].first->update();
        m_gameObjects[4].first->update();
        if(pinfo_gun != static_cast <Play_background*>
                (m_gameObjects[0].first)->get_info() )
        {
            static_cast <Play_background*> (m_gameObjects[0].first)
            ->upd_info(pinfo_gun);
            static_cast <Play_background*> (m_gameObjects[0].first)
            ->reset();
        }
    }
    pBot = static_cast<Play_background*>
           (m_gameObjects[0].first)->getBot();
}

void PlayState::render()
{
    if(T == 0 ||
            InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)||
            InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_TAB))return;
    m_gameObjects[0].first->draw(m_gameObjects[0].second, 1);

    for(Bot* X:pBot)
    {
        X->draw(1, X->get_is_running());
    }
    m_gameObjects[1].first->draw(m_gameObjects[1].second, 1);

    if(InputHandle::Get_Instance()->get_B())
    {
        TextureManager::get_Instance()->draw("bback", 305, 90, 630, 400, Game::get_Instance()->getRenderer(), 1, 1);
        m_gameObjects[2].first->draw(m_gameObjects[1].second, 1);
        m_gameObjects[3].first->draw(m_gameObjects[1].second, 1);
        m_gameObjects[4].first->draw(m_gameObjects[1].second, 1);
        if(static_cast<MenuButton*> (m_gameObjects[2].first)->check_inbutton())
            TextureManager::get_Instance()->draw("PhantomSpec", 575, 150, 350, 270, Game::get_Instance()->getRenderer(), 1, 1);
        if(static_cast<MenuButton*> (m_gameObjects[3].first)->check_inbutton())
            TextureManager::get_Instance()->draw("VandalSpec", 575, 150, 350, 270, Game::get_Instance()->getRenderer(), 1, 1);
        if(static_cast<MenuButton*> (m_gameObjects[4].first)->check_inbutton())
            TextureManager::get_Instance()->draw("SheriffSpec", 575, 150, 350, 270, Game::get_Instance()->getRenderer(), 1, 1);
    }
    NUM = to_string(static_cast<Play_background*>(m_gameObjects[0].first)->get_num_ammo())
          +'/'+to_string( (int)pinfo_gun->get_maxammo());
    TIME = to_string(T)+' '+'s';
    if(T < 10) TIME = '0' + TIME;
    TextManager::Get_Instance()->print_Text(NUM, "font1", {0, 0, 0, 255}, 1100, 550, Game::get_Instance()->getRenderer());
    TextManager::Get_Instance()->print_Text(TIME, "font2", {255, 0, 0, 255}, 630, 0, Game::get_Instance()->getRenderer());
    // cout<<12<<" ";
}

bool PlayState::onEnter()
{
    pinfo_gun = Phantom;
    TextureManager::get_Instance()->
    load("Assets/r2.png","back1",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/crosshair.png","crs1",Game::get_Instance()->getRenderer());

    TextureManager::get_Instance()->
    load("Assets/running.png","bott",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/2.png","bott2",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/3.png","bott3",Game::get_Instance()->getRenderer());

    TextureManager::get_Instance()->
    load("Assets/Vandal_button.png","Vandal",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Phantom_button.png","Phantom",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Sheriff_button.png","Sheriff",Game::get_Instance()->getRenderer());


    TextureManager::get_Instance()->
    load("Assets/Sheriff_Specs.png","SheriffSpec",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Phantom_Specs.png","PhantomSpec",Game::get_Instance()->getRenderer());
    TextureManager::get_Instance()->
    load("Assets/Vandal_Specs.png","VandalSpec",Game::get_Instance()->getRenderer());

    TextureManager::get_Instance()->
    load("Assets/b_back.png","bback",Game::get_Instance()->getRenderer());

    TextManager::Get_Instance()->
    add_Font("Assets/BRADLEY.ttf", "font1", 50);
    TextManager::Get_Instance()->
    add_Font("Assets/BRADLEY.ttf", "font2", 75);

    SoundManager::Get_Instance()->load("Assets/Kill_sound_effect.mp3", "Kill");
    SoundManager::Get_Instance()->load("Assets/Phantom_reload.mp3", "pReload");
    SoundManager::Get_Instance()->load("Assets/Vandal_reload.mp3", "vReload");
    SoundManager::Get_Instance()->load("Assets/Sheriff_reload.mp3", "sReload");
    SoundManager::Get_Instance()->load("Assets/PhatomFire_sound.mp3", "pFire");
    SoundManager::Get_Instance()->load("Assets/VandalFire_sound.mp3", "vFire");
    SoundManager::Get_Instance()->load("Assets/SheriffFire_sound.mp3", "sFire");

    m_gameObjects.push_back({new Play_background(new LoaderParams(-640, -360, 2560, 1440,"back1")),1});
    m_gameObjects.push_back({new Crosshair(new LoaderParams (620,280,40,40,"crs1")),1});
    static_cast <Play_background*> (m_gameObjects[0].first)
    ->upd_info(pinfo_gun);
    static_cast <Play_background*> (m_gameObjects[0].first)
    ->reset();
    return true;

}

bool PlayState::onExit()
{
    m_gameObjects[0].first->clean();
    m_gameObjects[1].first->clean();
    m_gameObjects.clear();

    TextureManager::get_Instance()->clearFromTextureMap("back1");
    TextureManager::get_Instance()->clearFromTextureMap("crs1");

    TextureManager::get_Instance()->clearFromTextureMap("bott");
    TextureManager::get_Instance()->clearFromTextureMap("bott2");
    TextureManager::get_Instance()->clearFromTextureMap("bott3");

    TextureManager::get_Instance()->clearFromTextureMap("Vandal");
    TextureManager::get_Instance()->clearFromTextureMap("Phantom");
    TextureManager::get_Instance()->clearFromTextureMap("Sheriff");

    TextureManager::get_Instance()->clearFromTextureMap("SheriffSpec");
    TextureManager::get_Instance()->clearFromTextureMap("PhantomSpec");
    TextureManager::get_Instance()->clearFromTextureMap("VandalSpec");

    TextureManager::get_Instance()->clearFromTextureMap("bback");

    TextManager::Get_Instance()->clearFrom_mFont("font1");
    TextManager::Get_Instance()->clearFrom_mFont("font2");

    SoundManager::Get_Instance()->delSound("Kill");
    SoundManager::Get_Instance()->delSound("pReload");
    SoundManager::Get_Instance()->delSound("vReload");
    SoundManager::Get_Instance()->delSound("sReload");
    SoundManager::Get_Instance()->delSound("pFire");
    SoundManager::Get_Instance()->delSound("vFire");
    SoundManager::Get_Instance()->delSound("pFire");

    for(int i = 0; i < pBot.size(); i++)
        pBot[i]->clean();
    pBot.clear();
    return true;
}

void PlayState::s_Phantom()
{
    pinfo_gun = Phantom;
}

void PlayState::s_Vandal()
{
    pinfo_gun = Vandal;
}

void PlayState::s_Sheriff()
{
    pinfo_gun = Sheriff;
}

