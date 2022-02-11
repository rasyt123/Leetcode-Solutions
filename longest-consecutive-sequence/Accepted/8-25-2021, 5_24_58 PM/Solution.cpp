// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        
        consecutive sum should start with a 1. 
        
        First observations:
        We can use a set or a hashmap here.
        consecutive element all have a difference of 1 with each other 
        
        This question requires multiple passes
        
        We can pass through the array once and add all of the items to a set or a hashmap
        The set will put all of the elements in order already
        
        We can pass through the array a second time and when we do, if the next item
        is equal to 1 plus the current it is consecutive, so we can just update the counter.
        if it isnt we can just reset the counter.
        
        The time complexity will be (O(N) + O(N))
        which is still O(N)
        
        1 2 3 4 100 200  
        
        */
        int length = 1;
        int lenlength = 1;
        map<int, int> elements;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            elements[nums[i]] = nums[i];
        } 
        for (pair<int, int> item : elements) {
            if (elements.find(item.first + 1) != elements.end() and item.first + 1 == elements[item.first + 1]) {
              length += 1;
              lenlength = max(lenlength, length);
            } else {
              length = 1;
            }
        }
        
        
        return lenlength;
    }
};