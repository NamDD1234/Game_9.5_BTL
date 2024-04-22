#ifndef _InstructionState_h_

#define _InstructionState_h_

#include "GameState.h"
#include "SDLGameObject.h"
#include <vector>
#include "game.h"
#include "background.h"

using namespace std;

class SDLGameObject;

class InstructionState :public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual string getStateID() const
    {
        return s_InstructionStateID;
    }
private:
    static string s_InstructionStateID;
    vector <SDLGameObject*> m_gameObjects;
};
#endif // _InstructionState_h_
