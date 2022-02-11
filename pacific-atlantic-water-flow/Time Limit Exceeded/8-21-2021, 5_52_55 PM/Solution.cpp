// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool pacific;
        bool atlantic;
        int num_rows = heights.size();
        int num_cols = heights.at(0).size();
        vector<int> coords;

        vector<vector<int>> result;

        vector<pair<int, int>> neighbors;
        vector<vector<bool>> atlantictrue(num_rows, vector<bool>(num_cols, false));
        vector<vector<bool>> pacifictrue(num_rows, vector<bool>(num_cols, false));



        vector<bool> bothpaths{false, false};


        for (int row = 0; row <= num_rows - 1; row++) {
            for (int col = 0; col <= num_cols - 1; col++) {
                vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
                neighbors = buildneighbors(row, col);
                dfs(row, col, bothpaths, visited, neighbors, heights, atlantictrue, pacifictrue);
                if (bothpaths[0] and bothpaths[1]){
                    coords = {row, col};
                    result.push_back(coords);
                    coords.clear();
                }


                if (bothpaths[0]) {
                    pacifictrue[row][col] = true;
                }
                if (bothpaths[1]) {
                    atlantictrue[row][col] = true;
                }
                bothpaths[0] = false;
                bothpaths[1] = false;
            }
        }

        return result;

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


    bool isValid(int row, int col, vector<vector<int>>& heights) {
        return (row >= 0 and row < heights.size()) and (col >= 0 and col < heights.at(0).size());
    }

    void dfs(int row, int col, vector<bool>& bothpaths, vector<vector<bool>>& visited, vector<pair<int, int>> neighbors, vector<vector<int>>& heights, vector<vector<bool>>& atlantictrue, vector<vector<bool>>& pacifictrue) {
        visited[row][col] = true;
        neighbors = buildneighbors(row, col);
        if (row - 1 < 0 or col - 1 < 0) {
            bothpaths[0] = true;
        }

        if (row + 1 > visited.size() - 1 or col + 1 > visited.at(0).size() - 1) {
            bothpaths[1] = true;
        }

        if (bothpaths[0] and bothpaths[1]) {
            return;
        }

        for (pair<int,int> items : neighbors) {
            int row1 = items.first;
            int col1 = items.second;
            if (isValid(items.first, items.second, heights) and heights[items.first][items.second] <= heights[row][col] and !visited[items.first][items.second]) {
                if (atlantictrue[items.first][items.second] and pacifictrue[items.first][items.second]) {
                    bothpaths[0] = true;
                    bothpaths[1] = true;
                    return;
                }
                if (pacifictrue[items.first][items.second]) {
                    bothpaths[0] = true;
                }
                if (atlantictrue[items.first][items.second]) {
                    bothpaths[1] = true;
                }
                if (!atlantictrue[items.first][items.second] and !pacifictrue[items.first][items.second]) {
                    dfs(items.first, items.second, bothpaths, visited, neighbors, heights, atlantictrue, pacifictrue);
                }
            }
        }


        return;
    }

};