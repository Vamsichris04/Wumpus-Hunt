//
// Created by barbulescuv on 11/8/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Entity.h"


class Weapon : public Entity{
private:
    int ammo;
    int damage;
    std::string name;
public:
    Weapon(int ammo, int damage, std::string name);
    ~Weapon() override;

    int getAmmo() const;
    int getDamage() const;
    std::string getName() const;

    void setAmmo(int ammo);
    void setDamage(int damage);
    void setName(std::string name);
};



#endif //WEAPON_H
