/* 
 * File:   SpotLight.cpp
 * Author: Lukas
 * 
 * Created on Pondelok, 2015, júl 13, 17:55
 */

#include "SpotLight.h"

SpotLight::SpotLight() {
    pointLight.GetBaseLight().SetIntensity(0);
}

SpotLight::SpotLight(PointLight pointLight,glm::vec3 direction, float cutoff) :
pointLight(pointLight), direction(glm::normalize(direction)), cutoff(cutoff) {
}

float SpotLight::GetCutoff() const {
    return cutoff;
}

glm::vec3 SpotLight::GetDirection() const {
    return direction;
}

PointLight SpotLight::GetPointLight() const {
    return pointLight;
}

void SpotLight::SetDirection(glm::vec3 direction) {
    this->direction = direction;
}

void SpotLight::SetPointLight(PointLight pointLight) {
    this->pointLight = pointLight;
}

void SpotLight::SetCutoff(float cutoff) {
    this->cutoff = cutoff;
}


SpotLight::~SpotLight() {
}

