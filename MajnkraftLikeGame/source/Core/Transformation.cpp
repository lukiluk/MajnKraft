#define GLEW_STATIC
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>
#include <glm/gtx/transform.hpp>
#include "Transformation.h"

Transformation::Transformation() :posX(0.0f), posY(0.0f), posZ(0.0f),
        rotX(0.0f), rotY(0.0f), rotZ(0.0f),
        scaleX(1.0f), scaleY(1.0f),scaleZ(1.0f)
{
}

Transformation::Transformation(const Transformation& orig){
    
}

void Transformation::rotate(float rotateAmtX,float rotateAmtY ,float rotateAmtZ) {
    rotX=rotateAmtX;
    rotY=rotateAmtY;
    rotZ=rotateAmtZ;
}

void Transformation::move(float x,float y,float z){
    posX=x;
    posY=y;
    posZ=z;
}

void Transformation::apply(GLuint shaderProgram){
    glm::mat4 posMatrix= glm::translate(glm::vec3(posX,posY,posZ));
    glm::mat4 rotXMatrix = glm::rotate(rotX,glm::vec3(1.0f, 0.0f, 0.0f));   //orotuje o dane monozstvo, okolo danej osi 
    glm::mat4 rotYMatrix = glm::rotate(rotY,glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotZMatrix = glm::rotate(rotZ,glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 scaleMatrix = glm::scale(glm::vec3(scaleX,scaleY,scaleZ));
    glm::mat4 rotMatrix= rotZMatrix*rotYMatrix*rotXMatrix;                  //zisti finalnu rotacnu maticu
    glm::mat4 trans=posMatrix*rotMatrix*scaleMatrix;                                  //zisti finalnu maticu modelu
    GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");                //najde premmennu s nazvom trans
    glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));       //posle maticu modelu ako pointer
}

Transformation::~Transformation() {
}

