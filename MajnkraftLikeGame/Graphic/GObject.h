/* 
 * File:   GObject.h
 * Author: Lukas
 *
 * Created on Štvrtok, 2015, február 12, 16:35
 */

#ifndef GOBJECT_H
#define	GOBJECT_H

#include "Shader.h"
#include "Texture.h"
#include "../Core/Transformation.h"
#include "Mesh.h"

enum TypeOfObject{CUBE,COMPLEX};
enum TypeOfShader{TEXTUREBASIC,AMBIENT};

class GObject{
public:
    GObject(TypeOfObject objectType,TypeOfShader shaderType);
    TypeOfObject getObjectType() const ;
    void setObjectType(TypeOfObject objetType);
    TypeOfShader getShaderType() const ;
    void setShaderType(TypeOfShader shaderType);
    void rotate(float amountX,float ammountY,float ammountZ);
    void move(float ammountX,float ammountY,float ammountZ);
    void setTextures(char* front,char* back=NULL,char* left=NULL,char* right=NULL,char* top=NULL ,char* bottom=NULL);
    void drawTo(float x,float y,float z);
    GLuint getActiveShader();
    virtual ~GObject();
private:
    static const int MAXTEXTURES=6;
    TypeOfObject objectType;
    TypeOfShader shaderType;
    Mesh* mesh;
    Texture textures[MAXTEXTURES];
    GLuint activeShader;
    Transformation* transformation;
};

#endif	/* GOBJECT_H */

