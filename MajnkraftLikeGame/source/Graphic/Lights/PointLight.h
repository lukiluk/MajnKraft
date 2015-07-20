/* 
 * File:   PointLight.h
 * Author: Lukas
 *
 * Created on Streda, 2015, júl 1, 21:34
 */

#ifndef POINTLIGHT_H
#define	POINTLIGHT_H

#include "BaseLight.h"
#include "Attenuation.h"


class PointLight {
public:
    PointLight();
    PointLight(BaseLight baseLight, Attenuation attenuation, glm::vec3 position, float range);

    Attenuation GetAttenuation() const;

    void SetAttenuation(Attenuation attenuation);

    BaseLight GetBaseLight() const;

    void SetBaseLight(BaseLight baseLight);

    glm::vec3 GetPosition() const;

    void SetPosition(glm::vec3 position);
    float GetRange() const;

    void SetRange(float range);

    virtual ~PointLight();
private:
    BaseLight baseLight = BaseLight(glm::vec3(1.0f,1.0f,1.0f),0.0f);;
    Attenuation attenuation = Attenuation(0.0f,0.0f,0.0f);;
    glm::vec3 position  = glm::vec3(0.0f,0.0f,0.0f);
    float range = 0;
};

#endif	/* POINTLIGHT_H */

