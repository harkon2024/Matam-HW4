
#pragma once

#include "../Players/Player.h"


using std::string;
using std::to_string;

class Event {
protected:
    std::string m_outcome;
public:
    Event();
    virtual ~ Event();

    virtual std::string getOutcome() const { return m_outcome; }

    virtual void operator()(unique_ptr<Player> & player)= 0;

    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;
};
