#include "Player.h"


Player::Player(string name, unique_ptr<Job> job, unique_ptr<Character> character,int level, int force){
    this -> name = name;
    this -> level = level;
    this -> force = force;
    this -> job = std::move(job);
    this -> character = std::move(character);
    maxHp = job -> getMaxhp();
    currentHp = maxHp;
    coins = job -> getStartingCoins();
}


void Player::buyPotions(){
    character-> buyPotions(coins, currentHp, maxHp);
}



int Player::getForce() const{
    return force;
}

void Player::levelUp(){
    level++;
}

void Player::addCoins(int amount){
    coins += amount;
}

void Player::takeDamage(int amount){
    currentHp -= amount;
    if(currentHp < 0) currentHp =0;
}

Job* Player::getJob() const {
    return job.get();
}

string Player::getName() const{
    return name;
}

int Player::getLevel() const{
    return level;
}

int Player::getHealthPoints() const{
    return currentHp;
}

int Player::getCoins() const{
    return coins;
}

int Player::getCombatPower() const{
    return job->getCombatPower(*const_cast<Player*>(this));
}

string Player::getDescription() const{
    return name + "," + job -> getJobName() + "with" + character -> getCharacterName() +"character (level" + level + ", force" + force;
}