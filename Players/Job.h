//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_JOB_H
#define MATAM_HW4_JOB_H

#include "Monster.h"
class Player;

class Job{

public:
    virtual bool isMagical() = 0;

    virtual void winBattle(Player& player, const Monster& monster) =0;

    virtual void loseBattle(Player& player, const Monster& monster) = 0;

    virtual int addForce(int,Player& player) const = 0;

    virtual int getMaxhp() const =0;

    virtual int getStartingCoins() const = 0;

    virtual int getCombatPower(Player& player) = 0;

    virtual std::string getJobName() const = 0;

    virtual ~Job()= default;

    static std::shared_ptr<Job> createJob(const std::string& jobName);

};
#endif //MATAM_HW4_JOB_H
