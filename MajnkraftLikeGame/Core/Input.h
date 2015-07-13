/* 
 * File:   Input.h
 * Author: Lukas
 *
 * Created on Pondelok, 2015, február 16, 19:20
 */

#ifndef INPUT_H
#define	INPUT_H
#include <map>
#include "SDL2/SDL.h"

class Input{
private:
    SDL_Event event;
    std::map<SDL_Scancode, bool> holdedKeys;
    std::map<SDL_Scancode, bool> pressedKeys;           //true stacenie,false pustenie
    std::map<int, bool> holdedMB;      // mouseButton
    std::map<int, bool> clickedMB;            //mouseButton ,true stacenie,false pustenie
    unsigned short mouseX,mouseY;
    short mouseDeltaX,mouseDeltaY;
    const Uint8* keyStates;
public:
    Input();
    bool input();
    /*Ci je klavesa stlacena*/
    bool isKeyHolded(SDL_Scancode key);
    /*Ci sa stlacila klavesa*/
    bool isKeyPressed(SDL_Scancode key);
    /*Ci sa pustila klavesa*/
    bool isKeyRelased(SDL_Scancode key);
    /*Ci je tlacidlo mysi stlacene*/
    bool isMBHolded(int button);
    /*Ci sa stacilo tlacidlo mysi*/
    bool wasMBClicked(int button);
    /*Ci sa pustilo tlacidlo mysi*/
    bool wasMBRelased(int button);
    
    short getMouseDeltaX() const;
    short getMouseDeltaY() const;
    unsigned short getMouseX() const;
    unsigned short getMouseY() const;
};
#endif	/* INPUT_H */

