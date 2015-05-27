/* 
 * File:   InfoKocka.h
 * Author: robert
 *
 * Created on December 3, 2014, 11:30 AM
 */

#ifndef INFOKOCKA_H
#define	INFOKOCKA_H

#include "../Kocky/Kocka.h"

class InfoKocka {
public:
    InfoKocka();
    InfoKocka(Kocka* kocka, bool viditelnost);
    InfoKocka(const InfoKocka& orig);
    virtual ~InfoKocka();
    
    Kocka* getTyp(){ return this->typ;}
    bool getViditelnost(){ return this->viditelnost;}
    void draw(int positionX, int positionY, int positionZ);
    
private:
    Kocka* typ;
    bool viditelnost;
};

#endif	/* INFOKOCKA_H */

