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
#include "Input.h"
#include "Svet/Svet.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    
    Window window(800,600,true);
    Input input;
    
    float objectRotateAmtX=0;
    float objectRotateAmtY=0;
    GObject* kocka1 = new GObject(CUBE,TEXTUREBASIC);
    GObject* kocka2 = new GObject(CUBE,TEXTUREBASIC);
    kocka2->setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
    ,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
    kocka1->setTextures("./Graphic/Textures/rock.png");
    //Svet* svet = new Svet();
  
    Camera camera(70.0f,(float)8/6,0.01f,1000.0f,kocka2->getActiveShader());     //vytvara cameru
    camera.update(glm::vec3(1.0f, 1.0f, 4.0f),glm::vec3(0.0f, 0.0f,-1.0f),                                  //aktualizuje kameru(pojde do hlavneho cyklu))
        glm::vec3(0.0f, 1.0f, 0.0f));
    camera.setCameraPosition(1.0f, 1.0f, 4.0f);
    camera.setLookAtPosition(0.0f,0.0f,-2.0f);
    SDL_Event windowEvent;                                          //Zachytava ukoncenie okna a klavesnicu
    
     int mouseX=0,mouseY=0;
     bool run=true;
    while (run)
    {
        if (SDL_PollEvent(&windowEvent))                          //zachyti udalosti ktore sa stali v okne
            if (windowEvent.type == SDL_QUIT) break; 
        // Clear the screen to black
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);                       //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         //Vycisti sa obrazovka

        
        camera.update(glm::vec3(1.0f, 1.0f, 4.0f),glm::vec3(0.0f, 0.0f,-1.0f),                                  //aktualizuje kameru(pojde do hlavneho cyklu))
        glm::vec3(0.0f, 1.0f, 0.0f));
    //    svet->draw();
       /// kocka2->rotate(objectRotateAmtX,objectRotateAmtY,0.0f);
       // kocka2->drawTo(0.0f,0.0f,0.0f);
        //kocka2->drawTo(1.0f,0.0f,0.0f);       
       // kocka1->drawTo(0.0f,1.0f,0.0f);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                for (int k = 1; k <= 20; k++) {
                    if(j==20){
                        kocka2->drawTo(k,j,i);
                    }
                    if(i==1||j==1||k==1||i==20||k==20){
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
       /* bool leftClicked=false;
        if (SDL_PollEvent(&windowEvent)) {                           //zachyti udalosti ktore sa stali v okne
            if (windowEvent.type == SDL_QUIT) break;                //ak skoncil program tak sa ukonci hlavny cyklus
              else if( windowEvent.type == SDL_KEYDOWN ){
                        //Select surfaces based on key press
                        switch( windowEvent.key.keysym.sym )        //ak sa stlacila klavesa
                        {
                            case SDLK_UP:
                                objectRotateAmtY+=0.02f;
                             
                            break;

                            case SDLK_DOWN:
                                objectRotateAmtY+=-0.02f;
                            break;

                            case SDLK_LEFT:
                                objectRotateAmtX+=-0.02f;
                            break;

                            case SDLK_RIGHT:
                                objectRotateAmtX+=0.02f;
                            break;
                            
                            case SDLK_s :
                                //camera.moveCameraBack();
                                camera.move(glm::vec3(0,0,1),0.1);
                            break;
                            
                            case SDLK_w :
                                camera.moveCameraFoward();
                            break;
                            
                            case SDLK_a :
                                camera.moveCameraLeft();
                            break;
                            
                            case SDLK_d :
                                camera.moveCameraRight();
                            break;
                                 
                            break;
                            
                            default:
                         //   gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
            if(windowEvent.type == SDL_MOUSEBUTTONDOWN){
                if (windowEvent.button.button == SDL_BUTTON_LEFT){
                    SDL_ShowCursor(0);
                    leftClicked=true;
                }
                if (windowEvent.button.button == SDL_BUTTON_MIDDLE);
                if (windowEvent.button.button == SDL_BUTTON_RIGHT);
            }
            if(windowEvent.type == SDL_MOUSEBUTTONUP){
                if (windowEvent.button.button == SDL_BUTTON_LEFT){
                    SDL_ShowCursor(1);
                    leftClicked=false;
                }
                if (windowEvent.button.button == SDL_BUTTON_MIDDLE);
                if (windowEvent.button.button == SDL_BUTTON_RIGHT);
            }
            if (windowEvent.type == SDL_MOUSEMOTION)
            {
                // If the mouse is moving to the left 
                if (windowEvent.motion.xrel < 0)
                    camera.lookLeft();
                // If the mouse is moving to the right 
                else if (windowEvent.motion.xrel > 0)
                    camera.lookRight();
                // If the mouse is moving up 
                else if (windowEvent.motion.yrel < 0)
                    camera.lookUp();
                // If the mouse is moving down 
                else if (windowEvent.motion.yrel > 0)
                    camera.lookDown();
            }
            if( windowEvent.type == SDL_KEYUP ){
                switch( windowEvent.key.keysym.sym ){
                    case SDLK_RIGHT:    rotateAmtX=0;
                    break;
                    case SDLK_LEFT:     rotateAmtX=0;
                    break;
                    case SDLK_UP:       rotateAmtY=0;
                    break;
                    case SDLK_DOWN:     rotateAmtY=0;
                    break;
                }
            }
            
        }*/
        
        
    }

    SDL_Quit();

    return 0;
}
