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
#include <deque>

using namespace std;

bool isBalancedPair(char left, char right){
    return ((left == '(' && right == ')') ||
            (left == '{' && right == '}') ||
            (left == '[' && right == ']'));
}

string isBalanced(string s) {
    stack<char> box;
    for(int i=0; i<s.size(); i++){
        if (box.empty() || !isBalancedPair(box.top(), s[i])){
            box.push(s[i]);
        } else {
            box.pop();
        }
    }
    return box.empty() ? "YES" : "NO";
}



stack<int> sumsStack(vector<int> v){
    stack<int> s;
    int sum = 0;
    vector<int>::iterator it = v.end();
    while (it != v.begin()) {
        --it;
        sum += *it;
        s.push(sum);
    }
    return s;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    vector<stack<int>> vs;
    vs.push_back(sumsStack(h1));
    vs.push_back(sumsStack(h2));
    vs.push_back(sumsStack(h3));
    
    while (!vs[0].empty() && !vs[1].empty() && !vs[2].empty()) {
        int maxIndex = 0;
        if (vs[0].top() == vs[1].top() && vs[1].top() == vs[2].top()) return vs[0].top();
        for (int i=1; i<3; i++){
            if (vs[i].top() > vs[maxIndex].top()){
                maxIndex = i;
            }
        }
        vs[maxIndex].pop();
    }
    return  0;
}

bool isPrimeNumber(int n){
    for(int i = 2; i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> answers;
    std::reverse(number.begin(), number.end());
    stack<int> numbers(deque<int>(number.begin(), number.end()));
    stack<int> draft = numbers;
    
    int n = 2;
    int i = 0;
    while (i < q) {
        if (isPrimeNumber(n)){
            draft = numbers;
            numbers = stack<int>();
            while (!draft.empty()){
                int value = draft.top();
                if (value % n == 0) {
                    answers.insert(answers.end(), value);
                } else {
                    numbers.push(value);
                }
                draft.pop();
            }
            i++;
        }
        n++;
    }
    
    unsigned long end = answers.size();
    while (!numbers.empty()){
        answers.insert(answers.begin() + end, numbers.top());
        numbers.pop();
    }
    
    return  answers;

}

void stack_ex(){
//    isBalanced
//    string s = "{[{()]}";
//    string result = isBalanced(s);

//    equalStacks
//    vector<int> h1 = {3,2,1,1,1};
//    vector<int> h2 = {4,3,2};
//    vector<int> h3 = {1,1,4,1};
//    int h = equalStacks(h1, h2, h3);
    
//    waiter
//    vector<int> v = {2,3,4,5,6,7}; int q = 3; // result {2,4,6,3,5,7}
//    vector<int> v = {3,4,7,6,5}; int q = 1; // result {4,6,3,7,5}
//    vector<int> v = {3,3,4,4,9}; int q = 2; // result {4,4,9,3,3}
//    waiter(v, q);
}
