#ifndef _game_h_
#define _game_h_

#include "player.h"
#include "Ball_background.h"
#include "InputHandle.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "crosshair.h"


using namespace std;

class Game
{
public:
    static Game* get_Instance();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int
              height, int width, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit();
    bool running()
    {
        return m_bRunning;
    }
    SDL_Renderer* getRenderer() const
    {
        return m_pRenderer;
    }

    GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }

    void upd_timeplay(int new_timeplay) { time_play = new_timeplay; }
    int get_timeplay() { return time_play; }

    void upd_easyorhard(int new_upd) { easy_or_hard = new_upd; }
    int get_easyorhard() { return easy_or_hard; }

    void upd_reloadornot(int new_upd) { reload_or_not = new_upd; }
    int get_reloadornot() { return reload_or_not; }
private:

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    int time_play = 0;
    int easy_or_hard = 0;
    int reload_or_not = 0;
    static Game* G_Instance;
    Game();
    vector<GameObject*> m_gameObjects;

    GameStateMachine* m_pGameStateMachine;
};
#endif // _game_h_


