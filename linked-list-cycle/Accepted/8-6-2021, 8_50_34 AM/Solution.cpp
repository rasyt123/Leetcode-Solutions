// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //3 - > 2 - > 0 -> -4
        // - > 2 
        // First we need to check if the next is null
        // return false immediately 
        //we need to go through the linked list one by one 
        // Use hashtable to remember each of the nodes mapped to the index
        // if the next pointer is an node that exists in the hashtable
        //return true;
        map<ListNode*, int> l1nodes;
        
        ListNode* curr = head;
        int index = 0;
        while (curr != nullptr) {
            if (curr->next == nullptr) {
                return false;
            }
            if (l1nodes.find(curr) != l1nodes.end()) {
                return true;
            }
            l1nodes[curr] = index;
            ++index;
            curr = curr->next;
        }
        return false;
        
    }
};