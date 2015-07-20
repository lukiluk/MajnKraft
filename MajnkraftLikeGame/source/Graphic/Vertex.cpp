/* 
 * File:   Vertex.cpp
 * Author: Lukas
 * 
 * Created on Streda, 2015, júl 15, 22:23
 */

#include <glm/detail/type_vec.hpp>

#include "Vertex.h"

Vertex::Vertex() {
}

Vertex::Vertex(glm::vec3 position) :
    position(position) {
}

Vertex::Vertex(glm::vec3 position, glm::vec2 texturePosition) :
    position(position), texturePosition(texturePosition) {
}

Vertex::Vertex(glm::vec3 position, glm::vec3 normal) :
    position(position), normal(normal) {
}

Vertex::Vertex(glm::vec3 position, glm::vec2 texturePosition, glm::vec3 normal) :
    position(position), texturePosition(texturePosition), normal(normal) {
}
//-----------------------------------------------------------------------------------
Vertex::Vertex(float posX, float posY, float posZ) :
    position(glm::vec3(posX,posY,posZ)){
}

Vertex::Vertex(float posX, float posY, float posZ, float textureX, float textureY) : 
    position(glm::vec3(posX,posY,posZ)), texturePosition(glm::vec2(textureX,textureY)) {
}

Vertex::Vertex(float posX, float posY, float posZ, float normalX, float normalY, float normalZ) :
    position(glm::vec3(posX,posY,posZ)), normal(glm::vec3(normalX,normalY,normalZ)) {    
}

Vertex::Vertex(float posX, float posY, float posZ, float textureX, float textureY, float normalX, float normalY, float normalZ) :
    position(glm::vec3(posX,posY,posZ)), texturePosition(glm::vec2(textureX,textureY)), normal(glm::vec3(normalX,normalY,normalZ)) { 
}
//-----------------------------------------------------------------------------------
glm::vec3 Vertex::GetPosition() const {
    return position;
}

glm::vec2 Vertex::GetTexturePosition() const {
    return texturePosition;
}

glm::vec3 Vertex::GetNormal() const {
    return normal;
}

void Vertex::SetNormal(glm::vec3 normal) {
    this->normal = normal;
}

void Vertex::SetPosition(glm::vec3 position) {
    this->position = position;
}

void Vertex::SetTexturePosition(glm::vec2 texturePosition) {
    this->texturePosition = texturePosition;
}

Vertex::~Vertex() {
}

