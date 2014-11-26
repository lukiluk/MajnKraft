/* 
 * File:   Struktury.h
 * Author: robert
 *
 * Created on November 26, 2014, 12:24 PM
 */

#ifndef STRUKTURY_H
#define	STRUKTURY_H

#include "Kocky/Kocka.h"

struct InfoKocka{
    Kocka* typ;
    bool viditelnost;
};

struct Chunk{
    InfoKocka*** castSveta;
    int ID;
};

#endif	/* STRUKTURY_H */

