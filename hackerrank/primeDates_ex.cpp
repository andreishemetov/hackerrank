//
//  primeDates_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 11/11/2022.
//

#include "primeDates_ex.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int month[15];

void updateLeapYear(int year) {
    if(year % 400 == 0) {
        month[2] = 29;
    } else if(year % 100 == 0) {
        month[2] = 28;
    } else if(year % 4 == 0) {
        month[2] = 29;
    } else {
        month[2] = 28;
    }
}

void storeMonth() {
    month[1] = 31;
    month[2] = 28;
    month[3] = 31;
    month[4] = 30;
    month[5] = 31;
    month[6] = 30;
    month[7] = 31;
    month[8] = 31;
    month[9] = 30;
    month[10] = 31;
    month[11] = 30;
    month[12] = 31;
}

int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    storeMonth();

    int result = 0;

    while(true) {
        int x = d1;
        x = x * 100 + m1;
        x = x * 10000 + y1;
        if(x % 4 == 0 || x % 7 == 0) {
            result = result + 1;
        }
        if(d1 == d2 && m1 == m2 && y1 == y2) {
            break;
        }
        cout<<d1<<"-"<<m1<<"-"<<y1<<endl;
        updateLeapYear(y1);
        d1 = d1 + 1;
        if(d1 > month[m1]) {
            m1 = m1 + 1;
            d1 = 1;
            if(m1 > 12) {
                y1 =  y1 + 1;
                m1 = 1;
            }
        }
    }
    return result;
}


void primeDates_ex(){
    string dates = "02-08-2025 04-09-2025";
    int d1, m1, y1, d2, m2, y2;
    for(int i = 0; i < dates.size(); i++) {
        if(dates[i] == '-') {
            dates[i] = ' ';
        }
    }
    stringstream str;
    str << dates;
    str >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

    int result = findLuckyDates(d1, m1, y1, d2, m2, y2);
    cout << result << endl;
}



