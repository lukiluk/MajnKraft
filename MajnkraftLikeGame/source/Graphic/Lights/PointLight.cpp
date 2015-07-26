/* 
 * File:   PointLight.cpp
 * Author: Lukas
 * 
 * Created on Streda, 2015, júl 1, 21:34
 */

#include "PointLight.h"

PointLight::PointLight() {
}

PointLight::PointLight(BaseLight baseLight, Attenuation attenuation, glm::vec3 position, float range) :
baseLight(baseLight), attenuation(attenuation), position(position), range(range) {
}

Attenuation PointLight::GetAttenuation() const {
    return attenuation;
}

BaseLight PointLight::GetBaseLight() const {
    return baseLight;
}

glm::vec3 PointLight::GetPosition() const {
    return position;
}

void PointLight::SetAttenuation(Attenuation attenuation) {
    this->attenuation = attenuation;
}

void PointLight::SetBaseLight(BaseLight baseLight) {
    this->baseLight = baseLight;
}

void PointLight::SetPosition(glm::vec3 position) {
    this->position = position;
}

float PointLight::GetRange() const {
    return range;
}

void PointLight::SetRange(float range) {
    this->range = range;
}

PointLight::~PointLight() {
}

