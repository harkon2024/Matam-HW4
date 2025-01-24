//
// Created by harry cohen on 2025-01-13.
//
#include "SolarEclipse.h"
#include "Utilities.h"


void SolarEclipse::operator()(Player &player) {
    int effect = player.getJob()->isMagical() ? 1 : -1;
    int newForce = player.getJob()->addForce(effect, player); // Compute new force
    player.setForce(newForce); // Explicitly update the player's force
    m_outcome = getSolarEclipseMessage(player, effect);
}

std::string SolarEclipse::getDescription() const  {
return "Solar Eclipse Description";
}