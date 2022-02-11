// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, r, m;
        l = 0; 
        r = nums.size() - 1;
        int targetitem = -1;
        
        while (l <= r) {
            if (nums[l] == target) {
                targetitem = l;
            }
            m = l + (r - l) / 2;
            if (target > nums[l] and target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        
        
        //if the target is greater than the low but less than the mid
        // search through the left subarray
        //otherwise
        //    search through the right subarray 
        
        
        
        return targetitem;
        
        
    }
};