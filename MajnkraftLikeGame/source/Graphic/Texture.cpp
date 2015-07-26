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
#include <stdio.h>
#include <iostream>

Texture::Texture() : used(false),width(0),height(0) {
}

void Texture::loadTexture(GLuint shaderProgram, std::string file) {
    shader = shaderProgram;
    glGenTextures(1, textures);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    std::string path;
    path.append(TEXTURE_FOLDER);
    path.append(file);
    std::string extension = file.substr(file.find_last_of('.') + 1);
    GLenum format;
    if (extension == "png") {
        IMG_Init(IMG_INIT_PNG);
        format = GL_RGBA;
    }
    else if(extension == "jpg"){
        IMG_Init(IMG_INIT_JPG);
        format = GL_RGB;
    }
    else{
        printf("Unsuported(suported .png,.jpg) or invalid texture type in %s\n",file.c_str());
        return;
    }
    img = IMG_Load(path.c_str());
    if (img == NULL) {
        printf("Cannot find or load texture %s\n",path.c_str());
        return;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //Nastavi co sa ma stat ak poziadam o pixel vacsi ako je velkost textury
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //Nastavi sposob ako sa ma zmensovat textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //Nastavi sposob akym sa ma zvatsovat textura,linear znamena farebny priemer najblissich bodov, nearest nastavuje presny pixel
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, format, GL_UNSIGNED_BYTE, img->pixels); //vytvori texturu na zaklade nacitanej textury
    used = true;
}

void Texture::bindTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glUniform1i(glGetUniformLocation(shader, "tex0"), 0); //poslem texturu shaderu
}

bool Texture::isUsed() {
    return used;
}

Texture::~Texture() {
    glDeleteTextures(1, textures);
}

