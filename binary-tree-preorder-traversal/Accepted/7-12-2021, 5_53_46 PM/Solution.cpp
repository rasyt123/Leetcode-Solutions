// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        vector<int> bintree;
        if (root == nullptr) {
            return bintree;
        }
        s1.push(root);
        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            bintree.push_back(root->val);
            if (root->right != nullptr) {
                s1.push(root->right);
            }
            if (root->left != nullptr) {
                s1.push(root->left);
            }
        }
        return bintree;
    }
};