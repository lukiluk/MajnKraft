/* 
 * File:   KockaKamena.h
 * Author: robert
 *
 * Created on December 3, 2014, 1:08 PM
 */

#ifndef KOCKAKAMENA_H
#define	KOCKAKAMENA_H
#include "Kocka.h"

class KockaKamena  : public Kocka{
public:
    KockaKamena();
    KockaKamena(const KockaKamena& orig);
    virtual ~KockaKamena();
    
    virtual void draw(double x, double y, double z);
    virtual void update();
private:

};

#endif	/* KOCKAKAMENA_H */

