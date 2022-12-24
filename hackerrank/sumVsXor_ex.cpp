//
//  sumVsXor_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 24.11.22.
//

#include "sumVsXor_ex.hpp"
#include <iostream>
#include <cmath>

using namespace std;


long sumVsXor(long n) {
    int countZeroBits = 0;
    while (n) {
        if ((n&1) == 0) countZeroBits++;
        n = n>>1;
    }
    long result = pow(2,countZeroBits);
    return result;
}

// https://medium.com/@mlgerardvla/hackerrank-sum-vs-xor-63e18dbd11cf
void sumVsXor_ex(){
    cout << "sumVsXor_ex\n";
    long n = 1111111113456;
    long calcResult = sumVsXor(n);
    long expResult = 16777216;
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<"calcResult:"<<calcResult<<" expResult:"<<expResult<<" >> Test "<<result<<endl;
    cout<<endl;
}
