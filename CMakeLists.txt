cmake_minimum_required(VERSION 3.29)
project(Wumpus_Hunt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wumpus_Hunt
        WumpusDriver.cpp
        Entity.cpp
        Weapon.cpp
        Person.cpp
        Hazard.cpp
        Treasure.cpp
        Survivor.cpp
        Alien.cpp
        Room.cpp
        Ammo.cpp
)
