// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        /*
          1. Find the maximum depth of the node in the left subtree
          2. Find the maximum depth of the node in ther right subtree
  
          add these two depths together
  
          if the subtree on the right is null, then just set the maximum depth of the node as zero
          if the subtree on the left is null, then just set the maximum depth of the node to be zero
  
        */
        vector<int> depthvector;
        vector<int> depthvector2;
        int rootdepth = 1;
        int depth1;
        int depth2;
        dfs(root->left, depthvector, 1);
        dfs(root->right, depthvector2, 1);
        if (root->left == nullptr) {
            depth1 = 0;
        } else {
            depth1 = *max_element(depthvector.begin(), depthvector.end());
        }
        if (root->right == nullptr) {
            depth2 = 0;
        } else {
            depth2 = *max_element(depthvector2.begin(), depthvector2.end());
        }
        

        return depth1 + depth2;


    }

    void dfs(TreeNode* root, vector<int>& depthvector, int depth) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr and root->right == nullptr) {
            depthvector.push_back(depth);
            return;
        } else {
            ++depth;
        }
        dfs(root->left, depthvector, depth);
        dfs(root->right, depthvector, depth);
    }
};