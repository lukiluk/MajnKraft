/* 
 * File:   TextureBasicShader.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2015, marec 3, 17:06
 */

#define GLSL(src) "#version 330 core\n" #src
#include "TextureBasicShader.h"

TextureBasicShader::TextureBasicShader() {

    createShaders(
            //vertexShader
            GLSL(
            uniform mat4 trans;
            uniform mat4 view;
            uniform mat4 proj;
            uniform vec3 overrideColor;

            in vec3 position;
            in vec3 color;
            in vec2 texcoord;

            out vec3 Color;
            out vec2 Texcoord;

            void main() {
                Color = overrideColor * color;
                Texcoord = texcoord;
                gl_Position = proj * view * trans * vec4(position, 1.0);
            })
            ,
    //fragmentShader
    GLSL(
            uniform sampler2D tex0;
            uniform sampler2D tex1;

            in vec3 Color;
            in vec2 Texcoord;

            out vec4 outColor;

            void main() {
                 outColor = mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) * vec4(Color, 1.0);
            }
    )

    );
    
    addUniform("trans");
    addUniform("view");
    addUniform("proj");
    addUniform("overrideColor");
}



TextureBasicShader& TextureBasicShader::getInstance() {
    static TextureBasicShader instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}





