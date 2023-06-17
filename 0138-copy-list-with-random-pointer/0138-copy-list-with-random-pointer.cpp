/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  void insertatTail(Node* &head, Node* &tail, int d)
  {
       Node* newnode = new Node(d);
       if(head == NULL)
       {
           head = newnode;
           tail = newnode;
           return;
       }
      else{
          tail->next = newnode;
          tail = newnode;
      }
  }
    Node* copyRandomList(Node* head) {
    
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertatTail(clonehead,clonetail,temp->val);
            temp = temp -> next;
        }
        
        unordered_map<Node*, Node*> mpp;
        Node* temp1 = head;
        Node* temp2 = clonehead;
        while(temp1 != NULL && temp2 != NULL)
        {
            mpp[temp1] = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        temp1 = head;
        temp2 = clonehead;
        
        while(temp1!=NULL)
        {
            temp2->random = mpp[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return clonehead;
    }
};