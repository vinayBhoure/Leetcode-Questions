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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void insertnode(ListNode* &head, ListNode* &tail, int x)
    {
        ListNode* temp = new ListNode(x);
          if(head == NULL)
          {
              head = temp;
              tail = temp;
              return;
          }
        
        else{
            tail -> next = temp;
            tail = temp;
        }
        
    }
    
    ListNode* add(ListNode* a, ListNode* b)
    {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        
        while(a != NULL || b != NULL || carry != 0)
        {
            int val1 =0;
            if(a != NULL) 
                val1 = a->val;
            
            int val2 =0;
            if(b != NULL) 
                val2 = b->val;
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            insertnode(head,tail,digit);
            carry = sum/10;
            
            if(a!=NULL) 
                a = a->next;
            
            if(b!=NULL) 
                b = b->next;
        }
        return head;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
    ListNode* a = l1;
    ListNode* b = l2;
        
    ListNode* ans = add(a,b);
        
        
        
    return ans;
    }
};