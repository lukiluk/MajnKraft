/* 
 * File:   KockaVzduchu.h
 * Author: robert
 *
 * Created on December 3, 2014, 1:23 PM
 */

#ifndef KOCKAVZDUCHU_H
#define	KOCKAVZDUCHU_H
#include "Kocka.h"
#include "../../Graphic/GObject.h"
class KockaVzduchu : public Kocka{
public:
    KockaVzduchu();
    KockaVzduchu(const KockaVzduchu& orig);
    virtual ~KockaVzduchu();
    
    virtual void draw(double x, double y, double z);
    virtual void update();
private:

};

#endif	/* KOCKAVZDUCHU_H */

