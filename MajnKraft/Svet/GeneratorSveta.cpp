/* 
 * File:   GeneratorSveta.cpp
 * Author: robert
 * 
 * Created on November 26, 2014, 12:30 PM
 */

#include "GeneratorSveta.h"
#include "../Kocky/Kocka.h"

GeneratorSveta::GeneratorSveta() {
    this->kockaTravy = new KockaTravy();
    this->kockaKamena = new KockaKamena();
    this->kockaZeme = new KockaZeme();
    this->kockaVzduchu = new KockaVzduchu();
}

GeneratorSveta::GeneratorSveta(const GeneratorSveta& orig) {
}

GeneratorSveta::~GeneratorSveta() {
}

Chunk* GeneratorSveta::generuj(){
    Chunk testChunk = Chunk();
    InfoKocka**** cubes;
    
    cubes = new InfoKocka***[testChunk.DLZKA_CHUNKU];
    for(int x = 0; x < testChunk.DLZKA_CHUNKU; x++){
        cubes[x] = new InfoKocka**[testChunk.SIRKA_CHUNKU];
        for(int y = 0; y < testChunk.SIRKA_CHUNKU; y++){
            cubes[x][y] = new InfoKocka*[testChunk.VYSKA_CHUNKU];
            for(int z = 0; z < testChunk.VYSKA_CHUNKU; z++){
                if(z >=0 && z < 60){
                    cubes[x][y][z] = new InfoKocka(this->kockaKamena,true);
                }else if(z == 60){
                    cubes[x][y][z] = new InfoKocka(this->kockaZeme,true);
                }else if(z == 61){
                    cubes[x][y][z] = new InfoKocka(this->kockaTravy,true);
                }else{
                    cubes[x][y][z] = new InfoKocka(this->kockaVzduchu,true);
                }
            }
        }
    }
    
    testChunk.setCubes(cubes);
    return &testChunk;
}
