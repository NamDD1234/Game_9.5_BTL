#ifndef _ball_h_
#define _ball_h_

#include "SDLGameObject.h"
#include "InputHandle.h"
#include <bits/stdc++.h>
#include "Vector2D.h"

using namespace std;

class Ball : public SDLGameObject
{
public:
    Ball(const LoaderParams* pParams);
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
    virtual int get_currentframe();
    virtual void set_currentframe(int I);
    virtual Vector2D get_position();
    virtual bool get_hit(Vector2D ID);
    virtual void set_position(Vector2D new_position);
    double getWidth() const { return m_width; }
    double getHeight() const { return m_height; }
    void upd_hit(bool new_hit) {ok_hit = new_hit;}
    bool in_hit(){return ok_hit;}

    void upd_zoombal(double new_zoombal)
    {
        zoom_bal = new_zoombal;
    }

    double get_zoom_bal()
    {
        return zoom_bal;
    }

    int get_timebal()
    {
        return time_bal;
    }
    void upd_timebal()
    {
        time_bal ++;
    }

private:
    bool ok_hit = false;
    int time_bal = 0;
    double zoom_bal = 1;
};


#endif // _ball_h_

