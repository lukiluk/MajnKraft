#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL_config.h>
#include "Shader.h"
#include <stdio.h>
#define GLSL(src) "#version 150 core\n" #src

Shader::Shader() {

}
/*Skontroluje shader na chyby*/
void Shader::checkShader(GLuint shader,GLuint flag,bool isProgram){
    GLint succes = 0;
    GLchar errorMsg[1024] = {0};
    (isProgram)?
        glGetProgramiv(shader,flag,&succes):
        glGetShaderiv(shader,flag,&succes);
    if(succes == GL_FALSE){
        (isProgram)?
        glGetProgramInfoLog(shader,sizeof(errorMsg),NULL,errorMsg):
        glGetShaderInfoLog(shader,sizeof(errorMsg),NULL,errorMsg);
        fprintf(stderr, errorMsg);
    }
}
/*Nacita textureShader*/
void Shader::loadShader() {
    //vytvori shader ktory urci body "trojuholnikov"
    const char* vertexSource = GLSL(
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
        }
    );

    vertexShader = glCreateShader(GL_VERTEX_SHADER);            //vytvori identifikator pre shader
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    Shader::checkShader(shaderProgram,GL_COMPILE_STATUS,false);
    
    // Create and compile the fragment shader
    const char* fragmentSource = GLSL(
        uniform sampler2D tex0;
        uniform sampler2D tex1;

        in vec3 Color;
        in vec2 Texcoord;

        out vec4 outColor;
        
        void main() {
            outColor = mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) * vec4(Color, 1.0);
        }
    );

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkShader(shaderProgram,GL_COMPILE_STATUS,false);
    // Link the vertex and fragment shader into a shader program
    shaderProgram = glCreateProgram();          //vytvori identifikator pre shader
    glAttachShader(shaderProgram, vertexShader);    //prideli k shaderu vertex shader
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");   //??
    glLinkProgram(shaderProgram);                       //zlinkuje shader
    checkShader(shaderProgram,GL_LINK_STATUS,true);
    glUseProgram(shaderProgram);                        //prikaze pouzivat shader
}


Shader::~Shader() {
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteProgram(shaderProgram);
}
