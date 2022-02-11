// https://leetcode.com/problems/path-sum-iii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<int, bool> runningsums;
        int currsum = 0;
        dfs(root, runningsums, targetSum, count, currsum);
        return count;
    }
    
    /*
    10 15 17 18
    
    */
    
    
    void dfs(TreeNode* root, unordered_map<int, bool> table, int targetSum, int& count, int currsum) {
        if (root == nullptr) {
            return;
        }
        int newsum = currsum + root->val;
        table[newsum] = true;
        if (table[newsum - targetSum] or newsum - targetSum == 0) {
            count += 1;
        }
        dfs(root->left, table, targetSum, count, newsum);
        dfs(root->right, table, targetSum, count, newsum);
    }
};