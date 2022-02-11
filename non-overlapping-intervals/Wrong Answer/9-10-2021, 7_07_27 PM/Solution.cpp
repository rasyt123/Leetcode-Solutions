// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
        Sort intervals by ascending order, no need to sort the 
        intervals by their respective values like rearranging the values of the intervals
        and putting them into other intervals/
    
     
        Whenever the end interval of the first is greater than the end of the next interval
        that means that the interval is overlapping 
        Count all overlapping intervals including the duplicates
        
        [[1,2],[1,2],[1,2], [1, 5] [2,3] [2,3], [2, 3]]
        3  4 5 
       stack [1, 2] , [2, 3], 
        
        if we have a stack, we can push all of the intervals that we dont want to delete on the top
        as we iterate, if the interval is the same, then we can just +1 to the counter and 
        
        if the top of the stack interval end is greater than the end of the one iterating, + 1 
        to the counter
        
        if it's not, just push that item to the top of the stack 
        
        
        [1, 2] [1, 5]
    
        */
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> interval;
        int intervalcount = 0;
        for (vector<int> item : intervals) {
            if (!interval.empty()) {
                vector<int> result = interval.top();
                if (item == result or result[1] > item[0]) {
                    intervalcount += 1;
                    continue;
                } 
            }
            interval.push(item);
        }
        return intervalcount;
        
    }
};