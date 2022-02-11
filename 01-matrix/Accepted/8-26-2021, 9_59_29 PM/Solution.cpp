// https://leetcode.com/problems/01-matrix

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }    /*
        Methodology/Patterns
        
        Most of the time with these questions we want to be taking a non naive approach with the BFS or the DFS. we really dont want to run dfs or bfs for each cell because the run time complexity could be possibly worse than brute force. We want to optimize the naive solution by using a technique called flowing from the ocean.
        
        
        
        - We only want to bfs once rather than bfsing at each 1. we can bfs through all the zeros and change the respective neighbors of those zeros to be the correct distance from the ones. path from point a to b is the same distance as point b to a. 


    - 1 + value at the matrix S. Since the -1s are alreacy marked with the distance from the zeros, if we just add 
    to the value of the cell previous to it we will get the current distance from the zero
    
    
    Method:
    
    1. We add all of the zeros in the matrix into the bfs queue and mark them as visited. We add
    the neighbors of the front element of the queue that haven't been visited. for each one of these 
    neighbors that are -1s, we add how far it is away which is 1 + current zero. It's the same as moving from 0 to 1. 0 + 1 = 1 + 0; each one of these neighbors we add to the queue to explore the next level
    
    
    


        
        
        
    */
        
    
};