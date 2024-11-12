//
// Created by barbulescuv on 10/28/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

class Person; // Forward declaration to avoid circular dependency

class Entity {
public:
    virtual ~Entity() = 0;
    virtual void interact(Person* p) = 0;
    virtual void printSelf() = 0;
};

inline Entity::~Entity() {}

#endif //ENTITY_H
