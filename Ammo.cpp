//
// Created by barbulescuv on 11/8/2024.
//

#include "Ammo.h"

#include <utility>

Ammo::Ammo(std::string name, int changeValueBy) {
    this -> name = std::move(name);
    this -> changeValueBy = changeValueBy;
}

Ammo::~Ammo() = default;

void Ammo::interact(Person *p) {
    // If the ammo is for the same type of weapon the player is carrying, add ammo
    if (p -> getWeapon().getName() == this->name) {
        p -> getWeapon().changeAmmo(changeValueBy);
    }
}



