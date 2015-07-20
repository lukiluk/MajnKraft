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

#include "Vertex.h"

class MeshCube {
private:
    GLuint vao;
    GLuint ibo;
    GLuint vbo;
    std::vector<Vertex> verticies;
    std::vector<int> indecies;
    std::vector<int> normals;

public:
    MeshCube();
    void loadCube();
    void draw(GLuint shaderProgram);
    
    void selectCube();
    void selectCubeBack();
    void selectCubeFront();
    void selectCubeRight();
    void selectCubeLeft();
    void selectCubeTop();
    void selectCubeBottom();
    
    void selectTestPlane();
    
    ~MeshCube();
};


#endif	/* MESH_H */

