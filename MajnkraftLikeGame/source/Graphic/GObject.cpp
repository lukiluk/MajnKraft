/* 
 * File:   GObject.cpp
 * Author: Lukas
 * 
 * Created on Štvrtok, 2015, február 12, 16:35
 */

#include "GObject.h"
#include "TextureBasicShader.h"
#include "PhongShader.h"
#include <glm/glm.hpp>

GObject::GObject(TypeOfObject objectType, TypeOfShader shaderType) : objectType(objectType), shaderType(shaderType) {
    if (this->objectType == CUBE) {
        mesh = new Mesh();
    }
    if (this->objectType == PLANE) {
        mesh = new Mesh();
    }
    if (this->shaderType == TEXTUREBASIC) {
        activeShader = TextureBasicShader::getInstance().getShaderProgram();
    }
    if (this->shaderType == PHONG) {
        activeShader = PhongShader::getInstance().getShaderProgram();
    }
    transformation = new Transformation();
}

TypeOfObject GObject::getObjectType() const {
    return objectType;
}

void GObject::setObjectType(TypeOfObject objectType) {
    this->objectType = objectType;
    if (this->objectType == CUBE) {
        mesh = new Mesh();
    }
    if (this->objectType == PLANE) {
        mesh = new Mesh();
    }
}

TypeOfShader GObject::getShaderType() const {
    return shaderType;
}

void GObject::setShaderType(TypeOfShader shaderType) {
    this->shaderType = shaderType;
    if (this->shaderType == TEXTUREBASIC) {
        activeShader = TextureBasicShader::getInstance().getShaderProgram();
    }
    if (this->shaderType == PHONG) {
        activeShader = PhongShader::getInstance().getShaderProgram();
    }
}

void GObject::setTextures(char* front, char* back, char* left, char* right, char* top, char* bottom) {
    if (back == NULL) {
        textures[0].loadTexture(activeShader, front);
    } else {
        textures[0].loadTexture(activeShader, front);
        textures[1].loadTexture(activeShader, back);
        textures[2].loadTexture(activeShader, left);
        textures[3].loadTexture(activeShader, right);
        textures[4].loadTexture(activeShader, top);
        textures[5].loadTexture(activeShader, bottom);
    }
}

void GObject::move(float ammountX, float ammountY, float ammountZ) {
    transformation->move(ammountX, ammountY, ammountZ);
}

void GObject::rotate(float ammountX, float ammountY, float ammountZ) {
    transformation->rotate(-ammountY, ammountX, ammountZ);
}

void GObject::scale(float ammountX, float ammountY, float ammountZ) {
    transformation->setScaleX(ammountX);
    transformation->setScaleY(ammountY);
    transformation->setScaleZ(ammountZ);
}

void GObject::draw() {
    transformation->apply(activeShader);
    if (objectType == CUBE) {
        if (textures[1].isUsed()) {
            textures[0].bindTexture();
            mesh->selectCubeFront();
            mesh->draw(activeShader);
            textures[1].bindTexture();
            mesh->selectCubeBack();
            mesh->draw(activeShader);
            textures[2].bindTexture();
            mesh->selectCubeLeft();
            mesh->draw(activeShader);
            textures[3].bindTexture();
            mesh->selectCubeRight();
            mesh->draw(activeShader);
            textures[4].bindTexture();
            mesh->selectCubeTop();
            mesh->draw(activeShader);
            textures[5].bindTexture();
            mesh->selectCubeBottom();
            mesh->draw(activeShader);
        } else {
            textures[0].bindTexture();
            mesh->selectCubeFront();
            mesh->draw(activeShader);
            mesh->selectCubeBack();
            mesh->draw(activeShader);
            mesh->selectCubeLeft();
            mesh->draw(activeShader);
            mesh->selectCubeRight();
            mesh->draw(activeShader);
            mesh->selectCubeTop();
            mesh->draw(activeShader);
            mesh->selectCubeBottom();
            mesh->draw(activeShader);
        }
    } else if (objectType == PLANE) {
        textures[0].bindTexture();
        mesh->selectTestPlane();
        mesh->draw(activeShader);
    }
}

GLuint GObject::getActiveShader() {
    return activeShader;
}

GObject::~GObject() {
    delete mesh;
    delete transformation;
}
