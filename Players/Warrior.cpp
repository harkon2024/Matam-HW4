//
// Created by harry cohen on 2025-01-14.
//

#include "Warrior.h"

void Warrior::winBattle(Player& player, const Monster& monster){
player.levelUp();
int costs = 0;
costs = monster.getLoot();
player.addCoins(costs);
player.takeDamage(10);
}

void Warrior::loseBattle(Player& player, const Monster& monster){
    int damage =0;
    damage = monster.getDamage();
    player.takeDamage(damage);
    player.takeDamage(10);
}

int Warrior::addForce(int num, Player& player) const {
    int force = 0;
    force = player.getForce()+num;
    return force;
}

int Warrior::getMaxhp() const {
    return 150;
}

int Warrior::getStartingCoins() const {
    return 10;
}

bool Warrior::isMagical(){
    return false;
}

int Warrior::getCombatPower(Player& player){
    int combatPower = 0;
    combatPower= player.getForce()*2 + player.getLevel();
    return combatPower;
}

std::string Warrior::getJobName() const{
    return "Warrior";
}

Warrior::Warrior(){
}