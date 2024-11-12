#include "Weapon.h"
#include "Person.h"
#include <iostream>

// Base Weapon Constructor & Destructor
Weapon::Weapon(int ammo, int damage, const std::string& name)
    : ammo(ammo), damage(damage), name(name) {}

Weapon::~Weapon() = default;

// Getters
int Weapon::getAmmo() const {
    return ammo;
}

int Weapon::getDamage() const {
    return damage;
}

std::string Weapon::getName() const {
    return name;
}

// Setters
void Weapon::changeAmmo(int ammo) {
    this->ammo += ammo;
}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

void Weapon::setName(const std::string& name) {
    this->name = name;
}

// Knife Class
Knife::Knife() : Weapon(1, 5, "Knife") {}  // Knife starts with limited power

int Knife::getRange() const {
    return 1;  // Knife can clear one room
}

void Knife::interact(Person& player) {
    std::cout << "You swing the Knife. It can only clear one room." << std::endl;
}

// Gun Class
Gun::Gun() : Weapon(1, 10, "Gun") {}  // Gun starts with one ammo

int Gun::getRange() const {
    return 2;  // Gun can clear two rooms
}

void Gun::interact(Person& player) {
    if (ammo > 0) {
        std::cout << "You fire the Gun. It can clear up to two rooms." << std::endl;
        ammo--;  // Use one ammo per shot
    } else {
        std::cout << "Out of ammo for the Gun! Find more ammo to use it." << std::endl;
    }
}

// Flamethrower Class
Flamethrower::Flamethrower() : Weapon(1, 15, "Flamethrower") {}  // Flamethrower starts with one ammo

int Flamethrower::getRange() const {
    return 3;  // Flamethrower can clear three rooms
}

void Flamethrower::interact(Person& player) {
    if (ammo > 0) {
        std::cout << "You use the Flamethrower. It can clear up to three rooms." << std::endl;
        ammo--;  // Use one ammo per shot
    } else {
        std::cout << "Out of ammo for the Flamethrower! Find more fuel to use it." << std::endl;
    }
}
