// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        TreeNode* current;
        bool foundp;
        bool foundq;
        vector<TreeNode*> BST;
        queue<TreeNode*> add;
        add.push(root);
        while (!add.empty()) {
            current = add.front();
            add.pop();
            if (current->left != nullptr) {
                add.push(current->left);
            }
            if (current->right != nullptr) {
                add.push(current->right);
            }
            BST.push_back(current);
        }

        for (int i = 0; i < BST.size(); i++) {
            current = BST[i];
            foundp = BSTContains(current, p);
            foundq = BSTContains(current, q);
            if (foundp and foundq) {
                lca = current;
            }
        }
        return lca;

    }


    bool BSTContains(TreeNode* currnode, TreeNode* descendant) {
        TreeNode* beast = currnode;
        while (beast) {
            if (descendant->val == beast->val) {
                return true;
            }
            if (descendant->val < beast->val) {
                beast = beast->left;
            } else {
                beast = beast->right;
            }
        }

        return false;
    }
};
