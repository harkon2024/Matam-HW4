//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_POTIONSMERCHANT_H
#define MATAM_HW4_POTIONSMERCHANT_H
#include "Event.h"
class PotionsMerchant : public Event{

public:

    void operator()(unique_ptr<Player> & player) override;

    ~PotionsMerchant() override = default;

}
#endif //MATAM_HW4_POTIONSMERCHANT_H
