// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
    public:
    BSTIterator(TreeNode* root) {
        /*
         I need an inorder traversal starting from the root
         can add the items into a vector that holds the traversal
         next can add to the currindex and return the item at 
         the current index 

         hasnext can return true if currindex is not out of range of the vector


        */

        currindex = -1;
        vector<int> inordertraversal = {};
        dfs(root);
    }
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }

        dfs(root->left);
        inordertraversal.push_back(root->val);
        dfs(root->right);
    }
    int next() {
        ++currindex;
        return inordertraversal[currindex];
 
    }

    bool hasNext() {
        int index;
        index = currindex;
        ++index;
        if (index >= inordertraversal.size()) {
            return false;
        } else {
            return true;
        }
        
    }
    private:
        int currindex;
        vector<int> inordertraversal;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */