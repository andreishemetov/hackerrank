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

void insertionSort(int *arr, int size){
    int j = 0;
    for (int i=1; i<size; i++){
        j = i;
        while (j>0 && arr[j]<arr[j-1]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

vector<int> quickSort(vector<int> v){
    if (v.size() < 2) {
        return v;
    }
    int pivot = v.front();
    vector<int> less;
    vector<int> greater;
    for (int i=1; i<v.size(); i++){
        if (v[i] < pivot) {
            less.push_back(v[i]);
        } else {
            greater.push_back(v[i]);
        }
    }
    vector<int> result = quickSort(less);
    result.push_back(pivot);
    vector sortGreater = quickSort(greater);
    result.insert(result.end(), sortGreater.begin(), sortGreater.end());
    return result;
}


// https://tproger.ru/articles/zachem-nuzhny-algoritmy-sortirovki/
void sorting_ex(){
    const int sz = 10;
    int arr[sz] = {52,45,32,64,12,87,78,98,23,7};
    vector<int> vect(arr, arr+sz);
//    bubbleSort(arr, sz);
//    insertionSort(arr, sz);
    vector<int> v = quickSort(vect);
    printf("FINISH!!!");
}
