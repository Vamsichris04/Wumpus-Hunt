#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Entity;  // Forward declaration of Entity
class Person;  // Forward declaration of Person

class Room {
private:
    Entity* object = nullptr;  // Points to any entity in the room
    Person* player = nullptr;  // Points to the player if present in this room

    Room* up = nullptr;
    Room* down = nullptr;
    Room* left = nullptr;
    Room* right = nullptr;

public:
    Room();
    ~Room();

    void setThing(Entity* e);
    void setPerson(Person* p);

    Entity* getThing() const;
    Person* getPerson() const;

    void interact() const;  // Handle interaction with the room's entity
    void print() const;     // Print the contents of the room

    Room* getUp() const;
    Room* getDown() const;
    Room* getLeft() const;
    Room* getRight() const;

    void setUp(Room* room);
    void setDown(Room* room);
    void setLeft(Room* room);
    void setRight(Room* room);

    int getDistanceTo(Room* room) const;  // Stub for future distance calculation
};

#endif // ROOM_H
