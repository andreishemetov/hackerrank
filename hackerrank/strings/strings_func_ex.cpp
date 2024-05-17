//
//  strings_func_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetau on 17/05/2024.
//

#include "strings_func_ex.hpp"
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;


string superReducedString(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (result.empty()) {
            result += s[i];
        } else {
            if (result[result.length() -1] == s[i]) {
                result.pop_back();
            } else {
                result += s[i];
            }
        }
    }
    return result.empty() ? "Empty String" : result;
}

void superReducedString_ex(){
    cout << "superReducedString_ex\n";
    string input = "aaabccddd";
    string expected = "abd";
    string calculated = superReducedString(input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

int camelcase(string s) {
    int count = 0;
    if (!s.empty()) {
        count ++;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < 'a') {
                count++;
            }
        }
    }
    return count;
}

void camelcase_ex() {
    cout << "camelcase_ex\n";
    string input = "saveChangesInTheEditor";
    int expected = 5;
    int calculated = camelcase(input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

int strongPassword(int n, string password) {
    string specialStr = "!@#$%^&*()-+";
    set<char> specialSet(specialStr.begin(), specialStr.end());
    
    bool hasNumbers = false;
    bool hasSpecial = false;
    bool hasLower = false;
    bool hasUpper = false;
    int requiredSymbols = 4;
    
    int i = 0;
    while (!(i == password.length() || (i > 6 && requiredSymbols == 0))) {
        if (password[i] >= 'a' && password[i] <= 'z' && !hasLower){
            hasLower = true;
            requiredSymbols --;
        } else if (password[i] >= 'A' && password[i] <= 'Z' && !hasUpper){
            hasUpper = true;
            requiredSymbols --;
        } else if (password[i] >= '0' && password[i] <= '9' && !hasNumbers){
            hasNumbers = true;
            requiredSymbols --;
        } else if (specialSet.count(password[i]) > 0 && !hasSpecial){
            hasSpecial = true;
            requiredSymbols --;
        }
        i++;
    }
    int result = max((int)(6-password.length()), requiredSymbols);
    return result;
}

void strongPassword_ex() {
    cout << "strongPassword_ex\n";
    string input = "#HackerRank";
    int expected = 1;
    int calculated = strongPassword((int)input.length(), input);
    string result = calculated == expected ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}
