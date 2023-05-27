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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
                 
        int  l = length(head);
        //TIME COMPLEXITY == O(n)
        
        if(head == NULL)
        {
            return NULL;
        }
        
        if(k > l)
        {
            return head;
        }
        // 1. reverse k element of linkedlist
        ListNode* next = NULL;
         ListNode* curr = head;
         ListNode* prev = NULL;
        int cnt = 0;
        
        while(curr != NULL && cnt < k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        // 2. reverse next elements using recursion
        if(next != NULL){
        head -> next = reverseKGroup(next,k);
        }
        //return head of reversed linkedlist 
        return prev;
    }
};