
#pragma once

#include "../Players/Player.h"

class Event {
public:
    Event();
    virtual ~ Event();

    virtual void operator()(unique_ptr<Player> & player)= 0;

    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;
};
