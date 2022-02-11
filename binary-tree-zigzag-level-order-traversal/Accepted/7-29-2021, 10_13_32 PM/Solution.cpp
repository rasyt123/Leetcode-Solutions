// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> thetree;
        if (root == nullptr) {
            return thetree;
        }
        int turn = 1;
        vector<int> currlevel;
        deque<TreeNode*> children;
        deque<TreeNode*> q1;
        TreeNode* current = root;
        TreeNode* second;
        q1.push_back(current);
        while (!q1.empty()) {
            int size = q1.size();
            if (turn == 1) {
                for (int i = 0; i < size; i++) {
                    current = q1.front();
                    q1.pop_front();
                    currlevel.push_back(current->val);


                    if (current->left != nullptr) {
                        q1.push_back(current->left);
                    }

                    if (current->right != nullptr) {
                        q1.push_back(current->right);
                    }

                }
                thetree.push_back(currlevel);
                currlevel.clear();
                turn = 0;
            } else {
                for (int i = 0; i < size; i++) {
                    current = q1.back();
                    q1.pop_back();
                    currlevel.push_back(current->val);

                    if (current->right != nullptr) {
                        q1.push_front(current->right);
                    }
                    if (current->left != nullptr) {
                        q1.push_front(current->left);
                    }

                }

                thetree.push_back(currlevel);
                currlevel.clear();
                turn = 1;
        }
    }
        return thetree;
    }
};
