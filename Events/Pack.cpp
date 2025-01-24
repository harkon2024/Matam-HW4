//
// Created by harry cohen on 2025-01-13.
//
#include "Pack.h"
#include <memory>
#include <vector>
using namespace std;


Pack::Pack() : Monster("Pack",0, 0, 0, 0) {

}

void Pack::addMonster(unique_ptr<Monster> monster){
    members.push_back(std::move(monster));
}

void Pack::winBattle() {
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        (*it)->winBattle();
    }
}

void Pack::loseBattle() {
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        (*it)->loseBattle();
    }
}

int Pack::getCombatPower() const {
    int totalCombatPower = 0;
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        totalCombatPower += (*it)->getCombatPower();
    }
    return totalCombatPower;
}

int Pack::getLoot() const {
    int totalLoot = 0;
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        totalLoot += (*it)->getLoot();
    }
    return totalLoot;
}

int Pack::getDamage() const {
    int totalDamage = 0;
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        totalDamage += (*it)->getDamage();
    }
    return totalDamage;
}

int Pack::getLevel() const {
    int totalLevel = 0;
    std::vector<std::unique_ptr<Monster>>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        totalLevel += (*it)->getLevel();
    }
    return totalLevel;
}

int Pack::getMemberCount() const{
return members.size();
}