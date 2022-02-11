// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /*
        Let's use iterative dfs on this problem with an adjacency list

        We want to remember all of the paths from the start

        I need to mark that I've taken a certain path already

        I need to run dfs on every one of zero's neighbors


        When we go through one path and we reach the n -1 th node through dfs, we backtrack and mark each place
        we just visited through the path as unvisited, so if we go through a different node in the beginning and we
        end up on the same path, we can include it in the list of paths.
        */

        vector<vector<int>> paths;
        vector<bool> marked(graph.size(), false);
        vector<int> currpath;
        dfs(0, graph, paths, marked, currpath);

        return paths;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& paths, vector<bool>& marked, vector<int> currpath) {
        int target = graph.size() - 1;
        marked[node] = true;
        currpath.push_back(node);
        if (node == target) {
            paths.push_back(currpath);
        }
        for (int item : graph[node]) {
            if (!marked[item]) {
                dfs(item, graph, paths, marked, currpath);
            }
        }
        marked[node] = false;
        return;
    }
};