// v Linuxe: -lSDL2 -lGL -lGLEW -lSDL2_image
// vo Windows: -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32

#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
/*
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>*/



#include "SDL2/SDL.h"
#include "Graphic/Window.h"
#include "Graphic/Camera.h"
#include "Graphic/GObject.h"
#include "Core/Input.h"
#include "Game/Svet/Svet.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    
    Window window(800,600,true);
    Input input;

    GObject* kocka1 = new GObject(CUBE,AMBIENT);
    GObject* kocka2 = new GObject(CUBE,AMBIENT);
    kocka2->setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
    ,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
    kocka1->setTextures("./Graphic/Textures/rock.png");
    //Svet* svet = new Svet();
  
    Camera camera(70.0f,(float)8/6,0.01f,1000.0f,kocka2->getActiveShader());     //vytvara cameru
    camera.setCameraPosition(1.0f, 1.0f, 4.0f);
    camera.setLookAtPosition(0.0f,0.0f,-2.0f);
    SDL_Event windowEvent;                                          //Zachytava ukoncenie okna a klavesnicu
    
    bool run=true;
    while (run)
    {
        if (SDL_PollEvent(&windowEvent))                          //zachyti udalosti ktore sa stali v okne
            if (windowEvent.type == SDL_QUIT) break; 
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                       //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         //Vycisti sa obrazovka

        
        camera.update();
        //draw cube
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 1; k <= 10; k++) {
                    if(j==10){
                        kocka2->drawTo(k,j,i);
                    }
                    if(i==1||j==1||k==1||i==10||k==10){
                        kocka1->drawTo(k,j,i);
                    }
                }
            }
        }

        run=input.input();
        if(input.wasKeyDown(SDLK_ESCAPE)){
            break;
        }
        if(input.isKeyPressed(SDLK_s)){
            camera.moveCameraBack();
        }
        if(input.isKeyPressed(SDLK_w)){
            camera.moveCameraFoward();
        }
        if(input.isKeyPressed(SDLK_a)){
             camera.moveCameraLeft();
        }
        if(input.isKeyPressed(SDLK_d)){
            camera.moveCameraRight();
        }
        // If the mouse is moving to the left 
        if (input.getMouseDeltaX() < 0)
            camera.lookLeft();
                // If the mouse is moving to the right 
        if (input.getMouseDeltaX() > 0)
            camera.lookRight();
                // If the mouse is moving up 
        if (input.getMouseDeltaY() < 0)
            camera.lookUp();
                // If the mouse is moving down 
        if (input.getMouseDeltaY() > 0)
            camera.lookDown();
        if (input.isMBPressed(SDL_BUTTON_LEFT)){
            SDL_SetRelativeMouseMode(SDL_TRUE);
        }
        if(input.wasMBUp(SDL_BUTTON_LEFT)) {
            SDL_SetRelativeMouseMode(SDL_FALSE);
        }
        window.Update();    
    }

    SDL_Quit();

    return 0;
}
