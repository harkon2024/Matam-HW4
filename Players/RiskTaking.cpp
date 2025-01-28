//
// Created by harry cohen on 2025-01-14.
//

#include "RiskTaking.h"


int RiskTaking::buyPotions(int& coins,int& currentHp,int maxHp ){
    int count = 0;
    if(currentHp < 50){
        coins -= 5;
        currentHp += 10;
        count++;
        if(currentHp > maxHp){ currentHp = maxHp;}
    }
    return count;
}

std::string RiskTaking::getCharacterName() const{
    return "RiskTaking";
}

RiskTaking::RiskTaking() {
}