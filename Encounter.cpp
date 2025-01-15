//
// Created by harry cohen on 2025-01-13.
//
#include "Encounter.h"


void Encounter::operator()(unique_ptr<Player> & player){
    if(monster-> getCombatPower() >= player -> getJob()-> getCombatPower()){
        player -> getJob()-> loseBattle(*player, *monster);
        monster -> winBattle();
    }else{
        player -> getJob()-> winBattle(*player, *monster);
        monster -> loseBattle();
    }
}