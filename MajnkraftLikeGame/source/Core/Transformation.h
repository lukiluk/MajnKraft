/* 
 * File:   Transformation.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:43
 */

#ifndef TRANSFORMATION_H
#define	TRANSFORMATION_H
#include <glm/glm.hpp>
class Transformation {
public:
    Transformation();
    Transformation(const Transformation& orig);
    void rotate(float rotateAmtX,float rotateAmtY,float rotateAmtZ);
    void move(float x,float y,float z);
    void apply(GLuint shaderProgram);
    virtual ~Transformation();

    float getPosX() const { return posX;}
    float getPosY() const { return posY;} 
    float getPosZ() const { return posZ;} 
    float getRotX() const { return rotX;}
    float getRotY() const { return rotY;}
    float getRotZ() const { return rotZ;}
    float getScaleX() const { return scaleX;}
    float getScaleY() const { return scaleY;}
    float getScaleZ() const { return scaleZ;}
    void setPosX(float posX) { this->posX = posX;}
    void setPosY(float posY) { this->posY = posY;}
    void setPosZ(float posZ) { this->posZ = posZ;}
    void setRotX(float rotX) { this->rotX = rotX;}
    void setRotY(float rotY) { this->rotY = rotY;}
    void setRotZ(float rotZ) { this->rotZ = rotZ;}
    void setScaleX(float scaleX) { this->scaleX = scaleX;}
    void setScaleY(float scaleY) { this->scaleY = scaleY;}
    void setScaleZ(float scaleZ){ this->scaleZ = scaleZ;}
    
private:
    float posX;
    float posY;
    float posZ;
    float rotX;
    float rotY;
    float rotZ;
    float scaleX;
    float scaleY;
    float scaleZ;
    
};

#endif	/* TRANSFORMATION_H */

