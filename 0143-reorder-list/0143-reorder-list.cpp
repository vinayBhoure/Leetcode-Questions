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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void solution1(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = reverse(slow->next);
        
        while(prev != NULL){
            ListNode* tempCurr = curr->next;
            ListNode* tempPrev = prev->next;
            
            curr->next = prev;
            prev->next = tempCurr;
            
            curr = tempCurr;
            prev = tempPrev;
        }
         if (curr != NULL) 
        curr->next = NULL;
    }
    
    void reorderList(ListNode* head) {
       stack<ListNode* > st;
       ListNode* temp = head;
        while(temp != NULL){
            st.push(temp);
            temp = temp->next;
        }
        int n = st.size()/2;
        ListNode* curr = head;
        while(n--){
            auto topnode = st.top();
            st.pop();
            
            ListNode* currNext = curr->next;
            curr->next = topnode;
            topnode->next = currNext;
            
            curr = currNext;
        }
        curr->next = NULL;
    }
};