#ifndef _SETTINGSTATE_H_
#define _SETTINGSTATE_H_

using namespace std;

#include "SDLGameObject.h"
#include "game.h"
#include "MenuButton.h"
#include "background.h"
#include "TextureManager.h"
#include "Text_and_Number.h"
#include <bits/stdc++.h>

using namespace std;

class SettingState : public GameState
{
public:
    SettingState(){}
    virtual ~SettingState(){}
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateID() const
    {
        return s_SettingID;
    }
    static void reloading();
    static void unreloading();
    static void harder();
    static void easier();
private:
    static string s_SettingID;

    static vector<GameObject*>m_gameObjects;
};
#endif // _SETTINGSTATE_H_
