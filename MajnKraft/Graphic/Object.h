/* 
 * File:   Object.h
 * Author: Lukas
 *
 * Created on Sobota, 2015, január 17, 18:50
 */

#ifndef OBJECT_H
#define	OBJECT_H
#include "Texture.h"
#include "Transformation.h"
#include "Shader.h"
#include "Mesh.h"
enum TypeOfObject{CUBE,COMPLEX};
enum TypeOfShader{TEXTURECLASSIC};
class Object {
public:
    Object(TypeOfObject objectType,TypeOfShader shaderType);
    TypeOfObject getObjectType() const ;
    void setObjectType(TypeOfObject objetType);
    TypeOfShader getShaderType() const ;
    void setShaderType(TypeOfShader shaderType);
    void rotate(float amountX,float ammountY);
    void setTextures(char* front,char* back=NULL,char* left=NULL,char* right=NULL,char* top=NULL ,char* bottom=NULL);
    void drawTo(float x,float y,float z);
    virtual ~Object();
private:
    static const int MAXTEXTURES=6;
    TypeOfObject objectType;
    TypeOfShader shaderType;
    Mesh* mesh;
    Texture** textures;
    Shader* activeShader;
    Transformation* transformation;
};

#endif	/* OBJECT_H */

