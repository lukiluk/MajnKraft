/* 
 * File:   GeneratorSveta.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:30 PM
 */

#ifndef GENERATORSVETA_H
#define	GENERATORSVETA_H

#include "../Struktury.h"

class GeneratorSveta {
public:
    GeneratorSveta();
    GeneratorSveta(const GeneratorSveta& orig);
    virtual ~GeneratorSveta();
    Chunk* nacitaj();
    
private:
    Chunk* generuj();
    Chunk* nacitajZDisku();

};

#endif	/* GENERATORSVETA_H */

