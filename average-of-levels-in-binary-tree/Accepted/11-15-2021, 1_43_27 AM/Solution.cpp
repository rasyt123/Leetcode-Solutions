// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        /*
        We can do a bfs at each level, 
        iterate through each node at the level, then 
        add up all the numbers and divide them by the number of nodes on
        the level, then add them to a vector 
        
        */
            
        queue<TreeNode*> q1;
        q1.push(root);
        double sum = 0;
        double curraverage;
        vector<double> doublesaverages;
        while (!q1.empty()) {
            int size = q1.size();
            vector<double> currlevelnodes;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q1.front();
                q1.pop();
                sum += curr->val;
                if (curr->left != nullptr) {
                    q1.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q1.push(curr->right);
                }
            }
            curraverage = sum / size;
            doublesaverages.push_back(curraverage);
            sum = 0;
        }
        return doublesaverages;
    }
};