#pragma once

#include "SDLGameObject.h"
#include "InputHandle.h"
#include <bits/stdc++.h>
#include "game.h"
#include "Vector2D.h"
#include "Gun_specification.h"
#include "bot.h"
#include "IT.h"
using namespace std;

class Bot;

class Play_background : public SDLGameObject
{
public:
    Play_background(const LoaderParams* pParams);
    ~Play_background(){}
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
    vector<Bot*> getBot()
    {
        return bot;
    }
    void setBot(vector<Bot*> new_bot)
    {
        bot = new_bot;
    }
    virtual Vector2D get_position()
    {
        return m_position;
    }
    void upd_Bot1(int startt, int endd, int value)
    {
        Bot_1->updateRange(startt, endd, value);
    }
    void upd_Bot2(int startt, int endd, int value)
    {
        Bot_2->updateRange(startt, endd, value);
    }
    void upd_Bot3(int startt, int endd, int value)
    {
        Bot_3->updateRange(startt, endd, value);
    }
    bool get_Bot1(int startt, int endd)
    {
        return Bot_1->getRange(startt, endd);
    }
    bool get_Bot2(int startt, int endd)
    {
        return Bot_2->getRange(startt, endd);
    }
    bool get_Bot3(int startt, int endd)
    {
        return Bot_3->getRange(startt, endd);
    }
    bool upd_info(Specification* new_info)
    {
        info_gun = new_info;
        return true;
    }

    Specification* get_info(){ return info_gun; }

    void reset()
    {
        num_ammo = info_gun->get_maxammo();
        time_reload = 0;
        ammo_fired = 0;
        in_fire = false;
        change  = false;
        in_reload = false;
    }
    void minus_hp(Vector2D X, Bot* BOT);
    int get_num_ammo() { return num_ammo; }

    void upd_inrunning(bool new_running) { in_running = new_running; }
    int get_running() { return in_running; }

    int get_slkill() { return sl_kill; }
    int get_slheadshot() { return sl_headshot; }

private:
    vector<Bot*>bot;
    Specification* info_gun;
    SegmentTree *Bot_1 = new SegmentTree(1400), *Bot_2 = new SegmentTree(1400), *Bot_3 = new SegmentTree(1400);
    int R_X = 0, R_Y = 0;
    int time = 0;
    Vector2D hit = Vector2D(0,0);

    double time_reload = 0;
    int num_ammo = 0;
    double ammo_fired = 0;
    bool in_fire = false, change = false;

    int in_running = 0;
    int moving = 0;
    int down = 0;
    int in_reload = false;
    int sl_kill = 0;
    int sl_headshot = 0;
};

