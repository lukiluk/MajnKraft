#include "Input.h"

Input::Input():mouseDeltaX(0),mouseDeltaY(0),mouseX(0),mouseY(0) {

}

bool Input::input() {
    if (!keyPress.empty()) {
        keyPress.clear();
    }
    if (!MBClick.empty()) {
        MBClick.clear();
    }
    mouseDeltaX = 0;
    mouseDeltaY = 0;
    while (SDL_PollEvent(&event)) {
        
        switch (event.type) {
            case SDL_QUIT:
                return false;
            case SDL_KEYDOWN:
                pressedKeys[event.key.keysym.sym] = true;
                keyPress[event.key.keysym.sym] = true;
                return true;
                break;
            case SDL_KEYUP:
                pressedKeys[event.key.keysym.sym] = false;
                keyPress[event.key.keysym.sym] = false;
                return true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                pressedMB[event.button.button] = true;
                MBClick[event.button.button] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                pressedMB[event.button.button] = false;
                MBClick[event.button.button] = false;
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


bool Input::isKeyPressed(SDL_Keycode key) {
    if (pressedKeys.find(key) != pressedKeys.end() && pressedKeys[key])  //skontroluje ci sa nachadza v tabulke a ci je stacena klavesa
        return true;
    else
        return false;

}

bool Input::wasKeyDown(SDL_Keycode key) {
    if (keyPress.find(key) != keyPress.end() && keyPress[key])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
        return true;
    else
        return false;
}

bool Input::wasKeyUp(SDL_Keycode key) {
    if (keyPress.find(key) != keyPress.end() && !keyPress[key]) //skontroluje ci sa nachadza v tabulke a ci bola pustena klavesa
        return true;
    else
        return false;
}

bool Input::isMBPressed(int button) {
    if (pressedMB.find(button) != pressedMB.end() && pressedMB[button])
        return true;
    else
        return false;
}

bool Input::wasMBDown(int button) {
    if (MBClick.find(button) != MBClick.end() && MBClick[button])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
        return true;
    else
        return false;
}

bool Input::wasMBUp(int button) {
    if (MBClick.find(button) != MBClick.end() && !MBClick[button])  //skontroluje ci sa nachadza v tabulke a ci bola stacena klavesa
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




