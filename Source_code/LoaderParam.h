#pragma once
#include <bits/stdc++.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class LoaderParams
{
public:
    virtual ~LoaderParams(){}
    LoaderParams(int x, int y, int width, int height, string
                 TextureID) : m_x(x), m_y(y), m_width(width), m_height(height),
        m_TextureID(TextureID){}

    int getX() const{return m_x;}
    int getY() const{return m_y;}

    int getWidth() const{return m_width;}
    int getHeight() const{return m_height;}

    string getTextureID() const{return m_TextureID;}
private:

    int m_x;
    int m_y;

    int m_width;
    int m_height;

    string m_TextureID;
};
