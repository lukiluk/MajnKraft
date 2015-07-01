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
#include "BaseLight.h"
#include "DirectionalLight.h"
#include <glm/gtc/type_ptr.hpp>
#include <string>

class Shader
{
private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    std::map<std::string,int> uniforms;
    void checkShader(GLuint shader,GLuint flag,bool isProgram);
public:
	Shader();
	void createShaders(char* vertexSource,char* fragmentSource);
        void bindProgram();
        void addUniform(std::string name);
        void setUniform(std::string name,int value);
        void setUniform(std::string name,float value);
        void setUniform(std::string name,glm::vec3 value);
        void setUniform(std::string name,glm::mat4 value);
        void setUniform(std::string name,BaseLight baseLight);
        void setUniform(std::string name,DirectionalLight directionalLight);
	~Shader();
        
    GLuint getShaderProgram() const;

};
#endif	/* SHADER_H */

