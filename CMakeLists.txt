cmake_minimum_required(VERSION 3.27)
project(Matam_HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Events)
include_directories(Players)

add_executable(Matam_HW4
        Events/Event.h
        Players/Player.h
        main.cpp
        MatamStory.cpp
        MatamStory.h
        Utilities.cpp
        Utilities.h
        Player.cpp
        SolarEclipse.h
        PotionsMerchant.h
        PotionsMerchant.cpp
        Monster.h
        Monster.cpp
        Balrog.cpp
        Pack.h
        Slime.cpp
        Slime.h
        Snail.h
        Snail.cpp
        Pack.cpp
        Encounter.h
        Character.cpp
        Responsible.h
        RiskTaking.cpp
        RiskTaking.h
        SolarEclipse.cpp
        Responsible.cpp
        Warrior.h
        Players/Archer.h
        Magician.h
        Warrior.cpp
        Encounter.cpp
        Archer.cpp
        Magician.cpp)
