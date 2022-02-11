// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        Binary Search Question

        Looks like I need to use binary search on each of the rows
        and check the end value with the target so I can skip
        unecessary rows that do not need to be checked
        */
        int end = matrix.at(0).size() - 1;
        int l = 0, r = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++) {
            if (target <= matrix[i][end]) {
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        l = mid + 1;
                    } else {
                       r = mid - 1;
                    }
                }
                return false;
            }
        }
         return false;
    }

};