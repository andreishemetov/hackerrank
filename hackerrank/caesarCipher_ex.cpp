//
//  caesarCipher_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 08/11/2022.
//

#include "caesarCipher_ex.hpp"
#include <iostream>

using namespace std;


string caesarCipher(string s, int k) {
    char b2 = 'a';
    char e2 = 'z';
    char b1 = 'A';
    char e1 = 'Z';
    
    printf("%d %d %d %d\n", b1, e1, b2, e2);
    
    for (int i=0; i<s.size(); i++){
        if (s[i] >= b1 && s[i] <= e1) {
            char c = (s[i] + k - b1) % (e1 - b1 + 1) + b1;
            s[i] = c;
        } else if (s[i] >= b2 && s[i] <= e2){
            int c = (s[i] + k - b2) % (e2 - b2 + 1) + b2;
            s[i] = char(c);
        }
    }
    printf("%s\n",s.c_str());
    return s;
}

void caesarCipher_ex(){
    cout << "caesarCipher_ex\n";
    int k = 62;
    string s = "!m-rB`-oN!.W`cLAcVbN/CqSoolII!SImji.!w/`Xu`uZa1TWPRq`uRBtok`xPT`lL-zPTc.BSRIhu..-!.!tcl!-U";
    string result = caesarCipher(s, k);
    cout<<"result: "<<result<<endl;
    string expected_result = "!w-bL`-yX!.G`mVKmFlX/MaCyyvSS!CSwts.!g/`He`eJk1DGZBa`eBLdyu`hZD`vV-jZDm.LCBSre..-!.!dmv!-E";
    cout << endl;
}

