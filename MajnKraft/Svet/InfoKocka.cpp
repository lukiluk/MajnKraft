/* 
 * File:   InfoKocka.cpp
 * Author: robert
 * 
 * Created on December 3, 2014, 11:30 AM
 */

#include "InfoKocka.h"

InfoKocka::InfoKocka() {
}

InfoKocka::InfoKocka(Kocka* kocka, bool viditelnost){
    this->typ = kocka;
    this->viditelnost = viditelnost;
}

InfoKocka::InfoKocka(const InfoKocka& orig) {
}

InfoKocka::~InfoKocka() {
}

