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
#include <sstream>

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
    vector<int> v = {2,3,4,5,6,7}; int q = 3; // result {2,4,6,3,5,7}
//    vector<int> v = {3,4,7,6,5}; int q = 1; // result {4,6,3,7,5}
//    vector<int> v = {3,3,4,4,9}; int q = 2; // result {4,4,9,3,3}
    waiter(v, q);
}

/*
 https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150
 71. Simplify Path
 Given an absolute path for a Unix-style file system, which begins with a slash '/', transform this path into its simplified canonical path.
 In Unix-style file system context, a single period '.' signifies the current directory, a double period ".." denotes moving up one directory level, and multiple slashes such as "//" are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous rules (like "...") as valid names for files or directories.

 The simplified canonical path should adhere to the following rules:

 It must start with a single slash '/'.
 Directories within the path should be separated by only one slash '/'.
 It should not end with a slash '/', unless it's the root directory.
 It should exclude any single or double periods used to denote current or parent directories.
 Return the new path.

 Example 1:
 Input: path = "/home/"
 Output: "/home"

 Example 2:
 Input: path = "/home//foo/"
 Output: "/home/foo"

 Example 3:
 Input: path = "/home/user/Documents/../Pictures"
 Output: "/home/user/Pictures"
  */

string simplifyPath(string path) {
    stringstream data(path);
    string line;
    vector<string> result;
    while(getline(data,line,'/')) {
        if (!line.empty() && line != "."){
            if (line == ".."){
                if (!result.empty()) result.pop_back();
            } else {
                result.push_back(line);
            }
        }
    }
    if (result.empty()) return "/";
    string rpath = "";
    for (int i=0; i<result.size(); i++){
        rpath += "/" + result[i];
    }
    
    return rpath;
}

void simplifyPath_ex(){
    cout << "simplifyPath_ex\n";
    string path = "/.../a/../b/c/../d/./";
    string result = simplifyPath(path);
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
