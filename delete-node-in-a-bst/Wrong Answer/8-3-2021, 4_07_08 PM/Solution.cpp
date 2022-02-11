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
        TreeNode* parent;
        TreeNode* temp;
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr and root->right == nullptr and key == root->val) {
            return nullptr;
        }

        parent = nullptr;
        temp = deletezanode(root, parent, key);

        return root;

    }

    TreeNode* findminnode(TreeNode* root) {
        TreeNode* currnode = root;
        while (currnode->left != nullptr) {
            currnode = currnode->left;
        }
        return currnode;

    }


    //When we delete a node, we want to replace the current node with the minimum on the right subtree
    // which means picking at a leaf all the way down to the left of the right subtree
    //IT would be a pain in the ass to replace the current node with a node that isnt a leaf that has more than
    // one child
    //If you cant go left then the right subtree node is all you have for a replacement
    //
    //


    TreeNode* deletezanode(TreeNode* root, TreeNode* parent, int key) {
        TreeNode *minnode;
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > key) {
            root->left = deletezanode(root->left, root, key);
        } else if (root->val < key) {
            root->right = deletezanode(root->right, root, key);
        } else {
            if (root->left == nullptr and root->right == nullptr) {
                return nullptr;
            } else if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            }
            minnode = findminnode(root->right);
            root->val = minnode->val;
            root->right = deletezanode(root->right, root, minnode->val);

        }
        return root;
    }
    };

