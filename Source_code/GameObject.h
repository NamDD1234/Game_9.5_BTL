#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include<iostream>
#include "LoaderParam.h"

class GameObject
{
public:
    virtual void draw(double ti_le, int type_flip) = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual ~GameObject() {}
protected:
    GameObject(const LoaderParams* pParams) {}

};


#endif // _GAMEOBJJECT_H_
