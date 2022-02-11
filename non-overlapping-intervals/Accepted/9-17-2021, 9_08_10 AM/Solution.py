// https://leetcode.com/problems/non-overlapping-intervals

class Solution:
     def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        prev = float("-inf")
        ans = 0
        for i in intervals:
            #we check every interval
            if i[0] >= prev:
                prev = i[1]
                # if the interval start is greater than the previous interval end,
                # then it is non overlapping, so we set the interval we want to compare
                # to be the 
                #
            else:
                #otherwise if the interval is overlapping
                #add 1 to the counter for removal
                #set the previous to be the minimum end of both intervals
                #so you don't end up incurring multiple intervals that the maximum interval contains 
                ans += 1
                prev = min(prev, i[1])
        return ans
        