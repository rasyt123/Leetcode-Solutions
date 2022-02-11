// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        /*
            current node is
            I need to use a fast pointer with curr->next->next so I can link the swapped pointer to the third node
            Imagine you swapped 2 and 1 so 2 points to 1, 2 no longer pointers to 3, so this is why prev
            curr
       while (nextemp->next != nullptr)
            nexttemp = prev->next->next;
            curr = prev->next;
            prev->next = null
            curr->next = prev;
            prev->next = nexttemp;


        */
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }

        ListNode* nexttemp = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* temp;
        ListNode* secondcurr = curr;
        ListNode* behind = nullptr;
        bool first = true;
        while (nexttemp != nullptr and nexttemp->next != nullptr) {
            nexttemp = prev->next->next;
            prev->next = nullptr;
            curr->next = prev;
            prev->next = nexttemp;


            temp = prev;
            prev = curr;
            curr = temp;


            if (first) {
                first = false;
            } else {
                behind->next = prev;
            }
            behind = curr;

            prev = prev->next->next;
            if (curr->next == nullptr) {
                break;
            }
            curr = curr->next->next;
        }

        return secondcurr;
    }
};