//
// Created by barbulescuv on 10/28/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Entity.h"

class Weapon : public Entity{
protected:
    std::string name;
    int damage = 0;
    int ammo = 1;
public:
    Weapon(int ammo, int damage, std::string name);
    ~Weapon() override;

    int getAmmo() const;
    int getDamage() const;
    std::string getName() const;

    void changeAmmo(int ammo);
    void setDamage(int damage);
    void setName(std::string name);
};

class Gun : public Weapon {
public:
    Gun();
    void interact(Person& player);
};

class Flamethrower : public Weapon {
public:
    Flamethrower();
    void interact(Person& player);
};

#endif //WEAPON_H
