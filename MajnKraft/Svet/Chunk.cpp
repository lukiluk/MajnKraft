/* 
 * File:   Chunk.cpp
 * Author: robert
 * 
 * Created on December 3, 2014, 11:34 AM
 */

#include "Chunk.h"

Chunk::Chunk() {
}

Chunk::Chunk(const Chunk& orig) {
}

Chunk::~Chunk() {
}

InfoKocka* Chunk::getBlock(int x, int y, int z) {
    if (z >= 0 && z < 256)
        return this->cubes[x][y][z];
    return (InfoKocka*) - 1;
}

int Chunk::getChunkID() {
    return this->ID;
}

void Chunk::setCubes(InfoKocka**** cubes) {
    this->cubes = cubes;
}

void Chunk::draw(int offsetX, int offsetY) {
    for(int i=0; i < DLZKA_CHUNKU; i++){
        for(int j=0; j < SIRKA_CHUNKU; j++){
            for(int k=0; k < VYSKA_CHUNKU; k++){
                cubes[i][j][k]->draw(i+(offsetX*DLZKA_CHUNKU), j+(offsetY*SIRKA_CHUNKU), k);
            }
        }
    }
}
