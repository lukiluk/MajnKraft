/* 
 * File:   Material.h
 * Author: Lukas
 *
 * Created on Piatok, 2015, júl 3, 19:01
 */

#ifndef MATERIAL_H
#define	MATERIAL_H

#include "Texture.h"
#include <glm/glm.hpp>

class Material {
public:
    Material();
    Material(Texture texture);
    Material(glm::vec3 color);
    Material(glm::vec3 color, Texture texture);
    Material(float specularIntensity, float specularPower, Texture texture);
    Material(glm::vec3 color, float specularIntensity, float specularPower, Texture texture);

    glm::vec3 GetColor() const;
    void SetColor(glm::vec3 color);

    float GetSpecularIntensity() const;
    void SetSpecularIntensity(float specularIntensity);

    float GetSpecularPower() const;
    void SetSpecularPower(float specularPower);

    Texture GetTexture() const;
    void SetTexture(Texture texture);

    virtual ~Material();
private:
    Texture texture;
    glm::vec3 color;
    float specularIntensity;
    float specularPower;
};

#endif	/* MATERIAL_H */

