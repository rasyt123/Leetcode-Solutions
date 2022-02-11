// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1size = 0;
        int l2size = 0;
        int sizedif;
        int carryover;
        int temp;
        ListNode* zimp = l1;
        ListNode* headl1 = l1;
        ListNode* headl2 = l2;
        ListNode* Tail;
        ListNode* temporary;
        while (headl1 != nullptr) {
            ++l1size;
            headl1 = headl1->next;

        }

        while (headl2 != nullptr) {
            ++l2size;
            headl2 = headl2->next;
        }

        headl1 = l1;
        headl2 = l2;

        if (l1size > l2size) {
            sizedif = l1size - l2size;
            while (headl2 != nullptr) {
                if (headl2->next == nullptr) {
                    Tail = headl2;
                }
                headl2 = headl2->next;
            }
            while (sizedif--) {
                ListNode* temporary = new ListNode;
                temporary->val = 0;
                Tail->next = temporary;
                temporary->next = nullptr;
                Tail = temporary;
            }
        } else if (l2size > l1size) {
            sizedif = l2size - l1size;
            while (headl1 != nullptr) {
                if (headl1->next == nullptr) {
                    Tail = headl1;
                }
                headl1 = headl1->next;
            }
            while (sizedif--) {
                ListNode* temporary = new ListNode;
                temporary->val = 0;
                Tail->next = temporary;
                temporary->next = nullptr;
                Tail = temporary;
            }
        }

        while (l1 != nullptr and l2 != nullptr) {
            l1->val = l1->val + l2->val;
            if (l1->val >= 10 && l1->next == nullptr) {
                l1->val = l1->val % 10;
                ListNode* temporary = new ListNode;
                temporary->val = 0;
                l1->next = temporary;
                temporary->next = nullptr;
                l1 = temporary;
                temp = l1->val;
                l1->val = 1;
            }
            else if (l1->val >= 10) {
                temp = l1->val;
                l1->val = l1->val % 10;
                temp = temp / 10;
                l1->next->val = l1->next->val + temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return zimp;

    }
};