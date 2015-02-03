/* 
 * File:   Texture.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:21
 */

#ifndef TEXTURE_H
#define	TEXTURE_H
#include <SDL2/SDL.h>
#include <GL/gl.h>

class Texture {
private:
    GLuint textures[1];
    int width, height, comp;
    SDL_Surface *img;
public:
    Texture();
    void loadTexture(GLuint shaderProgram,char* path);
    void bindTexture();
    virtual ~Texture();
private:
    Texture(const Texture& orig);
};

#endif	/* TEXTURE_H */

