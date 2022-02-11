// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        long max_global = nums[0], max_local = nums[0], min_local = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tie(min_local, max_local) = minmax<long>({nums[i], nums[i] * max_local, nums[i] * min_local});
            max_global = max(max_global, max_local);
        }
        return max_global;
    }
};