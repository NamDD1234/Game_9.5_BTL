#include "play_background.h"
using namespace std;

Play_background::Play_background(const LoaderParams* pParams):
    SDLGameObject(pParams)
{

}

void Play_background::draw(double ti_le, int type_flip)
{
    SDLGameObject::draw(ti_le, type_flip);
}

void Play_background::minus_hp(Vector2D X, Bot* BOT)
{
    int x = BOT->get_position().getX();
    int y = BOT->get_position().getY();
    int wid = BOT->getWidth();
    int hei = BOT->getHeight();
    int id_X = X.getX();
    int id_Y = X.getY();
    iii dame = iii(0,ii(0,0));
    if(BOT->get_zoombot() == 1)dame =  info_gun->get_15();
    if(BOT->get_zoombot() >= 1.4 && BOT->get_zoombot() <= 1.6)
        dame = info_gun->get_30();
    if(BOT->get_zoombot() >= 2.4 && BOT->get_zoombot() <= 2.6)
        dame = info_gun->get_50();
    if(id_X >= x + wid * 0.25 && id_X <= x + wid * 0.75)
    {
        if(id_Y > y + hei * 0.26 && id_Y <= y + hei * 0.55)
            BOT->upd_HP(BOT->get_HP() - dame.second.first);
        else if(id_Y > y + hei * 0.55 && id_Y < y + hei * 0.95)
            BOT->upd_HP(BOT->get_HP() - dame.second.second);
        if(BOT->get_HP() <= 0) sl_kill ++;
    }
    if(id_X >= x + wid * 0.4 && id_X <= x + wid * 0.55)
    {
        if(id_Y >= y + hei * 0.12 && id_Y <= y + hei * 0.25)
            BOT->upd_HP(BOT->get_HP() - dame.first);
        if(BOT->get_HP() <= 0) sl_kill ++, sl_headshot ++;
    }
    //cout<<BOT->get_HP()<<"\n";
}

