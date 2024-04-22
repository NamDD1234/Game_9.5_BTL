#ifndef _bot_h_
#define _bot_h_

#include "SDLGameObject.h"
#include "InputHandle.h"
#include <bits/stdc++.h>
#include "Vector2D.h"
#include "GameObject.h"
using namespace std;

class Bot : public SDLGameObject
{
public:
    Bot(const LoaderParams* pParams);
    ~Bot(){}
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();

    virtual int get_currentframe();
    virtual void set_currentframe(int I);

    virtual Vector2D get_position();
    virtual void set_position(Vector2D new_position);

    double getWidth() const
    {
        return m_width;
    }
    double getHeight() const
    {
        return m_height;
    }
    int get_HP()
    {
        return HP;
    }
    void upd_HP(int new_HP)
    {
        HP = new_HP;
    }
    int get_is_running()
    {
        return is_running;
    }
    void upd_is_running(int new_is_running)
    {
        is_running = new_is_running;
    }
    double get_zoombot()
    {
        return zoom_bot;
    }
    void upd_zoombot(double new_zoombot)
    {
        zoom_bot = new_zoombot;
    }
    void upd_countexist() { count_exist++; }
    int get_countexist() { return count_exist; }

    void upd_countcf(int new_cf) { count_cf = new_cf; }
    int get_countcf()
    {
        return count_cf;
    }
private:
    int HP = 100;
    int is_running = 0;
    double zoom_bot = 1;
    int count_exist = 0;
    int count_cf = 0; // change_frame
};


#endif // _ball_h_


