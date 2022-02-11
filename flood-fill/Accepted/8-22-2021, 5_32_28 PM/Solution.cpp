// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> marked(image.size(), vector<bool>(image[0].size(), false));
        bfs(image, sr, sc, marked, newColor);
        return image;
    }


    void bfs(vector<vector<int>>& image, int startrow, int startcol, vector<vector<bool>>& marked, int newColor) {
        queue<pair<int, int>> processn;
        vector<pair<int, int>> neighbors;
        pair<int, int> nextnode;
        processn.push({startrow, startcol});
        while (!processn.empty()) {
            nextnode = processn.front();
            processn.pop();
            int row = nextnode.first;
            int col = nextnode.second;
            int oldcolor = image[row][col];
            if (!marked[row][col]) {
                image[row][col] = newColor;
                marked[row][col] = true;
                neighbors = buildneighbors(row, col);
                for (pair<int, int> w : neighbors) {
                    if (isValid(w.first, w.second, image) and !marked[w.first][w.second] and image[w.first][w.second] == oldcolor) {
                        processn.push(w);
                    }
                }
            }

        }

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