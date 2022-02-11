// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /* 
        [0, 2]
        [1, 5]
        
        How to tell when the intervals are intersecting?
        
        
        XXXXXX
        XXX
         XXXXX
        012345 
        
     
        
        1. 
        merge the intervals 
        increment left pointer until it covers both intervals
        l pointer must be greater than or equal to all three of the start of the interval
        we set l to be min start of the two arrays and r to be the max of the two arrays at the end 
        of the interval
        
        
        [0, 5]
        [0, 2]
        [1, 5]
        greater than or equal 
        
        5 10 
        8 12
        
        
        
        
         0 2 
         1 5 
         
         1 2 
         
         
        
        
        */
        if (firstList.size() == 0 or secondList.size() == 0) {
            return {};
        }
        vector<vector<int>> intervalresult;
        for (int i = 0; i < firstList.size(); i++) {
            int l = min(firstList[i][0], secondList[i][0]);
            int r = max(firstList[i][1], secondList[i][1]);
            

            while (l <= firstList[i][0] or l <= secondList[i][0]) {
                ++l;
            }
            l -= 1;
            while (r >= firstList[i][1] or r >= secondList[i][1]) {
                --r;
            }
            r += 1;
            intervalresult.push_back({l, r});
            if (i + 1 < firstList.size() and firstList[i][1] == secondList[i + 1][0]) {
                intervalresult.push_back({firstList[i][1], firstList[i][1]});
            } else if (i + 1 < firstList.size() and secondList[i][1] == firstList[i + 1][0]) {
                intervalresult.push_back({secondList[i][1], secondList[i][1]});
            }
        }
        return intervalresult;
    }
};