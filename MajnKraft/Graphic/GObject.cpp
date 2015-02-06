/* 
 * File:   Object.cpp
 * Author: Lukas
 * 
 * Created on Sobota, 2015, január 17, 18:50
 */

#include "Object.h"

Object::Object(TypeOfObject objectType,TypeOfShader shaderType):objectType(objectType),shaderType(shaderType) {
    if(this->objectType==CUBE)
        mesh=new Mesh();
    if(this->shaderType==TEXTURECLASSIC)
        activeShader=new Shader();
    transformation = new Transformation();
}

TypeOfObject Object::getObjectType() const {
        return objectType;
}

void Object::setObjectType(TypeOfObject objectType) {
    this->objectType = objectType;
}

TypeOfShader Object::getShaderType() const {
    return shaderType;
}

void Object::setShaderType(TypeOfShader shaderType) {
    this->shaderType = shaderType;
}

void Object::setTextures(char* front,char* back,char* left,char* right,char* top ,char* bottom){
    if(back=NULL){
        textures[0]=new Texture();
        textures[0]->loadTexture(activeShader->getShaderProgram(),front);
    }
    else{
        for (int i = 0; i < MAXTEXTURES; i++) {
            textures = new Texture();
        }
        textures[0]->loadTexture(activeShader->getShaderProgram(),front);
        textures[1]->loadTexture(activeShader->getShaderProgram(),back);
        textures[2]->loadTexture(activeShader->getShaderProgram(),left);
        textures[3]->loadTexture(activeShader->getShaderProgram(),right);
        textures[4]->loadTexture(activeShader->getShaderProgram(),top);
        textures[5]->loadTexture(activeShader->getShaderProgram(),bottom);
    }
}
void Object::rotate(float ammountX ,float ammountY){
    transformation->rotate(ammountX,ammountY,activeShader->getShaderProgram());
}

void Object::drawTo(float x,float y,float z){
    transformation->move(x,y,z,activeShader->getShaderProgram());
    if(textures[1]){
        textures[0]->bindTexture();
        mesh->selectCubeFront();
        mesh->draw(activeShader->getShaderProgram());
        textures[1]->bindTexture();
        mesh->selectCubeBack();
        mesh->draw(activeShader->getShaderProgram());
        textures[2]->bindTexture();
        mesh->selectCubeLeft();
        mesh->draw(activeShader->getShaderProgram());
        textures[3]->bindTexture();
        mesh->selectCubeRight();
        mesh->draw(activeShader->getShaderProgram());
        textures[4]->bindTexture();
        mesh->selectCubeTop();
        mesh->draw(activeShader->getShaderProgram());
        textures[5]->bindTexture();
        mesh->selectCubeBottom();
        mesh->draw(activeShader->getShaderProgram());
    }
    else{
        textures[0]->bindTexture();
        mesh->selectCube();
        mesh->draw(activeShader->getShaderProgram());
    }
}

Object::~Object() {
    delete(mesh);
    delete(activeShader);
    delete[](textures);
    delete(transformation);
}

