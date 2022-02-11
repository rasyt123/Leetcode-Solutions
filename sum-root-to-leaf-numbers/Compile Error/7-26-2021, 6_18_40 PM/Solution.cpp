// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    vector<int> res;
    void Util(TreeNode* root, int sum)
    {
        if(root==NULL)
        {
            return;
        }
        if(sum==0)
        {
            sum += root->val;
        }
        else
        {
            sum = (sum*10)+root->val;
        }
        if(root->left==NULL && root->right==NULL)
                res.push_back(sum);
        Util(root->left,sum);
        Util(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        Util(root,0);
        return accumulate(res.begin(),res.end(),0);
    }
}