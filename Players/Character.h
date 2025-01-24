//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_CHARACTER_H
#define MATAM_HW4_CHARACTER_H
#include "Player.h"
class Character{

public:
    virtual int buyPotions(int& coins,int& currentHp, int maxHp) = 0;

    virtual std::string getCharacterName() const =0;

    virtual ~Character()= default;

    static std::shared_ptr<Character> createCharacter(const std::string& characterName);

};
#endif //MATAM_HW4_CHARACTER_H
