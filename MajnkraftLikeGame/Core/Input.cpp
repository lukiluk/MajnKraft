#include "Input.h"
#include <stdio.h>

Input::Input():keyStates(SDL_GetKeyboardState(NULL)),mouseDeltaX(0),mouseDeltaY(0),mouseX(0),mouseY(0) {

}

bool Input::input() {
    pressedKeys.clear();
    clickedMB.clear();
    mouseDeltaX = 0;
    mouseDeltaY = 0;
    while (SDL_PollEvent(&event)) {
        
        switch (event.type) {
            case SDL_QUIT:
                return false;
            case SDL_KEYDOWN:
                pressedKeys[event.key.keysym.scancode] = true;
                return true;
                break;
            case SDL_KEYUP:
                holdedKeys[event.key.keysym.scancode] = false;
                pressedKeys[event.key.keysym.scancode] = false;
                return true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                holdedMB[event.button.button] = true;
                clickedMB[event.button.button] = true;
                printf("click");
                break;
            case SDL_MOUSEBUTTONUP:
                holdedMB[event.button.button] = false;
                clickedMB[event.button.button] = false;
                break;
            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                mouseDeltaX = event.motion.xrel;
                mouseDeltaY = event.motion.yrel;
                break;
            default:break;
        }
    }
    return true;
}


bool Input::isKeyHolded(SDL_Scancode key) {
    if (keyStates[key])  //skontroluje ci sa nachadza v tabulke a ci je stacena klavesa
        return true;
    else
        return false;

}

bool Input::isKeyPressed(SDL_Scancode key) {
    if (pressedKeys.find(key) != pressedKeys.end() && pressedKeys[key])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
        return true;
    else
        return false;
}

bool Input::isKeyRelased(SDL_Scancode key) {
    if (pressedKeys.find(key) != pressedKeys.end() && !pressedKeys[key]) //skontroluje ci sa nachadza v tabulke a ci bola pustena klavesa
        return true;
    else
        return false;
}

bool Input::isMBHolded(int button) {
    if (holdedMB.find(button) != holdedMB.end() && holdedMB[button])
        return true;
    else
        return false;
}

bool Input::wasMBClicked(int button) {
    if (clickedMB.find(button) != clickedMB.end() && clickedMB[button])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
        return true;
    else
        return false;
}

bool Input::wasMBRelased(int button) {
    if (clickedMB.find(button) != clickedMB.end() && !clickedMB[button])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
        return true;
    else
        return false;
}

short Input::getMouseDeltaX() const {
    return mouseDeltaX;
}

short Input::getMouseDeltaY() const {
    return mouseDeltaY;
}

unsigned short Input::getMouseY() const {
    return mouseY;
}

unsigned short Input::getMouseX() const {
    return mouseX;
}




