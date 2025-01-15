//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_MONSTER_H
#define MATAM_HW4_MONSTER_H
class Monster{
protected:
    int force, level, loot,damage;

public:


    Monster(int, int,int,int);

    virtual int getCombatPower() const;

    virtual void winBattle();

    virtual void loseBattle();

    virtual int getLoot() const;

    virtual int getDamage() const;

    virtual ~Monster();


};
#endif //MATAM_HW4_MONSTER_H
