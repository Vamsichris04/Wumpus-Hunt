//
// Created by barbulescuv on 10/28/2024.
//

#include <iostream>
#include <vector>
using namespace std;

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

