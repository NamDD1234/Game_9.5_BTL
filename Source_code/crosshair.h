#pragma once

#include "SDLGameObject.h"
#include "InputHandle.h"

using namespace std;

class Crosshair : public SDLGameObject
{
public:
    Crosshair(const LoaderParams* pParams);
    ~Crosshair(){}
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
};

