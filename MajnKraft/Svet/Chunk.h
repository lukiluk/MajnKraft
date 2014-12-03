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
    Chunk();
    Chunk(const Chunk& orig);
    virtual ~Chunk();
    
    InfoKocka* getBlock(int x, int y, int z) { 
        if (z >= 0 && z < 256)
            return &this->castSveta[x][y][z];
        return (InfoKocka*)-1;
    }
    
    int getChunkID(){ return this->ID; }
    

private:
    InfoKocka** castSveta[256];
    int ID;

};

#endif	/* CHUNK_H */

