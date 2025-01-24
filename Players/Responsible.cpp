//
// Created by harry cohen on 2025-01-14.
//

#include "Responsible.h"
int Responsible::buyPotions(int& coins,int& currentHp,int maxHp ) {
    int count = 0;
    while(coins >= 5 && currentHp < maxHp) {
        coins -= 5;
        currentHp += 10;
        if (currentHp > maxHp) {
            currentHp = maxHp;
        }
        count++;
    }
    return count;
}

std::string Responsible::getCharacterName() const{
    return "Responsible";
}

Responsible::Responsible() {
}