// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode;
        /*
        We need to recurse through both trees depending on the value of the key
        
        If root == nullptr:
            make a new treenode
            initialize the value with val
            return this new treenode;
        
        
        if the val is greater than the rootval and the root has two children:
          root->right = InsertBST(root->right, val);
        otherwise if the val is less than the rootval and the root has two children:
          root->left = InsertBST(root->left, val);
            
          
         return root
        */
        
        
        if (root == nullptr) {
            newnode = new TreeNode;
            newnode->val = val;
            return newnode;
        }
        
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        
    
        return root;
        
        
        
    
    }
};