// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit;
       int l, r;
       int maxP = 0;
       l = 0;
       r = 1;
        
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r += 1;
        }
        return maxP;
       
    }
};