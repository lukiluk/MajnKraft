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
#include "Graphic/Mesh.h"
#include "Graphic/Shader.h"
#include "Graphic/Texture.h"
#include "Graphic/Transformation.h"
#include "Graphic/Camera.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    
    Window window(800,600,true);
    
    
    float rotateAmtX=0;
    
    Mesh* mesh=new Mesh();                          //uklada tvar objektu a umoznuje jeho vykreslenie
    Shader* shader = new Shader();                  //vytvara farbu objektu
    Texture* texture = new Texture();               //vytvara texturu objektu
    Transformation* transf = new Transformation();  //urcuje matematicky pohlad na scenu
    mesh->loadCube();                               
    shader->loadShader();
    texture->loadTexture(shader->getShaderProgram());
    Camera camera(70.0f,(float)8/6,0.01f,1000.0f,shader->getShaderProgram());     //vytvara cameru
    camera.Update(glm::vec3(1.0f, 1.0f, 4.0f),glm::vec3(0.0f, 0.0f,-1.0f),                                  //aktualizuje kameru(pojde do hlavneho cyklu))
        glm::vec3(0.0f, 1.0f, 0.0f));
    SDL_Event windowEvent;                                          //Zachytava ukoncenie okna a klavesnicu
    while (true)
    {
        // Clear the screen to black
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);                       //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         //Vycisti sa obrazovka

        // Apply a rotation
        transf->rotate(rotateAmtX,shader->getShaderProgram());      //orotuje sa objekt o dane mnozstvo
        mesh->draw(shader->getShaderProgram());                     //vykesli sa kocka

      
        if (SDL_PollEvent(&windowEvent))                            //zachyti udalosti ktore sa stali v okne
        {
            if (windowEvent.type == SDL_QUIT) break;                //ak skoncil program tak sa ukonci hlavny cyklus
              else if( windowEvent.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( windowEvent.key.keysym.sym )        //ak sa stlacila klavesa
                        {
                            case SDLK_UP:
                          //  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            break;

                            case SDLK_DOWN:
                         //   gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            break;

                            case SDLK_LEFT:
                         //   gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            break;

                            case SDLK_RIGHT:
                                rotateAmtX+=0.01;
                            break;

                            default:
                         //   gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
        }

        window.Update();
    }

    // ---------------------------- CLEARING ------------------------------ //

    // Delete allocated resources
    
    delete transf;
    delete texture;
    delete shader;
    delete mesh;
    // ---------------------------- TERMINATE ----------------------------- //
    SDL_Quit();

    return 0;
}
