//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include "Entity.h"
#include "Person.h"


class Room {
private:
    Entity* object;
    Person* player;

    Room* up = nullptr;
    Room* down = nullptr;
    Room* left = nullptr;
    Room* right = nullptr;
public:
    Room();
    ~Room();

    void setThing(Entity* e);
    Entity* getThing() const;
    void setPerson(Person *p);
    Person* getPerson() const;

    void print() const;

    void interact() const;

    Room* getUp() const;
    Room* getDown() const;
    Room* getLeft() const;
    Room* getRight() const;

    void setUp(Room* room);
    void setDown(Room* room);
    void setLeft(Room* room);
    void setRight(Room* room);
    int getDistanceTo(Room* room);
};



#endif //ROOM_H
