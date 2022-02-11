// https://leetcode.com/problems/balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        //use recursive bfs calling the left and right of the node of the binary tree
        // you need to recursive calls to cover the right subtree and left subtree
        // you only need one parameter for this recursive function 
        //
        //so basically, 
        //isBalanced(TreeNode* root1, TreeNode* root2)
        // if root1 and root2 are both nullptr, then 
        //      should just set the depth to be zero
        //if abs(depth(root1) - depth(root2->left)) > 1
        // return false
        // else:
        //    isBalanced(root1->left, root1->right);
        //    isBalanced(root2->left, root2->right);
        //
        //
        //Start with using the  
        //Use depth helper//
        //Calculates the height of a subtree;
        if (!checkHeight(root->left, root->right)) {
            return false;
        } else {
            return true;
        }
    
    
        
    }
    
    bool checkHeight(TreeNode* root1, TreeNode* root2) {
        int height1;
        int height2;
        
        height1 = Height(root1);
        height2 = Height(root2);
        
        if (abs(height1 - height2) > 1) {
            return false;
        } else if (root1 != nullptr and root2 != nullptr) {
            return checkHeight(root1->left, root1->right) and checkHeight(root2->left, root2->right);
        }
        return true;
    }
    
    int Height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int lDepth = Height(root->left);
            int rDepth = Height(root->right);
            
            if (lDepth > rDepth) {
                return (lDepth + 1);
            } else {
                return (rDepth + 1);
            }
        }
        
        
    }
};