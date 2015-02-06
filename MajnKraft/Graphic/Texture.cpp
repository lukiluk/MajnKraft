/* 
 * File:   Texture.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2014, november 18, 23:21
 */
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

Texture::Texture():used(false) {  
}
Texture::Texture(const Texture& orig){
}
void Texture::loadTexture(GLuint shaderProgram,char* path) {
    shader= shaderProgram;
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    IMG_Init(IMG_INIT_PNG);
    img = IMG_Load(path);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);  //vytvori texturu na zaklade nacitanej textury
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);//Nastavi co sa ma stat ak poziadam o pixel vacsi ako je velkost textury
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);   //Nastavi sposob ako sa ma zmensovat textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);   //Nastavi sposob akym sa ma zvatsovat textura,linear znamena farebny priemer najblissich bodov, nearest nastavuje presny pixel
    used=true;
}

void Texture::bindTexture(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glUniform1i(glGetUniformLocation(shader, "tex0"), 0);    //poslem texturu shaderu
}

bool Texture::isUsed(){
    return used;
}

Texture::~Texture() {
    glDeleteTextures(1, textures);
}

