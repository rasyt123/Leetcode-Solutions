// https://leetcode.com/problems/binary-tree-pruning

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
    TreeNode* pruneTree(TreeNode* root) {
        /*
        Postorder traversal
        The leaves of every binary tree that are zeros basically
        need to be pruned 
        
        once we prune leaves, we are back to the base case that the root is a leaf that is zero 
        
        if the root is equal to null:
            return null:
        root->left = dfs(root->left, ) 
        root->right =
        
        if both rootleft and rootright are null and root->val = 0:
            return null
        return root 
        */
        TreeNode* roots = dfs(root);
        return root;
        
    }
    
    
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (root->left == nullptr and root->right == nullptr and 
           root->val == 0) {
            return nullptr;
        }
        return root;
    }
};