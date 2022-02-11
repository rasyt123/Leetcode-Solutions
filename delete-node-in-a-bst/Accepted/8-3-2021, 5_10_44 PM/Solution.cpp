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

        return temp;

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
            //if the root val is bigger than the key, we need to go the left subtree
            //each recursive call will return the node it's currently on
            root->left = deletezanode(root->left, root, key);
        } else if (root->val < key) {
            //if the root val is smaller than the key, we need to search to the right subtree
            root->right = deletezanode(root->right, root, key);
        } else {
            // 3 scenarious of deletion 
            
            
            //if the root is a leaf, just return null so the previous node recursive call
            // can connect its pointer 
            if (root->left == nullptr and root->right == nullptr) {
                return nullptr;
            } else if (root->left == nullptr) {
                return root->right;
                //when u delete a node with only one child, just return the current node's child so the 
                //previous node will take ownership of it
            } else if (root->right == nullptr) {
                //when u delete a node with only one child, just return the current node's child so the 
                //previous node will take ownership of it.
                return root->left;
            }
            
            
            
            //if the node u want to delete has multiple children
            //replace the current node with the minimum value from the right subtree
            //the node that was going to be the replaced will be checked by the function so it can be queued 
            //up for removal with the three cases. 
        
            minnode = findminnode(root->right);
            root->val = minnode->val;
            root->right = deletezanode(root->right, root, minnode->val);

        }
        return root;
    }
    };

