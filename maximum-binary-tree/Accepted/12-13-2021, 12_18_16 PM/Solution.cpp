// https://leetcode.com/problems/maximum-binary-tree

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        /*
        [3,2,1,6,0,5]

        [3, 2, 1]

        [0, 5]
        l should start as zero and r should be nums.size() - 1

        1. create a new node when recursing but have this node
        be the max of the existing subarray or array

        l index and r index
        for left subarray prefix, r should me index of max - 1
        and l should stay the same

        for right subarray prefix, l should be index of max + 1
        and r should be end of the array

        */
        int l = 0;
        int r = nums.size() - 1;
        TreeNode* result = buildTree(nums, l, r);
        return result;
    }


    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (r < 0 or l > nums.size() - 1) {
            return nullptr;
        }
        int maxval = nums[l];
        int maxid = l;
        for (int left = l; left <= r; left++) {
            if (nums[left] > maxval) {
                maxval = nums[left];
                maxid = left;
            }
        }
        TreeNode* maxnode = new TreeNode;
        maxnode->val = maxval;
        maxnode->left = buildTree(nums, l, maxid - 1);
        maxnode->right = buildTree(nums, maxid + 1, r);
        return maxnode;
    }
};