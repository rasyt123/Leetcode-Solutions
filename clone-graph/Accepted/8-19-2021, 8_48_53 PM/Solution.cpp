// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> G2;
        map<Node*, bool> marked;
        Node* clone;
        if (node == nullptr) {
            return nullptr;
        }
        
        dfs(node, G2, marked);
        return G2[node->val];
    }
    
    
    void dfs(Node* node, map<int, Node*>& G2,  map<Node*, bool>& marked) {
        int nodeval;
        Node* newnode = nullptr;
        if (marked.find(node) == marked.end()) {
            newnode = new Node(node->val);
            G2[newnode->val] = newnode;
        }
        marked[node] = true;
        for (Node* item : node->neighbors) {
            if(marked.find(item) == marked.end()) {
                dfs(item, G2, marked);
            }
        }
        if (newnode != nullptr) {
            for (Node* item : node->neighbors) {
                nodeval = item->val;
                newnode->neighbors.emplace_back(G2[nodeval]);
            }
        }
    }

        
        
};