// https://leetcode.com/problems/reverse-linked-list

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* Current = head;
        ListNode* Previous;
        ListNode* Next = head->next;

        Previous = Current;
        Current = Next;
        Next = Current->next;
        Current->next = Previous;
        Previous->next = nullptr;
        while (Current != nullptr) {
            Previous = Current;
            Current = Next;
            if (Current->next == nullptr) {
                Current->next = Previous;
                break;
            } else {
                Next = Current->next;
                Current->next = Previous;
            }
        }
        return Current;
    }
};