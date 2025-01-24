//
// Created by harry cohen on 2025-01-14.
//

#ifndef MATAM_HW4_RISKTAKING_H
#define MATAM_HW4_RISKTAKING_H
#include "Character.h"
class RiskTaking : public Character {

public:

    RiskTaking();

    ~RiskTaking() override = default;

    std::string getCharacterName() const override;

    int buyPotions(int& coins,int& currentHp,int maxHp ) override;



};
#endif //MATAM_HW4_RISKTAKING_H
