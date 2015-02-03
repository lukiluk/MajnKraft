#define GLEW_STATIC
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>
#include <glm/gtx/transform.hpp>
#include "Transformation.h"

Transformation::Transformation() {
}
Transformation::Transformation(const Transformation& orig){
    
}
/*Orotuje objekt o dane mnozstvo a posle udaje shaderu*/
void Transformation::rotate(float rotateAmtX,float rotateAmtY ,GLuint shaderProgram) {
    trans = glm::rotate(
            trans,
            rotateAmtX,
            glm::vec3(0.0f, 1.0f, 0.0f)
        ); 
    trans = glm::rotate(
            trans,
            rotateAmtY ,
            glm::vec3(1.0f, 0.0f, 0.0f)
        );
        // Draw cube
     uniTrans = glGetUniformLocation(shaderProgram, "trans");
     glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}

void Transformation::move(float x,float y,float z,GLuint shaderProgram){
    trans = glm::translate(glm::vec3(x,y,z)); 
        // Draw cube
     uniTrans = glGetUniformLocation(shaderProgram, "trans");
     glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}

Transformation::~Transformation() {
}

