// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        /*
        Depth first search problem

        Pacific ocean touches island's left and top edges

        Atlantic ocean touches right islands'right and bottom edges

        hold neighbors with adjacency list


        we need to mark all of the rows and cols we visit with a visited vector
        we need to run a depth first search on every cell and check whether or not
        from the cell we've hit one end in the pacific ocean and one end in the atlantic
        ocean

        we can have a data structure that holds the boolean values of atlantic
        and pacific oceans



        I need a function that builds all of the neighbors to go through
        use vector or map with pairs

        isPacific
        we need a function that checks if the current column and row are out of
        bounds to the left and right

        Pacific ocean:  currrow - 1 < 0 or currcol - 1 < 0


        isAtlantic
        Atlantic ocean: currow + 1 > 0 or currcol + 1 > 0
        5 - 3 3 4 1

        */
        int num_rows = heights.size();
        int num_cols = heights.at(0).size();
        vector<int> coords;

        vector<vector<int>> result;

        vector<pair<int, int>> neighbors;

        vector<bool> bothpaths{false, false};



        for (int row = 0; row <= num_rows - 1; row++) {
            for (int col = 0; col <= num_cols - 1; col++) {
                vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
                neighbors = buildneighbors(row, col);
                dfs(row, col, bothpaths, visited, neighbors, heights);
                if (bothpaths[0] and bothpaths[1]) {
                    coords = {row, col};
                    result.push_back(coords);
                    coords.clear();
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

    void dfs(int row, int col, vector<bool>& bothpaths, vector<vector<bool>>& visited, vector<pair<int, int>> neighbors, vector<vector<int>>& heights) {
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
            int value = items.first;
            int value2 = items.second;
            if (isValid(items.first, items.second, heights) and heights[items.first][items.second] <= heights[row][col] and !visited[items.first][items.second]) {
                dfs(items.first, items.second, bothpaths, visited, neighbors, heights);
            }
        }


        return;
    }
};
