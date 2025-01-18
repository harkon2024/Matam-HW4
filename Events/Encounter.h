
#ifndef MATAM_HW4_ENCOUNTER_H
#define MATAM_HW4_ENCOUNTER_H
#include "Event.h"
#include "Monster.h"
class Encounter :public Event{
    unique_ptr<Monster> monster;
public:
    Encounter(unique_ptr<Monster> monster);

    ~Encounter() override = default;

    void operator()(unique_ptr<Player> & player) override;

    //construcot move ptr

};
#endif //MATAM_HW4_ENCOUNTER_H

