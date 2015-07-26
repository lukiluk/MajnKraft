/* 
 * File:   Engine.cpp
 * Author: Lukas
 * 
 * Created on Štvrtok, 2015, máj 28, 1:05
 */

#include "Engine.h"

#include "SDL2/SDL.h"

Engine::Engine(int width, int height, int fps, char* windowTitle) :
    width(width), height(height), windowTitle(windowTitle), frameTime(1/fps), running(false) 
{
    window =new Window(width, height, windowTitle);
}

void Engine::run(IGame* game, Uint32 ips, Uint32 ups, Uint32 fps) {
    game->initialize();
    while (game->isRunning()) {
        if (SDL_GetTicks() - lastInputTime > 1/ips) {
            game->input();
        }
        if (SDL_GetTicks() - lastUpdateTime > 1/ups) {
            game->update();
        }
        if (SDL_GetTicks() - lastInputTime > 1/fps) {
            game->render();
            window->update();
        }
    }

}

Engine::Engine(const Engine& orig) {
}

Engine::~Engine() {
    delete window;
}

