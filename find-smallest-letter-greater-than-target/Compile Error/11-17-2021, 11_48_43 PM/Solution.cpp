// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        /*
        
        I know a straightforward o(n) solution, but I need to find the o log n 
        solution (the binary search one )
        
        
        return the smallest character in the array that is larger than the target 
        
        [0, 3, 7]               
        
        
        target = a
        diff = 
        
        diff = the difference between the target and the letter at the mmiddle
        
        
        while l <= r:
            int m = r - (l - r) / 2
            if the item at the mid is > target and the diff is smaller:
                i = m
                r = mid - 1
            otherwise:
                l = mid + 1
        
        
        
        
        
        */
        
        
        int l = 0;
        int r = letters.size() - 1;
        int diff = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target and target - letters[mid] > )
    
        }
        
    }
};