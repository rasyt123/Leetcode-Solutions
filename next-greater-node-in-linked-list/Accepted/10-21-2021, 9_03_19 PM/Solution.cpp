// https://leetcode.com/problems/next-greater-node-in-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        /*
        create a vector of integers
        Create a new dummy node.
        this is probably going to be a O(n^2) solution 
        from a particular node that we start at 
    we iterate through the linked list
        root == curr;
        we iterate through the linked list with another node pointer
            if the value to the right is greater than root 
                we push the index of the 
            increment currindex;
            
        */
        ListNode* curr = head;
        vector<int> result;
        while (curr != nullptr) {
            ListNode* compare = curr;
            while (compare != nullptr) {
                if (compare->val > curr->val) {
                    result.push_back(compare->val);
                    break;
                }
                compare = compare->next;
            }
            if (compare == nullptr) {
                result.push_back(0);
                
            }
            curr = curr->next;
        }
        return result;
        
        
        
        
    }
};