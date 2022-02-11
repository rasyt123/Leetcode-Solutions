// https://leetcode.com/problems/trim-a-binary-search-tree

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        /*
        
        
        I need to check if the current node is not between low and high
        
        I only want to recurse to nodes that are outside the range
        
        If a node is outside the range of high, then every subtree of that node
        will need to be trimmed. (not necessarily) we will trim the nodes one at a time
        
        If a node is outside the range of low as in less than, then every subtree of that node will need to be
        trimmed. We will trim the nodes one at a time. 
        
        
        Make a helper function that will find the minimum node in the left subtree
        we need to keep deleting until the current node is within the range 
        
    
        */
        if (!root) {
            return nullptr;
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if (root->val < low) {
            return root->right;
        }
        if (root->val > high) {
            return root->left;
        }
        return root;
    }
};