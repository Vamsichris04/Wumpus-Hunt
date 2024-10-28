//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include "Entity.h"


class Room {
private:
    // Each room contains a thing and potentially a person
    // Things are stored at index 0, persons at index 1
    Entity entities[2];

    Room* up = nullptr;
    Room* down = nullptr;
    Room* left = nullptr;
    Room* right = nullptr;
public:
    Room();
    Room(Entity* up, Entity* down, Entity* left, Entity* right);
    ~Room();

    void setThing(Entity* e);
    void setPerson(Person* p);

    void print();

    void interact();
};



#endif //ROOM_H
