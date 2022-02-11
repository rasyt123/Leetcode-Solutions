// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        vector<int> bintree;
        TreeNode* deletion;
        TreeNode* childleft;
        TreeNode* childright;
        TreeNode* moot;
        bool first = true;
        
        if (root == nullptr) {
            return bintree;
        }
        
        s1.push(root);
        
        if (root->right != nullptr and root->left != nullptr) {
            childleft = root->left;
            childright =  root->right;
        }
        
        while (!s1.empty()) {
            root = s1.top();
            if (root->right == nullptr and root->left == nullptr) {
                if (childleft != nullptr and childright != nullptr) {
                    if (first) {
                        while (s1.top() != childright) {
                            bintree.push_back(s1.top()->val);
                            s1.pop();
                            first = false;
                        }
                    } else {
                         while (!s1.empty()) {
                            bintree.push_back(s1.top()->val);
                            s1.pop();
                        }
                    }
                } else {
                    while (!s1.empty()) {
                        bintree.push_back(s1.top()->val);
                        s1.pop();
                    }
                }
            }
            if (root->right != nullptr) {
                s1.push(root->right);
            }
            if (root->left != nullptr) {
                s1.push(root->left);
            }
        }
        return bintree;
    }
};