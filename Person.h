//
// Created by barbulescuv on 10/28/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include "Entity.h"
#include "Weapon.h"


class Person : public Entity{
private:
    int health;
    Weapon weapon;
public:
    Person();
    Person(int startingHeath);
    Person(int startingHeath, Weapon startingWeapon);
    ~Person();

    void interact(Person* p) override;
    void printSelf() override;

    void changeHealth(int change);

    void setWeapon(Weapon w);
    void getWeapon();
};



#endif //PERSON_H
