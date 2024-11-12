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
            //TODO: Implement when weapons are developed
            //Weapon* w = new Weapon(5, 5, "pistol");
            //newRoom->setThing(w);
            break;
        } case '+': {
            //TODO: Implement when weapons are developed
            //newRoom->setPerson(new Person(10, new Weapon()))
            break;
        } case '!': {
            newRoom->setThing(new Survivor());
            break;
        } case '@': {
            //TODO: Implement when hazards are developed
            //newRoom->setThing(new Hazard());
            break;
        } case '?': {
            newRoom->setThing(new Ammo("pistol", 10));
            break;
        } case '#': {
            //newRoom->setThing(new Alien());
            break;
        } default:
            newRoom->setThing(nullptr);
            break;
    }

    return newRoom;
}

