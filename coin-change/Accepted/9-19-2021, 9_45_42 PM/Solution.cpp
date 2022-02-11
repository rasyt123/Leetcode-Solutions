// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) {
        return 0;
      }
      
      vector<int> dp(amount + 1);
      return coinChange(coins, amount, dp);
    }
    
    
  private:
    int coinChange(vector<int>& coins, int remainder, vector<int>& dp) {
      if (remainder < 0) {
        return -1;
      }
    
     
      if (remainder == 0) {
        return 0;
      }
  
  
      if (dp[remainder] != 0) {
        return dp[remainder];
      }
  
     
      int minimum = INT_MAX;
      for (int coin: coins) {
        int changeResult = coinChange(coins, remainder - coin, dp);
        if (changeResult >= 0 && changeResult < minimum) {
          minimum = 1 + changeResult;
        }
      }
 
      dp[remainder] = (minimum == INT_MAX) ? -1 : minimum;
  
      return dp[remainder];
    }
};


