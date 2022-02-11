// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low;
        int high;
        int minimum;
        low = 0;
        high = nums.size() - 1;
        minimum = nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (high < minimum) {
                minimum = high;
            }
            if (low < minimum) {
                minimum = low;
            }
            
            if (nums[low] > nums[high] and nums[mid] < nums[high]) {
                minimum = nums[mid];
                return minimum;
            }
            
            if (nums[high] > nums[mid]) {
                 high = mid - 1;
            }
            if (nums[mid] > nums[low]) {
                 low = mid + 1;
            }
        }
        
        return minimum;
        
    }
};