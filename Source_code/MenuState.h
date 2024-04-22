#ifndef _MenuState_h_
#define _MenuState_h_

#include "GameState.h"
#include "SDLGameObject.h"
#include "game.h"
#include "MenuButton.h"
#include "BallState.h"
#include "PlayState.h"
#include "EndState.h"
#include "HistoryState.h"
#include "background.h"
#include "InstructionState.h"

using namespace std;

class MenuState : public GameState
{
public:
    MenuState(){};
    virtual ~MenuState(){}
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateID() const
    {
        return s_menuID;
    }

    static void s_menuToPlay();
    static void s_exitFromMenu();
    static void s_option();
    static void s_history();
    static void s_instruction();

private:
    static string s_menuID;

    static vector<GameObject*> m_gameObjects;
};
#endif // _MenuState_h_
