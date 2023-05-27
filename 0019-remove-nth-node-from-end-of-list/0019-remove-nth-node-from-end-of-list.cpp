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
    int length(ListNode* head){
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }
        return i;
    }
    
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
             // // if only one element is present
        if(length(head) == 1)
        {
           return NULL;
        }
       
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        
        for(int i=0; i<=n; i++)
        {
            fast = fast->next;
        }
        
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        if (slow->next != NULL) {
    slow->next = slow->next->next;
}
        
        return start->next;
    }
};