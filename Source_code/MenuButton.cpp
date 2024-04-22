#include "MenuButton.h"

using namespace std;

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)() )
    :  SDLGameObject(pParams),m_callback(callback)
{

}
void MenuButton ::draw(double ti_le,int type_flip)
{
    SDLGameObject::draw(ti_le, type_flip);
}

void MenuButton::update()
{
    Vector2D* pMousePos = InputHandle::Get_Instance()
                          ->getMousePosition();


    if(pMousePos->getX() < (m_position.getX() + m_width / up_size)
            && pMousePos->getX() > m_position.getX()
            && pMousePos->getY() < (m_position.getY() + m_height / up_size)
            && pMousePos->getY() > m_position.getY())
                if(m_bReleased == false && !InputHandle::Get_Instance()->getMouseButtonState(LEFT) )m_callback();

    if(!InputHandle::Get_Instance()->getMouseButtonState(LEFT))m_bReleased = true;

    if(pMousePos->getX() < (m_position.getX() + m_width / up_size)
            && pMousePos->getX() > m_position.getX()
            && pMousePos->getY() < (m_position.getY() + m_height / up_size)
            && pMousePos->getY() > m_position.getY())
    {

        if(InputHandle ::Get_Instance()->getMouseButtonState(LEFT) &&m_bReleased)
        {
            m_currentFrame = CLICKED;
            m_bReleased = false;
        }
        else if(!InputHandle ::Get_Instance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
        else m_currentFrame = MOUSE_OUT;
        in_button = true;
    }
    else
        m_currentFrame = MOUSE_OUT, in_button = false;
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}
