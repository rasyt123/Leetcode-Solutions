// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        /*
        We use two pointers
        one slow and one fast 
        
        fast = 2ms/ s 
        slow = 1ms/s 
        
        When the fast pointer finishes going to the end from one point to antother, and because it moves twice as fast 
        as slow, slow will be at the halfway point of the linked list 
        when fast reaches the end 
        
        
            4ms      
        - - - - -
        
        - - - 
           2ms 
        
        
        */
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
        
    }
};