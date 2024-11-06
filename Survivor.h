//
// Created by barbulescuv on 10/28/2024.
//

#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <functional>

#include "Entity.h"


class Survivor : public Entity{
private:
    int xTranslate = 0;
    int yTranslate = 0;

    /**
     * Generates random values between -5 and 5
     * for xTranslate and yTranslate variables
     */
    void setXYTranslate();
    //void moveInDirection(Person *p, int steps, std::function<Room*()> getNextRoom, function<void(Room*)> setRoom);
public:
    Survivor();
    ~Survivor() override;

    /**
     * Teleports player to a random room within the
     * bounds of the map
     * @param p the player
     */
    void interact(Person* p) override;
    void printSelf() override;
};



#endif //SURVIVOR_H