bool cmp(Bot *X, Bot *Y)
{
    return X->get_zoombot() >= Y->get_zoombot();
}
void Play_background::update()
{

    for(int i = 0; i < bot.size(); i++)
    {
        Bot* X = bot[i];
        if(X->get_HP() <= 0)
        {
            SoundManager::Get_Instance()->playSound("Kill", 0);
            int R = X->get_position().getX()- m_position.getX() - 640 + X->getWidth();
            int L = R - X->getWidth();
            if(R > 1165)
            {
                R = 1165;
                L = R - X->getWidth();
            }
            if(L < 0)
            {
                L = 0;
                R = L + X->getWidth();
            }
            if(X->get_zoombot() == 1)
                Bot_1->updateRange(L, R, 0);
            if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6)
                Bot_2->updateRange(L, R, 0);
            if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6)
                Bot_3->updateRange(L, R, 0);
            bot[i]->clean();
            bot.erase(bot.begin() + i);
            i--;
        }
    }

    if(Game::get_Instance()->get_easyorhard())
    {
        if(bot.size() > 1)
        {
            while(bot.size())
            {
                Bot* X = bot.back();
                int R = X->get_position().getX()- m_position.getX() - 640 + X->getWidth();
                int L = R - X->getWidth();
                if(R > 1165)
                {
                    R = 1165;
                    L = R - X->getWidth();
                }
                if(L < 0)
                {
                    L = 0;
                    R = L + X->getWidth();
                }
                if(X->get_zoombot() == 1)
                    Bot_1->updateRange(L, R, 0);
                if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6)
                    Bot_2->updateRange(L, R, 0);
                if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6)
                    Bot_3->updateRange(L, R, 0);
                bot.back()->clean();
                bot.pop_back();
            }
        }
        if(bot.size())
        {
            if(bot.back()->get_countexist() == 60)
            {
                Bot* X = bot.back();
                int R = X->get_position().getX()- m_position.getX() - 640 + X->getWidth();
                int L = R - X->getWidth();
                if(R > 1165)
                {
                    R = 1165;
                    L = R - X->getWidth();
                }
                if(L < 0)
                {
                    L = 0;
                    R = L + X->getWidth();
                }
                if(X->get_zoombot() == 1)
                    Bot_1->updateRange(L, R, 0);
                if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6)
                    Bot_2->updateRange(L, R, 0);
                if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6)
                    Bot_3->updateRange(L, R, 0);
                bot.back()->clean();
                bot.pop_back();
            }
            else
                bot.back()->upd_countexist();
        }
        //  cout<<2<<" ";
    }
    else
    {
        for(Bot* X:bot)
        {
            if(!X->get_is_running())
            {
                int direction = (rand() % 2)? 1 : -1;
                int ok = 1;
                int val = X->get_position().getX()- m_position.getX() - 640 +
                          X->getWidth() *(direction > 0) + 14 * direction;
                val = max(val, 0);
                val = min(val, 1165);
                if(X->get_zoombot() == 1 &&
                        Bot_1->getRange (val, val))
                    ok = 0;
                if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6 &&
                        Bot_2->getRange (val, val))
                    ok = 0;
                if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6 &&
                        Bot_3->getRange (val, val))
                    ok = 0;
                if(ok)
                {
                    int u = rand()%200;
                    if(!u) X->upd_is_running(direction);
                }
            }
            if(X->get_is_running() != 0)
            {
                int val = X->get_position().getX()- m_position.getX() - 640 +
                          (int)(1.0*X->getWidth())* (X->get_is_running() < 0) + 30 * (-X->get_is_running());
                val = max(val, 0);
                val = min(val, 1165);

                if(X->get_zoombot() == 1 &&
                        Bot_1->getRange (val, val))
                    X->set_currentframe(22);
                if(X->get_zoombot() >= 1.4 && X->get_zoombot() <=1.6 &&
                        Bot_2->getRange (val, val))
                    X->set_currentframe(22);
                if(X->get_zoombot() >= 2.4 && X->get_zoombot() <=2.6 &&
                        Bot_3->getRange (val, val))
                    X->set_currentframe(22);

                if(X->get_currentframe() == 22)
                {
                    X->upd_is_running(0);
                    X->set_currentframe(0);
                }
                else if(X->get_countcf() == 1)
                {
                    int R = X->get_position().getX()- m_position.getX() - 640 + X->getWidth();
                    int L = R - X->getWidth();
                    if(R > 1165)
                    {
                        R = 1165;
                        L = R - X->getWidth();
                    }
                    if(L < 0)
                    {
                        L = 0;
                        R = L + X->getWidth();
                    }
                    if(X->get_zoombot() == 1)
                        Bot_1->updateRange(L, R, 0);
                    if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6)
                        Bot_2->updateRange(L, R, 0);
                    if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6)
                        Bot_3->updateRange(L, R, 0);

                    X->set_currentframe(X -> get_currentframe() + 1);

                    X->set_position(X -> get_position() + Vector2D(-X->get_is_running() * 7, 0));

                    R = X->get_position().getX()- m_position.getX() - 640 + X->getWidth();
                    L = R - X->getWidth();
                    if(R > 1165)
                    {
                        R = 1165;
                        L = R - X->getWidth();
                    }
                    if(L < 0)
                    {
                        L = 0;
                        R = L + X->getWidth();
                    }
                    if(X->get_zoombot() == 1)
                        Bot_1->updateRange(L, R, 1);
                    if(X->get_zoombot() >= 1.4 && X->get_zoombot() <= 1.6)
                        Bot_2->updateRange(L, R, 1);
                    if(X->get_zoombot() >= 2.4 && X->get_zoombot() <= 2.6)
                        Bot_3->updateRange(L, R, 1);
                    X->upd_countcf(0);
                }
                else X->upd_countcf(X->get_countcf() + 1);
            }
        }
    }
    //  cout<<3<<" ";
    if( InputHandle::Get_Instance() -> getMouseButtonState(LEFT) )
    {
        if(!info_gun->get_autofire())
        {
            if(!num_ammo)
            {
                R_X -=2, R_Y -=2, R_X = max(R_X, 0), R_Y = max(R_Y, 0), in_fire = false, change = false;
                if(!in_reload)
                    SoundManager::Get_Instance()->playSound("sReload", 0), in_reload = true;
            }
            else if(!in_fire)
            {
                SoundManager::Get_Instance()->playSound("sFire", 0);
                if(!Game::get_Instance()->get_reloadornot())num_ammo --;
                in_fire = true;
                change  = true;
                R_X = rand() % (int)info_gun->get_recoil();
                R_Y = rand() % (int)info_gun->get_recoil();
                R_X*= rand() % 2 ? 1: -1;
            }
            else R_X = 0, R_Y = 0, change = false;
        }
        else
        {
            if(!num_ammo)
            {
                if(!in_reload)
                {
                    if(info_gun->get_maxammo() == 25)SoundManager::Get_Instance()->playSound("vReload", 0);
                    else SoundManager::Get_Instance()->playSound("pReload", 0);
                    in_reload = true;
                }
                time = -1, ammo_fired = 0, R_X -=2, R_Y -=2, R_X = max(R_X, 0), R_Y = max(R_Y, 0), change = false;
            }
            else if(1.0*time /(60/info_gun->get_firespeed()) >=
                    ammo_fired && num_ammo)
            {
                if(info_gun->get_maxammo() == 25)SoundManager::Get_Instance()->playSound("vFire", 0);
                else SoundManager::Get_Instance()->playSound("pFire", 0);
                ammo_fired ++;
                R_X = rand() % 35;
                R_Y = rand() % (10 * (int)ammo_fired);
                if(10 * ammo_fired >= info_gun->get_recoil())
                    R_Y = info_gun->get_recoil() +
                          ((rand() % 2) ? -2 : 2);
                R_X*= rand() % 2 ? 1: -1;
                if(num_ammo == info_gun->get_maxammo()&&!Game::get_Instance()->get_reloadornot())
                    R_X = R_Y = 0;
                if(!Game::get_Instance()->get_reloadornot())num_ammo--;
                change = true;
            }
            else change = false;
            time++;
        }
    }
    else R_X = 0,R_Y = 0, time = 0, ammo_fired = 0,in_fire = false, change = false;

    Vector2D new_position = Vector2D(0,0) - *(InputHandle::Get_Instance()->getMousePosition());

    if(InputHandle::Get_Instance()->get_Ctrl())down = -10;
    else if(InputHandle::Get_Instance()->get_Shift())down = -5;
    else down = 0;

    if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_A))
        moving -= (down != 0) ? (3 + down/5) : 3, in_running = 10;
    else if(InputHandle::Get_Instance()->isKeyDown(SDL_SCANCODE_D))
        moving += (down != 0) ? (3 + down/5) : 3, in_running = 10;
    else
    {
        if(in_running)
        {
            R_X = R_Y = 0;
            in_running --;
        }
    }

    if(moving < 0) moving = max(moving, -30);
    if(moving > 0) moving = min(moving, 30);

    Vector2D movement = new_position - m_position;

    double up_recoil = 1;
    if(InputHandle::Get_Instance()->get_Ctrl())up_recoil = 0.65;
    if(in_running) up_recoil += 1;

    m_position +=  movement * 0.3
                   + Vector2D(R_X * up_recoil, R_Y * up_recoil)
                   - Vector2D(moving, 0)
                   + Vector2D(0, down);
    // cout<<4<<" ";
    for(int i = 0; i < bot.size(); i++)
    {
        Bot *X = bot[i];
        X->set_position(X->get_position() + movement * 0.3
                        + Vector2D(R_X * up_recoil, R_Y * up_recoil)
                        - Vector2D(moving, 0)
                        + Vector2D(0, down));
        if( InputHandle::Get_Instance() -> getMouseButtonState(LEFT)
                && !time_reload && change)
            minus_hp(Vector2D(640,300), X);
    }
    // cout<<5<<" ";
    if(num_ammo == 0 && time_reload < 60 * info_gun->get_timereload())
        time_reload ++;
    else if(time_reload >= 60 * info_gun->get_timereload())reset();
    if(bot.size() > 0)
        sort(bot.begin(),bot.end(),cmp);
    //cout<<6<<" ";
}

void Play_background::clean()
{
    for(Bot* X : bot)
        X->clean();
    bot.clear();
    Bot_1->getClear(0, 1400);
    Bot_2->getClear(0, 1400);
    Bot_3->getClear(0, 1400);
}

