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
    
//     int length(ListNode* head) {
//     int length = 0;
//     ListNode* current = head;
    
//     while (current != nullptr) {
//         length++;
//         current = current->next;
//     }
    
//     return length;
// }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
//         ListNode *temp = head;
//         ListNode *prev = NULL;
//         int len = length(head);
        
//         if(head == NULL || head->next == NULL) return head;
        
        
//         if(len <= k )
//         {
//             k = k % len;
//         }
        
        
//         for(int i=0; i<k; i++)
//         {
//             while(temp->next != NULL)
//              {
//                 prev = temp;
//                 temp = temp -> next;
//             }
//                 temp -> next = head;
//                 prev -> next = NULL;
//                 head = temp;
//         }
        
//         return head;
        
        ListNode* tail = head;
        int length = 0;
        
        if(head == NULL || head->next == NULL) return head;
        
        while(tail->next != NULL)
        {
            tail = tail->next;
            length++;
        }
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        if(k>=length+1){
            k = k%(length+1);
        }
        
        if(!k) return head;
        
        for(int i=0; i<(length-k+1); i++)
        {
            prev = temp;
            temp = temp -> next;
        }
        tail->next = head;
        prev->next = NULL;
        head = temp;
        
        return head;
    }
};