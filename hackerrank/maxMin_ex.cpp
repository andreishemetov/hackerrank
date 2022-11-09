//
//  maxMin_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 08/11/2022.
//

#include "maxMin_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int result = INT_MAX;
    for (int i=0, j=k-1; j<arr.size(); i++, j++){
        int diff = arr[j]-arr[i];
        if (diff < result) {
            result = diff;
        }
    }
    return  result;
}


void maxMin_ex(){
    cout << "maxMin_ex\n";
    vector<int> arr = {1,2,3,4,10,20,30,40,100,200};
    int k = 4;
    int calcResult = maxMin(k, arr);
    int expResult = 3;
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<"calcResult:"<<calcResult<<" expResult:"<<expResult<<" >> Test "<<result<<endl;
    cout<<endl;
}
