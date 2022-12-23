//
//  array_manipulation_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 23/12/2022.
//

#include "array_manipulation_ex.hpp"
#include <iostream>
#include <vector>

using namespace std;


long arrayManipulation(int n, vector<vector<int>> queries) {
    long maxEl = 0;
    vector<long> arr(n, 0);
    for (int q = 0; q < queries.size(); q++){
        int b = queries[q][0] - 1;
        int e = queries[q][1] - 1;
        int value = queries[q][2];
        for (int i=b; i<=e; i++){
            arr[i] += value;
            if (arr[i] > maxEl) maxEl = arr[i];
        }
    }
    return maxEl;
}

void array_manipulation_ex(){
    cout << "array_manipulation_ex\n";
    int n = 5;
    vector<vector<int>> queries = {
        {1,2,100},
        {2,5,100},
        {3,4,100}
    };
    long calcResult = arrayManipulation(n, queries);
    long expResult = 200;
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
