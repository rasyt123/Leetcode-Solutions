// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
         I need to find one triplet in which the sum of all the numbers are the closest to the target. the 3 numbers are not contiguous
         we dont have to ignore duplicates here


         The sum that is closest to the target in mathematical terms is the absolute value of the sum - target
         with two sum, we used two pointers to determine the values of the two parts that made up the target while one was fixed
         no need to test for triplets on the last two numbers because there aren't enough numbers remaining


         two pointers with one pointer on the left end and one pointer on the right end
         test


         if the sum of the l and r items are bigger than the target,
           we need to shift the right pointer to the left by 1.
         if the sum of the l and r items are smaller than the target
           we need to shift the left pointer to the right by 1.




        */


        int n = nums.size();
        int l = 0;
        int r = nums.size() - 1;
        int includednum;
        int tripletsum;
        int maxdif;
        int maxsum;
        std::sort(nums.begin(), nums.end());
        maxdif = abs(nums[0] + nums[1] + nums[2] - target);
        for (int i = 0; i < n - 2; i++) {
            includednum = nums[i];
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                tripletsum = includednum + nums[l] + nums[r];
                if (abs(tripletsum - target) <= maxdif) {
                    maxdif = abs(tripletsum - target);
                    maxsum = tripletsum;
                }
                if (tripletsum < target) {
                    ++l;
                } else if (tripletsum > target) {
                    --r;
                }

            }
        }
        return maxsum;
    }
};