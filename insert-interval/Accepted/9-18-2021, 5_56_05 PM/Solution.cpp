// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<vector<int>> comparison;
        vector<int> temp;
        int end;
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }


        for (vector<int> item : intervals) {
            if (comparison.empty()) {
                comparison.push_back(item);
                comparison.push_back(newInterval);
                sort(comparison.begin(), comparison.end());

                if (comparison[1][0] <= comparison[0][1]) {
                    end = max(comparison[0][1], comparison[1][1]);
                    newInterval = {comparison[0][0], end};
                    temp = newInterval;
                    if (item == intervals[intervals.size() - 1]) {
                        result.push_back(temp);
                    }
                } else {
                    result.push_back(item);
                    if (temp.size() > 0) {
                        result.push_back(temp);
                        temp = {};
                    } else if (item == intervals[intervals.size() - 1]) {
                        if (find(result.begin(), result.end(), newInterval) == result.end()) {
                            result.push_back(newInterval);
                        }
                    }
                }
                if ((intervals.size() == 1 and item == newInterval) or (intervals.size() == 0)) {
                    comparison.pop_back();
                    return comparison;
                }
                comparison = {};
            }
        }
        if (result.size() == 0) {
            result.push_back(temp);
        }
        sort(result.begin(), result.end());
        return result; 

    }

};