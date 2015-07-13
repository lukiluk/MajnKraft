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
#include "PhongShader.h"
#include <glm/gtx/quaternion.hpp>
#define GLEW_STATIC
#include <GL/glew.h>

/*Vytvori kameru na zaklade  sirky zorneho pola , minimalnej a maximalnej vzdialenosti ktoru vykresluje , a shaderu ktoremu posiela vysledok */
Camera::Camera(float fov,float aspectRatio,float minDistance,float maxDistance,GLint shader):shaderProgram(shader),sensitivity(1.8f),position(glm::vec3(0.0f,0.0f,0.0f)),fowardVector(glm::vec3(0.0f, 0.0f,-1.0f)),
upVector(glm::vec3(0.0f, 1.0f,0.0f)){
    glm::mat4 perspective = glm::perspective(fov, aspectRatio, minDistance, maxDistance);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "proj"), 1, GL_FALSE, &perspective[0][0]);
}

void Camera::setCameraPosition(float x, float y, float z){
    position=glm::vec3(x,y,z);
}

void Camera::setLookAtPosition(float x, float y, float z){
   fowardVector=glm::vec3(x,y,z);
}
/*Urci poziciu a uhol kamery na zaklade miesta kde sa nachadza ,miesta kam sa pozera , a 
  vektorom ktory ukozuje hore(na urcenie rotacie) a posle udaje shaderu*/
void Camera::update(){
    view = glm::lookAt(this->position,this->position+this->fowardVector* 1.0f,this->upVector);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"),
            1, GL_FALSE,&view[0][0]);
    PhongShader::getInstance().setUniform("eyePos",position);
}


void Camera::move(glm::vec3 direction, float amt) {
    position+=direction*amt;
}

glm::vec3 Camera::getLeft() {
    glm::vec3 leftVector = glm::cross(upVector,fowardVector);
    return leftVector;
}

glm::vec3 Camera::getRight() {
    glm::vec3 rightVector = -glm::cross(upVector,fowardVector);
    return rightVector;
}
//http://hamelot.co.uk/visualization/moderngl-camera/
void Camera::rotate(float angleX,float angleY) {
    glm::vec3 axisH = glm::cross(fowardVector,upVector);
    glm::quat quatHorizontal = glm::angleAxis(glm::degrees(angleX), axisH);
    glm::quat quatVertical = glm::angleAxis(glm::degrees(angleY), -upVector);
    glm::quat temp = glm::cross(quatHorizontal, quatVertical);
    temp = glm::normalize(temp);
    fowardVector = glm::rotate(temp, fowardVector);
}

void Camera::lookLeft(){
    //fowardVector.x-=0.1*sensitivity;
    rotate(0.0f,-0.0001f*sensitivity);
}

void Camera::lookRight(){
    //fowardVector.x+=0.1*sensitivity;
    rotate(0.0f,0.0001f*sensitivity);
}

void Camera::lookUp(){
    //fowardVector.y+=0.1*sensitivity;
    rotate(0.0001f*sensitivity,0.0f);
}

void Camera::lookDown(){
    //fowardVector.y-=0.1*sensitivity;
    rotate(-0.0001f*sensitivity,-0.0f);
}

void Camera::moveCameraLeft(){
   position+=glm::cross(upVector,fowardVector)*0.2f;
}

void Camera::moveCameraRight(){
   position+=glm::cross(fowardVector,upVector)*0.2f;
}

void Camera::moveCameraUp(){
    position.y+=0.1;
}

void Camera::moveCameraDown(){
    position.y-=0.1;
}

void Camera::moveCameraFoward() {
    //position.z-=0.1;
    position+=fowardVector*0.1f;
}

void Camera::moveCameraBack() {
    //position.z+=0.1;
    position+=-fowardVector*0.1f;
}

void Camera::setSensitivity(float sensitivity) {
    this->sensitivity=sensitivity;
}

Camera::~Camera() {
}