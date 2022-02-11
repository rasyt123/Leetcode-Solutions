// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        ListNode* Head = head;
        std::stack<int> stack1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        curr = prev;
        while (curr != NULL) {
            stack1.push(curr->val);
            curr = curr->next;
        }
        curr = prev;
        while (curr != NULL) {
            if (curr->val != stack1.top()) {
                return false;
            } else {
                stack1.pop();
            }
            curr = curr->next;
        }
        if (stack1.empty()) {
            return true;
        } else {
            return false;
        }
    }
};