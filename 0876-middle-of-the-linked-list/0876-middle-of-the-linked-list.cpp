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
    ListNode* middleNode(ListNode* head) {
        
      // appraoch 1
//         ListNode* temp = head;
//         int l = 0;
        
//         while(temp != NULL)
//         {
//             temp = temp -> next;
//             l++;
//         }
        
//         ListNode* node = head;
//         int cnt = 0;
        
//         while( cnt < l/2 )
//         {
//             node = node -> next;
//             cnt++;
//         }
    
//         return node;
        
        
        // appraoch 2
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        if(head == NULL || head -> next == NULL) return head;
        
        // when 2 node are present
        if(head -> next -> next == NULL)
        {
            return head -> next;
        }
        
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast -> next;
            }
            
            slow = slow -> next;
        }
        
        return slow;
        
    }
};