//
// Created by harry cohen on 2025-01-13.
//

#include "Monster.h"
#include "Slime.h"
#include "Balrog.h"
#include "Snail.h"
#include "Pack.h"

std::unique_ptr<Monster> Monster::createMonster(const std::string& monsterName) {
    if (monsterName == "Snail") {
        return std::unique_ptr<Monster>(new Snail());
    } else if (monsterName == "Slime") {
        return std::unique_ptr<Monster>(new Slime());
    }else if (monsterName == "Balrog") {
            return std::unique_ptr<Monster>(new Balrog());
        }
    else if (monsterName == "Pack") {
        return std::unique_ptr<Monster>(new Pack());

    } else {
        throw std::invalid_argument("Unknown monster type: " + monsterName);
    }
}

std::unique_ptr<Monster> Monster::createPackMonster(Pack* pack) {
    return std::unique_ptr<Monster>(new Pack());
}

int Monster::getCombatPower() const{
    return force + level;
}

 void Monster::winBattle(){
     return;
}

void Monster::loseBattle(){
    return;
}

 int Monster::getLoot() const{
    return loot;
}

int Monster::getDamage() const{
    return damage;
}

int Monster::getLevel() const{
    return level;
}

std::string Monster::getName() const{
    return name;
}

Monster::Monster(const std::string& name, int level, int force,int loot,int damage):name(name),level(level),
force(force), loot(loot),damage(damage){}

Monster::~Monster() {}

int Monster::getMemberCount() const {
    return 1;
}