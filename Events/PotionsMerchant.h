//
// Created by harry cohen on 2025-01-13.
//

#ifndef MATAM_HW4_POTIONSMERCHANT_H
#define MATAM_HW4_POTIONSMERCHANT_H
#include "Event.h"
class PotionsMerchant : public Event{
    std::string m_outcome;
public:

    void operator()(Player & player) override;

    std::string getOutcome() const override { return m_outcome; }

    ~PotionsMerchant() override = default;

    std::string getDescription() const override;

};
#endif //MATAM_HW4_POTIONSMERCHANT_H
