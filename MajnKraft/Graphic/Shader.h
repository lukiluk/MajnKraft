/* 
 * File:   Shader.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:04
 */

#ifndef SHADER_H
#define	SHADER_H
//private:
class Shader
{
private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
public:
	Shader();
	void loadShader();
	~Shader();
        void checkShader(GLuint shader,GLuint flag,bool isProgram);
    GLuint getShaderProgram() const {
        return shaderProgram;
    }

};
#endif	/* SHADER_H */

