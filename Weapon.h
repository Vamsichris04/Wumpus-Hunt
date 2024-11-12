#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "Entity.h" // Include Entity here, as Weapon directly inherits from it
class Person; // Forward declaration to avoid circular dependency

class Weapon : public Entity {
protected:
    std::string name;
    int damage = 0;
    int ammo = 1;

public:
    Weapon(int ammo, int damage, const std::string& name);
    ~Weapon();

    int getAmmo() const;
    int getDamage() const;
    std::string getName() const;

    void changeAmmo(int ammo);
    void setDamage(int damage);
    void setName(const std::string& name);

    virtual int getRange() const = 0;  // Pure virtual function for weapon range
    virtual void interact(Person& player); // Interact function to be overridden
};

// Knife class
class Knife : public Weapon {
public:
    Knife();
    int getRange() const override;    // Knife clears one room
    void interact(Person& player) override;
};

// Gun class
class Gun : public Weapon {
public:
    Gun();
    int getRange() const override;    // Gun clears two rooms
    void interact(Person& player) override;
};

// Flamethrower class
class Flamethrower : public Weapon {
public:
    Flamethrower();
    int getRange() const override;    // Flamethrower clears three rooms
    void interact(Person& player) override;
};

#endif //WEAPON_H
