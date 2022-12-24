//
//  bomberman_Game_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 24.11.22.
//

#include "bomberman_Game_ex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int getNum(int r, int c) {
    return r * 1000 + c;
}

vector<string> bomberMan(int n, vector<string> grid) {
    set<int> bombers = {};
    for (int r=0; r < grid.size(); r++){
        for (int c=0; c < grid[r].size(); c++){
            if (grid[r][c] == 'O'){
                int num = getNum(r,c);
                bombers.insert(num);
            }
        }
    }
    
    for (auto it=bombers.begin(); it != bombers.end(); ++it)
        cout << ' ' << *it;
    
    return grid;
}



void bomberman_game_ex(){
    cout << "bomberman_game_ex\n";
    int n = 3;
    vector<string> grid = {".......", "...O...", "....O..", ".......", "OO.....", "OO....."};
    vector<string> calcResult = bomberMan(n, grid);
    vector<string> expResult = {"OOO.OOO", "OO...OO", "OOO...O", "..OO.OO", "...OOOO", "...OOOO"};
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout << " >> Test "<<result<<endl;
    cout<<endl;
}
