// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = head;
        ListNode* NthEnd;
        ListNode* temp;
        int size = 0;
        int prevn;
        while (start != nullptr) {
            ++size;
            start = start->next;
        }
        if (size == 1 and n == 1) {
            free(head);
            head = nullptr;
            return head;
        } else {
             start = head;
             prevn = size - n - 1;
             if (size - n == 0) {
                head = start->next;
                start->next = nullptr;
                return head;
             } else if (size - n == size - 1) {
                 prevn = size - 2;
                 while (prevn--) {
                     start = start->next;
                 }
                 temp = start->next;
                 start->next = nullptr;
                 return head;
             } else {
                 while (prevn--) {
                     start = start->next;
                 }
                 start->next = start->next->next;
                 return head;
             }
        }


    }
};