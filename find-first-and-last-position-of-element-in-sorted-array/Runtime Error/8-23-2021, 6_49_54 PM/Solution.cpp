// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        /*
        Find first and last position of element in sorted array
        [8, 8, 8, 8]
         l  m  r


         Potential Solution:
         Use binary search normally to split the array into two halves
         but if the middle is the same as the target, then we can use two pointers
         to go up and down the target.  one to search the first position and the second to find the right position



        if the target is not found in the search, we shouldnt return it

        */
        int l = 0, r = nums.size() - 1;
        vector<int> range;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                int rpoint = mid + 1;
                int lpoint = mid - 1;
                while (nums[rpoint] == target and rpoint < nums.size()) {
                    ++rpoint;
                }
                while (nums[lpoint] == target and lpoint >= 0) {
                    --lpoint;
                }
                --rpoint;
                lpoint++;
                range.push_back(lpoint);
                range.push_back(rpoint);
                return range;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        range = {-1, -1};
        return range;
    }
};