//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_PACK_H
#define MATAM_HW4_PACK_H
#include "Monster.h"
#include <memory>
#include <vector>

using namespace std;

class Pack: public Monster {
    vector<unique_ptr<Monster>> members;

public:

    Pack();

    void addMonster(unique_ptr<Monster>&);

    void winBattle() override;

    void loseBattle() override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    ~Pack() override = default;

};
#endif //MATAM_HW4_PACK_H
