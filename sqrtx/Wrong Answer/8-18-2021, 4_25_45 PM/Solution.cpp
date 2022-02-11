// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        /*
        Binary Search Problem

        decimal is truncated



         [1, 2, 3, 4]

         Set l to be 1, Set R to be 4;

         take the middle of the l and r and test if that if the middle is a
         square of x
            if it is just return the middle

         if the middle square is bigger than the target
             we should check the left sorted portion
         otherwise:
            we check the right sorted portion



        has to be between 1 and 8
        1 + 8 /2 = 4.5

        4.5^2 20.25

        1 + 4.4

        We can keep resizing the input and output to be with errors of 0.1
        and if the difference between mid * mid is less than or equal to 0.5 we should just
        return the truncated version of mid
        */
        if (x == 0) {
            return 0;
        }
        double l = 0, r = x;
        double mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid * mid == x) {
                return mid;
            }
            if (abs(mid * mid - x) <= 0.5) {
                return std::round(mid);
            }


            if (mid * mid > x) {
                r = mid - 0.1;
            } else {
                l = mid + 0.1;
            }
        }
        return mid;
    }
};
