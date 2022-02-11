// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //O(n)

        int k = 1;
        int max_sum = 0;
        int window_sum;
        int othersum;
        othersum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            max_sum = 0;
            for (int j = 0; j < k; j++) {
                max_sum += nums[j];
            }
            window_sum = max_sum;
            for (int a = k; a < nums.size(); a++) {
                window_sum += nums[a] - nums[a - k];
                max_sum = max(max_sum, window_sum);
                if (max_sum > othersum) {
                    othersum = max_sum;
                }

            }
            ++k;
        }
        
        if (max_sum > othersum) {
            othersum = max_sum;
        }

        return othersum;

    }
};