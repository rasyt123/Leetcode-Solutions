// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp;
        temp = deletezanode(root, nullptr, key);
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr and root->right == nullptr) {
            return nullptr;
        }
        if (temp != nullptr) {
            return temp;
        } else {
            return root;
        }

    }


    TreeNode* deletezanode(TreeNode* root, TreeNode* parent, int key) {

        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > key) {
            deletezanode(root->left, root, key);
        } else if (root->val < key) {
            deletezanode(root->right, root, key);
        } else {
            if (parent == nullptr and root->left and root->right) {
                root->right->left = root->left;
                root = root->right;
                return root;
            } else if (parent == nullptr and root->left != nullptr) {
                root = root->left;
                return root;
            } else if (parent == nullptr and root->right != nullptr) {
                root = root->right;
                return root;
            }
            
            


            if (root->val < parent->val and root->left != nullptr and root->right != nullptr) {
                parent->left = root->right;
                parent->left->left = root->left;

            } else if (root->val < parent->val) {
                parent->left = root->left;

            }

            if (root->val > parent->val and root->left != nullptr and root->right != nullptr) {
                parent->right = root->left;
                parent->right->right = root->right;
            } else if (root->val > parent->val) {
                parent->right = root->right;

            }
        }
        return nullptr;
    }
};

