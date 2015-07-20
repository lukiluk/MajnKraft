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
#include <string>

class Texture {
private:
    static constexpr const char* TEXTURE_FOLDER = "resources/textures/";
    
    GLuint textures[1],shader;
    int width, height, comp;
    SDL_Surface* img;
    bool used;
public:
    Texture();
    void loadTexture(GLuint shaderProgram,std::string path);
    void bindTexture();
    bool isUsed();
    virtual ~Texture();
private:
   // Texture(const Texture& orig);
};

#endif	/* TEXTURE_H */

