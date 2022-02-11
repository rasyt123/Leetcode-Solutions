// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /*
        perform regular level order traversal and then 
        reverse the result 
        */
        if (root == nullptr) {
            return {};
        }
        
        queue<TreeNode*> q1;
        q1.push(root);
        vector<vector<int>> levelresult;
        while (!q1.empty()) {
            int size = q1.size();
            vector<int> currlevel;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q1.front();
                currlevel.push_back(curr->val);
                q1.pop();
                if (curr->left != nullptr) {
                    q1.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q1.push(curr->right);
                }
            }
            levelresult.push_back(currlevel);
        }
        reverse(levelresult.begin(), levelresult.end());
        return levelresult;
    }
                
    
};