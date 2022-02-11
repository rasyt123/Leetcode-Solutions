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
     vector<int> max;
     for (int i = 0; i < t; i++) {
         if (i == t - 1) {
           ;
         } else {
            for (int j = 0; j < t; j++) {
              product = nums[i];
              for (int k = i + 1; k < j + 2 && k < t; k++) {
                  product = product * nums[k];
              }
              max.push_back(product);
            }
        }
     }
     a = *max_element(max.begin(), max.end());
     return a;
    }
};