//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ALIEN_H
#define ALIEN_H
#include "Entity.h"


class Alien : public Entity{
private:
    bool hit = false;
    bool grabbedPlayer = false;
public:
    Alien();
    void interact(Person p) override;
    void printSelf() override;
};



#endif //ALIEN_H
