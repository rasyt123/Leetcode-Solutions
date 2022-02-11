// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        map<int, int> goods;
        goods[2] = 2;
        goods[1] = 1;
        int result;
        result = countsteps(n, goods);
        return result;
    }
    
    
    int countsteps(int n, map<int, int>& memoize) {
        if (n <= 1) {
            return n;
        } else {
            if (memoize.find(n) == memoize.end()) {
                memoize[n] = countsteps(n - 1, memoize) + countsteps(n - 2, memoize);
            } 
        }
        return memoize[n];
    }
};