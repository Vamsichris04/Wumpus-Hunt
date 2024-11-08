cmake_minimum_required(VERSION 3.29)
project(Wumpus_Hunt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wumpus_Hunt
    WumpusDriver.cpp
        Entity.h
        Entity.cpp
        Weapon.h
        Weapon.cpp
        Person.h
        Hazard.h
        Hazard.cpp
        Person.cpp
        Treasure.h
        Treasure.cpp
        Survivor.h
        Survivor.cpp
        Alien.h
        Alien.cpp
        Room.h
        Room.cpp
        Ammo.h
        Ammo.h
        Ammo.h
        Ammo.cpp
)
