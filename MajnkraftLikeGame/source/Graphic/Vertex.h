/* 
 * File:   Vertex.h
 * Author: Lukas
 *
 * Created on Streda, 2015, júl 15, 22:23
 */

#ifndef VERTEX_H
#define	VERTEX_H

#include <glm/glm.hpp>

class Vertex {
public:
    static const int NUMBER_COUNT = 8;//2*VEC3 + VEC2
    
    Vertex();
    
    Vertex(glm::vec3 position);
    Vertex(glm::vec3 position, glm::vec2 texturePosition);
    Vertex(glm::vec3 position, glm::vec3 normal);
    Vertex(glm::vec3 position, glm::vec2 texturePosition, glm::vec3 normal);
    
    Vertex(float posX,float posY, float posZ);
    Vertex(float posX,float posY, float posZ, float textureX, float textureY);
    Vertex(float posX,float posY, float posZ, float normalX, float normalY, float normalZ);
    Vertex(float posX,float posY, float posZ, float textureX, float textureY, float normalX, float normalY, float normalZ);
    
    glm::vec3 GetNormal() const;
    glm::vec3 GetPosition() const;
    glm::vec2 GetTexturePosition() const;
    void SetNormal(glm::vec3 normal);
    void SetPosition(glm::vec3 position);
    void SetTexturePosition(glm::vec2 texturePosition);
    
    virtual ~Vertex();
    
private:
    glm::vec3 position;
    glm::vec2 texturePosition;
    glm::vec3 normal;
};

#endif	/* VERTEX_H */

