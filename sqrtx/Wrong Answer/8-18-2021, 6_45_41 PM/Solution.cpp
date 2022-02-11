// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
         int l = 1, r = x;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (mid * mid == x) {
                return mid;
            }
            if (mid * mid > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l - 1;
    }
};