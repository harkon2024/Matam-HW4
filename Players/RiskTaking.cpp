//
// Created by harry cohen on 2025-01-14.
//

#include "RiskTaking.h"


void RiskTaking::buyPotions(int& coins,int& currentHp,int maxHp ){
    if(currentHp < 50){
        coins -= 5;
        currentHp += 10;
        if(currentHp > maxHp) currentHp = maxHp;
    }
}

std::string RiskTaking::getCharacterName() const{
    return "Risk Taking";
}