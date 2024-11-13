//
// Created by barbulescuv on 11/8/2024.
//

#include "Ammo.h"
#include <iostream>
#include <utility>

#include "Person.h"
#include "Weapon.h"

Ammo::Ammo(std::string name, int changeValueBy) {
    this -> name = std::move(name);
    this -> changeValueBy = changeValueBy;
}

Ammo::~Ammo() = default;

void Ammo::interact(Person *p) {
    // Ammo is the same for each gun
    if (p -> getWeapon() != nullptr) {
        p -> getWeapon() -> changeAmmo(changeValueBy);
        std::cout << "You found ammo for your gun! Ammo increase by " << changeValueBy << "." << std::endl;
    } else {
        std::cout << "You found ammo, but you dont have a weapon :( !" << std::endl;
    }
}
void Ammo::printSelf() {
    std::cout << "Ammo" << std::endl;
}



