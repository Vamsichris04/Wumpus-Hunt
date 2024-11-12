#include "Alien.h"
#include <iostream>
#include <cmath>

#include "Person.h"
#include "Room.h"
#include "Weapon.h"

// Constructor
Alien::Alien() : hit(false), grabbedPlayer(false) {
    std::cout << "An Alien has spawned in a random room!" << std::endl;
}

// Checks if Alien has been hit
bool Alien::isHit() const {
    return hit;
}

// Interact with player (if player enters the room with Alien)
void Alien::interact(Person* p) {
    if (hit) {
        std::cout << "The Alien is already dead." << std::endl;
        return;
    }

    std::cout << "You have entered the Alien's room unarmed or with limited range! The Alien attacks!" << std::endl;
    p->changeHealth(-p->getHealth()); // Player dies, game over
}

// Simulate the Alien being hit by a weapon
void Alien::hitByWeapon(int range, Person* p) {
    if (hit) {
        std::cout << "The Alien has already been killed." << std::endl;
        return;
    }

    Room* playerRoom = p->getRoom();
    Room* alienRoom = this->getRoom();  // Assuming Alien is an Entity with a room reference.

    int distance = playerRoom->getDistanceTo(alienRoom);  // Assuming Room has method to calculate distance.

    if (distance <= range) {
        Weapon* weapon = p->getWeapon();
        std::cout << "You attack the Alien with your " << weapon->getName() << " killing instantly at range distance range." << std::endl;
        hit = true;
        p->changeHealth(2);
    } else {
        // Room outside range
        std::cout << "Warning or you have not shot correctly for alien target off distance for shooters." << std::endl; return;
    }
}

// Display the Alien symbol
void Alien::printSelf() {
    std::cout << "You smell something foul."  << std::endl; // Represents Alien on the map
}
