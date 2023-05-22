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
    
    ListNode* sort(ListNode* head1, ListNode* head2)
    {
 if(head1 -> next == NULL)
        {
            head1 -> next = head2;
            return head1;
        }
        // else if(head2 -> next == NULL)
        // {
        //     head2 -
        //     return list1;
        // }
        
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* next1 = head1->next;
        ListNode* next2 = head2->next;
        
        while(next1 != NULL && temp2 != NULL)
        {
            if((temp1->val <= temp2 -> val) && (temp2->val <= next1 -> val))
            {
                // add node
                temp1->next = temp2;
                next2 = temp2->next;
                temp2->next = next1;
                
                //update pointer
                temp1 = temp2;
                temp2 = next2;
            }
            else{
                temp1 = next1;
                next1 = next1 -> next;
            }
            if(next1 == NULL)
            {
                temp1 -> next = temp2;
                return head1;
            }
        }
    
    return head1;
    }
    
   /***************************************************************************/
//     
     // ListNode* approach2(ListNode* head1, ListNode* head2)
     // {
     //    //writr ur code
     // }
    /******************************************************************************************/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        if(list1 == NULL)
        {
            return list2;
        }
        else if(list2 == NULL)
        {
            return list1;
        }
        else if((list1 == NULL) && (list2 == NULL) )
        {
            return NULL;
        }
        /*************************/
        
        /********************************/
        
       if(list1 -> val <= list2 -> val)
       {
           sort(list1, list2);
           return list1;
       }
        
        else{
            sort(list2, list1);
            return list2;
        }
        
        return NULL;
    }
};