// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode;
        ListNode* result = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val != val) {
                dummy->next = curr;
                dummy = dummy->next;
            } else if (curr->next == nullptr) {
                dummy->next = nullptr;
            }
            curr = curr->next;
        }
        return result->next;
        //1 2 3
    }
};