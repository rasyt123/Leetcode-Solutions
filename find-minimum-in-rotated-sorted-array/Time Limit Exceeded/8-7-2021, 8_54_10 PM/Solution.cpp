// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low;
        int high;
        int minimum;
        if(nums.size() == 1) {
            return nums[0];
        } else if(nums.size() == 2) {
            if (nums[0] > nums[1]) {
                minimum = nums[1];
            } else {
                minimum = nums[0];
            }
            return minimum;
        }
        low = 0;
        high = nums.size() - 1;
        minimum = nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[high] < minimum) {
                minimum = nums[high];
            }
            if (nums[low] < minimum) {
                minimum = nums[low];
            }
            if (nums[mid] < minimum) {
                minimum = nums[mid];
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