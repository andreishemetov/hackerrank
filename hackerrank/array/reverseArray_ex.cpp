//
//  reverseArray_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 23/12/2022.
//

#include "reverseArray_ex.hpp"
#include <iostream>
#include <vector>

using namespace std;


vector<int> reverseArray(vector<int> input) {
    int *b = &input[0];
    unsigned long sz = input.size() - 1;
    int *e = &input[0] + sz;
    
    while (b<e) {
        int v = *b;
        *b = *e;
        *e = v;
        b++;
        e--;
    }
    return input;
}

void reverseArray_ex(){
    cout << "reverseArray_ex\n";
    vector<int> input = {1,4,3,2,7};
    vector<int> calcResult = reverseArray(input);
    vector<int> expResult = {7,2,3,4,1};
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
