// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s1;
        TreeNode* current;

        if (root == nullptr) {
            return;
        }
        s1.push(root);
        while (!s1.empty()) {
            current = s1.top();
            s1.pop();
            if (current->right != nullptr) {
                s1.push(current->right);
            }
            if (current->left != nullptr) {
                s1.push(current->left);
            }
            if (s1.empty()) {
                current->right = nullptr;
            } else {
                current->right = s1.top();
            }
            current->left = nullptr;
        }
    }
};
