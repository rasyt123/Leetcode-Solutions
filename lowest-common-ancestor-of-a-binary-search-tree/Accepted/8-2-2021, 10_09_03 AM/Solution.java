// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //A node that is an ancestor is one that has a value that is between p and q 
        // A parent node is one that has a node larger than itself or less than itself .

        // Value of current node or parent node.
        int parentVal = root.val;

        // Value of p
        int pVal = p.val;

        // Value of q;
        int qVal = q.val;
        //The starting root is not an ancestor but the base. if both q and p's values are greater than the base
        //and the base has an existing left and right pointers to left and right subtrees, then their exists
        // another node that has a split, hence the 
        //

        if (pVal > parentVal && qVal > parentVal) {
            //If both p and qs values are greater than the current node's val.
            //we know that both of those nodes are in the right subtree
            //so we should keep exploring until we find 
            // If both p and q are greater than parent
            return lowestCommonAncestor(root.right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            //We need to explore the left subtree for an ancestor 
            // If both p and q are lesser than parent
            return lowestCommonAncestor(root.left, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            //
            return root;
        }
    }
}