// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
        
        
        while curr is not null and pos <= right + 1
         if pos == l - 1:
            startprev = curr;
         if pos == r + 1:
            endafter = curr
         if pos >= left and <= right:
            if pos == left:
                tail = curr
            temp = curr->next
            curr->next = prev;
            prev = curr;
            curr = temp;
          otherwise:
            pos += 1;
            curr = curr->next;
        startprev->next = prev;
        tail->next = endafter;
            
         
        */
        ListNode* curr = head;
        ListNode* startprev = nullptr;
        ListNode* endafter = nullptr;
        ListNode* temp;
        ListNode* prev = nullptr;
        ListNode* tail;
        int pos = 1;
        while (curr != nullptr and pos <= right + 1) {
            if (pos == left - 1) {
                startprev = curr;
            }
            if (pos == right + 1) {
                endafter = curr;
            }
            if (pos >= left and pos <= right) {
                if (pos == left) {
                    tail = curr;
                }
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            } else {
                pos += 1;
                curr = curr->next;
            }
        }
        startprev->next = prev;
        tail->next = endafter;
        if (startprev == nullptr) {
            return prev;
        }
        return startprev;
    
    }
};