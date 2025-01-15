//
// Created by harry cohen on 2025-01-13.
//
#include "SolarEclipse.h"


void SolarEclipse::operator()(unique_ptr<Player> & player){
    if(player -> getJob() -> isMagical()){
        player -> getJob() -> addForce(1);
    }else{
        player -> getJob() -> addForce(-1);
    }
}