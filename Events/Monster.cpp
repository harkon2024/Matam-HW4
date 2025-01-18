//
// Created by harry cohen on 2025-01-13.
//
#include "Monster.h"


int Monster::getCombatPower() const{
    return force + level;
}

 void Monster::winBattle(){
     return;
}

void Monster::loseBattle(){
    return;
}

 int Monster::getLoot() const{
    return loot;
}

int Monster::getDamage() const{
    return damage;
}
