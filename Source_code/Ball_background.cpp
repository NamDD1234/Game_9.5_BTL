#include "Ball_background.h"
#include "ball.h"
using namespace std;

const double zoom[] = {1, 1.25, 1.5, 1.75, 2};

BallBG::BallBG(const LoaderParams* pParams):
    SDLGameObject(pParams)
{

}
void BallBG::draw(double ti_le,int type_flip)
{
    SDLGameObject::draw(ti_le, type_flip);
}

void BallBG::update()
{
    Vector2D* mouse_position = InputHandle::Get_Instance()->getMousePosition();

    Vector2D new_position = Vector2D(0,0) - *mouse_position ;

    Vector2D movement = new_position - m_position;
    m_position +=  movement * 0.3;
    for(int i = 0; i < m_ball.size(); i++)
    {
        if( static_cast<Ball*>(m_ball[i])->in_hit() )static_cast<Ball*>(m_ball[i])->upd_timebal();
        {
            if(static_cast<Ball*>(m_ball[i])->get_timebal() == 10)
            {
                m_ball[i]->clean();
                m_ball.erase(m_ball.begin() + i);
                i--;
                m_ball.push_back(new Ball( new LoaderParams(m_position.getX() + 640 + rand()%(1280 - 50),
                                           m_position.getY() + 300 + rand()%(600 - 50),
                                           100,100,"ball")));
                static_cast<Ball*>(m_ball.back())->set_currentframe(0);
                static_cast<Ball*>(m_ball.back())->upd_zoombal(zoom[rand()%5]);
            }
        }
    }
    for(int i = 0; i < m_ball.size(); i++)
    {
        double Z = static_cast<Ball*>(m_ball[i])->get_zoom_bal();
        static_cast<Ball*>(m_ball[i])->set_position(static_cast<Ball*>(m_ball[i])->get_position() + movement * 0.3);

        if(static_cast<Ball*>(m_ball[i])->get_hit( Vector2D(640, 300)))
            if(InputHandle::Get_Instance()->getMouseButtonState(LEFT))
                if( !static_cast<Ball*>(m_ball[i])->in_hit() )
                {
                    SoundManager::Get_Instance()->playSound("killball", 0);
                    sl_ball ++;
                    static_cast<Ball*>(m_ball[i])->upd_hit(true);
                    static_cast<Ball*>(m_ball[i])->set_currentframe(1);
                }
    }
}

void BallBG::clean()
{
    SDLGameObject::clean();
}
