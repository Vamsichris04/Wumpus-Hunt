//
// Created by barbulescuv on 10/28/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include "Entity.h"
#include "Room.h"
#include "Weapon.h"


class Person : public Entity{
private:
    int health;
    Weapon weapon;
    Room* room = nullptr;
public:
    Person(int startingHealth, const Weapon& startingWeapon, Room* startingRoom);
    ~Person() override;

    void interact(Person* p) override;
    void printSelf() override;

    void changeHealth(int change);
    int getHealth() const;

    void setWeapon(const Weapon& w);
    Weapon& getWeapon();

    void setRoom(Room* r);
    Room* getRoom() const;
};



#endif //PERSON_H
