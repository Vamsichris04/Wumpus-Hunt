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
    //Entity** entities = new Entity*[2];

    Entity* object = new Entity;
    Person *player = nullptr;

    Room* up = nullptr;
    Room* down = nullptr;
    Room* left = nullptr;
    Room* right = nullptr;
public:
    Room(Room* up, Room* down, Room* left, Room* right);
    ~Room();

    void setThing(Entity* e);
    void setPerson(Person *p);

    void print() const;

    void interact() const;

    Room* getUp() const;
    Room* getDown() const;
    Room* getLeft() const;
    Room* getRight() const;
};



#endif //ROOM_H
