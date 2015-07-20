/* 
 * File:   DirectionalLight.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2015, jún 30, 23:05
 */

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() {
    base = BaseLight();
    direction = glm::vec3(0,0,0);
}

DirectionalLight::DirectionalLight(BaseLight base, glm::vec3 direction) :
base(base), direction(glm::normalize(direction)) {
}

BaseLight DirectionalLight::GetBase() const {
    return base;
}

glm::vec3 DirectionalLight::GetDirection() const {
    return direction;
}

void DirectionalLight::SetBase(BaseLight base) {
    this->base = base;
}

void DirectionalLight::SetDirection(glm::vec3 direction) {
    this->direction = direction;
}

DirectionalLight::~DirectionalLight() {
}

