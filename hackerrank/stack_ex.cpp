//
//  stack_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 25.12.22.
//

#include "stack_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string isBalanced(string s) {
    stack<char> box;
    for(int i=0; i<s.size(); i++){
        if (box.empty() || box.top() != s[i]){
            box.push(s[i]);
        } else {
            box.pop();
        }
    }
    return box.empty() ? "YES" : "NO";
}

void stack_ex(){
    string s = "{[()]}";
    string result = isBalanced(s);
}
