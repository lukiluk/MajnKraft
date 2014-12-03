/* 
 * File:   Texture.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:21
 */

#ifndef TEXTURE_H
#define	TEXTURE_H

class Texture {
private:
    GLuint textures[1];
    int width, height, comp = 0;
    SDL_Surface *img = 0;
public:
    Texture();
    Texture(const Texture& orig);
    void loadTexture(GLuint shaderProgram);
    virtual ~Texture();
private:

};

#endif	/* TEXTURE_H */

