//
// Created by harry cohen on 2025-01-18.
//
#include "Job.h"
#include "Archer.h"
#include "Warrior.h"
#include "Magician.h"

std::shared_ptr<Job> Job::createJob(const std::string& jobName) {
    if (jobName == "Archer") {
        return std::make_shared<Archer>();
    } else if (jobName == "Warrior") {
        return std::make_shared<Warrior>();
    } else if (jobName == "Magician") {
        return std::make_shared<Magician>();
    } else {
        throw std::invalid_argument("Unknown job: " + jobName);
    }
}