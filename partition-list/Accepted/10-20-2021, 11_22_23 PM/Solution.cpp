// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        /*
        all nodes less than x
        all nodes equal to x
        all nodes greater than x
        */
        ListNode* l1 = head;

        ListNode* dum2 = new ListNode;
        ListNode* head2 = dum2;


        ListNode* dum4 = new ListNode;
        ListNode* head4 = dum4;

        while (l1 != nullptr) {
            if (l1->val < x) {
                dum2->next = l1;
                dum2 = dum2->next;
            } else if (l1->val >= x) {
                dum4->next = l1;
                dum4 = dum4->next;
            }
            l1 = l1->next;
        }
        dum4->next = nullptr;
        dum2->next = head4->next;
        return head2->next;



    }
};