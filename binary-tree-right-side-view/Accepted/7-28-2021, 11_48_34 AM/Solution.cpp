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
        vector<int> levelordernodes;
        int numlevels;
        numlevels = maxDepth(root);
        LevelOrderRecur(root, numlevels, source, levelordernodes);
        return source;
    }
    
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
        
    }
    
    void LevelOrderRight(TreeNode* root, int level, vector<int>& source, vector<int>& levelordernodes) {
        int item;
        if (root == nullptr) {
            return;
        }
        if (level == 1) {
            item = root->val;
            levelordernodes.push_back(item);
        } else {
            LevelOrderRight(root->right, level - 1, source, levelordernodes);
            LevelOrderRight(root->left, level - 1, source, levelordernodes);
        }
        
        
    }
    
    void LevelOrderRecur(TreeNode* root, int levels, vector<int>& source, vector<int>& levelordernodes) {
        for (int i = 1; i <= levels; i++) {
            LevelOrderRight(root, i, source, levelordernodes);
            if (levelordernodes.size() >= 1) {
                source.push_back(levelordernodes[0]);
                levelordernodes.clear();
            }
        }
        
    }
};