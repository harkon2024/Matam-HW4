
#include "MatamStory.h"

#include "Utilities.h"
#include "PotionsMerchant.h"
#include "SolarEclipse.h"
#include "Encounter.h"
#include "Pack.h"
#include <fstream>
#include <sstream>

MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    if (!eventsStream) {
        throw std::invalid_argument("Error: Invalid or empty events stream.");
    }
    if (!playersStream) {
        throw std::invalid_argument("Error: Invalid or empty players stream.");
    }
    if (eventsStream.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Invalid Events File" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(eventsStream, line)) {
        std::istringstream ss(line);
        std::string eventType;
        ss >> eventType;

        try {
            if (eventType == "Slime" || eventType == "Balrog" || eventType == "Snail") {
                events.emplace_back(std::make_unique<Encounter>(Monster::createMonster(eventType)));
            } else if (eventType == "PotionsMerchant") {
                events.emplace_back(std::make_unique<PotionsMerchant>());
            } else if (eventType == "SolarEclipse") {
                events.emplace_back(std::make_unique<SolarEclipse>());
            } else if (eventType == "Pack") {
                Pack *pack = new Pack();
                int k;

                if (!(ss >> k) || k <= 0) {
                    std::cerr << "Invalid Events File" << std::endl;
                    delete pack; // Prevent memory leak
                    std::exit(EXIT_FAILURE); // Exit the program with an error code
                }

                for (int i = 0; i < k; i++) {
                    std::string monsterType;
                    if (!(ss >> monsterType)) {
                        std::cerr << "Invalid Events File" << std::endl;
                        delete pack; // Prevent memory leak
                        std::exit(EXIT_FAILURE); // Exit the program with an error code
                    }
                    try {
                        pack->addMonster(Monster::createMonster(monsterType));
                    } catch (const std::exception &e) {
                        std::cerr << "Invalid Events File" << std::endl;
                        delete pack; // Prevent memory leak
                        std::exit(EXIT_FAILURE); // Exit the program with an error code
                    }
                }

                events.emplace_back(std::make_unique<Encounter>(std::unique_ptr<Monster>(pack)));
            } else {
                std::cerr << "Invalid Events File" << std::endl;
                std::exit(EXIT_FAILURE); // Exit the program with an error code
            }
        } catch (const std::exception &e) {
            std::cerr << "Invalid Events File" << std::endl;
            std::exit(EXIT_FAILURE); // Exit the program with an error code
        }
    }

    while (std::getline(playersStream, line)) {
        std::istringstream ss(line);
        std::string name, jobType, characterType;

        if (!(ss >> name >> jobType >> characterType)) {
            std::cerr << "Invalid Players File" << std::endl;
            std::exit(EXIT_FAILURE); // Exit the program with an error code
        }

        std::shared_ptr<Job> job;
        std::shared_ptr<Character> character;
        try {
            job = Job::createJob(jobType);
            character = Character::createCharacter(characterType);
        } catch (const std::exception &e) {
            std::cerr << "Invalid Players File" << std::endl;
            std::exit(EXIT_FAILURE); // Exit the program with an error code
        }

        players.emplace_back(name, job, character);
    }

    this->m_turnIndex = 1;
}
    void MatamStory::handlePack(std::istringstream &ss, Pack *parentPack) {
        std::string word;
        while (std::getline(ss, word, ' ')) {
            if (word == "Pack") {
                Pack *nestedPack = new Pack();
                std::getline(ss, word, ' ');
                int k = std::stoi(word);
                for (int i = 0; i < k; ++i) {
                    std::getline(ss, word, ' ');
                    handlePack(ss, nestedPack);
                }
                parentPack->addMonster(Monster::createPackMonster(nestedPack));
            } else {
                parentPack->addMonster(Monster::createMonster(word));
            }
        }
    }


    void MatamStory::playTurn(Player &player, std::unique_ptr<Event> &event) {
        printTurnDetails(this->m_turnIndex, player, *event);
        (*event)(player);
        printTurnOutcome((event)->getOutcome());
        m_turnIndex++;
    }

    void MatamStory::playRound() {

        printRoundStart();
        static std::vector<std::unique_ptr<Event>>::iterator its = events.begin();

        for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
            if (!it->isKnockedOut()) {
                playTurn(*it, *its);
                ++its;

                if (its == events.end()) {
                    its = events.begin();
                }
            }
        }



        printRoundEnd();

        std::vector<Player> sortedPlayers = players;
        std::sort(sortedPlayers.begin(), sortedPlayers.end());
        printLeaderBoardMessage();
        for (int i = sortedPlayers.size() - 1; i >= 0; i--) {
            printLeaderBoardEntry(sortedPlayers.size() - i, sortedPlayers[i]);
        }


        printBarrier();
    }

    bool MatamStory::isGameOver() const {
        for (std::vector<Player>::const_iterator it = players.begin(); it != players.end(); ++it) {
            if ((it)->getLevel() >= 10) {
                return true;
            }
        }

        bool allExhausted = true;
        for (std::vector<Player>::const_iterator it = players.begin(); it != players.end() && allExhausted; ++it) {
            if (!(it->isKnockedOut())) {
                allExhausted = false;
            }
        }
        if (allExhausted) {
            return true;
        }
        return false;
    }

    void MatamStory::play() {
        printStartMessage();
        unsigned int index = 1;
        std::vector<Player>::const_iterator it;
        for (it = players.begin(); it != players.end(); ++it, ++index) {
            printStartPlayerEntry(index, *it);;
        }

        printBarrier();
        while (!isGameOver()) {
            playRound();
        }

        printGameOver();

        if (hasWinner()) {
            printWinner(*getWinner());
        } else {
            printNoWinners();
        }
    }

    bool MatamStory::hasWinner() {
        return getWinner() != players.end();
    }

    std::vector<Player>::const_iterator MatamStory::getWinner() {
        for (std::vector<Player>::const_iterator it = players.begin(); it != players.end();
             ++it) {
            if (it->getLevel() >= 10)
                return it;
        }
        return players.end();
    }
