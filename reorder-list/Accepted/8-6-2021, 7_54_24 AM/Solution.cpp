// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return;
        }
        //head of first half 
        ListNode* l1 = head;
        //head of second half 
        ListNode* slow = head;
        
        //tail of second half
        ListNode* fast = head;
        
        //tail of first half.
        ListNode* prev = nullptr; 
        
        
        while (fast != nullptr and fast->next != nullptr) {
            prev = slow;
            //tail of the first part of the linked list
            slow = slow->next;
            //
            fast = fast->next->next;
            //

        }
        
        prev->next = nullptr; 
        ListNode* l2 = reverselist(slow);
        //1 -> 2 -> 3 -> 4 -> null;
        //8 -> 7 -> 6 -> 5 -> null;
        merge(l1, l2);
    }
    
    
    
    ListNode* reverselist(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* temp;
        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
    //1 2 
    //4 3 
    
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr) {
            //we need to save the l1's next so once you finish linking the top and bottom,
            //We can link the bottom with the top list, which is l1->next
            //need temp places to store the next nodes 
            //cause once you change the direction of the current pointers l1 and l2
            //will not have access to l1->next or l2->next unless you make atemp
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            l1->next = l2;
            //since l2 starts at the beginning with l1
            //we can just make the first pointer pointer to the botoom;
            if (l1_next == nullptr) {
                //if we're at the tail we should
                //just halt the process. 
                break;
            }
           
            l2->next = l1_next;
            //make bottom pointer of l2 point to the next top of l1
            
            
            //move onto the next pointers that need to be arranged.
            l1 = l1_next;
            l2 = l2_next;
        }
    }
    
    
    
    
  
};