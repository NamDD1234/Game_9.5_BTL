#pragma once
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class TextManager
{
public:
    virtual ~TextManager(){}
    static TextManager* Get_Instance();
    bool add_Font(string font_name, string ID,
                  int font_site);
    void print_Text(string Text, string id, SDL_Color color, int x, int y,
                SDL_Renderer *pRenderer);
    void clearFrom_mFont(string id);

private:
    TextManager();
    map<string, TTF_Font*> m_Font;
    static TextManager* Instance;
};
