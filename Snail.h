//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_SNAIL_H
#define MATAM_HW4_SNAIL_H
#include "Monster.h"
class Snail : public Monster {

public:

    Snail();

    void winBattle() override;

    void loseBattle() override;

    ~Snail() override = default;


};
#endif //MATAM_HW4_SNAIL_H
