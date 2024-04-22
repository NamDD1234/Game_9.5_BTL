#ifndef _HISTORYSTATE_H_
#define _HISTORYSTATE_H_

#include "GameState.h"
#include "SDLGameObject.h"
#include "MenuButton.h"
#include "bits/stdc++.h"
#include "Text_and_Number.h"
#include "TextureManager.h"
#include "game.h"
#include "background.h"
using namespace std;

class HistoryState : public GameState
{
public:
    HistoryState(){};
    virtual ~HistoryState(){}
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateID() const
    {
        return s_HistoryID;
    }
    static void s_clearHistory();
private:
    static string s_HistoryID;

    static vector<GameObject*> m_gameObjects;
};
#endif // _HISTORYSTATE_H_
