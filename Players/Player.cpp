#include "Player.h"
using std::to_string;


Player::Player(string name, shared_ptr<Job> job, shared_ptr<Character> character,int level, int force){
    this -> name = name;
    this -> level = level;
    this -> force = force;
    this -> job = std::move(job);
    this -> character = std::move(character);
    maxHp = this ->job -> getMaxhp();
    currentHp = maxHp;
    coins = this ->job -> getStartingCoins();
}


int Player::buyPotions(){
   return character -> buyPotions(coins, currentHp, maxHp);
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

std::string Player::getDescription() const {
    return name + ", " + job->getJobName() + " with " + character->getCharacterName() +
           " character (level " + std::to_string(level) + ", force " + std::to_string(force) + ")";
}

bool Player::operator<(const Player& other) const {
    if (level != other.level) {
        return level < other.level;
    }
    if (coins != other.coins) {
        return coins < other.coins;
    }
    return name < other.name;
}

bool Player::isKnockedOut() const{
    return(currentHp <= 0);
}

void Player::setForce(int newForce) {
    this->force = newForce;
}