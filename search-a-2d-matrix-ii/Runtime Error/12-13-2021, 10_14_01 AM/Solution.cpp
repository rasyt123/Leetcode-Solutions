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
    
        
        */
        int c = 0;
        int r = 0;
        int colstop = matrix[0].size();
        int rowstop = matrix.size();
        while (c < colstop) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c -= 1;
                for (int i = 0; i < matrix.size(); i++) {
                    if (matrix[i][c] == target) {
                        return true;
                    }
                }
                break;
            }
            c += 1;
        }
        
        while (r < rowstop) {
            if (matrix[r][0] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                r -= 1;
                for (int i = 0; i < colstop; i++) {
                    if (matrix[r][i] == target) {
                        return true;
                    }
                    
                }
                break; 
            }
            r += 1;
        }
        return false;

    }
};