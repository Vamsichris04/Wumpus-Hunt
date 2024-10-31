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
    delete[] entities;
    delete up;
    delete down;
    delete left;
    delete right;

    entities = nullptr;
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

void Room::setThing(Entity *e) const {entities[0] = e;}
void Room::setPerson(Entity *p) const {entities[1] = p;}

void Room::interact() const {entities[0] ->interact(entities[1]);}

Room *Room::getUp() const {return up;}
Room *Room::getDown() const {return down;}
Room *Room::getLeft() const {return left;}
Room *Room::getRight() const {return right;}

void Room::print() const {entities[0] -> printSelf();}







