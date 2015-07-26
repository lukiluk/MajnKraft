/* 
 * File:   BaseLight.h
 * Author: Lukas
 *
 * Created on Utorok, 2015, jún 30, 22:54
 */

#ifndef BASELIGHT_H
#define	BASELIGHT_H

#include <glm/glm.hpp>

class BaseLight {
public:
    BaseLight();
    BaseLight(glm::vec3 color, float intensity);
    glm::vec3 GetColor() const;
    void SetColor(glm::vec3 color);
    float GetIntensity() const;
    void SetIntensity(float intensity);
    virtual ~BaseLight();
private:
    glm::vec3 color;
    float intensity;
};

#endif	/* BASELIGHT_H */

