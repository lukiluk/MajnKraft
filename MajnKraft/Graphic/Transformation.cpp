#define GLEW_STATIC
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>
#include "Transformation.h"

Transformation::Transformation() {
}
/*Orotuje objekt o dane mnozstvo a posle udaje shaderu*/
void Transformation::rotate(float rotateAmtX,GLuint shaderProgram) {
     glm::mat4 trans;
       trans = glm::rotate(
            trans,
            rotateAmtX * 2.0f,
              //  0.0f,
            glm::vec3(0.0f, 1.0f, 0.0f)
        ); 
        // Draw cube
     uniTrans = glGetUniformLocation(shaderProgram, "trans");
     glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}

Transformation::~Transformation() {
}

