/* 
 * File:   Chunk.h
 * Author: robert
 *
 * Created on December 3, 2014, 11:34 AM
 */

#ifndef CHUNK_H
#define	CHUNK_H

#include "InfoKocka.h"

class Chunk {
public:
    static const int DLZKA_CHUNKU = 16;
    static const int SIRKA_CHUNKU = 16;
    static const int VYSKA_CHUNKU = 256;
    Chunk();
    Chunk(const Chunk& orig);
    virtual ~Chunk();
    
    InfoKocka* getBlock(int x, int y, int z);
    
    void setCubes(InfoKocka**** castSveta);
    
    int getChunkID();
    void draw(int offsetX, int offsetY);
    

private:
    InfoKocka**** cubes;
    int ID;

};

#endif	/* CHUNK_H */

