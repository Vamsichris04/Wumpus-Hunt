//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ALIEN_H
#define ALIEN_H
#include "Entity.h"

class Room;

class Alien : public Entity{
    bool hit = false; // If the alien has been hit or not
    bool grabbedPlayer = false; // If the player has been grabbed by the alien or not
public:
    Alien();
    void interact(Person* p) override;
    void printSelf() override;
    bool isHit() const;                 // Check if the Alien has been hit
    Room* getRoom();
    void hitByWeapon(int range, Person* p);  // Alien is shot if within weapon range
};



#endif //ALIEN_H
