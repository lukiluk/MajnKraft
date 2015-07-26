/* 
 * File:   Engine.h
 * Author: Lukas
 *
 * Created on Štvrtok, 2015, máj 28, 1:05
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include "Input.h"
#include "../Graphic/Window.h"
#include "IGame.h"
#include <string>

class Engine {
    
public:
    Engine(int width, int height, int fps, char* windowTitle);
    void run(IGame* game, Uint32 ips, Uint32 ups, Uint32 fps);
    Engine(const Engine& orig);
    virtual ~Engine();
    
private:
    std::string windowTitle;
    int width;
    int height;
    double frameTime;
    bool running;
    Uint32 lastInputTime,lastRenderTime,lastUpdateTime;
    Uint32 inputUpdateTime,renderUpdateTime,UpdateTime;
    Window* window;
    Input input;

};

#endif	/* ENGINE_H */

