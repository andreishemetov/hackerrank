//
//  gridChallenge_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 10.11.22.
//

#include "gridChallenge_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string gridChallenge(vector<string> grid) {
    sort(grid[0].begin(), grid[0].end());
    for (int j=0; j<grid.size(); j++){
        char l = grid[0][j];
        for (int i=1; i<grid.size(); i++){
            if (j == 0) {
                sort(grid[i].begin(), grid[i].end());
            }
            char nl = grid[i][j];
            if (nl < l) {
                return "NO";
            }
            l = nl;
        }
    }
    return "YES";
}


void gridChallenge_ex(){
    cout << "gridChallenge_ex\n";
//    vector<string> grid = {
//        "ebacd",
//        "fghij",
//        "olmkn",
//        "trpqs",
//        "xywuv"
//    };
    vector<string> grid = {
        "nyx",
        "ynx",
        "xyt"
    };
    string calcResult = gridChallenge(grid);
    string expResult = "YES";
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<"calcResult:"<<calcResult<<" expResult:"<<expResult<<" >> Test "<<result<<endl;
    cout<<endl;
}


