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
#include <map>
#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <string>

class Shader
{
private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    std::map<std::string,int> uniforms;
    void checkShader(GLuint shader,GLuint flag,bool isProgram);
protected:
    static constexpr const char* SHADER_PATH = "resources/shader/";
    static constexpr const char* FRAGMENT_EXTENSION = "f";
    static constexpr const char* VERTEX_EXTENSION = "v";
public:
	Shader();
	void createShaders(std::string vertexSource,std::string fragmentSource);
        std::string loadShader(const std::string filename);
        void bindProgram();
        void addUniform(std::string name);
        void setUniform(std::string name,int value);
        void setUniform(std::string name,float value);
        void setUniform(std::string name,glm::vec3 value);
        void setUniform(std::string name,glm::mat4 value);
	~Shader();
        
    GLuint getShaderProgram() const;

};
#endif	/* SHADER_H */

