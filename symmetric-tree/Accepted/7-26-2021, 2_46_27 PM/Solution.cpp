// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        if (isMirror(root->left, root->right)) {
            return true;
        } else {
            return false;
        }
        //If the value of the root is null
        //Then I should just return false
        //if the root
        // Symmetric(root2, root3);
        
        
        //need to compare left node of left subtree first and then and then the right node
        //of the right subtree 
        
        //need to compare right node of left subtree and then the left node of the left subtree
        
    }
    
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr and root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr or root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        
        return isMirror(root1->left, root2->right) and isMirror(root1->right, root2->left);
    }
};