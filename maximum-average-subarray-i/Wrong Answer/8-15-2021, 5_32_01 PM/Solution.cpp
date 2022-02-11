// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        /*
        
        Sliding Window Approach
        Im given an integer k 
        
        1. Keep expanding the window until we've hit integer k
        2. Slide one item from the left once we've calculated
        a window of size k
        3. Calculate the average of those items;
        4. Save the average somewhere
        
        */
     
        
        int minWindowSize = 1000;
        float currentWindowSum = 0;
        int windowStart = 0;
        float currwinaverage = -100000;
        float average;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            currentWindowSum += nums[windowEnd];
            if (windowEnd >= k - 1) {
                average = currentWindowSum / k;
                currwinaverage = max(currwinaverage, average);
                currentWindowSum -= nums[windowEnd - (k - 1)];
            }
        }
        
        return currwinaverage;

    }
        
    
};