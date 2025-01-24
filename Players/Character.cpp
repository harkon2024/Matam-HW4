#include "Character.h"
#include "Responsible.h"
#include "RiskTaking.h"

std::shared_ptr<Character> Character::createCharacter(const std::string& characterName) {
    if (characterName == "Responsible") {
        return std::shared_ptr<Character>(new Responsible());
    } else if (characterName == "RiskTaking") {
        return std::shared_ptr<Character>(new RiskTaking());
    } else {
        throw std::invalid_argument("Unknown character type: " + characterName);
    }
}