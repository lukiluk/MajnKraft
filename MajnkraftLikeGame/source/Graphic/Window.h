#ifndef DISPLAY_H
#define	DISPLAY_H
#include <SDL2/SDL.h>
/*Vytvori nove okno*/
class Window {
public:
    Window();
    Window(int width,int height,char* title);
    void update();
    SDL_Window* getWindow();
    float GetHeight();
    float GetWidth();
    ~Window();
private:
    SDL_GLContext context;
    bool doubleBuffering;
    SDL_Window* window;
    float width=0,height=0;
};
//
#endif	/* DISPLAY_H */

