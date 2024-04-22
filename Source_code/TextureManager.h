#pragma once
#include <bits/stdc++.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class TextureManager
{
public:
    virtual ~TextureManager(){}
    static TextureManager* get_Instance();
    bool load(string fileName,string id,
              SDL_Renderer* pRenderer);

    void draw(string id, int x, int y, int width, int
              height, SDL_Renderer* pRenderer, int type_flip = 1, double ti_le  = 1);

    void drawFrame(string id, int x, int y, int width, int
                   height, int currentRow, int currentFrame, SDL_Renderer*
                   pRenderer, int type_flip = 1, double ti_le = 1);

    void clearFromTextureMap( string id );
private:
    TextureManager ();
    map<string, SDL_Texture*> m_textureMap;
    static TextureManager* Instance;
};
