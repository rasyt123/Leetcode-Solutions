// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> nodevalues;
       helper(root, nodevalues);
       return nodevalues;
    }
    void helper(TreeNode* root, vector<int>& nodevals) {
        if (root == nullptr) {
            return;
        }
        helper(root->left, nodevals);
        helper(root->right, nodevals);
        nodevals.push_back(root->val);
    }
};