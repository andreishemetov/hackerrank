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
#include <map>

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

/*
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?submissionId=1280563443
 Best time to Buy and Sell Stock
 You are given an array prices where prices[i] is the price of a given stock on the ith day.
 You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
 Input: prices = [7,1,5,3,6,4]
 Output: 5
 
 */

int maxProfit(vector<int> prices) {
    int bp = prices.front();
    int profit = 0;
    for (int i=1; i<prices.size(); i++) {
        int p = prices[i];
        if (p-bp > profit) {
            profit = p - bp;
        }
        if (p<bp) {
            bp = p;
        }
    }
    return profit;
}

void maxProfit_ex() {
    cout << "maxProfit_ex\n";
    vector<int> prices = {7,1,5,3,6,4};
    int result = maxProfit(prices);
    cout<<"maxProfit "<<result<<endl;
}

/*
 https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
 Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 
 Input: nums = [0,1,2,2,3,0,4,2], val = 2
 Output: 5, nums = [0,1,3,0,4,_,_,_]
 
 */

int removeElement(vector<int>& nums, int val) {
    int last = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[last] = nums[i];
            last++;
        }
    }
    return last;
}

void removeElement_ex() {
    cout << "removeElement_ex\n";
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int result = removeElement(nums, val);
    cout<<"result "<<result<<endl;
}

/*
 Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
 Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
 Return k after placing the final result in the first k slots of nums.
 Input: nums = [0,0,1,1,1,1,2,3,3]
 Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 */

int removeDuplicates(vector<int>& nums, int canRepeatNumber) {
    int last = -1;
    int repeatNumber = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (last < 0 || nums[i] != nums[last] || (nums[i] == nums[last] && repeatNumber < canRepeatNumber)) {
            if (last < 0 || nums[i] != nums[last]) {
                repeatNumber = 1;
            } else {
                repeatNumber ++;
            }
            last++;
            nums[last] = nums[i];
            
        }
    }
    return last + 1;
}

int removeDuplicates_leetCode(vector<int>& nums, int canRepeatNumber) {
    //Edge case: If length of nums is less than or equal to canRepeatNumber, return length
    if (nums.size() <= canRepeatNumber) return (int)nums.size();
       
    // Initialize slow pointer
    int slow = canRepeatNumber;
    
    // Iterate through the array with fast pointer
    for (int fast = canRepeatNumber; fast < nums.size(); fast++){
        // If current element is not equal to element at slow - canRepeatNumber
        if (nums[fast] != nums[slow-canRepeatNumber]){
            // Update element at slow and increment slow
            nums[slow] = nums[fast];
            slow += 1;
            
        }
    }
    return slow;
}

void removeDuplicates_ex() {
    cout << "removeDuplicates_ex\n";
    vector<int> nums = {0,0,1,2,2,2,3,3,4,6,6,10,10,10,10,12,13};
    int canRepeatNumber = 2;
    int result = removeDuplicates_leetCode(nums,canRepeatNumber);
    cout<<"result "<<result<<endl;
}

/*
 Rotate array
 Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 Input: nums = [1,2,3,4,5,6,7], k = 3
 Output: [5,6,7,1,2,3,4]
 */

void rotateArray_sol1(vector<int>& nums, int k) {
    int b = 0;
    int e = (int)nums.size() - 1;
    while (b<e) {
        int v = nums[b];
        nums[b] = nums[e];
        nums[e] = v;
        b++;
        e--;
    }
    
    b = 0;
    e = k - 1;
    while (b<e) {
        int v = nums[b];
        nums[b] = nums[e];
        nums[e] = v;
        b++;
        e--;
    }
    
    b = k;
    e = (int)nums.size() - 1;
    while (b<e) {
        int v = nums[b];
        nums[b] = nums[e];
        nums[e] = v;
        b++;
        e--;
    }
}

void rotateArray_sol2(vector<int>& nums, int k) {
    vector<int> result(nums.size());
    for (int i=0; i<nums.size(); i++){
        int j = (i+k) % nums.size();
        result[j] = nums[i];
    }
    nums = result;
}


void rotateArray_ex(){
    cout << "rotateArray_ex\n";
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotateArray_sol2(nums, k);
    vector<int> expResult = {5,6,7,1,2,3,4};
    string result = nums == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

/*
 https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
 Majority Element
 Given an array nums of size n, return the majority element.
 The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
  Input: nums = [2,2,1,1,1,2,2]
 Output: 2
  */

int majorityElement(vector<int>& nums) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    return nums[n/2];
}

int majorityElement_leetcode(vector<int>& nums) {
    int count = 0;
            int candidate = 0;
            
            for (int num : nums) {
                if (count == 0) {
                    candidate = num;
                }
                
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
            
            return candidate;
}


void majorityElement_ex(){
    cout << "majorityElement_ex\n";
    vector<int> nums = {2,2,1,1,1,2,2};
    int result = majorityElement_leetcode(nums);
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

/*
 https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 You can return the answer in any order.

 Example 1:

 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
  */

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> heap;
    for (int i=0; i<nums.size(); i++){
        int fv = target - nums[i];
        if (heap.contains(fv)){
            return {heap[fv], i};
        }
        heap[nums[i]] = i;
    }
    return {};
}

void twoSumt_ex(){
    cout << "twoSumt_ex\n";
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout <<">> Test "<<endl;
    cout<<endl;
}
