#ifndef SDLGAMEOBJ_H_
#define SDLGAMEOBJ_H_

#include "LoaderParam.h"
#include "Vector2D.h"
#include <string>
#include "TextureManager.h"
#include "GameObject.h"

class Game;

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
protected:
    Vector2D m_position; // toa do
    Vector2D m_velocity; // van toc
    Vector2D m_acceleration; // gia toc

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    double ti_le = 1;

    string m_TextureID;
};

#endif // SDLGAMEOBJ_H_
