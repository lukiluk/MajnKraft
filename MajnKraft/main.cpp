#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
/*
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>*/

#define GLM_FORCE_RADIANS

#include "SDL2/SDL.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transformation.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    
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
        transf->rotate();
        mesh->draw(shader->getShaderProgram());

      
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
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
