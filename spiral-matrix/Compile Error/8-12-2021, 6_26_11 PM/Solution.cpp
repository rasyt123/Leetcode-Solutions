// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> jboy;
        map<int, int> coords;
        int currow, currcolumn, currcol;
        currow = 0;
        currcol = 0;
        /*



        currrow, currcolumn
       Keep going right
       If you can't go right anymore (you've found a coordinate u've been to already)
       break

       Check num elements of vector with number of elements inside of the matrix

       go down
       if you can't go down anymore
       go left
       if you can't go left anymore, go up


       loop condition should say that we should keeping spiraling until the number of elements inside of the vector
       are equal to the ones inside of the matrix


        Need to figure out when not to bump an element that you've already visited


        */
        int colsize = matrix.at(0).size();
        int rowsize = matrix.size();
        int oldrow;
        int oldcol;
        int lowerrowsize = 0;
        int lowercolsize = 0;
        bool first = true;



        while (jboy.size() != matrix.at(0).size() * matrix.size()) {
            if (first) {

            } else {
                --colsize;
            }

            for (currcol ; currcol < colsize - 1; ++currcol) {
                jboy.push_back(matrix[currow][currcol]);
            }
            if(jboy.size() == matrix.at(0).size() * matrix.size()) {
                break;
            }

            if (first) {

            } else {
                --rowsize;
            }

            for (currow = currow; currow < rowsize - 1; ++currow) {
                jboy.push_back(matrix[currow][currcol]);
            }

            if (first) {

            } else {
                ++lowercolsize;
            }

            for (currcol = colsize - 1; currcol > lowercolsize; --currcol) {
                jboy.push_back(matrix[currow][currcol]);
            }


            ++lowerrowsize;
            for (currow ; currow > lowerrowsize; --currow) {
                jboy.push_back(matrix[currow][currcol]);
            }
            first = false;


        }



        return jboy;
    }
};


int main() {
    Solution jboy;
    vector<vector<int>> nums{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> manbeast;
    manbeast = jboy.spiralOrder(nums);





}