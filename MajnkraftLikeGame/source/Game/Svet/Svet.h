/* 
 * File:   Svet.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:27 PM
 */

#ifndef SVET_H
#define	SVET_H

#include "Chunk.h"


class Svet {
public:
    Svet();
    Svet(const Svet& orig);
    virtual ~Svet();
    void draw();
    
private:
    Chunk* nacitanySvet;

};

#endif	/* SVET_H */

