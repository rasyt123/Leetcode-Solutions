// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int kthSmallest(TreeNode* root, int k) {
        //try inorder traversal
        //With an inorder traversal, it is LNR, so you process nodes starting fro mthe bottom left and then the right 
        //And you ripple up/.
        //as you pop the elements from the stack, since the top of the stack has all the bottom nodes,
        //we can keep decrementing a variable that is equivalent to k 
        // and once that variable is equal to k, then we should return the val that is currently on the stack
        stack<TreeNode*> s1;
        TreeNode* node = root;
        
        if (root == nullptr) {
            return 0;
        }
        
        
        while (true) {
            if (node != nullptr) {
                s1.push(node);
                node = node->left;
            } else {
                if (s1.empty()) {
                    break;
                }
                node = s1.top();
                if (k == 1) {
                    return node->val;
                }
                s1.pop();
                --k;
                node = node->right;
            } 
        }
        return node->val;
    
        
          
        
        
    }
};