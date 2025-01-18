//
// Created by harry cohen on 2025-01-13.
//
#include "PotionsMerchant.h"


void PotionsMerchant::operator()(unique_ptr<Player> & player){
    player -> buyPotions();
};