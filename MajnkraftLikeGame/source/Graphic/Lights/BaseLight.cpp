/* 
 * File:   BaseLight.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2015, jún 30, 22:55
 */

#include "BaseLight.h"

BaseLight::BaseLight() {
    color = glm::vec3(0.0f,0.0f,0.0f);
    intensity = 0.0f;
}


BaseLight::BaseLight(glm::vec3 color, float intensity) :
    color(color), intensity(intensity) {
}

BaseLight::~BaseLight() {
}

glm::vec3 BaseLight::GetColor() const {
    return color;
}

float BaseLight::GetIntensity() const {
    return intensity;
}

void BaseLight::SetColor(glm::vec3 color) {
    this->color = color;
}

void BaseLight::SetIntensity(float intensity) {
    this->intensity = intensity;
}




