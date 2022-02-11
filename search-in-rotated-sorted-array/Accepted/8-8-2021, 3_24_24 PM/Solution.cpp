// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, r, m;
        l = 0;
        r = nums.size() - 1;
        int targetitem;
        m = l + (r - l) / 2;
        while (l <= r) {
            if (nums[m] == target) {
                targetitem = m;
                return targetitem;
            }
            if (nums[l] == target) {
                return l;
            }
         
            m = l + (r - l) / 2;
            if (target > nums[l] and target < nums[m]) {
                r = m - 1;
            } else if (nums[r] > nums[m] and target < nums[m]) {
                r = m - 1;
            } else if (nums[r] > nums[m] and target > nums[r]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (nums[targetitem] == target) {
            return targetitem;
        } else {
            return -1;
        }



        return targetitem;


    }
};