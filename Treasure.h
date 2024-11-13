//
// Created by barbulescuv on 10/28/2024.
//

#ifndef TREASURE_H
#define TREASURE_H
#include "Entity.h"
#include <string>


class Treasure : public Entity{
protected:
    int changeValueBy = 0;
    std::string name;
public:
    Treasure() = default;
    ~Treasure() override = default;

    virtual std::string getName() const;
    virtual int getChangeValue() const;
    virtual void setChangeValue(int value);
    void printSelf() override = 0;  // Depends on the derived class
};

#endif //TREASURE_H
