//
//  sorting_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 25.12.22.
//

#include "linkedList_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>

using namespace std;


void bubbleSort(int *arr, int size){
    for (int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if (arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sorting_ex(){
    const int sz = 10;
    int arr[sz] = {52,45,32,64,12,87,78,98,23,7};
    bubbleSort(arr, sz);
}
//int [] intArray = new int [] {52,45,32,64,12,87,78,98,23,7};
