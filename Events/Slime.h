//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_SLIME_H
#define MATAM_HW4_SLIME_H
#include "Monster.h"
class Slime : public Monster {

public:

    Slime();

    ~Slime() override = default;

    void winBattle() override;

    void loseBattle() override;


};
#endif //MATAM_HW4_SLIME_H
