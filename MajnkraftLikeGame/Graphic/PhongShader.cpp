/* 
 * File:   PhongShader.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2015, marec 3, 17:06
 */

#define GLSL(src) "#version 330 core\n" #src
#include "PhongShader.h"

PhongShader::PhongShader() {

    createShaders(
            //vertexShader
            GLSL(
            uniform mat4 trans;
            uniform mat4 view;
            uniform mat4 proj;

            in vec3 position;
            in vec2 texcoord;
            in vec3 normal;
            out vec2 Texcoord;
            out vec3 normal0;
            out vec3 worldPos0;

            void main() {
                Texcoord = texcoord;
                gl_Position = proj * view * trans * vec4(position, 1.0);
                normal0 = (trans * vec4(normal,0.0f)).xyz;
                worldPos0 = (trans * vec4(position,1.0f)).xyz;
            })
            ,
    //fragmentShader
    GLSL(
                    
            struct BaseLight{
                vec3 color;
                float intensity;
            };
            
            struct DirectionalLight{
                BaseLight base;
                vec3 direction;
            };
            
            uniform sampler2D tex0;
            uniform sampler2D tex1;
            uniform vec3 baseColor;
            uniform vec3 ambientLight;
            uniform DirectionalLight directionalLight;
            uniform float specularIntensity;
            uniform float specularPower;
            uniform vec3 eyePos;
            
            in vec2 Texcoord;
            in vec3 normal0;
            in vec3 worldPos0;
            out vec4 pixel;

            vec4 calcLight(BaseLight base,vec3 direction,vec3 normal){
                float difuseFactor=dot(normal,-direction);
                vec4 difuseColor = vec4(0,0,0,0);
                vec4 specularColor = vec4(0,0,0,0);
                if(difuseFactor>0){
                    difuseColor = vec4(base.color,1.0)*base.intensity*difuseFactor;
                
                    vec3 directionToEye = normalize(eyePos - worldPos0);
                    vec3 reflectDirection = normalize(reflect(direction,normal));
                    float specularFactor = dot(directionToEye,reflectDirection);
                    specularFactor = pow(specularFactor,specularPower);
                    if(specularFactor>0){
                        specularColor = vec4(base.color,1.0f) * specularIntensity * specularFactor;
                    }
                    
                }
                return difuseColor + specularColor;
            }
            
            vec4 calcDirectionalLight(DirectionalLight directionalLight,vec3 normal){
                return calcLight(directionalLight.base,directionalLight.direction,normal);
            }
            
            void main() {
                vec4 totalLight = vec4(ambientLight,1);
                vec4 color = vec4(baseColor,1);
                if(color != vec4(0,0,0,0)){
                    color *= mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) ;
                }
                vec3 normal = normalize(normal0);
                totalLight += calcDirectionalLight(directionalLight,normal);
                pixel = color*totalLight;
            }
    )

    );
    
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
}



PhongShader& PhongShader::getInstance() {
    static PhongShader instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}



