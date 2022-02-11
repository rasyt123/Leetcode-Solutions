// https://leetcode.com/problems/target-sum



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int numways = 0;
        int* numwaysptr;
        numwaysptr = &numways;
        dfs(nums, target, 0, 0, numwaysptr);
        return numways;
        
    }
    void dfs(vector<int>& nums, int target, int index, int totalsum, int* numwaysptr);
};


void Solution::dfs(std::vector<int>& nums, int target, int index, int totalsum, int* numwaysptr) {
    if (index > nums.size()) {
        return;
    }
    if (target == totalsum && index == nums.size()) {
        ++(*numwaysptr);
    }
    else {
        dfs(nums, target, index + 1, totalsum + nums[index], numwaysptr);
        dfs(nums, target, index + 1, totalsum - nums[index], numwaysptr);
    }
}