//
// Created by barbulescuv on 10/28/2024.
//

#include "Treasure.h"

 using namespace std;

string Treasure::getName() const {
 return name;
}
int Treasure::getChangeValue() {
 return changeValueBy;
}
void Treasure::setChangeValue(int value) {
 changeValueBy = value;
}




