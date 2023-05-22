/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* floydcycle(ListNode* head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        
         ListNode* slow = head;
        ListNode* fast = head;
       
        
         while(fast != NULL && slow != NULL)
        {
            fast = fast -> next;
            if(fast!=NULL)
            {
                fast = fast -> next;
            }
            
            slow = slow -> next;
            
            if(fast == slow)
            {
                return fast;
            }
         }    
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
       if(head == NULL || head -> next == NULL)
       {
           return NULL;
       }
         
        ListNode* node = floydcycle(head);
        ListNode* slow = head;
        
        if(node == NULL)
        {
            return NULL;
        }
        
        while(slow != node)
        {
            
            slow = slow -> next;
            node = node -> next;
        }
        
        return slow;
       
        
    }
};