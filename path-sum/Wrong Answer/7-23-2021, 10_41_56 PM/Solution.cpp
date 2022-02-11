// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool sumexists = false;
        bool success;
        //For this problem, I need to recurse through the left and right subtrees and add the values as I recurse.
        //if we keep adding and the sum happens to be bigger than the target, we should just return false;
        //As we recurse through the tree, if the sum happens to be the target, we should return true immediately.
        helper(root, targetSum, 0, &sumexists);
        if (targetSum == 0) {
            return false;
        }
        return sumexists;
    }

    void helper(TreeNode* root, int targetSum, int thesum, bool* foundmatch) {
        bool match1;
        if (root != nullptr and root->val == targetSum and (root->left || root->right)) {
            return;
        } else if (thesum == targetSum) {
            *foundmatch = true;
            return;
        }
        if (root == nullptr) {
            return;
        }
        if (root->val + thesum > targetSum) {
            return;
        }
        helper(root->left, targetSum, thesum + root->val, foundmatch);
        helper(root->right, targetSum, thesum + root->val, foundmatch);
    }
};