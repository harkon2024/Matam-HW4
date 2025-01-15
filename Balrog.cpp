//
// Created by harry cohen on 2025-01-13.
//
#include "Balrog.h"


Balrog::Balrog():Monster(1,15,100,9001){

}

void Balrog::winBattle(){
    level+=2;
}

void Balrog::loseBattle(){
    level+=2;
}




