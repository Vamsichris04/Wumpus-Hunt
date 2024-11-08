//
// Created by barbulescuv on 10/28/2024.
//

#include "Room.h"

Room::Room(Room *up, Room *down, Room *left, Room *right) {
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

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

void Room::setThing(Entity *e) {object = e;}
void Room::setPerson(Person *p) {player = p;}

void Room::interact() const {object ->interact(player);}

Room *Room::getUp() const {return up;}
Room *Room::getDown() const {return down;}
Room *Room::getLeft() const {return left;}
Room *Room::getRight() const {return right;}

void Room::print() const {object -> printSelf();}







