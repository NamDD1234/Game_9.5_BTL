#include "InputHandle.h"

using namespace std;

InputHandle* InputHandle::IH_Instance = NULL;

InputHandle:: InputHandle() {}

InputHandle* InputHandle::Get_Instance()
{
    if(IH_Instance == NULL)
    {
        IH_Instance = new InputHandle();
        return IH_Instance;
    }
    return IH_Instance;
}

bool InputHandle::isKeyDown(SDL_Scancode key)
{
    if(m_keystates != NULL)
    {
        if(m_keystates[key] == 1)
            return true;
        else
            return false;
    }
    return false;
}
void InputHandle ::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        m_keystates = SDL_GetKeyboardState(NULL);

        if(event.type == SDL_QUIT)
            Game::get_Instance()->quit();

        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
                m_mouseButtonStates [LEFT] = true;
            if(event.button.button == SDL_BUTTON_MIDDLE)
                m_mouseButtonStates [MIDDLE] = true;
            if(event.button.button == SDL_BUTTON_RIGHT)
                m_mouseButtonStates [RIGHT] = true;
        }

        if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
                m_mouseButtonStates [LEFT] = false;
            if(event.button.button == SDL_BUTTON_MIDDLE)
                m_mouseButtonStates [MIDDLE] = false;
            if(event.button.button == SDL_BUTTON_RIGHT)
                m_mouseButtonStates [RIGHT] = false;
        }
        if(event.type == SDL_MOUSEMOTION)
        {
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
        }

        // vt ctrl vs shift o day
        if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_RCTRL || event.key.keysym.sym == SDLK_LCTRL)
                if(!get_Ctrl())in_Ctrl = true;
            if(event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT)
                if(!get_Shift())in_Shift = true;
            if(event.key.keysym.sym == SDLK_b)
                in_B = true;
            if(event.key.keysym.sym == SDLK_ESCAPE)
                in_esc = true;

        }

        if(event.type == SDL_KEYUP)
        {
            if(event.key.keysym.sym == SDLK_RCTRL || event.key.keysym.sym == SDLK_LCTRL)
                if(get_Ctrl())in_Ctrl = false;
            if(event.key.keysym.sym == SDLK_RSHIFT || event.key.keysym.sym == SDLK_LSHIFT)
                if(get_Shift())in_Shift = false;
            if(event.key.keysym.sym == SDLK_b)
                in_B = false;
        }
    }
}

void InputHandle ::clean()
{

}

bool InputHandle ::getMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}


Vector2D *InputHandle::getMousePosition()
{
    return m_mousePosition;
}
