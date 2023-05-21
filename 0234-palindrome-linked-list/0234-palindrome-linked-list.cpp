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
  /**  
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL ) return NULL;
        
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while(curr != NULL)
        {
            forward = curr ->next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        head = prev;
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        
        ListNode* reverseHead = reverse(head);
        ListNode* temp = head;
        
       while(temp != NULL)
       {
           if(reverseHead->val == temp->val)
           {
               reverseHead = reverseHead -> next;
               temp = temp -> next;
           }
           else {
               return false;
           }
       }
        return true;  */
    
   bool isPalindrome(ListNode* head){
       ListNode* temp = head;
       vector<int> v;
       while(temp != NULL)
       {
           v.push_back(temp->val);
           temp = temp->next;
       }
       
       for(int i =0; i < v.size()/2; i++)
       {
           if(v[i] != v[v.size() -1-i])
           {
               return false;
           }
       }
       return true;
       
   }
    
    
};