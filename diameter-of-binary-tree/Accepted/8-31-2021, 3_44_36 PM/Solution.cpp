// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> depthvector;
        dfs(root, depthvector);

        return *max_element(depthvector.begin(), depthvector.end());


    }
    int findHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }



    void dfs(TreeNode* root, vector<int>& depthvector) {
        int heightleft;
        int heightright;
        if (root == nullptr) {
            return;
        }

        heightleft = findHeight(root->left);
        heightright = findHeight(root->right);
        depthvector.push_back(heightleft + heightright);

        dfs(root->left, depthvector);
        dfs(root->right, depthvector);
    }
};