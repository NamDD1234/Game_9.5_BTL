#ifndef BALL_BG_H
#define BALL_BG_H

#include "SDLGameObject.h"
#include "Vector2D.h"
#include "ball.h"
#include "GameObject.h"

class BallBG : public SDLGameObject
{
public:
    BallBG(const LoaderParams* pParams);
    ~BallBG(){}
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();

    int get_slball()
    {
        return sl_ball;
    }
    void upd_slball(int new_slball)
    {
        sl_ball = new_slball;
    }

    vector<GameObject*> getBall()
    {
        return m_ball;
    }
    void setBall(vector<GameObject*> Bal)
    {
        m_ball = Bal;
    }

    Vector2D get_position()
    {
        return m_position;
    }
private:
    vector<GameObject*> m_ball;
    int sl_ball = 0;
};
#endif // BALL_BG_H
