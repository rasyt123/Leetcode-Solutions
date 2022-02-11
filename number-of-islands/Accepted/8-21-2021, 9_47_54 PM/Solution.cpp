// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int numislands = 0;
        int num_rows = grid.size();
        int num_cols = grid.at(0).size();
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid.at(0).size(); col++) {
                if (grid[row][col] == '1') {
                    if (!visited[row][col]) {
                        dfs(numislands, visited, row, col, grid);
                        ++numislands;
                    }
                }
            }
        }
        return numislands;
    }

    bool isValid(int row, int col, vector<vector<char>>& heights) {
        return (row >= 0 and row < heights.size()) and (col >= 0 and col < heights.at(0).size());
    }
    void dfs(int& numislands, vector<vector<bool>>& visited, int row, int col, vector<vector<char>>& grid) {

        if (grid[row][col] == '0' ) {
            return;
        }
        vector<pair<int, int>> neighbors;
        neighbors = buildneighbors(row, col);
        visited[row][col] = true;
        for (pair<int, int> items : neighbors) {
            if (isValid(items.first, items.second, grid) and !visited[items.first][items.second]) {
                dfs(numislands, visited, items.first, items.second, grid);
            }
        }
        return;


    }
    vector<pair<int, int>> buildneighbors(int currow, int currcol) {
        vector<pair<int, int>> neighbors;
        int north = currow - 1;
        int south = currow + 1;
        int west = currcol - 1;
        int east = currcol + 1;
        neighbors = {{north, currcol}, {south, currcol}, {currow, west}, {currow, east}};
        return neighbors;
    }


};