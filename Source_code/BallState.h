#ifndef _BallState_h_

#define _BallState_h_

#include "GameState.h"
#include "SDLGameObject.h"
#include <bits/stdc++.h>
#include "game.h"
#include "InputHandle.h"
#include "crosshair.h"
#include "ball.h"
#include "Text_and_Number.h"
#include "SoundManager.h"
using namespace std;

class Ball;

class BallState :public GameState
{
public:
    virtual ~BallState(){}
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual string getStateID() const
    {
        return s_ballID;
    }
    int get_time() { return time; }
    void upd_time(int new_time) { time = new_time; }
    int get_T() { return T; }
    void upd_T(int new_T) { T = new_T; }
    int get_slball() { return sl_ball; }
    void upd_slball(int new_slball) { sl_ball = new_slball; }
private:
    static string s_ballID;
    static vector < pair<GameObject*,double> > m_gameObjects;
    static vector<GameObject*> vtball;
    int time = 0;

    int T = 60;
    int T_max = T;
    Vector2D vec = Vector2D (0, 0);
    int sl_ball = 0;
};
#endif // _BallState_h_
