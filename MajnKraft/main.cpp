/* 
 * File:   main.cpp
 * Author: robert
 *
 * Created on October 29, 2014, 12:23 PM
 */

#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Delay(1000);

    SDL_Quit();
    return 0;
}

