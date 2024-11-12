//
// Created by barbulescuv on 10/28/2024.
//

#include "Room.h"

Room::Room() = default;

Room::~Room() {
    delete object;
    delete player;
    delete up;
    delete down;
    delete left;
    delete right;

    object = nullptr;
    player = nullptr;
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

void Room::setThing(Entity *e) {
    delete object;
    object = e;
}
Entity* Room::getThing() const {
    return object;
}
void Room::setPerson(Person *p) {player = p;}
Person *Room::getPerson() const {return player;}

void Room::interact() const {object ->interact(player);}

Room *Room::getUp() const {return up;}
Room *Room::getDown() const {return down;}
Room *Room::getLeft() const {return left;}
Room *Room::getRight() const {return right;}

void Room::setUp(Room* room) { up = room; }
void Room::setDown(Room* room) { down = room; }
void Room::setLeft(Room* room) { left = room; }
void Room::setRight(Room* room) { right = room; }

void Room::print() const {object -> printSelf();}







