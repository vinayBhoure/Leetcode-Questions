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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        if(head == NULL || head-> next == NULL)
        {
             return head;
        }
        
        
        
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = head;
        
        for(int i=1; i<left; i++)
        {
            prev = curr;
            curr = curr -> next;
        }
         
        ListNode* start = prev;
        ListNode* end = curr;
        
        for(int i=1; i <= right-left+1;i++)
        {
            forward = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
         end -> next = curr;
       
         if(start != NULL) start -> next = prev;
         else head = prev;
       
           
       
     return head;
    }
};