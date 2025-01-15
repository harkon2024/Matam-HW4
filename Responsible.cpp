//
// Created by harry cohen on 2025-01-14.
//

#include "Responsible.h"
void Responsible::buyPotions(int& coins,int& currentHp,int maxHp ) {

    while(coins >= 5 && currentHp < maxHp){
        coins -= 5;
        currentHp += 10;
        if(currentHp > maxHp) currentHp = maxHp;
    }
}

std::string Responsible::getCharacterName() const{
    return "Responsible";
}