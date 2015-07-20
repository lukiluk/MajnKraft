/* 
 * File:   KockaTravy.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:19 PM
 */

#ifndef KOCKATRAVY_H
#define	KOCKATRAVY_H

#include "Kocka.h"
#include "../../Graphic/GObject.h"

class KockaTravy : public Kocka{
public:
    KockaTravy();
    KockaTravy(const KockaTravy& orig);
    virtual ~KockaTravy();
    
    virtual void draw(double x, double y, double z);
    virtual void update();
private:

};

#endif	/* KOCKATRAVY_H */

