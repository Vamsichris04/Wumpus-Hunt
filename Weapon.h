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
    int ammo = 0;
public:
    ~Weapon() override = default;
    virtual int getDamage();
    virtual std::string getName();

    virtual int setDamage();
    virtual std::string setName();

    virtual int getAmmo();
    virtual int setAmmo();
};



#endif //WEAPON_H
