//
// Created by harry cohen on 2025-01-13.
//
#include "SolarEclipse.h"


void SolarEclipse::operator()(unique_ptr<Player> & player){
    int effect;
    if(player -> getJob() -> isMagical()){
        effect = 1;
        player -> getJob() -> addForce(effect);
    }else{
        effect = -1;
        player -> getJob() -> addForce(effect);
    }
    m_outcome = getSolarEclipseMessage(*player, effect);
}