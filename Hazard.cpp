//
// Created by barbulescuv on 10/28/2024.
//

#include "Hazard.h"
#include <iostream>
#include <cstdlib> // for rand

using namespace std;

// Base Hazard Constructor
Hazard::Hazard(const string& name, int damage) : name(name), damage(damage) {}

// Accessors
int Hazard::getDamage() const {
    return damage;
}

string Hazard::getName() const {
    return name;
}

// Mutators
void Hazard::setDamage(int dmg) {
    damage = dmg;
}

void Hazard::setName(const string& hazardName) {
    name = hazardName;
}

// Print method
void Hazard::printSelf() const {
    cout << "Hazard: " << name << ", Damage: " << damage << endl;
}

// Alien Constructor
Alien::Alien() : Hazard("Alien", 100) {} // If totalHp = 100

void Alien::interact(Person& player) {
    cout << "You encountered the Alien! Game Over." << endl;
    // Game Ending implementation
}

// Exposed Wires and Pits Constructor
ExposedWiresAndPits::ExposedWiresAndPits() : Hazard("Exposed Wires or Pit", 10) {}

void ExposedWiresAndPits::interact(Person& player) {
    int damage = rand() % 10 + 1; // Random damage between 1-10
    cout << "You encountered Exposed Wires or fell into a Pit! Taking " << damage << " damage." << endl;
    player.changeHealth(-damage);
}

// Low Oxygen Room Constructor
LowOxygenRoom::LowOxygenRoom() : Hazard("Low Oxygen Room", 10) {}

void LowOxygenRoom::interact(Person& player) {
    int damage = rand() % 10 + 1; // Random damage between 1-10
    cout << "The air is thin! Taking " << damage << " damage from low oxygen." << endl;
    player.changeHealth(-damage);
}

// Faulty Doors Constructor
FaultyDoors::FaultyDoors() : Hazard("Faulty Doors", 10) {}

void FaultyDoors::interact(Person& player) {
    int damage = rand() % 10 + 1; // Random damage between 1-10
    cout << "A faulty door slammed shut on you! Taking " << damage << " damage." << endl;
    player.changeHealth(-damage);
}
