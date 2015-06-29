/* 
 * File:   Engine.cpp
 * Author: Lukas
 * 
 * Created on Štvrtok, 2015, máj 28, 1:05
 */

#include "Engine.h"

#include "SDL2/SDL.h"

Engine::Engine(int width, int height, int fps, std::string windowTitle) {
    this->width = width;
    this->height = height;
    this->windowTitle = windowTitle;
    this->frameTime = 1 / fps;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = Window(width, height, true);
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
        }
    }

}

Engine::Engine(const Engine& orig) {
}

Engine::~Engine() {
}

