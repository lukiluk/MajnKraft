/* 
 * File:   Transformation.h
 * Author: Lukas
 *
 * Created on Utorok, 2014, november 18, 23:43
 */

#ifndef TRANSFORMATION_H
#define	TRANSFORMATION_H

class Transformation {
public:
    Transformation();
    Transformation(const Transformation& orig);
    void rotate(float rotateAmtX,GLuint);
    virtual ~Transformation();
private:
    GLint uniTrans;
    GLint uniView;
    GLint uniProj;
    glm::mat4 view;
    glm::mat4 proj;
};

#endif	/* TRANSFORMATION_H */

