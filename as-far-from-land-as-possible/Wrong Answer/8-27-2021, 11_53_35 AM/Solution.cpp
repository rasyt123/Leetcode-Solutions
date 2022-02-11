// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        /*
        BFS Problem
        Naive Solution: run bfs on every zero and calculate the distance between
        every island from each zero.


        coords of the 1s : (0,0)  (0, 2) (1,0) (1,2)

        We can mark all of the zero nodes as negative
        WE can BFS this once by using ocean to island technique

        Plan:
        Only BFS Once. BFS from the islands themselves, and add all of the islands to the queue. Set the neighbors of each island to be     appropriate distance from each of
the water cells and add those cells to the queue and calculate the distance
from each of those cells. mark neighbors as visited
        */
        int num_rows = grid.size();
        int num_cols = grid.at(0).size();
        pair<int, int> queuefront;
        vector<pair<int, int>> neighbors;
        int maxdistance = -100000;
        int row;
        int col;
        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(0).size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    visited[i][j] = true;
                    nodes.push({i, j});
                } else {
                    grid[i][j] = -1;
                }
            }
        }


        while (!nodes.empty()) {
            queuefront = nodes.front();
            nodes.pop();
            row = queuefront.first;
            col = queuefront.second;
            neighbors = buildneighbors(row, col);
            visited[row][col] = true;
            for (pair<int, int> item : neighbors) {
                if (isValid(item.first, item.second, grid) and !visited[item.first][item.second]) {
                    grid[item.first][item.second] = grid[row][col] + 1;
                    nodes.push({item.first, item.second});
                    visited[item.first][item.second] = true;
                    maxdistance = max(maxdistance, grid[item.first][item.second]);
                }
            }
        }
        return maxdistance;

    }


    bool isValid(int row, int col, vector<vector<int>>& heights) {
        return (row >= 0 and row < heights.size()) and (col >= 0 and col < heights.at(0).size());
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