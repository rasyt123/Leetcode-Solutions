// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        /*
        1 + 2 + ... + k = k(k + 1)/2 coins
        This is the summation formula for the num
        
        Find the maximum k such that k(k + 1)/2 <= N
        If the sum is 8, then the 
        1 + 2 + 3 + 4 + 5 + 6 + 7 + 8
        
        1 2 3 4 
        
        [3, 4]
         L
         M
         R
        but not 1 + 2 + 3 + 4
        [1, 2, 3, 4]
         
        if the sum at the middle (using summation formula) is less than n 
            look at the right side of the sorted array
        if the sum at the middle is bigger than n, 
            look at the left side of the sorted array 
        
        */
       
        int l = 0, r = n;
        int mid;
        int sum;
        while (l < r) {
            mid = l + (r - l) / 2;
            sum = (mid * (mid + 1)) / 2;
            if (sum == n) {
                return mid;
            } else if (sum < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
        
        
        
    }
};