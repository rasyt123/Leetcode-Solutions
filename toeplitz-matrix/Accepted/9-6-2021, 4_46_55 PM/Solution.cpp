// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.at(0).size(); i++) {
        int item = matrix[0][i];
        int j = i;
        int f = 0;
        while (j + 1 < matrix.at(0).size() and f + 1 < matrix.size()) {
            if (item != matrix[f + 1][j + 1]) {
                return false;
            } 
            j++;
            f++;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        int item = matrix[i][0];
        int j = i;
        int f = 0;
        while (j + 1 < matrix.size() and f + 1 < matrix.at(0).size()) {
            if (item != matrix[j + 1][f + 1]) {
                return false;
            } 
            j++;
            f++;
        }
    }
    return true;
    }
};