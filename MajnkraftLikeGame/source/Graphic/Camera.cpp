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

Camera::Camera() {

}

/*Vytvori kameru na zaklade  sirky zorneho pola , minimalnej a maximalnej vzdialenosti ktoru vykresluje , a shaderu ktoremu posiela vysledok */
Camera::Camera(float fieldOfView,float aspectRatio,float minRenderDistance,float maxRenderDistance,GLint shader):shaderProgram(shader),sensitivity(1.8f),position(glm::vec3(0.0f,0.0f,0.0f)),fowardVector(glm::vec3(0.0f, 0.0f,-1.0f)),
upVector(glm::vec3(0.0f, 1.0f,0.0f)),fieldOfView(fieldOfView),aspectRatio(aspectRatio),minRenderDistance(minRenderDistance),maxRenderDistance(maxRenderDistance)
{
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(fieldOfView, aspectRatio, minRenderDistance, maxRenderDistance);
}


void Camera::setCameraPosition(float x, float y, float z){
    position=glm::vec3(x,y,z);
}

void Camera::setLookAtPosition(float x, float y, float z){
   fowardVector=glm::vec3(x,y,z);
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(this->position,this->position+this->fowardVector* 1.0f,this->upVector);
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

glm::vec3 Camera::getCameraPosition() {
    return position;
}

void Camera::setSensitivity(float sensitivity) {
    this->sensitivity=sensitivity;
}

float Camera::getAspectRatio() const {
    return aspectRatio;
}

float Camera::getFieldOfView() const {
    return fieldOfView;
}

float Camera::getMaxRenderDistance() const {
    return maxRenderDistance;
}

float Camera::getMinRenderDistance() const {
    return minRenderDistance;
}

void Camera::setAspectRatio(float aspectRatio) {
    this->aspectRatio = aspectRatio;
}

void Camera::setFieldOfView(float fieldOfView) {
    this->fieldOfView = fieldOfView;
}

void Camera::setMaxRenderDistance(float maxRenderDistance) {
    this->maxRenderDistance = maxRenderDistance;
}

void Camera::setMinRenderDistance(float minRenderDistance) {
    this->minRenderDistance = minRenderDistance;
}

Camera::~Camera() {
}