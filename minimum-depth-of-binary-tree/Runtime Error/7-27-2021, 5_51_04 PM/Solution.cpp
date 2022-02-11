// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int minDepth(TreeNode* root) {
        vector<int> depthvector;
        int rootdepth = 1;
        helper(root, depthvector, 1);
        int minvalue;
        minvalue = depthvector[0];
        if (root == nullptr) {
            return 0;
        } else {
            for (int i = 0; i < depthvector.size(); i++) {
                if (depthvector[i] < minvalue) {
                    minvalue = depthvector[i];
                }
            }
            return minvalue;
        }
        
        
    }
    
    void helper(TreeNode* root, vector<int>& depthvector, int depth) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr and root->right == nullptr) {
            depthvector.push_back(depth);
            return;
        } else {
            ++depth;
        }
        
        helper(root->left, depthvector, depth);
        helper(root->right, depthvector, depth);
    }
};