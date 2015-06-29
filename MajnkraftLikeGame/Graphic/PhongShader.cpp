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
            out vec2 Texcoord;

            void main() {
                Texcoord = texcoord;
                gl_Position = proj * view * trans * vec4(position, 1.0);
            })
            ,
    //fragmentShader
    GLSL(
            uniform sampler2D tex0;
            uniform sampler2D tex1;
            uniform vec3 baseColor;
            uniform vec3 ambientLight;
            
            in vec2 Texcoord;
            out vec4 pixel;

            void main() {
                vec4 totalLight = vec4(ambientLight,1);
                vec4 color = vec4(baseColor,1);
                if(color != vec4(0,0,0,0)){
                    color *= mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) ;
                }
                pixel = color*totalLight;
            }
    )

    );
    
    addUniform("trans");
    addUniform("view");
    addUniform("proj");
    addUniform("baseColor");
    addUniform("ambientLight");
}



PhongShader& PhongShader::getInstance() {
    static PhongShader instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}



