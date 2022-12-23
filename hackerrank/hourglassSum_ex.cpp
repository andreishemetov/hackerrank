//
//  hourglassSum_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 23/12/2022.
//

#include "hourglassSum_ex.hpp"
#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    for (int r = 0; r < arr.size()-2; r++) {
        for (int c = 0; c < arr[r].size()-2; c++) {
            int i = 0;
            int sum = 0;
            while (i < 3) {
                sum += arr[r][c+i] + arr[r+2][c+i];
                if (i == 1) sum += arr[r+i][c+i];
                i++;
            }
            if (sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

void hourglassSum_ex() {
    cout << "hourglassSum_ex\n";
    vector<vector<int>> input = {
        {1,1,1,0,0,0},
        {0,1,0,0,0,0},
        {1,1,1,0,0,0},
        {0,0,2,4,4,0},
        {0,0,0,2,0,0},
        {0,0,1,2,4,0}
    };
    int calcResult = hourglassSum(input);
    int expResult = 19;
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

