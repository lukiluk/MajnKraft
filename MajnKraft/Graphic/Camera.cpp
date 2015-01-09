/* 
 * File:   Camera.cpp
 * Author: Lukas
 * 
 * Created on Streda, 2014, december 31, 2:28
 */

#include "Camera.h"
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include <GL/glew.h>

/*Vytvori kameru na zaklade  sirky zorneho pola , minimalnej a maximalnej vzdialenosti ktoru vykresluje , a shaderu ktoremu posiela vysledok */
Camera::Camera(float fov,float aspectRatio,float minDistance,float maxDistance,GLint shader):shaderProgram(shader) {
    glm::mat4 perspective = glm::perspective(fov, aspectRatio, minDistance, maxDistance);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "proj"), 1, GL_FALSE, &perspective[0][0]);
}

/*Urci poziciu a uhol kamery na zaklade miesta kde sa nachadza ,miesta kam sa pozera , a 
  vektorom ktory ukozuje hore(na urcenie rotacie) a posle udaje shaderu*/
void Camera::Update(glm::vec3 position,glm::vec3 fowardVector,glm::vec3 upVector){
    this->position=position;
    this->fowardVector=fowardVector;
    this->upVector=upVector;
    view = glm::lookAt(this->position,this->position+this->fowardVector,this->upVector);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"),
            1, GL_FALSE,&view[0][0]);
}

Camera::~Camera() {
}

