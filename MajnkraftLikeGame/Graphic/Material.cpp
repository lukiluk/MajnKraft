/* 
 * File:   Material.cpp
 * Author: Lukas
 * 
 * Created on Piatok, 2015, júl 3, 19:01
 */



#include "Material.h"

Material::Material():
        color(glm::vec3(0.5f,0.5f,0.5f)),
        specularIntensity(0.0f),
        specularPower(0.0f) 
{
}

Material::Material(Texture texture) : 
        texture(texture),
        color(glm::vec3(1.0f,1.0f,1.0f)),
        specularIntensity(0.0f),
        specularPower(0.0f) 
{
}

Material::Material(glm::vec3 color) :
        color(color),
        specularIntensity(0.0f),
        specularPower(0.0f) 
{
}

Material::Material(glm::vec3 color, Texture texture) :
        texture(texture),
        color(color),
        specularIntensity(0.0f),
        specularPower(0.0f) 
{
}

Material::Material(glm::vec3 color, float specularIntensity, float specularPower, Texture texture) :
        texture(texture),
        color(color),
        specularIntensity(specularIntensity),
        specularPower(specularPower) 
{
}

Material::Material(float specularIntensity, float specularPower, Texture texture) :
        texture(texture),
        color(glm::vec3(1.0f,1.0f,1.0f)),
        specularIntensity(specularIntensity),
        specularPower(specularPower) 
{
}


glm::vec3 Material::GetColor() const {
    return color;
}

float Material::GetSpecularIntensity() const {
    return specularIntensity;
}

float Material::GetSpecularPower() const {
    return specularPower;
}

Texture Material::GetTexture() const {
    return texture;
}

void Material::SetColor(glm::vec3 color) {
    this->color = color;
}

void Material::SetSpecularIntensity(float specularIntensity) {
    this->specularIntensity = specularIntensity;
}

void Material::SetSpecularPower(float specularPower) {
    this->specularPower = specularPower;
}

void Material::SetTexture(Texture texture) {
    this->texture = texture;
}

Material::~Material() {
}

