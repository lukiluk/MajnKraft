/* 
 * File:   KockaKamena.cpp
 * Author: robert
 * 
 * Created on December 3, 2014, 1:08 PM
 */

#include "KockaKamena.h"

KockaKamena::KockaKamena() {
    //kocka2 = new GObject(CUBE,TEXTURECLASSIC);
    object = new GObject(CUBE,TEXTUREBASIC);
   object->setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
    ,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
}

KockaKamena::KockaKamena(const KockaKamena& orig) {
}

KockaKamena::~KockaKamena() {
}

void KockaKamena::draw(double x, double y, double z){
//   object->drawTo(x,y,z);
}
void KockaKamena::update(){
}

