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
            if (helper(root, subRoot)) {
                return true;
            } else {
                return false;
            }
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (root->val != subRoot->val) {
            return false;
        }
        if (root->val == subRoot->val and subRoot->left == nullptr and subRoot->right == nullptr and root->right == nullptr and root->left == nullptr) {
            return true;
        }
        
        if (root->val == subRoot->val and subRoot->left != nullptr and subRoot->right != nullptr and root->left != nullptr and root->right != nullptr) {
            return true and helper(root->left, subRoot->left) and helper(root->right, subRoot->right);
        }
        else if (root->val == subRoot->val and subRoot->left != nullptr and root->left != nullptr) {
            return true and helper(root->left, subRoot->left);
        } else if (root->val == subRoot->val and subRoot->right != nullptr and root->right != nullptr) {
            return true and helper(root->right, subRoot->right);
        }
        return false;
    }
};