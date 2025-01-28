//
// Created by harry cohen on 2025-01-13.
//
#include "Encounter.h"
#include "Utilities.h"


void Encounter::operator()(Player & player){
    if(monster-> getCombatPower() > player.getJob()-> getCombatPower(player)){
        player.getJob()-> loseBattle(player, *monster);
        monster -> winBattle();
        m_outcome = getEncounterLostMessage(player, monster -> getDamage());
    }else{
        player.getJob()-> winBattle(player, *monster);
        monster -> loseBattle();
        m_outcome = getEncounterWonMessage(player, monster -> getLoot());
    }
}

std::string Encounter::getDescription() const {
    if (monster->getName() != "Pack") {
        return monster->getName() + " (power " + std::to_string(monster->getLevel()) +
               ", loot " + std::to_string(monster->getLoot()) +
               ", damage " + std::to_string(monster->getDamage()) + ")";
    } else {
        return "Pack of " + std::to_string(monster->getMemberCount()) +
               " members (power " + std::to_string(monster->getLevel()) +
               ", loot " + std::to_string(monster->getLoot()) +
               ", damage " + std::to_string(monster->getDamage()) + ")";
    }
}


Encounter::Encounter(std::unique_ptr<Monster> monster)
        : monster(std::move(monster)), m_outcome("") {}