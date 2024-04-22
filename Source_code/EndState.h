#ifndef _Endstate_h_
#define _Endstate_h_

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
#include "PlayState.h"
#include "MenuState.h"

using namespace std;

class EndState : public GameState
{
public:
    EndState(int sl_ball, int sl_bot, int headshot_kills, int T_max, bool new_T):
        e_sl_ball(sl_ball),e_sl_bot(sl_bot), e_headshot_kills(headshot_kills), e_T_max(T_max), check_T(new_T)
    {

    }
    virtual ~EndState();
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual string getStateID() const
    {
        return s_endID;
    }
    static void s_Resume();
    static void s_Newgame();
    static void s_Backtomenu();
private:
    static string s_endID;
    static vector < GameObject* > m_gameObjects;
    bool check_T = true;
    int e_sl_ball = -1, e_sl_bot = -1, e_headshot_kills = -1, e_T_max = 0;
    static int e_type;
};
#endif // _Endstate_h_
