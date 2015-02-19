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
    std::map<int, bool> pressedKeys;
    std::map<int, bool> keyPress;           //true stacenie,false pustenie
    std::map<int, bool> pressedMB;      // mouseButton
    std::map<int, bool> MBClick;            //mouseButton ,true stacenie,false pustenie
    unsigned short mouseX,mouseY;
    short mouseDeltaX,mouseDeltaY;
public:
    Input();
    bool input();
    /*Ci je klavesa stlacena*/
    bool isKeyPressed(SDL_Keycode key);
    /*Ci sa stlacila klavesa*/
    bool wasKeyDown(SDL_Keycode key);
    /*Ci sa pustila klavesa*/
    bool wasKeyUp(SDL_Keycode key);
    /*Ci je tlacidlo mysi stlacene*/
    bool isMBPressed(int button);
    /*Ci sa stacilo tlacidlo mysi*/
    bool wasMBDown(int button);
    /*Ci sa pustilo tlacidlo mysi*/
    bool wasMBUp(int button);
    
    short getMouseDeltaX() const;
    short getMouseDeltaY() const;
    unsigned short getMouseX() const;
    unsigned short getMouseY() const;
};
#endif	/* INPUT_H */

