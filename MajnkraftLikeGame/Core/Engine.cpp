/* 
 * File:   Engine.cpp
 * Author: Lukas
 * 
 * Created on Štvrtok, 2015, máj 28, 1:05
 */

#include "Engine.h"
#include "SDL2/SDL.h"
#include "Input.h"
#include "../Graphic/Window.h"
#include <string>

Engine::Engine(int width, int height, int fps, std::string title) {
    this->width = width;
    this->height = height;
    this->title = title;
    this->frameTime = 1/fps;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    Window window(800,600,true);
    Input input;
}

Engine::Engine(const Engine& orig) {
}

Engine::~Engine() {
}

