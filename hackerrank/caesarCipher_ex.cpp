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
    for (int i=0; i < s.length(); i++){
        char start = 'A';
        char end = 'Z';
        char l = s[i];
        int d = k % 26;
        if (l >= start && l <= end) {
            int nl = l+d;
            if (nl-end >0) {
                s[i]=start+nl-end-1;
            }  else {
                s[i] = nl;
            }
        }
        start = 'a';
        end = 'z';
        if (l >= start && l <= end) {
            int nl = l+d;
            if (nl-end >0) {
                s[i]=start+nl-end-1;
            }  else {
                s[i] = nl;
            }
        }
    }
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

