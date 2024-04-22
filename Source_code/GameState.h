#ifndef _GameState_h_
#define _GameState_h_

#include <string>

using namespace std;

class GameState
{
public:
    virtual ~GameState(){}
    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual string getStateID() const  = 0;
};

#endif // _GameState_h_
