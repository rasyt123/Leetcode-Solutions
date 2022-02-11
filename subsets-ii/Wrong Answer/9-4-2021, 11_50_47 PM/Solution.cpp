// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        Turn this into an indexed based solution 
        I can choose whether to put an item into a subset or leave it out
        I can use backtracking with depth first search. 
        
        
    
        When including and excluding items at a particular index  to build a subset, we get two options. If we run these top options on 
        every single subset, then we will have tried all the combinations.
        
        Parameters 
        Base case:
        f
        if the index is out of range:
            add the subset to the list of subsets
        
        push the item into the subset
        recursion(add the index + 1, );
        Exclude the item from the subset that we just added so we get a fresh combination.
        recursion(add the current index + 1, );
        return;
        */
        vector<int> subsetDup;
        vector<vector<int>> dupesets;
        dfs(0, subsetDup, nums, dupesets);
        return dupesets;
    }
    
    
    void dfs(int currindex, vector<int> subsetDup, vector<int>& nums, vector<vector<int>>& dupesets) {
        if (currindex == nums.size() and !subsetexists(subsetDup, dupesets)) {
            dupesets.push_back(subsetDup);
            return;
        }
        
         if (currindex >= nums.size()) {
            return;
        }
        subsetDup.push_back(nums[currindex]);
        dfs(currindex + 1, subsetDup, nums, dupesets);
        subsetDup.pop_back();
        dfs(currindex + 1, subsetDup, nums, dupesets);
        return;
    }
    
    bool subsetexists(vector<int> subsetDup, vector<vector<int>>& dupesets) {
        for (vector<int>& item : dupesets) {
            if (item == subsetDup) {
                return true;
            }
        }
        return false;
    }
};