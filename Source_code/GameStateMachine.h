#ifndef _GameStateMachine_h_

#define _GameStateMachine_h_

#include "GameState.h"
#include <vector>
#include <iostream>
//#include "InputHandle.h"
using namespace std;

class GameStateMachine
{
public:
    GameStateMachine(){};
    virtual ~GameStateMachine(){}
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

    void update();
    void render();
    void clear_all();

private:
    static vector<GameState* > m_gameStates;
    //vector<GameState* > m_gameStates;
};

#endif // _GameStateMachine_h_
