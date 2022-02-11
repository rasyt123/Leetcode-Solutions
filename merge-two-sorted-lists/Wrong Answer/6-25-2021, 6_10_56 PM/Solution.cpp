// https://leetcode.com/problems/merge-two-sorted-lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr and l2 == nullptr) {
            return l1;
        }
        ListNode* head = nullptr;
        ListNode* temp;
        ListNode* l1front = l1;
        ListNode* l2front = l2;
        ListNode* prev;
        ListNode* tail;
        bool found;
        int minimumval;
        if (l1 != nullptr) {
            minimumval = l1->val;
        } else if (l2 != nullptr) {
            minimumval = l2->val;
        }
        while (l1 != nullptr or l2 != nullptr) {
            l1 = l1front;
            while (l1 != nullptr) {
                if (l1->val <= minimumval) {
                    minimumval = l1->val;
                }
                l1 = l1->next;
            }
            l1 = l1front;
            l2 = l2front;
            while (l2 != nullptr) {
                if (l2->val <= minimumval) {
                    minimumval = l2->val;
                }
                l2 = l2->next;
            }
            l2 = l2front;
            while (l1 != nullptr) {
                if (minimumval == l1->val) {
                    temp = l1;
                    found = true;
                    break;
                }
                l1 = l1->next;
            }
            if (found) {
                l1front = temp->next;
                found = false;
            } else {
                while (l2 != nullptr) {
                    if (minimumval == l2->val) {
                        temp = l2;
                        l2front = temp->next;
                        break;
                    }
                    l2 = l2->next;
                }
            }
            if (head == nullptr) {
                head = temp;
                head->next = nullptr;
                tail = head;
            } else {
                if (l1 == nullptr and l2 == nullptr) {
                    break;
                } else {
                    tail->next = temp;
                    tail = temp;
                    tail->next = nullptr;
                }
            }
            if (l1 != nullptr) {
                if (l1front == nullptr) {
                    minimumval = temp->val;
                } else {
                    minimumval = l1front->val;
                }
            } else {
                if (l2 != nullptr) {
                    if (l2front == nullptr) {
                        minimumval = temp->val;
                    } else {
                        minimumval = l2front->val;
                    }
                }
            }
        }
        return head;

    }
};