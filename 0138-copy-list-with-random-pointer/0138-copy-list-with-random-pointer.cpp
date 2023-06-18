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
    Node* approach1(Node* head)
    {
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
    
    Node* approach2(Node* head)
    {
         // 1.
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertatTail(clonehead,clonetail,temp->val);
            temp = temp -> next;
        }
        //2.
        Node* originalnode = head;
        Node* clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL)
        {
            Node* next = originalnode->next;
            originalnode->next = clonehead;
            originalnode = next;
            
            next = clonehead->next;
            clonenode->next = originalnode;
            clonenode = next;
        }
        
        //3.
        temp = head;
        while(temp!=NULL)
        {
            if(temp->next != NULL)
            {
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp=temp->next->next;
        }
        
        //4.
        originalnode = head;
        clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL)
        {
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            
           if(originalnode != NULL )
           {
                clonenode->next = originalnode->next;
           }
            clonenode = clonenode->next;
        }
        
        //5.
        return clonehead;
    }
    Node* copyRandomList(Node* head) {
    
        // Node* ans = approach2(head);
        // return ans;
         if (head == NULL)
        return NULL;

    // 1. Create clone nodes and insert them after each original node
    Node* originalNode = head;
    while (originalNode != NULL) {
        Node* clonedNode = new Node(originalNode->val);
        clonedNode->next = originalNode->next;
        originalNode->next = clonedNode;
        originalNode = clonedNode->next;
    }

    // 2. Set the random pointers for cloned nodes
    originalNode = head;
    while (originalNode != NULL) {
        Node* clonedNode = originalNode->next;
        if (originalNode->random != NULL)
            clonedNode->random = originalNode->random->next;
        originalNode = clonedNode->next;
    }

    // 3. Separate original and cloned nodes
    originalNode = head;
    Node* clonedHead = originalNode->next;
    Node* clonedNode = clonedHead;
    while (originalNode != NULL) {
        originalNode->next = clonedNode->next;
        originalNode = originalNode->next;
        if (originalNode != NULL) {
            clonedNode->next = originalNode->next;
            clonedNode = clonedNode->next;
        }
    }

    return clonedHead;
      
       
    }
};