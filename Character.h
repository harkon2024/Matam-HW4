//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_CHARACTER_H
#define MATAM_HW4_CHARACTER_H
#include "Player.h"
class Character{

public:
    virtual void buyPotions(int& coins,int& currentHp, int maxHp) = 0;

    virtual std::string getCharacterName() const =0;

    virtual ~Character()= default;

};
#endif //MATAM_HW4_CHARACTER_H
