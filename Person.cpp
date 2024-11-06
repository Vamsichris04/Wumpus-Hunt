//
// Created by barbulescuv on 10/28/2024.
//

#include <iostream>
using namespace std;
#include "Person.h"

Person::Person(const int startingHealth, const Weapon& startingWeapon, Room* startingRoom) : health(startingHealth),  weapon(startingWeapon), room(startingRoom) {};
Person::~Person() {
    delete room;
}

void Person::interact(Person *p) {

}

void Person::printSelf() {
    cout << '+' << endl;
}

void Person::changeHealth(int change) {
    health += change;
}

int Person::getHealth() const {
    return health;
}

void Person::setWeapon(const Weapon& w) {
    weapon = w;
}

Weapon& Person::getWeapon() {
    return weapon;
}

void Person::setRoom(Room* r) {
    room = r;
}

Room* Person::getRoom() const {
    return room;
}







