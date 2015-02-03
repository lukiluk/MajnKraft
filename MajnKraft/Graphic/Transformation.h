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
    void rotate(float rotateAmtX,float rotateAmtY,GLuint);
    void move(float x,float y,float z,GLuint shaderProgram);
    virtual ~Transformation();
private:
    GLint uniTrans;
    GLint uniView;
    GLint uniProj;
    glm::mat4 view;
    glm::mat4 proj;
    glm::mat4 trans;
};

#endif	/* TRANSFORMATION_H */

