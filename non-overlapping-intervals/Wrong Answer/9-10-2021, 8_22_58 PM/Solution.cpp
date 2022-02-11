// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);
        stack<vector<int>> interval;
        int intervalcount = 0;
        //intervals[0] is the previous
        interval.push(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (!interval.empty()) {
                vector<int> result = interval.top();
                if (intervals[i][0] < result[1]) {
                    intervalcount += 1;
                    interval.push(intervals[i]);
                    continue;
                }
            }
        }

        return intervalcount;

    }
    
    static bool compare(vector<int>v1, vector<int>v2) {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
    }
};