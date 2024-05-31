//
//  dynamicArray_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 10.11.22.
//

#include "dynamicArray_ex.hpp"
#include <iostream>
#include <vector>

using namespace std;


vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> result = {};
    int lastAnswer = 0;
    vector<vector<int>> arr(n);
    
    for(int i=0; i<queries.size(); i++){
        int q = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        
        int idx = (x ^ lastAnswer) % n;
        if (q==1){
            arr[idx].push_back(y);
        } else {
            int j = y % arr[idx].size();
            lastAnswer = arr[idx][j];
            result.push_back(lastAnswer);
        }
    }
    
    return result;
}


void dynamicArray_ex(){
    cout << "dynamicArray_ex\n";
    int n = 2;
    vector<vector<int>> queries = {
        {1,0,5},
        {1,1,7},
        {1,0,3},
        {2,1,0},
        {2,1,1}
    };
    vector<int> calcResult = dynamicArray(n, queries);
    vector<int> expResult = {7,3};
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}


