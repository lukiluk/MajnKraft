/* 
 * File:   KockaTravy.cpp
 * Author: robert
 * 
 * Created on November 26, 2014, 12:19 PM
 */

#include "KockaTravy.h"

KockaTravy::KockaTravy() {
}

KockaTravy::KockaTravy(const KockaTravy& orig) {
}

KockaTravy::~KockaTravy() {
}

void KockaTravy::draw(double x, double y, double z){
    GObject grafika = GObject(CUBE,TEXTUREBASIC);
    grafika.setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
    ,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
   // grafika.drawTo(x,y,z);
}

void KockaTravy::update(){
    
}