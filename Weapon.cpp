//
// Created by barbulescuv on 11/8/2024.
//

#include "Weapon.h"

// Constructor & destructor
Weapon::Weapon(int ammo, int damage, std::string name) : ammo(ammo), damage(damage), name(name) {}
Weapon::~Weapon() = default;

// Getters
int Weapon::getAmmo() const {
    return ammo;
}

int Weapon::getDamage() const {
    return damage;
}

std::string Weapon::getName() const{
    return name;
}

// Setters
void Weapon::setAmmo(const int ammo) {
    this->ammo = ammo;
}

void Weapon::setDamage(const int damage) {
    this->damage = damage;
}

void Weapon::setName(std::string name) {
    this->name = std::move(name);
}








