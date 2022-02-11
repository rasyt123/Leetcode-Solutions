// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> thetree;
        if (root == nullptr) {
            return thetree;
        }
        vector<int> currlevel;
        vector<TreeNode*> children;
        queue<TreeNode*> q1;
        TreeNode* current = root;
        q1.push(current);
        while (!q1.empty() and current != nullptr) {
            current = q1.front();
            q1.pop();
            if (std::find(children.begin(), children.end(), current) != children.end()) {
                children.clear();
                thetree.push_back(currlevel);
                currlevel.clear();
                currlevel.push_back(current->val);
            } else {
                currlevel.push_back(current->val);
            }
            if (current->left != nullptr) {
                q1.push(current->left);
                children.push_back(current->left);
            }
            if (current->right != nullptr) {
                q1.push(current->right);
                children.push_back(current->right);
            }
        }
        if (q1.empty()) {
            thetree.push_back(currlevel);
            currlevel.clear();
        }
        return thetree;

    }
};
