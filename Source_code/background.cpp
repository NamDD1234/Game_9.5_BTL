#include "background.h"

using namespace std;

BG::BG(const LoaderParams* pParams):
    SDLGameObject(pParams){}

void BG::update()
{
    m_position.setX(m_position.getX() - 5);
    if(m_position.getX() <= -(2560 - 1280) )m_position.setX(0);
}

void BG::draw(double tile, int type_flip)
{
    SDLGameObject::draw(tile, type_flip);
}

void BG::clean()
{
    SDLGameObject::clean();
}
