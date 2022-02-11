// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sortedintervals;
        vector<vector<int>> answer;
        vector<int> starts;
        vector<int> ends;
        vector<int> extra;
        stack<vector<int>> intervalmerge;

        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }


        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < starts.size(); i++) {
            sortedintervals.push_back({starts[i], ends[i]});
        }
        for (vector<int> item : sortedintervals) {
            if (!intervalmerge.empty()) {
                vector<int> result = intervalmerge.top();
                if (result[1] >= item[0]) {
                    intervalmerge.pop();
                    intervalmerge.push({result[0], item[1]});
                    continue;
                }
            }
            intervalmerge.push(item);
        }
        while (!intervalmerge.empty()) {
            vector<int> topinterval = intervalmerge.top();
            answer.push_back(topinterval);
            intervalmerge.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;   
    }
};