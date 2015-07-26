/* 
 * File:   GeneratorSveta.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:30 PM
 */

#ifndef GENERATORSVETA_H
#define	GENERATORSVETA_H

#include "Chunk.h"
#include "../Kocky/KockySpolocne.h"

class GeneratorSveta {
public:
    GeneratorSveta();
    GeneratorSveta(const GeneratorSveta& orig);
    virtual ~GeneratorSveta();
    //TODO - zmenit toto volanie, aby nacital len to co chceme a nie cely svet
    Chunk* nacitaj(){ return generuj();}
    
private:
    Kocka* kockaTravy;
    Kocka* kockaKamena;
    Kocka* kockaZeme;
    Kocka* kockaVzduchu;
    Chunk* generuj();
    Chunk* nacitajZDisku();

};

#endif	/* GENERATORSVETA_H */

