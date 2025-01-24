//
// Created by harry cohen on 2025-01-14.
//
#include "Magician.h"

void Magician::winBattle(Player& player, const Monster& monster){
    player.levelUp();
    int costs = 0;
    costs = monster.getLoot();
    player.addCoins(costs);
}

void Magician::loseBattle(Player& player, const Monster& monster){
    int damage =0;
    damage = monster.getDamage();
    player.takeDamage(damage);
}

int Magician::addForce(int num, Player& player) const {
    int force = 0;
    force = player.getForce()+num;
    return force;
}

int Magician::getMaxhp() const {
    return 100;
}

int Magician::getStartingCoins() const {
    return 10;
}

bool Magician::isMagical(){
    return true;
}

int Magician::getCombatPower(Player& player){
    int combatPower = 0;
    combatPower= player.getForce()+ player.getLevel();
    return combatPower;
}

std::string Magician::getJobName() const{
return "Magician";
}

Magician::Magician() {}