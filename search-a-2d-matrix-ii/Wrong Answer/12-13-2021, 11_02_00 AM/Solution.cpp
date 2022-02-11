// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        
        
        keep moving right checking if the element to the right of it 
        is greater than target
                if it is the target
                    return true
                otherwise greater than the target
                    break 
                move down 
                
        keep moving down checking if the element that's right below it 
        is greater than the target
                if itis the target
                    return true
                otherwise greater than the target
                    break
                move to the right 
                
                
        new method 
        we can check if the 
    
        
        */

        int colstop = matrix[0].size();
        int rowstop = matrix.size();
        for (int c = 0; c < colstop; c++) {
            if (target > matrix[0][c] and target < matrix[0][colstop - 1]) {
                for (int i = 0; i < rowstop; i++) {
                    if (matrix[0][i] == target) {
                        return true;
                    }
                }
            }
            if (target > matrix[0][c] and target < matrix[rowstop - 1][c]) {
                 for (int i = 0; i < rowstop; i++) {
                    if (matrix[i][c] == target) {
                        return true;
                    }
                }
            }
        }
        return false;

    }
};