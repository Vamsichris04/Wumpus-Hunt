//
// Created by barbulescuv on 10/28/2024.
//

#ifndef TREASURE_H
#define TREASURE_H
#include "Entity.h"


class Treasure : public Entity{
protected:
    int changeValueBy = 0;
    std::string name;
public:
    ~Treasure() override = default;
};



#endif //TREASURE_H
