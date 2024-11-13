//
// Created by barbulescuv on 10/28/2024.
//

#include <iostream>
#include <vector>
#include "Room.h"
#include "Alien.h"
#include "Ammo.h"
#include "Weapon.h"
#include "Hazard.h"
#include "Person.h"
#include "Survivor.h"
#include "Treasure.h"
#include "Entity.h"

using namespace std;
Room* buildMap(const vector<vector<char>>& map);
Room* buildRoom(char object);
void printHints(const Room* room);

void displayMap(const vector<vector<char>>& map) {
    for (const auto& row : map) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> map = {
        {'.', '-', '>', '+', '-'},
        {'-', '!', '@', '.', '>'},
        {'-', '?', '.', '>', '!'},
        {'-', '@', '#', '-', '.'},
        {'@', '-', '.', '>', '@'}
    };

    // Display the map
    cout << "Map Layout:" << endl;
    displayMap(map);

    Room* room = buildMap(map);
    Person* player = room->getPerson();
    bool gameOver = false;

    while (!gameOver) {
        printHints(room);

        // Player and object interact together
        room->interact();

        char choice;
        cin >> choice;
        switch (choice) {
            case 'w': {
                if (room->getLeft() != nullptr) {
                    player->setRoom(room->getLeft());
                    room->getLeft()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getLeft();
                }
                break;
            }
            case 'e': {
                if (room->getRight() != nullptr) {
                    player->setRoom(room->getRight());
                    room->getRight()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getRight();
                }
                break;
            }
            case 'n': {
                if (room->getUp() != nullptr) {
                    player->setRoom(room->getUp());
                    room->getUp()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getUp();
                }
                break;
            }
            case 's': {
                if (room->getDown() != nullptr) {
                    player->setRoom(room->getDown());
                    room->getDown()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getDown();
                }
                break;
            }
            case 'q': {
                gameOver = true;
                break;
            }
            default: break;
        }
    }

    return 0;
}

// Function to build and link rooms according to the map layout
/**
 * Builds and links rooms according to map layout
 * @param map the map of characters dictating what's in each room
 * @return the players starting room
 */
Room* buildMap(const vector<vector<char>>& map) {
    const int rows = map.size();
    const int cols = map[0].size();

    // Initialize the 2D vector of Room pointers
    vector<vector<Room*>> roomGrid(rows, vector<Room*>(cols, nullptr));
    Room* startingRoom = nullptr;

    // Create Room objects and store them in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char object = map[i][j];
            if (object == '+') {
                startingRoom = buildRoom(object);
                roomGrid[i][j] = startingRoom;
            } else {
                roomGrid[i][j] = buildRoom(object);
            }
        }
    }

    // Link the rooms
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Room* currentRoom = roomGrid[i][j];

            // Set up pointer if not in the first row
            if (i > 0) {
                currentRoom->setUp(roomGrid[i - 1][j]);
                roomGrid[i - 1][j]->setDown(currentRoom);
            }

            // Set down pointer if not in the last row
            if (i < rows - 1) {
                currentRoom->setDown(roomGrid[i + 1][j]);
                roomGrid[i + 1][j]->setUp(currentRoom);
            }

            // Set left pointer if not in the first column
            if (j > 0) {
                currentRoom->setLeft(roomGrid[i][j - 1]);
                roomGrid[i][j - 1]->setRight(currentRoom);
            }

            // Set right pointer if not in the last column
            if (j < cols - 1) {
                currentRoom->setRight(roomGrid[i][j + 1]);
                roomGrid[i][j + 1]->setLeft(currentRoom);
            }
        }
    }

    return startingRoom;
}

Room* buildRoom(char object) {
    Room* newRoom = new Room();
    switch (object) {
        case '>': {
            Weapon* w = new Weapon(5, 5, "pistol");
            newRoom->setThing(w);
            break;
        } case '+': {
            newRoom->setPerson(new Person(10, new Weapon()))
            break;
        } case '!': {
            newRoom->setThing(new Survivor());
            break;
        } case '@': {
            newRoom->setThing(new Hazard());
            break;
        } case '?': {
            newRoom->setThing(new Ammo("pistol", 10));
            break;
        } case '#': {
            newRoom->setThing(new Alien());
            break;
        } default:
            newRoom->setThing(nullptr);
            break;
    }

    return newRoom;
}

void printHints(const Room* room) {
    if (room->getLeft() != nullptr) {
        room->getLeft()->getThing()->printSelf();
    }
    if (room->getRight() != nullptr) {
        room->getRight()->getThing()->printSelf();
    }
    if (room->getUp() != nullptr) {
        room->getUp()->getThing()->printSelf();
    }
    if (room->getDown() != nullptr) {
        room->getDown()->getThing()->printSelf();
    }
}

