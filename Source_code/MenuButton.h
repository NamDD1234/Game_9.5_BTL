#ifndef _MenuButton_h_

#define _MenuButton_h_

#include "SDLGameObject.h"
#include "InputHandle.h"

using namespace std;

enum button_state
{
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:
    MenuButton(const LoaderParams* pParams, void (*callback)());
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
    bool check_inbutton() { return in_button; }
    void upd_size(double s_size) { up_size = s_size; }
    bool check_release() { return m_bReleased; }
private:
    void (*m_callback)();
    bool m_bReleased  = true;
    bool in_button;
    double up_size = 1;

};
#endif // _MenuButton_h_
