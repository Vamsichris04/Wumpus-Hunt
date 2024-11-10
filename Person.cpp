//
// Created by barbulescuv on 10/28/2024.
//

#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(int startingHealth, Room* startingRoom)
    : health(startingHealth), room(startingRoom) {

}

Person::~Person() {
    delete weapon;
    delete room;
    weapon = nullptr;
    room = nullptr;
}

void Person::interact(Person *p) {
    //TODO
}

void Person::printSelf() {
    cout << '+' << endl;
}

void Person::changeHealth(int change) {
    health += change;
    if (health <= 0) {
        std::cout << "You have died. Game Over." << std::endl;
    }

}

int Person::getHealth() const {
    return health;
}

void Person::setWeapon(Weapon* w) {
    if (weapon != nullptr) {
        delete weapon;
    }
    weapon = w;
    if (weapon) {
        cout << "You picked up a" << weapon-> getName() << "!" << endl;
    }
}

Weapon* Person::getWeapon() const {
    return weapon;
}

void Person::setRoom(Room* r) {
    if (room != r) {
        delete room;  // Free the old room
    }
    room = r;
}

Room* Person::getRoom() const {
    return room;
}







