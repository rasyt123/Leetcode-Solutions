// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        /*
        Binary Search Problem 
        A staircase happens when the height o
        
        Dont look at the height, look at the staircase sideways
        
        [3, 2, 0]
         0  1   2
        First Staircase
        
        
        [4, 3, 1]
        Second Staircase
        
        
        1 2 2
        
        1 2 3 2
        
        1 2 2 3 
        sort array and return maximum index
        
        
        We create an array with all the slowly increasing elements. if we find that we can't increase the 
        space for the row, then just subtract n by the number of remaining coins and inserting it into the array.
         
         
        Then we use binary search.
        if it's binary search, how about finding the largest element in here and returning the index + 1
    
        */
        vector<int> coins;
        int coinsum = n;
        int i = 1;
        while (i < coinsum) {
            coins.push_back(i);
            coinsum -= i;
            i++;
        }
        coins.push_back(coinsum);
        sort(coins.begin(), coins.end());
        return coins[coins.size() - 1];
        
        
        
    }
};