/* 
 * File:   KockaZeme.h
 * Author: robert
 *
 * Created on December 3, 2014, 1:08 PM
 */

#ifndef KOCKAZEME_H
#define	KOCKAZEME_H
#include "Kocka.h"
#include "../../Graphic/GObject.h"
class KockaZeme  : public Kocka{
public:
    KockaZeme();
    KockaZeme(const KockaZeme& orig);
    virtual ~KockaZeme();
    
    virtual void draw(double x, double y, double z);
    virtual void update();
private:

};

#endif	/* KOCKAZEME_H */

