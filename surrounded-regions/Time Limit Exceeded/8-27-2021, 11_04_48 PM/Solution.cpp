// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        Any O that is on the border is one that cannot be flipped.
        We only need to bfs from one location which is x.

        Any zero that is on the inside of the border should be automatically flipped, so we can just use a normal bfs from one x
        and explore level by level on the graph. if the node popped from the queue happens not be a border 0, flip it to an x
        other wise if it's a border one ignore it.
        */
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0, visited);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            if (board[i][board[0].size() - 1] == 'O') {
                bfs(board, i, board[0].size() - 1, visited);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                bfs(board, 0, i, visited);
            }

        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[board.size() - 1][i] == 'O') {
                bfs(board, board.size() - 1, i, visited);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (!visited[i][j] and borderrow(i, board) and bordercol(j, board)) {
                    board[i][j] = 'X';
                }
            }
        }
    }


    void bfs(vector<vector<char>>& board, int startrow, int startcol, vector<vector<bool>>& visited) {
        queue<pair<int, int>> nodes;
        nodes.push({startrow, startcol});
        vector<pair<int, int>> neighbors;
        pair<int, int> result;
        while (!nodes.empty()) {
            result = nodes.front();
            nodes.pop();
            int row = result.first;
            int col = result.second;
            visited[row][col] = true;
            neighbors = buildneighbors(row, col);
            for (pair<int, int> item : neighbors) {
                if (isValid(item.first, item.second, board) and !visited[item.first][item.second]) {
                    if (board[item.first][item.second] != 'X') {
                        nodes.push({item.first, item.second});
                    }
                }
            }

        }

    }

    bool borderrow(int item, vector<vector<char>>& board) {
        return item > 0 and item < board.size() - 1;
    }

    bool bordercol(int item, vector<vector<char>>& board) {
        return item > 0 and item < board.at(0).size() - 1;
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


    bool isValid(int row, int col, vector<vector<char>>& image) {
        return (row >= 0 and row < image.size()) and (col >= 0 and col < image.at(0).size());
    }



};