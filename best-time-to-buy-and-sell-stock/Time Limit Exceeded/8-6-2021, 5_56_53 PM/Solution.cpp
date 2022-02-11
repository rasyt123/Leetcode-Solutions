// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Use hashtable to store all of the profits 
        //Calculate all of the profits for each 
        // stock that you buy 
        //o(n^2)
        //max()
    
        //2 pointers o(n) solution
        //sort the array first 
        // [7, 1, 5, 3, 6, 4]
        //  0  1 2   3   4 5
        //the max profit is the highest stock minus the smallest stock
        
        //notallowed profit = a[0] - a[1];
        //
        //
        // secondprofit = a[index] - a[i] 
        //for each item in prices;
        //     profit = maxprofit(a[i], i + 1)
        //     if (profit )
        // return profit
        int maxprofit;
        maxprofit = 0;
        int profit;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                profit = prices[j] - prices[i];
                maxprofit = max(maxprofit, profit);
            }
        }
        return maxprofit;
        
        
        
        
       
    }
};