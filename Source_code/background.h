#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "SDLGameObject.h"
#include "InputHandle.h"
#include <bits/stdc++.h>
#include "Vector2D.h"

using namespace std;

class BG : public SDLGameObject
{
public:
    BG(const LoaderParams* pParams);
    ~BG(){}
    virtual void draw(double ti_le, int type_flip);
    virtual void update();
    virtual void clean();
};
#endif // BACKGROUND_H_
