//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "Person.h"


class Entity {
public:
    virtual ~Entity() = default;
    virtual void interact(Person* p);
    virtual void printSelf();

    void interact(Entity* p);
};



#endif //ENTITY_H
