/* 
 * File:   KockaZeme.cpp
 * Author: robert
 * 
 * Created on December 3, 2014, 1:08 PM
 */

#include "KockaZeme.h"

KockaZeme::KockaZeme() {
}

KockaZeme::KockaZeme(const KockaZeme& orig) {
}

KockaZeme::~KockaZeme() {
}
void KockaZeme::draw(double x, double y, double z){
    GObject grafika = GObject(CUBE,TEXTUREBASIC);
    grafika.setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
    ,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
//    grafika.drawTo(x,y,z);
}
void KockaZeme::update(){}

