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
    
    bool floydcycledetect(ListNode* head)
    {
        
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(slow != NULL && fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next; 
            }
            else{
                return false;
            }
            
            slow = slow -> next;
            
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        
        bool intersection = floydcycledetect(head);
        
        return intersection;
        
    }
};