//
//  sparse_arrays_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 23/12/2022.
//

#include "sparse_arrays_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> matchingsStrings(vector<string> strings, vector<string> queries) {
    vector<int> result;
    for (int i=0; i<queries.size(); i++){
        int count = (int)std::count(strings.begin(), strings.end(), queries[i]);
        result.push_back(count);
    }
    return result;
}

void sparse_arrays_ex(){
    cout << "sparse_arrays_ex\n";
    vector<string> strings = {"ab", "ab", "abc"};
    vector<string> queries = {"ab", "abc", "bc"};
    vector<int> calcResult = matchingsStrings(strings, queries);
    vector<int> expResult = {2,1,0};
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
