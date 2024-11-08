//
// Created by barbulescuv on 11/8/2024.
//

#ifndef AMMO_H
#define AMMO_H
#include "Treasure.h"


class Ammo : public Treasure{
public:
    Ammo(std::string name, int changeValueBy);
    ~Ammo() override;

    void interact(Person *p) override;
    void printSelf() override;
};



#endif //AMMO_H
