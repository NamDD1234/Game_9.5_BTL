#include "SDLGameObject.h"
#include "game.h"

using namespace std;


SDLGameObject::SDLGameObject(const LoaderParams* pParams):
    GameObject(pParams),
    m_position(pParams->getX(), pParams->getY()),
    m_velocity (0, 0),
    m_acceleration(0, 0)
{

    m_width = pParams->getWidth();
    m_height = pParams->getHeight();

    m_TextureID = pParams->getTextureID();

    m_currentRow = 1;
    m_currentFrame = 0;
}

void SDLGameObject::draw(double ti_le,int type_flip)
{
    TextureManager::get_Instance()->drawFrame(m_TextureID,
            (int) m_position.getX(), (int) m_position.getY(),
            m_width, m_height, m_currentRow, m_currentFrame,
            Game::get_Instance()->getRenderer(), type_flip, ti_le);
}

void SDLGameObject::update()
{
    m_velocity +=m_acceleration;
    m_position += m_velocity;

}

void SDLGameObject::clean()
{
    //TextureManager::get_Instance()->clearFromTextureMap(m_TextureID);
}

