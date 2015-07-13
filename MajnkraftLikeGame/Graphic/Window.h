#ifndef DISPLAY_H
#define	DISPLAY_H
#include <SDL2/SDL.h>
/*Vytvori nove okno*/
class Window {
public:
    Window();
    Window(int,int,bool);
    void update();
    SDL_Window* getWindow();
    float GetHeight() const;
    float GetWidth() const;
    ~Window();
private:
    SDL_GLContext context;
    bool doubleBuffering;
    SDL_Window* window;
    float width=0,height=0;
};

#endif	/* DISPLAY_H */

