//
//  array_func_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 28.05.24.
//

#include "array_func_ex.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 */

void mergeTwoSortArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(j >= 0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
    }


void mergeTwoSortArrays_ex() {
    cout << "mergeTwoSortArrays_ex\n";
    vector<int> nums1 = {1,2,3,6,10,13};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    mergeTwoSortArrays(nums1, m, nums2, n);
    cout<<endl;
}

/*
 Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.
 
 Lily decides to share a contiguous segment of the bar selected such that:
 
 The length of the segment matches Ron's birth month, and,
 The sum of the integers on the squares is equal to his birth day.
 Determine how many ways she can divide the chocolate.
 
 Example
 
 
 
 Lily wants to find segments summing to Ron's birth day,  with a length equalling his birth month, . In this case, there are two segments meeting her criteria:  and .
 */

int subarrayDivision(vector<int> s, int d, int m) {
    int n = 0;
    for(int i=0; i<=s.size() - m; i++){
        long sum = 0;
        for(int j=i; j<i+m; j++){
            sum+=s[j];
        }
        if (sum == d) n++;
    }
    return n;
}

void subarrayDivision_ex() {
    cout << "subarrayDivision_ex\n";
    vector<int> v = {2,2,1,3,2};
    int d = 4;
    int m = 2;
    int result = subarrayDivision(v, d, m);
    cout<<endl;
}
