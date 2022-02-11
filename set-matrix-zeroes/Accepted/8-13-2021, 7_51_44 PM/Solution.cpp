// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        constant space; 
        
        I can loop through the matrix and set each zero to be a #
        if it's a #, we can change the row and columns to be zeroes except for the #
        
        then we can go through the entire matrix again:
            set the #s to zeroes
        
        be done'
        
        */
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = -500;
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                if (matrix[i][j] == -500) {
                    for (int row = i; row >= 0; row--) {
                        if (matrix[row][j] != -500) {
                             matrix[row][j] = 0;
                        }
                    }
                    for (int row = i; row < matrix.size(); row++) {
                         if (matrix[row][j] != -500) {
                             matrix[row][j] = 0;
                        }
                    }
                    for (int col = j; col < matrix.at(0).size(); col++) {
                        if (matrix[i][col] != -500) {
                             matrix[i][col] = 0;
                        }
                    }
                    
                    for (int col = j; col >= 0; --col) {
                        if (matrix[i][col] != -500) {
                             matrix[i][col] = 0;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                if (matrix[i][j] == -500) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};