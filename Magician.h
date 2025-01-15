//
// Created by harry cohen on 2025-01-14.
//

#ifndef MATAM_HW4_MAGICIAN_H
#define MATAM_HW4_MAGICIAN_H
#include "Job.h"
class Magician : public Job {

public:

    Magician();

    ~Magician() override = default;

    void winBattle(Player& player, const Monster& monster) override;

    void loseBattle(Player& player, const Monster& monster) override;

    int addForce(int, Player& player) const override;

    int getMaxhp() const override;

    int getStartingCoins() const override;

    bool isMagical() override;

    int getCombatPower(Player& player) override;

    std::string getJobName() const override;

};
#endif //MATAM_HW4_MAGICIAN_H
