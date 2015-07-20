/* 
 * File:   PhongShader.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2015, marec 3, 17:06
 */
#include "PhongShader.h"

PhongShader::PhongShader() {
    createShaders(loadShader(std::string("phongShader.")+ std::string(VERTEX_EXTENSION)), loadShader(std::string("phongShader.") + std::string(FRAGMENT_EXTENSION)));
    addUniform("trans");
    addUniform("view");
    addUniform("proj");
    addUniform("baseColor");
    addUniform("ambientLight");
    addUniform("directionalLight.base.color");
    addUniform("directionalLight.base.intensity");
    addUniform("directionalLight.direction");
    addUniform("specularIntensity");
    addUniform("specularPower");
    addUniform("eyePos");
    for (int i = 0; i < MAX_POINT_LIGHTS; i++) {
        std::string s = SSTR(i);
        addUniform(("pointLights[" + s + "].base.color"));
        addUniform(("pointLights[" + s + "].base.intensity"));
        addUniform(("pointLights[" + s + "].atten.constant"));
        addUniform(("pointLights[" + s + "].atten.linear"));
        addUniform(("pointLights[" + s + "].atten.exponent"));
        addUniform(("pointLights[" + s + "].position"));
        addUniform(("pointLights[" + s + "].range"));
    }
    for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
        std::string s = SSTR(i);
        addUniform(("spotLights[" + s + "].pointLight.base.color"));
        addUniform(("spotLights[" + s + "].pointLight.base.intensity"));
        addUniform(("spotLights[" + s + "].pointLight.atten.constant"));
        addUniform(("spotLights[" + s + "].pointLight.atten.linear"));
        addUniform(("spotLights[" + s + "].pointLight.atten.exponent"));
        addUniform(("spotLights[" + s + "].pointLight.position"));
        addUniform(("spotLights[" + s + "].pointLight.range"));
        addUniform(("spotLights[" + s + "].direction"));
        addUniform(("spotLights[" + s + "].cutoff"));
    }

}

PhongShader& PhongShader::getInstance() {
    static PhongShader instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

void PhongShader::updateUniforms(glm::mat4 projectionMatrix,glm::mat4 viewMatrix, glm::vec3 cameraPosition) {
    setUniform("proj",projectionMatrix);
    setUniform("view",viewMatrix);
    setUniform("eyePos",cameraPosition);
    if (ambientLight == glm::vec3()) {
        printf("Warning: ambient lignht is zero");
    } else if (ALChanged) {
        setUniform("ambientLight", ambientLight);
    }
    if (specularIntensity == 0.0f) {
        printf("Warning: specular intensity is zero");
    } else if (SIChanged) {
        setUniform("specularIntensity", specularIntensity);
    }
    if (specularPower == 0.0f) {
        printf("Warning: specular power is zero");
    } else if (SPChanged) {
        setUniform("specularPower", specularPower);
    }
    if (DLChanged) {
        setUniformP("directionalLight", directionalLight);
    }
    for (int i = 0; i < pointLights.size(); i++) {
        setUniformP("pointLights[" + SSTR(i) + "]", pointLights[i]);
    }
    for (int i = 0; i < spotLights.size(); i++) {
        setUniformP("spotLights[" + SSTR(i) + "]", spotLights[i]);
    }
    SPChanged = false;
    DLChanged = false;
    ALChanged = false;
    SIChanged = false;
}

void PhongShader::setUniformP(std::string name, BaseLight baseLight) {
    try {
        setUniform(name + ".color", baseLight.GetColor());
        setUniform(name + ".intensity", baseLight.GetIntensity());
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void PhongShader::setUniformP(std::string name, DirectionalLight directionalLight) {
    try {
        setUniformP((name + ".base"), directionalLight.GetBase());
        setUniform((name + ".direction"), directionalLight.GetDirection());
        DLChanged = true;
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void PhongShader::setUniformP(std::string name, PointLight pointLight) {
    try {
        setUniformP(name + ".base", pointLight.GetBaseLight());
        setUniform(name + ".atten.constant", pointLight.GetAttenuation().GetConstant());
        setUniform(name + ".atten.linear", pointLight.GetAttenuation().GetLinear());
        setUniform(name + ".atten.exponent", pointLight.GetAttenuation().GetExponent());
        setUniform(name + ".position", pointLight.GetPosition());
        setUniform(name + ".range", pointLight.GetRange());
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void PhongShader::setUniformP(std::string name, SpotLight spotLight){
    try {
        setUniformP(name + ".pointLight",spotLight.GetPointLight());
        setUniform(name + ".direction",spotLight.GetDirection());
        setUniform(name + ".cutoff",spotLight.GetCutoff());
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void PhongShader::setPointLights(std::vector<PointLight> pPointLights) {
    if (pPointLights.size() > MAX_POINT_LIGHTS) {
        printf("You passed too much point lights");
        return;
    }
    if (pointLights.size()!=0) {
        pointLights.clear();
    }
    for (int i = 0; i < pPointLights.size(); i++) {
        this->pointLights.push_back(pPointLights.at(i));
    }
}

void PhongShader::setSpotLights(std::vector<SpotLight> pSpotLights) {
    if (pSpotLights.size() > MAX_SPOT_LIGHTS) {
        printf("You passed too much spot lights");
        return;
    }
    if (spotLights.size()!=0) {
        spotLights.clear();
    }
    for (int i = 0; i < pSpotLights.size(); i++) {
        this->spotLights.push_back(pSpotLights.at(i));
    }
}


void PhongShader::setAmbientLight(glm::vec3 ambientLight) {
    this->ambientLight = ambientLight;
    ALChanged = true;
}

void PhongShader::setDirectionalLight(DirectionalLight directionalLight) {
    this->directionalLight = directionalLight;
}

void PhongShader::setSpecularIntensity(float specularIntensity) {
    this->specularIntensity = specularIntensity;
    SIChanged = true;
}

void PhongShader::setSpecularPower(float specularPower) {
    this->specularPower = specularPower;
    SPChanged = true;
}
