/* 
 * File:   Shader.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:04
 */

#ifndef SHADER_H
#define	SHADER_H
//#define GLEW_STATIC
#include <GL/glew.h>
#include <stdio.h>
#include <map>
#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    std::map<char*,int> uniforms;
    void checkShader(GLuint shader,GLuint flag,bool isProgram);
public:
	Shader();
	void createShaders(char* vertexSource,char* fragmentSource);
        void bindProgram();
        void addUniform(char* name);
        void setUniformi(char* name,int value);
        void setUniformf(char* name,float value);
        void setUniformV3(char* name,glm::vec3 value);
        void setUniformM4(char* name,glm::mat4 value);
	~Shader();
        
    GLuint getShaderProgram() const;

};
#endif	/* SHADER_H */

