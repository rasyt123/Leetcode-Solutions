// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        recursehelper(0, nums, subsets, subset);
        return subsets;
    }
    
    
    void recursehelper(int ind, vector<int>& nums, vector<vector<int>>& subsets, vector<int> subset) {
        if (ind == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        recursehelper(ind + 1, nums, subsets, subset);
        subset.pop_back();
        recursehelper(ind + 1, nums, subsets, subset);
        return;
    }
};