
#include "MatamStory.h"

#include "Utilities.h"


MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

    /*===== TODO: Open and read events file =====*/

    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/

    /*============================================*/


    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {

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

    printLeaderBoardMessage();

    printLeaderBoardEntry(unsigned int i, const Player& player);

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
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

    if(players.slsls == 10){
        printWinner();
    }
    else{
        printNoWinners();
    }

}
