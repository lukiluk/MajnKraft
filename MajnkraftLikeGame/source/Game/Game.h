/* 
 * File:   Game.h
 * Author: Lukas
 *
 * Created on Sobota, 2015, máj 30, 17:27
 */

#ifndef GAME_H
#define	GAME_H

#include "../Core/IGame.h"
#include <SDL2/SDL.h>
#include "../Graphic/Window.h"
#include "../Graphic/Camera.h"
#include "../Graphic/GObject.h"
#include "../Core/Input.h"
#include "../Game/Svet/Svet.h"
#include "../Graphic/PhongShader.h"

class Game : public IGame {
public:
    Game();
    void initialize();
    void input();
    void render();
    void update();
    
    bool isRunning();
    void setRunning(bool running);

    Game(const Game& orig);
    virtual ~Game();
private:
    bool running;
    GObject* kocka1;
    GObject* plane;
    Camera camera;
    Input playerInput;
    SDL_Event windowEvent;                                          //Zachytava ukoncenie okna a klavesnicu
    
    std::vector<PointLight> pls;
    std::vector<SpotLight> sls;
};

#endif	/* GAME_H */

