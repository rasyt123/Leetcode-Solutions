// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
       Easy Binary Search Question

       first check the center of the array. If the l + mid value is greater than the target, look
       at the left side of the array

       if the mid + right

       [4 7 13 25 22]
        L    M   R
       target - nums[i]
       */


        int item;
        int result;
        vector<int> sums;
        for (int i = 0; i < numbers.size(); i++) {
            item = target - numbers[i];
            if (item > numbers[numbers.size() - 1]) {
                continue;
            } else {
                result = item;
                int l = i, r = numbers.size() - 1;
                int mid;
                while (l <= r) {
                    mid = l + (r - l) / 2;
                    if (numbers[mid] == result) {
                        sums.push_back(i + 1);
                        sums.push_back(mid + 1);
                        return sums;
                    } else if (numbers[mid] < result) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }

        }
        return sums;
    }
};