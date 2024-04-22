#include "bot.h"

using namespace std;

Bot::Bot(const LoaderParams* pParams):
    SDLGameObject(pParams)
{

}

void Bot::draw(double ti_le, int type_flip)
{
    SDLGameObject::draw(ti_le, type_flip);
}

void Bot::update()
{

}


int Bot::get_currentframe()
{
    return m_currentFrame;
}

void Bot::set_currentframe(int I)
{
    m_currentFrame = I;
}

Vector2D Bot::get_position()
{
    return m_position;
}

void Bot::set_position(Vector2D new_position)
{
    m_position = new_position;
}
void Bot::clean()
{
    SDLGameObject::clean();
}


