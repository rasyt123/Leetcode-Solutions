// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*

        create new sorted vec for comparisons
        [3, 5][4, 8]


        newinterval = [4, 8]
        comparison interval = [3, 5]

        newinterval = [3, 8]
        comparison interval = [8, 10]

        [8, 10]
        iterate through the intervals

        if the comparison interval's start is less than or equal to the new interval's end
        merge and update the interal

        merge by taking the minimum start interal and taking the comparison interal end


        [3, 10] new interval
        [12, 16] comparison interval


        [12, 16] new interval
        [14, 17] comparison
        [3, 8][6, 7]

        prev = inf;
        for each interval:
            if overlapping:
                create vector with {prev, comparison interval end} called temp
            otherwise:
                if temp actually exists:
                    add temp vector to the list of new intervals
                add non overlapping vector
                set newinterval to be

        */

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