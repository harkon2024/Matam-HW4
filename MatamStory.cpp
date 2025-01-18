
#include "MatamStory.h"

#include "Utilities.h"


MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {
    {

        m_eventIndex %= events.size();

        printTurnDetails(m_turnIndex, player, *events[m_eventIndex]);


        (*events[m_eventIndex])(player);


        std::string outcome = events[m_eventIndex]->getOutcome();
        printTurnOutcome(outcome);


        m_turnIndex++;
        m_eventIndex = (m_eventIndex + 1) % events.size();
    }

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();
    unsigned int index = 0;
    std::vector<std::unique_ptr<Player>>::const_iterator it = players.begin();
    std::vector<std::unique_ptr<Event>>::const_iterator its = events.begin();
    while(it != players.end()) {
        playTurn(**it);
        printTurnDetails(index, **it,**its);
        **its(it);
        printTurnOutcome(string outcome);
        ++it;
        ++index;

        ++its;
        if(its == events.end()){
            its = events.begin();
        }
    }

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    std::vector<const Player*> sortedPlayers = sortPlayers(players);
    printLeaderBoardMessage();
    for (unsigned int i = 0; i < sortedPlayers.size(); i++)
    {

        printLeaderBoardEntry(i+1, *sortedPlayers[i]);
    }

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    for (std::vector<std::unique_ptr<Player>>::const_iterator it = players.begin();
         it != players.end();
         ++it)
    {

        if ((*it)->getLevel() >= 10)
        {
            return true;
        }
    }

    bool allExhausted = true;
    for (std::vector<std::unique_ptr<Player>>::const_iterator it = players.begin();
         it != players.end();
         ++it)
    {
        if ((*it)->getHealthPoints() > 0)
        {
            allExhausted = false;
            break;
        }
    }

    if (allExhausted)
    {
        return true;
    }


    return false;

}

void MatamStory::play() {
    printStartMessage();
    unsigned int index = 0;
    std::vector<std::unique_ptr<Player>>::const_iterator it;
    for (it = players.begin(); it != players.end(); ++it, ++index) {
        printStartPlayerEntry(index, **it);;
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if(hasWinner()){
        const Player* winner = getWinner();
        printWinner(winner);
    }
    else{
        printNoWinners();
    }

}

bool MatamStory::hasWinner() const
{

    for (std::vector<std::unique_ptr<Player>>::const_iterator it = players.begin();
         it != players.end();
         ++it)
    {

        if ((*it)->getLevel() >= 10)
        {
            return true;
        }
    }

    return false;
}

