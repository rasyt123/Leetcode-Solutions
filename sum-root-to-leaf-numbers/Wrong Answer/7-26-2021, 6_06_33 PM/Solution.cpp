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
    int sumNumbers(TreeNode* root) {
        int total;
        string pathsum;
        vector<string> sumnums;
        //Need to carry a string over to all the paths and keeping adding letters to the string
        //use stoi to convert the value of the string to an integer
        //use vector of vector of strings to hold all path values
        //if the left and right of the currentnode is null, then we add the string to the vector of strings
        //after all the recursive calls are done, we can just sum up all the strings inside of the vector
        //Use postorder traversal
        addnums(root, sumnums, pathsum);
        for (auto item : sumnums) {
            total += stoi(item);
        }
        return total;

    }

    void addnums(TreeNode* root, vector<string>& sumnums, string pathsum) {
        pathsum += to_string(root->val);
        if (root->left == nullptr and root->right == nullptr) {
            sumnums.push_back(pathsum);
            return;
        }

        addnums(root->left, sumnums, pathsum);
        addnums(root->right, sumnums, pathsum);
        return;
    }
};
