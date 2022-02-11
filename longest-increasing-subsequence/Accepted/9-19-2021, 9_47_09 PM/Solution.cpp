// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int result;
        int ans = INT_MIN;
        vector<int> dp(nums.size(), 0);
        result = findls(0, nums, dp, ans);
        if (ans == INT_MIN) {
            return 1;
        }
        return ans;

    }


    int findls(int index, vector<int>& nums, vector<int>& dp, int& ans) {
        int maximum = INT_MIN;
        int length;
        int element;

        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != 0) {
            return dp[index];
        }
        element = nums[index];
        for (int i = index; i < nums.size() - 1; i++) {
            length = findls(i + 1, nums, dp, ans);
            if ((length >= maximum and nums[i + 1] > element)) {
                    maximum = 1 + length;
                    ans = max(ans, maximum);
            }
        }

        if (maximum == INT_MIN) {
            dp[index] = 1;
        } else {
            dp[index] = maximum;
        }
        return dp[index];

    }
};