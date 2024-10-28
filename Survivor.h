//
// Created by barbulescuv on 10/28/2024.
//

#ifndef SURVIVOR_H
#define SURVIVOR_H
#include "Entity.h"


class Survivor : public Entity{
private:
    int xTranslate = 0;
    int yTranslate = 0;

    void setXYTranslate();
public:
    Survivor();
    void interact(Person p) override;
    void printSelf() override;
};



#endif //SURVIVOR_H
