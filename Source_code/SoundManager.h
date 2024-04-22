#pragma once

#include<bits/stdc++.h>
#include<SDL_mixer.h>

using namespace std;

class SoundManager
{
public:
    static SoundManager* Get_Instance();
    virtual ~ SoundManager(){}
    bool load(string Sound_Name, string ID);
    void playSound(string ID, int loop);
    void delSound(string ID);
private:
    SoundManager();
    map<string, Mix_Chunk*> m_Sound;
    static SoundManager* Instance;
};

