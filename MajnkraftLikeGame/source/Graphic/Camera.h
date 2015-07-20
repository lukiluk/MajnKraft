/* 
 * File:   Camera.h
 * Author: Lukas
 *
 * Created on Streda, 2014, december 31, 2:28
 */

#ifndef CAMERA_H
#define	CAMERA_H
#include "glm/glm.hpp"
#define GLEW_STATIC
#include "GL/glew.h"

class Camera {
public:
    Camera();
    Camera(float fov,float aspect,float minDistance,float maxDist,GLint shader);
    void setCameraPosition(float x,float y,float z);
    glm::vec3 getCameraPosition();
    void setLookAtPosition(float x,float y,float z);
    void moveCameraLeft();
    void moveCameraRight();
    void moveCameraUp();
    void moveCameraDown();
    void moveCameraBack();
    void moveCameraFoward();
    void lookLeft();
    void lookRight();
    void lookUp();
    void lookDown();
    void setSensitivity(float);
    void update();
    
    float getAspectRatio() const;
    void setAspectRatio(float aspectRatio);
    float getFieldOfView() const;
    void setFieldOfView(float fieldOfView);
    float getMaxRenderDistance() const;
    void setMaxRenderDistance(float maxRenderDistance);
    float getMinRenderDistance() const;
    void setMinRenderDistance(float minRenderDistance);
    glm::mat4 getProjectionMatrix();
    
    glm::mat4 getViewMatrix();
    
    void move(glm::vec3 direction,float amt);
    void rotate(float angleX,float angleY);
    glm::vec3 getLeft();
    glm::vec3 getRight();
    
    virtual ~Camera();
private:
    
    float sensitivity;
    
    glm::vec3 position;
    glm::vec3 upVector = glm::vec3(0.0f,1.0f,0.0f);
    glm::vec3 fowardVector;
    glm::mat4 view;
    
    float fieldOfView;
    float aspectRatio;
    float minRenderDistance;
    float maxRenderDistance;
    glm::mat4 projectedMatrix;
    
    GLint shaderProgram;
};

#endif	/* CAMERA_H */

