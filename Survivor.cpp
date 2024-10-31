//
// Created by barbulescuv on 10/28/2024.
//

using namespace std;
#include "Survivor.h"
#include "Person.h"
#include <random>

Survivor::Survivor() = default;
Survivor::~Survivor() = default;

void Survivor::interact(Person *p) {
    setXYTranslate();

    // X motion
    int xIterator = 0;
    if (xTranslate < 0) {
        while(xIterator < -xTranslate && p->getRoom()->getLeft() != nullptr) {
            xIterator++;
            p->setRoom(p->getRoom()->getLeft());
        }
    } else if (xTranslate > 0) {
        while(xIterator < xTranslate && p->getRoom()->getRight() != nullptr) {
            xIterator++;
            p->setRoom(p->getRoom()->getRight());
        }
    }

    // Y Motion
    int yIterator = 0;
    if (yTranslate < 0) {
        while(yIterator < -yTranslate && p->getRoom()->getDown() != nullptr) {
            yIterator++;
            p->setRoom(p->getRoom()->getDown());
        }
    } else if (yTranslate > 0) {
        while(yIterator < yTranslate && p->getRoom()->getUp() != nullptr) {
            yIterator++;
            p->setRoom(p->getRoom()->getUp());
        }
    }
}


void Survivor::setXYTranslate() {
    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine

    // Define the range
    uniform_int_distribution<> dist(-5, 5);

    // Generate a random number
    xTranslate = dist(gen);
    yTranslate = dist(gen);
}




