/* 
 * File:   Camera.h
 * Author: Lukas
 *
 * Created on Streda, 2014, december 31, 2:28
 */

#ifndef CAMERA_H
#define	CAMERA_H
#include "glm/glm.hpp"
#include "GL/glew.h"

class Camera {
public:
    Camera(float fov,float aspect,float minDistance,float maxDist,GLint shader);
    void cameraPosition(float x,float y,float z);
    void lookAtPosition(float x,float y,float z);
    void update(glm::vec3 position,glm::vec3 fowardVector,glm::vec3 upVector);
    virtual ~Camera();
private:
    glm::vec3 position;
    glm::vec3 upVector;
    glm::vec3 fowardVector;
    glm::mat4 view;
    GLint shaderProgram;
};

#endif	/* CAMERA_H */

