//
// Created by harry cohen on 2025-01-13.
//
#include "PotionsMerchant.h"
#include "Utilities.h"

void PotionsMerchant::operator()(Player & player){
    int amountPurchased = player.buyPotions();
    m_outcome = getPotionsPurchaseMessage(player, amountPurchased);
}

std::string PotionsMerchant::getDescription() const {
return "Potions"
       "Merchant";
}