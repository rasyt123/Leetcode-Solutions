// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxPathSum(TreeNode* root) {
        /*
        Preorder traversal + helper 
        
        Paths can have the same sum but also if you traverse from the end to the start node or
        you traverse from the start to the end node, then you will have the same sum.
        
        
        If I were to do this bottom up from a particular path 
        I would need the sum of the left and right subtree and the current node
        helper funciton:
        if the root is null:
            we should just return zero;
        
        
        item max(current + leftsubtree, current + rightsubtree)
        item2 = max(current + leftsubtree + rightsubtree, item);
        return item2;
     
        dfs(root->left);
        dfs(root->right);
        

        */
        int ans;
        ans = 0;
        dfs(root, ans);
        if (ans > maxpathsum) {
            return ans;
        } else {
            return maxpathsum;
        }
    }
    
    int calculatesum(TreeNode* root) { 
        int leftorright;
        int bothsub;
        
       
        if (!root) {
            return 0;
        }
        
        if (root->left == nullptr and root->right == nullptr) {
            return root->val;
        }
         int current = root->val;
        //  -10 + 9,  20 + 15 , 20 + 7 = 2
        leftorright = max(current + calculatesum(root->left), current + calculatesum(root->right));
        bothsub = calculatesum(root->left) + current + calculatesum(root->right);
        if (bothsub > maxpathsum) {
            maxpathsum = bothsub;
        }
        return leftorright;
        
    }
    
    
    void dfs(TreeNode* root, int& ans) {
        int sum;
        if (!root) {
            return;
        }
        
        sum = calculatesum(root);
        if (sum > ans) {
            ans = sum;
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    
    private:
        int maxpathsum = INT_MIN;
};