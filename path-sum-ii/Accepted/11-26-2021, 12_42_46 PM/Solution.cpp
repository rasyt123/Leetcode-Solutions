// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        /*
        if the root is null:
            just return 
        if the root is a leaf and the sum is equal to target:
            push this into vector of vectors
        We use a predorder traversal, going through the nodes, and 
        pushing them onto a vector 
        
        return this referenced vector 
        
        
        */
        vector<vector<int>> totalpaths;
        vector<int> path;
        dfs(root, targetSum, totalpaths, path, 0);
        return totalpaths;
    }
    
    
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& totalpaths, vector<int> currpath, int sum) {
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        currpath.push_back(root->val);
        if (root->left == nullptr and root->right == nullptr and sum == targetSum) {
            totalpaths.push_back(currpath);
        }
        dfs(root->left, targetSum, totalpaths, currpath, sum);
        dfs(root->right, targetSum, totalpaths, currpath, sum);  
    }
};