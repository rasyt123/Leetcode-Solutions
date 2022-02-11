// https://leetcode.com/problems/rotate-list

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
private:


public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* Head = head;
        ListNode* current = head;
        ListNode* Tail;
        int temp;
        int value;
        while (k--) {
            value = Head->val;
            while (current != nullptr) {
                if (current->next == nullptr) {
                    Tail = current;
                    Tail->next = Head;
                    Head->val = value;
                    Tail->next = nullptr;
                } else {
                    temp = current->next->val;
                    current->next->val = value;
                    value = temp;
                }
                current = current->next;
            }
            current = head;
        }
        return head;
    }
};