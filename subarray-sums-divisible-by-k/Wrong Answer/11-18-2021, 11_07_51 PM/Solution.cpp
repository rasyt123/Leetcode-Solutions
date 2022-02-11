// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
        Sliding window or some prefix sum problem 
        
        Prefix Sum::
        
        [4, 9, 9, 7, 4, 5]
        counter = 0
        
        check if the sum mod k is equal to zero 
        for each element in the modified prefix sum array:
            currsum = current elemtn
            if sum % k == 0:
                counter += 1;
            for (int i = 0; i <= element of modified prefux; i++)
                subtract current element from currsum 
                if sum % k == 0:
                    counter += 1:
        */
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            int currsum = nums[i];
            if (currsum % k == 0) {
                count += 1;
            }
            for (int j = 0; j < i; j++) {
                currsum -= nums[j];
                if (currsum % k == 0) {
                    count += 1;
                }
                
            }
        }
        return count;
    }
};