// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return false;
        }
        if (root == nullptr) {
            return false;
        }

        if (root->val == subRoot->val) {
            if (subRoot->left != nullptr and subRoot->right != nullptr) {
                if (root->left->val == subRoot->left->val and root->right->val == subRoot->right->val) {
                    if (root->left->left == nullptr and root->left->right == nullptr and root->right->left == nullptr and root->right->right == nullptr)
                            return true;
                }
            } else if (subRoot->left != nullptr and subRoot->right == nullptr and root->left->left == nullptr) {
                if (root->left->val == subRoot->left->val) {
                    if (root->left->left == nullptr and root->left->right == nullptr) {
                        return true;
                    }
                }
            } else if (subRoot->right != nullptr and subRoot->left == nullptr and root->right->right == nullptr) {
                if (root->right->val == subRoot->right->val) {
                    if (root->right->right == nullptr and root->right->left == nullptr) {
                        return true;
                    }
                }
            } else {
                return false;
            }
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};