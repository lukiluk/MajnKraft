/* 
 * File:   Transformation.cpp
 * Author: Lukas
 * 
 * Created on Utorok, 2014, november 18, 23:43
 */
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transformation.h"

Transformation::Transformation() {
}

Transformation::Transformation(const Transformation& orig) {
}

void Transformation::transform(GLuint shaderProgram) {
    uniTrans = glGetUniformLocation(shaderProgram, "trans");

    view = glm::lookAt(
        glm::vec3(2.5f, 2.5f, 1.5f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );
    uniView = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
    uniProj = glGetUniformLocation(shaderProgram, "proj");
    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

void Transformation::rotate() {
     glm::mat4 trans;
        trans = glm::rotate(
            trans,
            //(float)sin(glfwGetTime()) * 2.0f,
                0.0f,
            glm::vec3(0.0f, 0.0f, 1.0f)
        );

        // Draw cube
     glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
}

Transformation::~Transformation() {
}

