/* 
 * File:   Mesh.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 22:56
 */

#ifndef MESH_H
#define	MESH_H
#define GLEW_STATIC
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
class Mesh
{
private:
        GLuint vao;
        GLuint vbo;
public:
	Mesh();
	void loadCube();
	void draw(GLuint shaderProgram);
	~Mesh();
};


#endif	/* MESH_H */

