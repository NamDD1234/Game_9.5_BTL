#pragma once

#include "SDLGameObject.h"
#include "InputHandle.h"
#include <bits/stdc++.h>
#include "game.h"
#include "Vector2D.h"
#include "Gun_specification.h"

using namespace std;

enum type_gun
{
    Phantom = 0,
    Vandal = 1,
    Sheriff = 2
};

class Gun : public SDLGameObject, public Specification
{
public:
    Gun(const LoaderParams* pParams, Specification* pSpecs);
    virtual ~Gun();
    virtual void draw(double ti_le);
    virtual void update();
    virtual void clean();

private:

};
