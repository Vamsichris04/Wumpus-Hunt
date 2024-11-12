//
// Created by barbulescuv on 10/28/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include "Entity.h"

// Forward declarations to avoid circular dependencies
class Entity;
class Weapon;
class Room;


class Person : public Entity{
protected:
    int health;
    Weapon* weapon = nullptr;
    Room* room = nullptr;
public:
    Person(int startingHealth, Room* startingRoom);
    ~Person() override;

    void interact(Person* p) override;
    void printSelf() override;

    void changeHealth(int change);
    int getHealth() const;

    void setWeapon(Weapon* w);
    Weapon* getWeapon() const;

    void setRoom(Room* r);
    Room* getRoom() const;
};



#endif //PERSON_H
