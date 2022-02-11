// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {


        /*
        Binary Search Question

        [1, 2, 3, 4, 5, 6]
         0  1  2  3  4  5

         [1, 2, 3]
          L  M  R


        [1, 3, 5, 6]
         0  1  2  3

         [1, 3]
          L  R
          M

          [3]


        So pretty much, if the value of the middle is greater than the target
        then we look at the left side of  the array

        if the middle of the array is less than the target, we look at the
        right side of the array

        if the middle is


        if the index that is returned at the end is the same as the size of nums - 1
           then we return that
        otherwise
           we return mid

         We use regular binary search and return the index if it exists

        */


        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            return mid;
        }
        if (mid == nums.size() - 1 and nums.size() > 1) {
            return mid + 1;
        } else if (target > nums[mid]) {
            return mid + 1;
        } else {
            return mid;
        }

    }
};