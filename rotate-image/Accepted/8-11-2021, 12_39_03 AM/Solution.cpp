// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        Transpose the matrix and then reverse all of the rows



        */
        int temp1;
        int temp2;

        int reversetemp;
        int n = 0;

        for (int i = 0; i < matrix.at(0).size(); i++) {
            for (int j = n; j < matrix.size(); j++) {
                temp1 = matrix[i][j];
                temp2 = matrix[j][i];
                matrix[i][j] = temp2;
                matrix[j][i] = temp1;
            }
            ++n;
        }

        for (int i = 0; i < matrix.at(0).size(); i++) {
            for (int j = 0; j < matrix.size() / 2; j++) {
                reversetemp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1 - j] = reversetemp;
            }
        }

    }


};
