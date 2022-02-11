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
            ListNode *Tail;
            ListNode *Next;
            ListNode *current = head;
            ListNode* OldTail;
            if (head == nullptr) {
                return nullptr;
            }
            while (current != nullptr) {
                if (current->next == nullptr) {
                    Tail = current;
                    OldTail = current;
                }
                current = current->next;
            }
            current = head;
            while (k--) {
                while (current != OldTail) {
                    Next = current->next;
                    current->next = nullptr;
                    Tail->next = current;
                    Tail = current;
                    current = Next;
                }
                current = Next;
                OldTail = Tail;
            }
            return current;
        }
    };