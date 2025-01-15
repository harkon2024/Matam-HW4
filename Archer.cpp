//
// Created by harry cohen on 2025-01-14.
//
#include "Archer.h"

void Archer::winBattle(Player& player, const Monster& monster){
    player.levelUp();
    int costs = 0;
    costs = monster.getLoot();
    player.addCoins(costs);
}

void Archer::loseBattle(Player& player, const Monster& monster){
    int damage =0;
    damage = monster.getDamage();
    player.takeDamage(damage);
}

int Archer::addForce(int num, Player& player) const {
    int force = 0;
    force = player.getForce()+num;
    return force;
}

int Archer::getMaxhp() const {
    return 100;
}

int Archer::getStartingCoins() const {
    return 20;
}

bool Archer::isMagical(){
    return false;
}

int Archer::getCombatPower(Player& player){
    int combatPower = 0;
    combatPower= player.getForce()+ player.getLevel();
    return combatPower;
}

std::string Archer::getJobName() const{
    return "Archer";
}