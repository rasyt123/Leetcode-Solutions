// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
        Use level order traversal
        on each level, store a vector nodes.
        iterate through this vector:
            set the next value of the ith node to be the ith + 1 
            set the last next node value in the vector to be null 
        we return the root
        */
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node*> q1;
        q1.push(root);
        while (!q1.empty()) {
            int size = q1.size();
            vector<Node*> currlevel;
            for (int i = 0; i < size; i++) {
                Node* curr = q1.front();
                currlevel.push_back(curr);
                q1.pop();
                if (curr->left != nullptr) {
                    q1.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q1.push(curr->right);
                }
            }
            for (int i = 0; i < currlevel.size() - 1; i++) {
                currlevel[i]->next = currlevel[i + 1];
            }
            currlevel[currlevel.size() - 1]->next = nullptr;
            currlevel = {};
        }
        return root;
    }
};