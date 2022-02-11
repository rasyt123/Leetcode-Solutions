// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        
        both nodes p and q appear in the subtrees of a particular node 
        or (left/right children)
        
        that means when we're at particular node, 
        we need to return true that we've found one node P in a subtree
        and return true that we've found one node q in a subtree 
        
        
        two cases:
                   when p is the node itself and q exists in a subtree of p
                   when q is the node itself and p exists in a subtree of q 
        
        We can solve this with post order traversal 
        We start from the bottom, returning true if the left or right subtrees have a p or q 
        Pass in reference for LCA 
        */
        dfs(root, p, q);
        return lca;
     
    }
    
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool leftsub = dfs(root->left, p, q);
        bool rightsub = dfs(root->right, p, q);
        if ((p->val == root->val and leftsub) or (p->val == root->val and rightsub)) {
            lca = root;
            found = true;
        } else if ((q->val == root->val and leftsub) or (q->val == root->val and rightsub)) {
            lca = root;
            found = true;
        }
        
        if (p->val == root->val or q->val == root->val) {
            return true;
        }
        
        if (leftsub and rightsub and !found) {
            lca = root;
            found = true;
        }
        return leftsub or rightsub;

    }
    
    
    private:
        TreeNode* lca;
        bool found = false;
};