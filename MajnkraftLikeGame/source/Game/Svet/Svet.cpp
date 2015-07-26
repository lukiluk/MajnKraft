/* 
 * File:   Svet.cpp
 * Author: robert
 * 
 * Created on November 26, 2014, 12:27 PM
 */

#include "Svet.h"
#include "GeneratorSveta.h"

Svet::Svet() {
    nacitanySvet = GeneratorSveta().nacitaj();
}

Svet::Svet(const Svet& orig) {
}

Svet::~Svet() {
}

void Svet::draw() {
   // nacitanySvet = GeneratorSveta().nacitaj(); //docasne
    //nacitanySvet->draw(0,0);
}