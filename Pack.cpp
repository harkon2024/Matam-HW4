//
// Created by harry cohen on 2025-01-13.
//
#include "Pack.h"

Pack::Pack() : Monster(0, 0, 0, 0) {

}

void addMonster(unique_ptr<Monster> &);

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
