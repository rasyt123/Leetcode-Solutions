// https://leetcode.com/problems/maximum-product-subarray

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>



class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int a;
     int t = nums.size();
     int product = 1;
     int maxproduct = nums[0];
     for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
             product = nums[i];
             for (int k = i + 1; k < j + 2 && k < t; k++) {
                  product = product * nums[k];
             }
             if (product >= maxproduct) {
                 maxproduct = product;
             }
            }
        }
         return maxproduct;
    }
};