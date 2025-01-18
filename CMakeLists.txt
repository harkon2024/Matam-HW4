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
        Players/Player.cpp
        Events/SolarEclipse.h
        Events/PotionsMerchant.h
        Events/PotionsMerchant.cpp
        Events/Monster.h
        Events/Monster.cpp
        Events/Balrog.cpp
        Events/Pack.h
        Events/Slime.cpp
        Events/Slime.h
        Events/Snail.h
        Events/Snail.cpp
        Events/Pack.cpp
        Events/Encounter.h
        Players/Character.cpp
        Players/Responsible.h
        Players/RiskTaking.cpp
        Players/RiskTaking.h
        Events/SolarEclipse.cpp
        Players/Responsible.cpp
        Players/Warrior.h
        Players/Archer.h
        Players/Magician.h
        Players/Warrior.cpp
        Events/Encounter.cpp
        Players/Archer.cpp
        Players/Magician.cpp
        Events/Event.cpp)
