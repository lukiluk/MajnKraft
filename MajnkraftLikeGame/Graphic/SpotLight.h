/* 
 * File:   SpotLight.h
 * Author: Lukas
 *
 * Created on Pondelok, 2015, júl 13, 17:55
 */

#ifndef SPOTLIGHT_H
#define	SPOTLIGHT_H

#include "PointLight.h"


class SpotLight {
public:
    SpotLight();
    SpotLight(PointLight pointLight, glm::vec3 direction, float cutoff);

    float GetCutoff() const;

    void SetCutoff(float cutoff);

    glm::vec3 GetDirection() const;

    void SetDirection(glm::vec3 direction);

    PointLight GetPointLight() const;

    void SetPointLight(PointLight pointLight);

    virtual ~SpotLight();
private:
    PointLight pointLight;
    glm::vec3 direction;
    float cutoff;
};

#endif	/* SPOTLIGHT_H */

