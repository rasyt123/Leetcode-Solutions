// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        1D dp o(n) space 
        We need to start robbing from the end 
        
        
        When at 9 dollars, I can rob the house with 1 only  
        
        
        Subproblems:
            when we want to take the maximum profit robbing 
            a particular house, we split this into sub problems 
            where we can take the max profit of the houses after the current, and use 
            that to build a solution for the maximum profit of the house we're on 
        
        Optimal Substructure:
            The maximum profit that we can make is the
            current amount of money + 2 houses to the right
            starting from teh end of the houses
            
             Ni + (i + 2)
            
            if there is only one house:
                we can only rob that house 
            if there is no house 2 spaces down, then 
                we can only rob the current house
            if 
            
            base cases:
                the two houses at the end can only rob itself 
                when we move down to an
                
            dp[]
            dp[]
            
            
            [1]
            [3, 1]
            
            [2, 7, 9, 3, 1]
            [2]
            [9, 3 , 1]
            
            [3, 1]  3
            [1]  1
            [9, 3, 1] 9 + 1 = 10
            [7, 9 , 3 1] 
            
                    
                 profit = max(profit,nums[i] + dp[i + 2])
                 dp[i] = profit;
        */
        
        vector<int> dp(nums.size(), 0);
        int profit = 0;
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[nums.size() - 1], nums[nums.size() - 2]);
        }
        dp[nums.size() - 1] = nums[nums.size() - 1];
        dp[nums.size() - 2] = nums[nums.size() - 2];
        profit = max(nums[nums.size() - 1], nums[nums.size() - 2]);
        for (int i = nums.size() - 3; i >= 0; i--) {
            dp[i] = nums[i] + dp[i + 2];
            profit = max(profit, dp[i]);
        }
        return profit;
        
    }
};