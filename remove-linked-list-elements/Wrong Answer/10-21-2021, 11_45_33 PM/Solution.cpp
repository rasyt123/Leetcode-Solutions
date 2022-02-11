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
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* dummy = new ListNode;
        if (curr != nullptr and curr->val == val) {
            curr = curr->next;
        }
        dummy->next = head;
        while (curr != nullptr) {
            ListNode* temp = curr;
            curr = curr->next;
            prev = temp;
            if (curr != nullptr and curr->val == val) {
                prev->next = curr->next;
            }
        }
        return dummy->next;
        //1 2 3
    }
};