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
    Room* room;
public:
    Person();
    Person(int startingHeath);
    Person(int startingHeath, Weapon startingWeapon);
    Person(int startingHealth, Weapon startingWeapon, Room& startingRoom);
    ~Person() override;

    void interact(Person* p) override;
    void printSelf() override;

    void changeHealth(int change);

    void setWeapon(Weapon w);
    Weapon getWeapon();

    void setHealth(int change);
    int getHealth() const;

    void setRoom(Room* r);
    Room* getRoom();
};



#endif //PERSON_H
