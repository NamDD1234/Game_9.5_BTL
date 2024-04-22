#include "crosshair.h"

using namespace std;

Crosshair::Crosshair(const LoaderParams* pParams):
    SDLGameObject(pParams)
{

}
void Crosshair::draw(double ti_le, int type_flip)
{
    SDLGameObject::draw(ti_le, type_flip);
}

void Crosshair::update()
{
    if(InputHandle ::Get_Instance()->getMouseButtonState(LEFT))
    {
        m_currentFrame = 1;
    }else m_currentFrame = 0;
}

void Crosshair::clean()
{
    SDLGameObject::clean();
}

