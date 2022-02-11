// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        /*
        We can initailize 2 dummy linked list nodes
        and merge these at the end
        and a counter for odd or even
        when we traverse through the linked list, if the index is even, set the next of
            if the index is even:
                dummy1->next = curretnode;
                dummy1 = dummy1->next
            otherwise
                dummy2->next = currentnode;
                dummy2 = dummy2->next
        1 3 5
        dummy1 next = 2
        2 4
        return head;
        */

        int currindex = 1;
        ListNode* dummy1 = new ListNode;
        ListNode* curdummy1 = dummy1;
        ListNode* dummy2 = new ListNode;
        ListNode* curdummy2 = dummy2;

        ListNode* curr = head;

        while (curr != nullptr) {
            if (currindex % 2 == 0) {
                dummy1->next = curr;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = curr;
                dummy2 = dummy2->next;
            }
            currindex += 1;
            curr = curr->next;
        }
        dummy1->next = nullptr;
        dummy2->next = nullptr;
        dummy2->next = curdummy1->next;
        return curdummy2->next;

    }
};