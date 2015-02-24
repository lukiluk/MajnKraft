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

void Chunk::draw(int offsetX, int offsetY) {
    for(int i=0; i < DLZKA_CHUNKU; i++){
        for(int j=0; j < SIRKA_CHUNKU; i++){
            for(int k=0; k < VYSKA_CHUNKU; k++){
                castSveta[i][j][k]->draw(i+(offsetX*DLZKA_CHUNKU), j+(offsetY*SIRKA_CHUNKU), k);
            }
        }
    }
}
