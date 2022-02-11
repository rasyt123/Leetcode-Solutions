// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* temp;
        TreeNode* finaluru = root;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            root = q1.front();
            q1.pop();
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            if (root->left != nullptr) {
                q1.push(root->left);
            }
            if (root->right != nullptr) {
                q1.push(root->right);
            }
        }
        return finaluru;

    }
};