//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_MONSTER_H
#define MATAM_HW4_MONSTER_H
#include <memory>
#include <string>


class Pack;

class Monster{
protected:
    std::string name;
    int level, force, loot,damage;


public:


    Monster(const std::string& name, int level, int force,int loot,int damage);

    virtual int getCombatPower() const;

    virtual void winBattle();

    virtual void loseBattle();

    virtual int getLoot() const;

    virtual int getDamage() const;

    virtual int getLevel() const;

    std::string getName() const;

    virtual int getMemberCount() const;

    virtual ~Monster();

    static std::unique_ptr<Monster> createMonster(const std::string& monsterName);

    static std::unique_ptr<Monster> createPackMonster(Pack* pack);



};
#endif //MATAM_HW4_MONSTER_H
