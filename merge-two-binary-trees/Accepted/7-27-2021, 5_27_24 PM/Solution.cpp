// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        mergeoverlap(root1, root2);
        if (root1 == nullptr and root2 != nullptr) {
            return root2;
        } else {
            return root1;
        }

        //merge helper

        //mergetrees(root1 left, root1 left, root2left, root2left)
        //mergetrees(root1 right, root1 right, root2right,  )


    }

    void mergeoverlap(TreeNode* root1, TreeNode* root2) {
        
        TreeNode* temp;
        if (root2 == nullptr) {
            return;
        }


        if (root1 == nullptr and root2 == nullptr) {
            return;
        }

        if (root1 != nullptr and root2 != nullptr) {
            root1->val = root1->val + root2->val;
        }
        
        if (root1 == nullptr and root2 != nullptr) {
            root1 = root2;
        }
        
        if (root1->right == nullptr and root2->right != nullptr) {
            root1->right = root2->right;
            root2->right = nullptr;
        }

        if (root1->left == nullptr and root2->left != nullptr) {
            root1->left = root2->left;
            root2->left = nullptr;
        }

        mergeoverlap(root1->left, root2->left);
        mergeoverlap(root1->right, root2->right);
        
        return;
    }


};