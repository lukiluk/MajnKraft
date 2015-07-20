#define GLEW_STATIC
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <vector>
#include "MeshCube.h"

MeshCube::MeshCube() {
    // Create Vertex Array Object
    glGenVertexArrays(1, &vao); //vytvori identifikator pola vertexov
    glBindVertexArray(vao); //prikaze pouzivat zadane pole  vertexov

    //Create index buufer object
    glGenBuffers(1, &ibo); //vytvori identifikator buffra indexou
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo); //prikaze pouzivat zadane buffra  indexou
    
    // Create a Vertex Buffer Object and copy the vertex data to it
    glGenBuffers(1, &vbo);  //vytvori identifikator buffera
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //urci typ bufera a prikaze pouzivat zadany  buffer
    
    verticies.push_back(Vertex( 0.5f, -0.5f, -0.5f));
    verticies.push_back(Vertex( 0.5f, -0.5f,  0.5f));
    verticies.push_back(Vertex(-0.5f, -0.5f,  0.5f));
    verticies.push_back(Vertex(-0.5f, -0.5f, -0.5f));
    verticies.push_back(Vertex( 0.5f,  0.5f, -0.5f));
    verticies.push_back(Vertex( 0.5f,  0.5f,  0.5f));
    verticies.push_back(Vertex(-0.5f,  0.5f,  0.5f));
    verticies.push_back(Vertex(-0.5f,  0.5f, -0.5f));
}

void MeshCube::draw(GLuint shaderProgram) {         //stale nieviem podrobne co to robi
// Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");       //nacita z shaderu poziciu premmennej position
    glEnableVertexAttribArray(posAttrib);                                   //umozni vyuzitie posAttrib pri vykreslovani glDrawArrays or glDrawElements.
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);    //specifies the location and data format of the array of generic vertex attributes at index index to use when rendering

    GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    
    GLint normAttrib = glGetAttribLocation(shaderProgram, "normal");
    glEnableVertexAttribArray(normAttrib);
    glVertexAttribPointer(normAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

    GLint uniColor = glGetUniformLocation(shaderProgram, "baseColor");
    glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);    //nastavi v shadery uniColor na danu  hodnotu
    
    glDrawArrays(GL_TRIANGLES, 0, 36);      //vykresli buffer ako trojuhoniky
    
    glDisableVertexAttribArray(posAttrib); //opak EnableVertexArray
    glDisableVertexAttribArray(texAttrib);
    glDisableVertexAttribArray(normAttrib);
    glDisableVertexAttribArray(uniColor);
}

/*void  MeshCube::selectCubeBack(){
    GLfloat cubeBack[] = {                                  //body kocky ktore sa spajaju
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
       -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
       -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
       -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
    };

    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeBack[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra
}
void  MeshCube::selectCubeFront(){
    GLfloat cubeFront[] = {                                  //body kocky ktore sa spajaju
       -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    };
    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeFront[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra        
}
void  MeshCube::selectCubeRight(){
    GLfloat cubeRight[] = {                                  //body kocky ktore sa spajaju
        0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
    };
    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeRight[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra       
}
void  MeshCube::selectCubeLeft(){
    GLfloat cubeLeft[] = {                                  //body kocky ktore sa spajaju
        -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    };
    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeLeft[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra        
}
void  MeshCube::selectCubeTop(){
    GLfloat cubeTop[] = {                                  //body kocky ktore sa spajaju
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, 0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
    };
    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeTop[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra       
}
void  MeshCube::selectCubeBottom(){
    GLfloat cubeBottom[] = {                                  //body kocky ktore sa spajaju
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
       -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
       -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
       -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
    };
    for (int i = 0; i < VERCITIESLENGHT; i++) {
        vertices[i]=cubeBottom[i];
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //nacita body do buffra        
}

*/
MeshCube::~MeshCube() {
    glDeleteBuffers(1, &vbo);           //uvolni buffer
    glDeleteVertexArrays(1, &vao);      //uvolni pole vertexov
}
