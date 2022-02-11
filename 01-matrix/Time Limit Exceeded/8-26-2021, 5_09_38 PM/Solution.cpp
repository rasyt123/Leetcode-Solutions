// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
        BFS Problem
        A zero already means that the distance is zero. No need to bfs the
        empty cells already. I need to go through the entire matrix
        and run a bfs on the 1s and the neighbors. I can count the path
        that is taken along the bfs from the ones while ignoring the zeros.
        */

        int path;

        vector<vector<int>> distances(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.at(0).size(); j++) {
                if (mat[i][j] != 0) {
                    vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
                    path = bfs(mat, i, j, visited);
                    distances[i][j] = path;
                }
            }
        }
        return distances;

    }

    int bfs(vector<vector<int>>& mat, int row, int col, vector<vector<bool>>& marked) {
        queue<pair<int, int>> processn;
        vector<pair<int, int>> neighbors;
        pair<int, int> nextnode;
        int smallpath = 10000;
        int pathlength;
        int numneighbors = 1;
        processn.push({row, col});
        while (!processn.empty()) {
            nextnode = processn.front();
            processn.pop();
            int currow = nextnode.first;
            int currcol = nextnode.second;
            if (mat[currow][currcol] == 0) {
                int rowdif = abs(row - currow);
                int coldif = abs(col - currcol);
                pathlength = rowdif + coldif;
                smallpath = min(pathlength, smallpath);
            }

            if (!marked[currow][currcol]) {
                marked[currow][currcol] = true;
                neighbors = buildneighbors(currow, currcol);
                for (pair<int, int> w : neighbors)
                    if (isValid(w.first, w.second, mat) and !marked[w.first][w.second]) {
                        processn.push(w);
                    }
            }
        }
        return smallpath;
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


    bool isValid(int row, int col, vector<vector<int>>& image) {
        return (row >= 0 and row < image.size()) and (col >= 0 and col < image.at(0).size());
    }
};