/* 
 * File:   PhongShader.h
 * Author: Lukas
 *
 * Created on Utorok, 2015, marec 3, 17:06
 */

#ifndef PHONGSHADER_H
#define	PHONGSHADER_H

#include "Shader.h"
#include <glm/glm.hpp>

class PhongShader :public Shader{
public:
    static PhongShader& getInstance();
    void updateUniforms();
    static glm::vec3 ambientLight;
private:
    PhongShader();
    PhongShader(const PhongShader& orig);
    
};

#endif	/* TEXTUREBASICSHADER_H */

