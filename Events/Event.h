
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

    virtual void operator()(Player & player)= 0;

    virtual string getDescription() const = 0;

    static std::unique_ptr<Event> createEvent(const std::string& eventType);
};
