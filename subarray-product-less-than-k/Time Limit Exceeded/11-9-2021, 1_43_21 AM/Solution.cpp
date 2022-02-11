// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        We use two pointers
        one l pointer and one r pointer

        l and r start at the front of the list

  product = 1;
  l = 0
  r = 0
  while l or r are less than the list size
        if the product is greater than k or r is greater than the length of numss.size() - 1;
            increment l by 1
            set r = l
            reset the product
            product = 1;

        product * = nums[r];
        if product is within range:
            we add one to the counter

        increment r by 1
        */

        int product = 1;
        int l = 0;
        int r = 0;
        int count = 0;
        while (l < nums.size() or r < nums.size()) {
            if (l == nums.size() - 1 and r > nums.size() - 1) {
                break;
            }
            if (product >= k or r > nums.size() - 1) {
                l += 1;
                r = l;
                product = 1;
            }
            product *= nums[r];
            if (product < k) {
                count += 1;
            }
            r += 1;

        }
        return count;
    }
};