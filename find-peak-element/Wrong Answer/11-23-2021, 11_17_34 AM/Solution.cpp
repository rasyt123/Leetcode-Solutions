// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*    
        Need to determine the conditions for the binary search 
        on one peak 
        
        [1,2,1,3,5,7]
         0 1 2 3 4 5 6 
         
        [1, 1, 1, 3, 5, 7, 6]
         0  1  2  3  4  5  6 
         
        
         
        We know we've found a match when the middle element is greater than the one to the left 
        of it and the one to the right of it 
        
        
        no peak means that the portion has to be sorted 
        
        
        
        
        
        */
        return 0;
        
    }
};