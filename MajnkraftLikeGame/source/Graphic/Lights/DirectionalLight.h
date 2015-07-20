/* 
 * File:   DirectionalLight.h
 * Author: Lukas
 *
 * Created on Utorok, 2015, jún 30, 23:05
 */

#ifndef DIRECTIONALLIGHT_H
#define	DIRECTIONALLIGHT_H

#include "BaseLight.h"


class DirectionalLight {
public:
    DirectionalLight();
    DirectionalLight(BaseLight base, glm::vec3 direction);
    BaseLight GetBase() const;
    void SetBase(BaseLight base);
    glm::vec3 GetDirection() const;
    void SetDirection(glm::vec3 direction);
    virtual ~DirectionalLight();
private:
    BaseLight base;
    glm::vec3 direction;
};

#endif	/* DIRECTIONALLIGHT_H */

