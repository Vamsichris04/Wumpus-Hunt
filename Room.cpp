#include "Room.h"
#include "Entity.h"
#include "Person.h"

// Constructor
Room::Room() = default;

// Destructor
Room::~Room() {
    delete object;  // Only delete owned objects
    delete player;  // Room owns player pointer only if specifically assigned
}

// Setters
void Room::setThing(Entity* e) {
    if (object) {
        delete object;  // Clean up the old entity
    }
    object = e;
}

void Room::setPerson(Person* p) {
    player = p;  // No need to delete, player might move between rooms
}

// Getters
Entity* Room::getThing() const {
    return object;
}

Person* Room::getPerson() const {
    return player;
}

// Interaction
void Room::interact() const {
    if (object) {
        object->interact(player);
    } else {
        std::cout << "The room is empty." << std::endl;
    }
}

// Printing room's contents
void Room::print() const {
    if (object) {
        object->printSelf();
    } else {
        std::cout << '.';  // Empty room marker
    }
}

// Neighboring rooms getters
Room* Room::getUp() const {
    return up;
}

Room* Room::getDown() const {
    return down;
}

Room* Room::getLeft() const {
    return left;
}

Room* Room::getRight() const {
    return right;
}

// Neighboring rooms setters
void Room::setUp(Room* room) {
    up = room;
}

void Room::setDown(Room* room) {
    down = room;
}

void Room::setLeft(Room* room) {
    left = room;
}

void Room::setRight(Room* room) {
    right = room;
}

// Stub for distance calculation
int Room::getDistanceTo(Room* room) const {
    // Placeholder: implement if distance calculations are necessary
    return 1;  // Assume adjacent rooms have distance 1
}
