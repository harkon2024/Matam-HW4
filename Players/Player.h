
#pragma once

#include <string>
#include <memory>
#include "Job.h"
#include "Character.h"

class Character;

using std::string;
using std:: unique_ptr;
using namespace std;

class Player {
    string name;
    int level, currentHp, maxHp, coins, force;
    shared_ptr<Job> job;
    shared_ptr<Character> character;

public:
    Player(string name, shared_ptr<Job> job, shared_ptr<Character> character,int level = 1, int force = 5);

    int buyPotions();

    void levelUp();

    void addCoins(int amount);

    void takeDamage(int amount);

    Job* getJob() const;

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    int getCombatPower() const;

    bool operator < (const Player& other) const;

    bool isKnockedOut() const;

    void setForce(int newForce);




};
