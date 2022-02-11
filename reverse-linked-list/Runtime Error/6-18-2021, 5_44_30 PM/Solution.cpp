// https://leetcode.com/problems/reverse-linked-list



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* Current = head;
        ListNode* Previous = nullptr;
        ListNode* Next = head->next;
        
        while (head != nullptr) {
            Previous = head;
            head = Next;
            if (head->next == nullptr) {
                head->next = Previous;
                
                return head;
            } else {
                Next = head->next;
                head->next = Previous;
              
            }
            
        }
        return head;
    }
};