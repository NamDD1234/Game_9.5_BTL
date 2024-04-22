#ifndef _InputHandle_h_
#define _InputHandle_h_

#include<SDL.h>
#include<iostream>
#include<vector>

#include "game.h"
#include "Vector2D.h"

using namespace std;

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandle
{
public:
    static InputHandle* Get_Instance();

    void update();
    void clean();

    bool isKeyDown(SDL_Scancode key);
    bool getMouseButtonState(int buttonNumber);


    Vector2D* getMousePosition();

    bool get_Ctrl() { return in_Ctrl; }
    bool get_Shift() { return in_Shift; }
    bool get_B() { return in_B; }
    bool get_esc() { return in_esc; }

    Vector2D get_oldposition() { return old_position; }

    void change_oldposition(Vector2D new_position)
    { old_position = new_position; }
    int get_oldX() { return old_position.getX(); }
    int get_oldY() { return old_position.getY(); }
    void false_esc() { in_esc = false; }
private:
    InputHandle();
    ~InputHandle() {}
    static InputHandle* IH_Instance;

    bool m_mouseButtonStates[3] = {false, false, false};

    Vector2D* m_mousePosition = new Vector2D (0,0);

    const Uint8* m_keystates = NULL;

    bool in_Ctrl = false, in_Shift = false;
    bool in_B = false, in_esc = false;
    Vector2D old_position = Vector2D(0,0);
};
#endif // _InputHandle_h_
