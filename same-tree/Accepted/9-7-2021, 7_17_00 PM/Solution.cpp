// https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
          We can use a depth first search traversing through the nodes p and q at the same time
          We can compare the values at each of the node.
          if one is null and the other isnt that basically says that the structure of the trees
          is not the same so we should return false;
          
                    
          if both p and q are null then we can return trye
                      
          if the values at the nodes are different then we should return false
          
          Both p and q subtrees should be the same
        
        
        
    
        */
        if (p == nullptr and q == nullptr) {
            return true;
        }
        
        if ((p == nullptr and q != nullptr) or (q == nullptr and p != nullptr)) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
    
    
};