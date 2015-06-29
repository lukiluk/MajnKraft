/* 
 * File:   Game.h
 * Author: Lukas
 *
 * Created on Sobota, 2015, máj 30, 17:27
 */

#ifndef GAME_H
#define	GAME_H

#include "../Core/IGame.h"
#include "SDL2/SDL.h"
#include "../Graphic/Window.h"
#include "../Graphic/Camera.h"
#include "../Graphic/GObject.h"
#include "../Core/Input.h"
#include "../Game/Svet/Svet.h"

class Game : public IGame {
public:
    Game();
    virtual void initialize();
    virtual void input();
    virtual void render();
    virtual void update();
    
    bool isRunning() const;
    void setRunning(bool running);




    Game(const Game& orig);
    virtual ~Game();
private:
    bool running;
    Window window = Window(800,600,true);
    Input inputer= Input();
    GObject* kocka1 = new GObject(CUBE,TEXTUREBASIC);
    GObject* kocka2 = new GObject(CUBE,TEXTUREBASIC);
    Camera camera= Camera(70.0f,(float)8/6,0.01f,1000.0f,kocka2->getActiveShader());     //vytvara cameru
    SDL_Event windowEvent;                                          //Zachytava ukoncenie okna a klavesnicu
};

#endif	/* GAME_H */

