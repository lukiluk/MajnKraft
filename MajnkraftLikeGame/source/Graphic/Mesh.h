/* 
 * File:   Mesh.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 22:56
 */

#ifndef MESH_H
#define	MESH_H
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

class Mesh {
private:
    static const int VERCITIESLENGHT = 48;
    GLuint vao;
    GLuint ibo;
    GLuint vbo;
    GLfloat vertices[VERCITIESLENGHT];


public:
    Mesh();
    void loadCube();
    void draw(GLuint shaderProgram);
    ~Mesh();
    void selectCube();
    void selectCubeBack();
    void selectCubeFront();
    void selectCubeRight();
    void selectCubeLeft();
    void selectCubeTop();
    void selectCubeBottom();
    
    void selectTestPlane();
};


#endif	/* MESH_H */

