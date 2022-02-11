// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int bsl(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int m = l+(r-l)/2;
            if (nums[m]==target && (m==0 || nums[m-1]!=target)) {
                return m;
            }
            else if (nums[m]>=target) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return -1;
        
    }
    
    int bsr(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int m = l+(r-l)/2;
            if (nums[m]==target && (m==nums.size()-1 || nums[m+1]!=target)) {
                return m;
            }
            else if (nums[m]<=target) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = bsl(nums, target);
        if (l==-1) {
            return {-1, -1};
        }
        int r = bsr(nums, target);
        return {l, r};
    }
};