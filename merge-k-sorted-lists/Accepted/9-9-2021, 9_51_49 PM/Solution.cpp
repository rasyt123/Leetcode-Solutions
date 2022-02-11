// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            store all of the linkedlist nodes
            in a hashmap with the value as the first element of the pair
            and the node itself as the second

            add all of the linked list nodes into a binary min heap
            with the value associated with the node

            go through the entire priority queue and construct the linked list
            with a dummy node.
        */
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* dummy;
        ListNode* newnode;
        ListNode* curr;
        dummy = new ListNode;
        ListNode* other = dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (int i = 0; i < lists.size(); i++) {
            curr = lists[i];
            while (curr != nullptr) {
                pq.push({curr->val,curr});
                curr = curr->next;
            }
        }
        while (!pq.empty()) {
            auto node = pq.top();
            dummy->next = node.second;
            dummy = dummy->next;
            pq.pop();
        }
        return other->next;

    }
};