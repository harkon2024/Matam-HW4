//
// Created by harry cohen on 2025-01-14.
//

#ifndef MATAM_HW4_RESPONSIBLE_H
#define MATAM_HW4_RESPONSIBLE_H
#include "Character.h"
class Responsible : public Character {

public:

    Responsible();

    ~Responsible() override = default;

    void buyPotions(int& coins,int& currentHp,int maxHp ) override;

    std::string getCharacterName() const override;

};
#endif //MATAM_HW4_RESPONSIBLE_H
