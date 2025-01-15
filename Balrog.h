//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_BALROG_H
#define MATAM_HW4_BALROG_H
#include "Monster.h"
class Balrog : public Monster {

public:

    Balrog();

    void winBattle() override;

    void loseBattle() override;

     ~Balrog()override = default;




};
#endif //MATAM_HW4_BALROG_H
