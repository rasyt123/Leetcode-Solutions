// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /* 
        Maintain a list of the intervals here in a vector of vectors 
        return the intersection of the two interval lists 
        
        
        What defines an intersection:
            End of the first list is greater than or equal start of the second 
            
            or the start of of the first list less than or equal to end of the second 
            
        Solution 1 Merge Intervals 
            
         first list    [0, 2]     first list [1, 5]
         second list   [1, 5]     second list [0, 2]
            
        iterate through bot
       
        Think of the Two Pointer Solution: 
        
        l = 0 and r = 0
        
        We want l to be the start of the intersection and r to be the end of the intersection
        of two particular intervals 
        
        [5, 10]
        [8, 12]
    
        */
         vector<vector<int>> result;
        if (firstList.size() == 0 or secondList.size() == 0) {
            return {};
        }
        
        for (int i = 0; i < firstList.size(); i++) {
            
            if (firstList[i][1] >= secondList[i][0]) {
                vector<int> mergedinterval = {secondList[i][0], firstList[i][1]};
                result.push_back(mergedinterval);
            } else if (firstList[i][0] <= secondList[i][1]) {
                vector<int> mergedinterval = {firstList[i][0], secondList[i][1]};
                result.push_back(mergedinterval);
            }
            
            
            if (i + 1 < firstList.size() and secondList[i][1] == firstList[i + 1][0]) {
                vector<int> mergedinterval = {secondList[i][1], secondList[i][1]};
                result.push_back(mergedinterval);
            } else if (i + 1 < firstList.size() and firstList[i][1] == secondList[i + 1][0]) {
                vector<int> mergedinterval = {firstList[i][1], firstList[i][1]};
                result.push_back(mergedinterval);
            }
        }
        /*
        
        XXXXXX
        5    10
    XXXXX     
    1   5    
        
        */
      
        return result;
        
    }
};