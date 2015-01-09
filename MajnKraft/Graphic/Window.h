#ifndef DISPLAY_H
#define	DISPLAY_H
#include <SDL2/SDL.h>
/*Vytvori nove okno*/
class Window {
public:
    Window(int,int,bool);
    void Update();
    ~Window();
private:
    SDL_GLContext context;
    bool doubleBuffering;
    SDL_Window* window;
};

#endif	/* DISPLAY_H */

