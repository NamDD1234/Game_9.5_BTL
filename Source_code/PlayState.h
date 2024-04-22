#ifndef _PlayState_h_
#define _PlayState_h_

#include "GameState.h"
#include "SDLGameObject.h"
#include <bits/stdc++.h>
#include "game.h"
#include "InputHandle.h"
#include "crosshair.h"
#include "MenuButton.h"
#include "GameStateMachine.h"
#include "play_background.h"
#include "bot.h"
#include "Gun_specification.h"
#include "Text_and_Number.h"
#include "EndState.h"
#include "SoundManager.h"
#include "SettingState.h"

using namespace std;


class PlayState : public GameState
{
public:
    PlayState(){};
    virtual ~PlayState(){}
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual string getStateID() const
    {
        return s_playID;
    }
private:
    static string s_playID;
    static vector < pair<GameObject*,double> > m_gameObjects;
    static vector < Bot* > pBot;
    static Specification* pinfo_gun;

    static void s_Phantom();
    static void s_Vandal();
    static void s_Sheriff();
    int T_max = 60;
    int time = 0; int T = T_max;
    string NUM, TIME;
};
#endif // _PlayState_h_
