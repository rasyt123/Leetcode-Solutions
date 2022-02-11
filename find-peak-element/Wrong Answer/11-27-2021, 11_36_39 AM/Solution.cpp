// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        1 2 3 4 5 7 6
        0 1 2 3 4 5 6 
        
        6 10 5 4 3 2 1
        
        
        1 4 3 5 6 7 8 9 
        0 1 2 3 4 5 6 7
        
        2 binary searches = log (n) time 
        
        log(n)
        starting from the mid:
            if it is a peak:
                return the peak
            if the element that is right next to it is greater than curr:
                look to left 
            otherwise
                look to the rigjt 
         
            
        log(n)
        starting from the mid:
            if it is a peak:
                return the peak:
            if the element that is the right is greater than curr:
                look to the right
            otherwise 
                look to the left 
        */
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] > nums[m - 1] and nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m - 1] > nums[m]) {
                r = m;
            } else {
                l = m + 1;
       }
    }
        int l1 = 0;
        int l2 = nums.size() - 1;
        int mid;
        while (l1 < l2) {
            mid = l1 + (l2 - l1) / 2;
            if (nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid + 1]) {
                l2 = mid;
            } else {
                l1 = mid + 1;
            }
        }
        return m;
            
        
    }
};