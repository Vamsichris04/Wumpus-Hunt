//
// Created by barbulescuv on 10/28/2024.
//

#ifndef HAZARDS_H
#define HAZARDS_H
#include "Entity.h"
#include <string>

using namespace std;

class Hazard : public Entity{
protected:
    int damage = 0;
    std::string name;
public:
    Hazard(const string& name, int damage);
    ~Hazard() override = default;

    virtual int getDamage() const;
    virtual string getName() const;
    virtual void setDamage(int dmg);
    virtual void setName(const string& hazardName);

    void printSelf() const;
};

class ExposedWiresAndPits : public Hazard {
public:
    ExposedWiresAndPits();
    void interact(Person& player) ; // Random damage or fatal pitfall
};

class LowOxygenRoom : public Hazard {
public:
    LowOxygenRoom();
    void interact(Person& player) ; // Random damage
};

class FaultyDoors : public Hazard {
public:
    FaultyDoors();
    void interact(Person& player) ; // Random damage
};

#endif // HAZARDS_H