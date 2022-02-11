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



        1 8

        1 + 8 = 9

        9 / 2 = 4


        1 + 4 = 5

        1 2 3 4
        l m   r
        2 3 4
        L M R
        1 2 3 4 5 6 7 8 9 10

         if the target is between l and m   and the distance between l and m is 1
            then return l
        if the target is bettwen m and r and the distance between r and m is one;
            return mid;

        sqrt(8)
        = 2.8


        1 2 3 4

        */
        if (x == 0) {
            return 0;
        }
        int l = 1, r = x;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid * mid == x) {
                return mid;
            }
            if (l * l < x and mid * mid > x and abs(mid - l) == 1) {
                return l;
            }
            if (mid * mid < x and r * r > x and abs(r - mid) == 1) {
                return mid;
            } 
            if (mid * mid > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return mid;
    }
};

