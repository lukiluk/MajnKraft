#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
/*
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>*/



#include "SDL2/SDL.h"
#include "Graphic/Mesh.h"
#include "Graphic/Shader.h"
#include "Graphic/Texture.h"
#include "Graphic/Transformation.h"

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    
    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    glewExperimental = GL_TRUE;
    glewInit();

    // Init GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Initialize OpenGL
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    int rotateAmtX=0;
    Mesh* mesh=new Mesh();                          //uklada tvar objektu a umoznuje jeho vykreslenie
    Shader* shader = new Shader();                  //vytvara farbu objektu
    Texture* texture = new Texture();               //vytvara texturu objektu
    Transformation* transf = new Transformation();  //urcuje matematicky pohlad na scenu
    mesh->loadCube();                               
    shader->loadShader();
    texture->loadTexture(shader->getShaderProgram());
    transf->transform(shader->getShaderProgram());
    
    // ---------------------------- RENDERING ------------------------------ //
    SDL_Event windowEvent;
    while (true)
    {
        // Clear the screen to black
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply a rotation
        transf->rotate(rotateAmtX);
        mesh->draw(shader->getShaderProgram());

      
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
              else if( windowEvent.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( windowEvent.key.keysym.sym )
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
                                rotateAmtX++;
                            break;

                            default:
                         //   gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
        }

        SDL_GL_SwapWindow(window);
    }

    // ---------------------------- CLEARING ------------------------------ //

    // Delete allocated resources
    
    delete transf;
    delete texture;
    delete shader;
    delete mesh;
    // ---------------------------- TERMINATE ----------------------------- //

    SDL_GL_DeleteContext(context);
    SDL_Quit();

    return 0;
}
