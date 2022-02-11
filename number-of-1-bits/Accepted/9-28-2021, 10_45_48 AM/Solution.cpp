// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        we check if the bit in the ones place is a 1 
        
        if we take the n & 1 everytime and check if the result of that 
        is equal to one, we have a one so we can update the counter 
        
        we keep rightshifting n until it is all zeros 
        
        
        */
        int count = 0;
        
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) {
                ++count;
            }
            n >>= 1;
        }
        return count;
        
    }
};