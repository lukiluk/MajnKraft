/* 
 * File:   Mesh.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 22:56
 */

#ifndef MESH_H
#define	MESH_H
#include <gl\glew.h>
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

