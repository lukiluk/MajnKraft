/* 
 * File:   PhongShader.h
 * Author: Lukas
 *
 * Created on Utorok, 2015, marec 3, 17:06
 */

#ifndef PHONGSHADER_H
#define	PHONGSHADER_H

#include <sstream>
#include <glm/glm.hpp>
#include <vector>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include "Shader.h"
#include <glm/glm.hpp>
#include <string>
#include <stdio.h>
#include "Lights/PointLight.h"
#include "Lights/BaseLight.h"
#include "Lights/DirectionalLight.h"
#include "Lights/SpotLight.h"
#include <vector>

class PhongShader : public Shader {
private:
    static const int MAX_POINT_LIGHTS = 4;
    static const int MAX_SPOT_LIGHTS = 4;
    
    PhongShader();
    PhongShader(const PhongShader& orig);
    
    glm::vec3 ambientLight;
    DirectionalLight directionalLight;
    std::vector<PointLight> pointLights;
    std::vector<SpotLight> spotLights;
    
    float specularIntensity;
    float specularPower;
    bool ALChanged=false,DLChanged=false,SIChanged=false,SPChanged=false;
public:
    static PhongShader& getInstance();
    void updateUniforms(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::vec3 cameraPosition);
    
    void setUniformP(std::string name, BaseLight baseLight);
    void setUniformP(std::string name, DirectionalLight directionalLight);
    void setUniformP(std::string name, PointLight pointLight);
    void setUniformP(std::string name, SpotLight spotLight);
    
    void setPointLights(std::vector<PointLight> pPointLights);
    void setSpotLights(std::vector<SpotLight> pSpotLights);
    void setAmbientLight(glm::vec3 ambientLight);
    void setDirectionalLight(DirectionalLight directionalLight);
    void setSpecularIntensity(float specularIntensity);
    void setSpecularPower(float specularPower);


};

#endif	/* TEXTUREBASICSHADER_H */

