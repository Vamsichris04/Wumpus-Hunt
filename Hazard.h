//
// Created by barbulescuv on 10/28/2024.
//

#ifndef HAZARDS_H
#define HAZARDS_H
#include "Entity.h"
#include <string>



class Hazard : public Entity{
protected:
    int damage = 0;
    std::string name;
public:
    ~Hazard() override = default;
    virtual int getDamage();
    virtual std::string getName();
    virtual int setDamage();
    virtual std::string setName();
};



#endif //HAZARDS_H
