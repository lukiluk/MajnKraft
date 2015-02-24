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
    Chunk testovaci = Chunk();
    InfoKocka**** svet;
    
    svet = new InfoKocka***[testovaci.DLZKA_CHUNKU];
    for(int x = 0; x < testovaci.DLZKA_CHUNKU; x++){
        svet[x] = new InfoKocka**[testovaci.SIRKA_CHUNKU];
        for(int y = 0; y < testovaci.SIRKA_CHUNKU; y++){
            svet[x][y] = new InfoKocka*[testovaci.VYSKA_CHUNKU];
            for(int z = 0; z < testovaci.VYSKA_CHUNKU; z++){
                if(z >=0 && z < 60){
                    svet[x][y][z] = new InfoKocka(this->kockaKamena,false);
                }else if(z == 60){
                    svet[x][y][z] = new InfoKocka(this->kockaZeme,false);
                }else if(z == 61){
                    svet[x][y][z] = new InfoKocka(this->kockaTravy,true);
                }else{
                    svet[x][y][z] = new InfoKocka(this->kockaVzduchu,true);
                }
            }
        }
    }
    
    testovaci.setSvet(svet);
    return &testovaci;
}
