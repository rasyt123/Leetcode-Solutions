// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> source;
        int numlevels;
        numlevels = countrightDepth(root, 1);
        LevelOrderRecur(root, numlevels, source);
        return source;
    }
    
    
    int countrightDepth(TreeNode* root, int level) {
        if (root == nullptr) {
            return level;
        } else {
            ++level;
        }
        return countrightDepth(root->right, level);
        
    }
    
    void LevelOrderRight(TreeNode* root, int level, vector<int>& source) {
        if (root == nullptr) {
            return;
        }
        if (level == 1) {
            source.push_back(root->val);
        } else {
            LevelOrderRight(root->right, level - 1, source);
        }
        
        
    }
    
    void LevelOrderRecur(TreeNode* root, int levels, vector<int>& source) {
        for (int i = 1; i <= levels; i++) {
            LevelOrderRight(root, i, source);
        }
        
    }
};