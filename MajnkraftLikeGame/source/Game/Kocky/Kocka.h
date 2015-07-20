/* 
 * File:   Kocka.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:16 PM
 */

#ifndef KOCKA_H
#define	KOCKA_H

class Kocka{
public :
    virtual ~Kocka() {}
    virtual void draw(double x,double y,double z) = 0;
};

#endif	/* KOCKA_H */

