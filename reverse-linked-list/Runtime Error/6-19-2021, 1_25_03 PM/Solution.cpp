// https://leetcode.com/problems/reverse-linked-list

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
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
            if (Current == nullptr) {
                return Previous;
            }
            else if (Current->next == nullptr) {
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