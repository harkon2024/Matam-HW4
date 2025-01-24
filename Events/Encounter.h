
#ifndef MATAM_HW4_ENCOUNTER_H
#define MATAM_HW4_ENCOUNTER_H
#include "Event.h"
#include "Monster.h"
#include "Pack.h"

class Encounter :public Event{
    unique_ptr<Monster> monster;
    std::string m_outcome;
public:
    Encounter(unique_ptr<Monster> monster);

    ~Encounter() override = default;

    std::string getOutcome() const override { return m_outcome; }

    void operator()(Player & player) override;

    string getDescription() const override;


};
#endif //MATAM_HW4_ENCOUNTER_H

