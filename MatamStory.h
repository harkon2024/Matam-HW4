
#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Players/Player.h"
#include "Events/Event.h"
#include "Pack.h"


class MatamStory{
private:
    std::vector<Player> players;
    std::vector<unique_ptr<Event>> events;
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player &player,std::unique_ptr<Event> &event);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    bool hasWinner();

    std::vector<Player> ::const_iterator getWinner();

    void handlePack(std::istringstream& ss, Pack* parentPack);

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();


};
